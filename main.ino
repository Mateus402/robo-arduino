// Definições dos pinos
const int motorDireito = 9;
const int motorEsquerdo = 11;
const int LDRMeio = A0;
const int LDRDireito = A1;
const int LDREsquerdo = A2;

// Valor base para comparação
const int valorBase = 400;

void setup() {
  Serial.begin(9600);
  pinMode(motorDireito, OUTPUT);
  pinMode(motorEsquerdo, OUTPUT);
}

void loop() {
  // Leitura dos valores dos sensores
  int sensorMeio = analogRead(LDRMeio);
  int sensorDireito = analogRead(LDRDireito);
  int sensorEsquerdo = analogRead(LDREsquerdo);

  // Imprime a leitura dos sensores LDR
  Serial.print("Meio: ");
  Serial.println(sensorMeio);
  Serial.print("Direito: ");
  Serial.println(sensorDireito);
  Serial.print("Esquerdo: ");
  Serial.println(sensorEsquerdo);
  Serial.println("____________");

  // Decisão de movimento baseada nos sensores
  if(sensorMeio > valorBase && sensorDireito < valorBase && sensorEsquerdo < valorBase || sensorMeio > valorBase && sensorDireito > valorBase && sensorEsquerdo > valorBase) {
    andarFrente();
  } else if(sensorDireito > valorBase && sensorEsquerdo < valorBase) {
    virarDireita();
  } else if(sensorEsquerdo > valorBase && sensorDireito < valorBase) {
    virarEsquerda();
  } else {
    parar();
  }
  
  delay(100); // Ajuste o delay conforme necessário para melhor resposta
}

void andarFrente() {
  digitalWrite(motorDireito, HIGH);
  digitalWrite(motorEsquerdo, HIGH);
}

void virarDireita() {
  digitalWrite(motorDireito, LOW);
  digitalWrite(motorEsquerdo, HIGH);
}

void virarEsquerda() {
  digitalWrite(motorDireito, HIGH);
  digitalWrite(motorEsquerdo, LOW);
}

void parar() {
  digitalWrite(motorDireito, LOW);  
  digitalWrite(motorEsquerdo, LOW);

}