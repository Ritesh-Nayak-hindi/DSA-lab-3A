// addition of two numbers
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
char num1[10];
char num2[10];
struct Node *head1=NULL;
struct Node *head2=NULL;
char result[10];

void set_num1(){
    printf("ENTER A NULL CAHARACTER TO END NUMBER\n");
    for(int i=0;i<=9;i++){
        char ch;
        scanf(" %c",&ch);
        num1[i]=ch;
        if(ch=='*'){
            num1[i]='\0';
            break;
        }
        
    }
}
void set_num2(){
    printf("ENTER '*' NULL CAHARACTER TO END NUMBER\n");
    for(int i=0;i<=9;i++){
        char ch;
        scanf(" %c",&ch);
        num2[i]=ch;
        if(ch=='*'){
            num2[i]='\0';
            break;
        }
        
    }
}
void insert(struct Node **L1,int data){
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if(*L1==NULL){
        *L1=temp;
        return;
    }
    temp->next=*L1;
    *L1=temp;
}
void create(){
    printf("WHICH NUMBER WOULD YOU LIKE TO SET 1 or 2\n");
    int a;
    scanf("%d",&a);
    if(a==1){
        int i=0;
        while(num1[i]!='\0'){
            insert(&head1,num1[i] - '0');
            i++;
        }
    }
    else{
        int i=0;
        while(num2[i]!='\0'){
            insert(&head2,num2[i] - '0');
            i++;
        }
    }
}

void add(char result[]){
    int carry=0,sum=0,operand1=0,operand2=0,index=0;
    struct Node *temp1=head1;
    struct Node *temp2=head2;
    while(temp1!=NULL || temp2!=NULL){
        (temp1==NULL)? operand1=0:(operand1=temp1->data);
        (temp2==NULL)? operand2=0:(operand2=temp2->data);
        
        sum=operand1+operand2+carry;
        if(sum>=10){
            carry=1;
            sum=sum%10;
        }
        else{
            carry=0;
        }
        result[index]=sum+'0';
        index++;
        
        if(temp1!=NULL){
            temp1=temp1->next;
        }
        if(temp2!=NULL){
            temp2=temp2->next;
        }
    }
    result[index]='\0';
    
    
}

void reverse(char result[]){
    int len=0;
    while(result[len]!='\0'){
        len++;
    }
    char temp[len];
    for(int i=0;i<len;i++){
        temp[i]=result[len-i-1];
    }
    for(int i=0;i<len;i++){
        result[i]=temp[i];
    }
    
    
}

void display(){
    int i=0;
    reverse(result);
    while(result[i]!='\0'){
        printf("%c",result[i]);
        i++;
    }
}

int main(){
    while(1){
        printf("ENTER THE CHOICE\n1.set_number1()\n2.set_number2()\n3.create()\n4.add()\n5.display()\n-1 to exit the program");
        int i;
        scanf("%d",&i);
        if(i==-1){
            exit(0);
        }
        switch (i) {
            case 1:
                set_num1();
                break;
            case 2:
                set_num2();
                break;
            case 3:
                create();
                break;
            case 4:
                add(result);
                break;
            case 5:
                display();
                break;
                
            default:
                break;
        }
    }
    
}
