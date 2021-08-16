// 2. Add Two Numbers - https://leetcode.com/problems/add-two-numbers/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        // ListNode* curr1 = l1;
        // ListNode* curr2 = l2;
        ListNode* head = new ListNode((l1->val + l2->val)%10);
        ListNode* curr = head;
        carry = (l1->val + l2->val)/10;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 && l2){
            int sum = 0;
            sum = (l1->val + l2->val + carry);
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            l1 = l1->next;
            l2 = l2->next;
            curr = curr->next;
        }
        while(l1){
            int sum = 0;
            sum = (l1->val + carry);
            curr->next = new ListNode(sum%10);
            carry = sum/10;
            l1 = l1->next;
            curr = curr->next;
        }
        while(l2){
            int sum = 0;
            sum = (l2->val + carry);
            curr->next = new ListNode(sum%10);
            carry = sum/10;
            l2 = l2->next;
            curr = curr->next;
        }
        while(carry){
            curr->next = new ListNode(carry%10);
            carry = carry/10;
            curr = curr->next;
        }
        return head;
    }
};
// Discussion 
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}
/*******************************************************************************/
// 3. Longest Substring Without Repeating Characters - https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int l = 0;
        int r = 0;
        int n = s.length();
        map<char, int> m;
        for(int r = 0; r<n; r++){
            if(m.find(s[r]) != m.end())
                l = max(m[s[r]] + 1, l); // Explained Below
            m[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
/*
 Because (j) here represents the start index of our string.
 (i) is the pointer that traverses the whole string. 
 Say we find s.charAt(i) is already in the map, case 1: its index < j, 
 then our start index should still be j because it is no longer included in the
 calculation of the length of the string; case 2: index >= j, then our start index should be (index + 1).
 Try running this simple input "abba" you will come to know.
*/
/**************************************************************************************************/
// 4. Median of Two Sorted Arrays - https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size())
            return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int l = 0;
        int r = n1;
        while(l <= r){
            int cut1 = (l + r) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            if(l1<=r2 && l2<=r1){
                if((n1 + n2) % 2 == 0)
                    return ((max(l1, l2) + min(r1, r2)) / 2.0);
                else
                    return max(l1, l2);
            }
            else if(l1 > r2)
                r = cut1 - 1;
            else
                l = cut1 + 1;
        }
        return 0.0;
    }
};
/*****************************************************************************/