#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    void topView(Node * root) {
      if(root==NULL)
      return;
      map<int,int> mp;
      queue<pair<Node*,int>> q;
      q.push({root,0}); 
      while(!q.empty()){
        auto p = q.front();
        Node *cur  = p.first;
        int hd = p.second;
        if(mp.find(hd)==mp.end())
        mp[hd] = cur->data;
        q.pop();
        if(cur->left)
        q.push({cur->left,hd-1});
        if(cur->right)
        q.push({cur->right,hd+1});
      }
    map<int,int>::const_iterator p = mp.begin();
  for(long unsigned int i=0;i<mp.size();i++){
      cout << p->second;
      if(i!=mp.size()-1) cout <<" ";
      p++;
    }
    }
    void deleter(Node *root){
	if(root->left != NULL){
		deleter(root->left);
	}
	if(root->right != NULL){
		deleter(root->right);
	}
	delete root;
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
    myTree.topView(root);
    myTree.deleter(root);
    cout <<endl;
    return 0;
}