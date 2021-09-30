#pragma once
#ifndef LINKEDLIST_H 

#define LINKEDLIST_H
#include <iostream>

// Node template:
template <class T>
class Node {
public:
    T data;
    Node<T>* next;
};

// Linked list class template:
template <class T>
class LinkedList {
private:
    Node<T>* head;
public:
    int curr_size;
    // Constructor:
    LinkedList();
    // Methods:  
    int size();                         // Get the size of the list.
    T get(int index);                   // Get an element from a particular index.
    int index(T data);                  // Get the index of the first matching value from the list.
    void push(T data);                  // Insert an element at the beggining of the list.
    void append(T data);                // Insert an element at the end of the list.
    void insert(int index, T data);     // Insert an element at a particular index.
    void remove(T data);                // Remove the first matching value from the list.
    void pop(int index);                // Delete an element at a particular index.
    void reverse();                     // Reverse the list.
    void del();                         // Delete the list.
    void printList();                   // Print the list.
};

// Class constructor and methods of the class template:

// Constructor:
template <class T>
LinkedList<T>::LinkedList() {
    this->head = NULL;
    this->curr_size = 0;
}

// Get the size of the list:
template <class T>
int LinkedList<T>::size() {
    return this->curr_size;
}

// Get an element from a particular index:
template <class T>
T LinkedList<T>::get(int index) {
    try {
        if (this->curr_size == 0) {
            throw "Empty list";
        }
        else {
            if (this->curr_size <= index) {
                throw "Index out of range";
            }
            Node<T>* aux = this->head;
            int pos = 0;
            while (aux != NULL) {
                if (pos == index) {
                    return aux->data;
                }
                aux = aux->next;
                pos++;
            }
        }
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }

    /*
    T temp[1] = {};
    T& obj = temp[0];
    return obj;
    */
}

// Get the index of the first matching value from the list.
template <class T>
int LinkedList<T>::index(T data) {
    Node<T>* aux = this->head;
    int index = 0;
    while (aux != NULL && aux->data != data) {
        aux = aux->next;
        index++;
    }
    if (aux == NULL) {
        return -1;
    }
    else {
        return index;
    }
}

// Insert an element at the beggining of the list:
template <class T>
void LinkedList<T>::push(T data) {
    Node<T>* new_node = new Node<T>;
    new_node->data = data;
    new_node->next = this->head;
    this->head = new_node;
    this->curr_size++;
}

// Insert an element at the end of the list:
template <class T>
void LinkedList<T>::append(T data) {
    Node<T>* new_node = new Node<T>;
    new_node->data = data;
    new_node->next = NULL;
    if (this->head == NULL) {
        this->head = new_node;
    }
    else {
        Node<T>* aux = this->head;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = new_node;
    }
    this->curr_size++;
}

// Insert an element at a particular index:
template <class T>
void LinkedList<T>::insert(int index, T data) {
    try {
        if (this->curr_size < index || index < 0) {
            throw "Index out of range";
        }
        else {
            Node<T>* new_node = new Node<T>;
            new_node->data = data;
            if (index == 0) {
                new_node->next = this->head;
                this->head = new_node;
            }
            else {
                Node<T>* aux = this->head;
                int pos = 1;
                while (aux->next != NULL && pos != index) {
                    aux = aux->next;
                    pos++;
                }
                new_node->next = aux->next;
                aux->next = new_node;
            }
            this->curr_size++;
        }
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

// Remove the first matching value from the list:
template <class T>
void LinkedList<T>::remove(T data) {
    try {
        if (this->curr_size == 0) {
            throw "Empty list";
        }
        else {
            if (this->head->data == data) {
                this->head = this->head->next;
            }
            else {
                Node<T>* aux = this->head;
                while (aux->next != NULL) {
                    if (aux->next->data == data) {
                        Node<T>* temp = aux->next;
                        aux->next = aux->next->next;
                        free(temp);
                        break;
                    }
                    aux = aux->next;
                }
            }
            this->curr_size--;
        }
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

// Delete an element at a particular index:
template <class T>
void LinkedList<T>::pop(int index) {
    try {
        if (this->curr_size <= index || index < 0) {
            throw "Index out of range";
        }
        else {
            if (index == 0) {
                this->head = this->head->next;
            }
            else {
                Node<T>* aux = this->head;
                int pos = 1;
                while (aux->next != NULL) {
                    if (pos == index) {
                        Node<T>* temp = aux->next;
                        aux->next = aux->next->next;
                        free(temp);
                        break;
                    }
                    aux = aux->next;
                    pos++;
                }
            }
            this->curr_size--;
        }
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

// Reverse the list:
template <class T>
void LinkedList<T>::reverse() {
    Node<T>* aux = this->head;
    Node<T>* temp = NULL;
    Node<T>* inv = NULL;
    while (aux != NULL) {
        Node<T>* new_node = new Node<T>;
        new_node->data = aux->data;
        new_node->next = inv;
        inv = new_node;
        temp = aux->next;
        free(aux);
        aux = temp;
    }
    this->head = inv;
}

// Delete the list:
template <class T>
void LinkedList<T>::del() {
    Node<T>* aux = this->head;
    Node<T>* temp = NULL;
    while (aux != NULL) {
        temp = aux->next;
        free(aux);
        aux = temp;
    }
    this->head = NULL;
    this->curr_size = 0;
}

// Print the list:
template <class T>
void LinkedList<T>::printList() {
    Node<T>* aux = this->head;
    while (aux != NULL) {
        std::cout << aux->data << " ";
        aux = aux->next;
    }
    std::cout << std::endl;
}

#endif