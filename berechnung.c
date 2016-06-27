#include <stdio.h>
#include <math.h>
#include "berechnung.h"

void calculateDerivative(float coefficents[]) {

  float derivativeCoefficents[5] = { 0 };

  printPolynom(coefficents, 6);

  for (int i = 0; i < 6; i++) {
    derivativeCoefficents[i] = coefficents[i] * (5 - i);
  }

  printPolynom(derivativeCoefficents, 5);

  writeCalculatedValues(coefficents, derivativeCoefficents, 5);

}

void calculateIntegral(float coefficents[]) {

  float integralCoefficents[7] = { 0 };

  printPolynom(coefficents, 6);

  for (int i = 0; i < 6; i++) {
    integralCoefficents[i] = coefficents[i] / (6 - i);
  }

  printPolynom(integralCoefficents, 7);

  writeCalculatedValues(coefficents, integralCoefficents, 7);

}

void writeCalculatedValues(float coefficents[], float calculatedCoefficents[], int length) {

  float *domain;
  float stepLength;
  float currentCalculationPosition;
  FILE *values = fopen("werte.dat", "w");


  domain = getDomain();

  stepLength = (domain[1] - domain[0]) / 50;

  currentCalculationPosition = domain[0];

  for (int i = 0; i <= 51; i++) {

    float polynomalValue = calculatePolynomalValue(coefficents, currentCalculationPosition, 6);
    float calculatedValue = calculatePolynomalValue(calculatedCoefficents, currentCalculationPosition, length);
    fprintf(values, "%d %f %f\n", i, polynomalValue, calculatedValue);

    currentCalculationPosition += stepLength;
  }

  fclose(values);
}

float calculatePolynomalValue(float coefficents[], float position, int length) {
  float result = 0;

  for (int i = 0; i < length - 1; i++) {
    result += coefficents[i] * pow(position,(length - 1) - i);
  }

  result += coefficents[length - 1];

  return result;
}

void printPolynom(float coefficents[], int length) {
  for (int i = 0; i < length - 1; i++) {
    printf("%f * x^%d + ", coefficents[i], (length - 1) - i);
  }
  printf("%f\n", coefficents[length - 1]);
}

float * getDomain() {

  static float domain[2];

  printf("%s\n", "Bitte geben sie den Defintionsbereich an");
  printf("%s", "Von: ");
  scanf("%f", &domain[0]);
  printf("%s", "Bis: ");
  scanf("%f", &domain[1]);
  printf("\n");

  return domain;
}
