#include <iostream>

int findFloorValue(int a[], int size, int val)
{
    int beg = 0;
    int end = size-1;

    if(a[beg] > val)
        return -1;
    if(val >= a[end])
        return a[end];

    while((end-beg) > 1)
    {
        int mid = (beg+end)/2;

        if(a[mid] <= val)
        {
            beg = mid;
        }
        else
        {
            end = mid;
        }
    }

    if(a[end] == val)
        return a[end];

    return a[beg];
}


int main()
{
    int arr[7] = { 5 , 22 , 48 , 49 , 57 , 79 , 90 };

    int k = 47;
    int floorVal = findFloorValue(arr, 7, k);

    std::cout << "Floor value of " << k << " is " << floorVal << std::endl;
    return 0;
}

