#include <iostream>

#define Max 100

class Sqlist {
 public:
  Sqlist(int n) : capacity(n){};
  Sqlist(){};
  bool insert(int data) {
    if (this->size + 1 > this->capacity) {
      if (this->capacity * 2 > Max) return false;
      this->capacity *= 2;
    }

    this->data[this->size++] = data;
    return true;
  }
  void traversal() {
    for (int i = 0; i < this->size; ++i)
      std::cout << this->data[i] << std::endl;
  }

  ~Sqlist(){};

 private:
  int data[Max] = {0};
  int size = 0;
  int capacity = 0;
};

int main() {
  Sqlist sq(7);
  for (int i = 0; i < 7; ++i) sq.insert(i + 1);
  sq.traversal();

  return 0;
}
