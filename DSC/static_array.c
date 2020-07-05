//
//  array.c
//  DSC
//
//  Created by ahmed shalaby on 7/5/20.
//  Copyright © 2020 ahmed shalaby. All rights reserved.
//

#include "static_array.h"

// Initialize an array with static length
const int N = 1e5+3;
int n;
int arr[N];

int test_array() {

    // Functionality Testing
    
    printf("Array size: %d \n", n);
    printf("Array items: ");
    print_array();
    printf("\n");
    printf("----------------------------------------------------\n");

    /* Expected Output:
    Array size: 0
    Array items:
    ----------------------------------------------------
    */
    
    printf("adding the following elements 10 20 30 40 50\n");
    insert_element(10, n);
    insert_element(20, n);
    insert_element(30, n);
    insert_element(40, n);
    insert_element(50, n);
    printf("the above elements have been added to the array\n");

    /* Expected Output:
    adding the following elements 10 20 30 40 50
    the above elements have been added to the array
    */

    printf("Array size: %d \n", n);
    printf("Array items: ");
    print_array();
    printf("\n");
    printf("----------------------------------------------------\n");

    /* Expected Output:
    Array size: 5
    Array items: 10 20 30 40 50
    ----------------------------------------------------
    */

    printf("add element 60 at position %d : \n", n);
    insert_element(60, n);
    printf("Array size: %d\n", n);
    printf("Array items: ");
    print_array();
    printf("\n");
    printf("----------------------------------------------------\n");

    /* Expected Output:
    add element 60 at position 5 :
    Array size: 6
    Array items: 10 20 30 40 50 60
    ----------------------------------------------------
    */

    printf("add element 20 at position 0 : \n");
    insert_element(20, 0);
    printf("Array size: %d \n", n);
    printf("Array items: ");
    print_array();
    printf("\n");
    printf("----------------------------------------------------\n");

    /* Expected Output:
    add element 20 at position 0 :
    Array size: 7
    Array items: 20 10 20 30 40 50 60
    ----------------------------------------------------
    */

    printf("add element 70 at position 4 : \n");
    insert_element(70, 4);
    printf("Array size: %d \n", n);
    printf("Array items: ");
    print_array();
    printf("\n");
    printf("----------------------------------------------------\n");

    /* Expected Output:
    add element 70 at position 4 :
    Array size: 8
    Array items: 20 10 20 30 70 40 50 60
    ----------------------------------------------------
    */

    printf("add element 90 at position %d : \n", n-1);
    insert_element(90, n-1);
    printf("Array size: %d \n", n);
    printf("Array items: ");
    print_array();
    printf("\n");
    printf("----------------------------------------------------\n");

    /* Expected Output:
    add element 90 at position 7 :
    Array size: 9
    Array items: 20 10 20 30 70 40 50 90 60
    ----------------------------------------------------
    */

    printf("delete element at position 0 : \n");
    delete_element(0);
    printf("Array size: %d \n", n);
    printf("Array items: ");
    print_array();
    printf("\n");
    printf("----------------------------------------------------\n");

    /* Expected Output:
    delete element at position 0 :
    Array size: 8
    Array items: 10 20 30 70 40 50 90 60
    ----------------------------------------------------
    */

    printf("delete element at position %d : \n", n-1);
    delete_element(n-1);
    printf("Array size: %d \n", n);
    printf("Array items: ");
    print_array();
    printf("\n");
    printf("----------------------------------------------------\n");

    /* Expected Output:
    delete element at position 7 :
    Array size: 7
    Array items: 10 20 30 70 40 50 90
    ----------------------------------------------------
    */

    printf("delete element at position 3 : \n");
    delete_element(3);
    printf("Array size: %d \n", n);
    printf("Array items: ");
    print_array();
    printf("\n");
    printf("----------------------------------------------------\n");

    /* Expected Output:
    delete element at position 3 :
    Array size: 6
    Array items: 10 20 30 40 50 90
    ----------------------------------------------------
    */

    int i = 40;
    if (search_element(i))
        printf("element %d in the array\n", i);
    else
        printf("element %d not in the array\n", i);

    i = 100;
    if (search_element(i))
        printf("element %d in the array\n", i);
    else
        printf("element %d not in the array\n", i);
    printf("----------------------------------------------------\n");

    /* Expected Output:
    element 40 in the array
    element 100 not in the array
    ----------------------------------------------------
    */
    
    return 0;

}
// This function inserts an element at the given index in the array
void insert_element(int item, int idx) {
    // check for invalid index
    if (idx < 0 || idx > n)
        return;
    // loop to shif values till reach the given index
    int j = n;
    while (j >= idx) {
        arr[j+1] = arr[j];
        j = j - 1;
    }
    // insert the new element
    arr[idx] = item;
    // update the size of the array
    n = n + 1;
}

// This function deletes an element at the given index in the array
void delete_element(int idx) {
    // check for invalid index
    if (idx < 0 || idx >= n)
        return;
    // loop to shif values till reach end of the array
    int j = idx;
    while (j < n) {
        arr[j] = arr[j+1];
        j = j + 1;
    }
    // update the size of the array
    n = n - 1;
}

// This function searches for an element in the array
bool search_element(int item) {
    int j = 0;
    // loop to find the given element in the array
    while (j < n) {
        if (arr[j] == item)
            // return that the element in the array
            return true;
        j = j + 1;
    }
    // return that the element not in the array
    return false;
}

// This function prints the contents of the array
void print_array() {
    // loop to print the elements in the array
    for (int i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);
}

