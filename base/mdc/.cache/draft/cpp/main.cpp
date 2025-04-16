#include <iostream>

// ADD!0
int mdc(int a, int b) {
  if (b == 0) {
    return a;
  }
  return mdc(b, a % b);
  todo
  return 0;
}

//
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << mdc(a, b) << std::endl;
  return 0;
}
