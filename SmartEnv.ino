#include <dht.h>
#include <LiquidCrystal.h>
int s;
int t;
int hum = 30;
int mid;
dht ard;
LiquidCrystal lcd_1(7, 6, 5, 4, 3, 2);
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  lcd_1.begin(16, 2);
  lcd_1.setCursor(0, 0);
  lcd_1.print("*NV Creations");
  delay(3000);
  lcd_1.clear();
}
void loop() {
  int val = ard.read11(11);
  Serial.print("temp ");
  Serial.print(ard.temperature);
  Serial.print("\t humidity");
  Serial.println(ard.humidity);
  delay(1000);
  s = ard.temperature; t = ard.humidity;
  int  prin = digitalRead(10);
  if (prin == 1) {
    lcd_1.clear();
    lcd_1.setCursor(8, 0);
    lcd_1.print("Humidity");
    lcd_1.setCursor(0, 0);
    lcd_1.print(t);
    lcd_1.setCursor(8, 1);
    lcd_1.print("Celsius");
    lcd_1.setCursor(0, 1);
    lcd_1.print(s);
  }

  int hu = digitalRead(9);
  if (hu == 1) {
    lcd_1.clear();
    mid = 9;
    lcd_1.setCursor(0, 0);
    lcd_1.print("if humidity ");
    lcd_1.setCursor(12, 0);
    lcd_1.print(hum);
    lcd_1.setCursor(0, 1);
    lcd_1.print("Port will ");
    if (1 == digitalRead(12)) {
      lcd_1.setCursor(10, 1);
      lcd_1.print("ON ");

    }
    else {
      lcd_1.setCursor(10, 1);
      lcd_1.print("OFF");

    }


  }
  int add = analogRead(1);
  int dic = analogRead(0);
  if (add > 1000) {
    hum = (hum + 1);
    delay(100);
  }
  if (dic > 1000) {
    hum = (hum - 1);
    delay(100);
  }
  int tem = digitalRead(8);
  if (tem == 1) {
    lcd_1.clear();
    mid = 8;

    lcd_1.setCursor(0, 0);
    lcd_1.print("if Celsius ");
    lcd_1.setCursor(12, 0);
    lcd_1.print(hum);
    lcd_1.setCursor(0, 1);
    lcd_1.print("Port will ");
    if (1 == digitalRead(12)) {
      lcd_1.setCursor(10, 1);
      lcd_1.print("ON ");

    }
    else {
      lcd_1.setCursor(10, 1);
      lcd_1.print("OFF");

    }
  }
  if (mid == 8){
    if (s <= hum) {
      digitalWrite(13,digitalRead(12));
    }
    else{
     digitalWrite(13,!digitalRead(12)); 
  }
  }
  if (mid == 9){
    if (t <= hum) {
      digitalWrite(13, digitalRead(12));
    }
    else{
      digitalWrite(13,!digitalRead(12));
    }
  }
}
