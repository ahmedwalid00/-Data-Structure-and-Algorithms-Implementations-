#include <iostream>

using namespace std;

template<class t>
class LinkedList
{
    struct node
    {
        t item;
        node* next;
    };
    node* first;
    node* last;
    int length;
public:
    LinkedList()
    {
        first = last = nullptr;
        length = 0;
    }
    bool isEmpty(){return (length == 0);}

    void insert_first(t element)
    {
        node* NewNode = new node;
        NewNode -> item = element;
        if(isEmpty())
        {
            first = last = NewNode;
            NewNode ->next = nullptr;
        }
        else
        {
            NewNode ->next = first;
            first = NewNode;
        }
        ++length;
    }

    void insert_last(t element)
    {
        node* NewNode = new node;
        NewNode -> item = element;

        if(isEmpty())
        {
            last = first = NewNode;
            NewNode -> next = nullptr;
        }
        else
        {
            last -> next = NewNode;
            NewNode ->next = nullptr;
            last = NewNode;
        }
        ++length;
    }

    void insert_at_postion(int pos , t element)
    {
        node* NewNode = new node;
        NewNode ->item = element;
        if(pos == 0){insert_first(element);}
        else if(pos == length) {insert_last(element);}
        else
        {
            node* cur = first;

            for(size_t i = 0 ; i < pos ; ++i)
            {
                cur = cur ->next;
            }
            NewNode ->next = cur -> next;
            cur ->next = NewNode;
        }
        ++length;
    }

    void print()
    {
        node* cur = first;
        cout << "[ " ;
        while(cur != nullptr)
        {
            cout << cur -> item << " ";
            cur = cur -> next;
        }
        cout << " ]" << endl;
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
            node* temp = first;
            first = first ->next;
            delete temp;
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
            node* cur = first;
            node* prev = nullptr;

            while(cur->next != nullptr)
            {
                prev = cur;
                cur = cur ->next;
            }
             delete cur;
             prev ->next = nullptr;
             last = prev;
             --length;
        }
    }

    void remove(t element)
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
            node* cur = first -> next;
            node* prev = first;

            while((cur != nullptr) && (cur ->item != element))
            {
                prev = cur;
                cur = cur -> next;
            }
            if(cur == nullptr)
            {
                cout << " element is not found " << endl;
                return;
            }
            if(last == cur)
            {
                last = prev;
            }
            prev ->next = cur -> next;
            delete cur;
            --length;
        }

    }

    void remove_at_postion(int pos)
    {
         if(isEmpty())
        {
            cout << "the list is empty " << endl;
            return;
        }
        else if(length == 0)
        {
            remove_first();
            return;
        }
        else if(pos == length-1)
        {
            remove_last();
            return;
        }
        else
        {
            node* cur = first;

            for(size_t i = 0 ; i < pos ; ++i)
            {
                cur = cur -> next;
            }
            node* temp = cur ->next;
            cur -> next = temp -> next;
            delete temp;
            --length;
        }
    }

    void reverse()
    {
        node* cur = first;
        node* prev = nullptr;
        node* next = cur -> next;

        while(next != nullptr)
        {
            cur ->next = prev;
            prev = cur;
            cur =next;
            next = cur -> next;
        }
        first = prev;
    }

    void search(t element)
    {
        node* cur = first;
        int pos =0 ;

        while (cur != nullptr)
        {
            if(cur -> item == element)
            {
                cout << " the element has been found at : " << pos << endl;
                return;
            }
            cur = cur ->next;
            ++pos;
        }
        cout << " the element is not found " << endl;
    }

};

int main()
{
   LinkedList<int> l;
   l.insert_first(40);
   l.insert_first(30);
   l.insert_first(20);
   l.insert_first(10);

   l.search(67);
   l.print();
}
