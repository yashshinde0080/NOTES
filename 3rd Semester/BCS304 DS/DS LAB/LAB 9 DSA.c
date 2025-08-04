#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct Node {
    int coeff;        // Coefficient of the term
    int powX, powY, powZ;  // Powers of x, y, and z
    struct Node *next; // Pointer to the next node
} Node;

// Function to create a new node
Node* createNode(int coeff, int powX, int powY, int powZ) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->powX = powX;
    newNode->powY = powY;
    newNode->powZ = powZ;
    newNode->next = newNode; // Circular property
    return newNode;
}

// Function to insert a node at the end of the SCLL
void insertNode(Node **head, int coeff, int powX, int powY, int powZ) {
    Node *newNode = createNode(coeff, powX, powY, powZ);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = newNode;
    }
    newNode->next = *head;
}

// Function to display a polynomial
void displayPolynomial(Node *head) {
    if (!head) {
        printf("0\n");
        return;
    }
    Node *temp = head;
    do {
        printf("%d*x^%d*y^%d*z^%d", temp->coeff, temp->powX, temp->powY, temp->powZ);
        temp = temp->next;
        if (temp != head) printf(" + ");
    } while (temp != head);
    printf("\n");
}

// Function to evaluate a polynomial for given x, y, z
int evaluatePolynomial(Node *head, int x, int y, int z) {
    int result = 0;
    Node *temp = head;
    do {
        result += temp->coeff * pow(x, temp->powX) * pow(y, temp->powY) * pow(z, temp->powZ);
        temp = temp->next;
    } while (temp != head);
    return result;
}

// Function to add two polynomials and store the result in POLYSUM
void addPolynomials(Node *poly1, Node *poly2, Node **polySum) {
    Node *temp1 = poly1;
    int found;
    do {
        insertNode(polySum, temp1->coeff, temp1->powX, temp1->powY, temp1->powZ);
        temp1 = temp1->next;
    } while (temp1 != poly1);

    Node *temp2 = poly2;
    do {
        Node *temp = *polySum;
        found = 0;
        do {
            if (temp->powX == temp2->powX && temp->powY == temp2->powY && temp->powZ == temp2->powZ) {
                temp->coeff += temp2->coeff;
                found = 1;
                break;
            }
            temp = temp->next;
        } while (temp != *polySum);

        if (!found) insertNode(polySum, temp2->coeff, temp2->powX, temp2->powY, temp2->powZ);
        temp2 = temp2->next;
    } while (temp2 != poly2);
}

// Main function to demonstrate the program
int main() {
    Node *P = NULL, *POLY1 = NULL, *POLY2 = NULL, *POLYSUM = NULL;

    // Creating polynomial P(x,y,z) = 6x^2y^2z - 4yz^5 + 3x^3yz + 2xy^5z - 2xyz^3
    insertNode(&P, 6, 2, 2, 1);   // 6x^2y^2z
    insertNode(&P, -4, 0, 1, 5);  // -4yz^5
    insertNode(&P, 3, 3, 1, 1);   // 3x^3yz
    insertNode(&P, 2, 1, 5, 1);   // 2xy^5z
    insertNode(&P, -2, 1, 1, 3);  // -2xyz^3

    printf("Polynomial P(x,y,z): ");
    displayPolynomial(P);

    printf("Evaluation of P(x=2, y=1, z=3): %d\n", evaluatePolynomial(P, 2, 1, 3));

    // Creating two polynomials POLY1 and POLY2
    insertNode(&POLY1, 3, 2, 1, 0);  // 3x^2y
    insertNode(&POLY1, 4, 0, 0, 5);  // 4z^5
    insertNode(&POLY2, 5, 1, 1, 1);  // 5xyz
    insertNode(&POLY2, -2, 0, 0, 5); // -2z^5

    printf("\nPolynomial POLY1(x,y,z): ");
    displayPolynomial(POLY1);
    printf("Polynomial POLY2(x,y,z): ");
    displayPolynomial(POLY2);

    // Adding POLY1 and POLY2
    addPolynomials(POLY1, POLY2, &POLYSUM);
    printf("Sum of POLY1 and POLY2 (POLYSUM): ");
    displayPolynomial(POLYSUM);

    return 0;
}
