// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
// Return the running sum of nums.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4};

    for (size_t i = 1; i < nums.size(); i++) {
        nums[i] = nums[i] + nums[i - 1];
    }

    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;
    return 0;
}
