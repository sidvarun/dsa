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
// 5. Longest Palindromic Substring - https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
    public String longestPalindrome(String s) {
        if(s == null || s.length() < 1) 
            return "";
        int start = 0;
        int end = 0;
        for(int i = 0; i<s.length(); i++){
            int len1 = solve(s, i, i);
            int len2 = solve(s, i, i+1);
            int len = Math.max(len1, len2);
            if(len > end - start){
                start = i - ((len - 1) / 2);
                end = i + (len / 2);
            }
        }
        return s.substring(start, end + 1);
    }
    public int solve(String s, int left, int right){
        if(s == null || left > right)
            return 0;
        while(left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)){
            left--;
            right++;
        }
        return right - left - 1;
    }
}
/*******************************************************************************************************/
// Longest Palindrome in a String  - https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1#
class Solution {
    public String longestPalin(String s) {
        if(s == null || s.length() < 2) 
            return s;
        int start = 0;
        int end = 0;
        for(int i = 0; i<s.length(); i++){
            int len1 = solve(s, i, i);
            int len2 = solve(s, i, i+1);
            int len = Math.max(len1, len2);
            if(len > end - start + 1){
                start = i - ((len - 1) / 2);
                end = i + (len / 2);
            }
        }
        return s.substring(start, end + 1);
    }
    public int solve(String s, int left, int right){
        if(s == null || left > right)
            return 0;
        while(left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)){
            left--;
            right++;
        }
        return right - left - 1;
    }
}
/********************************************************************************************************/
// 7. Reverse Integer - https://leetcode.com/problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        long int ans = 0;
        while(x != 0)
        {
            ans = (ans * 10) + (x % 10);
            x = x/10;
        }
        if(ans > INT_MAX || ans < INT_MIN)
        {
            return 0;
        }
        return ans;
    }
};
/*********************************************************************************************************/
// 11. Container With Most Water - https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() - 1;
        int left = 0;
        int right = n;
        int res = INT_MIN;
        while(left < right){
            res = max(res, min(height[left], height[right]) * (right - left));
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return res;
    }
};
// Explanation for moving the smaller of the 2
/*
    I found a lot of the discussion and proof about this quite opaque, but one thing helped it finally clicked for me (which is sort of proof by contradiction i guess)
    You have two heights H_left and H_right, and H_right < H_left, then we know we have two choices, we want to move one of them. 
    If we move the larger one, we cannot increase the height for the simple reason that we are always limited by the shortest,
    and we would be decreasing j-i, the width as well.
    To clarify: let's say we kept the shortest forever, what would happen? 
    Well, j-i would decrease, and either we come across a taller block, which doesn't matter because our shorter one we kept only mattered,
    or we find a shorter one, in which case that one matters.
    Either way we end up with a smaller area, so we must move the shorter one because moving the larger one cannot give an increase in area.
*/
/***********************************************************************************/
// 13. Roman to Integer - https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char, int> m = { { 'I' , 1 },
                                       { 'V' , 5 },
                                       { 'X' , 10 },
                                       { 'L' , 50 },
                                       { 'C' , 100 },
                                       { 'D' , 500 },
                                       { 'M' , 1000 } 
                                    };
        int sum = m[s[n-1]];
        for(int i = n - 2; i>=0; i--){
            if(m[s[i]] < m[s[i+1]])
                sum -= m[s[i]];
            else
                sum += m[s[i]];
        }
        return sum;
    }
};
/**********************************************************************************/
// 12. Integer to Roman - https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string  str[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int i = 0; i<13; i++){
            while(num >= value[i]){
                num = num - value[i];
                res += str[i];
            }
        }
        return res;
    }
};
/****************************************************************************/
// 14. Longest Common Prefix - https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        int res = 0;
        if(strs.size() == 1)
            return strs[0];
        while(true){
            int j;
            for(j = 0; j<strs.size() - 1; j++){
                if(i == strs[j].size() || i == strs[j+1].size() || strs[j][i] != strs[j+1][i])
                    break;
            }
            if(j != strs.size() - 1)
                break;
            else 
                res++;
            i++;
        }
        return strs[0].substr(0, res);    
    }
};
/***********************************************************************/
// 15. 3Sum - https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0)
            return res; 
        sort(nums.begin(), nums.end());
      
        for(int i = 0; i<nums.size() - 1; i++){
            int front = i + 1;
            int back = nums.size() - 1;
            int sum = nums[i] * -1;
            while(front < back){
                if(nums[front] + nums[back] < sum)
                    front++;
                else if(nums[front] + nums[back] > sum)
                    back--;
                else{
                    vector<int> v = {nums[i], nums[front], nums[back]};
                    res.push_back(v);
                    while(front < back && nums[back] == v[2])
                        back--;
                    while(front < back && nums[front] == v[1])
                        front++;
                }
            }
            while(i + 1 < nums.size() && nums[i+1] == nums[i])
                i++;
        }
        return res;
    }
};
/*************************************************************************/
// 17. Letter Combinations of a Phone Number - https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        queue<string> q;
        string ref[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if(digits == "")
            return res;
        q.push("");
        for(int i = 0; i<digits.length(); i++){
            int c = q.size();
            string str = ref[digits[i] - '0'];
            while(c--){
                string sub = q.front();
                q.pop();
                for(int j = 0; j<str.length(); j++)
                    q.push(sub + str[j]);
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
/*********************************************************************************/
// 19. Remove Nth Node From End of List - https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        if(head == NULL)
            return head;
        int count = 0;
        while(curr){
            count++;
            curr = curr->next;
        }
        int k = count - n - 1;
        ListNode* curr1 = head;
        if(k == -1){
            head = head->next;
            return head;
        }
        while(k-- && curr1){
            curr1 = curr1->next;
        }
        if(curr1->next)
            curr1->next = curr1->next->next;
        else
            curr1->next = NULL;
        return head;
    }
};
/*
A one pass solution can be done using pointers. Move one pointer fast --> n+1 places forward, 
to maintain a gap of n between the two pointers and then move both at the same speed. 
Finally, when the fast pointer reaches the end, the slow pointer will be n+1 places behind - just the right spot for it to be able to skip the next node.
Since the question gives that n is valid, not too many checks have to be put in place. Otherwise, this would be necessary.
*/
/*************************************************************************************/
// 20. Valid Parentheses - https://leetcode.com/problems/valid-parentheses/
public boolean isValid(String s) {
	Stack<Character> stack = new Stack<Character>();
	for (char c : s.toCharArray()) {
		if (c == '(')
			stack.push(')');
		else if (c == '{')
			stack.push('}');
		else if (c == '[')
			stack.push(']');
		else if (stack.isEmpty() || stack.pop() != c)
			return false;
	}
	return stack.isEmpty();
}
/*********************************************************************************/
// 21. Merge Two Sorted Lists - https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val > l2->val)
            return mergeTwoLists(l2, l1);
        ListNode* curr = l1;
        ListNode* curr1 = l1->next;
        ListNode* curr2 = l2;
        while(curr1 && curr2){
            if(curr1->val > curr2->val){
                curr->next = curr2;
                curr2 = curr2->next;
            }
            else{
                curr->next = curr1;
                curr1 = curr1->next;
            }
            curr = curr->next;
        }
        if(curr1)
            curr->next = curr1;
        if(curr2)
            curr->next = curr2;
        return l1;
    }
};
/**************************************************************************************/
// 22. Generate Parentheses - https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
    void backTrack(vector<string> &res, string s, int open, int close, int n){
        if(s.length() == n * 2){
            res.push_back(s);
            return;
        }
        if(open < n)
            backTrack(res, s + "(", open + 1, close, n);
        if(close < open)
            backTrack(res, s + ")", open, close + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backTrack(res, "", 0, 0, n);
        return res;
    }
};
/************************************************************************************/
// 23. Merge k Sorted Lists - https://leetcode.com/problems/merge-k-sorted-lists/
class Solution {
public:
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val > l2->val)
            return mergeTwoLists(l2, l1);
        ListNode* curr = l1;
        ListNode* curr1 = l1->next;
        ListNode* curr2 = l2;
        while(curr1 && curr2){
            if(curr1->val > curr2->val){
                curr->next = curr2;
                curr2 = curr2->next;
            }
            else{
                curr->next = curr1;
                curr1 = curr1->next;
            }
            curr = curr->next;
        }
        if(curr1)
            curr->next = curr1;
        if(curr2)
            curr->next = curr2;
        return l1;
    }
        
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* head = NULL;
        if(n == 0)
            return head;
        if(n == 1)
            return lists[0];
        head = lists[0];
        for(int i = 1; i<n; i++){
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
};
/*********************************************************************************/
// 26. Remove Duplicates from Sorted Array - https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for(int i = 0; i<nums.size(); ){
            nums[index++] = nums[i];
            while(i < nums.size() && nums[i] == nums[index - 1])
                i++;
        }
        return index;
    }
};
/******************************************************************************/