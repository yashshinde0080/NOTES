#include<stdio.h>
#include<math.h>
void tower(int n, int source, int dest,int temp);
void tower(int n, int source, int dest,int temp){
    if(n==0)
        return;
    tower(n-1, source, dest,temp);
    printf("Move disc %d from %c to %c \n", n, source, dest);
    tower(n-1, temp, source, dest);
}
void main(){
    int n;
    printf("enter the no of dfiscs:\n");
    scanf("%d\n", &n);
    printf("the sequence involved is :\n");
    tower(n,'A','B','C');
    printf("totoal number of moves involove is : %d\n", (int) pow(2,n)-1);
}
