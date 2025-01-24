#include <iostream>
#include <algorithm>

using namespace std;

int partition2(int arr[] , int istart , int jend)
{
    int i = istart;
    int j = jend ;
    int piv = arr[istart];

    while( i < j)
    {
        while((arr[i] <= piv)&&(i <= jend ))
        {
            ++i;
        }

       while((arr[j] > piv))
       {
           --j;
       }

        if(i < j)
            swap(arr[i],arr[j]);
    }
    swap(arr[istart],arr[j]);
    return j;
}

void quick_sort(int arr[] ,int l , int r)
{
    if(l<r)
    {
        int piv = partition2(arr,l,r);

        quick_sort(arr,l,piv-1);
        quick_sort(arr,piv+1,r);

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
    quick_sort(arr,0,n-1);
    print(arr,n);

    return 0;
}
