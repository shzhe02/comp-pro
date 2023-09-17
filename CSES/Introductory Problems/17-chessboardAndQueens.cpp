#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> placeQueen(vector<string> state, int y, int x) {
  vector<string> newState = state;
  for (int i = 0; i < 8; i++) {
    newState[y][i] = '*';
    newState[i][x] = '*';
  }
  for (int i = 1; i < 8; i++) {
    int yu = y + i;
    int yd = y - i;
    int xu = x + i;
    int xd = x - i;
    newState[(yu < 8) ? yu : y][(xd >= 0) ? xd : x] = '*';
    newState[(yd >= 0) ? yd : y][(xu < 8) ? xu : x] = '*';
    newState[(yu < 8) ? yu : y][(xu < 8) ? xu : x] = '*';
    newState[(yd >= 0) ? yd : y][(xd >= 0) ? xd : x] = '*';   
  }
  return newState;
}

int findStates(vector<string> state, int queensLeft) {
  if (queensLeft == 0) {
    return 1;
  }
  int possibilities = 0;
  for (int i = 0; i < 8; ++i) {
      if (state[8 - queensLeft][i] == '.') {
        possibilities += findStates(placeQueen(state, 8 - queensLeft, i), queensLeft - 1);
      }
  }
  return possibilities;
}

int main() {
  vector<string> board;
  int count = 8;
  while (count--) {
    string line;
    cin >> line;
    board.push_back(line);
  }
  cout << findStates(board, 8);
  // cout << endl;
  // auto test = placeQueen(board, 3, 4);
  // for (auto i : test) {
  //   cout << i << endl;
  // }
  // cout << endl << endl;
  // for (auto i : board) {
  //   cout << i << endl;
  // }
}