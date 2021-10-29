#include <iostream>
#include <vector>
#include <map>

class Digit
{
    public:
        Digit(int n) {num = n; freq=1;}
        Digit() {freq=1;}

        //value
        int getNum() { return num; }

        //Freq
        unsigned int getFreq() { return freq; }
        void incrementFreq() { freq++;}

        void print()
        {
            std::cout << "Value:" << num << " Freq:" << freq << std::endl;
        }

    private:
        int num;
        unsigned int freq;
};

class MaxHeap
{
    public:
        MaxHeap() { size = 0; }
        void addToHeap(Digit* pDigit);
        void print()
        {
            std::cout << "Printing Heap" << std::endl;
            for(int i=0; i< size; i++)
            {
                std::cout << "[" << i << "]:"; 
                heap[i]->print();
            }
        }

        int getMaxElem();
        bool isEmpty()
        {
            if(size>0)
                return false;
            return true;
        }

    private:
        int getParent(int index)
        {
            return (((index+1)/2) -1);
        }

        int getLeftChild(int index)
        {
            int left = (index+1)*2 - 1;
            if(left < size)
                return left;
            else
                return -1;
        }

        int getRightChild(int index)
        {
            int right = (index+1)*2;
            if(right < size)
                return right;
            else
                return -1;
        }

        void swap(int a, int b)
        {
            Digit* temp = heap[a];
            heap[a] = heap[b];
            heap[b] = temp;
        }
        void heapify(int index);

        void checkParent();
        Digit* heap[100];
        int size;
};

void MaxHeap::heapify(int index)
{
    int left = getLeftChild(index);
    int right = getRightChild(index);

    if(left!=-1 && right!=-1)
    {
        if(heap[left]->getFreq() < heap[right]->getFreq())
        {
            if(heap[right]->getFreq() > heap[index]->getFreq())
            {
                swap(right,index);
                heapify(right);
            }
        }
        else
        {
            if(heap[left]->getFreq() > heap[index]->getFreq())
            {
                swap(left,index);
                heapify(left);
            }
        }
    }
    else if(left!=-1)
    {
        if(heap[left]->getFreq() > heap[index]->getFreq())
        {
            swap(left,index);
            heapify(left);
        }
    }
}

int MaxHeap::getMaxElem()
{
    int maxElem;
    if(size!=0)
    {
        int index = 0;
        int last = size-1;
        Digit* pD = heap[index];
        maxElem = pD->getNum();

        swap(index,last);
        size--;
        delete(pD); pD=0;
        heapify(0);
    }
    return maxElem;
}

void MaxHeap::addToHeap(Digit* pDigit)
{
    heap[size++] = pDigit;
    checkParent();
}

void MaxHeap::checkParent()
{
    int index = size-1;

    while(index!=0)
    {
        int parent = getParent(index); 
        if(heap[parent]->getFreq() < heap[index]->getFreq())
        {
            swap(index,parent);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void findFrequentNumbers(std::vector<int>& in, int n, std::vector<int>& out)
{
    MaxHeap h;
    std::map<int,Digit*> freqMap;

    for(auto& iter : in)
    {
        auto mapIter = freqMap.find(iter);
        if(mapIter!=freqMap.end())
        {
            (mapIter->second)->incrementFreq();
        }
        else
        {
            Digit* d = new Digit(iter);
            freqMap[iter] = d;
        }
    }

    std::cout << "Printing Map -" << std::endl;
    for(auto& iter : freqMap)
    {
        std::cout << "[" << iter.first << "]";
        (iter.second)->print();
    }

    for(auto& mapIter : freqMap)
    {
        Digit* pDigit = (mapIter.second);
        h.addToHeap(pDigit);
    }
    h.print();

    for(int i=0;i<n;i++)
    {
        if(!h.isEmpty())
        {
            int max = h.getMaxElem();
            out.push_back(max);
        }
        else
            break;
    }

}

int main()
{
    std::vector<int> input = { 6,7,8,8,6,4,3,4,1,9,6,8,2};

    std::vector<int> output;

    int n = 3; // Top n frequent
    findFrequentNumbers(input,n, output);

    std::cout << "Top " << n << " frequent numbers: { ";
    for(auto& iter : output)
    {
        std::cout << iter << " ";
    }
    std::cout << "}" << std::endl;

    return 0;
}
