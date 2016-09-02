#include <SoftwareSerial.h>
int val = 0;
int bot;
unsigned long i = 0;
unsigned long d = 0;
int bot2;
int b;
int g;
int h;
int j;
int arreglo1[20];
int arreglo2[20];
int arreglo3[20];
int arreglo4[20];
unsigned long tiempo;
unsigned long tiempo2;
unsigned long tiempo3;
unsigned long tiempof;
SoftwareSerial XBee(0, 1); // Arduino RX, TX (XBee Dout, Din)

void setup() {
  //Serial.begin(9600);
  XBee.begin(9600);
  pinMode(2, INPUT);
  pinMode(8, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), xbee, RISING);
}

void loop() {
  val = digitalRead(2);
  bot = digitalRead(8);

  if (bot == 1 && bot2 == 0) {
    i = millis();
    arreglo2[j] = millis();
    bot2 = 1;
    j++;
  }
  if  (bot == 0 && bot2 == 1) {
    d = millis();
    bot2 = 0;
    tiempo = d - i;
    arreglo1[g] = tiempo;
    g++;
  }

}
void xbee() {
  if (tiempo != 0 && tiempo != tiempo3) {
    tiempof = millis();
    tiempo2 = tiempof - i;
    
    String stringuno = "[  Tiempo =  ";
    String stringdos = "   Momento =  ";
    String stringfinal = "  ]";
    String stringtres = "A";
    for (b = 0; b < 20; b++) {
      arreglo3[b] = tiempof - arreglo2[b];
      if (arreglo1[b] > 10) {
        //XBee.print (stringuno + arreglo1[b] + stringdos + arreglo3[b] + stringfinal);
        XBee.print ( arreglo1[b] + stringtres + arreglo3[b]);
        //XBee.print(arreglo1[b]);
        //Serial.print(arreglo1[b]);
        //  Serial.write(arreglo1[b]);

      }
    }
    tiempo3 = tiempo;
    g = 0;
    for (h = 0; h < 21; h++) {
      arreglo1[h] = 0;
    }
  }
}

