/*
 * Remove duplicate from a unsorted linked list
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr nodeNew(int n) {
    NodePtr node = malloc(sizeof(Node));
    node->num = n;
    node->next = NULL;
    return node;
}

void deleteNode(NodePtr node) {
    node->num = node->next->num;
    NodePtr nodeTmp = node->next;
    node->next = node->next->next;
    free(nodeTmp);
}

void printLinkedList(NodePtr node) {
    printf("\n");
    while(node != NULL) {
        if(node->next != NULL)
            printf("(%d)->", node->num);
        else
            printf("(%d)", node->num);
        node = node->next;
    }
    printf("\n");
}

// Node create linke list
// head is the head of the linked list
// numberto list and number total refer to a vector os numbers
// to convert in a list
NodePtr createLinkedList(int numbersToList[], int numberTotal) {
    int index = 0; 
    NodePtr node = NULL;
    NodePtr head = NULL;
    NodePtr tail = NULL;
    // while there is int to read
    while(index < numberTotal) {
        // create node
        node = nodeNew(numbersToList[index]);
        if(head == NULL) {
            // is the first node
            head = node;
        } else {
            // put node at last element of list
            tail->next = node;
        }
        tail = node;
        index++;
    }
    return head;
}

/* p2 will run the list faster than p1,
 * if they match the same node, delete it
 */
void removeDupsLinkedList(NodePtr head) {
    if(head->next == NULL) {
        // just 1 node
        return;
    }
    NodePtr p1 = head;
    NodePtr p2 = head->next;

    while(p2 != NULL) {
        if(p2->num == p1->num) 
            deleteNode(p2);
        else
            p2 = p2->next;
    }
    removeDupsLinkedList(p1 = p1->next);
}

void doIt(int numbers[], int sizeVectorNumbers) {
    // create linked list from vector numbers
    NodePtr list = createLinkedList(numbers, sizeVectorNumbers);

    // print list
    printLinkedList(list);

    // remove dups from list'
    removeDupsLinkedList(list);

    // print list again
    printLinkedList(list);
    printf("-------------------------------\n");
}

int main() {

    int numbers[] = {0, 0, 1, 7, 4 ,6};
    int sizeVectorNumbers = sizeof(numbers)/sizeof(int);
    doIt(numbers, sizeVectorNumbers);

    int numbers2[] = {0, 4, 4, 4, 6, 8, 9};
    int sizeVectorNumbers2 = sizeof(numbers2)/sizeof(int);
    doIt(numbers2, sizeVectorNumbers2);

    int numbers3[] = {0, 4, 10, 8, 6, 8, 6, 8, 0, 10, 12 };
    int sizeVectorNumbers3 = sizeof(numbers3)/sizeof(int);
    doIt(numbers3, sizeVectorNumbers3);

    return 0;
}
