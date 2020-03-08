char input[30];      //  文字列格納用 
int i = 0;    //  文字数のカウンタ 
void setup() { 
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);

} 

void loop() {     //  データ受信したとき     
  if (Serial.available()) {
    input[i] = Serial.read();
    //  文字数が 30 以上  or  末尾文字         
    if (input[i] == '1') {
      for(i=0;i<10;i++){
      digitalWrite(12, HIGH); 
      digitalWrite(9, HIGH); 
      delay(100);
      digitalWrite(12, LOW);
      digitalWrite(9, LOW);
      delay(100);
      }}
     if (input[i] == '2') {
      for(i=0;i<10;i++){
      digitalWrite(13, HIGH); 
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(13, LOW); 
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      digitalWrite(7, LOW);
      delay(100);
      }
     }
     if (input[i] == '3') {
      for(i=0;i<10;i++){
      digitalWrite(13, HIGH); 
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(13, LOW); 
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      delay(100);
      }
     }
     if (input[i] == '4') {
      for(i=0;i<10;i++){
      digitalWrite(12, HIGH); 
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      delay(100);
      digitalWrite(12, LOW); 
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      delay(100);
      }
     }
     if (input[i] == '5') {
      for(i=0;i<10;i++){
      digitalWrite(12, HIGH); 
      digitalWrite(13, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(12, LOW); 
      digitalWrite(13, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      delay(100);
      }
     }
     if (input[i] == '6') {
      for(i=0;i<10;i++){
      digitalWrite(12, HIGH); 
      digitalWrite(13, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(12, LOW); 
      digitalWrite(13, LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      delay(100);
      }
     }
     if (input[i] == '7') {
      for(i=0;i<10;i++){
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH); 
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(13, LOW); 
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      delay(100);
      }
     }
     if (input[i] == '8') {
      for(i=0;i<10;i++){
      digitalWrite(12, HIGH); 
      digitalWrite(13, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(12, LOW); 
      digitalWrite(13, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      delay(100);
      }
     }
     if (input[i] == '9') {
      for(i=0;i<10;i++){
      digitalWrite(12, HIGH); 
      digitalWrite(13, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(12, LOW); 
      digitalWrite(13, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      delay(100);
      }
     }
     if (input[i] == '0') {
      for(i=0;i<10;i++){
      digitalWrite(12, HIGH); 
      digitalWrite(13, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(12, LOW); 
      digitalWrite(13, LOW);
      digitalWrite(11, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      delay(100);
      }
     }

    
      //  カウンタの初期化    
      i = 0;         
    } else { i++; }     
  }
