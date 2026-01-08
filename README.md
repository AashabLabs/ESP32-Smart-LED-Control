# ESP32-Smart-LED-Control
Smart LED control using ESP32 and Wi-Fi


Description / Problem

This project demonstrates controlling an LED wirelessly using an ESP32 via Wi-Fi.


Components Used:

- ESP32
- LED
- 220Ω Resistor
- Breadboard & Jumper Wires

Circuit Diagram:

![Circuit Diagram](circuit/circuit.png)

Working Principle:

- ESP32 connects to Wi-Fi
- Hosts a simple web page with ON/OFF buttons
- User clicks buttons → ESP32 turns LED ON/OFF

Usage:

1. Upload code to ESP32
2. Open Serial Monitor to get IP address
3. Open browser → type IP address → use ON/OFF buttons
    
Future Improvements:

- Add multiple LEDs
- Control via mobile app (Blynk)
- Add password authentication
