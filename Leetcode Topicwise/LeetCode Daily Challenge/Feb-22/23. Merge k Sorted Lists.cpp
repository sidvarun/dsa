/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge2Lists(ListNode* h1, ListNode* h2){
        if(h1 == NULL)
            return h2;
        if(h2 == NULL)
            return h1;
        
        if(h1->val > h2->val){
            ListNode* temp = h1;
            h1 = h2;
            h2 = temp;
        }
        ListNode* newHead = h1;
        h1 = h1->next;
        ListNode* p = newHead;
        while(h1 && h2){
            if(h1->val <= h2->val){
                p->next = h1;
                h1 = h1->next;
            }
            else{
                p->next = h2;
                h2 = h2->next;
            }
            p = p->next;
        }
        
        while(h1){
            p->next = h1;
            h1 = h1->next;
            p = p->next;
        }
        
        while(h2){
            p->next = h2;
            h2 = h2->next;
            p = p->next;
        }
        return newHead;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        if(lists.size() == 1)
            return lists[0];
        
        ListNode* h1 = lists[0];
        ListNode* h2 = lists[1];
        int i = 2;
        while(i <= lists.size()){
            h1 = merge2Lists(h1, h2);
            h2 = lists[i];
            i++;
        }
        
        return h1;
    }
};