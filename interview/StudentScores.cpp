#include <iostream>
#include <vector>

class MaxHeap
{
    public:
        MaxHeap(int arr[],int size);
        void makeHeap();
        int getMaxElem() { return 0;}
        void heapify(int index);
        void print();
        int getLeftChild(int index);
        int getRightChild(int index);
        int getParent(int index);
        int getMaxElem(int& arrId);
        bool isEmpty();
        void insertToHeap(int val,int sec);
    private:
        void swap(int a,int b);
        int size;
        int scores[50];
        int arr[50];
};

MaxHeap::MaxHeap(int input[],int s)
{
    size = s;
    for(int i=0;i<size;i++)
    {
        scores[i] = input[i];
        arr[i]=i+1;
    }
}

void
MaxHeap::swap(int a, int b)
{
    int temp = scores[a];
    scores[a] = scores[b];
    scores[b] = temp;

    temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void
MaxHeap::print()
{
    for(int i=0;i<size;i++)
    {
        std::cout << arr[i] << "-->[" << scores[i] << "]" << std::endl;
    }
    std::cout << std::endl << "---" << std::endl;
}

int
MaxHeap::getLeftChild(int index)
{
    int left = ((index+1)*2)-1;
    if(left>=size)
        return -1;
    return left;
}

int
MaxHeap::getRightChild(int index)
{
    int right = ((index+1)*2);
    if(right>=size)
        return -1;
    return right;
}

int
MaxHeap::getParent(int index)
{
    int p = ((index+1)/2)-1;

    if(p<0 || p>=size)
        return -1;
    return p;
}

void
MaxHeap::heapify(int index)
{
    int left = getLeftChild(index);
    int right = getRightChild(index);
    if((left!=-1) && (right!=-1))
    {
        int max;
        if(scores[left] < scores[right])
        {
            if(scores[right] > scores[index])
            {
                swap(right,index);
                heapify(right);
            }
        }
        else
        {
            if(scores[left] > scores[index])
            {
                swap(left,index);
                heapify(left);
            }
        }
    }
    if(left!=-1)
    {
        if(scores[left] > scores[index])
        {
            swap(left,index);
            heapify(left);
        }
    }
}

void
MaxHeap::makeHeap()
{
    for(int i=size;i>=0;i--)
    {
        heapify(i); 
    }
}

int
MaxHeap::getMaxElem(int& arrId)
{
    int max = scores[0];
    arrId = arr[0];

    //remove the element and adjust
    swap(size-1,0);
    scores[size-1]=-1;
    arr[size-1]=0;
    size--;

    heapify(0);
    return max;
}

bool
MaxHeap::isEmpty()
{
    return (size>0)?false:true;
}

void
MaxHeap::insertToHeap(int val,int sec)
{
    size++;
    scores[size-1] = val;
    arr[size-1] = sec;
    swap(0,size-1);
    heapify(0);
}

//-------------- heap ends -----------

void printScores(std::string ref, std::vector<int> score)
{
    std::cout << ref << std::endl;
    for(auto& iter : score)
    {
        std::cout << "[" << iter << "]";
    }
    std::cout << std::endl;
}

std::vector<int>&
MergeScores(std::vector<int> a, std::vector<int> b, std::vector<int> c)
{
    std::vector<int>::iterator ai;
    std::vector<int>::iterator bi;
    std::vector<int>::iterator ci;

    std::vector<int>* merged = new std::vector<int>();

    int input[3];
    if(!a.empty())
    {
        ai = a.begin();
        input[0]=*ai;
    }
    if(!b.empty())
    {
        bi = b.begin();
        input[1]=*bi;
    }
    if(!c.empty())
    {
        ci = c.begin();
        input[2]=*ci;
    }

    MaxHeap* heap = new MaxHeap(input,3);
    heap->makeHeap();

    int k=0;
    while(!heap->isEmpty())
    {
        int id=0;
        int maxElem = heap->getMaxElem(id); 
        merged->push_back(maxElem);
        if(id==1)
        {
            ai++;
            if(ai!=a.end())
                heap->insertToHeap(*ai,1);
        }
        if(id==2)
        {
            bi++;
            if(bi!=b.end())
                heap->insertToHeap(*bi,2);
        }
        if(id==3)
        {
            ci++;
            if(ci!=c.end())
                heap->insertToHeap(*ci,3);
        }
    }

    return *merged;
}

// Taking 3 arrays as sample input

int main()
{
    //Sorted input
    std::vector<int> SecA = { 80,77,60,45,44};
    std::vector<int> SecB = { 90,74,70,69,48};
    std::vector<int> SecC = { 83,73,63,49,40};

    printScores("SecA",SecA);
    printScores("SecB",SecB);
    printScores("SecC",SecC);

    std::vector<int>& Overall = MergeScores(SecA,SecB,SecC);

    printScores("Overall",Overall);

    return 0;
}

