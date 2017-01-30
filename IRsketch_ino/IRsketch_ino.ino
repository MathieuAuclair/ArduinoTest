#include <IRremote.h>

int RECV_PIN = 11;
boolean blinkMode = false, power = false;
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
    if(results.value == 16753245)//power button
    {
      if(!blinkMode)
      {
        if(digitalRead(13) == LOW)
          {
            digitalWrite(13, HIGH);
          }
        else
        {
          digitalWrite(13, LOW);
        }
      }
      else
      {
        blinkMode = false;
        digitalWrite(13, LOW);
      }
    }
    else if(results.value == 16736925 && digitalRead(13) == HIGH)//change mode button
        {
          if(blinkMode)
            blinkMode = false;
          else
            blinkMode = true;
        }
    irrecv.resume(); // Receive the next value
    
  }
  
  if(blinkMode)
    {
      digitalWrite(13, LOW);
      delay(50);
      digitalWrite(13, HIGH);
      delay(50);
    }
    else
      delay(100);
}
