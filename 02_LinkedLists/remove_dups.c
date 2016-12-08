/*
 * Remove duplicate from a unsorted linked list
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr makeNode(int n) {
    NodePtr node = malloc(sizeof(Node));
    node->num = n;
    node->next = NULL;
    return node;
}

NodePtr deleteNode(NodePtr node) {
    //TODO
}

void printLinkedList(NodePtr node) {
    printf("\n");
    while(node != NULL) {
        printf("(%d)->", node->num);
        node = node->next;
    }
    printf("(END)\n");
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
        node = makeNode(numbersToList[index]);
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

void removeDupsLinkedList(NodePtr head) {
    // create nodeptr p1 and p2
    // while p1 diff from NULL
    //   while p2 diff from NULL
    //     if p1 == p2
    //     remove node(p2)
    //   advance p1 to next node
}


int main() {
    int numbers[] = {0, 4 ,6};
    int sizeVectorNumbers = sizeof(numbers)/sizeof(int);
    // create linked list from vector numbers
    NodePtr list = createLinkedList(numbers, sizeVectorNumbers);

    // print list
    printLinkedList(list);

    // remove dups from list'
    // TODO

    // print list again
    printLinkedList(list);
    return 0;
}
