#include <Arduino.h>



void writedata(int address, byte value) {
  while (EECR & (1 << EEPE)) {}
  EEAR = address;
  EEDR = value;
  EECR |= (1 << EEMPE);
  EECR |= (1 << EEPE);
}


byte readdata(int address) {
  while (EECR & (1 << EEPE)) {}
  EEAR = address;
  EECR |= (1 << EERE);
  return EEDR;
}
void setup() {
  Serial.begin(2400);
}

void loop() {
  if (Serial.available() > 0) {
    String received = Serial.readStringUntil('\n');

    int addr = 0;
    int Len = received.length();
    for (int i = 0; i < Len; i++) {
      writedata(addr + i, received[i]);
    }

    Serial.println(received);

    delay(100);
  }

  if (readdata(0) != 0) {
    String Stringsent = "";
    int addr = 0;
    int Len = readdata(addr);
    for (int i = 0; i < Len; i++) {
      char ch = readdata(addr + 1 + i);
      Stringsent += ch;
    }
    Serial.println(Stringsent);

    for (int i = 0; i < E2END; i++) {
      writedata(i, 0);
    }

    delay(100);
  }
}
