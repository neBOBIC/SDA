#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size();

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    return lo;
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    cout << searchInsert(nums, target);

    return 0;
}