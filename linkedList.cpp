Node *reverseK(Node *head,int k){
    Node *curr=head,*next=NULL,*prev=NULL;
    int count=0;
    while(curr!=NULL&&count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
        Node *rest_head=reverseK(next,k);
        head->next=rest_head;
    }
    return prev;
}
/*****************************************************************************************/
// Reverse a Doubly Linked List - https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1#

Node* reverseDLL(Node * head)
{
    //Your code here
    if(head == NULL || head->next == NULL)
        return head;
    Node* p = NULL;
    Node* c = head;
    Node* n = head->next;
    while(c != NULL){
        c->next = p;
        c->prev = n;
        p = c;
        c = n;
        if(n)
            n = n->next;
    }
    return p;
}
/*****************************************************************************************/
// Multiply two linked lists  - https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1#

long long int llToNumber(Node* head){
    long long int n = 0;
    Node* curr = head;
    int i = 0;
    while(curr){
        n = (n*10%1000000007+ curr->data%1000000007)%1000000007;
        curr = curr->next;
    }
    return n;
}
long long  multiplyTwoLists (Node* l1, Node* l2)
{
  long long int n1 = llToNumber(l1);
  long long int n2 = llToNumber(l2);
  return (n1%1000000007 * n2%1000000007)%1000000007;
}
/*******************************************************************************************/
// Check if Linked List is Palindrome  - https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

/* 
    Algorithm:
    Get the middle of the linked list. 
    Reverse the second half of the linked list. 
    Check if the first half and second half are identical. 
    Construct the original linked list by reversing the second half again and attaching it back to the first half
    Return 1 if list is palindrome else 0 
*/
class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverseLL(Node* head){
        if(head == NULL || head->next == NULL)
            return head;
        Node* p = NULL;
        Node* c = head;
        Node* n = head->next;
        while(c != NULL){
            c->next = p;
            p = c;
            c = n;
            if(n)
                n = n->next;
        }
        return p;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        int count = 0;
        Node* curr = head;
        while(curr){
            count++;
            curr = curr->next;
        }
        int n;
        if(count % 2 != 0)
            n = count/2;
        else
            n = count/2 - 1;
        Node* c = head;
        while(n){
            n--;
            c = c->next;
        }
        c->next = reverseLL(c->next);
        c = c->next;
        while(c){
            if(head->data != c->data)
                return false;
            head = head->next;
            c = c->next;
        }
        return true;
    }
};

