#include <iostream>

int findKthMissingNumber(int a[], int size, int k)
{
    int result;

    int beg = 0;
    int end = size-1;
    int numMissing = a[end]-size;

    //Kth missing number is after the end of the list
    if(k > numMissing)
    {
        int diff = k-numMissing;
        result = a[end]+diff;
    }
    else if(k < a[beg]) //kth missing number is before the first given one
    {
        result = k;
    }
    else
    {
        while( (end-beg) > 1)
        {
            int mid = (end+beg)/2;
            int num = a[mid]; 
            if(k > num-(mid+1))
            {
                //look right
                beg = mid;
            }
            else
            {
                //look left
                end=mid;
            }
        }

        int num = a[end];
        numMissing = a[end] - (end+1);
        int diff = numMissing-k;
        result = a[end] - diff -1;
    }


    return result;
}


int main()
{
    int input[6] = { 5,8,10,17,18 };

    int k = 14;
    int result = findKthMissingNumber(input,5,  k);

    std::cout << "Missing element #" << k << " is " << result << std::endl;

    return 0;
}
