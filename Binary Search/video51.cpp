#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> a, int n) {
    int low = 0;
    int high = n - 1;
    int mini = INT_MAX;
    int ans = 0;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        // If the subarray is already sorted
        if (a[low] < a[high]) {
            if (a[low] < mini) {
                mini = a[low];
                ans = low;
            }
            break;
        }

        // If mid element is less than high element, search in left half
        if (a[mid] < a[high]) {
            if (a[mid] < mini) {
                mini = a[mid];
                ans = mid;
            }
            high = mid - 1;
        } 
        // If mid element is greater than or equal to high element, search in right half
        else {
            if (a[low] < mini) {
                mini = a[low];
                ans = low;
            }
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> a = {8, 9, 1, 2, 3, 4, 5, 6, 7};
    cout << findKRotation(a, a.size());
    
    return 0;
}
