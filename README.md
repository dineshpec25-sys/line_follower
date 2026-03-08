# Line Follower Robot 🤖

A high-performance line following robot built using the STM32 Blue Pill microcontroller with a 5-channel IR sensor array for precise line detection.

---

## 📋 Project Overview

This robot autonomously follows a black line on a white surface using IR sensors to detect the line position and control the motors accordingly. The STM32 Blue Pill provides fast processing for smooth and accurate line tracking.

---

## 🔧 Components

| Component | Description |
|-----------|-------------|
| **STM32 Blue Pill** (STM32F103C8T6) | Main microcontroller |
| **5-Channel IR Sensor Array** | Line detection |
| **N20 Micro Gear Motors** | Drive motors |
| **Motor Driver** | Controls motor speed and direction |
| **LiPo / 7.4V Battery** | Power supply |

---

## ⚙️ How It Works

1. The **5-channel IR array** continuously reads the line position
2. Sensor data is sent to the **STM32 Blue Pill**
3. STM32 processes the data and calculates the error using **PID control**
4. The **motor driver** adjusts left and right motor speeds based on PID output
5. The robot steers itself to stay centered on the line

---

## 🧠 Control Algorithm

- **PID (Proportional-Integral-Derivative)** control for smooth steering
- Weighted sensor reading to calculate line position error
- Dynamic speed adjustment based on curve sharpness

---

## 📌 Pin Configuration

| STM32 Pin | Connected To |
|-----------|-------------|
| PA0 - PA4 | IR Sensor Array (S1 - S5) |
| PB6, PB7  | Motor Driver IN1, IN2 (Left Motor) |
| PB8, PB9  | Motor Driver IN3, IN4 (Right Motor) |
| PA8, PA9  | PWM Speed Control (ENA, ENB) |

---

## 🚀 Getting Started

### Prerequisites
- STM32CubeIDE or Arduino IDE with STM32 board support
- ST-Link V2 programmer

### Upload Code
1. Clone this repository
   ```
   git clone https://github.com/dineshpec25-sys/line-follower
   ```
2. Open the project in STM32CubeIDE
3. Connect ST-Link to the Blue Pill
4. Build and flash the code

---

## 📁 Project Structure

```
line-follower/
├── src/
│   └── main.c          # Main source code
├── inc/
│   └── pid.h           # PID controller header
├── README.md
└── circuit_diagram.png
```

---

## 👥 Team

| Role | Name |
|------|------|
| Cap  | Hariharan V T |
| VC   | Divya |
| TM   | Ponmudi M R |
| Sat  | Hindula |

**Group No.** 100234

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).
