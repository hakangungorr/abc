#include <iostream>
using namespace std;

class CustomerQueue {
public: // Customer yapısını public yapıyoruz
    struct Customer {
        int id;
        int processingTime;
    };

private:
    Customer* queue;
    int front;
    int rear;
    int size;
    int capacity;

public:
    CustomerQueue(int capacity) {
        this->capacity = capacity;
        queue = new Customer[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~CustomerQueue() {
        delete[] queue;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int id, int processingTime) {
        if (isFull()) {
            cout << "Kuyruk dolu! Yeni müşteri eklenemiyor.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = {id, processingTime};
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Kuyruk boş! Çıkartılacak müşteri yok.\n";
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    Customer peek() {
        if (isEmpty()) {
            cout << "Kuyruk boş!\n";
            return {-1, -1};
        }
        return queue[front];
    }

    int getSize() {
        return size;
    }
};

int main() {
    int capacity, customerCount;

    cout << "Kuyruk boyutunu giriniz: ";
    cin >> capacity;
    CustomerQueue queue(capacity);

    cout << "Müşteri sayısını giriniz: ";
    cin >> customerCount;

    for (int i = 0; i < customerCount; i++) {
        int id, processingTime;
        cout << "Müşteri ID ve işlem süresi (dakika) giriniz: ";
        cin >> id >> processingTime;
        queue.enqueue(id, processingTime);
    }

    cout << "İşlem sırasındaki  müşteriler:\n";
    while (!queue.isEmpty()) {
        CustomerQueue::Customer current = queue.peek();
        cout << "Müşteri ID: " << current.id << " işlem süresi: " << current.processingTime << " dakika\n";
        cout << "Müşteri ID: " << current.id << " işlem tamamlandı. Süre: " << current.processingTime << " dakika.\n";
        queue.dequeue();
    }

    return 0;
}
