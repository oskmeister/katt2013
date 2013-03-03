#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr1, arr2;
    int A = 0;
    int B = 0;
    for (int i = 0; i < N; ++i) {
        int cur;
        cin >> cur;
        arr1.push_back(cur);
        A += cur;
    }
    for (int i = 0; i < N; ++i) {
        int cur ;
        cin >> cur;
        arr2.push_back(cur);
        B += cur;
    }

    sort(arr2.begin(),arr2.end());

    int minimum = 1<<30;
    for (int i = 0; i < N; ++i) {
        int diff = B + 2*arr1[i] - A;
        int look = ceil(diff/2.0);
        int pos = (lower_bound(arr2.begin(), arr2.end(),look)-arr2.begin());
        if (pos < N) {
            minimum = min(minimum, abs((B-arr2[pos]+arr1[i]) - (A-arr1[i]+arr2[pos])));
        }
        --pos;
        if (pos >= 0) {
            minimum = min(minimum, abs((B-arr2[pos]+arr1[i]) - (A-arr1[i]+arr2[pos])));
        }
    }

    cout << minimum << endl;
}
