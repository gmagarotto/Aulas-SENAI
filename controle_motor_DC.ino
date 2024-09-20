#include <SoftwareSerial.h>
#define MOTOR_A_CW 2
#define MOTOR_A_CCW 3

#define MOTOR_B_CW
#define MOTOR_B_CCW

#define MOTOR_C_CW
#define MOTOR_C_CCW

#define ARD_BT_RX 6  // Arduino RX () -> Bluetooth TXD
#define ARD_BT_TX 7  // Arduino RX () -> Bluetooth RXD

SoftwareSerial bluetooth(ARD_BT_RX, ARD_BT_TX);

void setup() {
  pinMode(MOTOR_A_CW, OUTPUT);
  pinMode(MOTOR_A_CCW, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(10);
  bluetooth.begin(9600);
}

void loop() {
  char comando = 0;
  char letra = 0;
  if (bluetooth.available() > 0) {
    letra = bluetooth.read();
  }
  if (letra == 'W') {
    digitalWrite(MOTOR_A_CW, HIGH);
    digitalWrite(MOTOR_A_CCW, LOW);
    bluetooth.print("*MCARRINHO INDO PRA FRENTE\n*");
    Serial.println("Motor girando para frente");
  }
  if (letra == 'A') {
    digitalWrite(MOTOR_A_CW, LOW);
    digitalWrite(MOTOR_A_CCW, HIGH);
    bluetooth.print("*MCARRINHO INDO PRA TRAS\n*");
    Serial.println("Motor girando para tras");
  }
  if (letra == 'D') {
    digitalWrite(MOTOR_A_CW, LOW);
    digitalWrite(MOTOR_A_CCW, LOW);
    bluetooth.print("*MCARRINHO PARADO\n*");
    Serial.println("Motor parado");
  }


  if (Serial.available() > 0) {
    comando = Serial.read();
    Serial.print("Recebido: ");
    Serial.println(comando);
    // Comando para ir pra frente.
    if (comando == 'W') {
      digitalWrite(MOTOR_A_CW, HIGH);
      digitalWrite(MOTOR_A_CCW, LOW);
      Serial.println("Motor girando para frente");
    }
    // Comando para dar ré.
    if (comando == 'S') {
      digitalWrite(MOTOR_A_CW, LOW);
      digitalWrite(MOTOR_A_CCW, HIGH);
      Serial.println("Motor girando para tras");
    }
    // Comando pra parar.
    if (comando == 'X') {
      digitalWrite(MOTOR_A_CW, LOW);
      digitalWrite(MOTOR_A_CCW, LOW);
      Serial.println("Motor parado!");
    }
  }
}