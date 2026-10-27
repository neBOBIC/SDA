#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& nums, int lo, int hi) {
    int pivot = nums[lo];
    int boundary = lo;

    for (int scan = lo + 1; scan < hi; scan++) {
        if (nums[scan] < pivot) {
            boundary++;
            swap(nums[boundary], nums[scan]);
        }
    }

    swap(nums[lo], nums[boundary]);

    return boundary;
}

void quickSort(vector<int>& nums, int lo, int hi) {
    if (hi - lo <= 1) {
        return;
    }

    int p = partition(nums, lo, hi);

    quickSort(nums, lo, p);
    quickSort(nums, p + 1, hi);
}

int main() {
    vector<int> nums = {6, 2, 5, 2, 1};

    quickSort(nums, 0, nums.size());

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}