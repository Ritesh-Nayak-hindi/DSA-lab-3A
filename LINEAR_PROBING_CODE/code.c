// linaer probing in hashing code

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define table_size 10

int hashtable[table_size];
bool isOccupied[table_size]={false};

int hashingfunction(int key){
    return (key%table_size);
}

void insert(int key){
    int index=hashingfunction(key);
    int orgIndex=index;
    while(isOccupied[index]){
        index=(index+1)%table_size;
        if(index==orgIndex){
            printf("THE TABLE IS FULL");
            return;
        }
    }
    hashtable[index]=key;
    isOccupied[index]=true;
}

int search(int key){
    int index=hashingfunction(key);
    int orgIndex=index;
    while(isOccupied[index]){
        if(hashtable[index]==key){
            return index;
        }
        index=(index+1)%table_size;
        if(index==orgIndex){
            return -1;
        }
    }
    return -1;
}

void delete(int key){
    int index=search(key);
    if(index==-1){
        printf("THE KEY IS NOT PRESENT IN THE GIVEN TABLE");
        return;
    }
    printf("DELETED INDEX IS %d AND VALUE IS %d",index,hashtable[index]);
    isOccupied[index]=false;
}

void display(void){
    for(int i=0;i<table_size;i++){
        if(isOccupied[i]){
            printf("THE ELEMENT AT INDEX %d IS %d\n",i,hashtable[i]);
        }
        else{
            printf("NO ELEMENT IS PRESENT AT INDEX %d\n",i);
        }
    }
}

int main(void){
    insert(43);
    insert(135);
    insert(72);
    insert(23);
    insert(99);
    insert(19);
    insert(82);
    printf("%d: ",search(23));
}

// OUTPUT:
// THE INDEX IS FOUND:4
// THE ELEMENT AT INDEX 0 IS 19
// NO ELEMENT IS PRESENT AT INDEX 1
// THE ELEMENT AT INDEX 2 IS 72
// THE ELEMENT AT INDEX 3 IS 43
// THE ELEMENT AT INDEX 4 IS 23
// THE ELEMENT AT INDEX 5 IS 135
// THE ELEMENT AT INDEX 6 IS 82
// NO ELEMENT IS PRESENT AT INDEX 7
// NO ELEMENT IS PRESENT AT INDEX 8
// THE ELEMENT AT INDEX 9 IS 99

