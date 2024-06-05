#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int valorsensorgas;
int ledhigh = 5;  
int ledlow = 6;   
int buzzer = 7;   

const int gasThresholdLow = 300;
const int gasThresholdHigh = 1000;

void setup() {
  pinMode(ledhigh, OUTPUT);
  pinMode(ledlow, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
}

void loop() {
  valorsensorgas = analogRead(A1);

  lcd.clear();
  lcd.print("Gas: ");
  lcd.print(valorsensorgas);
  Serial.println(valorsensorgas);

  if (valorsensorgas >= gasThresholdLow && valorsensorgas <= gasThresholdHigh) {
    digitalWrite(ledhigh, HIGH);
    digitalWrite(ledlow, LOW);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Status: WARNING");
  } else {
    digitalWrite(ledhigh, LOW);
    digitalWrite(ledlow, HIGH);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Status: Aman      ");
  }
  delay(1000);
}
