/*
 * author : Fengxiang Hu  date:13.03.2018
 * Figaro TGS813 Gas detector from Japan
 * 
 * principle:
 * High sensitivity to methane, propane,and butane
 * an der Sensoroberfläche gemessen oder direkt die Wärmeleitfähigkeit des Gases als Messgröße verwendet.
 */


const int inputPin = A1; 


void setup() {
  Serial.begin(9600);
pinMode(inputPin, INPUT);
}

void loop() {
  int val = analogRead(inputPin);
  Serial.println(val);
  delay(1000);
}
