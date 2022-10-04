#include <string.h>

int compare(String s){
  if(s == ".----") return 1;
  if(s == "..---") return 2;
  if(s == "...--") return 3;
  if(s == "....-") return 4;
  if(s == ".....") return 5;
  if(s == "-....") return 6;
  if(s == "--...") return 7;
  if(s == "---..") return 8;
  if(s == "----.") return 9;
  if(s == "-----") return 0;
}

void ponto(){
  digitalWrite(4, HIGH);
  delay(2000);
  digitalWrite(4, LOW);
  delay(1000);
}
void barra(){
  digitalWrite(4, HIGH);
  delay(6000);
  digitalWrite(4, LOW);
  delay(2000);
}
bool SwitchL = false;
void piscadinha(int i){
  switch(i){
    case 1:
      ponto(); barra(); barra(); barra(); barra();
      break;
    case 2:
      ponto(); ponto(); barra(); barra(); barra();
      break;
    case 3:
      ponto(); ponto(); ponto(); barra(); barra();
      break;
    case 4:
      ponto(); ponto(); ponto(); ponto(); barra();
      break;
    case 5:
      ponto(); ponto(); ponto(); ponto(); ponto();
      break;
    case 6:
      barra(); ponto(); ponto(); ponto(); ponto();
      break;
    case 7:
      barra(); barra(); ponto(); ponto(); ponto();
      break;
    case 8:
      barra(); barra(); barra(); ponto(); ponto();
      break;
    case 9:
      barra(); barra(); barra(); barra(); ponto();
      break;
    case 0:
      barra(); barra(); barra(); barra(); barra();
      break;
  }
}
int d = 0;
int soma = 0;
double luz = 0;
int tempo_luz = 0;
double total = 0;
int cnt = 0;
int tempo = 0;
bool check = false;
String s = "";
void setup()
{
  pinMode(A4, INPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void piscar(int a, int b){
  delay(3000);
  piscadinha(a);
  Serial.println("CONCLUIDO: A");
  piscadinha(b);
  Serial.println("CONCLUIDO: B");
  SwitchL = true;
}

void loop()
{
  //if(!SwitchL){
    //piscar(8,8);
    //SwitchL = true;
    //return;
  //}
  //piscadinha(2);
  luz = analogRead(A4);
  //Serial.println(luz);
  //Serial.println(luz);
  if(luz < 500 and !check){
   tempo_luz = millis();
   check = true; 
  } 
  else if(luz >= 700 and check){
    tempo = millis() - tempo_luz;
    //Serial.println(luz);
    if(tempo > 3500) s += '-';
    else s += '.';
    check = false;
    Serial.println(s);
  }
  
  if(s.length() == 5){
    int a = compare(s);
    Serial.println(compare(s));
    soma += a;
    d++;
    s = "";
  }
  if(d == 2){
    Serial.println(soma);
    String str = String(soma);
    Serial.println(str);
    delay(2000);
    for(int i = 0; i < str.length(); i++){
      int n = str[i] - 48;
      Serial.println(n);
      piscadinha(n);
    }
    delay(2000);
  }
  
  
}