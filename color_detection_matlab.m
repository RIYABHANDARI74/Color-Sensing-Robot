clc;
clear;
serialPort = 'COM3'; % Adjust as needed
baudRate = 9600;
s = serial(serialPort, 'BaudRate', baudRate);
fopen(s);

figure('Name', 'Color Detection', 'NumberTitle', 'off');
hold on;
xlabel('Red'); ylabel('Green'); zlabel('Blue');
grid on;

while true
    if s.BytesAvailable > 0
        colorData = fscanf(s, '%c');
        switch colorData
            case 'R'
                color = [1, 0, 0]; % Red
                disp('Red Detected');
            case 'G'
                color = [0, 1, 0]; % Green
                disp('Green Detected');
            case 'B'
                color = [0, 0, 1]; % Blue
                disp('Blue Detected');
            otherwise
                continue;
        end
        scatter3(rand(), rand(), rand(), 100, color, 'filled');
        drawnow;
    end
end

fclose(s);
delete(s);
clear s;
