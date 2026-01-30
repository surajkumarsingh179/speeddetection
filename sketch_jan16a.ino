#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ---------------- LCD ----------------
LiquidCrystal_I2C lcd(0x27, 16, 2);   // change to 0x3F if needed

// ------------- IR Sensors -------------
#define SENSOR_1_PIN 2   // INT0
#define SENSOR_2_PIN 3   // INT1

volatile unsigned long time1 = 0;
volatile unsigned long time2 = 0;
volatile bool sensor1Hit = false;
volatile bool sensor2Hit = false;

// Distance between sensors (meters)
const float distance = 0.10;   // 10 cm

float speed_mps = 0;
float speed_kmph = 0;

// ---------- Interrupts ----------
void sensor1ISR() {
  if (!sensor1Hit) {
    time1 = micros();
    sensor1Hit = true;
  }
}

void sensor2ISR() {
  if (sensor1Hit && !sensor2Hit) {
    time2 = micros();
    sensor2Hit = true;
  }
}

void setup() {
  // LCD init
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Speed Gun");
  lcd.setCursor(0, 1);
  lcd.print("Initializing");
  delay(2000);
  lcd.clear();

  pinMode(SENSOR_1_PIN, INPUT);
  pinMode(SENSOR_2_PIN, INPUT);

  attachInterrupt(digitalPinToInterrupt(SENSOR_1_PIN), sensor1ISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(SENSOR_2_PIN), sensor2ISR, FALLING);
}

void loop() {
  if (sensor1Hit && sensor2Hit) {

    unsigned long timeDiff = time2 - time1; // microseconds

    lcd.clear();

    if (timeDiff > 0) {
      speed_mps = distance / (timeDiff / 1000000.0);
      speed_kmph = speed_mps * 3.6;

      lcd.setCursor(0, 0);
      lcd.print("Speed:");

      lcd.setCursor(0, 1);
      lcd.print(speed_kmph, 2);
      lcd.print(" km/h");
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Invalid Read");
    }

    // Reset for next object
    sensor1Hit = false;
    sensor2Hit = false;
    time1 = 0;
    time2 = 0;

    delay(1500);
  }
}
