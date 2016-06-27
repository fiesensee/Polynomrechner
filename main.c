#include <stdio.h>
#include "main.h"
#include "berechnung.h"
#include "grafik.h"

int main() {

  int state;

  printf("%s\n", "Hallo und Willkommen");
  state = runMenu();
  while(state != 0) {
    state = runMenu();
  }

}

int runMenu() {

  int program = 0;

  program = getProgramm();
  if (program == 4) {
    return 0;
  }
  executeProgramm(program);
  return 1;
}

int getProgramm() {

  int program = 0;

  while (program != 1 && program != 2 && program != 3 && program != 4) {
    printf("%s\n", "Bitte gib ein welches Programm du benutzten moechtest: ");
    printf("%s\n", "1-Gib dein Polynom ein");
    printf("%s\n", "2-Berechne die Stammfunktion");
    printf("%s\n", "3-Berechne die Ableitung");
    printf("%s\n", "4-Beende das Programm");

    scanf("%d", &program);

    if (program != 1 && program != 2 && program != 3 && program != 4) {
      printf("%s\n", "Non-valid input, please try again.");
    }

  }
  return program;

}

void executeProgramm(int program) {

  if (program == 1) {
    setCoefficents();
  } else if (program == 2) {
    calculateIntegral(coefficents);
    drawGraph();
  } else if (program == 3){
    calculateIntegral(coefficents);
    drawGraph();
  }
}

void setCoefficents() {

  printf("%s\n", "Der Polynomgrad darf hoechstens 5 sein.");
  printf("%s\n", "Die Form des Polynoms ist p(x)=k1 * x^5 + k2 * x^4 + k3 * x^3 + k4 * x^2 + k5 * x + k6");
  printf("%s\n", "Fuehrende Nullen muessen angegeben werden.");

  for (int i = 0; i < 6; i++) {
    float coefficent;
    printf("%s%d%s\n", "Bitte gib Koeffizienten Nummer ", i + 1, " ein");
    scanf("%f", &coefficent);
    coefficents[i] = coefficent;
  }

  //test
  for (int i = 0; i < 6; i++) {
    printf("%f\n", coefficents[i]);
  }
}
