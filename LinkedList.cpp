#include <iostream>

class LinkedList{
private:
    struct Node;

    typedef Node * NodePtr;
    
    struct Node
    {
        int data;
        NodePtr next;
    };

    NodePtr head;

    int length;
    
public:
    LinkedList();
    void insert(int value);
    void display() const;
    int getLength();
    void reset();
    bool search(int value);
    void deleteVal(int value);
    void reverse();    
    ~LinkedList();
};

LinkedList::LinkedList()
{
    this->head = nullptr;
    this->length = 0;
}

void LinkedList::insert(int value)
{
    // create a new node
    NodePtr newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    NodePtr temp = nullptr;

    if(!this->head)
    {
        this->head = newNode;
        this->length++;
    }
    else
    {
        temp = this->head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        
        temp->next = newNode;
        this->length++;

    }

    newNode = nullptr;

    return;    
}

void LinkedList::display() const
{
    if(!this->head)
    {
        std::cout << "Empty List" << std::endl;
    }
    else
    {
        NodePtr temp = this->head;

        std::cout << "-> ";
        while(temp)
        {
            std::cout << temp->data << "\t";
            temp = temp->next;
        }
        std::cout << std::endl;

        temp = nullptr;
    }
    
}

int LinkedList::getLength()
{
    return this->length;
}

void LinkedList::reset()
{
    NodePtr temp = nullptr, next = nullptr;

    if(this->head)
    {
        temp = this->head;
        this->head = nullptr;

        while(temp)
        {
            next = temp->next;
            delete temp;
            length--;
            temp = next;
            next = nullptr;
        }
    }  
}

bool LinkedList::search(int value)
{
    NodePtr temp = this->head;

    while(temp)
    {
        if(temp->data == value)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;

}

void LinkedList::deleteVal(int value)
{
    if(search(value))
    {
        NodePtr temp = this->head;
        NodePtr prev = nullptr;

        while(temp)
        {
            if(temp->data == value)
            {   
                if(prev)
                {
                    prev->next = temp->next;
                }
                else
                {
                    this->head = temp->next;
                }
                
                
                delete temp;
                this->length--;
                break;
            }
            prev = temp;
            temp = temp->next;
        }      
    }
    else
    {
        std::cout << "Value not found" << std::endl;
    }
    
}

void LinkedList::reverse()
{
    if(!this->head)
    {
        // Empty list
    }
    else
    {
        NodePtr prev = nullptr;
        NodePtr currPtr = this->head;
        NodePtr nextPtr = this->head->next;
        NodePtr tempPtr = nextPtr->next;

        while(tempPtr != nullptr)
        {
            tempPtr = nextPtr->next;
            nextPtr->next = currPtr;
            currPtr->next = prev;

            prev = currPtr;
            currPtr = nextPtr;
            nextPtr = tempPtr;
        }
        this->head = currPtr;
    }
}

LinkedList::~LinkedList()
{
    NodePtr temp = nullptr, next = nullptr;

    if(this->head)
    {
        temp = this->head;
        this->head = nullptr;

        while(temp)
        {
            next = temp->next;
            delete temp;
            length--;
            temp = next;
            next = nullptr;
        }
    }
}

// Driver-function
int main(void){

    LinkedList L1;

    L1.insert(11);
    L1.insert(2);
    L1.insert(34);
    L1.insert(47);
    L1.insert(52);

    L1.display();
    std::cout << L1.getLength() << std::endl;
    L1.reset();
    L1.display();

    L1.insert(2);
    L1.insert(3);
    L1.display();
    std::cout << L1.getLength() << std::endl;

    L1.search(21) ? std::cout << "Found" << std::endl : std::cout << "Not Found" << std::endl;

    L1.deleteVal(2);
    L1.display();
    std::cout << L1.getLength() << std::endl;
    L1.insert(11);
    L1.insert(2);
    L1.insert(34);
    L1.reverse();
    L1.display();
    L1.reverse();
    L1.display();

    return 0;
}