#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char* msg;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

void insert_list(char* msg)
{
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        perror("Could not insert node");
        exit(EXIT_FAILURE);
    }

    node->msg = malloc(strlen(msg) + 1);
    if (node->msg == NULL) {
        perror("Could not insert message");
        free(node);
        exit(EXIT_FAILURE);
    }

    strncpy(node->msg, msg, strlen(msg) + 1);

    // Insert at the start of the list
    node->next = head;
    if (node->next != NULL) {
        node->next->prev = node;
    }
    node->prev = NULL;

    if (head != NULL) {
        head->prev = node;
    }

    head = node;
}

void print_list(void)
{
    Node* current = head;

    while (current != NULL) {
        printf("%s\n", current->msg);
        current = current->next;
    }
}

void free_list(void)
{
    Node* current = head;

    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->msg);
        free(temp);
    }
}

Node* find_node(char* msg)
{
    Node* current = head;

    while (current != NULL) {
        if (strcmp(current->msg, msg) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

bool delete_node(char* msg)
{
    // The list is empty or we couldnt find the node
    Node* node = find_node(msg);
    if (node == NULL || head == NULL) {
        return false;
    }

    // Node to delete is at the start
    if (node == head) {
        head = node->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else {
        // Node is not at the start
        node->prev->next = node->next;
        if (node->next != NULL) {
            node->next->prev = node->prev;
        }
    }

    free(node->msg);
    free(node);

    return true;
}

int main(void)
{
    return 0;
}
