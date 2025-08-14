#include <SPI.h>// Import SPI library

#define SCK_PIN  13
#define MISO_PIN 12
#define MOSI_PIN 11
#define SS_PIN   10   // broche de séléction de l'esclave 1
#define SS_PIN_2   9  // broche de séléction de l'esclave 2

void setup()
{
  pinMode(MOSI_PIN, OUTPUT);
  pinMode(MISO_PIN, INPUT);
  pinMode(SCK_PIN, OUTPUT);
  pinMode(SS_PIN, OUTPUT);
  pinMode(SS_PIN_2, OUTPUT);
  digitalWrite(SS_PIN, HIGH); // l'esclave 1 n'est pas addressé
  digitalWrite(SS_PIN_2, HIGH);  // l'esclave 1 n'est pas addressé
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV64); // Définition du CLOCK du maitre
                                        // 4MHz divisé par 64 ce qui donne 62.5KHZ
  Serial.begin(9600);
}


void loop()
{
 digitalWrite(SS_PIN, LOW);  // selection de l'esclave 1
 SPI.transfer('C'); // envoie du caractére C
  delayMicroseconds(20);
  SPI.transfer('\n'); // envoie d'un retour à la ligne
  delayMicroseconds(20);
  digitalWrite(SS_PIN, HIGH);  // déselection de l'esclave 1
 delay(200);
 digitalWrite(SS_PIN_2, LOW);  // selection de l'esclave 2
 SPI.transfer('C'); // envoie du caractére C
  delayMicroseconds(20);
  SPI.transfer('\n'); // envoie d'un retour à la ligne
  delayMicroseconds(20);
  digitalWrite(SS_PIN_2, HIGH);  // déselection de l'esclave 2
 delay(200);
}
