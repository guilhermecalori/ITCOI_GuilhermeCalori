// C++ code
//
int pinoLed = 13;
int pinoSensorLuz = A0;
int limiarLuz = 599;
int valorLuz = 0;

void setup ()
{
  pinMode(pinoLed, OUTPUT);
  pinMode(pinoSensorLuz, INPUT);
  Serial.begin(9600);
}

void loop ()
{
  valorLuz = analogRead(pinoSensorLuz);
  Serial.print("Leitura do fotorresistor: ");
  Serial.print(valorLuz);
  if (valorLuz > limiarLuz)
  {
    digitalWrite(pinoLed, LOW);
    Serial.print("Ambiente claro - LED apagado");
  }
  else
  {
    digitalWrite(pinoLed, HIGH);
    Serial.print("Ambiente escuro - LED aceso");
  }
 delay(500);
  
}
