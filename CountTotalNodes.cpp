#include <iostream>
using namespace std;

// Qs : 02
// Count the total number of nodes in the linked list.

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

  int countRecursive(Node *node) {
    if (node == NULL)
      return 0;                            // Base Case
    return 1 + countRecursive(node->next); // Recursive Step
  }

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
      cout << "[ " << temp->data <<  " ]" << "->";
      temp = temp->next; // update temp for next iteration
    }
    cout << "[ NULL ]" << endl;
  }

  void displayRecursiveCount() {
    cout << "Recursive count: " << countRecursive(head) << endl;
  }

  // count total number of nodes present in the LinkedList
  void countTotalNodes() {
    // if the head has a 'NULL' means there is no node available in our Linked
    // list i.e. our LinkedList is empty
    if (head == NULL) {
      cout << "LinkedList is empty.Nothing to count!,thus the total number "
              "of nodes are 0"
           << endl;
      return;
    }
    int count = 0;

    Node *temp = head;
    while (temp != NULL) {
      ++count;
      temp = temp->next; // update temp for next iteration
    }
    cout << "Total number of nodes present in the Linked List is " << count
         << " nodes" << endl;
  }
};
int main() {
  cout << "\n \t \t \t \t \t Program to Count the total number of nodes in "
          "the linked list. "
       << endl;
  cout << "\n \t \t \t \t "
          "\t==============================================================="
       << endl;
  // create a LinkedList object
  LinkedList ll;

  ll.push_front(1);
  ll.push_front(2);
  ll.push_front(3);

  ll.printLL();

  ll.countTotalNodes();
}