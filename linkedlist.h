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
        numElem++;

    }


    T& front() {

      if (head != nullptr) {
        return head->data;

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
          newNode->next = NULL;
          tail->next = newNode;
          newNode->previous = tail;
          tail = newNode;

        }
        numElem++;


    }


    T& back() {
      return tail->data;
    }


    int size() {
      return numElem;
    }


    NodeIterator<T> begin() const {
      cout<< "Test begin" <<"\n";
      return NodeIterator<T>(head);
    }


     NodeIterator<T> end() const {
      cout << "Test end" <<"\n";

      return nullptr;
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
