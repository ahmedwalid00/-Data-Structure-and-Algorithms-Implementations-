#include <iostream>
#include <algorithm>

using namespace std;

void hepify(int arr[] , int s , int i)
{
    int l = i*2+1;
    int r = i*2+2;

    int max = i;

    if((l<s) && (arr[l] > arr[max]))
        max = l;
    if((r<s) && (arr[r] > arr[max]))
        max = r;

    if(max != i)
  {
        swap(arr[i],arr[max]);
    hepify(arr,s,max);
  }
}

void build_heap(int arr[],int s)
{
    for(int i = s/2-1 ; i >= 0 ; --i)
    {
        hepify(arr,s,i);
    }
}

void heap_sort(int arr[] , int s)
{
    build_heap(arr,s);
    for(int i = s-1 ; i >= 0 ; --i)
    {
        swap(arr[0],arr[i]);
        hepify(arr,i,0);
    }
}



void print(int arr [] , int n)
{
    for(int i = 0 ; i < n ; ++i)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

int main()
{
    int arr[]={5,3,1,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    heap_sort(arr,n);
    print(arr,n);

    return 0;
}
