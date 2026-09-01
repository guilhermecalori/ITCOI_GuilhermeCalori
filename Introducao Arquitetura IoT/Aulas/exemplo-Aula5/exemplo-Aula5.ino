const int carroVerde = 12;
const int carroAmarelo = 11;
const int carroVermelho = 10;
const int pedVerde = 9;
const int pedVermelho = 8;

void setup() {
  pinMode(carroVerde, OUTPUT);
  pinMode(carroAmarelo, OUTPUT);
  pinMode(carroVermelho, OUTPUT);
  pinMode(pedVerde, OUTPUT);
  pinMode(pedVermelho, OUTPUT);
}

void loop() {
  //Fluxo Livre 
  digitalWrite(carroVerde, HIGH);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVermelho, LOW);
  digitalWrite(pedVerde, LOW);
  digitalWrite(pedVermelho, HIGH);
  delay(5000);

  // Atenção 
  digitalWrite(carroVerde, LOW);
  digitalWrite(carroAmarelo, HIGH);
  // pedVermelho permanece HIGH
  delay(3000);

  // Travessia
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVermelho, HIGH);
  digitalWrite(pedVermelho, LOW);
  digitalWrite(pedVerde, HIGH);
  delay(5000);

  // Alerta de Fim 
  digitalWrite(pedVerde, LOW);
  // carroVermelho permanece HIGH durante o alerta
  for (int i = 0; i < 5; i++) {
    digitalWrite(pedVermelho, HIGH);
    delay(250);
    digitalWrite(pedVermelho, LOW);
    delay(250);
  }
}
