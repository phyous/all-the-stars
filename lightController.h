/*
  lightController.h - Library for playing musical notes on a Parallax Serial LCD with speaker (#27977-RT).
  Created by Philip Youssef, November 3, 2012.
*/
#ifndef LightController_h
#define LightController_h
#include "Arduino.h"

class LightController
{
  public:
    LightController(int* lights, int numLights);
    void setLights(int lightSetting);
  private:
    int *lights;
    int numLights;
    boolean readLight(int lightSetting, int pos);
};
#endif
