class MyCircularQueue {
    int size;
    int capacity;
    int front, rear;
    int* buffer;

public:
    MyCircularQueue(int k) : capacity(k), front(0), rear(0), size(0) {
        buffer = new int[capacity];
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        
        buffer[rear] = value;
        size++;
        rear = (rear+1) % capacity;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;

        int y = buffer[front];
        size--;
        front = (front+1)%capacity;
        return true;
    }
    
    int Front() {

        if(isEmpty())
        {
            return -1;
        }
        return buffer[front];
    }
    
    int Rear() {

        if(isEmpty())
        {
           return -1;
        }
         return buffer[(rear-1+capacity)%capacity];
    }
    
    bool isEmpty() {
        if(size == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(size == capacity) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */