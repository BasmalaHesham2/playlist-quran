#ifndef DLL_H
#define DLL_H
#include <iostream>
using namespace std;
template<typename T>
// Node structure for Doubly Linked List
struct Node {
public:
    T data;
    Node* next;
    Node* prev;
    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List Class
template<typename T>
class DLL {
private:
    Node<T>* head;
public:
    DLL() : head(nullptr) {}

    // Traverse Forward

    void TraverseForward() {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Traverse Backward
    void TraverseBackward() {
        if (head==NULL) {return;} // Empty list
        Node<T>* current = head;
        while (current->next) { // Go to the last node
            current = current->next;
        }
        while (current) { // Traverse backwards
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    // Search
    bool Search(T value) {
        Node<T>* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Get size
    size_t getSize() {
        size_t counter = 0;
        Node<T>* current = head;
        while (current) {
            counter++;
            current = current->next;
        }
        return counter;
    }

   void inserbegnode(T value){
    Node<T>*newnode=new Node<T>(value);
    newnode->prev=NULL; newnode->next=NULL;
     if(head==nullptr){
     head=newnode;
     }
      else{
     head->prev=newnode;
     newnode->next=head;
     head=newnode;
     }
 }

    // Insert at end
    void insertAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head==nullptr) {
            head = newNode;
        } else {
            Node<T> *temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Insert at given position
    void insertAtGivenPos(T value, int pos) {
        if (pos == 1) {
            inserbegnode(value);
        } else {
            Node<T>* newNode = new Node<T>(value);
            Node<T>* temp = head;
            for (size_t i = 1; i < pos - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }
            if (temp==nullptr) {
                cout << "Out of range" << endl;
                delete newNode;
            } else {
                newNode->next = temp->next;
                if (temp->next!=nullptr) {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
                newNode->prev = temp;
            }
        }
    }

    // Delete at beginning
    void deleteAtBeg() {
        if (head==nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        if (head!=nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }
    // Delete at end
    void deleteAtEnd() {
        if (head==nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next==nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node<T>* temp = head;
            while (temp->next!=nullptr) {
                temp = temp->next;
            }
            temp->prev->next = nullptr;
            delete temp;
        }
    }// Delete at specific position
    void deleteAtSpecificPos(int position) {
        if (position < 1) {
            cout << "Invalid position" << endl;
            return;
        }
        if (head==nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (position == 1) {
            deleteAtBeg();
            return;
        }
        Node<T>* temp = head;
        for (size_t i = 1; i < position && temp; i++) {
            temp = temp->next;
        }
        if (temp==nullptr) {
            cout << "Out of boundary" << endl;
        } else {
            if (temp->next!=nullptr) {
                temp->next->prev = temp->prev;
            }
            if (temp->prev!=nullptr) {
                temp->prev->next = temp->next;
            }
            delete temp;
        }
    }

    // Clear the list
    void clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* temp = current->next;
            delete current;
            current = temp;
        }
        head = nullptr;
    }
       Node<T> *gethead()const
        {
            return head;
    }

    // Destructor
    ~DLL() {
        clear();
    }
};

#endif // DLL_H
