// C++ code
//  
#include <LiquidCrystal.h>

int segundo = 0;
int hora = 0;
int minuto = 0;
int volatile aux = 0;
int volatile aux2 = 0;
int ruidoE = 0;
int ruidoS = 0;
LiquidCrystal lcd_1(12, 11, 5, 4, 6, 7);

void setup()
{
  pinMode(2, INPUT_PULLUP);//MINUTO
  attachInterrupt(digitalPinToInterrupt(2), mudaMinuto, FALLING);
  pinMode(3, INPUT_PULLUP);//HORA
  attachInterrupt(digitalPinToInterrupt(3), mudaHora, FALLING);
  
  lcd_1.begin(16, 2);
}

void loop(){
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Hora:");

char HoraFormat[9];
lcd_1.setCursor(6, 0);
sprintf(HoraFormat, "%02d:%02d:%02d", hora, minuto, segundo);
lcd_1.print(HoraFormat);

segundo += 1;
segundo = segundo % 60;
delay(1000);

if(segundo == 59) {
delay(1000);
minuto+=1;
minuto = minuto % 60;

}

if( minuto == 59) {
hora+=1;
hora = hora % 60;

}


}

void mudaHora(){
  ruidoE = millis();
 if(ruidoE-ruidoS>250){
  hora+=1;
  ruidoS = ruidoE;
 }
  
}
void mudaMinuto(){
  ruidoE = millis();
 if(ruidoE-ruidoS>250){
  minuto+=1;
  ruidoS = ruidoE;
 }
}
