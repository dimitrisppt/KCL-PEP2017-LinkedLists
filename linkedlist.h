#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <initializer_list>

using std::initializer_list;


// TODO your code goes here:
template<typename T>
class LinkedList {

private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* newNode;
    int numElem;


public:

    LinkedList() {
        head = nullptr;
        tail = nullptr;
        numElem = 0;
    }



    ~LinkedList() {
      while (head->next != nullptr) {
        Node<T>* tempNode = head;
        head = head->next;
        delete tempNode;
      }
      delete head;
    }

    void push_front(const T & item) {

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


    // ---------------- Advanced Part
    LinkedList(initializer_list<T> list) {

      head = nullptr;
      tail = nullptr;
      numElem = 0;

      for (auto & itemInList: list) {
        push_back(itemInList);
      }

    }



    NodeIterator<T> insert(NodeIterator<T> itr, const T & elem) {
      if (head == nullptr) {
        head = new Node<T>(elem);
    		head->data = elem;
    		head->next = nullptr;
      }else{
    		Node<T>* temp = new Node<T>(elem);
        temp->next = itr.getNodePtr();
        temp->previous = temp->next->previous;
        temp->next->previous = temp;
        temp->previous->next = temp;
        ++numElem;
        return NodeIterator<T>(temp);
    	}
      return NodeIterator<T>(head);
    }

    NodeIterator<T> erase(NodeIterator<T> itr) {

      Node<T>* erasedNode = itr.getNodePtr();
      ++itr;
      if (erasedNode == tail) {
        tail = itr.getNodePtr();
        delete erasedNode;
        return nullptr;
      }
      erasedNode->next->previous = erasedNode->previous;
      erasedNode->previous->next = erasedNode->next;
      --numElem;
      return itr;


    }


};

// do not edit below this line

#endif
