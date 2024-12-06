#include <stdio.h>
#include <stdlib.h>
#define s 3
int arr[3],top=-1,item,ch;


void push(){
    if(top==s-1){
        printf("Stack overflow\n");
        return;
    }
    printf("Enter element to insert:");
    scanf("%d",&item);
    top+=1;
    arr[top]=item;
    printf("Done\n");
}

int pop(){
    if(top==-1){
        printf("Stack underflow\n");
        return -1;
    }
    item=arr[top];
    top--;
    return item;
}

void topele(){
    if(top==-1){
        printf("empty Stack\n");
        return;
    }
    printf("top element:%d\n",arr[top]);
}

void isempty(){
    if(top==-1){
        printf("empty\n");
        return;
    }
    printf("Not empty\n");   
}

void isfull(){
    if(top==s-1){
        printf("full\n");
        return;
    }
    printf("Not full\n");
}

void display(){
    if(top==-1){
        printf("empty Stack\n");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}



void main()
{
    while(1){
        printf("1-push,2-pop,3-topele,4-isempty,5-isfull,6-display,7-exit:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            push();
            break;

            case 2:
            printf("%d\n",pop());
            break;

            case 3:
            topele();
            break;

            case 4:
            isempty();
            break;

            case 5:
            isfull();
            break;

            case 6:
            display();
            break;

            case 7:
            exit(0);

        }
    }

    return;
}
