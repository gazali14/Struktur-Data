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

void count(ptrnode head) {
    int count = 0;
    struct node *p;
    p = head;
    while (p != NULL) {
        p = p->next;
        count++;
    }
    printf("\nJumlah node adalah : %d\n", count);
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
    count(head);

    return 0;
}
