#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insert(struct Node** head, int data) {
    struct Node* current = *head;

    if ((*head)->data >= data) {
        insertAtHead(head, data);
        return;
    }

    while (current->next != NULL) {
        if (current->next->data >= data) {
            struct Node* newNode = createNode(data);
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    insertAtEnd(*head, data);
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) printf(" ");
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    if (n <= 0) {
        return 0;
    }
    int data = 0;
    scanf("%d", &data);
    printf("%d\n", data);
    struct Node* head = createNode(data);
    while (--n) {
        scanf("%d", &data);
        insert(&head, data);
        printList(head);
    }
    freeList(head);
    return 0;
}