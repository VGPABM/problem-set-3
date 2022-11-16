#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
      *a = *b;
      *b = tmp;
}

void heapmaker(int arr[], int N, int i)
{
    int smallest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < N && arr[l] < arr[smallest])
        smallest= l;
 
    // If right child is larger than largest so far
    if (r < N && arr[r] < arr[smallest])
        smallest = r;
 
    // If largest is not root
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
 
        // Recursively heapify the affected sub-tree
        heapmaker(arr, N, smallest);
    }
}

void buildHeap(int arr[], int N)
{
    // Index of last non-leaf node
    int startIdx = (N / 2) - 1;
 
    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapmaker(arr, N, i);
    }
}

void printHeap(int arr[], int N)
{
    printf("Bentuk Array heapnya adalah:\n");
 
    for (int i = 0; i < N; ++i)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    //bentuk min heap 
    //                 12
    //            /         \
    //           34           23
    //         /    \        /  \
    //        46     76    65  45
    //      /   \    / 
    //     67   98  89
    // 
    int arr[10] = {45,67,23,46,89,65,12,34,98,76};
    int n = sizeof(arr) / sizeof(arr[0]);
    int test = sizeof(arr);
    cout<<n<<endl;
    
    buildHeap(arr, n);
    printHeap(arr, n);
    

    return 0;
}
