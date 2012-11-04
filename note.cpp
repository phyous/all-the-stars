/*
  Note.cpp - Library for playing musical notes on a Parallax Serial LCD with speaker (#27977-RT).
  Created by Philip Youssef, November 3, 2012.
*/
#include "note.h"
#include "Arduino.h"
#include <stdio.h>

Note::Note(char* _key,int _octave, int _length)
{
  key = _key;
  octave = _octave;
  length = _length;
}

void Note::playNote(){
  int l = hashNoteLength(length);
  int o = hashNoteOctave(octave);
  int k = hashNoteKey(key);
  
  Serial.write(hashNoteLength(length));      // Set length
  Serial.write(hashNoteOctave(octave));      // Set octave
  Serial.write(hashNoteKey(key));            // Play note
}

void Note::playNoteAndWait(){
  playNote();
  delay(2000/length);   
}

/* Convert user friendly note timing to parallax device code 
/  {1,  2,  4,  8,  16, 32, 64} => 
/  {214,213,212,211,210,209,208}
/ See http://www.parallax.com/Portals/0/Downloads/docs/prod/audiovis/27976-7-9-ParallaxSerialLCD-v3.0.pdf
*/ 
int Note::hashNoteLength(int length){
  if(length == 1) {return 214;}
  else if(length == 2) {return 213;}
  else if(length == 4) {return 212;}
  else if(length == 8) {return 211;}
  else if(length == 16) {return 210;}
  else if(length == 32) {return 209;}
  else if(length == 64) {return 208;}
}

/* Convert user friendly note code to parallax device code
/ {"A","A#","B","C","C#","D","D#","E","F","F#","G","G#"} =>
/ {220,221, 222,223,224, 225, 226,227,228,229, 230,231} 
*/
int Note::hashNoteKey(char *key){
  if(key[0] == 'A'){
    if(key[1] == '#'){ return 221;}
    else{return 220;} 
  } else if (key[0] == 'B'){
    if(key[1] == '#'){ return 222;}
  } else if  (key[0] == 'C'){
    if(key[1] == '#'){ return 224;}
    else{return 223;}   
  } else if  (key[0] == 'D'){
    if(key[1] == '#'){ return 226;}
    else{return 225;}   
  } else if  (key[0] == 'E'){
    return 227;
  } else if  (key[0] == 'F'){
    if(key[1] == '#'){ return 229;}
    else{return 228;}
  } else if  (key[0] == 'G'){
    if(key[1] == '#'){ return 231;}
    else{return 230;} 
  }
}

/* Convert user friendly octave code to parallax device code
/ {3,  4,  5,  6,  7} =>
/ {215,216,217,218,219} 
/ Octave higher than 7 or lower than 3 are not allowed (default to nearest octave)
*/
int Note::hashNoteOctave(int octave){
 if(octave < 3){octave = 3;}
 if(octave > 7){octave = 7;}
 return octave + 212;
}

void Note::printNote(){
  char buffer [15];
  //sprintf(buffer, "K:%s L:%d O:%d \n",key, length, octave);
  sprintf(buffer, "|K:%s|",key, length, octave);
  Serial.print(buffer);
}
