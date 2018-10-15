/*There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5*/

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findKth = function(A, B, k) {
    var lA = A.length;
    var lB = B.length;

    if (A.length === 0) { return B[k-1]; }
    if (B.length === 0) { return A[k-1]; }
    if (k === 1) { return Math.min(A[0], B[0]); }

    var a = (A.length >= k/2) ? A[ parseInt(k/2) - 1 ] : undefined;
    var b = (B.length >= k/2) ? B[ parseInt(k/2) - 1 ] : undefined;

    if ((b === undefined) || (a !== undefined && a < b)) {
        return findKth(A.slice(parseInt(k/2)), B, k - parseInt(k/2));
    } else {
        return findKth(A, B.slice(parseInt(k/2)), k - parseInt(k/2));
    }
};

var findMedianSortedArrays = function(nums1, nums2) {

    var n = nums1.length + nums2.length;
    if ( n % 2 === 1 ) {
        return findKth(nums1, nums2, parseInt(n / 2) + 1)
    } else {
        var smaller = findKth(nums1, nums2, parseInt(n / 2) );
        var bigger  = findKth(nums1, nums2, parseInt(n / 2) + 1);
        //console.log(smaller, bigger);
        return (smaller + bigger) / 2;
    }
};



var n1 = [1,3];
var n2 = [2]

console.log( findMedianSortedArrays(n1, n2) );
