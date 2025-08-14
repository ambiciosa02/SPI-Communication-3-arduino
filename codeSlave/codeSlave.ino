#include <SPI.h> // Import SPI library

#define SCK_PIN 13
#define MISO_PIN 12
#define MOSI_PIN 11
#define SS_PIN   10  
int i=0;
char k[20],v[20];
int valid=0;

void setup (void)
{
  Serial.begin (9600);  
  pinMode(MOSI_PIN, INPUT);
  pinMode(MISO_PIN, OUTPUT);
  pinMode(SCK_PIN, INPUT);
  pinMode(SS_PIN, INPUT);
  SPCR |= _BV(SPE);
  SPCR != _BV(SPIE);
  SPI.attachInterrupt();
}
ISR (SPI_STC_vect) // interruption appelé lors réception d'un caractére
{
char c = SPDR;  // Lire le caractere recu, SPDR registre de reception
if(c!='\n') // si le caractere n'est pas un retour à la ligne

{
 k[i]=c; // on le stocke de la tableau K[i]
  i++;
}
else if(c=='\n' ) // si le caractere recu est un retour à la ligne
{
  
  Serial.println(k); // on affiche le tableau K dans le moniteur série
  i=0;
}
}

void loop (void)
{
while(1);
}
