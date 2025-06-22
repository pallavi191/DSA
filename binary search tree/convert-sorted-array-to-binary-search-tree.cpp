// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

class Solution {
public:
    TreeNode* arrayToBST(vector<int>& nums, int start, int end) {
        if(start > end)
        return NULL;

        int mid = start + (end - start) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root -> left = arrayToBST(nums, start, mid - 1);
        root -> right = arrayToBST(nums, mid + 1, end);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return arrayToBST(nums, 0, n-1);
    }
};
