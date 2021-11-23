class Queue {
    int *arr;
    int curr_size;
    int max_size;
    int front;
    int rear;

   public:
    Queue(int default_size = 5) {
        max_size = default_size;
        arr = new int[max_size];
        curr_size = 0;
        front = 0;
        rear = max_size - 1;
    }

    bool full() { return curr_size == max_size; }

    bool empty() { return curr_size == 0; }

    void push(int data) {
        if (!full()) {
            rear = (rear + 1) % max_size;
            arr[rear] = data;
            curr_size++;
        }
    }

    void pop() {
        if (!empty()) {
            front = (front + 1) % max_size;
            curr_size--;
        }
    }

    int getFront() { return arr[front]; }
};