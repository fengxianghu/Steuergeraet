/*
 * Author: Hu Fengxiang 
 * Gassensor ACS712  Empfindlichkeit: 0.185V/A
 */

#define acs712 A2

const float  PROGMEM vpp = 0.0048828125;//将常量存放在flash里面
const float  PROGMEM sensitivity = 0.066;

void setup(){
  pinMode(acs712,INPUT);
  Serial.begin(9600);
}

void loop(){
  float counts = analogRead(acs712)+1;
  float voltage = counts*vpp;
  voltage -=2.5;// take away 2.5 v
 
  float amperage = voltage/sensitivity;
  Serial.print(F("amperage: "));
  //Serial.println(“Taichi-Maker”)，这个里面有字符串, 原来这个是存储在SRAM， 但是这样会消耗资源, 那么该怎么办呢？ 我们可以该改写 Serial.println(F("amperage: ") ) ;

  Serial.println(String(amperage));
  
  delay(500);
  
}

