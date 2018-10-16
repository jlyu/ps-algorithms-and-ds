/*The string "PAYPALISHIRING" is written in a zigzag pattern on
a given number of rows like this: (you may want to display this pattern
in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

    Input: s = "PAYPALISHIRING", numRows = 3
    Output: "PAHNAPLSIIGYIR"


Example 2:

    Input: s = "PAYPALISHIRING", numRows = 4
    Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

var convert = function(s, numRows) {
    if (Math.min(numRows, s.length) <= 1) { return s; }

    var lines = {};
    var bSeq = true;
    var counter = 0;

    s.split('').map(function(v, i) {

        if (! lines[counter]) { lines[counter] = ""; }
        lines[counter] += v;

        if (bSeq) {

            if (counter === numRows - 1) { bSeq = false; counter--; if(counter === 0) { bSeq = true; }  }
            else { counter++; }
        } else {

            if (counter === 1) { bSeq = true; counter--; }
            else { counter--; }
        }
    });

    var zigzag = "";
    for (var i = 0; i < Math.min(numRows, s.length); i++) {
      zigzag += lines[i];
    }
    return zigzag;
};
