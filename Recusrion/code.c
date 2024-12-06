#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int fac(int n){
    if(n==0 || n==1){
        return 1;
    }
    else return n*fac(n-1);
}

int fib(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    else return (fib(n-1)+fib(n-2));
}

void toh(int n,char* s,char* t,char* d){
    if(n==1) {
        printf("Move rod %d from %s to %s\n",n,s,t);
        return;
    }
    toh(n-1,s,d,t);
    printf("Move rod %d from %s to %s\n",n,s,t);
    toh(n-1,d,t,s);
}

void main(){
    printf("%d\n",fac(5));
    printf("%d\n",fib(7));
    printf("\n");
    toh(3,"start","end","temp");
}


// o/p

// 120
// 8

// Move rod 1 from start to end
// Move rod 2 from start to temp
// Move rod 1 from end to temp
// Move rod 3 from start to end
// Move rod 1 from temp to start
// Move rod 2 from temp to end
// Move rod 1 from start to end
