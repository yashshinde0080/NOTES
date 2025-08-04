#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

float compute(char symbol, float op1, float op2){
    switch(symbol){
        case'+' : return op1+op2;
        case '-': return op1-op2;
        case'*': return op1*op2;
        case '/' : return op1/op2;
        case '&' :
            case '^' : return pow(op1,op2);
            return 0;
    }
}

void main(){
float s[20],res, op1,op2;
int top, i;
char postfix[20], symbol;
printf("Enter the psodtfix expresion: \n");
scanf("%s",postfix);
top=-1;
for(i=0; i<strlen(postfix); i++){
    symbol=postfix[i];
    if(isdigit(symbol))
    s[++top]=symbol -'0';
    else{
        op2=s[top--];
        op1=s[top--];
        res=compute(symbol, op1, op2);
        s[++top]=res;
    }

}
res=s[top--];
printf("result : %f",res);
}
