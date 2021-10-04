https://leetcode.com/problems/sort-list/


ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == NULL)
        return head;
    ListNode *fast = head->next->next, *slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *r = sortList(slow->next);
    slow->next = NULL;
    ListNode *l = sortList(head);
    return merge(l, r);
}

ListNode *merge(ListNode *l, ListNode *r) {
    ListNode *dummy = new ListNode(0), *node;
    node = dummy;
    while (l && r) {
        if (l->val < r->val) {
            node->next = l;
            l = l->next;
        } else {
            node->next = r;
            r = r->next;
        }
        node = node->next;
    }
    if (l)
        node->next = l;
    else 
        node->next = r;
    return dummy->next;
}
/***********************************************/
class Solution {
public:
    ListNode* merge(ListNode* h1, ListNode* h2){
        if(!h1)
            return h2;
        if(!h2)
            return h1;
        ListNode* h = new ListNode(0);
        ListNode* t = h;
        while(h1 && h2){
            if(h1->val <= h2->val){
                h->next = new ListNode(h1->val);
                h = h->next;
                h1 = h1->next;
            }
            else{
                h->next = new ListNode(h2->val);
                h = h->next;
                h2 = h2->next;
            }
        }
        while(h1){
            h->next = new ListNode(h1->val);
            h = h->next;
            h1 = h1->next;
        }
        while(h2){
            h->next = new ListNode(h2->val);
            h = h->next;
            h2 = h2->next;
        }
        t = t->next;
        return t;
    }
    ListNode* sortList(ListNode* head) {
        if(!head)
            return head;
        int c = 0;
        ListNode* p = head;
        while(p){
            c++;
            p = p->next;
        }
        if(c == 1)
            return head;
        c = c/2;
        ListNode* t = head;
        int count = 0;

        while(count < c - 1){
            count++;
            t = t->next;
        }
        ListNode* u = t->next;
        t->next = NULL;
        ListNode* h1 = sortList(head);
        ListNode* h2 = sortList(u);
        return merge(h1, h2);
    }
};
