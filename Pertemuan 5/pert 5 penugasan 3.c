#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node* mynode;

mynode createNode(int nilai){
    mynode temp;
    temp = (mynode)malloc(sizeof(struct node));;
    temp->data = nilai;
    temp->next = NULL;
    temp->prev = NULL;
}

void insert_head(mynode* head, int data) {
    mynode newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void membalik_nilai(mynode* head) {
    mynode current = NULL;
    mynode temp = NULL;

    while (*head != NULL) {
        temp = (*head)->prev;
        (*head)->prev = (*head)->next;
        (*head)->next = temp;
        current = *head;
        *head = (*head)->prev;
    }

    if (current != NULL) {
        *head = current;
    }
}

void tampilnilai(mynode head) {
    mynode current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL)
            printf(" <=> ");
    }
    printf("\n");
}

int main(){
    int data,n;
    char pilih;
    mynode head = NULL;
    mynode tail = NULL;

    insert_head(&head, 3);
    insert_head(&head, 2);
    insert_head(&head, 1);

    printf("Daftar awal:\n");
    tampilnilai(head);

    membalik_nilai(&head);
    printf("Daftar setelah membalik nilai:\n");
    tampilnilai(head);
    return 0;

}
