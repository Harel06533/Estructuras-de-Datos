#include "date.h"

//Main
int main () {
  Date myDate = dateCreate(2003, 12, 25); 
  printDate(myDate);
  daysSum(myDate, 10);
  printDate(myDate);
  daysSub(myDate, 10);
  printDate(myDate);
  dateDestroy(myDate);
  return 0;
} 