#include <iostream>
#include <string>
using namespace std;

class ChosenNum {
private:
  int chosenNum;
public:
  ChosenNum(const int chNum) : chosenNum(chNum){}

  int getChNum() {
    return chosenNum;
  }
};

class IntArr {
private:
  int size;
  int* intArr;
  ChosenNum chosenNum;
public:
  IntArr(const int* arr, int size, int chNum) : size(size), chosenNum(chNum) {
    intArr = new int[size];
    for (int i = 0; i < size; i++) {
      intArr[i] = arr[i];
    }
  }

  ~IntArr() {
    delete[] intArr;
  }

  void delNum() {
    int j = 0;
    for (int i = 0; i < size; i++) {
      int elem = intArr[i];
      string s_elem = to_string(elem);
      int sumStr = 0;
      for (int index = 0; index < s_elem.size(); index++) {
        sumStr += s_elem[index] - '0';
      }
      if (sumStr > chosenNum.getChNum()) {
        intArr[j++] = intArr[i];
      }
    }
    size = j;
  }

  void print() const {
    for (int i = 0; i < size; i++) {
      cout << intArr[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  int arr[] = { 12, 38, 124, 100, 4 };
  int size = sizeof(arr) / sizeof(arr[0]);
  int chNum = 4;

  IntArr intArr(arr, size, chNum);
  
  cout << "Initial array: " << endl;
  intArr.print();

  intArr.delNum();

  cout << "Array after deletion: " << endl;
  intArr.print();
}
