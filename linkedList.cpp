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
/****************************************************************/
// Clone a linked list with next and random pointer - https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1#
class Solution
{
    public:
    Node *copyList(Node *head){
        //Write your code here
        if(!head)
            return NULL;
        Node* curr = head;
        while(curr){
            Node* temp = new Node(curr->data);
            temp->next = curr->next;
            curr->next = temp;
            curr = curr->next->next;
        }
        Node* c = head;
        while(c){
            if(c->arb)
                c->next->arb = c->arb->next;
            else 
                c->next->arb =NULL;
            c = c->next->next;
        }
        Node* original = head, *copy = head->next; 
  
        Node* temp = copy; 
      
        while (original && copy) { 
            original->next = original->next? original->next->next : original->next; 
      
            copy->next = copy->next?copy->next->next:copy->next; 
            original = original->next; 
            copy = copy->next; 
        } 
        return temp;   
    }

};

/*******************************************************************************************************/

// LRU Cache - https://practice.geeksforgeeks.org/problems/lru-cache/1#
class LRUCache
{
    public:
    list<pair<int,int>> dq;
    unordered_map<int, list<pair<int,int>> :: iterator> ma; 
    int maxSize;
    LRUCache(int N){
        maxSize = N;
        dq.clear();
        ma.clear();
    }
    void set(int x, int y) 
    {
        if(ma.find(x) == ma.end())
        {
           if(dq.size() == maxSize)
           {
               int Lx = dq.back().first;
               int Ly = dq.back().second;
               dq.pop_back();
               dq.push_front({x,y});
               ma.erase(Lx);
               ma[x] =dq.begin();
           }
           else{
               dq.push_front({x,y});
          
                ma[x] = dq.begin();
           }
        }
        else{
            auto it = ma.find(x);
            dq.erase(it->second);
            dq.push_front({x,y});
       
            ma[x]=dq.begin();
        }
    }
    int get(int x)
    {
        if(ma.find(x) == ma.end())
        {
            return -1;
        }
        auto it = ma.find(x);
        int d  = (*(it->second)).second;
        dq.erase(it->second);
        dq.push_front({x,d});
        ma[x] = dq.begin();
        return d;
    }
};
/**************************************************************************/
// Merge two sorted linked lists  - https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    if(!head1){
        head1 = head2;
        return head1;
    }
    if(!head2)
        return head1;
    Node* head;
    Node* tail;
    Node* a = head1;
    Node* b = head2;
    if(head1->data <= head2->data){
        head = head1;
        tail = head1;
        a = a->next;
    }
    else{
        head = head2;
        tail = head2;
        b = b->next;
    }
    while(a && b){
        if(b->data < a->data){
            tail->next = b;
            tail = b;
            b = b->next;
        }
        else{
            tail->next = a;
            tail = a;
            a = a->next;
        }
        
    }
    if(a == NULL)
        tail->next = b;
    else
        tail->next = a;
    return head;
}  
/*********************************************************************************/
// Pairwise swap elements of a linked list  - https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1#
class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        if(head==NULL||head->next==NULL)
            return head;
        Node *curr=head->next->next;
        Node *prev=head;
        head=head->next;
        head->next=prev;
        while(curr!=NULL&&curr->next!=NULL){
            prev->next=curr->next;
            prev=curr;
            Node *next=curr->next->next;
            curr->next->next=curr;
            curr=next;
        }
        prev->next=curr;
        return head;
    }
};
/********************************************************************************/
// Intersection Point in Y Shapped Linked Lists  - https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

int intersectPoint(Node* head1, Node* head2){
    // Your Code Here
    int c1 = 0;
    int c2 = 0;
    Node* curr1 = head1;
    Node* curr2 = head2;
    while(curr1){
        c1++;
        curr1 = curr1->next;
    }
    while(curr2){
        c2++;
        curr2 = curr2->next;
    }
    int d = abs(c1 - c2);
    curr1 = head1;
    curr2 = head2;
    if(c1>c2){
        while(d>0 && curr1){
            curr1 = curr1->next;
            d--;
        }
    }
    else{
        while(d>0 && curr2){
            curr2 = curr2->next;
            d--;
        }
    }
    while(curr1->next && curr2->next){
        if(curr1->next == curr2->next)
            return curr1->next->data;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return -1;
}
/*********************************************************************************/


