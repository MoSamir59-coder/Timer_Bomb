# 💣 Bomb Defusal Simulator - Real-Time Embedded System

## 📌 Overview
An interactive, real-time embedded system simulating a bomb defusal scenario. Built from scratch (bare-metal) using an ATmega32 microcontroller, this project demonstrates a robust, non-blocking software architecture utilizing a state machine to manage multiple hardware peripherals simultaneously without system freezing.

## 🎥 Project Demos

### 1. Hardware Implementation
Watch the physical execution of the system, including the active countdown, mechanical vault locking, and wire defusal logic on the actual kit.



https://github.com/user-attachments/assets/58c31996-b7cd-49cc-aeac-bdda13391cb0



### 2. Proteus Simulation
Watch the software logic, LCD multiplexing, and virtual hardware integration running in the Proteus simulation environment.



https://github.com/user-attachments/assets/0e031ee4-f6d9-4f95-9fe0-b082b452d686


---

## ⚙️ Hardware Components
- **Microcontroller:** ATmega32 (Running at 8MHz)
- **Inputs:** 
  - Potentiometer (ADC) for analog puzzle input.
  - 4x4 Keypad for digital passcode entry.
  - Emergency Wires (Internal Pull-ups) for defusal/detonation.
- **Outputs:** 
  - 16x2 LCD (4-bit mode).
  - 7-Segment Displays (Driven by 74HC595 Shift Register to optimize pins).
  - Servo Motor (Mechanical vault lock).
  - DC Motor (Cooling fan).
  - Active Buzzer (Timed pulse alarms).

## 💻 Software Architecture
- **Layered Design:** Strictly separated into MCAL, HAL, and APP layers for maximum driver reusability.
- **Non-Blocking Logic:** Complete elimination of `_delay_ms()` in the main super loop. The system reads sensors, monitors remote UART commands, and updates displays concurrently.
- **Interrupt-Driven Multi-tasking:** Timer0 configured in CTC mode generates a 1ms tick. This hardware interrupt manages precise 7-segment multiplexing and countdown intervals entirely independent of the main CPU loop.
- **Asynchronous Communication:** Non-blocking UART reception designed to monitor external "kill" commands without interrupting the game logic.

## 🕹️ How It Works (State Machine)
1. **Analog Puzzle (Stage 1):** The player must tune a potentiometer to a specific analog value and confirm the input to unlock the next stage.
2. **Digital Authentication (Stage 2):** The player enters a 4-digit passcode via the keypad. The system stores the full array before verification.
3. **Defusal Stage (Stage 3):** The countdown begins. The player must physically cut the correct defusal wire before time runs out. Cutting the wrong wire, letting the time expire, or receiving a remote UART command results in system detonation.

## 👨‍💻 Developer
Developed by **Mohamed Samir**  
*Undergraduate Student, Electronics and Communications Engineering Department, Damanhour University.*
