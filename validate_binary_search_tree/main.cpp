#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

namespace test
{

TreeNode* createValidBST() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(6);
    return root;
}

TreeNode* createInvalidTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(6);
    return root;
}

TreeNode* createInvalidTree2()
{
    TreeNode* root = new TreeNode(120);
    root->left = new TreeNode(70);
    root->right = new TreeNode(140);
    root->left->left = new TreeNode(50);
    root->left->right = new TreeNode(100);
    root->right->left = new TreeNode(130);
    root->right->right = new TreeNode(160);
    root->left->left->left = new TreeNode(20);
    root->left->left->right = new TreeNode(55);
    root->left->right->left = new TreeNode(75);
    root->left->right->right = new TreeNode(110);
    root->right->left->left = new TreeNode(119);
    root->right->left->right = new TreeNode(135);
    root->right->right->left = new TreeNode(150);
    root->right->right->right = new TreeNode(200);
    
    return root;
}

} // namespace test


class Solution {
public:

    int biggestValue(TreeNode* root)
    {
        if(root->left == nullptr && root->right == nullptr) return root->val;
        vector<int> values = {root->val};
        if(root->left != nullptr) values.push_back(biggestValue(root->left));
        if(root->right != nullptr) values.push_back(biggestValue(root->right));

        return *max_element(values.begin(), values.end());
    }

    int smallestValue(TreeNode* root)
    {
        if(root->left == nullptr && root->right == nullptr) return root->val;
        vector<int> values = {root->val};
        if(root->left != nullptr) values.push_back(smallestValue(root->left));
        if(root->right != nullptr) values.push_back(smallestValue(root->right));

        return *min_element(values.begin(), values.end());
    }

    bool isValidBST(TreeNode* root) {
        if(root->left == nullptr and root->right == nullptr) return true;
        if(root->left != nullptr and (biggestValue(root->left) >= root->val or not isValidBST(root->left))) return false;
        if(root->right != nullptr and (smallestValue(root->right) <= root->val or not isValidBST(root->right))) return false;

        return true;
    }
};

int main()
{
    TreeNode* validTree = test::createValidBST();
    TreeNode* invalidTree = test::createInvalidTree();
    TreeNode* invalidTree2 = test::createInvalidTree2();
    Solution sol;

    sol.isValidBST(validTree) ? cout << "Valid tree is validated\n" : cout << "ERROR: valid tree not validated\n";
    sol.isValidBST(invalidTree) ? cout << "ERROR: invalid tree validated\n" : cout << "Invalid tree not validated\n";
    sol.isValidBST(invalidTree2) ? cout << "ERROR: invalid tree validated\n" : cout << "Invalid tree not validated\n";

    return 0;
}