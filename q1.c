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

expNode *parse(char *equation);
void inOrder(expNode *nextNode);
void preOrder(expNode *nextNode);
void postOrder(expNode *nextNode);
float evaluate(expNode *rootNode);
void printTree();
void update(expNode *rootNode,char *variableName,char *newValue);

int main(int argc, char *argv[]){
  int userIn = 0;
  expNode *rootPtr = NULL;
  char equation[50];

  strcpy(equation, argv[1]);
  rootPtr = parse(equation);

  while(userIn != 7){
    printf("1. Display\n"); //sure
    printf("2. Preorder\n"); //done
    printf("3. Inorder\n"); //done
    printf("4. Postorder\n"); //done
    printf("5. Update\n");  //done
    printf("6. Calculate\n"); //done
    printf("7. Exit\n\n"); //done

    printf("Please choose an action: (Enter numbers 1 - 7): ");
    scanf("%d", &userIn);

    if(userIn == 1){
      printTree();
    }
    else if(userIn == 2){
      preOrder(rootPtr);
      printf("\n");
      printf("\n");
    }
    else if(userIn == 3){
      inOrder(rootPtr);
      printf("\n");
      printf("\n");
    }
    else if(userIn == 4){
      postOrder(rootPtr);
      printf("\n");
      printf("\n");
    }
    else if(userIn == 5){
      char variableName[10] = "";
      char newValue[10] = "";

      printf("Enter variable name: ");
      scanf("%s", variableName);
      printf("Enter new value: ");
      scanf("%s", newValue);

      printf("Updating value.\n");
      update(rootPtr,variableName,newValue);
      printf("\n");

    }
    else if(userIn == 6){
      float result = 0;

      result = evaluate(rootPtr);
      //check if result is inifite (divide by zero);
      if (result == -INFINITY || result == INFINITY){
        printf("You are dividing by zero.\n");
      } else {
        printf("The answer is: %f\n", result);
      }

      printf("\n");

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

expNode *parse(char *equation){
  int braCount = 0;
  int i = 0;
  expNode *newNode = malloc(sizeof(expNode));
  char *leftEqu = "";
  char *rightEqu = "";
  newNode->left = NULL;
  newNode->right = NULL;

  //if the first element in equation is a (
  if(equation[0] == '('){
    //count the number of brackets we pass by
    for(i = 0; i < strlen(equation) - 1; i++){
      if(equation[i] == '('){
        braCount += 1;
      }
      else if(equation[i] == ')'){
        braCount -= 1;
      }
      //if bracket == 1 and the next char in equation is an operator
      if(equation[i + 1] == '+' && braCount == 1){
        rightEqu = malloc(sizeof(i - 1));
        leftEqu = malloc(sizeof(strlen(equation) - i));

        strncpy(leftEqu, equation + 1, i);
        //create children for operator node
        //can add print statement here to check
        newNode->left = parse(leftEqu);

        strncpy(rightEqu, equation + i + 2, strlen(equation) - i - 3);
        newNode->right = parse(rightEqu);

        //create new node that holds operator (this occurs for all operators)
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
        newNode->left = parse(leftEqu);

        strncpy(rightEqu, equation + i + 2, strlen(equation) - i - 3);
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
        newNode->left = parse(leftEqu);

        strncpy(rightEqu, equation + i + 2, strlen(equation) - i - 3);
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
        newNode->left = parse(leftEqu);

        strncpy(rightEqu, equation + i + 2, strlen(equation) - i - 3);
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
  //check if element in equation is variable. Put it into new node.
  else if(equation[0] == 'x'){
    newNode->element = malloc(sizeof(strlen(equation)));
    strcpy(newNode->element, equation);

//this sets the values with x values to start with 0.0
/*
    for(k = 0; k < 4; k++){
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
    */
    return newNode;
  }
  //check if element in equation is digit. Put it into new node. (leaf nodes)
  else if(isdigit(equation[0]) != 0){
    newNode->element = malloc(sizeof(strlen(equation)));
    strcpy(newNode->element, equation);
    return newNode;
  }

  return newNode;

}

//online code https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
//function to print inorder
void inOrder(expNode *nextNode){
  if(nextNode){
    inOrder(nextNode->left);
    printf("%s ", nextNode->element);
    inOrder(nextNode->right);
  }
}

//online code https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
//function to print preorder
void preOrder(expNode *nextNode){
  if(nextNode){
    printf("%s ", nextNode->element);
    preOrder(nextNode->left);
    preOrder(nextNode->right);
  }
}

//online code https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
//function to print postorder
void postOrder(expNode *nextNode){
  if(nextNode){
    postOrder(nextNode->left);
    postOrder(nextNode->right);
    printf("%s ", nextNode->element);
  }
}

//help from https://www.youtube.com/watch?v=2tpcqDmvJBU
//function that calculates equation by reading binary tree
float evaluate(expNode *rootNode){
  float leftVal = 0;
  float rightVal = 0;
  float tempVal = 0;

  if(rootNode){
    //want to check if node is a leaf
    if(rootNode->left == NULL && rootNode->right == NULL){
      return atof(rootNode->element);
    }
    //if it isn't a leaf, then move on to the next left node
    leftVal = evaluate(rootNode->left);
    rightVal = evaluate(rootNode->right);

    //calculation of equation occurs here
    if(strcmp(rootNode->element, "+") == 0){
      tempVal = leftVal + rightVal;
      return tempVal;
    }
    else if(strcmp(rootNode->element, "-") == 0){
      tempVal = leftVal - rightVal;
      return tempVal;
    }
    else if(strcmp(rootNode->element, "*") == 0){
      tempVal = leftVal * rightVal;
      return tempVal;
    }
    else if(strcmp(rootNode->element, "/") == 0){
      tempVal = leftVal / rightVal;
      return tempVal;
    }
  }
  return 0.0;
}

void printTree(){
  printf("\t/\n______|______\n|\t|\n*\tx3\n______|______\n|\t\t|\n+\n____|____ ____|____\n|\t|\t|\t|\nx1\t5.12\tx2\t7.68\n");
}

//function to update variable value
void update(expNode *rootNode, char *variableName, char *newValue){
  if(rootNode){
    update(rootNode->left, variableName, newValue);
    //make sure the value you want to change exists in equation
    if(strcmp(rootNode->element, variableName) == 0){
      rootNode->element = malloc(sizeof(newValue));
      strcpy(rootNode->element, newValue);
    }
    update(rootNode->right, variableName, newValue);
  }

}
