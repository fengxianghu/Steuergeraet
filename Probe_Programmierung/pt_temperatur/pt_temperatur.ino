const int PROGMEM ptInputPin = A3;
const float Rs=47000; // 分压电阻
const double R0=100;//零度0应的阻值，注意单位是欧  
const float voltagePower=3.3; 
const int B=3850; 

void setup() {
   Serial.begin(9600);  
   pinMode(ptInputPin, INPUT);

}

void loop() {
    double digitalValue=analogRead(ptInputPin);
    Serial.print("current digitalValue:");
    Serial.println(digitalValue);

    
    double voltageValue=(digitalValue/1023)*3.3;
    Serial.print("Current voltage value=");
    Serial.println(voltageValue);   // 这个voltage 是22kohm两端的

    double a = ((voltagePower - voltageValue) / (Rs));
    Serial.print("the Strom:");
    Serial.println(a,8);


    Serial.print("Current registor value=");
    double Rt = (voltageValue) / a;
    Serial.println(Rt,6);

    
    Serial.print("Current temperature value=");


    Serial.println((Rt-R0)/(0.385*R0));
    Serial.println(); 
    delay(5000);
     
     
    
 

}
