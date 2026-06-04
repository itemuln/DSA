#include <iostream>

class Solution {
public:
  int helper(int num) {
    int total = 0;
    std::string numStr = std::to_string(num);
    for (int i = 1; i < numStr.length() - 1; i++) {
      if (numStr[i] > numStr[i - 1] && numStr[i] > numStr[i + 1]) {
        total++;
      } else if (numStr[i] < numStr[i - 1] && numStr[i] < numStr[i + 1]) {
        total++;
      }
    }
    return total;
  }
  int findWave(int num1, int num2) {
    int greater, lower;
    if (num1 >= num2) {
      greater = num1;
      lower = num2;
    } else {
      greater = num2;
      lower = num1;
    }
    if (greater < 100) {
      return 0;
    }

    while (lower < 100) {
      lower++;
    }
    int total = 0;
    while (lower <= greater) {
      total += helper(lower);
      lower++;
    }
    return total;
  }
  Solution(int num1, int num2) { std::cout << findWave(num1, num2) << "\n"; }
};

int main() {
  int num1, num2;
  std::cin >> num1 >> num2;
  Solution(num1, num2);
}
