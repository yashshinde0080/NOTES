#include<stdio.h>
#include<string.h>

// Function ISP to define precedence for symbols in the stack
int ISP(char symbol) {
    switch (symbol) {
        case '+':  // Addition
        case '-':  // Subtraction
            return 2; // Precedence for + and - in the stack
        case '*':  // Multiplication
        case '/':  // Division
        case '%':  // Modulus
            return 4; // Precedence for *, /, and % in the stack
        case '^':  // Exponentiation
        case '$':  // (Alternate for exponentiation)
            return 5; // Precedence for ^ and $ in the stack
        case '(':  // Left Parenthesis
            return 0; // Lowest precedence for left parenthesis
        case '#':  // Stack base marker
            return -1; // Used to mark the bottom of the stack
        default:   // Operand or any other symbol
            return 8;  // Highest precedence for operands
    }
}

// Function ICP to define precedence for symbols in the input expression
int ICP(char symbol) {
    switch (symbol) {
        case '+':  // Addition
        case '-':  // Subtraction
            return 1;  // Precedence for + and - in the input
        case '*':  // Multiplication
        case '/':  // Division
        case '%':  // Modulus
            return 3;  // Precedence for *, /, and % in the input
        case '^':  // Exponentiation
        case '$':  // (Alternate for exponentiation)
            return 6;  // Highest precedence for ^ and $ in the input
        case '(':  // Left Parenthesis
            return 9;  // Highest precedence for ( to push into the stack
        case ')':  // Right Parenthesis
            return 0;  // Used to pop elements until '(' is found
        default:   // Operand or any other symbol
            return 8;  // Precedence for operands
    }
}

// Function to convert infix expression to postfix expression
void infix_postfix(char infix[], char postfix[]) {
    int top = -1, j = 0, i;
    char s[30], symbol;

    /* Initialize stack with base marker '#'
       The stack base marker # acts as a safeguard to manage the stack during the conversion process,
	   ensuring the algorithm functions correctly, avoids underflow, and simplifies stack operations. */
    s[++top] = '#';

    // Loop through each symbol in the infix expression
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        //If it is operand then directly insert in postfix expression
        if (ISP(s[top]) == ICP(symbol))
        	postfix[j++] = symbol;
        else
        {
        	// Pop from stack and append to postfix as long as the stack precedence (ISP) is higher
	        while (ISP(s[top]) > ICP(symbol)) {
	            postfix[j++] = s[top--];
	        }

	        // Push symbol to stack if precedence doesn't match
	        if (ISP(s[top]) != ICP(symbol)) {
	            s[++top] = symbol;
	        } else {
	            top--;  // If match, pop the '('
	        }
		}
    }

    // Pop remaining symbols from stack to postfix expression
    while (s[top] != '#') {
        postfix[j++] = s[top--];
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';
}

// Main function to get user input and display the infix and postfix expressions
void main() {
    char infix[20], postfix[20];

    // Ask the user to enter a valid infix expression
    printf("\nEnter a valid infix expression:\n");
    scanf("%s", infix);

    // Call the conversion function
    infix_postfix(infix, postfix);

    // Display the infix and postfix expressions
    printf("\nThe infix expression is:\n");
    printf("%s", infix);

    printf("\nThe postfix expression is:\n");
    printf("%s", postfix);
}
