
#include<math.h>  
char a;
// -------relais----------------------
const int PROGMEM pinRelayGas = 2; // Temperature
const int PROGMEM pinRelayTem = 3; // Temperature
const int PROGMEM pinRelayStrom =4;//Strom

//----------------Temperature-------------------------  
const float PROGMEM voltagePower=5.0;  
const float PROGMEM Rs=33;//采样电阻为10千欧  
const int PROGMEM B=3976;  
const double PROGMEM T1=273.15+25;//常温  
const double PROGMEM R1=10;//常温对应的阻值，注意单位是千欧  
const int PROGMEM temperaturSensorInput = A0;

//----------------------Gassensor-----------------
const int PROGMEM inputPin = A1; 

//----------------------Stromsensor------------------
#define acs712 A2
const float  PROGMEM vpp = 0.0048828125;//将常量存放在flash里面
const float  PROGMEM sensitivity = 0.066;



  
void setup() {  
  Serial.begin(9600);  
  pinMode(pinRelayTem, OUTPUT); 
  pinMode(pinRelayStrom, OUTPUT); 
  pinMode(pinRelayGas, OUTPUT); 
  pinMode(acs712,INPUT);
  pinMode(inputPin, INPUT);
  guide();
}  


 
void gasSensor(){
selection();
     int val = analogRead(inputPin);
     Serial.print(F("Gaswert:"));
     Serial.println(val);
     delay(1000);
     Serial.println();
     selection();
}
void loop() {
delay(500);
temperatureSensor();
delay(500);
stromSensor();
delay(500);
gasSensor();
delay(500);
} 
//---------------------------------------------------Main programm of Stromsensor-------------------------------------------------------
void stromSensor(){  
    
    selection();
   
    float counts = analogRead(acs712)+1;
    float voltage = counts*vpp;
    voltage -=2.5;// take away 2.5 v
    float amperage = voltage/sensitivity;
    Serial.print(F("amperage: "));
    //Serial.println(“Taichi-Maker”)，这个里面有字符串, 原来这个是存储在SRAM， 但是这样会消耗资源, 那么该怎么办呢？ 我们可以该改写 Serial.println(F("amperage: ") ) ;
    Serial.println(String(amperage));
    delay(500);
    selection();

}
//-------------------------------------------------main programm of temperature sensor----------------------------------------------------------
void temperatureSensor(){
selection();   
     //get the volt of the pin A1  
     double digitalValue=analogRead(temperaturSensorInput);  
     double voltageValue=(digitalValue/1023)*5;  
     Serial.print(F("Current voltage value="));  
     Serial.println(voltageValue);  
    
     //通过分压比获得热敏电阻的阻值  
     double Rt=((voltagePower-voltageValue)*Rs)/voltageValue;  
     Serial.print(F("Current registor value="));  
     Serial.println(Rt);  
  
     //换算得到温度值  
     Serial.print(F("Current temperature value="));  
     Serial.println(((T1*B)/(B+T1*log(Rt/R1)))-273.15);
  //每3秒输出，更改此处修改频率  
     delay(300); 
     selection();
}   
    

//-------------------------------------------------main programm of guide ----------------------------------------------------------
void guide(){
Serial.println(F("----------------------Guide-----------------------------------"));
Serial.println(F("please input the character t,  the temperatur sensor is on"));
Serial.println(F("please input the number 2,  the gas sensor is on"));
Serial.println(F("please input the character s,  the strom sensor is on"));
Serial.println(F("---------------------------------------------------------------"));
}

void selection(){
if(Serial.available()>0 )// through the if-programm we can leave the while -Schleife
  {
    a = Serial.read();
    delay(500);
    if(a == 't'){
    digitalWrite(pinRelayTem,HIGH);
    Serial.println(F(" the temprature sensor is ON"));
    }else if(a =='T'){
    digitalWrite(pinRelayTem,LOW);
    Serial.println(F(" the temprature sensor is OFF"));
    }else if(a == 's'){
    digitalWrite(pinRelayStrom,HIGH);
    Serial.println(F(" the strom sensor is ON"));
    }else if(a == 'S'){
    digitalWrite(pinRelayStrom,LOW);
    Serial.println(F(" the strom sensor is OFF"));
    }else if(a == 'g'){
    digitalWrite(pinRelayGas,HIGH);
    Serial.println(F(" the gas sensor is ON"));
    }else if(a == 'G'){
    digitalWrite(pinRelayGas,LOW);
    Serial.println(F(" the gas sensor is OFF"));
    }else if(a == 'g'){
    digitalWrite(pinRelayGas,HIGH);
    Serial.println(F(" the gas sensor is ON"));
    }else{
    }
  }
   
}

