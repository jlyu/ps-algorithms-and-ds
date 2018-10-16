/*Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

    Input: 123
    Output: 321


Example 2:

    Input: -123
    Output: -321


Example 3:

    Input: 120
    Output: 21

Note:
Assume we are dealing with an environment which could only store integers
within the 32-bit signed integer range: [−2^31,  2^31 − 1].
For the purpose of this problem, assume that your function returns 0
when the reversed integer overflows.
*/

var reverse = function(x) {
    if ( x > 2147483647 || x < -2147483648 ) { return 0; }
    x = '' + x;
    var s = (x[0] === '-') ? '-' + x.slice(1).split('').reverse().join('')
                            : x.split('').reverse().join('');
    var i = parseInt(s);
    if ( i > 2147483647 || i < -2147483648 ) { return 0; }
    return i;
};

console.log( reverse("1534236469") );
console.log( reverse("-2147483412") );


console.log( reverse("-123") );
console.log( reverse("120") );
