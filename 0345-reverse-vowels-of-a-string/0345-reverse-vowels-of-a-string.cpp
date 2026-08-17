class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' ||
               ch == 'e' ||
               ch == 'i' ||
               ch == 'o' ||
               ch == 'u';
    }

    string reverseVowels(string s) {
        int Left = 0;
        int Right = s.size() - 1;
        while (Left < Right) {
            if (isVowel(s[Left]) && isVowel(s[Right])) {
                swap(s[Left++], s[Right--]);
            }
            else if (isVowel(s[Left])) {

                Right--;

            }
            else {
                Left++;
            }
        }
        return s;
    }
};

/* Intuition
We need to reverse only vowels, not the entire string.

Instead of creating another string, use two pointers.

Left pointer searches for the next vowel from the beginning.
Right pointer searches for the next vowel from the end.
When both pointers are on vowels, swap them.
This keeps all non-vowel characters in their original positions.

*/