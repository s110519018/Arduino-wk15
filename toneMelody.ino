/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_B5, NOTE_D6, NOTE_FS6,NOTE_D6,
  NOTE_AS5, NOTE_CS6, NOTE_E6,NOTE_CS6, 
  NOTE_B5, NOTE_D6, NOTE_FS6,NOTE_D6,
  NOTE_AS5, NOTE_CS6, NOTE_E6,NOTE_A6,
  NOTE_G6, NOTE_FS6,NOTE_E6,NOTE_G6,NOTE_FS6,NOTE_E6,NOTE_D6,NOTE_CS6,
  NOTE_B6,NOTE_G6,NOTE_FS6,NOTE_E6,
  NOTE_D6,NOTE_B6,NOTE_GS6,
  NOTE_D6,NOTE_B6,NOTE_GS6,
  NOTE_D6,NOTE_B6,NOTE_GS6,
  NOTE_D6,NOTE_B6,NOTE_GS6,
  NOTE_AS6,NOTE_B6,NOTE_CS7,NOTE_B6,NOTE_AS6,NOTE_AS6,
  NOTE_AS6,NOTE_GS6,NOTE_AS6,NOTE_B6,NOTE_AS6
  };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  2,2,2,2,
  4,4,2,
  4,4,2,
  4,4,2,
  4,4,2,
  8,8,8,8,4,4,
  4,8,8,4,2
  
};
int greenPin = 6;
int redPin = 9;
int bluePin = 5;
int counter = 0;//狀態切換

void setup() {
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);

  // iterate over the notes of the melody:
  for(int x=0;x<3;x++){

  for (int thisNote = 0; thisNote < 51; thisNote++) {
       counter++;
  if(counter == 1){//點亮綠色
    analogWrite(greenPin,125);
    analogWrite(redPin,125);
    analogWrite(bluePin,0);
  }
  else if(counter == 2){//點亮紅色
    analogWrite(greenPin,0);
    analogWrite(redPin,125);
    analogWrite(bluePin,125);
  }
  else if(counter == 3){//點亮藍色
    analogWrite(greenPin,125);
    analogWrite(redPin,0);
    analogWrite(bluePin,120);
  } 
     else if(counter == 4){//點亮藍色
    analogWrite(greenPin,150);
    analogWrite(redPin,255);
    analogWrite(bluePin,0);
    counter = 0;//歸零
  }
//  delay(50);
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1800 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);

  }
    

}
 
}
void loop() {
  // no need to repeat the melody.
}
