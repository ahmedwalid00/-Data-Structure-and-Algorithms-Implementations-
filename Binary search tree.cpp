#include <iostream>

using namespace std;

template<class t>
class BTS
{
    struct node
    {
        t info;
        node* left;
        node* right;
    };
    node* root;
    int length = 0 ;

public:
    BTS() : root(nullptr),length(0) {}
    bool isEmpty(){return (root == nullptr);}
    int num_of_elements(){return length;}

    void insert(t element)
    {
        node* NewNode = new node;
        NewNode ->info = element;
        NewNode ->left = nullptr;
        NewNode ->right = nullptr;
        node* current = root;
        node* tailCurrent = nullptr;

        if(isEmpty()){root = NewNode;}
        else
        {
            while(current != nullptr)
            {
                tailCurrent = current;
                if(current ->info >= element)
                    current = current ->left;
                else
                    current = current ->right;

            }

            if(tailCurrent ->info >= element)
                tailCurrent -> left = NewNode;
            else
                tailCurrent ->right = NewNode;
        }
        ++length;
    }

    void remove(t element)
    {
        node* current = root;
        node* tailCurrent = nullptr;


        if(isEmpty())
        {
            cout << " the tree is empty " << endl;
        }
        else if(length == 1)
        {
            node* temp = root;
            root = nullptr;
            delete temp;
        }
        else
        {
            node* temp = nullptr;
            bool found = false;

            while(current != nullptr)
            {
                if(current ->info == element)
                {
                    found = true;
                    break;
                }
                tailCurrent = current;
                if(current ->info >= element)
                    current = current -> left;
                else
                    current = current ->right;
            }
            if(!(found == true))
            {
                cout << " element is not found " << endl;
                return;
            }
            else if((current->left == nullptr) && (current->right == nullptr))
            {
                temp = current;
                if(tailCurrent->info >= current ->info)
                    tailCurrent ->left = nullptr;
                else
                    tailCurrent ->right = nullptr;
                delete temp;
            }
            else if((current ->left == nullptr) || (current ->right == nullptr))
            {
                temp = current;
               if(tailCurrent ->right == current)
               {
                   if(current -> left == nullptr)
                     tailCurrent ->right = current ->right;
                   else
                     tailCurrent ->right = current ->left;
                   delete temp;
               }
               else
               {
                   if(current -> left == nullptr)
                     tailCurrent ->left = current ->right;
                   else
                     tailCurrent ->left = current ->left;
                   delete temp;
               }

            }
            else if((current->left != nullptr) && (current ->right != nullptr))
            {
               temp = current;
               node* most_right = current ->left;
               most_right = most_right ->right;
               if(tailCurrent->info >= current ->info)
               {
                   tailCurrent ->left = most_right;
                   current->left->right = nullptr;
                   most_right ->left = current ->left;
                   most_right ->right = current ->right;
                   delete temp;
               }
            else
            {
                  tailCurrent ->right = most_right;
                   current->left->right = nullptr;
                   most_right ->left = current ->left;
                   most_right ->right = current ->right;
                   delete temp;
            }

            }
        }
        --length;
    }

    bool search(t element)
    {
        node* current = root;

        while(current != nullptr)
        {
            if(current ->info == element)
            {
                return true;
            }
            if(current ->info >= element)
                current = current ->left;
            else
                current = current ->right;
        }
        return false;
    }



};

int main()
{
   BTS<int> t1;
   t1.insert(12);
   t1.insert(15);
   t1.insert(11);
   t1.insert(13);
   t1.insert(41);
   t1.insert(65);
   t1.insert(2);
   t1.remove(8900);
   cout << t1.num_of_elements();

    return 0;
}
