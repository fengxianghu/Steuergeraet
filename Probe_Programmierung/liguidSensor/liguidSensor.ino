const float resistor1 = 20;// 20kohm
const float percent1 = 0.75;//75%
const int resistor2 = 100;// 100kohm
const float percent2 = 0.93;//93%
const int resistor3 = 150;// 150kohm
const float percent3 = 0.97;//97%
const float Rs = 22;// 22kohm
const int PROGMEM liquidInputPin = A4;
const float voltagePower = 3.3;

void setup() {
  Serial.begin(9600);
  pinMode(liquidInputPin, INPUT);
}

void loop() {
  double digitalValue = analogRead(liquidInputPin); //输出这个串口的值
  //Serial.print("current digitalValue:");
  //Serial.println(digitalValue);

  double voltageValue = (digitalValue / 1023) * 3.3;
  //Serial.print("Current voltage value=");
  //Serial.println(voltageValue);   // 这个voltage 是22kohm两端的

  double a = ((voltagePower - voltageValue) / (Rs * 1000));
  //Serial.print("the Strom:");
  //Serial.println(a,8);


  Serial.print("Current registor value=");
  double Rt = (voltageValue) / a;
  Serial.println(Rt);


  //Serial.println(20/0.75);



  if (Rt <= 20000) {
    Serial.print("RH:");
    Serial.println(Rt * 0.75 / 20000);
  }

  else if( Rt <= 100000)
  {
  Serial.println("Impedanz bei 75% < rF < 93%");
  Serial.print("RH:");
  Serial.println((Rt-20000+((80000/0.18)*0.75))/(80000/0.18));
  }
  else if ( Rt <= 150000)
  {
    Serial.println("Impedanz bei 93% <rf <97%");
    Serial.print("RH:");
    Serial.println((Rt-100000+((50000/0.04)*0.93))/(50000/0.04));
  } else
  {
    Serial.println("Impedanz bei rf > 97%");
  }

  delay(500);

  Serial.println();

}
