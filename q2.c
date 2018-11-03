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
  int arr[10];
} objNode;

typedef struct heapNode{
  objNode *obj;
  int length;
} heapNode;

void addToHeap(objNode objArr[], int i, int arrSize);

int main(){
  FILE *fp;

  char element[3];
  int fileArr[ROW][COLUMN];
  int i = 0;
  int k = 0;
  objNode objArr[21];
  int arrSize = 0;

  fp = fopen("f.dat", "r");

  if(fp == NULL){
    printf("File could not be opened.\n");
    exit(1);
  }
  //store file info into 2D array
  else if(fp != NULL){
    for(i = 0; i < ROW; i++){
      for(k = 0; k < COLUMN; k++){
        if(fscanf(fp, "%s ", element) == 1);
        fileArr[i][k] = atoi(element);
      }
    }
  }

  fclose(fp);

  //store elements into object nodes
  for(i = 0; i < ROW; i++){
    int temp = 0;
    temp = fileArr[i][0] + fileArr[i][1] + fileArr[i][2];
    objArr[i].key = temp;

    for(k = 0; k < COLUMN; k++){
        objArr[i].arr[k] = fileArr[i][k];
    }
  }

  arrSize = sizeof(objArr)/sizeof(objArr[0]);

  for(i = (arrSize / 2) - 1 ; i >= 0; i--){
    addToHeap(objArr, i, arrSize);
  }

  for(i = arrSize - 1; i >= 0; i--){
    objNode tempObj;

    tempObj.key = objArr[0].key;
    for(k = 0; k < 10; k++){
      tempObj.arr[k] = objArr[0].arr[k];
    }
    objArr[0].key = objArr[i].key;
    for(k = 0; k < 10; k++){
      objArr[0].arr[k] = objArr[i].arr[k];
    }
    objArr[i].key = tempObj.key;
    for(k = 0; k < 10; k++){
      objArr[i].arr[k] = tempObj.arr[k];
    }

    addToHeap(objArr, i, 0);
  }


  for(i = 0; i < ROW; i++){
    for(k = 0; k < COLUMN; k++){
      printf("%d ", fileArr[i][k]);
    }
    printf("\n");
  }

/*
  printf("$%d$\n", objArr[0].key);
  for(i = 0; i< COLUMN; i++){
    printf("#%d#\n", objArr[0].arr[i]);
  }
  */




  return 0;

}

//https://www.geeksforgeeks.org/heap-sort/ MY CODE IS MODIFIED FROM THIS NO MOSS PLEASE
void addToHeap(objNode objArr[], int i, int arrSize){
  int smallest = 0;
  int leftChild = 0;
  int rightChild = 0;
  int k = 0;
  objNode tempObj;
  smallest = i;
  //https://www.geeksforgeeks.org/array-representation-of-binary-heap/ Location of child nodes.
  leftChild = (2 * i) + 1;
  rightChild = (2 * i) + 2;

  if(leftChild < arrSize && objArr[leftChild].key < objArr[smallest].key){
    smallest = leftChild;
  }

  if(rightChild < arrSize && objArr[rightChild].key < objArr[smallest].key){
    smallest = rightChild;
  }

  if(smallest != i){
    tempObj.key = objArr[i].key;
    for(k = 0; k < 10; k++){
      tempObj.arr[k] = objArr[i].arr[k];
    }
    objArr[i].key = objArr[smallest].key;
    for(k = 0; k < 10; k++){
      objArr[i].arr[k] = objArr[smallest].arr[k];
    }
    objArr[smallest].key = tempObj.key;
    for(k = 0; k < 10; k++){
      objArr[smallest].arr[k] = tempObj.arr[k];
    }
    printf("--%d\n", objArr[smallest].key);
    addToHeap(objArr, smallest, arrSize);

  }

}
