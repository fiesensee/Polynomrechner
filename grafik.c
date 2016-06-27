#include <stdio.h>
#include <stdlib.h>
#include "grafik.h"

void drawGraph() {

  int state = 1;

  while (state != 0) {
    state = getDisplayMethod();
  }

  printf("%s\n", "");

}

int getDisplayMethod() {

  int displayMethod;

  printf("%s\n", "Entscheiden sie bitte wie sie den Graphen ausgeben moechten");
  printf("%s\n", "1-Auf ihrem Bildschirm anzeigen");
  printf("%s\n", "2-In einer Datei speichern");
  scanf("%d", &displayMethod);

  if (displayMethod == 1) {
    showPlot();
  } else if (displayMethod == 2) {
    savePlot();
  } else {
    printf("%s\n", "Ungueltige Eingabe, bitte versuchen sie es erneut.");
    return 1;
  }

  return 0;
}

void showPlot() {
  system("gnuplot -e 'save=0' grafik.gnu");
}

void savePlot() {
  system("gnuplot -e 'save=1' grafik.gnu");
}
