# 🎨 Color-Sensing Robot using MATLAB and P89V51RD2

A real-time color-sensing robotic system designed to detect object colors using a camera and direct movement accordingly using a P89V51RD2 microcontroller. This system is built for applications in industrial automation, object sorting, and intelligent vision-based robotics.

## 🚀 Features

- Real-time color detection using MATLAB image processing.
- Serial communication between MATLAB and P89V51RD2 microcontroller.
- Automated object tracking and directional control based on detected color.
- Modular code written in Embedded C and MATLAB.
- Robust design for adaptability in various object recognition scenarios.

## 🧠 Technologies Used

- **Microcontroller**: P89V51RD2 (8051 family)
- **Programming Languages**: Embedded C, MATLAB
- **Tools & Platforms**: 
  - MATLAB (Image Acquisition & Serial Communication)
  - Keil µVision (8051 Programming)
  - Proteus/Hardware Setup (Optional for simulation)
- **Hardware**: Color Sensor, Camera Module, Motor Driver (L293D), DC Motors

## 🛠️ How It Works

1. **Color Detection (MATLAB):**
   - Camera captures frames in real-time.
   - MATLAB processes the image and identifies specific color regions.
   - Based on the dominant color, a command (e.g., move left/right/stop) is sent via serial port.

2. **Microcontroller Control (P89V51RD2):**
   - Receives serial commands from MATLAB.
   - Executes movement through connected motors using logic in Embedded C.
   - Can be extended to perform sorting actions or other mechanical responses.

## 🔧 Setup Instructions

1. **Hardware Requirements:**
   - P89V51RD2 microcontroller
   - Color camera module
   - DC motors with motor driver (L293D)
   - Power supply and breadboard
   - Connecting wires, USB-to-Serial converter (if required)

2. **Software Requirements:**
   - MATLAB (R2018b or later recommended)
   - Keil µVision for 8051 development
   - Flash Magic (to burn code into P89V51RD2)

3. **Steps:**
   - Burn the Embedded C code to P89V51RD2 using Keil and Flash Magic.
   - Run the MATLAB script to begin camera capture and serial communication.
   - Place color objects in front of the camera and observe motor responses.

## 📂 Project Structure
Color-Sensing-Robot/
│
├── Embedded_Code/ # C code for P89V51RD2 (Keil project)
│ └── main.c
│
├── MATLAB_Code/ # Scripts for color detection and serial communication
│ └── color_detection.m
│
├── Docs/ # Circuit diagrams, documentation, etc.
│
└── README.md
