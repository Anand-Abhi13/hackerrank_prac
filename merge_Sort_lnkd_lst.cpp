#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


Node *merge(Node *h1,Node *h2)
{    if(h1==NULL)
    return h2;
    if(h2==NULL)
    return h1;
    if(h1->data<h2->data)
  { h1->next=merge(h1->next,h2);
    return h1;}
    else
  { h2->next=merge(h1,h2->next);
    return h2;}
}
Node* mergeSort(Node* h) {
    if(h==NULL || h->next==NULL)
    return h;
    Node *p=h,*q=h->next;
    while(q&&q->next)
    {p=p->next;
     q=q->next->next;}
    Node *p1=p->next;
    p->next=NULL;
    Node *c1=mergeSort(h);
    Node *c2=mergeSort(p1);
    return merge(c1,c2);
}


void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        cout<<endl;
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}
