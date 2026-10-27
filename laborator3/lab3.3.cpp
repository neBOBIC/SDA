#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k] = nums[i];
            i++;
        } else {
            temp[k] = nums[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = nums[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = nums[j];
        j++;
        k++;
    }

    for (int x = left; x <= right; x++) {
        nums[x] = temp[x];
    }
}

void mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(nums, temp, left, mid);
    mergeSort(nums, temp, mid + 1, right);

    merge(nums, temp, left, mid, right);
}

int main() {
    vector<int> nums = {6, 2, 5, 2, 1};
    vector<int> temp(nums.size());

    mergeSort(nums, temp, 0, nums.size() - 1);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}