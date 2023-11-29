#include <iostream>

using namespace std;

//maxheap

class heap{
    
    public:
    int * arr;
    int cap;
    int size;
    
    heap(){
        arr = new int[2];
        cap = 2;
        size = 1;
    }
    
    void increasecap(){
        cap *= 2;
        int * newarr = new int[cap];
        
        for(int i = 1; i < size; i++) newarr[i] = arr[i];
        
        delete [] arr;
        arr = newarr;
    }
    
    void insert(int num){
        if(size == cap){
            increasecap();
        }
        
        arr[size++] = num;
        heapifyup(size-1);
    }
    
    void heapifyup(int ind){
        if(ind == 1) return ;
        
        int parent = ind/2;
        
        if(parent >= 1 && arr[parent] < arr[ind]){
            swap(arr[parent],arr[ind]);
            heapifyup(parent);
        }
    }
    
    void heapifydown(int ind){
        
        int largest = ind;
        int left = 2*ind;
        int right = 2*ind + 1;
        
        if(left < size && arr[largest] < arr[left]){
            largest = left;
        }
        
        if(right < size && arr[largest] < arr[right]){
            largest = right;
        }
        
        if(largest != ind){
            swap(arr[largest],arr[ind]);
            heapifydown(largest);
        }
    }
    
    void heapsort(){
        int n = size;
        
        for(int i = n-1; i >= 1; i--){
            swap(arr[i],arr[1]);
            size--;
            heapifydown(1);
        }
        
        for(int i = 1; i < n; i++){
            cout << arr[i] << " " ;
        }
        cout << endl;
        
        size = n;
        
        for(int i = size-1/2; i >= 1; i--){
            heapifydown(i);
        }
    }
    
    void print(){
        for(int i = 1; i < size ; i++) cout << arr[i] << " ";
        
        cout << endl;
    }
};

int main()
{
    
    heap hp;
    hp.insert(1);
    hp.insert(2);
    hp.insert(3);
    hp.insert(4);
    hp.insert(5);
    hp.insert(6);
    hp.insert(7);
    hp.print();
    
    hp.heapsort();
    hp.print();
    
    
    return 0;
}
