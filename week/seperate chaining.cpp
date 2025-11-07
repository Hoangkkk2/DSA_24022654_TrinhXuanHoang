#include <iostream>
#include <list>
using namespace std;

const int SIZE = 10;

class hashtable {
    list<int> table[SIZE];
    int hashFunc(int key) { return key % SIZE; }

public:
    void insert(int key) {
        int index = hashFunc(key);
        table[index].push_back(key);
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            for (list<int>::iterator it = table[i].begin(); it != table[i].end(); ++it)
                cout << *it << " ";
        }
    }
};

int main() {
    hashtable h;
    int n, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> key;
        h.insert(key);
    }
    h.display();
    return 0;
}

