//===================================================================
// File: lowPassFilter.h
// Robert Parker
// 3/10/2024
// Version 1.0
//
// Implements a simple low pass filter.
// Credit to Phil's Lab for code ideas

#include "lowPassFilter.h"

//=========================================================================
// init
//=========================================================================
// Initializes the filter object. Call once before using the filter
//
// Parameters:
//   cutOffFrequency: The target filter cutoff frequency in Hz
//   sampleTime:  The sample time in seconds
// Return:  None
//==========================================================================
void LowPassFilter::init(float cutOffFrequency, float sampleTime) {
  previousFilteredValue = 0;
  currentFilteredValue = 0;

  float rcTimeConstant = 1.0f / (6.28318530718f * cutOffFrequency);
  coefficients[0] = sampleTime / (sampleTime + rcTimeConstant);
  coefficients[1] = rcTimeConstant / (sampleTime + rcTimeConstant);

}

//=========================================================================
// update
//=========================================================================
// Updates the filter given a new raw input value
//
// Parameters:
//   newRawValue: The new filter input value
// Return:  None
//==========================================================================
void LowPassFilter::update(float newRawValue) {
  previousFilteredValue = currentFilteredValue;
  currentFilteredValue = coefficients[0] * newRawValue + coefficients[1] * previousFilteredValue;
}

//=========================================================================
// getCurrentFilteredValue
//=========================================================================
// Returns the current filtered value
//
// Parameters: None
// Return:  The current filtered value
//==========================================================================
float LowPassFilter::getCurrentFilteredValue(void) {
  return currentFilteredValue;
}
