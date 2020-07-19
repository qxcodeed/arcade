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
    int height(Node* root) {
        // Write your code here.
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 0;
        int esq = height(root->left);
        int dir = height(root->right);
        if(esq > dir) return esq+1;
        return dir+1;
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
  
    int height = myTree.height(root);
    myTree.deleter(root);
    
  	std::cout << height <<endl;

    return 0;
}