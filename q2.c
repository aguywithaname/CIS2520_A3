/*
Name: Jason Chow
ID: 1003377
Date: 29/10/2018
Assignment 3 - q2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ROW 20
#define COLUMN 10

int main(){
  FILE *fp;

  fp = fopen("f.dat", "r");
  char element[2];
  int fileArr[20][10];
  int i = 0;
  int k = 0;

  if(fp != NULL){
    for (i = 0; i < ROW; i++){
      for(k = 0; k < COLUMN; k++){
        if(fscanf(fp, "%s", element) == 1){
          fileArr[i][k] = atoi(element);
        }
      }
    }

  }


}
