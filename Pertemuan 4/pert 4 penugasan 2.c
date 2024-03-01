#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node *ptrnode;

ptrnode createnode(int nilai) {
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->data = nilai;
    p->next = NULL;
    return (p);
}

ptrnode insert_head(ptrnode head, int nilai) {
    ptrnode newnode = createnode(nilai);
    newnode->next = head;
    head = newnode;
    return (head);
}


void tampilnilai(ptrnode head){
    int i=1;
    ptrnode n = head;
    while (n != NULL){
        printf("node ke %d : %d\n",i, n->data);
        n = n->next;
        i++;
    };
    printf("\n");
}

ptrnode tampilnilaiterbalik(ptrnode head){
    struct node *current, *prev, *next;
    current = head;
    prev=NULL;
    while (current != NULL){
        next = current ->next;
        current->next =prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    int data1,n;
    ptrnode head = NULL;

    printf("Masukan jumlah data : ");scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        printf("Masukkan data ke-%d = ", i + 1);
        scanf("%d", &data1);
        head = insert_head(head, data1);
    }
    printf("\nNilai sebelum di reverse\n");
    tampilnilai(head);

    printf("Nilai setelah di reverse\n");
    head=tampilnilaiterbalik(head);
    tampilnilai(head);



    return 0;
}
