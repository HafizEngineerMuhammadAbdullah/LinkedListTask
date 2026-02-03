#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next;

  Node(int val) {
    data = val;
    next = NULL;
  }
};

class List {
  Node *head;
  Node *tail;

  // Count the total nodes Recursively
  int countRecursive(Node *node) {
    if (node == NULL)
      return 0;                            // Base Case
    return 1 + countRecursive(node->next); // Recursive Step
  }

public:
  // Constructor for List Class
  List() { head = tail = NULL; }

  // Destructor for List class to free spaces when the object has no scope
  ~List() {
    Node *temp;
    while (head != NULL) {
      temp = head;
      head = head->next;
      delete temp;
    }
  }

  // Qs : 01
  //   Write a function to insert a new node at the beginning.
  // push/add the data(elements) at the front of linked list.
  void push_front(int val) // TC:O(1)
  {
    Node *newNode = new Node(val); // create a dynamic object
    // case 1:
    // if the linked list is empty(NULL)
    if (head == NULL) {
      head = tail = newNode; // head and tail pointer points towards the same
                             // node(first node).
      return;
    } else {
      newNode->next = head;
      head = newNode;
    }
  }

  // push/add the data(elements) at the end of linked list.
  void push_back(int val) // TC:O(1)
  {
    Node *newNode = new Node(val); // create a dynamic object
    if (head == NULL) {
      head = tail = newNode; // head and tail pointer points towards the same
                             // node(first node).
      return;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  // pop(delete/remove) the data(elements) from the front of the Linked list
  void pop_front() // TC:O(1)
  {
    // if my linked list is empty(head => NULL)
    if (head == NULL) {
      cout << "Linked List is empty.Nothing to pop" << endl;
      return;
    }
    // else my linked list is not empty(there is at least one node available in
    // linked list).
    else {
      Node *temp = head;
      head = head->next;
      temp->next = NULL;
      delete temp;
    }
  }

  // Qs : 01
  //   Write a function to delete the last node in the list.
  // pop(delete/remove) the data(elements) from the end of linked list
  void pop_back() // TC:O(n)
  {
    if (head == NULL) {
      cout << "Linked List is empty.Nothing to pop" << endl;
      return;
    }
    // if my linked list has only one node
    if (head->next == NULL) {
      delete head;
      head = tail = NULL;
      return;
    }
    Node *temp = head;
    while (temp->next != tail) {
      temp = temp->next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp;
    // tail = temp;
    // tail->next = NULL;
    // temp = temp->next;
    // delete temp;
  }

  // insert the data(elements) at any position of linked list.
  void insert(int val, int pos) // TC:O(n)
  {
    if (pos < 0) {
      cout << "Invalid Position" << endl;
      return;
    }
    if (pos == 0) {
      push_front(val);
      return;
    }

    Node *temp = head;
    for (int i = 0; i < pos - 1; i++) {
      if (temp == NULL) {
        cout << "Position is greater than the length of linked list" << endl;
        return;
      }
      temp = temp->next;
    }
    Node *newNode = new Node(val);
    if (temp->next == NULL) {
      tail = newNode;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }

  // Qs : 02
  //   Count the total number of nodes in the linked list.
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

  // Qs : 02 using Recursion
  void displayRecursiveCount() {
    cout << "Recursive count: " << countRecursive(head) << endl;
  }

  // Qs : 03
  //   Write a function to search for a value in the linked list
  // search for a key in linked list and return its index.
  void search(int key) // TC:O(n)
  {
    Node *temp = head;
    int idx = 0;
    while (temp != NULL) {
      if (temp->data == key) {
        cout << "Value " << key << " found at index " << idx << endl;
        return;
      }
      temp = temp->next;
      idx++;
    }
    cout << "Value " << key << " not found in the linked list" << endl;
    return;
  }

  // Qs : 02
  // Write a function to reverse the linked list iteratively.

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

  // Reverse helper method
  void reverseLLHelper() {
    tail = head;
    head = reverseLinkedList(head);
    return;
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

  // Qs : 03
  // Write a function to sort the linked list in ascending order.

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
    return head; // return head pointer
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
    //update the tail
    if (head == NULL) {
        tail = NULL;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        tail = temp; // Now the tail is correct for the next pop_back()
    }
    return;
  }


  // print all the elements of linked list.
  void printll() // TC:O(n)
  {
    if (head == NULL) {
      cout << "Singly Linked List is empty.Nothing to print" << endl;
      cout << " [ NULL ] " << endl;
      return;
    }
    Node *temp = head;
    while (temp != NULL) {
      cout << " [ " << temp->data << " ] -> ";
      temp = temp->next;
    }
    cout << " [ NULL ] " << endl;
  }
};

// display program instructions to user
void instructions() {
  cout << "Enter one of the following:\n"
       << " 0 to print the Singly Linked list\n"
       << " 1 to insert at beginning of Singly Linked list\n"
       << " 2 to insert at end of Singly Linked list\n"
       << " 3 to delete from beginning of Singly Linked list\n"
       << " 4 to delete from end of Singly Linked list\n"
       << " 5 to reverse the Singly Linked list\n"
       << " 6 to search a value in Singly Linked list\n"
       << " 7 to count total nodes in Singly Linked list\n"
       << " 8 to insert at a given position in Singly Linked list\n"
       << " 9 to end Singly Linked list processing\n";
  return;
}

void testList() {
  List ll;
  int choice, value, position;
  do {
    instructions();
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      ll.printll();
      break;
    case 1:
      cout << "Enter value to insert at beginning: ";
      cin >> value;
      ll.push_front(value);
      ll.printll();
      break;
    case 2:
      cout << "Enter value to insert at end: ";
      cin >> value;
      ll.push_back(value);
      ll.printll();
      break;
    case 3:
      ll.pop_front();
      ll.printll();
      break;
    case 4:
      ll.pop_back();
      ll.printll();
      break;
    case 5:
      ll.reverseLLHelper();
      ll.printll();
      break;
    case 6:
      cout << "Enter value to search in Doubly Linked List: ";
      cin >> value;
      ll.search(value);
      break;
    case 7:
      ll.countTotalNodes();
      break;
    case 8:
      cout << "Enter position to insert at: ";
      cin >> position;
      cout << "Enter value to insert at position " << position << ": ";
      cin >> value;
      ll.insert(value, position);
      ll.printll();
      break;
    case 9:
      cout << "Exiting Singly Linked List processing." << endl;
      break;
    default:
      cout << "Invalid choice! Please try again." << endl;
    }
  } while (choice != 9);
}
int main() {

  //   List ll;
  //   ll.push_front(10);
  //   ll.push_front(20);
  //   ll.push_front(30);
  //   ll.insert(25, 1);
  //   cout << ll.search(25) << endl;
  //   ll.printll();

  testList();
  return 0;
}