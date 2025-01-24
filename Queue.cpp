#include<iostream>
using namespace std;

#define size 5
int queue[size] , front = -1 , rear = -1 ;

void enqueue (int value)
{
    if(rear != size-1)
   {
       if(front == -1 && rear == -1)
       {
           front++;
           rear++;
           queue[rear] = value;
       }
       else
       {
           rear++;
           queue[rear] = value;
       }
   }
   else
   {
       cout << "the queue is full" << endl;
   }
}
void dequeue ()
{
    if(front != -1 && rear != -1 && front <= rear)
    {
        front++;
    }
    else
    {
        cout << "the queue is empty " << endl;
    }
}

void display()
{
    if(front != -1 && rear != -1 && front <= rear)
    {
        for(int i = front ; i <= rear ; ++i)
            cout << queue[i] << endl;
    }
    else
    {
        cout << " the queue is empty " << endl;
    }

}

int peek()
{
    if(front != -1 && rear != -1 && front <= rear)
        return queue[front];
    else
    {
        cout << " the queue is empty " << endl;
        return -1;
    }
}

int main()
{
    enqueue(5);
    enqueue(9);
    enqueue(7);
    enqueue(3);
    display();
    cout << "*********************************" << endl;
    dequeue();
    display();
    cout << "*********************************" << endl;
    cout << peek() << endl;
}
