/*
 * Find the intersection of 2 list and return it
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

// return de reference of the node that intersect the list listA and listB
NodePtr findIntersection(NodePtr listA, NodePtr listB) {
    // we cannot lose the head of list B
    NodePtr headListB = listB;

    // not found any intersection
    if(listA == NULL)
        return NULL;

    while(listB != NULL) {
        if(listA == listB)
            return listA;
        else
            listB = listB->next;
    }
    return findIntersection(listA->next, headListB);
}

void checkResult(NodePtr result) {
    if (NULL != result) 
        printf("Intersected [%d]\n", result->num);
    else
        printf("Not intersected. \n");
    return;
}

void doIt(int numbers[], int sizeVectorNumbers) {
    // create linked list from vector numbers
    NodePtr listA = createLinkedList(numbers, sizeVectorNumbers);
    printLinkedList(listA);

    NodePtr result = findIntersection(listA, listA->next->next);
    checkResult(result);
    

    NodePtr listB = listA->next->next->next->next;
    result = findIntersection(listA, listB);
    checkResult(result);

    listB = createLinkedList(numbers, sizeVectorNumbers);
    result = findIntersection(listA, listB);
    checkResult(result);
}

int main() {

    int numbers[] = { 0, 0, 1, 7, 4, 6 };
    int sizeVectorNumbers = sizeof(numbers)/sizeof(int);
    doIt(numbers, sizeVectorNumbers);

    return 0;
}
