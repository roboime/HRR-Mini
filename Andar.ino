/**@file Andar.ino  */

#include <Servo.h>

//Objetos da perna esquerda
Servo servo2;
Servo servo4;
Servo servo6;
Servo servo8;

//Objetos da perna direita
Servo servo1;
Servo servo3;
Servo servo5;
Servo servo7;

//Posições iniciais dos motores da esquerda
int pos2 = 100;
int posesq = 60;
int pos8 = 50;

//Posições iniciais dos motores da direita
int pos1 = 5;
int posdir = 110;
int pos7 = 180;


/**
 *  Configuração inicial do arduino e dos motores
 * */
void setup() {

//Inicialização dos motores da esquerda
  servo2.attach(52);
  servo4.attach(48);
  servo6.attach(44);
  servo8.attach(40);

//Inicialização dos motores da direita
  servo1.attach(34);
  servo3.attach(30);
  servo5.attach(24);
  servo7.attach(22);

  servo3.write(100);
  servo5.write(100);
  servo4.write(50);
  servo6.write(50);
}
/**
 * @brief Move as pernas para a frente em uma sequência de passos.
 *
 * Anda pra frente com ambas as pernas
 *
 */
 
void andarFrente(){
  for (int i = 0; i <= 7; i++) {
    //Perna esquerda
    servo2.write(pos2 + i);   
    servo8.write(pos8 + i);
    //Perna direita
    servo1.write(pos1 + i);   
    servo7.write(pos7 + i);
    delay(100);
  }

  delay(1000);


  while (posesq <= 70 && posdir <= 120) {
    servo4.write(posesq);
    servo6.write(posesq);
    servo3.write(posdir);
    servo5.write(posdir);
    delay(100);

    posesq += 1;
    posdir += 1;
  }

  delay(1000);

  for (int i = 0; i <= 7; i++) {
    //Perna esquerda
    servo2.write(pos2 + 7 - i);
    servo8.write(pos8 + 7 - i);
    //Perna direita
    servo1.write(pos1 + 7 - i);
    servo7.write(pos7 + 7 - i);
    delay(100);

  }

  delay(1000);

  while (posesq >= 50 && posdir >= 100) {
    servo4.write(posesq);
    servo6.write(posesq);
    servo3.write(posdir);
    servo5.write(posdir);

    delay(100);

    posesq -= 1; // Decrementa pos1
    posdir -= 1; // Incrementa pos2
  }

  delay(1000);
}

/**
 *  Loop principal do arduino
 * */
void loop() {
  andarFrente();
}
