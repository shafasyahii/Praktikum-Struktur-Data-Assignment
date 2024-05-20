#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    int i = heapSize;
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

int extractMax() {
    if (heapSize < 0) {
        std::cout << "Heap is empty. Cannot extract maximum.\n";
        return -1;
    }
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    if (i > heapSize) {
        std::cout << "Index out of bounds. Cannot change priority.\n";
        return;
    }
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

void remove(int i) {
    if (i > heapSize) {
        std::cout << "Index out of bounds. Cannot remove.\n";
        return;
    }
    H[i] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(i);
}

int getMax() {
    if (heapSize < 0) {
        std::cout << "Heap is empty. No maximum.\n";
        return -1;
    }
    return H[0];
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int p;
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> p;
        insert(p);
    }

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority : " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    int i;
    std::cout << "Enter the index to change priority: ";
    std::cin >> i;
    int p;
    std::cout << "Enter new priority: ";
    std::cin >> p;
    changePriority(i, p);

    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Enter the index to remove: ";
    std::cin >> i;
    remove(i);

    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}