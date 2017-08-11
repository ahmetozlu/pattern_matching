# Implementation and Performance Comparison of Search Algorithms
Pattern searching(string-matching) is an important problem in computer science. When we do search for a string in notepad/word file or browser or database, pattern searching algorithms are used to show the search results. 

This repository includes *implementations of Boyer Moore, Horspool and Brute Force algorithms* in **c programming language**. Moreover, *the execution times* are calculated in these c programs so *performance of Boyer Moore, Horspool and Brute Force algorithms can be examined* on different test cases.

---
**What does this repository include?**
1. Implementations of Boyer Moore, Horspool and Brute Force algorithms in c programming language
2. The execution times are calculated in these c programs for different input text files so performance of Boyer Moore, Horspool and Brute Force algorithms can be examined

- As a summary, these c programs take a pattern as an input and search it on a text file which is pointed by user and it gives pattern position, number of character comparison and total run time of algorithm so you can compare the performance of Boyer Moore, Horspool and Brute Force algorithms.
---

## Theory

**1.) Boyer-Moore Algorithm:** The Boyer-Moore algorithm is considered as the most efficient string-matching algorithm in usual applications. A simplified version of it or the entire algorithm is often implemented in text editors for the «search» and «substitute» commands.

The algorithm scans the characters of the pattern from right to left beginning with the rightmost one. In case of a mismatch (or a complete match of the whole pattern) it uses two precomputed functions to shift the window to the right. These two shift functions are called the good-suffix shift.

Main features;
- performs the comparisons from right to left;
- preprocessing phase in O(m+sigma) time and space complexity;
- searching phase in O(mn) time complexity;
- 3n text character comparisons in the worst case when searching for a non periodic pattern;
- O(n / m) best performance.

Please examine [**it**](http://www-igm.univ-mlv.fr/~lecroq/string/node14.html) for more information about "How does Boyer-Moore Algorithm works?".

**2.) Horspool Algorithm:** The bad-character shift used in the Boyer-Moore algorithm is not very efficient for small alphabets, but when the alphabet is large compared with the length of the pattern, as it is often the case with the ASCII table and ordinary searches made under a text editor, it becomes very useful.

Using it alone produces a very efficient algorithm in practice. Horspool proposed to use only the bad-character shift of the rightmost character of the window to compute the shifts in the Boyer-Moore algorithm.

Main features;
- simplification of the Boyer-Moore algorithm;
- easy to implement;
- preprocessing phase in O(m+sigma) time and O(sigma) space complexity;
- searching phase in O(mn) time complexity;
- the average number of comparisons for one text character is between 1/sigma and 2/(sigma+1).

Please examine [**it**](http://www-igm.univ-mlv.fr/~lecroq/string/node18.html) for more information about "How does Horspool Algorithm works?".

**3.) Brute Force Algorithm:** The brute force algorithm consists in checking, at all positions in the text between 0 and n-m, whether an occurrence of the pattern starts there or not. Then, after each attempt, it shifts the pattern by exactly one position to the right.

The brute force algorithm requires no preprocessing phase, and a constant extra space in addition to the pattern and the text. During the searching phase the text character comparisons can be done in any order. The time complexity of this searching phase is O(mn) (when searching for am-1b in an for instance). The expected number of text character comparisons is 2n.

Main features;
- no preprocessing phase;
- constant extra space needed;
- always shifts the window by exactly 1 position to the right;
- comparisons can be done in any order;
- searching phase in O(mn) time complexity;
- 2n expected text characters comparisons.

Please examine [**it**](http://www-igm.univ-mlv.fr/~lecroq/string/node3.html) for more information about "How does Brute Force Algorithm works?".

## Citation
If you use this code for your publications, please cite it as:

    @ONLINE{vdtc,
        author = "Ahmet Özlü",
        title  = "String Matching",
        year   = "2017",
        url    = "https://github.com/ahmetozlu/pattern_matching"
    }

## Author
Ahmet Özlü

## License
This system is available under the MIT license. See the LICENSE file for more info.
