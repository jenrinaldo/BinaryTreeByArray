#include <unistd.h>
//#define checkMemoryLeak

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include "BinaryTreeByArray.h"

//////////////////////////////////////////////////
typedef struct Element {
    int value;
} Element_t;

//////////////////////////////////////////////////
void test(void);
Element_t *createElement(int value);
bool destroyElement(Element_t *element);
int levelOrderTraversalOnBTslave(BT_t *B, int nodeIndex, void *parameter);
int preOrderTraversalOnBTslave(BT_t *B, int nodeIndex, void *parameter);
int inOrderTraversalOnBTslave(BT_t *B, int nodeIndex, void *parameter);
int postOrderTraversalOnBTslave(BT_t *B, int nodeIndex, void *parameter);

//////////////////////////////////////////////////
int main(int argc, const char * argv[]) {
    
#ifdef checkMemoryLeak
    while (true) {
        test();
        sleep(1);
    }
#else
    test();
#endif
    
    return EXIT_SUCCESS;
}

void test() {
    int numElement = 30;
    int findKey = 5;
    int deleteValue = 2;
    const int root = 0;
    
    BT_t *B = createBT();
    for (int i=0; i<numElement; i++) {
        Element_t *element = createElement(i);
        insertElementOnBT(B, i ,element);
    }
    
    printf("--- Binary Tree ---\n");
    viewBT(B, BT_OPTION_VIEW_INT);

    printf("*** level-order traversal ***\n");
    levelOrderTraversalOnBT(B, root, levelOrderTraversalOnBTslave, NULL);
    
    printf("*** pre-order traversal ***\n");
    preOrderTraversalOnBT(B, root, preOrderTraversalOnBTslave, NULL);
    
    printf("*** in-order traversal ***\n");
    inOrderTraversalOnBT(B, root, inOrderTraversalOnBTslave, NULL);
    
    printf("*** post-order traversal ***\n");
    postOrderTraversalOnBT(B, root, inOrderTraversalOnBTslave, NULL);
    
    printf("*** breadth first find ***\n");
    Element_t *element1 = findElementOnBT(B, findKey, BT_OPTION_BREADTH_FIRST_SEARCH);
    printf("breadth first find keyValue %d [%s] : found value = %d\n", findKey, __func__, element1->value);

    printf("*** depth first find ***\n");
    Element_t *element2 = findElementOnBT(B, findKey, BT_OPTION_DEPTH_FIRST_SEARCH);
    printf("depth first find keyValue %d [%s] : found value = %d\n", findKey, __func__, element2->value);

    printf("*** delete ***\n");
    printf("--- Binary Tree ---\n");
    viewBT(B, BT_OPTION_VIEW_INT);

    bool c = deleteElementOnBT(B, deleteValue);
    if (c) {
        printf("delete value %d : success.\n", deleteValue);
    }
    else {
        printf("error [%s] : could not delete value = %d.\n", __func__, deleteValue);
    }
    printf("--- Binary Tree ---\n");
    viewBT(B, BT_OPTION_VIEW_INT);

    destroyBT(B, BT_OPTION_WITH_ELEMENT);
}

Element_t *createElement(int value) {
    Element_t *e = malloc(sizeof(Element_t));
    if (e == NULL) return NULL;
    e->value = value;
    return e;
}

bool destroyElement(Element_t *element) {
    // Block illegal parameters.
    if (element == NULL) return false;
    free(element);
    return true;
}

int levelOrderTraversalOnBTslave(BT_t *B, int nodeIndex, void *parameter) {
    Element_t *element = getElementOnBT(B, nodeIndex);

    printf("level-order traversal : %d\n", element->value);
    return -1;  // none stop.
}

int preOrderTraversalOnBTslave(BT_t *B, int nodeIndex, void *parameter) {
    Element_t *element = getElementOnBT(B, nodeIndex);

    printf("pre-order traversal : %d\n", element->value);
    return -1;  // none stop.
}

int inOrderTraversalOnBTslave(BT_t *B, int nodeIndex, void *parameter) {
    Element_t *element = getElementOnBT(B, nodeIndex);

    printf("in-order traversal : %d\n", element->value);
    return -1;  // none stop.
}

int postOrderTraversalOnBTslave(BT_t *B, int nodeIndex, void *parameter) {
    Element_t *element = getElementOnBT(B, nodeIndex);

    printf("post-order traversal : %d\n", element->value);
    return -1;  // none stop.
}

