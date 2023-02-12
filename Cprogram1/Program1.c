/*
 * Program1.c
 *
 *  Created on: 11 Feb 2023
 *      Author: mirmacair
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main(void) {
  char filename[100];
  printf("name of file: ");
  scanf("%s", filename);

  FILE *file;
  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Could not open file %s", filename);
    return 1;
  }

  char line[MAX_LENGTH];

  char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  float sales[12];
  int i = 0;

  while (fgets(line, MAX_LENGTH, file) != NULL) {
    sscanf(line, "%f", &sales[i]);
    i++;
  }

  fclose(file);

  printf("\nMonthly sales report for 2022\n\n");
  printf("Month                   Sales\n");
  for (i = 0; i < 12; i++) {
    printf("%-10s              %.2f\n", months[i], sales[i]);
  }


  float min = sales[0];
  int mint = 0;

  for (i = 1; i < 12; i++) {
    if (sales[i] < min) {
      min = sales[i];
      mint = i;

    }
  }

  float max = sales[0];
  int maxt = 0;
  for (i = 1; i < 12; i++) {
    if (sales[i] > max) {
      max = sales[i];
      maxt = i;
    }
  }

  float average;

  for (i = 0; i < 12; i++){
	  average += sales[i];
  }

  average = average / 12;

  printf("\nSales summary:\n\n");
  printf("Minimum sales: %0.2f (%s)\n", min, months[mint]);
  printf("Maximum sales: %0.2f (%s)\n", max, months[maxt]);
  printf("Average sales: %0.2f", average);


  float first_six;
  float second_six;
  float third_six;
  float fourth_six;
  float fifth_six;
  float sixth_six;
  float seventh_six;

  for(i = 0; i < 12; i++){
	  if (i<=5 && i >= 0){
		  first_six += sales[i];
	  }
	  if (i<=6 && i >= 1){
	  		  second_six += sales[i];
	  }
	  if (i<=7 && i >= 2){
	  		  third_six += sales[i];
	  	  }
	  if (i<=8 && i >= 3){
	  		  fourth_six += sales[i];
	  	  }
	  if (i<=9 && i >= 4){
	  		  fifth_six += sales[i];
	  	  }
	  if (i<=10 && i >= 5){
	  		  sixth_six += sales[i];
	  	  }
	  if (i<=11 && i>=6){
	  		  seventh_six += sales[i];
	  }

  }


  printf("\n\nSix-Month moving average report:\n\n");

  printf("%s-%-12s   %10.2f\n",months[0],months[5],first_six / 6);
  printf("%s-%-11s   %10.2f\n", months[1],months[6],second_six / 6);
  printf("%s-%-14s   %10.2f\n",months[2],months[7],third_six / 6);
  printf("%s-%-14s   %10.2f\n",months[3],months[8],fourth_six / 6);
  printf("%s-%-16s   %10.2f\n",months[4],months[9],fifth_six / 6);
  printf("%s-%-15s   %10.2f\n", months[5],months[10],sixth_six / 6);
  printf("%s-%-15s   %10.2f\n",months[6],months[11],seventh_six / 6 );




  printf("\nSales report (highest to lowest):\n\n");
  printf("Month      Sales");


  for (int j = 0; j < 12; j ++)
  {
	  max = 0;
	  int location = 0;
	  for (i = 0; i < 12; i++) {
		if (sales[i] > max) {
		  max = sales[i];
		  location = i;
		}
	  }
	  printf("\n%-10s $%0.2f", months[location], sales[location] );
	  sales[location] = 0;
  }




  return 0;
}



