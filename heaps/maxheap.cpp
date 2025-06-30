// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class MaxHeap {
  public:
  int *arr;
  int size, totalSize;
  
  MaxHeap(int x) {
    size = 0;
    totalSize = x;
    arr = new int[x];
  }
  
  void insert(int val) {
      if(size == totalSize) {
          cout << "Heap overflow \n" ;
          return;
      }
      arr[size] = val;
      int index = size;
      size++;
      int parent = (index-1)/2;
      while(arr[index] > arr[parent]) {
          int temp = arr[parent];
          arr[parent] = arr[index];
          arr[index] = temp;

          index =  parent;
          parent = (index-1)/2;
      }
  }

  void print() {
      for(int i = 0; i < size; i++) {
          cout << arr[i] << " ";
      }
      cout << endl;
  }
};



int main() {
    // Write C++ code here
    MaxHeap H1(5);
    
    H1.insert(5);
    H1.insert(15);
    H1.insert(25);
    H1.insert(53);
    H1.insert(55);
    H1.insert(55); // Heap overflow 

    // print heap
    H1.print(); //55 53 15 5 25 

    // delete element from heap
    // H1.delete();


    return 0;
}
