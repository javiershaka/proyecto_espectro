#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN            6

#define NUMPIXELS      40
int randomPixel ;
int boton1 = 8;
int boton2 = 9;
int boton3 = 10;
int boton4 = 11;
int vidas = 3;
long tiempoPrevio = 0;
boolean fv = false;
long dificultad = 100;
long tiempoRespuestaP = 0;
int presionado;
long intervaloTiempo = 3000;
long sumatoria = 2999;
long intervaloRespuesta = 2900;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  pinMode(boton3, INPUT_PULLUP);
  pinMode(boton4, INPUT_PULLUP);
  Serial.begin(9600);
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  unsigned long tiempoTranscurrido = millis();
  unsigned long tiempoRespuesta = millis();


  int colortime = 0;
  int constante ;
  pixels.setPixelColor(20, pixels.Color(0, 0, 0));
  pixels.show();

  
  if (tiempoTranscurrido - tiempoPrevio > intervaloTiempo && vidas > 0 ) {

   
    tiempoPrevio = tiempoTranscurrido;
    randomPixel = random(4);
    pixels.setPixelColor(19, pixels.Color(0, 0, 0));
    fv = false;
    intervaloTiempo -= dificultad;
    intervaloRespuesta -= dificultad;
    Serial.println(intervaloTiempo);
    Serial.println(intervaloRespuesta);
  }

  if (vidas <= 0) {
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));
    pixels.setPixelColor(2, pixels.Color(255, 0, 0));
    pixels.setPixelColor(3, pixels.Color(255, 0, 0));

    pixels.show();
    delay(5000);
  }
  if (randomPixel == 0) {
    pixels.setPixelColor(0, pixels.Color(0, 0, 255));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));
    pixels.show();
    presionado = digitalRead(boton1);
    if (presionado == 0 && tiempoTranscurrido - tiempoPrevio <  intervaloRespuesta) {
      pixels.setPixelColor(19, pixels.Color(0, 255, 0));
      pixels.show();

      fv = true;
      tiempoTranscurrido = 0;
      

    }
    if (fv == false && tiempoTranscurrido - tiempoPrevio  > intervaloRespuesta) {
      pixels.setPixelColor(19, pixels.Color(255, 0, 0));

      pixels.show();
      delay(500);
      vidas --;
    }



  }
  if (randomPixel == 1) {
    pixels.setPixelColor(1, pixels.Color(0, 0, 255));
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));
    pixels.show();
    presionado = digitalRead(boton2);

    if (presionado == 0 && tiempoTranscurrido - tiempoPrevio <  intervaloRespuesta) {
      pixels.setPixelColor(19, pixels.Color(0, 255, 0));
      pixels.show();
      fv = true;


    }
    if (fv == false && tiempoTranscurrido - tiempoPrevio  > intervaloRespuesta) {
      pixels.setPixelColor(19, pixels.Color(255, 0, 0));

      pixels.show();
      delay(500);
      vidas --;
    }
  }
  if (randomPixel == 2) {
    pixels.setPixelColor(2, pixels.Color(0, 0, 255));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));
    pixels.show();
    presionado = digitalRead(boton3);

    if (presionado == 0 && tiempoTranscurrido - tiempoPrevio <  intervaloRespuesta) {
      pixels.setPixelColor(19, pixels.Color(0, 255, 0));
      pixels.show();
      fv = true;


    }
    if (fv == false && tiempoTranscurrido - tiempoPrevio  > intervaloRespuesta) {
      pixels.setPixelColor(19, pixels.Color(255, 0, 0));

      pixels.show();

      delay(500);
      vidas --;
    }
  }
  if (randomPixel == 3) {
    pixels.setPixelColor(3, pixels.Color(0, 0, 255));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
    presionado = digitalRead(boton4);

    if (presionado == 0 && tiempoTranscurrido - tiempoPrevio <  intervaloRespuesta) {
      pixels.setPixelColor(19, pixels.Color(0, 255, 0));
      pixels.show();

      fv = true;


    }
    if (fv == false && tiempoTranscurrido - tiempoPrevio  > intervaloRespuesta) {
      pixels.setPixelColor(19, pixels.Color(255, 0, 0));

      pixels.show();
      delay(500);
      vidas --;

    }
  }

}
//for(int i=0;i<NUMPIXELS;i++){
//}

