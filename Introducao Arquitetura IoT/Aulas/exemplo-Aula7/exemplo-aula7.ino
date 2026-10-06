#include <Servo.h>


// Mapeamento dos pinos conforme o esquema do circuito
const int pinoPotenciometro = A0; // Sinal do potenciómetro no A0
const int pinoServo = 3;          // Sinal do servomotor no pino digital 3


Servo meuServo; // Criação do objeto Servo


void setup() {
  meuServo.attach(pinoServo); // Inicializa o servo no pino 3
}


void loop() {
  // Leitura do valor analógico do potenciómetro (variação de 0 a 1023)
  int valorPot = analogRead(pinoPotenciometro);
  
  // Limita e mapeia o movimento entre 50° e 110°
  valorPot = map(valorPot, 0, 1023, 50, 110);
  
  // Envia o ângulo calculado para o servomotor
  meuServo.write(valorPot);
  
  // Pequeno atraso para estabilização do movimento do servo
  delay(15);
}
