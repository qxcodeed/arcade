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
    void levelOrder(Node * root) {
        queue<Node*> per;
        per.push(root);
        while(!per.empty()){
            Node * no = per.front();
            per.pop();
            if(no->left!=NULL) per.push(no->left);
            if(no->right!=NULL) per.push(no->right);
            cout << no->data <<" ";
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
  
    myTree.levelOrder(root);
    myTree.deleter(root);
    cout<<endl;

    return 0;
}