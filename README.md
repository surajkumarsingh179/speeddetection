# Speed Detection Using Arduino (Speed Gun)

This project is an **Arduino-based speed detection system** (speed gun) that measures the speed of a moving object using **two IR obstacle sensors** and displays the result on a **16×2 I2C LCD**.  
It is designed as a **low-cost, educational project** suitable for college labs and mini projects.

---

## 🔧 Components Used

- Arduino Uno (Tishvi UNO R3 / Arduino Uno compatible)
- 2 × IR Obstacle Sensors
- 16×2 LCD with I2C Module
- Breadboard
- Jumper Wires
- USB Cable

---

## ⚙️ Working Principle

1. Two IR sensors are placed at a fixed distance apart.
2. When an object crosses **Sensor 1**, the Arduino records the time.
3. When the same object crosses **Sensor 2**, the Arduino records the second time.
4. The time difference between the two triggers is calculated.
5. Speed is calculated using the formula:
    : Speed = Distance / Time
6. The calculated speed is displayed on the LCD in **km/h**.

---

## 🔌 Circuit Connections

### IR Sensors
| IR Sensor | Arduino Pin |
|---------|-------------|
| OUT (Sensor 1) | D2 |
| OUT (Sensor 2) | D3 |
| VCC | 5V |
| GND | GND |

### I2C LCD
| LCD Pin | Arduino Pin |
|--------|-------------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

> ⚠️ All grounds must be common.

---

## 🧠 Features

- Real-time speed measurement
- Simple and low-cost hardware
- Uses interrupts for accurate timing
- LCD display output
- Suitable for academic demonstrations

---

## 📜 Code Overview

- Uses `LiquidCrystal_I2C` library for LCD
- Uses `micros()` function for precise time measurement
- Interrupts are used on digital pins D2 and D3
- Speed is displayed in **km/h**

---

## 🧪 Testing Steps

1. Upload the code to Arduino.
2. Power the circuit.
3. Place the IR sensors facing forward (not on reflective surfaces).
4. Move an object across Sensor 1 and then Sensor 2.
5. Observe the speed on the LCD.

---

## ⚠️ Important Notes

- Adjust the **potentiometer** on IR sensors to avoid continuous detection.
- Do not place sensors facing reflective surfaces (tables, cloth).
- Ensure correct I2C address (`0x27` or `0x3F`) for LCD.
- Keep sensors aligned and parallel.

---

## 🚀 Applications

- Educational demonstrations
- Speed measurement experiments
- Mini / academic projects
- Sensor interfacing practice

---

## 📌 Future Improvements

- Add buzzer for speed limit warning
- Store speed data using EEPROM
- Add serial data logging
- Wireless display using Bluetooth / WiFi

---

## 👤 team

**Suraj Kumar Singh** 
**Pushkar Singh**
**Ashvary Sugam**
B.Tech Computer Science (AI & ML)  
GLA University  

---

## 📄 License

This project is open for educational use.
