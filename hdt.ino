#include <dht.h>

dht yi;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int y = yi.read11(7);
  Serial.print("Temperature = ");
  Serial.print(yi.temperature);
  Serial.print("\t Humidity = ");
  Serial.println(yi.humidity);
  delay(1000);
  // put your main code here, to run repeatedly:

}
