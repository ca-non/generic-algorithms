#include <iostream>

class StackL{
private:
    struct Node;

    typedef Node * NodePtr;
    
    struct Node
    {
        int data;
        NodePtr next;
    };

    NodePtr top;

    int size;

public:
    StackL();
    void push(int value);
    int pop();
    int getSize();
    void display();
    void clear();
    ~StackL();
};

StackL::StackL()
{
    this->top = nullptr;
    this->size = 0;
}

void StackL::push(int value)
{
    NodePtr newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if(!this->top)
    {
        this->top = newNode;
        this->size++;
    }
    else
    {
        newNode->next = this->top;
        this->top = newNode;
        this->size++;
    }
    
    newNode = nullptr;
}

int StackL::pop()
{
    if(!this->top)
    {
        std::cout<< "Empty Stack" << std::endl;
    }
    else
    {
        NodePtr temp = nullptr;
        int data = 0;
        temp = this->top;
        this->top = this->top->next;
        data =  temp->data;
        delete temp;
        this->size--;
        return data;
    }
    
}

int StackL::getSize()
{
    return this->size;
}

void StackL::display()
{
    NodePtr temp = this->top;

    std::cout<< "Top-> ";
    while(temp != nullptr)
    {
        std::cout << temp->data << "\t";
        temp = temp->next;
    }
    std::cout << std::endl;
    temp = nullptr;
}

void StackL::clear()
{
    NodePtr temp = this->top;
    NodePtr next = nullptr;
    this->top = nullptr;

    while(temp != nullptr)
    {
        next = temp->next;
        delete temp;
        temp = next;
    }   

    this->size = 0;
}

StackL::~StackL()
{
    NodePtr temp = this->top;
    NodePtr next = nullptr;
    this->top = nullptr;

    while(temp != nullptr)
    {
        next = temp->next;
        delete temp;
        temp = next;
    }

    this->size = 0;
   
}

// Driver
int main(void)
{
    StackL S1;
    int data = 0;

    S1.push(1);
    S1.push(13);
    S1.push(14);
    S1.push(21);

    S1.display();
    std::cout << S1.getSize() << std::endl;

    data = S1.pop();
    S1.display();
    data = S1.pop();
    S1.display();

    S1.clear();
    std::cout << S1.getSize() << std::endl;

    return 0;
}