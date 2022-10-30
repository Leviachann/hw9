#include <assert.h>
#include <iostream>
using namespace std;

class Student {
public:
  double avg;
  bool operator>(const Student obj) { return avg > obj.avg; }
  ostream& operator<<(ostream& os) {return cout<<avg; }
};

class PriorityQuene {
  Student *arr;
  int capacity;
  int rear;
  int count;

  int GetMaxIndex() {
    int maxIndex = 0;
    for (int i = 0; i < count; i++) {
      if (arr[i] > arr[maxIndex]) {
        maxIndex = i;
      }
    }
    return maxIndex;
  }

public:
  PriorityQuene(int size) {
    arr = new Student[size];
    capacity = size;
    rear = 0;
    count = 0;
  }

  bool IsFull() const { return count == capacity; }

  bool IsEmpty() const { return count == 0; }

  void EnQuene(Student val) {
    assert(!IsFull() && "Quene is full");
    arr[rear++] = val;
    count++;
  }

  void DeQuene() {
    assert(!IsEmpty() && "Quene is empty");
    int index = GetMaxIndex();
    for (int i = 0; i < count - 1; i++) {
      arr[i] = arr[i + 1];
    }
    count--;
    rear--;
  }

  Student &Front() {
    assert(!IsEmpty() && "Quene is empty");
    return arr[GetMaxIndex()];
  }

  void Print() {
    for (int i = 0; i < count; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  ~PriorityQuene() { delete[] arr; }
};