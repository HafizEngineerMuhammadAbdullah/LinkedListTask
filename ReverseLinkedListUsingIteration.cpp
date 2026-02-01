#include <iostream>
using namespace std;

// Qs : 02
// Write a function to reverse the linked list iteratively.

// create a Node class
struct Node {
public:
  int data;
  Node *next;

  // declare a parameterized constructor for Node Class
  Node(int data) {
    this->data = data;
    next = NULL;
  }
};

// create a LinkedList class
class LinkedList {

  Node *head;

public:
  LinkedList() { head = NULL; }

  
   ~LinkedList() {
    Node *temp;
    while (head != NULL) {
      temp = head;
      head = head->next;
      delete temp;
    }
  }

  // insert(push/add) the new node at the beginning of the LinkedList
  void push_front(int val) {

    Node *newNode = new Node(val); // create a new node
    // if the head has a 'NULL' means there is no node available in our Linked
    // list i.e. our LinkedList is empty
    if (head == NULL) {
      head = newNode;
      return;
    }

    // else if the head doesn't have a NULL value means our Linked List has at
    // least one node present i.e. our LinkedList is not empty.
    newNode->next = head;
    head = newNode;
  }

  // pop(delete/eliminate/remove) the node from the end(last) of the LinkedList
  void pop_back() {
    // if the head has a 'NULL' means there is no node available in our Linked
    // list i.e. our LinkedList is empty
    if (head == NULL) {
      cout << "LinkedList is empty.Nothing to pop!" << endl;
      return;
    }

    Node *temp = head;
    if (temp->next != NULL) {
      while (temp->next->next != NULL) {
        temp = temp->next;
      }
      Node *delNode = temp->next;
      temp->next = NULL;
      delete delNode;
    } else { // case of single node(when only one(single) node is present)
      delete temp;
      head = NULL;
    }
  }

  //   Reverse a LinkedList
  // Time Complexity: O(n)
  // Space Complexity: O(1)
  Node *reverseLinkedList(Node *head) {
    // if the head has a 'NULL' means there is no node available in our Linked
    // list i.e. our LinkedList is empty
    if (head == NULL) {
      cout << "LinkedList is empty.can't be reversed!" << endl;
      return NULL;
    }

    // using three pointer Approach
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  void reverseLLHelper() {
    head = reverseLinkedList(head);
    return;
  }

  // traverse the whole linked list and display all of it's elements
  void printLL() {
    // if the head has a 'NULL' means there is no node available in our Linked
    // list i.e. our LinkedList is empty
    if (head == NULL) {
      cout << "LinkedList is empty.Nothing to print!" << endl;
      return;
    }

    Node *temp = head;
    while (temp != NULL) {
      cout << "[ " << temp->data << " ]"
           << "->";
      temp = temp->next; // update temp for next iteration
    }
    cout << "[ NULL ]" << endl;
  }
};
int main() {

  cout << "\n \t \t \t \t \t Program to Write a function that reverse the "
          "linked list iteratively."
       << endl;
  cout << "\n \t \t \t \t "
          "\t=================================================================="
          "====="
       << endl;
  // create a LinkedList object
  LinkedList ll;

  ll.push_front(1);
  ll.push_front(2);
  ll.push_front(3);

  cout << "LinkedList before popping" << endl;
  ll.printLL();

  ll.pop_back();

  cout << "LinkedList after popping" << endl;
  ll.printLL();
  ll.pop_back();
  cout << "LinkedList after popping" << endl;
  ll.printLL();
  ll.pop_back();
  cout << "LinkedList after popping" << endl;
  ll.printLL();
  ll.reverseLLHelper();
  ll.printLL();
}