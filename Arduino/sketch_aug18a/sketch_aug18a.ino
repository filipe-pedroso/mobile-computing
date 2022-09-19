
int buttonState = 0;

void setup()
{
  pinMode(13, OUTPUT); //vermelho
  pinMode(12, OUTPUT); //amarelo
  pinMode(11, OUTPUT); //verde
  pinMode(10, OUTPUT); //vermelho pedestre
  pinMode(9, OUTPUT); //verde pedestre
  pinMode(2, INPUT); //botao
}

void loop()
{
 buttonState = digitalRead(2);
 digitalWrite (11, HIGH); //VERDE ACENDE
 digitalWrite (10, HIGH); // VERMELHO PEDESTRE ACENDE

 if(buttonState == HIGH){
  digitalWrite(11, LOW); // VERMELHO APAGA
  digitalWrite(12, HIGH); // AMARELO ACENDE
  delay(2000); //ESPERA2 SEGUNDOS
  digitalWrite(12, LOW); //AMARELO APAGA
  digitalWrite(13, HIGH); //VEMELHO ACENDE
  digitalWrite(10,LOW);
  digitalWrite(9, HIGH); //VERDE DO PEDESTRE ACENDE
  delay(4000); //ESPERA 4 SEGUNDOS
  digitalWrite(9,LOW); // APAGA O VERDE PEDESTRE
  digitalWrite(10,HIGH); //ACENDE VERMELHO PEDESTRE
  delay(500); // ESPERA 0,5 SEGUNDOS
  digitalWrite(10,LOW);//APAGA VERMELHO PEDESTRE 
  delay(500); // ESPERA 0,5 SEGUNDOS
  digitalWrite(10,HIGH); // ACENDE VERMELHO PEDESTRE
  delay(500); // ESPERA 0,5 SEGUNDOS
  digitalWrite(10,LOW); //APAGA VERMELHO PEDESTRE
  delay(500); // AESPERA 0,5 SEGUNDOS
  digitalWrite(10, HIGH); //ACENDE VERMELHO PEDESTRE
  digitalWrite(13, LOW); //APAGA VERMELHO
  digitalWrite(11,HIGH); // ACENDE VERDE
    
  }
  else{
    //
  }
}
