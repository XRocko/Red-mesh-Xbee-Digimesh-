#include <SoftwareSerial.h>
SoftwareSerial XBee(2, 3); // Arduino RX, TX (XBee Dout, Din)

void setup() 
{
  XBee.begin(9600);
  Serial.begin(9600);
  }

void loop()
{
    if(XBee.available()){      
      char c = XBee.read();
    Serial.print(c);
  }
  }
