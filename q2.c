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

int main(){
  FILE *fp;

  fp = fopen("f.dat", "r");
  char line[30];

  if(fp != NULL){
    while(fgets(line, sizeof(line), fp) != NULL){

    }
  }


}
