set title 'Polynom-Rechner'
set xlabel 'X'
set ylabel 'Y'
if (save==1) {
  set term postscript eps enhanced
  set output 'grafik.ps'
  plot 'werte.dat' title 'Pol' lc rgb 'red', 'werte.dat' using 3 title 'Stm/Abl' lc rgb 'green'
} else {
  plot 'werte.dat' title 'Pol' lc rgb 'red', 'werte.dat' using 3 title 'Stm/Abl' lc rgb 'green'
  pause -1
}
