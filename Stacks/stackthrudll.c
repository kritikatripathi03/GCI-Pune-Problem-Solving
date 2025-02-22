#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* top = NULL;

void push(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    if(top == NULL){
        top = newNode;
        newNode -> next = NULL;
        newNode -> prev =  NULL;
        return;
    }
    top -> prev = newNode;
    newNode -> next = top;
    top = newNode;
    top -> prev = NULL;
}

void pop(){
    struct node* temp = top;
    if(temp -> next == NULL){
        top = NULL;
        free(temp);
        return;
    }
    top = temp -> next;
    temp -> next = NULL;
    printf("%d\n", temp -> data);
    free(temp);
    top -> prev = NULL;
}

void print(){
    if(top == NULL){
        printf("Stack is Empty!\n");
        return;
    }
    struct node* temp = top;
    while(temp){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main()
{
    push(5);
    print();
    push(6);
    print();
    push(7);
    print();
    push(8);
    print();
    push(9);
    print();
    pop();
    print();
    pop();
    print();
    pop();
    print();
    pop();
    print();
    pop();
    print();
    return 0;
}