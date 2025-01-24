#include <iostream>

using namespace std;

template<class t>
class DoublyLinkedList
{
    struct node
    {
        t item;
        node* next;
        node* prev;
    };
    node* first;
    node* last;
    int length;
public:
    DoublyLinkedList()
    {
        first = last = nullptr;
        length = 0 ;
    }
    bool isEmpty(){return (length==0);}

    void insert_front(t element)
    {
        node* NewNode = new node;
        NewNode ->item = element;
        if(isEmpty())
        {
            first = last = NewNode;
            NewNode ->next = NewNode ->prev = nullptr;
        }
        else
        {
            NewNode ->prev = nullptr;
            NewNode ->next = first;
            first -> prev = NewNode;
            first = NewNode;
            ++length;
        }
    }

    void insert_back(t element)
    {
        node* NewNode = new node;
        NewNode ->item = element;
        if(isEmpty())
        {
            first = last = NewNode;
            NewNode ->next = NewNode ->prev = nullptr;
        }
        else
        {
            NewNode ->next = nullptr;
            NewNode -> prev = last;
            last -> next = NewNode;
            last = NewNode;
            ++length;
        }
    }

    void insert_at_postion(int pos , t element)
    {
        node* NewNode = new node;
        NewNode -> item = element;

        if(pos < 0 || pos >= length)
        {
            cout << " out of range " << endl;
            return;
        }
        else if(pos == 0){insert_front(element);}
        else if(pos == length){insert_back(element);}
        else
        {
            node* cur = first;
            for(size_t i = 0 ; i < pos ; ++i)
            {
                cur = cur -> next;
            }
            NewNode ->next = cur -> next;
            NewNode ->prev = cur;
            cur ->next = NewNode;
            cur ->next->prev = NewNode;
            ++length;
        }
    }

    void remove_first()
    {
        if(isEmpty())
        {
            cout << "the list is empty " << endl;
            return;
        }
        else if(length == 1)
        {
            first = last = nullptr;
            length = 0;
        }
        else
        {
            node* cur = first;
            first = first ->next;
            first ->prev = nullptr;
            delete cur;
            --length;
        }
    }

    void remove_last()
    {
      if(isEmpty())
        {
            cout << "the list is empty " << endl;
            return;
        }
        else if(length == 1)
        {
            first = last = nullptr;
            length = 0;
        }
        else
        {
            node* cur = last;
            last = last -> prev;
            last ->next = nullptr;
            delete cur;
            --length;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

