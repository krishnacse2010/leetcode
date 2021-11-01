#include <iostream>
#include <iomanip>
#include <vector>
#include <stdio.h>

using namespace std;

// Haven't tested corner cases
// Might crash with some inputs

void printVector(const char* name, std::vector<int>& vec)
{
    std::cout << name << ":" << std::endl;
    for(auto& iter : vec)
    {
        std::cout << iter << " ";
    }
    std::cout << std::endl;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int m = nums1.size();
    int n = nums2.size();

    //enough if we get merged array upto this index
    int median = (m+n)/2;

    int beg1 = 0;
    int end1 = m-1;
    int mid1,index2;


    while(beg1<=end1)
    {
        mid1 = (beg1+end1)/2;
        index2 = median - mid1; //elements required from nums2

        if(index2 < n) //valid index
        {
            if(nums1[mid1-1] >= nums2[index2])
            {
                end1 = mid1;
            }
            else if(nums2[index2-1] > nums1[mid1])
            {
                beg1 = mid1;
            }
            //perform checks
            else if( nums1[mid1-1] < nums2[index2] &&
                     nums2[index2-1] < nums1[mid1])
            {
                //found
                std::cout << "Split Point: ";
                std::cout << nums1[mid1-1] << "|" << nums2[index2-1] << std::endl;
                break;
            }
        }
    }

    if( (m+n)/2 %2 ==0)
    {
        double med1 = nums1[mid1-1]>nums2[index2-1]?nums1[mid1-1]:nums2[index2-1];
        double med2 = nums1[mid1] < nums2[index2] ? nums1[mid1] : nums2[index2];

        return (double) (med1+med2)/2;
    }
    else
    {
        double med1 = nums1[mid1]<nums2[index2]?nums1[mid1]:nums2[index2];
        return med1;
    }

}

int main()
{
    std::vector<int> a = { 3, 4, 17, 18, 21,26 };
    std::vector<int> b = { 1, 2, 5, 44, 45, 89 };

    std::cout << "Printing out entries" << std::endl;
    printVector("a",a);
    printVector("b",b);


    double res = findMedianSortedArrays(a,b);

    std::cout << "Median:" << res << std::endl;
    return 0;
}
