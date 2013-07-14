const int analogInPin[] = {A0,A1,A2,A3,A4,A5,A6,A7};  // Analog input pin that the potentiometer is attached to

void setup() 
{
  Serial.begin(9600); 
}

void loop() 
{
  long int values[8];
  
  int i;
  for(i=0; i<8; i++)
  {
    values[i] = analogRead(analogInPin[i]);              
  }
  
  for(i=0; i<8; i++)
  {
    long int millivolts = (5000*values[i])/1024;
    
    Serial.print(millivolts);
    
    if(i==7)
      Serial.print("\n");
    else
      Serial.print(", ");    
  }
   
  delay(10000);                     
}
