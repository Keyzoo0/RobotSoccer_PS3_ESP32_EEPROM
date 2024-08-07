#include "variabel.h"

void setup() {
  Serial.begin(115200);
  setup_motor();
  PS4.begin("00:a5:54:bb:e3:be");
  removePairedDevices();  // This helps to   solve connection issues


}

void loop() {
     if(PS4.isConnected()){
      kontrol_motor();
     }
}

