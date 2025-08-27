🚗📱 Bluetooth Controlled RC Car using Arduino UNO
📌 Project Overview

This project is a Bluetooth Controlled RC Car built with Arduino UNO. The car can be wirelessly controlled using any Android smartphone with a Bluetooth terminal/joystick app. Commands are sent via HC-05 Bluetooth module to the Arduino, which then controls the car’s movement through motor drivers.

This project demonstrates the integration of Arduino, wireless communication, and motor control, making it an exciting beginner-to-intermediate robotics project.

⚡ Features

Wireless control of car using Bluetooth & smartphone.

Supports Forward, Backward, Left, Right, and Stop movements.

Controlled via a Bluetooth terminal app or custom Android app.

Uses L293D motor driver (or L298N module) to drive DC motors.

Simple and cost-effective DIY robotics project.

🛠️ Components Used

Arduino UNO

HC-05 Bluetooth Module

L293D Motor Driver IC / L298N Module

DC Motors × 2 (or 4 for 4WD car)

Chassis with wheels

9V Battery / Li-ion Battery pack

Switch & Wires

⚙️ Working Principle

The HC-05 Bluetooth module pairs with a smartphone over Bluetooth.

User sends commands (e.g., F = Forward, B = Backward, L = Left, R = Right, S = Stop).

Arduino reads these commands via the serial interface.

According to the command, Arduino controls the motor driver to move the car in the desired direction.

📟 Control Commands
Command	Action
F	Move Forward
B	Move Backward
L	Turn Left
R	Turn Right
S	Stop
🔌 Circuit Connections

HC-05 Bluetooth → Arduino RX/TX (cross connection: TX → RX, RX → TX via voltage divider).

Motor Driver (L293D/L298N) → Arduino digital pins for motor control.

Motors → Connected to motor driver outputs.

Power Supply → 9V/12V battery for motors, 5V for Arduino & HC-05.

💻 Arduino Code (Logic)

Initialize serial communication with Bluetooth.

Read characters (F, B, L, R, S) from HC-05.

Based on character, set motor driver pins HIGH/LOW.

Motors rotate accordingly to move car.

🚀 Applications

Robotics learning projects 🤖

DIY hobby projects 🔧

Wireless car toys 🚙

Home automation robot base platform 🏠

📄 Future Improvements

Add ultrasonic sensor for obstacle avoidance.

Add camera module for wireless FPV streaming.

Control via Wi-Fi (ESP8266/NodeMCU) instead of Bluetooth.

Use voice commands to control movements.

Demo Video ()
