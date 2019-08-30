char input[10];
int i=0;

void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);

  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop(){

  if(Serial.available()){
    input[i] = Serial.read();
    
    if (input[i] == '1') {
      
      digitalWrite(13, LOW); 
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      delay(1000);
      digitalWrite(13, HIGH); 
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      
      
     }
     i=0;
    }else{i++;}
}
 
