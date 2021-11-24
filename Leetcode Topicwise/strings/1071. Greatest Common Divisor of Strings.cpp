https://leetcode.com/problems/greatest-common-divisor-of-strings/discuss/314698/Javascript-easy-to-understand-GCD-solution-with-explanation-(beats-97)

class Solution {
public:
    string gcdOfStrings(string str1, string str2){
        if(str1 + str2 != str2 + str1)
            return "";
        if(str1 == str2)
            return str1;
        if(str1.length() > str2.length())
            return gcdOfStrings(str1.substr(str2.length()), str2);
        else
            return gcdOfStrings(str1, str2.substr(str1.length()));
    }
};

/*
This solution is based on the Euclidean algorithm

First, let's talk about how we obtain the greatest common divisor (GCD) from numbers. Let's say you have two numbers 252 and 105, and you want to find the GCD of both numbers (which is 21).

Via the Euclidean algorithm, we know that the GCD of 252 and 105 is the same as the GCD of 252 - 105 (which is 147) and 105. In other words: 252, 105, and 147 are all multiples of 21. This can be observed from the fact that 252 = 21 * 12 and 105 = 21 * 5.

In simpler terms, if we subtract an arbitrary multiple of 21 from either 252 or 105, we know the resulting number will still be a multiple of 21.

Lets look at some examples.
105 - (21 * 3) = 42, which is still a multiple of 21.
105 - (21 * 1) = 84, which is still a multiple of 21.
252 - (21 * 5) = 126, which is still a multiple of 21.
252 - (21 * 8) = 84, which is still a multiple of 21.

Therefore in plain English, we can obtain the GCD of two numbers by recursively calculating the GCD of two variables:

The result of the larger number subtracted by the smaller number, and
The smaller number
When the two variables are equal, we have obtained the GCD.

Confused? Let's look at an example. Using the above logic, we can calculate the GCD of 252 and 105 as follows:

GCD(252, 105) is equivalent to:

GCD of 252 - 105 (= 147) and 105
GCD of 147 - 105 (= 42) and 105
GCD of 105 - 42 (= 63) and 42
GCD of 63 - 42 (= 21) and 42
GCD of 42 - 21 (= 21) and 21
GCD of 21 and 21, which is final answer: 21
Applying this same logic for strings, we get the following code:

var gcdOfStrings = function(str1, str2) {
    if (str1 + str2 != str2 + str1){ // Check whether or not a GCD is possible, first
        return "";
    } else if (str1 == str2){
        return str1;
    } else if (str1.length > str2.length){
        return gcdOfStrings(str1.slice(str2.length), str2);
    } else {
        return gcdOfStrings(str2.slice(str1.length), str1);
    }
};
*/