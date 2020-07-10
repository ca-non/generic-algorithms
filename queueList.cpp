#include <iostream>

class Queue{
private:
    struct Node;
    
    typedef Node * NodePtr;
    
    struct Node{
        int data;
        NodePtr next;
    };

    NodePtr front;
    NodePtr rear;

    bool isEmpty();

public:
    Queue();
    void enqueue(int data);
    void dequeue();
    void display();
    int getFront();
    ~Queue();

};

bool Queue::isEmpty()
{
    if(front == nullptr && rear == nullptr) return true;
    return false;
}

Queue::Queue()
{
    front = rear = nullptr;
}

void Queue::enqueue(int data)
{
    // Make a new Node
    NodePtr  newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if(isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    
}

void Queue::dequeue()
{
    if(isEmpty())
    {
        std::cout << "Empty Queue" << std::endl;
    }
    else if(front == rear)
    {
        delete front;
        front  = nullptr;
        rear = nullptr;
    }
    else
    {
        NodePtr temp = front;
        front = temp->next;
        delete temp;
        temp = nullptr;
    }
    
}

void Queue::display()
{
    if(isEmpty())
    {
        std::cout << "Empty Queue" << std::endl;
    }
    else
    {
        std::cout << "FRONT -> ";

        NodePtr temp = front;

        while(temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }

        temp = nullptr;

        std::cout << "REAR" << std::endl;
    }

}

int Queue::getFront()
{
    if(isEmpty())
    {
        std::cout << "Empty Queue" << std::endl;
        return -1;
    }
    else
    {
        return front->data;
    }
}

Queue::~Queue()
{
    if(isEmpty())
    {
        std::cout << "Empty Queue" << std::endl;
    }
    else
    {
        NodePtr temp = nullptr;

        while(front != nullptr)
        {
            temp = front;
            front = front->next;
            delete temp;
        }
        front = nullptr;
        rear = nullptr;
        temp = nullptr;
    }
}


int main(void){
    Queue Q1;

    Q1.enqueue(1);
    Q1.enqueue(12);
    Q1.enqueue(21);
    Q1.enqueue(31);
    Q1.enqueue(41);

    std::cout << Q1.getFront() << std::endl;

    Q1.dequeue();

    Q1.display();

    return 0;
}