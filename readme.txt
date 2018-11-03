Name: Jason Chow
ID: 1003377
Assignment 2

Run the makefile first.

Description:
q1.c

To run the program, enter a valid infix expression in the command line in double quotations(eg. ./q1 "(((1+x1)+(4+8))/(1+x2))").
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

IMPORTANT: Make sure you update any variables before you try to calculate the equation
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

Please choose an action: (Enter numbers 1 - 7): 7
Exiting program.


Description:
q2.c

Use ./q2 in the command line to run.
This program sorts the keys of each object and stores it into a heap.
The objects are sorted from least to greatest (smallest key at the top to the largest key at the bottom).

Important: MAKE SURE THE TEXTFILE YOU ARE ENTERING IS NAMED "f.dat", CONTAINS 20 ROWS,
10 COLUMNS AND EXISTS IN THE SAME FOLDER AS THE PROGRAM FILE.

Sample input/output:
INPUT FILE (not shown in program):
25 12 17 82 52 53 05 03 68 64
43 27 20 59 04 84 10 42 43 02
81 14 42 21 09 69 05 30 20 91
96 89 75 00 63 24 54 20 20 24
41 62 82 46 69 42 74 68 79 28
50 09 06 44 59 87 32 36 36 46
83 82 43 11 21 04 08 97 93 14
03 60 76 23 14 81 82 00 38 04
09 83 22 90 74 56 64 75 67 55
41 82 53 40 29 84 24 61 87 20
99 37 50 93 57 06 29 91 92 39
25 41 11 88 15 39 88 69 31 49
03 37 97 53 36 54 69 68 38 43
44 27 68 96 70 98 85 13 25 47
51 90 37 86 42 44 48 64 41 01
16 14 27 99 29 99 79 45 59 19
88 56 59 88 39 30 44 59 49 72
49 17 44 32 33 54 60 33 51 87
12 00 68 68 49 68 74 32 09 30
81 30 16 65 40 39 44 49 32 60

OUTPUT:
25 12 17 82 52 53 5 3 68 64       --> object with smallest key
16 14 27 99 29 99 79 45 59 19
50 9 6 44 59 87 32 36 36 46
25 41 11 88 15 39 88 69 31 49
12 0 68 68 49 68 74 32 9 30
43 27 20 59 4 84 10 42 43 2
49 17 44 32 33 54 60 33 51 87
9 83 22 90 74 56 64 75 67 55
81 30 16 65 40 39 44 49 32 60
81 14 42 21 9 69 5 30 20 91
3 37 97 53 36 54 69 68 38 43
44 27 68 96 70 98 85 13 25 47
3 60 76 23 14 81 82 0 38 4
41 82 53 40 29 84 24 61 87 20
51 90 37 86 42 44 48 64 41 1
41 62 82 46 69 42 74 68 79 28
99 37 50 93 57 6 29 91 92 39
88 56 59 88 39 30 44 59 49 72
83 82 43 11 21 4 8 97 93 14
96 89 75 0 63 24 54 20 20 24      --> object with largest key
