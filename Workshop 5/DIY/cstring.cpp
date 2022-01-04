// Workshop 1: DIY
// Date: 2021/1/24
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include "cstring.h"
namespace sdds
{
    void strCpy(char *des, const char *src)
    {
        while ((*des++ = *src++)) // Copies source character (src) into the destination (des)
            ;
    }

    void strnCpy(char *des, const char *src, int len)
    {
        for (int i = 0; i < len; i++) // Loops until i = len
        {
            des[i] = src[i]; // Copies the src string into des
        }

        if (strLen(src) < len)
        {
            des[len] = '\0'; // If length of source (# of characters copied) is less than Len, null terminate
        }
    }

    int strCmp(const char *s1, const char *s2)
    {

        while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2) // While *s1 and *s2 are  not '\0' and equal to each other do the following:
        {
            s1++; // Post increment s1 (address of string) to get to next character
            s2++; // Post increment s2 (address of string) to get to next character
        }

        if (*s1 == *s2)
        {
            return 0; // If *s1 and *s2 are equal, return 0
        }
        else if (*s1 > *s2)
        {
            return 1; // If *s1 is greather than *s2, return 1
        }
        else
        {
            return -1; // Return -1 if *s2 is greater than *s1
        }
    }

    int strnCmp(const char *s1, const char *s2, int len)
    {
        while (len && *s1 && (*s1 == *s2)) // While len and *s1 do not equal 0 and *s1 is equivalent to *s2, do the following: 
        {
            ++s1;  // Pre increment s1 (address of string) to get to next character
            ++s2;  // Pre increment s2 (address of string) to get to next character
            --len; // Pre decrement len
        }
        if (len == 0)
        {
            return 0; // If both of the strings are the same, return 0
        }
        else if (*s1 > *s2)
        {
            return 1; // If the second string is less than first string, return 1
        }
        else
        {
            return -1; // Return -1 if the first string is less than the second string
        }
    }

    int strLen(const char *s)
    {
        int len = 0;

        for (int i = 0; s[i] != '\0'; i++) // Iterate through each character in the string until the end
        {
            len++; // Post increment len for each iteration the string passes through
        }
        return (len); // Return length of string
    }

    const char *strStr(const char *str1, const char *str2)
    {
        int a = 0, b = 0, d;

        while (str1[a] != '\0') // This will keep looping through each character of the first string until the end
        {
            d = a;
            while (str2[b] != '\0') // This will keep looping through each character of the second string until the end
            {
                if (str1[d] != str2[b])
                {
                    break; // If the characters do not match, break
                }
                d++; // If they match, move on to the next character in the first string by post increment
                b++; // If they match, move on to the next character in the second string by post increment
            }
            if (str2[b] == '\0')         // If we reach the send of the second string do the following:
                return (char *)str1 + a; // Return the address of str1 + value of 'a' to find the address of the first occurance of string 2 within string 1
            else
            {
                a++;   // Move on to the next character in the first string with post increment to continue the search for a match
                b = 0; // Begin at the first character in the second string to find matches elsewhere in string 1
            }
        }
        return nullptr; // If there are no matches of string 2 within string 1, return nullptr
    }

    void strCat(char *des, const char *src)
    {
        while (*des != '\0') // Iteratate through each character in *des until the end of the string
            des++;           // Post increment for each iteration that the string goes through

        while ((*des++ = *src++) != '\0') // At the end of *des, concatenate src, cannot be null terminator
            ;
    }

} // namespace sdds
