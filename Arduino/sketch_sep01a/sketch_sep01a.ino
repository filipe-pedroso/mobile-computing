int i = 0;
void setup() {
  pinMode(3, INPUT_PULLUP); //dó
  pinMode(4, INPUT_PULLUP); //ré
  pinMode(5, INPUT_PULLUP); //mi
  pinMode(6, INPUT_PULLUP); //fá
  pinMode(7, INPUT_PULLUP); //sol
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
//  
//    int DO = digitalRead(3);
//    int RE = digitalRead(4);
//    int MI = digitalRead(5);
//    int FA = digitalRead(6);
//    int SOL = digitalRead(7);
  
    int Music [24] = {
      0, 1, 2, 3, 3, 3,
      0, 1, 0, 1, 1, 1,
      0, 4, 3, 2, 2, 2,
      0, 1, 2, 3, 3, 3
    };

    if(digitalRead(3) == LOW){
        tone(13, 262); 
        delay(500); 
        noTone(13);
        if(Music[i] == 0){
          i++;
         }else{
          i = 0;
          }
    }
    if(digitalRead(4) == LOW){
        tone(13, 294); 
        delay(500); 
        noTone(13);
        if(Music[i] == 1){
          i++;
         }else{
          i = 0;
          }
    }
    if(digitalRead(5) == LOW){
        tone(13, 330); 
        delay(500); 
        noTone(13);
        if(Music[i] == 2){
          i++;
         }else{
          i = 0;
          }
    }
    if(digitalRead(6) == LOW){
        tone(13, 349); 
        delay(500); 
        noTone(13);
        if(Music[i] == 3){
          i++;
         }else{
          i = 0;
          }
    }
    if(digitalRead(7) == LOW){
        tone(13, 392); 
        delay(500); 
        noTone(13);
        if(Music[i] == 4){
          i++;
         }else{
          i = 0;
          }
    }
    if(i == 24){
      Serial.println("AAAAAAAAAAAAAAAAAAAAA");
       digitalWrite(12, LOW);
       delay(3000);
       digitalWrite(12, HIGH);
       
  }
}
