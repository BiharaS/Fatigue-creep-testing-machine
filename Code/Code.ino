#include <LiquidCrystal.h>
#include <EEPROM.h>

// ---------------- CONFIGURATION ----------------
const unsigned long SAVE_INTERVAL = 100;
const unsigned long RESET_HOLD_TIME = 3000;

// ---------------- PIN DEFINITIONS ----------------
const int VALVE_EXTEND = 7;
const int RESET_COUNT_PIN = 8;   // NC button

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// ---------------- VARIABLES ----------------
unsigned long liveCount = 0;
bool lastValveState = LOW;
const int EEPROM_ADDRESS = 0;

// Reset button timing
unsigned long resetPressStart = 0;
bool resetDone = false;

// ---------------- SETUP ----------------
void setup() {
  pinMode(VALVE_EXTEND, OUTPUT);
  digitalWrite(VALVE_EXTEND, LOW);

  pinMode(RESET_COUNT_PIN, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Valve ON Count");

  // Restore count
  EEPROM.get(EEPROM_ADDRESS, liveCount);

  lcd.setCursor(0, 1);
  lcd.print("Count: ");
  lcd.print(liveCount);
}

// ---------------- LOOP ----------------
void loop() {

  // -------- RESET BUTTON CHECK (NC, 3s HOLD) --------
  if (digitalRead(RESET_COUNT_PIN) == HIGH) {  // NC pressed
    if (resetPressStart == 0) {
      resetPressStart = millis();
    }

    if (!resetDone && millis() - resetPressStart >= RESET_HOLD_TIME) {
      liveCount = 0;
      EEPROM.put(EEPROM_ADDRESS, liveCount);

      lcd.setCursor(0, 1);
      lcd.print("Count: 0       ");

      resetDone = true;   // prevent repeated resets
    }
  } else {
    resetPressStart = 0;
    resetDone = false;
  }

  // -------- VALVE CONTROL --------
  digitalWrite(VALVE_EXTEND, HIGH);

  if (lastValveState == LOW) {
    liveCount++;

    if (liveCount % SAVE_INTERVAL == 0) {
      EEPROM.put(EEPROM_ADDRESS, liveCount);
    }

    lcd.setCursor(0, 1);
    lcd.print("Count: ");
    lcd.print(liveCount);
    lcd.print("   ");
  }

  lastValveState = HIGH;
  delay(800);

  digitalWrite(VALVE_EXTEND, LOW);
  lastValveState = LOW;
  delay(100);
}
