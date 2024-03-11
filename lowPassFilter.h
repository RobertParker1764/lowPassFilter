//===================================================================
// File: lowPassFilter.h
// Robert Parker
// 3/10/2024
// Version 1.0
//
// Implements a simple low pass filter.
// Credit to Phil's Lab for code ideas

#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H

//===================================================================
// Class LowPassFilter
// ==================================================================
// A simple low pass filter
// ==================================================================

class LowPassFilter {
public:
  void init(float cutOffFrequency, float sampleTime);
  void update(float newRawValue);
  float getCurrentFilteredValue();

private:
  float coefficients[2];
  float previousFilteredValue;
  float currentFilteredValue;
};

#endif