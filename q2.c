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

typedef struct node{
  int key;
  int arr[15];
} heapNode;

int main(){
  FILE *fp;

  char element[3];
  int fileArr[ROW][COLUMN];
  int i = 0;
  int k = 0;

  fp = fopen("f.dat", "r");

  if(fp == NULL){
    printf("File could not be opened.\n");
    exit(1);
  }
  //store file info into 2D array
  else if(fp != NULL){
    for (i = 0; i < ROW; i++){
      for(k = 0; k < COLUMN; k++){
        if(fscanf(fp, "%s ", element) == 1);
        fileArr[i][k] = atoi(element);
      }
    }
  }

  fclose(fp);



  return 0;

}
