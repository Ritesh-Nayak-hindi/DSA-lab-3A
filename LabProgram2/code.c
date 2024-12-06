
#include<stdio.h>
#include<conio.h>
#include<string.h>

int top=-1,pos=0,index=0,length;
char symbol,temp,infix[20],stack[20],postfix[20];

void push(char d){
    top++;
    stack[top]=d;
}

char pop(){
    char symb=stack[top];
    top--;
    return symb;
}

int pred(char symbol){
    int p;
    switch (symbol){
        case '#': p=-1;
        break;

        case '(':p=0;
        break;

        case '+':
        case '-':p=1;
        break;

        case '*':
        case '/':p=2;
        break;

        case '^':p=3;
        break;
    }
    return p;
}

void infixtopostfix(){
    length=strlen(infix);
    push('#');
    while(index<length){
        symbol=infix[index];
        switch (symbol){
            case '(':
            push(symbol);
            break;

            case ')':
            temp=pop();
            while(temp!='('){
                postfix[pos++]=temp;
                temp=pop();
            }
            break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            while(pred(stack[top])>=pred(symbol)){
                temp=pop();
                postfix[pos++]=temp;
            }
            push(symbol);
            break;

            default: postfix[pos++]=symbol;
        }
        index++;
    }
    while(top>0){
        temp=pop();
        postfix[pos++]=temp;
    }
postfix[pos]='\0';

}





void main(){
    printf("Enter infix expression:");
    scanf("%s",infix);

    infixtopostfix();

    printf("Postfix Expression:%s",postfix);
    getch();
}



//Output-:

//Enter infix expression:A^B*C-D+E/F/(G+H)
//Postfix Expression:AB^C*D-EF/GH+/+
