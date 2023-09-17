#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n & 1) {
    
    if (((n - 1) >> 1) & 1) { // Odd number of blocks after trimming
      cout << "YES" << endl;
      cout << (n + 1) / 2 << endl;
      for (int j = 1; j <= (n - 1)/2; j += 2) {
        cout << j << " " << n - j << " ";
      }
      cout << endl;
      cout << n / 2 << endl;
      for (int i = 2; i <= (n - 1)/2; i += 2) {
        cout << i << " " << n - i << " ";
      }
      cout << n << endl;
      
    } else {
      cout << "NO" << endl;
    }
  } else {
    if (n & 3) { // Odd number of blocks
      cout << "NO" << endl;
    } else { // Even number of blocks
      cout << "YES" << endl;
      cout << n / 2 << endl;
      for (int j = 1; j <= n / 2; j += 2) {
        cout << j << " " << n - j + 1 << " ";
      }
      cout <<endl;
      cout << n / 2 << endl;
      for (int i = 2; i <= n / 2; i += 2) {
        cout << i << " " << n - i + 1 << " ";
      }
    }
  }
}
