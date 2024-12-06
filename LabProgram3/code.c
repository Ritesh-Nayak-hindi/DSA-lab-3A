//     Queue Implementation

#include<stdio.h>
#include<conio.h>
#define max 3
int Queue[max],front=-1,rear=-1;

void insert(){
if (rear==max-1){
    printf("overflow\n");
    return;
}
int data;
printf("Element to insert:");
scanf("%d",&data);
Queue[++rear]=data;
if(front==-1) front=0;
printf("Done\n");
return;
}

int delete(){
if(rear==-1){
    printf("Underflow\n");
    return -1;
}
int data=Queue[front];
if(front==rear){
    front=-1;
    rear=-1;
}
else{
    front++;
}
return data;
}

void display(){
    if(rear==-1){
    printf("Queue empty\n");
    return;
}
for(int i=front;i<=rear;i++){
    printf("%d\t",Queue[i]);
}
printf("\n");
return;
}

void main(){
printf("1-insert,2-delete,3-display,4-exit\n");
int ch;
while(1){
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch){
    case 1:
        insert();
        break;

    case 2:
        printf("deleted element:%d\n",delete());
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
// Enter your choice:1
// Element to insert:10
// Done
// Enter your choice:1
// Element to insert:20
// Done
// Enter your choice:1
// Element to insert:30
// Done
// Enter your choice:1
// overflow
// Enter your choice:3
// 10      20      30
// Enter your choice:2
// deleted element:10
// Enter your choice:2
// deleted element:20
// Enter your choice:2
// deleted element:30
// Enter your choice:2
// Underflow
// deleted element:-1
// Enter your choice:4
