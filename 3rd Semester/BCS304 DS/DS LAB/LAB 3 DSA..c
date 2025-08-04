#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
int s[10], top = -1;
void push() {
 if (top == MAXSIZE - 1)
 printf("\nStack overflow!!!!");
 else {
 printf("\nEnter element to insert:");
 scanf("%d", &s[++top]);
 }
}
void pop() {
 if (top == -1)
 printf("\nStack underflow!!!");
 else
 printf("\nElement popped is: %d", s[top--]);
}
void disp() {
 int t = top;
 if (t == -1)
 printf("\nStack empty!!");
 else
 printf("\nStack elements are:\n");
 while (t >= 0)
 printf("%d ", s[t--]);
}
void pali() {
 int num[5], rev[5], i, t;
 for (i = 0, t = top; t >= 0; i++, t--)
 num[i] = rev[t] = s[t];
 for (i = 0; i < top/2; i++)
 if (num[i] != rev[i])
 break;
 if (i == top/2)
 printf("\nIt is a palindrome");
 else
 printf("\nIt is not a palindrome");
}
int main() {
 int ch;
 do {
 printf("\n...Stack operations.....\n");
 printf("1.PUSH\n");
 printf("2.POP\n");
 printf("3.Palindrome\n");
 printf("4.Display\n");
 printf("5.Exit\n_______________\n");
 printf("Enter choice:");
 scanf("%d", &ch);
 switch (ch) {
 case 1:
 push();
 break;
 case 2:
 pop();
 break;
 case 3:
 pali();
 break;
 case 4:
 disp();
 break;
 case 5:
 exit(0);
 default:
 printf("\nInvalid choice");
 }
 } while (1);
 return 0;
}
