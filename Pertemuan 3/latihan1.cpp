#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// TODO : Menambahkan karakter ke stack
void push(char value) {
    if (top == MAX - 1) {
        cout << "Stack Penuh!\n";
    } else {
        top++;
        stack[top] = value;
        cout << value;
    }
}

// TODO : Mengambil karakter paling atas
char pop() {
    if (top == -1) {
        cout << "Stack kosong!\n";
        return '\0';
    } else {
        char item = stack[top];
        top--;
        return item;
    }
    cout << endl;
}

int main() {

    string kata;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    // TODO : Memasukkan setiap karakter ke stack
    for (char c : kata) {
        push(c);
    }

    // TODO Mengeluarkan karakter dari stack
    cout << endl;
    while (top != -1) {
        cout << pop();
    }
    
    cout << endl;

    return 0;
}