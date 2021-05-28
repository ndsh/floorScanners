/*
    · · · · · · · · · · · · · · · · · · · · ·

    SensorHead.h
    https://github.com/ndsh/floorScanners

    Copyright (c) 2016 - 2021

    · · · · · · · · · · · · · · · · · · · · ·
*/

#ifndef SENSORHEAD_H
#define SENSORHEAD_H

#include <Arduino.h>

class SensorHead {
	public:
		SensorHead(uint8_t _sensorPin, uint8_t _ledPin);

		void update();
		void read();
		void toggleLED(bool b);
		void toggleDataParsing(bool b);

	private:
		uint8_t sensorPin;
		uint8_t ledPin;
		bool isParsing;
};

#endif