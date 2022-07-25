// IR remote controller decoder
// Based on https://github.com/crankyoldgit/IRremoteESP8266 example files



#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>



const int RECV_PIN = 21;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(115200);
  irrecv.enableIRIn();
}

void loop(){
  if (irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    irrecv.resume();
    Serial.println();
  }
}
