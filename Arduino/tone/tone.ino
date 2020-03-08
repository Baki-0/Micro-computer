void setup() {
  pinMode(2,INPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

int notes[] = {262,294,330,349,392,440,494,523};
int i=0;
int n=0;
int s=0;

void loop() {

  if(digitalRead(2) == 1 && s==0){
      Serial.println("LOW");
      s = 1;
      
    }else if(digitalRead(2) == 0 && s == 1){
      Serial.println("HIGH");
      s = 0;
      
      tone(12,notes[i],1000);
      delay(500);
      i++;
      if(i>7)
        i=0;
    }
}
