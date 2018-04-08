const int PROGMEM waterLevelInputPin = A5;
const float voltagePower = 3.3;
const float Rs = 1000;// 22kohm

void setup() {
  Serial.begin(9600);
  pinMode(waterLevelInputPin, INPUT);

}

void loop() {
  double digitalValue = analogRead(waterLevelInputPin); //输出这个串口的:
  Serial.println(digitalValue);
  
  double voltageValue = (digitalValue / 1023) * 3.3;
  Serial.println(voltageValue,5);
  double a = ((voltagePower - voltageValue) / (Rs * 1000));
  Serial.print("the Strom:");
  Serial.println(a,8);
  
  Serial.print("Current registor value=");
  double Rt = (voltageValue) / a;
  
  Serial.println(Rt);
  delay(1000);
  Serial.println();
  

}
