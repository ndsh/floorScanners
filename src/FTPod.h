/*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 FTPod.h
 Copyright (c) 2016 The Fine Tuning of Marble
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef FTPod_h
#define FTPod_h

//Main includes
#include <Arduino.h>
#include "FTScore.h"
#include "FTClock.h"
#include "FTMotor.h"
#include "FTSensor.h"
#include "FTSynth.h"
#include "FTCom.h"

//AO Library
#include <CFOSynthesizer.h>
#include <CFOMidi.h>
#include <Scale.h>
#include <MacAddress.h>

//Definitions
#define DEBUG_POD true

class FTPod
{
  public:

    FTPod(uint8_t sensorPin, uint8_t ledPin, uint8_t motorDirPin, uint8_t motorStepPin, long fullRevolution);

    void update();
    String getMacAddress();
    void retrieveMacAddress();

    int podState; //Contains the main state number of the POD. Each state action is defined by the Score.
    int movCounter; //Keeps track of the number of movements started by the motor.
    long fullRev; //Keeping FULLREV value
    String macAddress;
    int mID;

    

  private:

  	FTScore* Score = nullptr;
  	FTClock* Clock = nullptr;
  	FTMotor* Motor = nullptr;
  	FTSensor* Sensor = nullptr;
  	FTSynth* Synth = nullptr;
  	FTCom* Com = nullptr;

    void receiveCom();
    void setClock();
    void conductScore();
    void parseSensor();
    void moveMotor();
    void tuneSynth();
};

#endif