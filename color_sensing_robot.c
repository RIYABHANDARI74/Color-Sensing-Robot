#include <reg51.h>
#include <stdio.h>

sbit S0 = P2^0;
sbit S1 = P2^1;
sbit S2 = P2^2;
sbit S3 = P2^3;
sbit OUT = P3^2;
sbit MOTOR1_FWD = P1^0;
sbit MOTOR1_BWD = P1^1;
sbit MOTOR2_FWD = P1^2;
sbit MOTOR2_BWD = P1^3;

void delay(unsigned int time) {
    unsigned int i, j;
    for (i = 0; i < time; i++) {
        for (j = 0; j < 1275; j++);
    }
}

void UART_Init(void) {
    TMOD = 0x20;
    TH1 = 0xFD;
    SCON = 0x50;
    TR1 = 1;
}

void UART_Tx(unsigned char data) {
    SBUF = data;
    while (!TI);
    TI = 0;
}

unsigned char UART_Rx(void) {
    while (!RI);
    RI = 0;
    return SBUF;
}

void send_color_data(unsigned char color) {
    UART_Tx(color);
}

void read_color_sensor(void) {
    S2 = 0; S3 = 0; // Red
    delay(100);
    if (OUT == 0) {
        send_color_data('R');
    }

    S2 = 1; S3 = 1; // Green
    delay(100);
    if (OUT == 0) {
        send_color_data('G');
    }

    S2 = 0; S3 = 1; // Blue
    delay(100);
    if (OUT == 0) {
        send_color_data('B');
    }
}

void move_robot(unsigned char command) {
    switch (command) {
        case 'R': // Move forward
            MOTOR1_FWD = 1; MOTOR1_BWD = 0;
            MOTOR2_FWD = 1; MOTOR2_BWD = 0;
            break;
        case 'G': // Stop
            MOTOR1_FWD = 0; MOTOR1_BWD = 0;
            MOTOR2_FWD = 0; MOTOR2_BWD = 0;
            break;
        case 'B': // Move backward
            MOTOR1_FWD = 0; MOTOR1_BWD = 1;
            MOTOR2_FWD = 0; MOTOR2_BWD = 1;
            break;
        default:
            break;
    }
}

void main(void) {
    unsigned char received_color;
    UART_Init();
    while (1) {
        read_color_sensor();
        received_color = UART_Rx();
        move_robot(received_color);
    }
}
