#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // for setting precision of output

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a;
    int mid = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        sort(a.begin(), a.end()); // sort the vector in ascending order

        // print the current state of the vector
        cout << "[";
        for (int k = 0; k < a.size(); k++) {
            cout << a[k];
            if (k != a.size() - 1) cout << ",";
        }
        cout << "]  ";

        // calculate the median and print it
        if (a.size() % 2 == 0) {
            mid = a.size() / 2;
            cout << fixed << setprecision(1) << (a[mid - 1] + a[mid]) / 2.0 << endl;
        }
        else {
            mid = a.size() / 2;
            cout << fixed << setprecision(1) << a[mid] / 1.0 << endl;
        }
    }

    return 0;
}
