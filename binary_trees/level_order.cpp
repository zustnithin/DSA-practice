#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <cmath>
using namespace std;
class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int data1,Node* l1,Node* r1){
        data=data1;
        left=l1;
        right=r1;
    }
    Node(int data1){
        data=data1;
        left=nullptr;
        right=nullptr;
    }
};
void levelOrder(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        cout << curr->data <<" ";
        q.pop();
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}
void it_preorder(Node* root){
    if(root==nullptr) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* curr = st.top();
        cout << curr->data <<" ";
        st.pop();
        if(curr->left!=NULL){
            st.push(curr->right);
        }
        if(curr->right!=NULL){
            st.push(curr->left);
        }
    }
}
void it_inorder(Node* root){
    stack<Node*> st;
    Node* curr = root;
    while(curr!=NULL || !st.empty()){
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        cout << curr->data << " ";
        st.pop();
        curr=curr->right;
    }

}
int maxi=0;

int max_height(Node* root){
    if(root==nullptr) return 0;
    int lh=max_height(root->left);
    int rh=max_height(root->right);
    maxi=max(maxi,lh+rh);
    if(abs(lh-rh)>1){
        return -1;
    }
    return 1+max(lh,rh);
}
bool isBalanced(Node* root){
    
    return max_height(root)!=-1;
}
int max_diameter(Node* root){
    
    return maxi;
}

int height(Node* root){
    if(root==NULL) return 0;
    
    int lh=height(root->left);
    int rh=height(root->right);
    maxi=max(maxi,root->data+lh+rh);
    return root->data+max(lh,rh);
}
int maxPathSum(Node* root){
    maxi=INT_MIN;
    height(root);
    return maxi;
}
bool isSameTree(Node* p,Node* q){
    if(p == NULL || q == NULL) return (p==q);
    return (p->data==q->data)&&(isSameTree(p->left,q->left))&&(p->right,q->right);
}
vector<vector<int>> zigzagTraversal(Node* root){
    vector<vector<int>> ans;
    if(root==nullptr) return ans;
    queue<Node*> q;
    q.push(root);
    bool LR = true;
    while(!q.empty()){
        int size=q.size();
        vector<int> row(size);
        for(int i=0;i<size;i++){
            int index;
            if(LR){
                index=i;
            }
            else{
                index=size-i-1;
            }
            Node* curr = q.front();
            q.pop();
            row[index]=curr->data;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        LR=!LR;
        ans.push_back(row);
    }
    return ans;
}
vector<int> ans;
bool isLeef(Node* root){
    return (root->left==NULL && root->right==NULL);
}
void leftBoundary(Node* root){
    Node* curr=root->left;
    while(curr){
        if(!isLeef(curr)){
            ans.push_back(curr->data);
        }
        if(curr->left){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
}
void leafNodes(Node* root){
    if(root==NULL) return;
    if(isLeef(root)){
        ans.push_back(root->data);
        return;
    }
    leafNodes(root->left);
    leafNodes(root->right);
}
void rightBoundary(Node* root){
    vector<int> temp;
    Node* curr=root->right;
    while(curr){
        if(!isLeef(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}
vector<int> boundaryTraversal(Node* root){
    if(root==NULL) return ans;
    if(!isLeef(root)){
        ans.push_back(root->data);
    }
    leftBoundary(root);
    leafNodes(root);
    rightBoundary(root);
    return ans;
}
void dfs(Node* root,int y,int x,map<int,map<int,multiset<int>>> &mp){
    if(root==NULL) return;
    mp[y][x].insert(root->data);
    dfs(root->left,y-1,x+1,mp);
    dfs(root->right,y+1,x+1,mp);
}
vector<vector<int>> verticalTraversal(Node* root){
    map<int,map<int,multiset<int>>> mp;
    dfs(root,0,0,mp);
    vector<vector<int>> ans;
    for(auto &column : mp){
        vector<int> temp;
        for(auto &row : column.second){
            for(int value : row.second){
                temp.push_back(value);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

vector<int> topView(Node* root){
    
    map<int,int> mp;
    queue<pair<Node* ,int>> q;
    q.push(make_pair(root,0));
    mp.emplace(0,root->data);
    while(!q.empty()){
        Node* curr= q.front().first;
        int y=q.front().second;
        q.pop();
        if(curr->left){
            q.push(make_pair(curr->left, y-1));

            mp.emplace(y-1,curr->left->data);
        }
        if(curr->right){
            q.push(make_pair(curr->right, y+1));
            mp.emplace(y+1,curr->right->data);
        }
    }
    vector<int> ans;
    for(auto &row : mp){
        ans.push_back(row.second);
    }
    return ans;
}
vector<int> bottomView(Node* root){
    queue<pair<Node*,int>> q;
    map<int,int> mp;
    q.push(make_pair(root,0));
    mp[0]=root->data;

    while(!q.empty()){
        Node* curr = q.front().first;
        int y=q.front().second;
        q.pop();
        if(curr->left){
            q.push(make_pair(curr->left,y-1));
            mp[y-1]=curr->left->data;
        }
        if(curr->right){
            q.push(make_pair(curr->right,y+1));
            mp[y+1]=curr->right->data;
        }
    }
    vector<int> ans;
    for(auto &row : mp){
        ans.push_back(row.second);
    }
    return ans;
}
bool mirror(Node* rootLeft,Node* rootRight){
    if(rootLeft==NULL && rootRight==NULL) return true;
    if(rootLeft==NULL || rootRight==NULL) return false;
    if(rootLeft->data!=rootRight->data) return false;
    return mirror(rootLeft->left,rootRight->right) && mirror(rootLeft->right,rootRight->left);
}
bool isSymmetric(Node* root){
    if (root==NULL) return true;
    return mirror(root->left,root->right);
    
}
void pathdfs(Node* root,vector<int> &path){
    if(root==NULL)return;
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        for(int x : path){
            cout << x << " ";
        }
    }
    pathdfs(root->left,path);
    pathdfs(root->right,path);
    path.pop_back();
}
void printPaths(Node* root){
    vector<int> path;
    pathdfs(root,path);
    
}

Node* LCA(Node* root,Node* p,Node* q){
    if(root==NULL) return root;
    if(root==p || root==q) return root;
    Node* l = LCA(root->left,p,q);
    Node* r = LCA(root->right,p,q);
    if(l && r) return root;
    if(l) return l;
    return r;
}
bool childrenSum(Node* root){
    if(root==NULL) return true;
    if(root->left && root->right){
        return (root->data==root->left->data+root->right->data)
         && childrenSum(root->left) && childrenSum(root->right);
    }
    if(root->left){
        return (root->data==root->left->data)
         && childrenSum(root->left) && childrenSum(root->right);
    }
    if(root->right){
        return (root->data==root->right->data)
         && childrenSum(root->left) && childrenSum(root->right);
    }
    else{
        return true;
    }
}
int leftHeight(Node* root){
    int h = 0;
    while(root){
        h++;
        root = root->left;
    }
    return h;
}

int rightHeight(Node* root){
    int h = 0;
    while(root){
        h++;
        root = root->right;
    }
    return h;
}

int noOfNodes(Node* root){

    if(root == NULL) return 0;

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if(lh == rh)
        return (1 << lh) - 1;

    return 1 + noOfNodes(root->left)
             + noOfNodes(root->right);
}
Node* constructPreIn(vector<int> P,vector<int> I){
    Node* root =new Node(P[0]);
    int length=I.size();
    while(length--){
        
    }
}
int main() {
    Node* root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(5);

    root->left->left = new Node(1);
    root->left->right = new Node(4);

    root->right->left = new Node(2);
    root->right->right = new Node(3);

    /*vector<int> ans= bottomView(root);
    
        for(int value :ans){
            cout << value << " ";
        }         */
    cout << childrenSum(root);
}

    
