//String Methods
let str = "Welcome to Astroworld";
let str2 = "abcdefghiklmnopqrstuvwxyzABCDEFGHIKJLMNOPQRSTUVWXYZ";

var res = str.charAt(0);
//returns the character at a given a index of a string

var res = str.charCodeAt(0);
//returns the unicode of the charachter at a given index of a string

var res = str.concat(str2);
//concatenates two strings together

var res = str.endsWith('Astroworld');
//returns boolean value of whethere a string ends with the specified characters

var res = String.fromCharCode('66');
//returns the character of a unicode number

var res = str.includes("world");
//determines whether a string contains the characters of a specified string

var res = str.indexOf('Astro');
//returns the position of the first occurrence of a specified value in a string

var res = str.lastIndexOf('Astro');
//returns the position of the last occurrence of a specified value in a string

var res = str.localeCompare(str2);
//returns a number indicating whether str1 comes before, after or is the same as str2 in sort order
//Returns -1 if str1 is sorted before str2
//Returns 0 if the two strings are equal
//Returns 1 if str1 is sorted after str2

var res = str.match(/worl/g);
//searches a string for a match against a regular expression, and returns the matches, as an Array object

var res = str.repeat(4);
//returns a new string with a specified number of copies of the string it was called on

var res = str.replace("Astroworld", "the Rodeo");
//searches a string for a specified value, or a regular expression, and returns a new string where the specified values are replaced

var res = str.search('Astro')
//searches a string for a specified value, and returns the position of the match

var res = str.search(/astro/i);
//case-insensitive search

var res = str.slice(0,5);
//extracts parts of a string and returns the extracted parts in a new string

var res = str.split(" ");
//split a string into an array of substrings, and returns the new array (if empty string "", string is split bw each char)

var res = str.startsWith("Welcome");
//determines whether a string begins with the characters of a specified string

var res = str.substr(1,4);
//extracts parts of a string, beginning at the character at the specified position, and returns the specified number of characters

var res = str.substring(1,4);
//method extracts the characters from a string, between two specified indices, and returns the new sub string

var res = str.toLocaleLowerCase();
//converts a string to lowercase letters, according to the host's current locale

var res = str.toLocaleUpperCase();
//converts a string to uppercase letters, according to the host's current locale

var res = str.toLowerCase();
//converts a string to lowercase letters

var res = str.toString();
//returns the value of a String object

var res = str.toUpperCase();
//converts a string to uppercase letters

var res = str.trim();
//removes whitespace from both sides of a string, nothing inbetween

var res = str.valueOf();
//returns the primitive value of a String object

// console.log(res);