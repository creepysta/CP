#include<bits/stdc++.h>

using namespace std;

class Heap {
    private:
    void heapify(int i, int n) {
        int l = 2*i+1, r = 2*i+2;
        int largest = i;
        if(l < n && a[largest] < a[l]) largest = l;
        if(r < n && a[largest] < a[r]) largest = r;
        if(largest != i) {
            swap(a[largest], a[i]);
            heapify(largest, n);
        }
    }
    int heap_size;
    vector<int> a;
    public:
    Heap() : a(vector<int>()), heap_size(0) { }
    Heap(const vector<int> &_a) : a(_a), heap_size(_a.size()) {
        build_heap();
    }
    void increase_val(int i, int x) {
        if(x < a[i]) return;
        a[i] = x;
        while(i >= 0 && a[(i-1)/2] < a[i]) {
            if(i == 0) break;
            swap(a[(i-1)/2], a[ i ]);
            i = (i-1)/2;
        }
    }
    void insert(int x) {
        cout << "Insert " << x << endl;
        a.push_back(-1);
        heap_size = a.size();
        // heap_size++;
        increase_val(heap_size-1, x);
    }
    void build_heap() {
        int n = a.size();
        for(int i = n/2; i >= 0; i--) {
            heapify(i, (int) a.size());
        }
    }
    int extractMax() {
        if(heap_size == 0) {
            cout << "Heap is empty\n";
            return -1;
        }
        int retval = a[0];
        cout << "Current elements in heap: ";
        for(int i : a) cout << i << ' ';
        cout << endl;
        cout << "Extracting max element from heap: " << retval << endl;
        swap(a[0], a[heap_size-1]);
        a.pop_back();
        heap_size--;
        heapify(0, heap_size);
        return retval;
    }
};


int main() {   
    vector<int> a{12, 90, 14, 91, 88};
    Heap heap(a);
    heap.insert(5);
    heap.insert(95);
    cout << heap.extractMax() << endl;
    cout << heap.extractMax() << endl;
    cout << heap.extractMax() << endl;
    cout << heap.extractMax() << endl;
    cout << heap.extractMax() << endl;
    heap.insert(99);
    cout << heap.extractMax() << endl;
    cout << heap.extractMax() << endl;
    cout << heap.extractMax() << endl;
    cout << heap.extractMax() << endl;
    heap.insert(99);
    cout << heap.extractMax() << endl;
    return 0;
}
