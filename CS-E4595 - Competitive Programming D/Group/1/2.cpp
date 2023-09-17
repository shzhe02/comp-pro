#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define PB push_back
#define SQ(a) (a) * (a)

void pour(vector<float> tanks, vector<float> tankVols, int col, float pourVol) {
  float pourLeft = pourVol;
  if (tankVols[col] < tanks[col]) { // Space left in tank, fill tank
    float toPour = min(0, )
    tankVols[col] 
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  vector<float> tanks;
  vector<float> tankVols;
  int col;
  float pourVol;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    float tankVol;
    cin >> tankVol;
    tanks.push_back(tankVol);
    tankVols.push_back(0);
  }
  cin >> col >> pourVol;
  col--;
  
  pour(tanks, tankVols, col, pourVol);
}
