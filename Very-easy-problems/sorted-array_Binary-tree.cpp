#include <iostream>
#include <vector>
using namespace std;

// Definition of a TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to convert a sorted array to a BST
TreeNode* sortedArrayToBST(const vector<int>& nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }

    // Choose the middle element as the root
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    // Recursively construct the left and right subtrees
    root->left = sortedArrayToBST(nums, left, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, right);

    return root;
}

// Helper function to print the BST in in-order traversal
void inorderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> nums;
    int size, element;

    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the sorted array:\n";
    for (int i = 0; i < size; i++) {
        cin >> element;
        nums.push_back(element);
    }

    TreeNode* root = sortedArrayToBST(nums, 0, nums.size() - 1);

    cout << "In-order traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
