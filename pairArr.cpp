#include <iostream>
#include <string>
using namespace std;

class Pair {
private:
  int intNum;
  float floatNum;
public:
  Pair() : intNum(0), floatNum(0.0){}

  Pair(int iNum, float fNum) : intNum(iNum), floatNum(fNum){}

  int getIntNum() {
    return intNum;
  }

  float getFloatNum() {
    return floatNum;
  }

  string getPair() {
    return "int Num: " + to_string(intNum) + " float Num: " + to_string(floatNum) + " ";
  }
};

class PairArr {
private:
  Pair* pairArr;
  int size;
public:
  PairArr(const Pair* arr, int size) : size(size) {
    pairArr = new Pair[size];
    for (int i = 0; i < size; i++) {
      pairArr[i] = arr[i];
    }
  }

  ~PairArr() {
    delete[] pairArr;
  }

  void delEqual() {
    int j = 0;
    for (int i = 0; i < size; i++) {
      if (pairArr[i].getIntNum() != pairArr[i].getFloatNum()) {
        pairArr[j++] = pairArr[i];
      }
    }
    size = j;
  }

  void print() const {
    for (int i = 0; i < size; i++) {
      cout << pairArr[i].getPair() << endl;
    }
    cout << endl;
  }
};

int main() {
  Pair p1(1, 9.5);
  Pair p2(2, 5.4);
  Pair p3(3, 3.0);
  Pair p4(4, 8.76);
  Pair p5(5, 5.0);

  Pair arr[] = { p1, p2, p3, p4, p5 };
  int size = sizeof(arr) / sizeof(arr[0]);

  PairArr pairArr(arr, size);

  cout << "Initial array: " << endl;
  pairArr.print();

  pairArr.delEqual();

  cout << "Array after deletion: " << endl;
  pairArr.print();
}
