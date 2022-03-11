#include <iostream>
#include <vector> 

using namespace std;

class Solution {
public:
    int search1(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // ����target������ұյ������[left, right]
        while (left <= right) { // ��left==right������[left, right]��Ȼ��Ч�������� <=
            int middle = left + ((right - left) >> 1);// ��ֹ��� ��ͬ��(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target �������䣬����[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target �������䣬����[middle + 1, right]
            } else { // nums[middle] == target
                return middle; // �������ҵ�Ŀ��ֵ��ֱ�ӷ����±�
            }
        }
        // δ�ҵ�Ŀ��ֵ
        return -1;
    }

    int search2(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); // ����target������ҿ������������[left, right)
        while (left < right) { // ��Ϊleft == right��ʱ����[left, right)����Ч�Ŀռ䣬����ʹ�� <
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle; // target �������䣬��[left, middle)��
            } else if (nums[middle] < target) {
                left = middle + 1; // target �������䣬��[middle + 1, right)��
            } else { // nums[middle] == target
                return middle; // �������ҵ�Ŀ��ֵ��ֱ�ӷ����±�
            }
        }
        // δ�ҵ�Ŀ��ֵ
        return -1;
    }
};

int main() {
    Solution soultionWay;
    vector<int>test;
    int arrayTest[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++) {
        test.push_back(arrayTest[i]);
    }
    int target = soultionWay.search1(test, 4);
    cout << target << endl;
    system( "pause" );
}