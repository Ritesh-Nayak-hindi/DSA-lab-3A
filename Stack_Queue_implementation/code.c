// stack and Queue implementation
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head1=NULL;
struct Node *head2=NULL;
int Max_size_stack;
int count =1;
int Max_size_queue;
int c=1;

struct Node *create(){
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    if(!temp){
        printf("THE CREATION OF THE NODE FAILED");
        return NULL;
    }
    printf("ENTER THE DATA THAT NEEDS TO BE PUSHED");
    scanf("%d",&temp->data);
    temp->next=NULL;
    return temp;
}

void push(struct Node **L1){
    struct Node *temp=create();
    if(*L1==NULL){
        *L1=temp;
        return;
    }
    if(count==Max_size_stack){
        printf("THE STACK IS FULL");
        return;
    }
    temp->next=*L1;
    *L1=temp;
    count++;
}

void pop(){
    if(head1==NULL){
        printf("THE STACK IS EMPTY\n");
        return;
    }
    struct Node *curr=head1;
    head1=head1->next;
    printf("THE POPED ELLEMENT IS %d: ",curr->data);
    free(curr);
}

void display_stack(){
    if(head1==NULL){
        printf("THE STACK IS EMPTY\n");
        return;
    }
    struct Node *curr=head1;
    while(curr!=NULL){
        printf("\n%d\n",curr->data);
        curr=curr->next;
    }
}

void enqueue(struct Node **L1){
    struct Node *temp=create();
    if(*L1==NULL){
        *L1=temp;
        return;
    }
    if(c==Max_size_queue){
        printf("THE QUEUE IS COMPLETLEY FULL");
        return;
    }
    struct Node *curr=*L1;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    c++;
    
    
}

void dequeue(){
    if(head2==NULL){
        printf("THE QUEUE IS EMPTY");
        return;
    }
    struct Node *curr=head2;
    head2=head2->next;
    printf("DEQUEUED ELEMENT IS:%d",curr->data);
    free(curr);
}

void display_queue(){
    if(head2==NULL){
        printf("THE GIVEN QUEUE IS ALREADY EMPTY");
        return;
    }
    struct Node *curr=head2;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
}
int main(){
    printf("WHAT SIZE OF STACK DO YOU WNAT");
    scanf("%d",&Max_size_stack);
    printf("WHAT SIZE OF QUEUE DO YOU WNAT");
    scanf("%d",&Max_size_queue);
    while(1){
        printf("ENTER YOUR CHOICE\n1.push into stack\n2.pop out of stack\n3.display the stack\n4.enqueue the queue\n5.dequeue the queue\n6.display the queue\n-1 exit the program\n");
        int i;
        scanf("%d",&i);
        if(i==-1){
            exit(0);
        }
        switch (i) {
            case 1:
                push(&head1);
                break;
            case 2:
                pop();
                break;
            case 3:
                display_stack();
                break;
            case 4:
                enqueue(&head2);
                break;
            case 5:
                dequeue();
                break;
            case 6:
                display_queue();
                break;
            default:
                printf("THE ENTERED CHOICE IS INVALID\n");
                break;
        }
    }
}

//output:

WHAT SIZE OF STACK DO YOU WNAT1
WHAT SIZE OF QUEUE DO YOU WNAT3
ENTER YOUR CHOICE
1.push into stack
2.pop out of stack
3.display the stack
4.enqueue the queue
5.dequeue the queue
6.display the queue
-1 exit the program
4
ENTER THE DATA THAT NEEDS TO BE PUSHED10
ENTER YOUR CHOICE
1.push into stack
2.pop out of stack
3.display the stack
4.enqueue the queue
5.dequeue the queue
6.display the queue
-1 exit the program
4
ENTER THE DATA THAT NEEDS TO BE PUSHED20
ENTER YOUR CHOICE
1.push into stack
2.pop out of stack
3.display the stack
4.enqueue the queue
5.dequeue the queue
6.display the queue
-1 exit the program4

ENTER THE DATA THAT NEEDS TO BE PUSHED30
ENTER YOUR CHOICE
1.push into stack
2.pop out of stack
3.display the stack
4.enqueue the queue
5.dequeue the queue
6.display the queue
-1 exit the program
4
ENTER THE DATA THAT NEEDS TO BE PUSHED50
THE QUEUE IS COMPLETLEY FULLENTER YOUR CHOICE
1.push into stack
2.pop out of stack
3.display the stack
4.enqueue the queue
5.dequeue the queue
6.display the queue
-1 exit the program
6
10 20 30 ENTER YOUR CHOICE
1.push into stack
2.pop out of stack
3.display the stack
4.enqueue the queue
5.dequeue the queue
6.display the queue
-1 exit the program
5
DEQUEUED ELEMENT IS:10ENTER YOUR CHOICE
1.push into stack
2.pop out of stack
3.display the stack
4.enqueue the queue
5.dequeue the queue
6.display the queue
-1 exit the program
6
20 30 ENTER YOUR CHOICE
1.push into stack
2.pop out of stack
3.display the stack
4.enqueue the queue
5.dequeue the queue
6.display the queue
-1 exit the program
-1
