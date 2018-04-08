/*
 * Author: Fengxiang Hu  Datum :12.03.2018
 * NTC-Wiederstand(Temperatursensor) 6655RP-9003007 gekauft in Conrad Elecztonic SE
 * 
 * Formel: Rt = R*EXP(B*(1/T1-1/T2))
 * Rt: Widerstand bei der Temperatur T   RN: Nennwiderstand bei Nenntemperatur
 * T1: absolute Betriebstemperatur       T2:Nenntemperatur(meist 25 grad ,das heißt 295,15K)
 * B: Boltzmannkonstante Eulerschie Zahl
 */

#include<math.h>  
  
const float voltagePower=3.3;  
const float Rs=33;//采样电阻为10千欧  
const int B=3976;  
const double T1=273.15+25;//常温  
const double R1=10;//常温对应的阻值，注意单位是千欧  
  
  
void setup() {  
  Serial.begin(9600);  
}  
  
void loop() {  
    
  //获得A1处的电压值  
  double digitalValue=analogRead(0);  
  double voltageValue=(digitalValue/1023)*3.3;  
  Serial.print("Current voltage value=");  
  Serial.println(voltageValue);  
    
  //通过分压比获得热敏电阻的阻值  
  double Rt=((voltagePower-voltageValue)*Rs)/voltageValue;  
  Serial.print("Current registor value=");  
  Serial.println(Rt);  
  
  //换算得到温度值  
  Serial.print("Current temperature value=");  
  Serial.println(((T1*B)/(B+T1*log(Rt/R1)))-273.15);//  
  Serial.println();  
    
  //每3秒输出，更改此处修改频率  
  delay(3000);  
    
} 
