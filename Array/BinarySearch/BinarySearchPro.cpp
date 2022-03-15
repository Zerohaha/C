#include <iostream>
#include <vector> 

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        // ���һ
        if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
        // �����
        if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};
        // �����
        return {-1, -1};
    }
private:
     int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2; // ��¼һ��rightBorderû�б���ֵ�����
        while (left <= right) {
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle - 1;
            } else { // Ѱ���ұ߽磬nums[middle] == target��ʱ�����left
                left = middle + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2; // ��¼һ��leftBorderû�б���ֵ�����
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] >= target) { // Ѱ����߽磬nums[middle] == target��ʱ�����right
                right = middle - 1;
                leftBorder = right;
            } else {
                left = middle + 1;
            }
        }
        return leftBorder;
    }
};

int main() {
    Solution soultionWay;
    vector<int>test;
    int arrayTest[10] = {1, 2, 3, 5, 5, 5, 5, 8, 9, 10};
    for (int i = 0; i < 10; i++) {
        test.push_back(arrayTest[i]);
    }
    vector<int> target = soultionWay.searchRange(test, 5);
    for (const auto& i : target)
        cout << i << ' ';
    system( "pause" );
}