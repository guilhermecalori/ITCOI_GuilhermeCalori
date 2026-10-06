// Mantém exatamente a fiação do seu circuito
const int pinoRed = 7;   
const int pinoGreen = 6; 
const int pinoBlue = 5;  
const int pinoPot = A0;  

void setup() {
  pinMode(pinoRed, OUTPUT);
  pinMode(pinoGreen, OUTPUT);
  pinMode(pinoBlue, OUTPUT);
}

void loop() {
  int valorPot = analogRead(pinoPot); 

  
  if (valorPot < 150) {
    apagaLed();
  } 
  
  else if (valorPot < 300) {
    acendeVermelho();
  } 
  
  else if (valorPot < 450) {
    digitalWrite(pinoRed, HIGH);
    digitalWrite(pinoGreen, LOW);
    digitalWrite(pinoBlue, HIGH);
  } 
  
  else if (valorPot < 600) {
    acendeAzul();
  } 
  
  else if (valorPot < 750) {
    digitalWrite(pinoRed, LOW);
    digitalWrite(pinoGreen, HIGH);
    digitalWrite(pinoBlue, HIGH);
  } 
  
  else {
    acendeVerde();
  }
}



void acendeVermelho() {
  digitalWrite(pinoRed, HIGH);
  digitalWrite(pinoGreen, LOW);
  digitalWrite(pinoBlue, LOW);
}

void acendeVerde() {
  digitalWrite(pinoRed, LOW);
  digitalWrite(pinoGreen, HIGH);
  digitalWrite(pinoBlue, LOW);
}

void acendeAzul() {
  digitalWrite(pinoRed, LOW);
  digitalWrite(pinoGreen, LOW);
  digitalWrite(pinoBlue, HIGH);
}

void apagaLed() {
  digitalWrite(pinoRed, LOW);
  digitalWrite(pinoGreen, LOW);
  digitalWrite(pinoBlue, LOW);
}
