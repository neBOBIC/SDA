#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size();

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    cout << search(nums, target);

    return 0;
}