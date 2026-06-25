#include <iostream>
using namespace std;
#include <vector>

vector<int> heap;

int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

void insert (int val){
    heap.push_back();
    heapifyUp(heap.size()-1);
}