long gas_Sensor;
long strom_Sensor;
long temperature_Sensor;


  
void setup() { 
  
  Serial.begin(9600);  
}  



void loop() {
delay(500);
temperatureSensor();
delay(500);
stromSensor();
delay(500);
gasSensor();
delay(500);
delay(10000);
} 
//---------------------------------------------------Main programm of Stromsensor-------------------------------------------------------

void stromSensor(){  
strom_Sensor = random(2,3);
Serial.print("The Strom of Stromsensor:");
Serial.print(strom_Sensor);
Serial.println("A");
}
//-------------------------------------------------main programm of temperature sensor----------------------------------------------------------

void temperatureSensor(){
Serial.print("The temperature of temperatureSensor:");
temperature_Sensor = random(300);
Serial.println(temperature_Sensor);
}   

 
void gasSensor(){
Serial.print("The value of gasSensor:");
gas_Sensor = random(1000,1024);
Serial.println(gas_Sensor);
}
 



