/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:
    Input: "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.

Example 2:
    Input: "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

Example 3:
    Input: "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.

Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

// Solution 1
var lengthOfLongestSubstring_v0 = function(s) {
    const map = {};
    var left = 0;

    return s.split('').reduce((max, v, i) => {
        left = map[v] >= left ? map[v] + 1 : left;
        map[v] = i;
        return Math.max(max, i - left + 1);
    }, 0);
}

// Solution 2  X
var lengthOfLongestSubstring_v1 = function(s) {
    var start = 0;
    var current = 0;
    if (s.length < 2) { return s.length; }
    var map = {};
    for (var i = 0, l = s.length; i < l; i++) {
        var tmp = ((map[ s[i] ] > -1) ? map[ s[i] ] : 0);
        var start = Math.max(start, tmp);
        var current = Math.max(current, i - start + 1);
        map[ s[i] ] = i; // update the index of char in strings
        console.log(start, tmp, current, map);
    }
    return current;
}

// Solution 3
var lengthOfLongestSubstring = function(s) {
    var start = 0;
    var maxLength = 0;
    var map = {};

    for (var i = 0, l = s.length; i < l; i++) {

        if ((map[s[i]] !== undefined) && (start <= map[s[i]]) ) {
            start = map[s[i]] + 1;
        } else {
            maxLength = Math.max(maxLength, i - start + 1);
        }
        map[ s[i] ] = i;
    }
    return maxLength;

}

console.log( lengthOfLongestSubstring("") );
console.log( lengthOfLongestSubstring(" ") );
console.log( lengthOfLongestSubstring("ok") );
console.log( lengthOfLongestSubstring("abcabcbb") );









