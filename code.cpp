//Right View

vector<int> printRightView(BinaryTreeNode<int>* root) {
    // Write your code here.
    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    vector<int> ans;
    if(!root)return ans;
    while(!q.empty()){
        int size=q.size();
        int curr=-1;
        while (size--) {
          BinaryTreeNode<int> *node = q.front();
          q.pop();
          curr=node->data;
          if (node->left)
            q.push(node->left);
          if (node->right)
            q.push(node->right);
        }
        ans.push_back(curr);
    }
    return ans;
}
