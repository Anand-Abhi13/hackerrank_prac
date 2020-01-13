#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

/*This is a function problem.You only need to complete the function given below*/
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/
/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* mergeSort(Node* head) {
    
for(Node* i=head;i!=NULL;i=i->next)
{
    for(Node* j=i->next;j!=NULL;j=j->next)
    {

        if(i->data>j->data)
        {
            int temp=i->data;
            i->data=j->data;
            j->data=temp;
        }
        
    
    }
}
    return head;
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
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}