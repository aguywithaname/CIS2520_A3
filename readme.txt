Name: Jason Chow
ID: 1003377
Assignment 2

Run the makefile first.

Description:
q1.c

To run the program, enter a valid infix expression in the command line (eg. ./q1 "(((1+x1)+(4+8))/(1+x2))").
As directed the assignment instructions, you will enter a number between 1 - 7
in order to run the functionality of the program. Here is a quick rundown:

1. Display - Displays a visual representation of the binary tree created
2. Preorder - Displays the entered equation in prefix form.
3. Inorder - Displays the entered equation in inorder form.
4. Postorder - Displays the entered equation in postfix form.
5. Update - Allows the user to change the value of a variable that exists in the equation (eg. x1).
            Replaces the variable with the new value.
6. Calculate - Calculates the equation entered. Accurate to 6 decimal places.
7. Exit - End program.

Important: Make sure you update any variables before you try to calculate the equation
(eg. no remaining x1 or x2 in equation please). PLEASE ALSO TAKE NOTE THAT WHEN YOU UPDATE
A VARIABLE, YOU CANNOT CHANGE IT AGAIN, THE VARIABLE WILL BE SET TO THAT UPDATED VALUE AS LONG AS THE
PROGRAM RUNS. YOU WILL NEED TO RESTART THE PROGRAM IF YOU WANT TO CHANGE THE VARIABLE VALUE TO ANOTHER VALUE.
When you update a value, you can use inorder print to show whether or not the variable has been updated.
Also, display doesn't really work the way I want it to. Please go easy on marking.

Sample input/output:
./q1 "(((1+x1)+(4+8))/(1+x2))"

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit

Please choose an action: (Enter numbers 1 - 7): 1
      /
______|______
|	          |
*	          x3
______|______
|		         |
+
____|____ ____|____
|	    |   |       |
x1	5.12	x2	   7.68

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit

Please choose an action: (Enter numbers 1 - 7): 2
/ + + 1 x1 + 4 8 + 1 x2

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit

Please choose an action: (Enter numbers 1 - 7): 3
1 + x1 + 4 + 8 / 1 + x2

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit

Please choose an action: (Enter numbers 1 - 7): 4
1 x1 + 4 8 + + 1 x2 + /

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit

Please choose an action: (Enter numbers 1 - 7): 5
Enter variable name: x1
Enter new value: 3
Updating value.

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit

Please choose an action: (Enter numbers 1 - 7): 3
1 + 3 + 4 + 8 / 1 + x2

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit


Please choose an action: (Enter numbers 1 - 7): 5
Enter variable name: x2
Enter new value: 7
Updating value.

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit

Please choose an action: (Enter numbers 1 - 7): 3
1 + 3 + 4 + 8 / 1 + 7

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit

Please choose an action: (Enter numbers 1 - 7): 6
The answer is: 2.000000

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit

Please choose an action: (Enter numbers 1 - 7): 7
Exiting program.
