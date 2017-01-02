/*
 * Detect a loop in a linked list
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

void printCircularLinkedList(NodePtr node) {
    NodePtr headList = node;

    if(node == NULL) {
        printf("(NULL)\n");
        return;
    }

    printf("\n");
    while(node->next != headList) {
        printf("(%d)->", node->num);
        node = node->next;
    }
    // Print the head to show that is a circular list
    printf("(%d)", node->num);
    printf("\n");
}

// Node create linke list
// head is the head of the linked list
// numberto list and number total refer to a vector os numbers
// to convert in a list
NodePtr createCircularLinkedList(int numbersToList[], int numberTotal) {
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
    tail->next = head;
    return head;
}

/* p2 will run the list faster than p1,
 * if they match the same node, it's the loop.
 */
NodePtr findLoopNode(NodePtr list) {
    if(list == NULL) {
        printf("There is no list.\n");
        return NULL;
    }

    if(list->next == NULL) {
        printf("There is one node in the list.\n");
        return list;
    }

    NodePtr p1 = list;
    NodePtr p2 = list->next;

    while(p1 != NULL) {
        while(p2 != NULL) {
            if(p1 == p2)
                return p1;
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    // There is no loop
    return NULL;

}

void doIt(int numbers[], int sizeVectorNumbers) {
    // create linked list from vector numbers
    NodePtr list = createCircularLinkedList(numbers, sizeVectorNumbers);

    // print list
    printCircularLinkedList(list);

    // remove dups from list'
    NodePtr loopNode = findLoopNode(list);

    // print list again
    printf("Loop is [%d]\n", loopNode->num);
    printf("-------------------------------\n");
}

int main() {

    int numbers[] = {0, 0, 1, 7, 4 ,6};
    int sizeVectorNumbers = sizeof(numbers)/sizeof(int);
    doIt(numbers, sizeVectorNumbers);

    int numbers2[] = {70, 4, 4, 4, 6, 8, 9};
    int sizeVectorNumbers2 = sizeof(numbers2)/sizeof(int);
    doIt(numbers2, sizeVectorNumbers2);

    int numbers3[] = {10, 4, 10, 8, 6, 8, 6, 8, 0, 10, 12 };
    int sizeVectorNumbers3 = sizeof(numbers3)/sizeof(int);
    doIt(numbers3, sizeVectorNumbers3);

    return 0;
}
