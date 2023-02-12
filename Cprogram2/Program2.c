/*
 * Program2.c
 *
 *  Created on: 11 Feb 2023
 *      Author: mirmacair
 */

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int a = 0;
int occurences[50];

void combinations(int array[],int score, int index){
	if(score < 0){
		return;
	}

	int count[5] = {0,0,0,0,0};
	char s1[20];
	char s2[20];
	char s3[20];
	char s4[20];
	char s5[20];



	if(score == 0){

		for (int i = 0; i < index; i++){
			if (array[i] == 8){
				count[0]++;
			}
			if (array[i] == 7){
				count[1]++;
			}
			if (array[i] == 6){
				count[2]++;
			}
			if (array[i] == 3){
				count[3]++;
			}
			if (array[i] == 2){
				count[4]++;
			}
		}






		for (int i = 0; i < 5; i++){
					if (i == 0){
						sprintf(s1, "%d", count[0]);
					}
					if (i == 1){
						sprintf(s2, "%d", count[1]);
					}
					if (i == 2){
						sprintf(s3, "%d", count[2]);
					}
					if (i == 3){
						sprintf(s4, "%d", count[3]);
					}
					if (i == 4){
						sprintf(s5, "%d", count[4]);
					}

				}

		strcat(s1, s2);
		strcat(s1, s3);
		strcat(s1, s4);
		strcat(s1, s5);

		int num = atoi(s1);


		for(int i = 0; i < sizeof(occurences); i++){
			if (occurences[i] == num){
				return;
			}
		}

		printf("\n");

		occurences[a] = num;
		a++;

		for (int i =0; i < 5; i++){
			if(i == 0){
				printf("%d TD + 2pt,", count[i]);
			}
			if(i == 1){
				printf(" %d TD + FG,", count[i]);
			}
			if(i == 2){
				printf(" %d TD,", count[i]);
			}
			if(i == 3){
				printf(" %d 3pt FG,", count[i]);
			}
			if(i == 4){
				printf(" %d Safety", count[i]);
			}

		}










		return;
	}


	for(int i = 0; i < 5; i++){
		if (i == 0){
			array[index] = 8;
			combinations(array, score - 8, index + 1);
		}
		if (i == 1){
					array[index] = 7;
					combinations(array, score - 7, index + 1);
				}
		if (i == 2){
					array[index] = 6;
					combinations(array, score - 6, index + 1);
				}
		if (i == 3){
					array[index] = 3;
					combinations(array, score - 3, index + 1);
				}
		if (i == 4){
					array[index] = 2;
					combinations(array, score - 2, index + 1);
				}
	}

}


int main(){

	int m  = 1;
	int combos[100];



	while (m != 0){
		printf("\n\nEnter 0 to STOP");
		printf("\n\nEnter the NFL score: ");
		scanf("%d", &m);
		combinations(combos, m, 0);


	}




	return 0;
}
