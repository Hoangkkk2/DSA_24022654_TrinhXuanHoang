#include <iostream>
using namespace std; 
const int MAX = 1000;
template<typename T>
class Queue
{
private:
    T base[MAX];
    int front_idx = 0;
    int rear_idx = 0;
    int count = 0;

public:
    void Enqueue(T x)
    {
        if (count < MAX) {
            base[rear_idx] = x;
            rear_idx = (rear_idx + 1) % MAX;
            count++;
        }
    }

    void Dequeue()
    {
        if (count > 0) {
            front_idx = (front_idx + 1) % MAX;
            count--;
        }
    }

    T front() const
    {
        if (count > 0) {
            return base[front_idx];
        }
        return T(); 
    }
    
    bool isEmpty() const
    {
        return count == 0;
    }
    
    void display() const {
        if (isEmpty()) return;
        int current_idx = front_idx;
        for (int i = 0; i < count; ++i) {
            cout << base[current_idx] << " ";
            current_idx = (current_idx + 1) % MAX;
        }
    }
};

int main()
{
    Queue<int> q;
    int value;
    cout << "Nhap so nguyen (Nhap 0 de ket thuc Enqueue):\n";
    while (true) {
        cout << "Nhap so: ";
        if (!(cin >> value)) {
            cout << "Loi nhap lieu. Dung lai.\n";
            break;
        }
        if (value == 0) {
            break;
        }
        q.Enqueue(value);
        cout << "   [Hang hien tai: ";
        q.display();
        cout << "]\n";
    }
    cout << "\n--- KET QUA XU LY (DEQUEUE) ---\n";
    while (!q.isEmpty()) {
        cout << "Phan tu dau: " << q.front() << endl;
        q.Dequeue();
    }
    
    cout << "End";
    return 0;
}
