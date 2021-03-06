#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* buildTree(string str)  {
    if(str.length() == 0 || str[0] == 'N')
            return NULL;

    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        if(currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        if(currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool isBalanced(Node *root);

int main() {
    string s;
	getline(cin,s);
    Node* root = buildTree(s);
    cout << isBalanced(root) << endl;
}

int height(Node* node) {
    if(node == nullptr) return 0;
    int h = 1 + max(height(node->left), height(node->right));
    return h;
}

bool func(Node* node) {
    if(node == nullptr) return true;
    bool b = true;
    int t = abs(height(node->left) - height(node->right));
    if(t > 1) return false;
    return true;
}


bool isBalanced(Node *root) {
    if(!root) return true;
    bool b =  func(root) && isBalanced(root->left) && isBalanced(root->right);
    return b;
}
