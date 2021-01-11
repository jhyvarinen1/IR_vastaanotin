/* Luodaan objekti nimeltä irrecv, jossa määritetään tappi johon infrapunavastaanotin on kytketty */


#include <IRremote.h>

int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // käynnistää vastaanottimen
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, DEC); //printtaa monitoriin "tuloksen"
    irrecv.resume(); // vastaanottaa seuraavan arvon
  }
}
