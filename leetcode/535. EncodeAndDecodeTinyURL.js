// https://leetcode.com/problems/encode-and-decode-tinyurl/description/

// Note: This is a companion problem to the System Design problem: Design TinyURL.
// TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

// Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. 
// You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.


var hashTable = [];
var alphabet = '1234567890abcdfghijklmnopqrstvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
var base = alphabet.length;
/**
 * Encodes a URL to a shortened URL.
 *
 * @param {string} longUrl
 * @return {string}
 */
var encode = function(longUrl) {
    
    hashTable.push(longUrl);
    var num = hashTable.length;

    var str = '';
	while (num > 0) {
			str = alphabet.charAt(num % base) + str;
			num = Math.floor(num / base);
	}
	return "http://tinyurl.com/" + str;
};

/**
 * Decodes a shortened URL to its original URL.
 *
 * @param {string} shortUrl
 * @return {string}
 */
var decode = function(shortUrl) {

    var num = 0;
    shortUrl = shortUrl.replace("http://tinyurl.com/" , "");
	for (var i = 0; i < shortUrl.length; i++) {
			num = num * base + alphabet.indexOf(shortUrl.charAt(i));
    }

	return hashTable[num - 1];
};

/**
 * Your functions will be called as such:
 * decode(encode(url));
 */


 /* with six characters containing a-z, A-Z and 0-9. That makes 56~57 billion possible strings

    0  → a
    1  → b
    ...
    25 → z
    ...
    52 → 0
    61 → 9

*/

//console.log( encode("https://leetcode.com/problems/encode-and-decode-tinyurl/description/") );

//console.log( encode("https://leetcode.com/problems/design-tinyurl") );

console.log( decode(encode("https://leetcode.com/problems/encode-and-decode-tinyurl/description/")) );