const byte AN = A0;
// vetor segmentos: a,b,c,d,e,f,g
const byte segmentos[7] = {2, 3, 4, 5, 6, 7, 8};
// declaracao da porta do LED
const byte pinLED = 11;

// numeros de 0 ate 5
const byte numeros[6][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1 
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}  // 5
};

void setup()
{
  Serial.begin(9600);
  for(int i = 0; i < 7; i++)
  {
    pinMode(segmentos[i], OUTPUT);
  }
  
  // Configura a porta 11 como saida
  pinMode(pinLED, OUTPUT);
}

void loop()
{
  // leitura analogica
  int leitura = analogRead(AN);
  
  // Converter 0-1023 para 0-5V
  float tensao = leitura * 5.0 / 1023.0;
  
  // Arredondar para exibicao no Display
  int numeroDisplay = tensao + 0.5;
  numeroDisplay = constrain(numeroDisplay, 0, 5);
  mostrarNumero(numeroDisplay);

  // Aciona o LED caso a tensao seja maior ou igual a 2.5V
  if (tensao >= 2.5) {
    digitalWrite(pinLED, HIGH);
  } else {
    digitalWrite(pinLED, LOW);
  }
  
  Serial.print("ADC: ");
  Serial.print(leitura);
  Serial.print(" | Tensao: ");
  Serial.print(tensao, 2);
  Serial.print(" V | Display: ");
  Serial.println(numeroDisplay);
  
  delay(1000);
}

void mostrarNumero(int numero)
{
  for (int i = 0; i < 7; i++){
    digitalWrite(
      segmentos[i],
      numeros[numero][i]
    );
  }
}
