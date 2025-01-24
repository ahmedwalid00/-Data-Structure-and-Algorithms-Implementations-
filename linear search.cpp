#include <iostream>
#include <algorithm>

using namespace std;

int linear_search(int arr[], int n , int key)
{
    for(int i = 0 ; i < n ; ++i)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int arr[]{30,12,41,67,89};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num;
    cin >> num;
    int result = linear_search(arr,n,num);

    if(result == -1)
        cout << " the item is not found " << endl;
    else
        cout << " the item " << num << " is found at index : " << result << endl;
}
