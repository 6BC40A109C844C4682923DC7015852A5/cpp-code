#include <iostream>

class Sqlist {
 public:
  Sqlist(int n) : capacity(n), data(new int[n]){};
  Sqlist(){};
  bool insert(int data) {
    if (this->size + 1 > this->capacity)
        return false;

    this->data[this->size] = data;
    this->size++;
    return true;
  }
  void traversal() {
    for (int i = 0; i < this->size; ++i)
      std::cout << this->data[i] << std::endl;
  }

  ~Sqlist(){};

 private:
  int *data;
  int size = 0;
  int capacity = 0;
};

int main() {
  Sqlist sq(7);
  for (int i = 0; i < 7; ++i) sq.insert(i + 1);
  sq.traversal();

  return 0;
}
