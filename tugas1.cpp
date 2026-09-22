#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insertFirst(int n)
{
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertLast(int n)
{
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAfter(int n, int check)
{
    if (head == NULL)
    {
        cout << "Linked list kosong, silakan insert di depan.\n";
        return;
    }

    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    Node *p = head;
    while (p != NULL && p->value != check)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "Node dengan nilai " << check << " tidak ditemukan dalam linked list.\n";
        delete newNode;
    }
    else
    {
        newNode->next = p->next;
        p->next = newNode;
        if (p == tail)
        {
            tail = newNode;
        }
    }
}

void deleteFirst()
{
    if (head == NULL)
    {
        cout << "Linked list kosong, tidak ada node untuk dihapus.\n";
        return;
    }

    Node *temp = head;
    head = head->next;
    if (head == NULL)
    {
        tail = NULL;
    }
    delete temp;
}

void deleteMiddle(int value)
{
    if (head == NULL)
    {
        cout << "Linked list kosong, tidak ada node untuk dihapus.\n";
        return;
    }

    if (head->value == value)
    {
        deleteFirst();
        return;
    }

    Node *p = head;
    while (p->next != NULL && p->next->value != value)
    {
        p = p->next;
    }

    if (p->next == NULL)
    {
        cout << "Node dengan nilai " << value << " tidak ditemukan dalam linked list.\n";
        return;
    }
    else
    {
        Node *temp = p->next;
        p->next = temp->next;
        if (temp == tail)
        {
            tail = p;
        }
        delete temp;
    }
}

void printList()
{
    Node *temp = head;
    cout << "Isi linked list : ";
    while (temp != NULL)
    {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    int pilihan, val, check;
    while (true)
    {
        cout << "===== MENU SINGLE LINKED LIST =====\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan linked list\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            cout << "Masukkan nilai: ";
            cin >> val;
            insertFirst(val);
            printList();
            break;
        case 2:
            cout << "Masukkan nilai: ";
            cin >> val;
            insertLast(val);
            printList();
            break;
        case 3:
            cout << "Masukkan nilai baru: ";
            cin >> val;
            cout << "Masukkan nilai yang ingin dicari: ";
            cin >> check;
            insertAfter(val, check);
            printList();
            break;
        case 4:
            cout << "Masukkan nilai yang ingin dihapus: ";
            cin >> val;
            deleteMiddle(val);
            printList();
            break;
        case 5:
            printList();
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}