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
    Node<T> *next;
};

// Linked list class template:
template <class T>
class LinkedList {
private:
    Node<T> *head;
    int curr_size;
public:
    // Constructor:
    LinkedList();
    // Methods:  
    int size();                         // Returns the size of the list.
    T get(int index);                   // Returns the element at the specified position (index).
    int index(T data);                  // Returns the index of the first element with the specified value.
    int count(T data);                  // Returns the number of elements (ocurrences) with the specified value.
    void push(T data);                  // Adds an element at the beggining of the list.
    void append(T data);                // Adds an element at the end of the list.
    void insert(int index, T data);     // Adds an element at the specified position (index).
    void remove(T data);                // Removes the first item with the specified value.
    void pop(int index);                // Removes the element at the specified position (index).
    void removeDuplicates();            // Removes duplicates of the list.
    void update(int index, T data);     // Updates the value of an element at the specified position (index).
    void reverse();                     // Reverses the order of the list.
    void extend(LinkedList list);       // Add the elements of a list to the end of the current list.
    LinkedList copy();                  // Returns a copy of the current list.
    void clear();                       // Removes all the elements from the list (Destructor).
    void printList();                   // Prints the list.
};

// Class constructor and methods of the class template:

// Constructor:
template <class T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
    this->curr_size = 0;
}

// Returns the size of the list:
template <class T>
int LinkedList<T>::size() {
    return this->curr_size;
}

// Returns the element at the specified position (index):
template <class T>
T LinkedList<T>::get(int index) {
    try {
        if (this->curr_size == 0) {
            throw "Empty list";
        }
        if (this->curr_size <= index || index < 0) {
            throw "Index out of range";
        }
        else {
            Node<T> *aux = this->head;
            int pos = 0;
            while (pos != index) {
                aux = aux->next;
                pos++;
            }
            return aux->data;
        }
    }
    catch (const char *msg) {
        std::cout << msg << std::endl;
    }

    /*
    T temp[1] = {};
    T& obj = temp[0];
    return obj;
    */
}

// Returns the index of the first element with the specified value:
template <class T>
int LinkedList<T>::index(T data) {
    Node<T> *aux = this->head;
    int index = 0;
    while (aux != nullptr && aux->data != data) {
        aux = aux->next;
        index++;
    }
    if (aux == nullptr) {
        return -1; // Element not found.
    }
    else {
        return index;
    }
}

// Returns the number of elements (ocurrences) with the specified value:
template <class T>
int LinkedList<T>::count(T data) {
    Node<T> *aux = this->head;
    int reps = 0;
    while (aux != nullptr) {
        if (aux->data == data) {
            reps++;
        }
        aux = aux->next;
    }
    return reps;
}

// Adds an element at the beggining of the list:
template <class T>
void LinkedList<T>::push(T data) {
    Node<T> *new_node = new Node<T>;
    new_node->data = data;
    new_node->next = this->head;
    this->head = new_node;
    this->curr_size++;
}

// Adds an element at the end of the list:
template <class T>
void LinkedList<T>::append(T data) {
    Node<T> *new_node = new Node<T>;
    new_node->data = data;
    new_node->next = nullptr;
    if (this->head == nullptr) {
        this->head = new_node;
    }
    else {
        Node<T> *aux = this->head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = new_node;
    }
    this->curr_size++;
}

// Adds an element at the specified position (index);
template <class T>
void LinkedList<T>::insert(int index, T data) {
    try {
        if (this->curr_size < index || index < 0) {
            throw "Index out of range";
        }
        else {
            Node<T> *new_node = new Node<T>;
            new_node->data = data;
            if (index == 0) {
                new_node->next = this->head;
                this->head = new_node;
            }
            else {
                Node<T> *aux = this->head;
                int pos = 1;
                while (pos != index) {
                    aux = aux->next;
                    pos++;
                }
                new_node->next = aux->next;
                aux->next = new_node;
            }
            this->curr_size++;
        }
    }
    catch (const char *msg) {
        std::cout << msg << std::endl;
    }
}

// Removes the first item with the specified value:
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
                Node<T> *aux = this->head;
                while (aux->next != nullptr) {
                    if (aux->next->data == data) {
                        Node<T> *temp = aux->next;
                        aux->next = aux->next->next;
                        free(temp);
                        break;
                    }
                    aux = aux->next;
                }
                if (aux->next == nullptr) {
                    throw "Element not found";
                }
            }
            this->curr_size--;
        }
    }
    catch (const char *msg) {
        std::cout << msg << std::endl;
    }
}

// Removes the element at the specified position (index):
template <class T>
void LinkedList<T>::pop(int index) {
    try {
        if (this->curr_size == 0) {
            throw "Empty list";
        }
        if (this->curr_size <= index || index < 0) {
            throw "Index out of range";
        }
        else {
            if (index == 0) {
                this->head = this->head->next;
            }
            else {
                Node<T> *aux = this->head;
                int pos = 1;
                while (pos != index) {
                    aux = aux->next;
                    pos++;
                }
                Node<T> *temp = aux->next;
                aux->next = aux->next->next;
                free(temp);
            }
            this->curr_size--;
        }
    }
    catch (const char *msg) {
        std::cout << msg << std::endl;
    }
}

// Removes duplicates of the list:
template <class T>
void LinkedList<T>::removeDuplicates() {
    Node<T> *aux1 = this->head, *aux2;
    int i, j;
    i = 0;
    while (aux1 != nullptr) {
        aux2 = aux1->next;
        j = i+1;
        while (aux2 != nullptr) {
            if (aux2->data == aux1->data) {
                Node<T> *temp = aux2->next;
                this->pop(j);
                aux2 = temp;
            }
            else {
                aux2 = aux2->next;
                j++;
            }
        }
        aux1 = aux1->next;
        i++;
    }
}

// Updates the value of an element at the specified position (index):
template <class T>
void LinkedList<T>::update(int index, T data) {
    try {
        if (this->curr_size == 0) {
            throw "Empty list";
        }
        if (this->curr_size <= index || index < 0) {
            throw "Index out of range";
        }
        else {
            Node<T>* aux = this->head;
            int pos = 0;
            while (pos != index) {
                aux = aux->next;
                pos++;
            }
            aux->data = data;
        }
    }
    catch (const char *msg) {
        std::cout << msg << std::endl;
    }
}

// Reverses the order of the list:
template <class T>
void LinkedList<T>::reverse() {
    Node<T> *aux = this->head;
    Node<T> *temp = nullptr;
    Node<T> *inv = nullptr;
    while (aux != nullptr) {
        Node<T> *new_node = new Node<T>;
        new_node->data = aux->data;
        new_node->next = inv;
        inv = new_node;
        temp = aux->next;
        free(aux);
        aux = temp;
    }
    this->head = inv;
}

// Add the elements of a list to the end of the current list:
template <class T>
void LinkedList<T>::extend(LinkedList list) {
    int size = list.size();
    int i = 0;
    while (i < size) {
        this->append(list.get(i));
        i++;
    }
}

// Returns a copy of the current list:
template <class T>
LinkedList<T> LinkedList<T>::copy() {
    LinkedList<T> new_list;
    Node<T>* aux = this->head;
    while (aux != nullptr) {
        new_list.append(aux->data);
        aux = aux->next;
    }
    return new_list;
}

// Removes all the elements from the list (Destructor):
template <class T>
void LinkedList<T>::clear() {
    Node<T> *aux = this->head;
    Node<T> *temp = nullptr;
    while (aux != nullptr) {
        temp = aux->next;
        free(aux);
        aux = temp;
    }
    this->head = nullptr;
    this->curr_size = 0;
}

// Prints the list:
template <class T>
void LinkedList<T>::printList() {
    Node<T> *aux = this->head;
    while (aux != nullptr) {
        std::cout << aux->data << " ";
        aux = aux->next;
    }
    std::cout << std::endl;
}

#endif