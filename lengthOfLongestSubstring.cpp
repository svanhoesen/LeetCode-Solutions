/*
* Author: Steffan Van Hoesen
* Date: April 10th, 2025
* Name: lengthOfLongestSubstring
* Purpose: Solve the lengthOfLongestSubstring problem with optimal time and space complexity.
* Description: Given a string s, find the length of the longest substring without duplicate characters.
*              
* Constraints: 1) 0 <= s.length <= 5 * 10^4
*              2) s consists of English letters, digits, symbols and spaces.
* Parameters: string s
* Return: Return the length of the longest substring an an int
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> seen; // Using a map to store the last positions of encountered characters
        int maximum_length = 0;
        int head = 0;
    
        for(int end = 0; end < s.length(); end++) 
        {
            if (seen.find(s[end]) != seen.end()) // Checking if we have already seen the element
            {
                head = max(head, seen[s[end]] + 1); // If the character has been encountered, move the head pointer to position after the last occurrence
            }
            seen[s[end]] = end;
            maximum_length = max(maximum_length, 
                                 end - head + 1);
        }
    return maximum_length;
    }
};
