/*
  Note.h - Library for playing musical notes on a Parallax Serial LCD with speaker (#27977-RT).
  Created by Philip Youssef, November 3, 2012.
*/
#ifndef Note_h
#define Note_h
#include "Arduino.h"

class Note
{
  public:
    Note(char* key,int octave,int length);
    void playNote();
    void playNoteAndWait();
  private:
   char *key;
   int octave;
   int length;
   int hashNoteLength(int length);
   int hashNoteKey(char *key);
   int hashNoteOctave(int octave);
   void printNote();
};
#endif
