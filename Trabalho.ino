#include <Thermistor.h>
#include "pitches.h"

 int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
    4, 8, 8, 4,4,4,4,4 };
  
  void rdyCoffee(){
    for (int thisNote = 0; thisNote < 8; thisNote++) {
  
      // to calculate the note duration, take one second 
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000/noteDurations[thisNote];
      tone(8, melody[thisNote],noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
    }
  }


Thermistor temp(0); 
void setup() {
  //verde
  pinMode(33, OUTPUT);
  //vermelho
  pinMode(35, OUTPUT);
  //azul
  pinMode(37,OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  //variavel que armazena temperatura
  int temperature = temp.getTemp()-(2*temp.getTemp());
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println("°C");
  delay(100);
  //chama o metodo do aviso sonoro
  
 
  //se quente:vermelho, se morno:verde,se frio:azul
  if ((temperature>=19)&& (temperature<= 20)){
    //liga e desliga o verde na temperatura ideal
    digitalWrite(33, HIGH);
    delay(800);                     
    rdyCoffee();
    digitalWrite(33, LOW);    
    delay(100);
    

  //vermelho ligado se não tiver na temperatura ideal
  }else if(temperature<= 18){
    digitalWrite(35,HIGH);
    delay(100);
    digitalWrite(35,LOW);
    delay(100);

  //azul ligado por estar muito frio
  }else if(temperature>=21){
    digitalWrite(37,HIGH);
    delay(100);
    digitalWrite(37,LOW);
    delay(100);
  }
}
