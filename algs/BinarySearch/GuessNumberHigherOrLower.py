#https://leetcode.com/problems/guess-number-higher-or-lower/description/

"""
We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!

Example:
n = 10, I pick 6.

Return 6.


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

"""
def guess(n):
    if n == 6: return 0
    if n > 6: return 1
    if n < 6: return -1

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        left, right = 1, n 
        while (left <= right):
            mid = left + (right - left) // 2
            if   guess(mid) == 0: return mid
            elif guess(mid) == 1:  left = mid + 1
            elif guess(mid) == -1: right = mid - 1


s = Solution()
print s.guessNumber(5)
print s.guessNumber(6)
print s.guessNumber(4)