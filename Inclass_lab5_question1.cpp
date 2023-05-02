#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>

using namespace std;

void quick_sort_nonrec(vector<int>& arr, int left, int right) {
    vector<pair<int, int>> ranges;
    ranges.push_back(make_pair(left, right));

    while (!ranges.empty()) {
        int start = ranges.back().first;
        int end = ranges.back().second;
        ranges.pop_back();

        while (start < end) {
            int pivot = arr[start];
            int i = start + 1;
            int j = end;

            while (i <= j) {
                while (i <= j && arr[i] < pivot) {
                    i++;
                }
                while (i <= j && arr[j] >= pivot) {
                    j--;
                }
                if (i <= j) {
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[start], arr[j]);

            if (j - start < end - j) {
                ranges.push_back(make_pair(start, j - 1));
                start = j + 1;
            } else {
                ranges.push_back(make_pair(j + 1, end));
                end = j - 1;
            }
        }
    }
}

void quick_sort_rec(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Choose pivot as the middle element
        int pivot = arr[(left + right) / 2];

        // Partition the array into two parts
        int i = left, j = right;
        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        // Recursively sort the two parts
        quick_sort_rec(arr, left, j);
        quick_sort_rec(arr, i, right);
    }
}

int main() {
    vector<int> arr = {43, 76, 23, 89, 11, 56, 97, 34, 65, 28, 45, 78, 8, 88, 10, 35, 55, 59, 99, 66, 71, 27, 72, 22, 81, 84, 96, 14, 31, 38, 44, 24, 83, 6, 25, 90, 79, 47, 9, 54};

    auto start_time = chrono::high_resolution_clock::now();
    quick_sort_rec(arr, 0, arr.size() - 1);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Recursive quick sort took " << duration.count() << " microseconds." << endl;

    start_time = chrono::high_resolution_clock::now();
    quick_sort_nonrec(arr, 0, arr.size() - 1);
    end_time = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Non-recursive quick sort took " << duration.count() << " microseconds." << endl;

    return 0;
}
