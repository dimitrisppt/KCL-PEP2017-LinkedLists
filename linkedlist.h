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

    void push_front(const T& item) {

        newNode = new Node<T>(item);

        if (head == nullptr) {
          newNode->previous = NULL;
          newNode->next = NULL;
          head = newNode;
          tail = newNode;
          cout << tail <<"\n";
        } else {
          newNode->previous = NULL;
          head->previous = newNode;
          newNode->next = head;
          head = newNode;
          cout << head <<"\n";
        }

    }


    T front() {

      if (head != nullptr) {
        newNode = new Node<T>();
        newNode->previous = head;
        newNode->next = head;
        return newNode;
      }
    }


    void push_back(T item) {

        newNode = new Node<T>(item);

        if (tail == nullptr) {
          newNode->previous = NULL;
          newNode->next = NULL;
          head = newNode;
          tail = newNode;
        } else {
          newNode->previous = NULL;
          tail->previous = newNode;
          newNode->next = tail;
          tail = newNode;

        }


    }


    T back() {
      //TODO complete function
      return &tail;
    }


    int size() {
      return numElem;
    }


    NodeIterator<T> begin() {
      cout<< "Test" <<"\n";
      return NodeIterator<T>(head);
    }


    NodeIterator<T> end() {
      cout << "Test1" <<"\n";
      return NodeIterator<T>(tail);
    }

    // ~LinkedList() {
    //   ListNode* current = head;
    //   while (current !=0) {
    //     ListNode* next = current->next;
    //     delete current;
    //     current = next;
    //   }
    //   head = 0;
    // }


};



// do not edit below this line

#endif
