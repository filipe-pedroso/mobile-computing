void setup() {

  pinMode(A5, INPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {

  int pot = analogRead(A5);
  int var = map(pot, 0, 1023, 0, 255);
  analogWrite(5, var);

}
