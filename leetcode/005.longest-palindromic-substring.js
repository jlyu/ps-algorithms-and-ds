/*
Given a string s, find the longest palindromic substring in s.
You may assume that the maximum length of s is 1000.

Example 1:

    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.


Example 2:

    Input: "cbbd"
    Output: "bb"
*/



var longestPalindrome = function(s) {
    if (s.length <= 1) { return s; }
    if (s.length >1000) { return; }

    var stringExpand = function(left, right) {
        while (left >= 0 && right < s.length && s[left] === s[right]) {
            left--;
            right++;
        }
        return s.slice(left+1, right);
    };

    var longest = s[0], t;

    for(var i = 0, l = s.length; i < l; i++) {
        t = stringExpand(i, i);
        if (t.length > longest.length) { longest = t; }
        t = stringExpand(i, i + 1);
        if (t.length > longest.length) { longest = t; }
    }
    return longest;
}
