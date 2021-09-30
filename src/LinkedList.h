// Author: Ricardo J. Castillo López

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
    void del();                         // Delete the list (Destructor).
    void printList();                   // Print the list.
};

// Class constructor and methods of the class template:

// Constructor:
template <class T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
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
            while (aux != nullptr) {
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
    while (aux != nullptr && aux->data != data) {
        aux = aux->next;
        index++;
    }
    if (aux == nullptr) {
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
    new_node->next = nullptr;
    if (this->head == nullptr) {
        this->head = new_node;
    }
    else {
        Node<T>* aux = this->head;
        while (aux->next != nullptr) {
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
                while (aux->next != nullptr && pos != index) {
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
                while (aux->next != nullptr) {
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
                while (aux->next != nullptr) {
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
    Node<T>* temp = nullptr;
    Node<T>* inv = nullptr;
    while (aux != nullptr) {
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
    Node<T>* temp = nullptr;
    while (aux != nullptr) {
        temp = aux->next;
        free(aux);
        aux = temp;
    }
    this->head = nullptr;
    this->curr_size = 0;
}

// Print the list:
template <class T>
void LinkedList<T>::printList() {
    Node<T>* aux = this->head;
    while (aux != nullptr) {
        std::cout << aux->data << " ";
        aux = aux->next;
    }
    std::cout << std::endl;
}

#endif