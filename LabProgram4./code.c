//   Circular Queue implementation
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define s 3
int Queue[s],front=-1,rear=-1;

void insert(){
    if(front==(rear+1)%s){
        printf("Overflow\n");
        return;
    }
    int data;
    printf("Enter element:");
    scanf("%d",&data);
    if(front==-1) front=rear=0;
    else rear=(rear+1)%s;
    Queue[rear]=data;
    printf("Done\n");
    return;
}

int delete(){
    if(front==-1){
        printf("Underflow\n");
        return -1;
    }
    int item=Queue[front];
    if(front==rear) front=rear=-1;
    else front=(front+1)%s;
    return item;
}

void display(){
    if(front==-1){
        printf("Queue empty\n");
        return;
    }
    int i;
    for(i=front;i!=rear;i=(i+1)%s){
        printf("%d\t",Queue[i]);
    }
    printf("%d\n",Queue[i]);
    return;
}


void main(){
    printf("1-insert,2-delete,3-display,4-exit\n");
    int ch;
    while(1){
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insert();
            break;

            case 2:
            printf("%d\n",delete());
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);
        }
    }
    return;
}




// Output:

// 1-insert,2-delete,3-display,4-exit
// Enter choice:1
// Enter element:10
// Done
// Enter choice:1
// Enter element:20
// Done
// Enter choice:1
// Enter element:30
// Done
// Enter choice:1
// Overflow
// Enter choice:2
// 10
// Enter choice:2
// 20
// Enter choice:1
// Enter element:40
// Done
// Enter choice:3
// 30      40
// Enter choice:2
// 30
// Enter choice:2
// 40
// Enter choice:2
// Underflow
// -1
// Enter choice:4
//Program ended with exit code: 0
