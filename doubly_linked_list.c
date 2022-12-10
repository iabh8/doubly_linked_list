#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;

void  insert_beg(int item){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    
    if (ptr == NULL){
        printf("\nOverflow");
    }
    else{
        if (head == NULL){
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = item;
            head = ptr;
        }
        else{
            ptr->data = item;
            ptr->next = head;
            ptr->prev = NULL;
            head->prev = ptr;
            head = ptr;
        printf("\nItem added at the begining!");
        }
    }
}

void insert_end(int item){
    struct node *current, *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    
    if (ptr == NULL){
        printf("\nOverflow");
    }
    else{
        if (head == NULL){
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = item;
            head = ptr;
        }
        else{
            current = head;
            while(current->next != NULL){
                current = current->next;
            }
            ptr->next = NULL;
            ptr->data = item;
            current->next = ptr;
            ptr->prev = current;
        }
        printf("\nItem added at the end!");
    }
}

void delete_beg(){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    
    if (head == NULL){
        printf("\nUnderflow");
    }
    else{
        if (head->next == NULL){
            head = NULL;
            free(head);
        }
        else{
            ptr = head;
            head = head->next;
            head->prev = NULL;
            free(ptr);
        }
        printf("\nFirst node deleted!");
    }
}

void delete_end(){
    struct node *current;
    current = (struct node *)malloc(sizeof(struct node));
    
    if (head == NULL){
        printf("\nUnderflow");
    }
    else{
        if (head->next == NULL){
            head = NULL;
            free(head);
        }
        else{
            current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->prev->next = NULL;
            free(current);
        }
        printf("\nLast node deleted!");
    }
}

void display(){
    printf("\n");
    struct node *current;
    current = (struct node *)malloc(sizeof(struct node));
    current = head;
    
    while(current!=NULL){
        printf("%d\t", current->data);
        current = current->next;
    }
}

void main(){
    insert_beg(10);
    insert_beg(30);
    insert_beg(50);
    insert_end(-10);
    insert_end(-30);
    display();
    delete_beg();
    delete_end();
    display();
}
