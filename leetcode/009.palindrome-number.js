/*
Determine whether an integer is a palindrome.
An integer is a palindrome when it reads the same backward as forward.

Example 1:

    Input: 121
    Output: true

Example 2:

    Input: -121
    Output: false

Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.


Example 3:

    Input: 10
    Output: false

Explanation: Reads 01 from right to left. Therefore it is not a palindrome.*/

var isPalindrome = function(x) {

    if (!(typeof x === 'number' && x % 1 === 0)) { return false; }

    var s = '' + x;
    var l = s.length

    var left  = (l % 2 == 0) ? l / 2 : ~~((l - 1) / 2);
    var right = (l % 2 == 0) ? left - 1 : left;

    while (left >= 0 && right <= l-1 && s[left] === s[right]) {
        left--;
        right++;
    }

    return (left < 0) && (right >= l);
};


console.log(isPalindrome(121));
console.log(isPalindrome(-121));
console.log(isPalindrome(10));
console.log(isPalindrome(-10));
console.log(isPalindrome(1234554321));
console.log(isPalindrome(123454321));

// console.log(isPalindrome("121"));
// console.log(isPalindrome("-121"));
// console.log(isPalindrome("10"));

// console.log(isPalindrome(""));
// console.log(isPalindrome(" "));
