#include <iostream>
#include <iomanip>
#include <vector>
#include <stdio.h>

using namespace std;

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
    int flag = (m+n)%2;
    int med = (m+n)/2;

    auto iter1=nums1.begin();
    auto iter2=nums2.begin();

    bool enough = false;

    vector<int>merged;
    //Compare and copy in increasing order
    while(iter1!=nums1.end() && iter2!=nums2.end())
    {
        if( (*iter1) < (*iter2))
        {
            merged.push_back(*iter1);
            iter1++;
        }
        else
        {
            merged.push_back(*iter2);
            iter2++;
        }


        if(merged.size() > med)
        {
            enough = true;
            break;
        }

    }
    //copy remaining elements if any
    while(!enough && iter1!=nums1.end())
    {
        merged.push_back(*iter1);
        iter1++;
        if(merged.size() > med)
        {
            enough = true;
            break;
        }
    }
    while(!enough && iter2!=nums2.end())
    {
        merged.push_back(*iter2);
        iter2++;
        if(merged.size() > med)
        {
            enough = true;
            break;
        }
    }

    double result;
    if(flag == 0)
    {
        double a = merged.at(med-1);
        double b = merged.at(med);
        result = (double)((a+b)/2);
    }
    else
        result = merged.at(med);

    return result;
}

int main()
{
    std::vector<int> a = { 4, 15, 18, 21,26, 29 };
    std::vector<int> b = { 1, 2, 5, 44, 45, 89 };

    std::cout << "Printing out entries" << std::endl;
    printVector("a",a);
    printVector("b",b);


    double res = findMedianSortedArrays(a,b);

    std::cout << "Median:" << res << std::endl;
    return 0;
}
