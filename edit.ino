int motorPin = 9;
int lightControl = 10;
//int circuitDetection = 4;
int circuitDetection = A0;
int initialSetup = 0;

void setup(){
   Serial.begin(9600); 
    pinMode(motorPin, OUTPUT);
    pinMode(circuitDetection, INPUT);
    pinMode(lightControl, OUTPUT);
    
     
     //digitalWrite(circuitDetection, OUTPUT);
     //  pinMode(secondPin, OUTPUT);
  // analogWrite(analogPin, 255);
}
int val;
//boolean newData = false;
void loop(){
  if(initialSetup == 0){
     digitalWrite(motorPin, HIGH);
     digitalWrite(lightControl, HIGH);
     //delay(8000);
     initialSetup += 1;
  } else {
    val = analogRead(circuitDetection);
  //val = digitalRead(circuitDetection);
 // Serial.println(val);
  
  //digitalWrite(secondPin, HIGH);
  
 // Serial.println(val);
  // if(Serial.available() > 0){
    // char water = Serial.read();
    // Serial.println(water);
   //}
   //delay(300);
      
    if(val > 50){
     digitalWrite(motorPin, HIGH);
     digitalWrite(lightControl, HIGH);
     
     Serial.write("L");
     delay(200);
   } else if (val < 50 ){
      //digitalWrite(motorPin, LOW);
      //digitalWrite(lightControl, LOW); 
      
      Serial.write("H"); 
      delay(200);  
  }
    
   //delay(100);   
  //delay(1000);

  }  
  }
