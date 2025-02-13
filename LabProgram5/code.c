//Linked List Implementation
#include <stdio.h>
#include <stdlib.h> 

struct Node {
    int data;
    struct Node *link;
};

typedef struct Node node;
node *start = NULL;

void insertAtBeginning() {
    node *new1 = (node*)malloc(sizeof(node));
    if (new1 == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    printf("Enter value to insert at beginning: ");
    scanf("%d", &new1->data);
    
    new1->link = start;  
    start = new1;    
}

void insertAtEnd() {
    node *new1 = (node*)malloc(sizeof(node)); 
    if (new1 == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    printf("Enter value to insert at end: ");
    scanf("%d", &new1->data);
    
    new1->link = NULL;
    
    if (start == NULL) {
        start = new1;
    } else {
        node *temp = start;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = new1; 
    }
}

void insertAtPosition() {
    int pos;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        return;
    }
    
    node *new1 = (node*)malloc(sizeof(node)); 
    if (new1 == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    printf("Enter value to insert at position %d: ", pos);
    scanf("%d", &new1->data);
    
    if (pos == 1) {
        new1->link = start;
        start = new1;
    } else {
        node *temp = start;
        for (int i = 1; i < pos - 1; i++) {
            if (temp == NULL) {
                printf("Position out of range.\n");
                free(new1);
                return;
            }
            temp = temp->link;
        }

        new1->link = temp->link;
        temp->link = new1;
    }
}

void deleteAtBeginning() {
    if (start == NULL) {
        printf("The list is empty, nothing to delete.\n");
        return;
    }
    
    node *temp = start;    
    start = start->link; 
    free(temp); 
    
    printf("Node deleted from the beginning.\n");
}

void deleteAtEnd() {
    if (start == NULL) {
        printf("The list is empty, nothing to delete.\n");
        return;
    }
    
    if (start->link == NULL) {
        free(start);
        start = NULL;
        printf("Node deleted from the end.\n");
        return;
    }
    
    node *temp = start;
    while (temp->link != NULL && temp->link->link != NULL) { // Traverse to the second last node
        temp = temp->link;
    }
    
    free(temp->link);  
    temp->link = NULL;
    
    printf("Node deleted from the end.\n");
}

void deleteAtPosition() {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

  
    if (pos < 1 || start == NULL) {
        printf("Invalid position or list is empty.\n");
        return;
    }
    
    if (pos == 1) {
        node *temp = start;
        start = start->link;
        free(temp);
        printf("Node deleted from position 1.\n");
        return;
    }

    node *temp = start;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL || temp->link == NULL) {
            printf("Position out of range.\n");
            return;
        }
        temp = temp->link;
    }

    node *delNode = temp->link; 
    temp->link = temp->link->link; 
    free(delNode); 
    
    printf("Node deleted from position %d.\n", pos);
}

void display() {
    node *temp;
    if (start == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    
    printf("Elements in the linked list: ");
    temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int ch;
    
    while (1) {
        printf("1 :Insert at Beginning  \n2 :Insert at End  \n3 :Insert at Position  \n4 :Delete at Beginning  \n5 :Delete at End  \n6 :Delete at Position  \n7 :Display  \n8 :Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAtPosition();
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                deleteAtPosition();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);  // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
