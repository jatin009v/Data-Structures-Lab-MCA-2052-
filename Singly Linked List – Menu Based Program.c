// Write a menu-based program in C to implement Singly Linked list and write functions to create node of linked-list; traversing linked-list; insert node in the beginning, 
// middle (after given location) & end of the linked-list; delete node from beginning, middle & end of the linked-list.

#include <stdio.h>
#include <stdlib.h>

// Node ka structure
struct Node {
    int data;              // node ka data part
    struct Node *next;     // next node ka address
};

struct Node *head = NULL; // head pointer (starting node)

// --------- Create New Node ----------
struct Node* createNode(int value) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node)); // memory allocate
    newNode->data = value;   // data set
    newNode->next = NULL;    // next NULL
    return newNode;
}

// --------- Traverse Linked List ----------
void traverse() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("Linked List empty hai\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// --------- Insert at Beginning ----------
void insertBeg(int value) {
    struct Node *newNode = createNode(value);

    newNode->next = head;  // new node next = old head
    head = newNode;        // head update
}

// --------- Insert at End ----------
void insertEnd(int value) {
    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// --------- Insert at Middle (after position) ----------
void insertMiddle(int value, int pos) {
    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// --------- Delete from Beginning ----------
void deleteBeg() {
    struct Node *temp;

    if (head == NULL) {
        printf("List empty hai\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);  // memory free
}

// --------- Delete from End ----------
void deleteEnd() {
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head == NULL) {
        printf("List empty hai\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// --------- Delete from Middle ----------
void deleteMiddle(int pos) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head == NULL) {
        printf("List empty hai\n");
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// --------- Main Menu ----------
int main() {
    int choice, value, pos;

    do {
        printf("\n===== SINGLY LINKED LIST MENU =====\n");
        printf("1. Traverse List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Middle\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from Middle\n");
        printf("7. Delete from End\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            traverse();
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertBeg(value);
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertMiddle(value, pos);
            break;

        case 4:
            printf("Enter value: ");
            scanf("%d", &value);
            insertEnd(value);
            break;

        case 5:
            deleteBeg();
            break;

        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteMiddle(pos);
            break;

        case 7:
            deleteEnd();
            break;

        case 0:
            printf("Program exit ho raha hai...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 0);

    return 0;
}
