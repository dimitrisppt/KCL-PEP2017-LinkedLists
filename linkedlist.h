#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

// TODO your code goes here:
template<typename T>
class LinkedList {

private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* newNode;
    bool found;
    int numElem;

public:

    LinkedList() {
        head = nullptr;
        tail = nullptr;
        numElem = 0;
    }

    ~LinkedList() {
      Node<T>* tempNode = head;
      while (head != nullptr) {
        tempNode = head->next;
        delete head;
        head = tempNode;
      }
      // delete tempNode;
      // delete tail;
    }

    void push_front(const T & item) {

        //delete newNode;
        newNode = new Node<T>(item);

        if (head == nullptr) {
          newNode->previous = NULL;
          newNode->next = NULL;
          head = newNode;
          tail = newNode;
        } else {
          newNode->previous = NULL;
          head->previous = newNode;
          newNode->next = head;
          head = newNode;
        }
        numElem++;
    }


    T & front() {
        return head->data;
    }


    void push_back(const T & item) {

        //delete newNode;
        newNode = new Node<T>(item);

        if (tail == nullptr) {
          newNode->previous = NULL;
          newNode->next = NULL;
          head = newNode;
          tail = newNode;
        } else {
          newNode->next = NULL;
          tail->next = newNode;
          newNode->previous = tail;
          tail = newNode;
        }
        numElem++;
    }


    T & back() {
      return tail->data;
    }


    int size() const {
      return numElem;
    }


    NodeIterator<T> begin() const {
      return NodeIterator<T>(head);
    }


    NodeIterator<T> end() const {
      return nullptr;
    }

};



// do not edit below this line

#endif
