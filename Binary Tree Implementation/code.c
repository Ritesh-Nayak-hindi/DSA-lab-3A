// tree code to insert,search and delete a node in a tree
// along with its inorder, postorder and preorder traversals

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * create(void){
    struct Node * curr=(struct Node *)malloc(sizeof(struct Node));
    if(!curr){
        return NULL;
    }
    printf("ENTER THE DATA TO BE INSETED AT THE GIVEN NODE");
    int data;
    scanf("%d",&data);
    curr->data=data;
    curr->left=curr->right=NULL;
    return curr;
}

void insert(struct Node *root,struct Node *temp){
    if(temp->data<root->data){
        if(root->left!=NULL){
            insert(root->left, temp);
        }
        else{
            root->left=temp;
        }
    }
    else{
        if(root->right!=NULL){
            insert(root->right, temp);
        }
        else{
            root->right=temp;
        }
        
    }
}

void preorder(struct Node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node *root){
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct Node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void search(struct Node *root,int key){
    if(root==NULL){
        printf("THE TREE IS EMPTY KEY NOT FOUND");
        return;
    }
    if(root->data==key){
        printf("THE KEY IS FOUND:%d-->",root->data);
        return;
    }
    if(key<root->data){
        search(root->left, key);
    }
    else{
        search(root->right, key);
    }
}

void insert_element(struct Node **root,int ele){
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=ele;
    temp->right=temp->left=NULL;
    if(*root==NULL){
        *root=temp;
        return;
    }
    if(ele>(*root)->data){
        insert_element(&(*root)->right, ele);
    }
    else{
        insert_element(&(*root)->left, ele);
    }
}

struct Node * Findmin(struct Node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct Node * delete_tree(struct Node *root,int key){
    if(root==NULL){
        return NULL;
    }
    else if(key<root->data){
        root->left=delete_tree(root->left, key);
    }
    else if(key>root->data){
        root->right=delete_tree(root->right, key);
    }
    else{
        // no child
        if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
            return root;
        }
        // one child
        else if(root->left==NULL){
            struct Node *temp=root;
            root=root->right;
            free(temp);
            temp=NULL;
            return root;
        }
        else if(root->right==NULL){
            struct Node *temp=root;
            root=root->left;
            free(temp);
            temp=NULL;
            return root;
        }
        // 2 children
        else{
            struct Node *temp=Findmin(root->right);
            root->data=temp->data;
            delete_tree(root->right, temp->data);
        }
    }
    return root;
}

int main(void){
    struct Node *root=NULL;
    char c;
    do{
        struct Node *temp=create();
        if(root==NULL){
            root=temp;
        }
        else{
            insert(root, temp);
        }
        printf("DO YOPU LIKE TO INSERT MORE NODES INTO THE TREE?");
        getchar();
        scanf("%c",&c);
    }while(c=='Y' || c=='y');
    
    printf("INORDER TRAVERSAL\n");
    inorder(root);
    printf("\n");
    printf("PREORDER TRAVERSAL\n");
    preorder(root);
    printf("\n");
    printf("POSTORDER TRAVERSAL\n");
    postorder(root);
    printf("\n");
    search(root, 10);
    search(root, 2);
    insert_element(&root, 10);
    printf("INORDER TRAVERSAL\n");
    inorder(root);
    printf("\n");
    delete_tree(root, 23);
    printf("INORDER TRAVERSAL\n");
    inorder(root);
    printf("\n");
    
    
}



// OUTPUT
// ENTER THE DATA TO BE INSETED AT THE GIVEN NODE10
// DO YOPU LIKE TO INSERT MORE NODES INTO THE TREE?y
// ENTER THE DATA TO BE INSETED AT THE GIVEN NODE20
// DO YOPU LIKE TO INSERT MORE NODES INTO THE TREE?y
// ENTER THE DATA TO BE INSETED AT THE GIVEN NODE8
// DO YOPU LIKE TO INSERT MORE NODES INTO THE TREE?y
// ENTER THE DATA TO BE INSETED AT THE GIVEN NODE1
// DO YOPU LIKE TO INSERT MORE NODES INTO THE TREE?y
// ENTER THE DATA TO BE INSETED AT THE GIVEN NODE17
// DO YOPU LIKE TO INSERT MORE NODES INTO THE TREE?y
// ENTER THE DATA TO BE INSETED AT THE GIVEN NODE23
// DO YOPU LIKE TO INSERT MORE NODES INTO THE TREE?y
// ENTER THE DATA TO BE INSETED AT THE GIVEN NODE22
// DO YOPU LIKE TO INSERT MORE NODES INTO THE TREE?y
// ENTER THE DATA TO BE INSETED AT THE GIVEN NODE45
// DO YOPU LIKE TO INSERT MORE NODES INTO THE TREE?n
// INORDER TRAVERSAL
// 1 8 10 17 20 22 23 45 
// PREORDER TRAVERSAL
// 10 8 1 20 17 23 22 45 
// POSTORDER TRAVERSAL
// 1 8 17 22 45 23 20 10 
// THE KEY IS FOUND:10-->THE TREE IS EMPTY KEY NOT FOUNDINORDER TRAVERSAL
// 1 8 10 10 17 20 22 23 45 
// INORDER TRAVERSAL
// 1 8 10 10 17 20 22 45 
