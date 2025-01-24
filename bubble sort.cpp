#include <iostream>

using namespace std;

void swap(int &x , int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void bubble_sort(int arr[] , int sizee)
{
    bool flag = true;
    for(int i = 0 ; i < sizee - 1 ; ++i)
    {
        for(int j = 0 ; j < sizee-i-1 ; ++j)
        {
            if(arr[j] > arr[j+1])
              {
                  swap(arr[j] , arr[j+1]);
                  flag = false;
              }
            if(flag)
            break;
        }

    }

}

void print(int arr[] , int sizee)
{
    for(int i = 0 ; i < sizee ; ++i)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

int main()
{
    int arr[]={1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n);
    print(arr,n);

    return 0;
}
