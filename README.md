# Project Buddy — Phase 1: Proximity Warning System
### Intelligent Autonomous Mobile Unit (I.A.M.U.)
**Designed & Simulated by Hope Gumede | Botho University | Gaborone, Botswana**

---

## What This Is

This is Phase 1 of Project Buddy — an ongoing effort to build an intelligent autonomous companion robot from the ground up.

This phase focuses on the perceptual logic layer: teaching a machine to read its environment, interpret spatial boundaries, and respond proportionally to proximity threats across three behavioral zones.

The system was designed and validated in Proteus Design Suite before physical hardware translation.

---

## System Components

| Component | Role |
|---|---|
| ATmega328P (Arduino Uno) | Core microcontroller |
| HC-SR04 Ultrasonic Sensor | Environmental distance measurement |
| 16x2 LCD Display | Live distance & threshold readout |
| Potentiometer | Adjustable threshold for validation testing |
| Green / Yellow / Red LEDs | Visual zone indicators |
| Piezoelectric Buzzer | Acoustic hazard warning |
| Motor | Drive control — cuts in danger zone |

---

## Behavioral Logic — The Three Zones

| Zone | Condition | System Response |
|---|---|---|
| ✅ SAFE | Distance > threshold | Motor ON, Green LED, Silence |
| ⚠️ CAUTION | Distance > threshold/2 | Motor ON, Yellow LED, Pulsed Buzzer |
| 🚨 DANGER | Distance ≤ threshold/2 | Motor OFF, Red LED, Continuous Alarm |

---

## Distance Calculation 
Distance (cm) = (Echo Duration × Speed of Sound) / 2
Distance (cm) = duration × 0.034 / 2

---

## Why The Potentiometer

In simulation, the robot cannot physically move through space. The potentiometer allows manual adjustment of the warning threshold during testing — effectively simulating the robot approaching objects at different distances. This validates that all zone transitions and component responses execute correctly across the full behavioral range.

---

## Simulation Note

This project was simulated at 4MHz clock frequency (reduced from standard 16MHz) to compensate for host machine processing limitations during real-time Proteus simulation. The underlying logic architecture remains identical to a standard 16MHz physical deployment.

This is intentional engineering — not a limitation.

---

## The Bigger Picture

This simulation is Phase 1 of a multi-phase roadmap:

- **Phase 1 (Complete):** Perceptual logic validated in simulation
- **Phase 2 (Final Year Project):** Physical hardware build — autonomous movement, escape logic, distress signaling
- **Phase 3 (Vision):** Sound source localization, voice recognition, AI integration — Buddy recognizes you, faces you, and responds to you

---

## Honest Disclaimer

This system has been validated in simulation only. Physical deployment will introduce real-world variables — sensor noise, power inconsistencies, material resistance — that simulation cannot fully replicate. That's where the real engineering begins.

---

*Built from Gaborone, Botswana. Starting small. Thinking big.* 🇧🇼
