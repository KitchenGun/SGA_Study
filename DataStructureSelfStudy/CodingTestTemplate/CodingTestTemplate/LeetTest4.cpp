#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
   
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        Traversal(root);
        return result;
    }

    void Traversal(TreeNode* root)
    {
        result.push_back(root->val);

        if (root->left != nullptr)
        {
            Traversal(root->left);
        }
        if (root->right != nullptr)
        {
            Traversal(root->right);
        }
    }

    vector<int> result;
};

int main()
{
    Solution* sol = new Solution;
    TreeNode* root = new TreeNode(1,nullptr,new TreeNode(2,new TreeNode(3,nullptr,nullptr),nullptr));

    sol->inorderTraversal(root);

    for (int a :sol->result)
    {
        cout << a << " ";
    }


}