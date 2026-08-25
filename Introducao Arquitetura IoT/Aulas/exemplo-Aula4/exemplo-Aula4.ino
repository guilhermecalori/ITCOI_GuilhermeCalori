// sensor de estacionamento
//

const int led1 = 4;
const int led2 = 5;
const int echoPin = 2;
const int trigPin = 3;
const int buzzerPin = 6;

//distancia limite para ativar o alerta
const int nThreshold = 30;

//armazenar o tempo de ida e volta
unsigned long nDuration;

//armazenar a distancia calculada em centimetros 
float nDistance;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  //garante que o trig comece desligado
  digitalWrite(trigPin, LOW);
  Serial.begin(9600);
  Serial.println("Iniciando detector ultrassonico...");
  
}

void loop()
{
 //envio de pulso ultrassonico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //medição do tempo de retorno
  nDuration = pulseIn (echoPin, HIGH, 30000);
  
  //verificaçao da leitura
  if (nDuration == 0)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    noTone(buzzerPin);
    
    Serial.println("Sem leitura válida.");
    delay(200);
    
    return; 
  }
  
  //calculo da distancia
  nDistance = nDuration * 0.0343 / 2;
  
  //exibição da distancia
  Serial.println("Distância: ");
  Serial.println(nDistance, 1);
  Serial.println(" cm");
  
  //apitar buzzer e acender led vermelho, apagar led verde
  if (nDistance < nThreshold)
  {
      digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    tone(buzzerPin, 2000);
    delay(400);
    noTone(buzzerPin);
    digitalWrite(led2, LOW);
    delay(300);
  }
  //distancia for = ou > que 30cm
  else
  {
      digitalWrite(led2, LOW);
    noTone(buzzerPin);
    digitalWrite(led1, HIGH);
    delay(400);
    digitalWrite(led1, LOW);
    delay(300);
  }
}
