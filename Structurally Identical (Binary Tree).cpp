#include<iostream>
#include<queue>
#include<deque>
using namespace std;

class node {
public:
    int data;
    node*left;
    node*right;
    node(int d) {
        data=d;
        left=NULL;
        right=NULL;
    }
};

void bfs(node*root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* f = q.front();
        if (f == NULL) {
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
        else {
            cout << f->data << " ";
            q.pop();

            if (f->left) {
                q.push(f->left);
            }
            if (f->right) {
                q.push(f->right);
            }
        }
    }
    return;
}

node* build() {
    int d;
    cin>>d;
    node*root=new node(d);
    queue<node*> dq;
    dq.push(root);     //you were inserting in stack manner before,i have made it to queue.
                      //you were using only one end of deque.

    int cnt=0;
    while(!dq.empty()) {
        node* n1=dq.front();
        dq.pop();
        string s1;
        cin>>s1;

        int x;
        if(s1=="true") {
            cin>>x;
            node* n=new node(x);
            n1->left=n;
            dq.push(n);
        }
        string s2;
        cin>>s2;
         if(s2=="true") {
            cin>>x;
            node* n=new node(x);
            n1->right=n;
            dq.push(n);
        }
   
    }

    return root;
}

bool isIdentical(node*root1,node*root2) {
    if(root1==NULL && root2==NULL) {
        return true;
    }

    else if(root1==NULL || root2==NULL)   //added by me , if any of the root is null then you can't its access left and right child
    return false;

    bool left=isIdentical(root1->left,root2->left);
    bool right=isIdentical(root1->right,root2->right);

    if(left && right) 
        return true;

    return false;
}

int main() {
    node*root1=build();
    node*root2=build();

    isIdentical(root1,root2) ? cout<<"true" : cout<<"false";

    return 0;
}