#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define parent(idx) ((idx - 1) >> 1)
#define leftChild(idx) ((idx << 1) + 1)
#define rightChild(idx) ((idx << 1) + 2)

// Binary Heap implementation

// Max Heap
template<typename t> 
class MaxHeap {
public:
    t sz;
    vector<t> heap;

    MaxHeap() { sz = 0; } // Constructor. Assign size of heap 0

    void upHeapify(t idx) { // Balances leaf element in heap
        if(idx and heap[parent(idx)] < heap[idx]) { // Compare value with it's parent
            swap(heap[parent(idx)], heap[idx]); // Swap if parent is greater than value
            upHeapify(parent(idx)); // Recursive Heapify call for parent
        }
    }

    void downHeapify(t idx) { // Balances root in heap
        t mx = idx;

        // Find minimum index out of root and it's two children
        if (leftChild(idx) < sz and heap[leftChild(idx)] > heap[idx]) mx = leftChild(idx);
        if (rightChild(idx) < sz and heap[rightChild(idx)] > heap[mx]) mx = rightChild(idx);

        swap(heap[idx], heap[mx]);

        // Recursively call for swapped child if root is changed, else recursion ends
        if(mx != idx) downHeapify(mx); // Recursive Heapify call
    }

    void insert(t value) { // Insert function for heap
        heap.push_back(value); // Insert element in heap
        upHeapify(sz); // Balance heap
        sz++; // Increment size
    }

    void remove() { // Delete root from heap
        if (!sz) { // If heap is empty
            cout << "Empty.\n";
            return;
        }

        heap[0] = heap[sz - 1]; // Make root equal to last element in heap array
        heap.pop_back(); // Pop last element
        sz--; // Decrease size
        downHeapify(0); // Rebalance heap to update root
    }

    void remove(t idx) { // Delete element from given idx
        if (!sz) { // If heap is empty
            cout << "Empty.\n";
            return;
        } 
        else if(idx > sz) { // If index is out of bound
            cout << "Index doesn't exist in heap.\n";
            return;
        }

        heap[idx] = INT_MAX; // Change value of index to minimum value
        upHeapify(idx); // Balance the tree
        remove(); // Now as the root is minimum, balance the tree
    }

    void display() { // Print heap, level order traversal
        for(auto &i : heap) 
            cout << i << " ";
        cout << "\n";
    }

};

void solve() { // Driver Function
    MaxHeap<int> tr;
    int q; // No. of queries
    cin >> q;
    for (int i = 0; i < q; i++) {
        string t; // Type of query
        cin >> t;
        if (t == "Insert") {
            int val;
            cin >> val;
            tr.insert(val);
        }
        else if (t == "Delete") {
            int idx; // Index in heap to be deleted
            cin >> idx;
            tr.remove(idx);
        }
        else {
            tr.display();
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}

/*
Test Cases
10
Insert 5
Insert 10
Insert 2
Insert 15
Delete 0
Insert 25
Delete 2
Insert 12
Insert 11
Display
*/