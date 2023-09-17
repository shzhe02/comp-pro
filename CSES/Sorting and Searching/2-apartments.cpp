#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> applicants;
  vector<int> apartments;
  while (n--) {
    int applicant;
    cin >> applicant;
    applicants.push_back(applicant);
  }
  while (m--) {
    int apartment;
    cin >> apartment;
    apartments.push_back(apartment);
  }
  sort(applicants.begin(), applicants.end());
  sort(apartments.begin(), apartments.end());
  int applicantCursor = applicants.size() - 1;
  int apartmentCursor = apartments.size() - 1;
  int count = 0;
  while (apartmentCursor >= 0 && applicantCursor >= 0) {
    int apartment = apartments[apartmentCursor];
    int applicant = applicants[applicantCursor];
    if (applicant > apartment + k) {
      applicantCursor--;
    } else if (applicant < apartment - k) {
      apartmentCursor--;
    } else {
      count++;
      applicantCursor--;
      apartmentCursor--;
    }
  }
  cout << count;
}
