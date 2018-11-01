/*
Name: Jason Chow
ID: 1003377
Date: 29/10/2018
Assignment 3 - q1.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct node{
  char *element;
  struct node *left;
  struct node *right;
} expNode;

//void insert(expNode *rootPtr);
expNode *parse(char *equation);
void inOrder(expNode *nextNode);
void preOrder(expNode *nextNode);
void postOrder(expNode *nextNode);

int main(int argc, char *argv[]){
  int userIn = 0;
  expNode *rootPtr = NULL;
  char equation[50];

  strcpy(equation, argv[1]);

  rootPtr = parse(equation);

  while(userIn != 7){
    printf("1. Display\n");
    printf("2. Preorder\n");
    printf("3. Inorder\n");
    printf("4. Postorder\n");
    printf("5. Update\n");
    printf("6. Calculate\n");
    printf("7. Exit\n\n");

    printf("Please choose an action: (Enter numbers 1 - 7): ");
    scanf("%d", &userIn);

    if(userIn == 1){

    }
    else if(userIn == 2){
      preOrder(rootPtr);
      printf("\n");
    }
    else if(userIn == 3){
      inOrder(rootPtr);
      printf("\n");
    }
    else if(userIn == 4){
      postOrder(rootPtr);
      printf("\n");
    }
    else if(userIn == 5){
      char variableName[10] = "";
      float newValue = 0;

    }
    else if(userIn == 6){

    }
    else if(userIn == 7){
      printf("Exiting program.\n");
    }
    else{
      printf("Invalid input. Please enter a number between 1 and 7.\n\n");
    }
  }

  return 0;

}

/*
void insert(char ){

}
*/

expNode *parse(char *equation){
  int braCount = 0;
  int i = 0;
  int k = 0;
  expNode *newNode = malloc(sizeof(expNode));
  char *leftEqu = "";
  char *rightEqu = "";

  if(equation[0] == '('){

    for(i = 0; i < strlen(equation) - 1; i++){
      if(equation[i] == '('){
        braCount += 1;
      }
      else if(equation[i] == ')'){
        braCount -= 1;
      }
      if(equation[i + 1] == '+' && braCount == 1){
        rightEqu = malloc(sizeof(i - 1));
        leftEqu = malloc(sizeof(strlen(equation) - i));

        strncpy(leftEqu, equation + 1, i);
        printf("<%s>\n", leftEqu);
        newNode->left = parse(leftEqu);

        strncpy(rightEqu, equation + i + 2, strlen(equation) - i - 3);
        printf("@%s@\n", rightEqu);
        newNode->right = parse(rightEqu);

        if(equation[1 + i] == '+'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "+");
        }
        else if(equation[1 + i] == '-'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "-");
        }
        else if(equation[1 + i] == '*'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "*");
        }
        else if(equation[1 + i] == '/'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "/");
        }

        return newNode;

      }
      else if(equation[i + 1] == '-' && braCount == 1){
        rightEqu = malloc(sizeof(i - 1));
        leftEqu = malloc(sizeof(strlen(equation) - i));

        strncpy(leftEqu, equation + 1, i);
        printf("<%s>\n", leftEqu);
        newNode->left = parse(leftEqu);

        strncpy(rightEqu, equation + i + 2, strlen(equation) - i - 3);
        printf("@%s@\n", rightEqu);
        newNode->right = parse(rightEqu);

        if(equation[1 + i] == '+'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "+");
        }
        else if(equation[1 + i] == '-'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "-");
        }
        else if(equation[1 + i] == '*'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "*");
        }
        else if(equation[1 + i] == '/'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "/");
        }

        return newNode;

      }
      else if(equation[i + 1] == '*' && braCount == 1){
        rightEqu = malloc(sizeof(i - 1));
        leftEqu = malloc(sizeof(strlen(equation) - i));

        strncpy(leftEqu, equation + 1, i);
        printf("<%s>\n", leftEqu);
        newNode->left = parse(leftEqu);

        strncpy(rightEqu, equation + i + 2, strlen(equation) - i - 3);
        printf("@%s@\n", rightEqu);
        newNode->right = parse(rightEqu);

        if(equation[1 + i] == '+'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "+");
        }
        else if(equation[1 + i] == '-'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "-");
        }
        else if(equation[1 + i] == '*'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "*");
        }
        else if(equation[1 + i] == '/'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "/");
        }

        return newNode;

      }
      else if(equation[i + 1] == '/' && braCount == 1){
        rightEqu = malloc(sizeof(i - 1));
        leftEqu = malloc(sizeof(strlen(equation) - i));

        strncpy(leftEqu, equation + 1, i);
        printf("<%s>\n", leftEqu);
        newNode->left = parse(leftEqu);

        strncpy(rightEqu, equation + i + 2, strlen(equation) - i - 3);
        printf("@%s@\n", rightEqu);
        newNode->right = parse(rightEqu);

        if(equation[1 + i] == '+'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "+");
        }
        else if(equation[1 + i] == '-'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "-");
        }
        else if(equation[1 + i] == '*'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "*");
        }
        else if(equation[1 + i] == '/'){
          newNode->element = malloc(sizeof(equation[1 + i]));
          strcpy(newNode->element, "/");
        }

        return newNode;

      }
    }
  }
  else if(equation[0] == 'x'){
    newNode->element = malloc(sizeof(strlen(equation) + 4));

    strcpy(newNode->element, equation);

    for(k = 0; k < 4; i++){
      if(k == 0){
        newNode->element[strlen(equation) + k] = ':';
      }
      else if(k == 1 || k == 3){
        newNode->element[strlen(equation) + k] = '0';
      }
      else if(k == 2){
        newNode->element[strlen(equation) + k] = '.';
      }
    }
    return newNode;
  }
  else if(isdigit(equation[0]) != 0){
    newNode->element = malloc(sizeof(strlen(equation)));
    strcpy(newNode->element, equation);
    return newNode;
  }

  return newNode;

}

//online code https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
void inOrder(expNode *nextNode){
  if(nextNode){
    inOrder(nextNode->left);
    printf("%s ", nextNode->element);
    inOrder(nextNode->right);
  }

//online code https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
void preOrder(expNode *nextNode){
  if(nextNode){
    printf("%s ", nextNode->element);
    preOrder(nextNode->left);
    preOrder(nextNode->right);
  }
}

//online code https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
void postOrder(expNode *nextNode){
  if(nextNode){
    postOrder(nextNode->left);
    postOrder(nextNode->right);
    printf("%s ", nextNode->element);
  }
}

}
