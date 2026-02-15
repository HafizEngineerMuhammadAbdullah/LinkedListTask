#include <iostream>
using namespace std;

// Qs: 03.
// Write a function to sort the linked list in ascending order.

// create a Node class
struct Node {
public:
  int data;
  Node *next;

  // declare a parameterized constructor for Node Class
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

// create a LinkedList class
class LinkedList {
  Node *head;
  Node *tail;

  // sort the Linked List in Ascending order using Merge Sort
  // helper function that takes head and tail of the linked list as input
  // Time Complexity: O(n log n)
  // Space Complexity: O(log n) due to recursive stack space or O(n) if
  // we consider the new linked list creation during merging.
  // Auxiliary Space: O(1)
  // returns the head of the sorted linked list
  Node *sortLinkedListUsingMergeSort(Node *head, Node *tail) {
    // Implement sorting logic here
    // find the mid index
    int mid = countCurrentLengthOfLL(head, tail) / 2;
    // Base case: return the single node
    if (head == tail) {
      return head;
    }
    // Recursive case
    if (head != tail) {
      Node *midNode = head;
      int count{1};
      // find the mid Node
      // traverse till mid index
      while (count < mid && midNode != NULL) {
        midNode = midNode->next;
        count++;
      }
      // prepare for next recursive calls
      Node *nextHead = midNode->next;
      // set the next of midNode to NULL to break the list into two halves
      midNode->next = NULL;
      // sort for left half
      // recursive calls for left and right halves
      Node *leftSorted = sortLinkedListUsingMergeSort(head, midNode);
      // sort for right half
      Node *rightSorted = sortLinkedListUsingMergeSort(nextHead, tail);

      // Merge the newly sorted versions
      return mergeTwoSortedLists(leftSorted,
                                 rightSorted); // merge the two sorted halves
    }
  }

public:
  LinkedList() {
    head = NULL;
    tail = NULL;
  }

  // insert(push/add) the new node at the beginning of the LinkedList
  void push_front(int val) {

    Node *newNode = new Node(val); // create a new node
    // if the head has a 'NULL' means there is no node available in our Linked
    // list i.e. our LinkedList is empty
    if (head == NULL) {
      head = tail = newNode;
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
    if (head == NULL || tail == NULL) {
      cout << "LinkedList is empty.Nothing to pop from back!" << endl;
      return;
    }
    if (head == tail) {
      delete head;
      head = tail = NULL;
      return;
    }

    Node *temp = head;
    while (temp->next != tail) {
      temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = NULL;
  }

  // method that count the current length of the Linked List
  int countCurrentLengthOfLL(Node *head, Node *tail) {
    // if the head has a 'NULL' means there is no node available in our Linked
    // list i.e. our LinkedList is empty
    if (head == NULL) {
      return 0;
    }

    // else if the head doesn't have a NULL value means our Linked List has at
    // least one node present i.e. our LinkedList is not empty.
    Node *temp = head;
    int count = 1;
    while (temp != tail) {
      temp = temp->next;
      count++;
    }
    return count; // return the count
  }

  // method that merge two Sorted Linked Lists and return the head of the new
  // Sorted Linked Lists Time Complexity: O(m + n)
  Node *mergeTwoSortedLists(Node *h1, Node *h2) {
    // if any one of the linked list is empty then return the other linked list
    // head
    if (h1 == NULL || h2 == NULL) {
      return h1 == NULL ? h2 : h1;
    }

    // compare the data of both linked list's head nodes and recursively call
    // for the next nodes
    if (h1->data <= h2->data) {
      h1->next = mergeTwoSortedLists(h1->next, h2);
      return h1;
    } else {
      h2->next = mergeTwoSortedLists(h1, h2->next);
      return h2;
    }
  }

  // method that sort the Linked List in Ascending order using Merge Sort
  void sortLinkedListUsingMergeSort() {
    // call the helper function to sort the linked list and update the head
    // pointer
    head = sortLinkedListUsingMergeSort(head, tail);
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
      cout << temp->data << "->";
      temp = temp->next; // update temp for next iteration
    }
    cout << "NULL" << endl;
  }
};
int main() {

  cout << "\n \t \t \t \t \t \t Optimized Version of Sort a Linked List in Ascending "
          "Order using Merge Sort Algorithm"
       << endl;
  cout << "\n \t \t \t \t \t "
          "\t------------------------------------------------------------------"
          "------------"
       << endl;
  // create a LinkedList object
  LinkedList ll;

  ll.push_front(1);
  ll.push_front(2);
  ll.push_front(3);
  ll.push_front(4);
  ll.push_front(5);
  ll.push_front(6);
  ll.push_front(7);
  ll.push_front(8);
  ll.push_front(9);
  ll.push_front(10);
  ll.printLL();

  ll.sortLinkedListUsingMergeSort();
  ll.printLL();
}