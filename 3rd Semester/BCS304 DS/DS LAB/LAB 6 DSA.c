#include <stdio.h>
#include <stdlib.h>
#define max 5
int q[max], f=-1, r=-1;
void ins(){
    if(f==(r+1)%max)
        printf("q overlfoefop\n");
    else{
        if (f==-1)
            f++;
        r=(r+1)%max;
        printf("element to inseet:");
        scanf("%d", &q[r]);
    }
}

void del(){
    if(r==-1)
        printf("q underflow\n");
    else{
        printf("element deleted is %d", q[f]);
        if(f==r)
            f=r=-1;
        else
            f=(f+1)%max;
    }
}

void disp(){
    if(f==-1)
        printf("emptu!!");
    else{
        int i;
        printf("elements are:");
        for(i=f; i!=r; i=(i+1)%max)
            printf("%d\t", q[i]);
            printf("%d", q[i]);
            printf("Front is at : %d\n Rear is at : %d\n", q[f],q[r]);
    }
}

int main() {
    printf("\n1.Insert");
    printf("\n2.Del");
    printf("\n3.Display");
    printf("\n4.exit");
    printf("enter your choice :");
    int ch;
    do{
        printf("enter choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1: ins(); break;
            case 2: del(); break;
            case 3: disp(); break;
            case 4: exit(0);
            default: printf("\nwrong choice!!!!");
        }
    }while(1);
    return 0;

}
