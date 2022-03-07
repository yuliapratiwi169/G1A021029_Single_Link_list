// C++ program to single link list
// menggunakan insertion sort
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  struct Node* next;
  Node(int x)
  {
    val = x;
    next = NULL;
  }
};

class LinkedlistIS {

public:
  Node* head;
  Node* sorted;

  void push(int val)
  {
    Node* newnode = new Node(val);
    /* tautkan daftar nama dari simpul baru */
    newnode->next = head;
    /* insert sebagai node awal dari single link list */
    head = newnode;
  }

  // fungsi untuk mengurutkan daftar tertaut menggunakan insertionsort
  // insert node tertentu
  void insertionSort(Node* headref)
  {
    // Inisialisasi daftar tertaut yang diurutkan
    sorted = NULL;
    Node* current = headref;
    // data untuk diurutkan
    while (current != NULL) {
      // Simpanan berikutnya untuk iterasi selanjutnya
      Node* next = current->next;
      sortedInsert(current);
      // Update current
      current = next;
    }
    // perbarui head_ref untuk menunjuk ke daftar tertaut yang diurutkan
    head = sorted;
  }
  void sortedInsert(Node* newnode)
  {
    if (sorted == NULL || sorted->val >= newnode->val) {
      newnode->next = sorted;
      sorted = newnode;
    }
    else {
      Node* current = sorted;
      /* lokasi node sebelum data diurutkan
      */
      while (current->next != NULL
        && current->next->val < newnode->val) {
        current = current->next;
      }
      newnode->next = current->next;
      current->next = newnode;
    }
  }
  /* Fungsi untuk print daftar tertaut */
  void printlist(Node* head)
  {
    while (head != NULL) {
      cout << head->val << " ";
      head = head->next;
    }
  }
};
// menjalankan program fungsi diatas
int main()
{
  LinkedlistIS list;
  list.head = NULL;
  list.push(5);
  list.push(9);
  list.push(13);
  list.push(7);
  list.push(3);
  cout << "Data sebelum diurutkan" << endl;
  list.printlist(list.head);
  cout << endl;
  list.insertionSort(list.head);
  cout << "Data setelah diurutkan" << endl;
  list.printlist(list.head);
}