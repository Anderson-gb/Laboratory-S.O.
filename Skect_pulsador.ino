
const int amarillo = 12;
const int rojo = 11;
const int boton = 2;

int modo = 5;
int ultimoModo = 0;

unsigned long t = 0;
int estado = 0;
bool parpadeo = 0;

void setup() {
  Serial.begin(9600);
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
}

void loop() {

  static bool bAnt = HIGH;
  bool b = digitalRead(boton);

  if (b == LOW && bAnt == HIGH) {
    modo++;
    if (modo > 5) modo = 1;
  }
  bAnt = b;

  unsigned long ahora = millis();

  if (modo != ultimoModo) {
    Serial.print("Modo: ");
    Serial.println(modo);
    ultimoModo = modo;
  }

  switch (modo) {

    case 1:
      digitalWrite(verde, 1);
      digitalWrite(amarillo, 0);
      digitalWrite(rojo, 0);
      break;

    case 2:
      if (ahora - t > 500) {
        t = ahora;
        parpadeo = !parpadeo;
        digitalWrite(verde, parpadeo);
        digitalWrite(amarillo, parpadeo);
        digitalWrite(rojo, parpadeo);
      }
      break;

    case 3:
      if (ahora - t > 500) {
        t = ahora;
        parpadeo = !parpadeo;
        digitalWrite(amarillo, parpadeo);
      }
      digitalWrite(verde, 0);
      digitalWrite(rojo, 0);
      break;

    case 4:
      digitalWrite(verde, 0);
      digitalWrite(amarillo, 0);
      digitalWrite(rojo, 0);
      break;

    case 5:
      if (ahora - t > 1000) {
        t = ahora;
        estado++;
        if (estado > 2) estado = 0;

        digitalWrite(verde, estado == 0);
        digitalWrite(amarillo, estado == 1);
        digitalWrite(rojo, estado == 2);
      }
      break;
  }
}