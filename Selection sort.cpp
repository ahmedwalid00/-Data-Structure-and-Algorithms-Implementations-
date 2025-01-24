#include <iostream>

using namespace std;

void swap(int &x , int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void selection_sort(int arr[] , int sizee)
{
    int min_index;

    for(int i = 0 ; i < sizee -1 ; ++i)
    {
        min_index = i ;
        for(int j = i+1 ; j < sizee ; ++j)
            if(arr[j] < arr[min_index])
               min_index = j ;
        swap(arr[min_index],arr[i]);
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
    int arr[]={5,2,3,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr,n);
    print(arr,n);

    return 0;
}
