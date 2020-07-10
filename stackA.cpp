#include <iostream>

class stackA{
private:
    int SIZE;

    int * buffer;

    int top;

public:
    stackA();
    stackA(int size);
    void push(int data);
    void pop();
    void display();
    int getTop();
    void clear();
    ~stackA();
};


stackA::stackA()
{
    this->SIZE = 10;
    this->buffer = new int[SIZE];
    this->top = -1;
}

stackA::stackA(int size)
{
    this->SIZE = size;
    this->buffer = new int[SIZE];
    this->top = -1;
}

void stackA::push(int data)
{
    if(this->top < this->SIZE-1)
    {
        this->top++;
        this->buffer[this->top] = data;
    }
    else
    {
        std::cout << "STACK OVERFLOW!" << std::endl;
    }
    
}

void stackA::pop()
{
    if(this->top != -1)
    {
        this->top--;
    }
    else
    {
        std::cout << "STACK is EMPTY" << std::endl;
    }
    
}

void stackA::display()
{
    if(this->top != -1)
    {
        int temp = this->top;
        
        std::cout << "Top -> ";

        while(temp != -1)
        {
            std::cout << this->buffer[temp] << " ";
            temp--;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "STACK is EMPTY" << std::endl;
    }   
}

 int stackA::getTop()
{
    if(this->top != -1)
    {
        return this->buffer[this->top];
    }
    else
    {
        std::cout << "STACK is EMPTY" << std::endl;
        return -1;
    }   
}

void stackA::clear()
{
    this->top = -1;
}

stackA::~stackA()
{
    this->top = -1;

    delete [] buffer;
}


int main(void)
{
    stackA S1 = stackA(2);

    S1.push(1);
    S1.push(11);
    S1.push(13);

    std::cout << S1.getTop() << std::endl;

    S1.display();


    return 0;
}