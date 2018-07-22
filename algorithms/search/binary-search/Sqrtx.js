//https://leetcode.com/problems/sqrtx/description/

// Implement int sqrt(int x).

// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

// Example 1:

// Input: 4
// Output: 2


// Example 2:

// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since 
//              the decimal part is truncated, 2 is returned.
/**
var search = function(nums, target) {
    //if (target < 1) { return -1; }
    if (nums.length <= 0) { return -1; }

    var low = 0;
    var high = nums.length - 1;

    while (low <= high) {
        var mid = low + parseInt( (high - low) / 2 ); // Prevent (LOW + HIGH) overflow
        if (nums[mid] === target) { return mid; }
        else if (nums[mid] < target) { low = mid + 1; }
        else if (nums[mid] > target) { high = mid - 1; }
    }

    return -1;
};
 */
/**
 * @param {number} x
 * @return {number}
 */

var mySqrt_v0 = function(x) {
    if (x < 0) { return -1; }
    if (x < 2) { return x; }
    var mid = parseInt( x / 2 );
    var result = 0;
    for (var i = 1; i<= mid + 1; i++) {
        result += (2 * i - 1);
        //console.log(result);
        if (result === x) { return i; }
        if (result > x) { return i - 1; }
    }
};

var mySqrt = function(x) {
    var left = 1, right = x;
    while (left < right) {
        var mid = parseInt( (left + right + 1) / 2);
        if (mid > x / mid) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }
    return right;
};

for(var i=0; i<100; i++) {
    console.log("mySqrt("+i+"):" + mySqrt(i));
    console.assert(mySqrt(i) === mySqrt_v0(i))
}
//console.log("mySqrt(4):" + mySqrt(4));
//console.log("mySqrt(8):" + mySqrt(8));
