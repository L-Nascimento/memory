// Define os pinos que serão utilizados para controle da ponte H
int ENA = 6; // pino PWM para controle da velocidade do motor
int IN1 = 7; // pino para controlar o sentido de rotação do motor
int IN2 = 8; // pino para controlar o sentido de rotação do motor

void setup() {
  // Configura os pinos como saída
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  // Inicializa o motor parado
  digitalWrite(ENA, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void loop() {
  // Verifica se recebeu o comando para girar o motor para frente (comando = 1)
  if (Serial.available() > 0) {
    int comando = Serial.read();
    if (comando == 1) {
      // Gira o motor para frente
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 255); // Define a velocidade do motor (0-255)
      delay(1000); // Aguarda 1 segundo
      // Para o motor
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 0);
    }
  }
}
