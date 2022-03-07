// SLL C++ program to sequential search
// sebuah elemen didalam daftar tertaut
#include <bits/stdc++.h>
using namespace std;

/* daftar node tertaut */
class Node
{
    public:
    int key;
    Node* next;
};

/* Diberi referensi (pointer to pointer) ke kepala
dari daftar dan int, mendorong node baru di depan
dari daftar. */
void push(Node** head_ref, int new_key)
{
    /* alokasikan node */
    Node* new_node = new Node();

    /* masukkan kuncinya */
    new_node->key = new_key;

    /* tautkan daftar lama dari node baru */
    new_node->next = (*head_ref);

    /* gerakkan head_ref untuk menunjuk ke simpul/node baru */
    (*head_ref) = new_node;
}

/* Memeriksa apakah nilai x ada dalam daftar yang ada */
bool search(Node* head, int x)
{
    Node* current = head; // Inisialisasi simpanan
    while (current != NULL)
    {
        if (current->key == x)
            return true;
        current = current->next;
    }
    return false;
}

/* menjalankan program untuk menguji fungsi hitungan*/
int main()
{
    /* Mulailah dengan daftar kosong */
    Node* head = NULL;
    int x = 14;

    /* gunakan Push() untuk membuat daftar di bawah ini
    14->21->11->30->10 */
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);

    search(head, 21)? cout<<"Yes" : cout<<"No";
    return 0;
}