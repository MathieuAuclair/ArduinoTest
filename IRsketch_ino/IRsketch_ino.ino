#include <IRremote.h>

int RECV_PIN = 11;
char ctrlSignal;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    if(results.value == 16753245)
    {
      if(digitalRead(13) == LOW)
        digitalWrite(13, HIGH);
      else
        digitalWrite(13, LOW);
    }
    irrecv.resume(); // Receive the next value
    
  }
  delay(100);
}
