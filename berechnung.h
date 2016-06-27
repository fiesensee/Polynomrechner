#ifndef BERECHNUNGHEADER_H
#define BERECHNUNGHEADER_H value

void printPolynom(float coefficents[], int length);

void calculateIntegral(float coefficents[]);

void calculateDerivative(float coefficents[]);

void writeCalculatedValues(float coefficents[], float calculatedCoefficents[], int length);

float calculatePolynomalValue(float coefficents[], float position, int length);

float * getDomain();

#endif
