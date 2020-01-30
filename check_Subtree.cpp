#include <cstring>
#include <iostream>
#include <map>
using namespace std;
#define MAX 1000

// Structure of a tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

bool isSubtree(Node *T, Node *S);

void storeInorder(Node *, char[], int &);

void storePreOrder(Node *, char[], int &);

// Driver program to test above function
int main() {
    int t;

    scanf("%d", &t);
    while (t--) {
        struct Node *child = NULL;
        map<int, Node *> m;
        int n;
        scanf(" %d\n", &n);
        struct Node *t2 = NULL;
        while (n--) {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);

            if (m.find(n1) == m.end()) {
                parent = new Node(n1);
                m[n1] = parent;
                if (t2 == NULL) t2 = parent;
            } else
                parent = m[n1];
            child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        struct Node *child1;
        map<int, Node *> m1;
        int nodes;
        scanf("%d\n", &nodes);
        struct Node *t1 = NULL;
        while (nodes--) {
            Node *parent1;
            char lr1;
            int n3, n4;
            scanf("%d %d %c", &n3, &n4, &lr1);
            if (m1.find(n3) == m1.end()) {
                parent1 = new Node(n3);
                m1[n3] = parent1;
                if (t1 == NULL) t1 = parent1;
            } else
                parent1 = m1[n3];

            child = new Node(n4);
            if (lr1 == 'L')
                parent1->left = child;
            else
                parent1->right = child;
            m1[n4] = child;
        }

        cout << isSubtree(t1, t2);
        cout << endl;
    }
}// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
bool exactSubtree(Node* T1,Node* T2) {
if(T1 == NULL && T2 == NULL) {
return true;
}
if(T2 == NULL || T1 == NULL) {
return false;
}
if(T1 -> data == T2 -> data) {
return exactSubtree(T1 -> right,T2 -> right) && exactSubtree(T1 -> left,T2 -> left);
}
return false;
}


bool isSubtree(Node* T1, Node* T2) {
if(T1 == NULL && T2 == NULL) {
return true;
}
if(T2 == NULL || T1 == NULL) {
return false;
}
return exactSubtree(T1,T2) || isSubtree(T1 -> right,T2) || isSubtree(T1 -> left,T2);
}