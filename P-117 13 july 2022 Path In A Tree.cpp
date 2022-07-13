// striver SDE sheet challange Path In A Tree
// author Vishwas Paikra
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

void traverse(vector<int> &ans, TreeNode<int> *root, int x) {
    if(!root || ans.size() && ans[ans.size()-1] == x) return;
    ans.push_back(root->data);
    if(ans[ans.size()-1] == x) return;
    traverse(ans, root->left, x);
    if(ans[ans.size()-1] == x) return;
    traverse(ans, root->right, x);
    if(ans[ans.size()-1] == x) return;
    ans.pop_back();
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    traverse(ans, root, x);
    return ans;
}

// using a stack

#include<bits/stdc++.h>
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    stack<TreeNode<int> *> stk;
    while(!stk.empty() || root) {
        if(root) {
            stk.push(root);
            ans.push_back(root->data);
            if(ans[ans.size()-1] == x) return ans;
            root = root->left;
        } else {
            root = stk.top();
            while(root->data != ans[ans.size()-1])
                ans.pop_back();
            stk.pop();
            root = root->right;
        }
    }
    return ans;
}

