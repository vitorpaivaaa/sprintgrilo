#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const int sensorPin = A1;   // Connect the LDR to analog pin A0
const int threshold = 500;  
LiquidCrystal_I2C lcd(0x20, 16, 2);  // I2C address and LCD dimensions

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight();
}
void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.println("Sensor Value: " + String(sensorValue));
  
  if (sensorValue > threshold) {
    // Energy consumption detected, display message on LCD
  
     lcd.init();    // Initialize the LCD display.
  lcd.clear();     // Clear the LCD display.
  lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Energy Consumed");
    lcd.setCursor(0, 1);
    lcd.print("Monitoring...");
    
    // Send data to the first Arduino using Serial communication
    Serial.println("Energy Consumption Detected");
  } else {
        lcd.init();    // Initialize the LCD display.
  lcd.clear();     // Clear the LCD display.
  lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("No Energy");
    lcd.setCursor(0, 1);
    lcd.print("Consumption");
  }
  delay(1000);  // Adjust delay based on the required monitoring frequency
}