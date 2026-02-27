

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {

  for (int numero = 1; numero <= 20; numero++) {

    for (int bit = 0; bit < 6; bit++) {

      if (numero & (1 << bit)) {
        digitalWrite(leds[bit], HIGH);
      } else {
        digitalWrite(leds[bit], LOW);
      }

    }

    delay(1000);
  }

}