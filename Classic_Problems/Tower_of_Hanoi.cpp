#include <iostream>

void hanoi(int n, char a, char b, char c){
  if (n == 1){
    std::cout << "Move " << n << " from " << a << " to " << c << std::endl;
  }
  else{
    hanoi(n-1, a, c, b);
    hanoi(1, a, b, c);
    hanoi(n-1, b, a, c);
  }
}

int main(){
  hanoi(10, 'a', 'b', 'c');
  return 0;
}
