#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for each node of the linked list
typedef struct Node {
    char data[100];
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(char data[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insert(Node** head, char data[]) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to search for a string in the linked list
int search(Node* head, char target[]) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->data, target) == 0) {
            return 1; // String found
        }
        current = current->next;
    }
    return 0; // String not found
}

int main() {
    Node* head = NULL;

    // Populate the linked list with some sample strings
    insert(&head, "apple");
    insert(&head, "banana");
    insert(&head, "orange");
    insert(&head, "grape");
    insert(&head, "kiwi");

    // Ask the user to enter a string to search for
    char target[100];
    printf("Enter a string to search for: ");
    scanf("%s", target);

    // Perform the search
    if (search(head, target)) {
        printf("String '%s' found in the list.\n", target);
    } else {
        printf("String '%s' not found in the list.\n", target);
    }

    return 0;
}
