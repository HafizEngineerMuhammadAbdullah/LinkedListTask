#include <iostream>
using namespace std;

// function prototype
void instructions(); // display program instructions to user
// function prototype
void testList(); // function to test the Doubly Linked List class
// create a class Node for Doubly Linked List
struct Node {
public:
  int data;
  Node *next;
  Node *prev;

  // create a parameterized constructor for Node class
  Node(int data) {
    this->data = data;
    this->next = this->prev = NULL;
  }
};

// create a doubly Linked List class
class DoublyLinkedList {

private:
  Node *head;

  // Qs : 02
  // Implement a function to reverse a doubly linked list.
  Node *reverseDll(Node *head) {
    // take three pointers for reversing a Linked List
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    // loop (walk) through Doubly Linked List
    while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      curr->prev = next;

      // update the pointers for the next iterations
      prev = curr;
      curr = next;
    }

    // return newHead of the Linked List
    return prev;
  }

  // Qs : 03
  // Implement a function to merge two DLLs.
  void mergeTwoDll(DoublyLinkedList &dll2) {
    // if first Doubly Linked List is empty
    if (isEmpty()) {
      head = dll2.head;
      return;
    }

    // if second Doubly Linked List is empty
    if (dll2.head == NULL) {
      return;
    }

    // else both the Doubly Linked Lists are not empty
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next; // update temp for next iteration
    }
    temp->next = dll2.head;
    dll2.head->prev = temp;
  }

public:
  // create a parameterized constructor for Doubly Linked List class
  DoublyLinkedList() { head = NULL; }

  ~DoublyLinkedList() {
    while (head != NULL) {
      pop_front();
    }
  }

  // method to push(add/insert) the new node at the beginning(start/front) of
  // the Doubly Linked List
  void push_front(int val) { // TC:O(1)

    Node *newNode = new Node(val); // create a newNode
    // if head has a value NULL means there is no single node available in our
    // Linked List means   our Doubly Linked List is empty!
    if (isEmpty()) {
      head = newNode;
      return;
    }

    // else if head doesn't have a value means there is at least one(single
    // node) available in our Doubly Linked List
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }

  void push_back(int val) { // TC:O(n)

    Node *newNode = new Node(val); // create a newNode
    // if head has a value NULL means there is no single node available in our
    // Doubly Linked List means  our Doubly Linked List is empty!
    if (isEmpty()) {
      head = newNode;
      return;
    }

    // else if head doesn't have a NULL value means there is at least one(single
    // node) available in our Doubly Linked List
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next; // update temp for next iteration
    }
    temp->next = newNode;
    newNode->prev = temp;
  }

  // method that pop(delete/remove/eliminate) the node from the
  // front(beginning/start) of the Doubly Linked List
  void pop_front() { // TC:O(1)
    // if head has a value NULL means there is no single node available in our
    // Doubly Linked List means  our Doubly Linked List is empty!
    if (isEmpty()) {
      cout << "Doubly Linked List is empty.Nothing to pop from front!" << endl;
      return;
    }

    // else if head doesn't have a NULL value means there is at least one(single
    // node) available(present) in our Doubly Linked List
    Node *temp = head;
    head = head->next;
    delete temp;
    if (head != NULL) {
      head->prev = NULL;
    }
  }

  void pop_back() { // TC:O(n)
    // if head has a value NULL means there is no single node available in our
    // Linked List means  our LinkedList is empty!
    if (isEmpty()) {
      cout << "LinkedList is empty.Nothing to pop from back!" << endl;
      return;
    }

    // else if head doesn't have a NULL value means there is at least one(single
    // node) available(present) in our Linked List
    Node *temp = head;
    if (temp->next !=
        NULL) { // caseI: When there are  two or more than two nodes
      while (temp->next->next != NULL) {
        temp = temp->next; // update the temp pointer
      }

      Node *delNode = temp->next;
      delete delNode;
      temp->next = NULL;
    } else { // caseII:when only single(one) node is present
      delete temp;
      head = NULL;
    }
  }

  // method to print the Doubly linked list
  void printDLL() { // TC:O(n)
    // if our Doubly linked list is empty means our head is pointing to the NULL
    // value
    if (isEmpty()) {
      cout << "Doubly Linked List is empty.Nothing to print!" << endl;
      return;
    }
    // else if our Doubly linked list is not empty
    Node *temp = head;
    cout << "Doubly Linked List: " << endl;
    cout << "NULL <-> ";
    while (temp != NULL) {
      cout << temp->data << " <-> ";
      temp = temp->next; // update temp for next iteration
    }
    cout << "NULL" << endl;
  }

  // Backward Traversal Algorithm:
  void printDllBackward() {
    // if our Doubly Linked List is empty means there is no node exist in our
    // Doubly  Linked List (Doubly Linked List is empty)
    if (isEmpty()) {
      cout << "Doubly Linked List is empty.Nothing to  Print!" << endl;
      return;
    }

    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    Node *tempTail = temp;
    // print the Doubly Linked List backward
    cout << "Doubly Linked List printed backward: " << endl;
    cout << "NULL "
         << "<=> ";
    while (tempTail != NULL) {
      cout << tempTail->data << " <=> ";
      tempTail = tempTail->prev;
    }
    cout << "NULL" << endl;
  }

  void reverseDll() {
    // if our DLL is empty
    if (isEmpty()) {
      cout << "Doubly Linked List is empty.Nothing to reverse!" << endl;
      return;
    }

    // call the reverse Dll method
    head = reverseDll(head);
  }

  // Qs : 02
  // Add a search function to find a given value.
  void searchInDll(int val) { // TC:O(n)
    // if our Doubly linked list is empty means our head is pointing to the NULL
    // value
    if (isEmpty()) {
      cout << "Doubly Linked List is empty.Nothing to Search!" << endl;
      return;
    }

    // else if our Doubly linked list is not empty
    Node *temp = head;
    int count = 0;
    while (temp->next != NULL) { // TC:O(n)
      count++;
      temp = temp->next;
    }
    count++;
    while (temp != NULL) { // TC:O(n)
      if (temp->data == val) {
        cout << "Item " << temp->data << " is found at index " << --count
             << endl;
        return;
      }
      count--;
      temp = temp->prev; // update temp for next iteration
    }
  }

  // Qs : 03
  // Write a function to count the total number of nodes in the DLL.
  void countTotalNodes() {
    // if our Doubly linked list is empty means our head is pointing to the NULL
    // value
    if (isEmpty()) {
      cout << "Doubly Linked List is empty.Nothing to Count!,thus the total "
              "number of nodes are 0"
           << endl;
      return;
    }

    // else if our Doubly linked list is not empty
    Node *temp = head;
    int count = 0;
    // caseI:when there is more than one node present in the DLL
    while (temp != NULL) { // TC:O(n)
      count++;
      temp = temp->next; // update temp for next iteration
    }
    cout << "Total number of nodes present in the Doubly Linked List is: "
         << count << " nodes" << endl;
  }

  // Qs : 04
  // Modify insertAtPosition() to handle inserting at the last position without
  // using insertAtEnd().
  void insertAtPosition(int pos, int val) {
    Node *newNode = new Node(val); // created a new Node
    int count{0};

    //insert at head
    if (pos == 0) {
      push_front(val);
      return;
    }

    // caseII: when more than one node is present in the DLL
    Node *temp = head;
    while (count < pos - 1 && temp != NULL) {
      temp = temp->next;
      count++;
    }

    if (temp == NULL) {
      cout << "Can't be inserted at position " << pos << endl;
      delete newNode;
      return;
    }

    if (temp->next == NULL) {
      temp->next = newNode;
      newNode->prev = temp;
      newNode->next = NULL;
      return;
    }
    Node *oldNext = temp->next;
    temp->next = newNode;
    oldNext->prev = newNode;

    newNode->next = oldNext;
    newNode->prev = temp;
  }

  // Qs : 01
  // Modify deleteAtPosition() to handle deletion from the last position without
  // calling deleteAtEnd().
  void deleteAtPosition(int pos) {
    int count{0};
    // if our Doubly linked list is empty means our head is pointing to the NULL
    // value
    if (isEmpty()) {
      cout << "Doubly Linked List is empty.Nothing to delete(pop)!" << endl;
      return;
    }

    if (pos == 0) {
      pop_front();
      return;
    }
    Node *temp = head;
    Node *oldNode;
    //
    while (count < pos - 1 && temp != NULL) {
      temp = temp->next;
      count++;
    }

    // if the temp is pointing towards the NULL value
    if (temp == NULL) {
      cout << "Can't be popped at this position " << pos << endl;
      return;
    }
    if (temp->next != NULL) {
      if (temp->next->next == NULL) {
        oldNode = temp->next;
        temp->next = NULL;
        oldNode->prev = NULL;
        delete oldNode;
      } else {
        oldNode = temp->next;
        Node *node = oldNode->next;
        temp->next = node;
        node->prev = temp;
        delete oldNode;
      }
    } else {
      cout << "Can't be popped at this position " << pos << endl;
      return;
    }
  }

  bool isEmpty() { return head == NULL; }

  void mergeTwoDll() {
    // create another Doubly Linked List object
    DoublyLinkedList dll2;
    dll2.push_back(30);
    dll2.push_back(40);
    dll2.push_back(50);

    // merge the two Doubly Linked Lists
    mergeTwoDll(dll2);
  }
};
int main() {

  cout << "\n \t \t \t \t \t \t \t Doubly Linked List Implementation in C++"
       << endl;
  cout << "\n \t \t \t \t \t \t \t--------------------------------------------"
       << endl;
  // dll.push_back(10);
  // dll.push_back(20);
  // dll.push_front(5);

  // dll.printDLL();

  // dll.countTotalNodes();

  // dll.searchInDll(10);

  // dll.printDllBackward();

  // dll.reverseDll();
  // cout << "After reversing the Doubly Linked List: " << endl;
  // dll.printDLL();

  // dll.reverseDll();
  // cout << "After reversing again the Doubly Linked List: " << endl;
  // dll.printDLL();
  // dll.mergeTwoDll();
  // cout << "After merging two Doubly Linked Lists: " << endl;
  // dll.printDLL();

  // dll.insertAtPosition(6, 555);
  // dll.insertAtPosition(7, 111);
  // dll.insertAtPosition(8, 123);
  // // dll.insertAtPosition(10,234);
  // dll.printDLL();
  // dll.deleteAtPosition(0);
  // dll.deleteAtPosition(5);
  // dll.deleteAtPosition(6);
  // dll.deleteAtPosition(1);
  // dll.printDLL();

  // Create a menu-driven program to test all operations dynamically.
  testList();
  return 0;
}

// display program instructions to user
void instructions() {
  cout << "Enter one of the following:\n"
       << " 0 to print the Doubly Linked list\n"
       << " 1 to insert at beginning of Doubly Linked list\n"
       << " 2 to insert at end of Doubly Linked list\n"
       << " 3 to delete from beginning of Doubly Linked list\n"
       << " 4 to delete from end of Doubly Linked list\n"
       << " 5 to merge two Doubly Linked lists\n"
       << " 6 to reverse the Doubly Linked list\n"
       << " 7 to search a value in Doubly Linked list\n"
       << " 8 to count total nodes in Doubly Linked list\n"
       << " 9 to insert at a given position in Doubly Linked list\n"
       << "10 to delete at a given position in Doubly Linked list\n"
       << " 11 to end Doubly Linked list processing\n";
  return;
}

void testList() {
  DoublyLinkedList dll;
  int choice, value, position;
  do {
    instructions();
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      dll.printDLL();
      break;
    case 1:
      cout << "Enter value to insert at beginning: ";
      cin >> value;
      dll.push_front(value);
      dll.printDLL();
      break;
    case 2:
      cout << "Enter value to insert at end: ";
      cin >> value;
      dll.push_back(value);
      dll.printDLL();
      break;
    case 3:
      dll.pop_front();
      dll.printDLL();
      break;
    case 4:
      dll.pop_back();
      dll.printDLL();
      break;
    case 5:
      dll.mergeTwoDll();
      dll.printDLL();
      break;
    case 6:
      dll.reverseDll();
      dll.printDLL();
      break;
    case 7:
      cout << "Enter value to search in Doubly Linked List: ";
      cin >> value;
      dll.searchInDll(value);
      break;
    case 8:
      dll.countTotalNodes();
      break;
    case 9:
      cout << "Enter position to insert at: ";
      cin >> position;
      cout << "Enter value to insert at position " << position << ": ";
      cin >> value;
      dll.insertAtPosition(position, value);
      dll.printDLL();
      break;
    case 10:
      cout << "Enter position to delete at: ";
      cin >> position;
      dll.deleteAtPosition(position);
      dll.printDLL();
      break;
    case 11:
      cout << "Exiting Doubly Linked List processing." << endl;
      break;
    default:
      cout << "Invalid choice! Please try again." << endl;
      break;
    }
  } while (choice != 11);
}