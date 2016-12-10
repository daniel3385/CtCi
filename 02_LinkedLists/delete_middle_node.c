/*
 * Delete middle node of a linked list
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

void printLinkedList(NodePtr node) {
    printf("\n");
    while(node != NULL) {
        if(node->next != NULL)
            // It's not the last node
            printf("(%d)->", node->num);
        else
            // It's the last node
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

void nodeDelete(NodePtr node) {
    node->num = node->next->num;                                       
    NodePtr nodeTmp = node->next;                                      
    node->next = node->next->next;                                    
    free(nodeTmp);
}

void doIt(int numbers[], int sizeVectorNumbers, int kth) {
    // create linked list from vector numbers
    NodePtr list = createLinkedList(numbers, sizeVectorNumbers);
   
    // convert the index kth in the node to be deleted
    NodePtr nodeToDelete = list;
    int index = 1;
    while(index < kth) {
        nodeToDelete = nodeToDelete->next;
        index++;
    }

    // print list before action
    printf("Delete the %d element.", kth);
    printLinkedList(list);

    nodeDelete(nodeToDelete);

    // print list again
    printLinkedList(list);
}

int main() {

    int numbers[] = {0, 0, 1, 7, 4 ,6};
    int sizeVectorNumbers = sizeof(numbers)/sizeof(int);
    doIt(numbers, sizeVectorNumbers, 4);

    int numbers2[] = {0, 4, 4, 4, 6, 8, 9};
    int sizeVectorNumbers2 = sizeof(numbers2)/sizeof(int);
    doIt(numbers2, sizeVectorNumbers2, 3);

    int numbers3[] = {0, 4, 10, 8, 6, 8, 6, 8, 0, 10, 12 };
    int sizeVectorNumbers3 = sizeof(numbers3)/sizeof(int);
    doIt(numbers3, sizeVectorNumbers3, 5);

    return 0;
}
