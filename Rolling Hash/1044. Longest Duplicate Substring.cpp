#define ULL unsigned long long

class Solution {
public:
	//enumerate each length of the string
    int check(const string &s, int len, ULL power) {
        unordered_set<ULL> seen;
        int n = s.length();

		//hash substring which length is equal to len into digital number
		// hash("ab") = 'a' + 'b' *131 = 97 + 98 *131 = 12935
        ULL hash = 0;
        for (int i = 0; i < len; i++)
            hash = hash * 131 + s[i];

		//store the hash code
        seen.insert(hash);
		
		//hash each substring which length is equal to len
		//for example string "abababab", len = 2
		//hash(s[0:2]) = hash("ab")  = 12935 it's not exist in seen, put 12936 in seen
		//hash(s[1:3]) = hash("ba") = 12805 it's not exist in seen, put 12805 in seen
		//hash(s[2:4]) = hash("ab") = 12935 it's exist in seen, return the index of this substring, return 2
        for (int i = len; i < n; i++) {
            hash = hash - power * s[i - len];
            hash = hash * 131 + s[i];
			//if we find the hash code is exist, return the index
            if (seen.find(hash) != seen.end())
                return i - len + 1;

            seen.insert(hash);
        }
		
		// otherwise return -1
        return -1;
    }

    string longestDupSubstring(string S) {
        int n = S.length();
        
		//initize the power of 131, for example, power = {131^0, 131^1, 131^2...}
        vector<ULL> power(n, 1);
        for (int i = 1; i < n; i++){
            power[i] = power[i - 1] * 131;
        }
		
		//binary search , enumerate each length of the string
		int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
			// if there is no duplicate in the length of len we Shrink length
            if (check(S, mid + 1, power[mid]) == -1)
                r = mid;
            else
                l = mid + 1; // otherwise increase length
        }

        if (l == 0)
            return "";

        return S.substr(check(S, l, power[l - 1]), l);
    }
};#define ULL unsigned long long

class Solution {
public:
	//enumerate each length of the string
    int check(const string &s, int len, ULL power) {
        unordered_set<ULL> seen;
        int n = s.length();

		//hash substring which length is equal to len into digital number
		// hash("ab") = 'a' + 'b' *131 = 97 + 98 *131 = 12935
        ULL hash = 0;
        for (int i = 0; i < len; i++)
            hash = hash * 131 + s[i];

		//store the hash code
        seen.insert(hash);
		
		//hash each substring which length is equal to len
		//for example string "abababab", len = 2
		//hash(s[0:2]) = hash("ab")  = 12935 it's not exist in seen, put 12936 in seen
		//hash(s[1:3]) = hash("ba") = 12805 it's not exist in seen, put 12805 in seen
		//hash(s[2:4]) = hash("ab") = 12935 it's exist in seen, return the index of this substring, return 2
        for (int i = len; i < n; i++) {
            hash = hash - power * s[i - len];
            hash = hash * 131 + s[i];
			//if we find the hash code is exist, return the index
            if (seen.find(hash) != seen.end())
                return i - len + 1;

            seen.insert(hash);
        }
		
		// otherwise return -1
        return -1;
    }

    string longestDupSubstring(string S) {
        int n = S.length();
        
		//initize the power of 131, for example, power = {131^0, 131^1, 131^2...}
        vector<ULL> power(n, 1);
        for (int i = 1; i < n; i++){
            power[i] = power[i - 1] * 131;
        }
		
		//binary search , enumerate each length of the string
		int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
			// if there is no duplicate in the length of len we Shrink length
            if (check(S, mid + 1, power[mid]) == -1)
                r = mid;
            else
                l = mid + 1; // otherwise increase length
        }

        if (l == 0)
            return "";

        return S.substr(check(S, l, power[l - 1]), l);
    }
};