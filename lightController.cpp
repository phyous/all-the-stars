/*
  lightController.cpp - Library for playing musical notes on a Parallax Serial LCD with speaker (#27977-RT).
  Created by Philip Youssef, November 3, 2012.
*/
#include "lightController.h"
#include "Arduino.h"

LightController::LightController(int* _lights, int _numLights)
{
  lights = _lights;  
  numLights = _numLights;
}

/*
/ lightSetting represents a set of bits corresponding to the lights that are on//off
/ Ex: 0b1001 - {on, off, off, on}
*/
void LightController::setLights(int lightSetting){
  for(int i = 0; i < numLights; i++){
    if(readLight(lightSetting, i)){
      digitalWrite(lights[i], HIGH);
    } else {
      digitalWrite(lights[i], LOW);
    }   
  } 
}


boolean LightController::readLight(int lightSetting, int pos){
  return  lightSetting & (0b1 << pos);
}
