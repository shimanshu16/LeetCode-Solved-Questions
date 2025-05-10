class MyCircularQueue {
public:
    int *arr;
    int front,rear,size;

    MyCircularQueue(int k) {
        arr=new int[k];
        front=-1;
        rear=-1;
        size=k-1;
    }
    
    bool enQueue(int value) {
        if (isFull()){return false;}
        else if (front==-1){front=0;rear=0;}
        else if (rear==size && front!=0){rear=0;}
        else {rear++;}
        arr[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if (front==-1){return false;}
        arr[front]=-1;
        if (front==rear){front=-1;rear=-1;}
        else {front=(front+1)%(size+1);}
        return true;
    }
    
    int Front() {
        if (front==-1){return -1;}
        return arr[front];
    }
    
    int Rear() {
        if (rear==-1){return -1;}
        return arr[rear];
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return ((rear+1)%(size+1)==front);
    }
};