#include <iostream>
using namespace std;

const int SIZE = 10;

class HashTable {
    int table[SIZE];
    int hashFunc(int key) { return key % SIZE; }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) table[i] = -1;
    }

    void insert(int key) {
        int index = hashFunc(key);
        while (table[index] != -1)
            index = (index + 1) % SIZE;
        table[index] = key;
    }

    void display() {
        for (int i = 0; i < SIZE; i++)
            if (table[i] != -1) cout << table[i] << " ";
    }
};

int main() {
    HashTable h;
    int n, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> key;
        h.insert(key);
    }
    h.display();
    return 0;
}

