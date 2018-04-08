/*
 * Author: Fengxiang Hu  Datum 13.02.2018
 * Relais
 */

 int pinRelay = 3;

void setup() {
 pinMode(pinRelay, OUTPUT); 
}

void loop() {
  digitalWrite(pinRelay,HIGH);
  delay(5000);
  digitalWrite(pinRelay,LOW);
  delay(1000);
}
