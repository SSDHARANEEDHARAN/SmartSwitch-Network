#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adjust the I2C address if needed
const int relay1Pin = 10;  // Use pin 7 for Relay 1
const int relay2Pin = 12;  // Use pin 8 for Relay 2

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); // Specify columns and rows
  lcd.backlight();

  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  
  // Initialize relays to OFF
  digitalWrite(relay1Pin, LOW);
  digitalWrite(relay2Pin, LOW);
  
  lcd.print("Ready");
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    
    switch (command) {
      case '1': // Relay 1 ON
        digitalWrite(relay1Pin, HIGH);
        lcd.clear();
        lcd.print("Relay 1 ON");
        break;
      case '2': // Relay 1 OFF
        digitalWrite(relay1Pin, LOW);
        lcd.clear();
        lcd.print("Relay 1 OFF");
        break;
      case '3': // Relay 2 ON
        digitalWrite(relay2Pin, HIGH);
        lcd.clear();
        lcd.print("Relay 2 ON");
        break;
      case '4': // Relay 2 OFF
        digitalWrite(relay2Pin, LOW);
        lcd.clear();
        lcd.print("Relay 2 OFF");
        break;
      case 'A': // Turn both ON
        digitalWrite(relay1Pin, HIGH);
        digitalWrite(relay2Pin, HIGH);
        lcd.clear();
        lcd.print("Both Relays ON");
        break;
      case 'B': // Turn both OFF
        digitalWrite(relay1Pin, LOW);
        digitalWrite(relay2Pin, LOW);
        lcd.clear();
        lcd.print("Both Relays OFF");
        break;
      case 'F': // Fault indication
        digitalWrite(relay1Pin, LOW);
        digitalWrite(relay2Pin, LOW);
        lcd.clear();
        lcd.print("CAUTION! FAULT!");
        break;
    }
  }
}
