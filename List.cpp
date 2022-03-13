/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Value-oriented list
 *                   - Print function runs in linear time -> O(n)
 *
 * Author: Mohammad Saghafian
 * Date: 22/January/2022
 */
#include <iostream>
#include <string>
#include "Patient.h"
#include "List.h" // Header file

using namespace std;

// Constructor
List::List(){
    // Assigning the capacity to the intial capacity
    elementCount = 0;
    capacity = INITIAL_CAPACITY;
    // Allocating initial memory for the value oriented list
    elements = new Patient[INITIAL_CAPACITY];
}

// Destructor
List::~List(){
    // Deleting
    delete [] elements;
}

// Description: Returns the total element count currently stored in List.
int List::getElementCount() const{
    return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented.
bool List::insert(const Patient& newElement){
    // Allocating double of the capacity if elementCount exceeds capacity
    // Also assigning all the previous data to the new memory 
    if(elementCount + 1 > capacity){
        capacity = capacity * 2;
        Patient * newElements = new Patient[capacity];
        for(int i = 0; i < elementCount; i++){
            newElements[i] = elements[i];
        }
        //delete[] elements;
        elements = newElements;
    }
    // Assigning newElement
    Patient P = newElement;
    for(int i = 0; i < elementCount; i++){
        if(elements[i] == P){
            return true;
        }
    }
    // Finding the right position for insertion
    int count = 0;
    // Skipping the unnecessary elements
    while(count < elementCount && elements[count] < P && count < capacity){
        count++;
    }
    // Inserting the new element to the last index.
    if(count == elementCount){
        elements[count] = P;
        elementCount++;
        return true;
    } 
    // Inserting the new element to the right position. And moving every single element
    // By one position
    else{
        // Assigning the old array values to the new array
        for(int i = count; i <= elementCount; i++){
            Patient tmp = elements[i];
            elements[i] = P;
            P = tmp;
        }
        // Increasing the elementCount
        elementCount++;
        return true;
    }
    return false;
}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented. 
bool List::remove( const Patient& toBeRemoved ){
    // Returning if the elementCount is zero
    if(elementCount == 0){
        return false;
    }
    // Allocating new memory for the new array with elementCount - 1.
    Patient toberemoved = toBeRemoved;
    Patient* newElements = new Patient[elementCount];
    int count = 0;
    bool found = false;
    // Copying the elements of the previous array to the new allocated array.
    for(int i = 0; i < elementCount; i++){
        // Skipping the element that matches toBeRemoved
        if(toberemoved == elements[i]){
            found = true;
            continue;
        }
        // Assigning other elements to the new element
        newElements[count] = elements[i];
        count++;
        
    }
    
    if(found){
        // Reducing the elementCount by one
        elementCount--;
        // Deleting the old array
        delete[] elements;
        // Assigning the new array to the old array
        elements = newElements;
        return true;
    }else{
        return false;
    }
}

// Description: Remove all elements.
void List::removeAll(){
    delete [] elements;
    elements = NULL;
    elementCount = 0;
    return;
}
// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target){
    Patient patient = target;
    // Linear search for finding the element
    for(int i = 0; i < elementCount; i++){
        if(patient == elements[i]){
            // Creating an element to return
            Patient* ret = new Patient;
            *ret = elements[i];
            return ret;
        }
        
    }
    
    return NULL;
}

// Description: Prints all elements stored in List by descending order of search key.
void List::printList(){
    for(int i = elementCount-1; i >= 0; i--){
        cout << elements[i];
    }
}
// end List.cpp