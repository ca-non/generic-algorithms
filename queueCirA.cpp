#include <iostream>

class Queue{
private:
    int SIZE;
    int front;
    int rear;
    int * buffer;

    bool isFull();
    bool isEmpty();
public:
    Queue();
    void enqueue(int data);
    void dequeue();
    void clear();
    void print();
    ~Queue();
};

Queue::Queue()
{
    this->SIZE = 10;
    this->front = -1;
    this->rear = -1;
    this->buffer = new int[SIZE];
}

bool Queue::isFull()
{
    if((this->rear+1)%this->SIZE == this->front) return true;
    return false;
}

bool Queue::isEmpty()
{
    if(this->rear == -1 && this->front == -1) return true;
    return false;
}

void Queue::enqueue(int data)
{
    if(this->isEmpty())
    {
        this->rear = 0;
        this->front = 0;
        this->buffer[rear] = data;
    }
    else if(this->isFull())
    {
        std::cout << "Queue is FULL" << std::endl;
    }
    else
    {
        this->rear = (this->rear+1)%this->SIZE;
        this->buffer[rear] = data;
    }
    
}

void Queue::dequeue()
{
    if(this->isEmpty())
    {
        std::cout << "Queue is EMPTY" << std::endl;
    }
    else if(this->front == this->rear)
    {
        this->front = -1;
        this->rear = -1;
    }
    else
    {
        this->front = (this->front+1) % this->SIZE;
    }
    
}

void Queue::clear()
{
    this->front = -1;
    this->rear = -1;
}

void Queue::print()
{
    int temp = this->front;
    std::cout << "FRONT -> ";

    while(temp <= this->rear)
    {
        std::cout << this->buffer[temp] << " ";
        temp = (temp+1)%this->SIZE;
    }

    std::cout << "REAR " << std::endl;
}

Queue::~Queue()
{
    this->front = -1;
    this->rear = -1;

    delete [] buffer;
}

int main(void)
{
    Queue Q1;

    Q1.enqueue(1);
    Q1.enqueue(12);
    Q1.enqueue(13);
    Q1.enqueue(14);

    Q1.dequeue();

    Q1.print();

    return 0;
}