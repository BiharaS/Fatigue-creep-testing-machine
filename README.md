# Fatigue-creep-testing-machine
A rapid-prototype automated fatigue and creep testing machine built as a backup backup unit for load cell durability testing, featuring Arduino-based pneumatic control and EEPROM cycle tracking.

# Automated Fatigue and Creep Testing Machine (Industrial Internship Project)

An automated testing machine developed during my industrial engineering internship at **Flintec Transducers (Pvt) Ltd** to execute accelerated load cycles (up to 1 million cycles) on precision load cells. This unit was built as a rapid-response prototype backup system designed to take over testing in the event that primary production fatigue testers fail.

---

## Project Background & Objective

This unit was built as a rapid-prototype backup system designed to operate in the event that existing production fatigue testing machines break down.

* **Core Strategy:** The high-level testing strategy and conceptual approach were guided by my supervisor.
* **My Role:** I independently engineered, wired, and programmed the entire electronic control system, helped the process of mechanical integration, and firmware logic.

---

## Mechanical Setup & Actuation

* **Pneumatic Actuation:** Powered by a Festo ISO cylinder (DSBC-40-25-PPSA-N3, 40 mm bore, 25 mm stroke) capable of delivering a theoretical force of 754 N at 0.6 MPa. 
* **Pneumatic Conditioning:** Integrated an FRL (Filter, Regulator, Lubricator) unit to supply clean, lubricated air, ensuring minimal wear across millions of cycles.
* **Structural Framing:** Fabricated using high-stability T-slot aluminum extrusion profiles joined with spring-loaded nuts.

---

## Electronics & Control Architecture

The system utilizes an open-source microcontroller platform to manage pneumatic sequencing:
* **Microcontroller:** Arduino Nano (To operate with minimum computatational power).
* **Signal Switching:** A 5/2 solenoid valve controlled via a **ULN2803A** Darlington driver IC to bridge the 5V Arduino logic with 24V industrial pneumatic hardware.
* **Display & Monitoring:** Connected an LCD module to provide real-time cycle counts during operation.

---

## Firmware & Data Persistence

To protect test progress against unexpected power interruptions, the firmware incorporates non-volatile memory management:
* **EEPROM Writing Optimization:** Because the internal EEPROM of an Arduino Nano has a finite write endurance (approximately 100,000 write cycles), the code is structured to save the cycle count incrementally every 100 cycles rather than continuously.
* **Cycle Calculation:** With an automated cycle period of 0.9 seconds, reaching the 1,000,000-cycle threshold takes roughly 10.4 days of continuous operation.

---

## Prototype Status & Reliability Note

* **Design Disclaimer:** This system was engineered strictly as a rapid prototype backup unit using accessible microcontrollers (Arduino Nano). Due to the inherent reliability and longevity constraints of open-source hobbyist hardware under harsh industrial environments, this prototype is explicitly maintained as a secondary contingency system rather than a primary production-grade asset, safeguarding company reliability standards.

---

## Media & Prototype Showcase

* Check out the working prototype videos and photos
