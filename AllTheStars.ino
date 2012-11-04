#include "note.h"
#include "lightController.h"
#include "math.h"

int lights[] = {2,3,4,5,8,9,10,11};
int lightCount = 8;
int lightState = 0;
LightController *lc;

// the setup routine runs once when you press reset:
void setup() { 
  Serial.begin(9600);                  // Set baud rate for serial connection
  Serial.write(0x11);                  // Turn backlight on
  Serial.write(0x0C);                  // Clear screen 
  lc = new LightController(lights, lightCount); 
  
  // Initialize the led pins as an output.
  for(int i=0; i< lightCount;i++){
    pinMode(lights[i], OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  playOdeToJoy();
}

int L_ALL_OFF   = 0b00000000;
int L_ALL_ON    = 0b11111111;
int L_X         = 0b10101010;
int L_X_REV     = 0b01010101;
int L_SQUARE    = 0b01100110;
int L_PAIR_1    = 0b10000010;
int L_PAIR_2    = 0b00100010;
int L_PAIR_3    = 0b00101000;
int L_PAIR_4    = 0b00011000;
int L_C_PAIR_1    = 0b10000001;
int L_C_PAIR_2    = 0b01000010;
int L_C_PAIR_3    = 0b00100100;
int L_C_PAIR_4    = 0b00011000;

void playOdeToJoy(){
  // First Phrase
  play("E",4,4, L_ALL_OFF, "This"); 
  play("E",4,4, L_SQUARE, "is"); 
  play("F",4,4, L_PAIR_3, "the"); 
  play("G",4,4, L_PAIR_4, "greatest"); 
  play("G",4,4, L_PAIR_2, "holi"); 
  play("F",4,4, L_PAIR_3, "holiday"); 
  play("E",4,4, L_PAIR_2, "song"); 
  play("D",4,4, L_PAIR_1, "ever!"); 
  play("C",4,4, L_X, "jingle"); 
  play("C",4,4, L_ALL_OFF, "bells"); 
  play("D",4,4, L_X, "all"); 
  play("E",4,4, L_X, "of");
  play("E",4,2, L_X_REV, "the"); 
  play("D",4,8, L_ALL_OFF, "way!");
  play("D",4,4, L_SQUARE, "hey!");
  syncAudio(25);
  
  // Second Phrase
  play("E",4,4, L_ALL_OFF, "lights"); 
  play("E",4,4, L_SQUARE, "and"); 
  play("F",4,4, L_PAIR_3, "ma"); 
  play("G",4,4, L_PAIR_4, "magic"); 
  play("G",4,4, L_PAIR_2, "bee"); 
  play("F",4,4, L_PAIR_3, "beeping"); 
  play("E",4,4, L_PAIR_2, "and"); 
  play("D",4,4, L_PAIR_1, "boo"); 
  play("C",4,4, L_ALL_ON, "booping"); 
  play("C",4,4, L_ALL_OFF, "sounds"); 
  play("D",4,4, L_ALL_ON, "to"); 
  play("E",4,4, L_X, "make");
  play("D",4,2, L_X_REV, "an"); 
  play("C",4,8, L_ALL_OFF, "angel");
  play("C",4,4, L_ALL_OFF, "cry");
  syncAudio(25);
  
  // Fancy part
  play("D",4,4, L_ALL_OFF, "na");
  play("D",4,4, L_C_PAIR_1, "na na");
  play("E",4,4, L_C_PAIR_2, "na na na");
  play("C",4,4, L_C_PAIR_3, "na");
  play("D",4,4, L_C_PAIR_4, "NA!");
  play("E",4,8, L_C_PAIR_3, "NA NA NA!");
  play("F",4,8, L_C_PAIR_2, "NA NA NA NA!");
  play("E",4,8, L_C_PAIR_1, "NA NA NA NA NA!");
  play("C",4,8, L_ALL_OFF, "NAAAAAAAAAA!!A!");
  syncAudio(25); 
  
  play("D",4,4, L_C_PAIR_1, ":)");
  play("E",4,8, L_C_PAIR_2, ":D");
  play("F",4,8, L_C_PAIR_3, ":D!");
  play("E",4,8, L_C_PAIR_4, ":D!!");
  play("D",4,8, L_C_PAIR_3, ":D!!!");
  play("C",4,8, L_C_PAIR_2, ":D!!!!");
  play("D",4,8, L_C_PAIR_1, ":D!!!!");
  play("G",3,4, L_ALL_OFF, "<<<< ^_^ >>>");
  syncAudio(25); 
  
  // Second phrase again
  play("E",4,4, L_ALL_OFF, "/"); 
  play("E",4,4, L_SQUARE, "/|"); 
  play("F",4,4, L_PAIR_3, "/|\\"); 
  play("G",4,4, L_PAIR_4, "/|\\@"); 
  play("G",4,4, L_PAIR_2, "@/|\\@"); 
  play("F",4,4, L_PAIR_3, "(@/|\\@)"); 
  play("E",4,4, L_PAIR_2, "!(@/|\\@)!"); 
  play("D",4,4, L_PAIR_1, "!(@/|\\@)!"); 
  play("C",4,4, L_X_REV, "!(@/|\\@)!"); 
  play("C",4,4, L_ALL_OFF, "-(@/|\\@)-"); 
  play("D",4,4, L_X_REV, "--@/|\\@--"); 
  play("E",4,4, L_X, "---/|\\---");
  play("D",4,2, L_X_REV, "----|----"); 
  play("C",4,8, L_ALL_OFF, "----<----");
  play("C",4,4, L_SQUARE, "----<3----");
  delay(10000);
}

void play(char* key, int octave, int length, int lightSetting, char* str){
  lc->setLights(lightSetting);
  Note(key,octave,length).playNote();
  printToDisplay(str);
  delay(2000/length);
  syncAudio(25);
}

void syncAudio(int syncDelay){
  delay(syncDelay);    
}

void printToDisplay(char* str){
  Serial.write(0x0C); 
  Serial.print(str);
}


