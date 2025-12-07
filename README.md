# Hand Gesture Recognition Glove  
A wearable embedded system that detects hand gestures using flex sensors, Arduino, and 8051 microcontroller. The project extracts analog flex sensor values, transmits them via Bluetooth, and classifies gestures such as **Hello**, **Okay**, and **Peace** using threshold-based logic.

---

## 🚀 Project Overview
This project implements a **smart wearable glove** capable of recognizing basic hand gestures using flex sensors placed on each finger.  
The system reads finger bending values through Arduino, sends them as CSV over Bluetooth, and an 8051 microcontroller parses and classifies the gesture.

### ✨ Key Features
- Flex sensor–based gesture detection  
- Arduino for analog data acquisition  
- Bluetooth HC-05 for wireless transmission  
- 8051 microcontroller (Keil C) for gesture classification  
- Recognizes gestures: **Hello**, **Okay**, **Peace**, and **Unknown**  
- Clean hardware setup & block diagram included  
- Complete code + report + presentation available  

---


---

## 🧠 System Workflow
1. **Flex Sensors** detect the bending of each finger.  
2. **Arduino Uno** reads analog values (A0–A4) and sends them in CSV format.  
3. **Bluetooth HC-05** transmits data wirelessly.  
4. **8051 Microcontroller** receives CSV, parses values, and performs threshold-based gesture classification.  
5. Output gestures are printed via UART terminal.

---

## 🧩 Hardware Components
- Arduino Uno  
- 8051 Microcontroller (AT89S52/AT89C51)  
- Flex Sensors (5x)  
- Bluetooth HC-05 Module  
- Resistors, jumper wires  
- Wearable glove prototype  

---

## 🧪 Gesture Classification Logic
The 8051 compares flex sensor thresholds:

| Gesture | Condition (Simplified) |
|--------|--------------------------|
| **Hello** | All values ≈ 1000 |
| **Okay** | All values < 1010 |
| **Peace** | All values > 1010 |
| **Unknown** | Anything else |

---

## 🛠 How to Run the Project

### **1️⃣ Upload Arduino Code**
Path: `Codes/flex_sensor_reader.ino`

Arduino reads flex sensors and sends CSV:
1020,980,1012,1005,990


### **2️⃣ Flash 8051 Code**
Path: `Codes/8051_gesture_recognition.c`

This code:
- Receives UART data  
- Parses CSV  
- Classifies gesture  
- Sends output like:  
Hello!
Okay!
Peace!
Unknown

### **3️⃣ Hardware Setup**
- Connect flex sensors → Arduino A0–A4  
- Arduino TX/RX → HC-05 Bluetooth  
- HC-05 → 8051 UART pins  
- Power both boards  

### **4️⃣ View Output**
Use Terminal/Serial Monitor or LCD module.

---

## 📘 Documentation

## 📘 Full Project Report
📄 [View Report](report/MPMC%20HAND%20GESTURE%20RECOGNITION%20GLOVE.pdf)

## 🎤 Presentation
📽️ [View Presentation](presentation/MPMC%20Project%20.pptx)


---

## 🖼 Images
Add your hardware photos in the `results/` folder. Example placeholders:

- Glove prototype  
- Hardware setup  
- Serial output screenshots  

---

## 👥 Contributors

- **Bojja Divya**   
- **Shreya Ranjhita M**   
- **Shruti Sameeksha Pradhan** 

### Supervisor
- **Dr. Abraham Sudharson Ponraj**  
  Associate Professor, School of Electronics Engineering, VIT Chennai. :contentReference[oaicite:2]{index=2}


---


## 📜 License
This project is licensed under the **MIT License**.


