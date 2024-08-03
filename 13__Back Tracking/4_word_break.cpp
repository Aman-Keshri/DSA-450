// A recursive program to print all possible
// partitions of a given string into dictionary
// words
#include <iostream>
using namespace std;

/* A utility function to check whether a word
is present in dictionary or not. An array of
strings is used for dictionary. Using array
of strings for dictionary is definitely not
a good idea. We have used for simplicity of
the program*/
int dictionaryContains(string &word)
{
    string dictionary[] = {"mobile", "samsung", "sam", "sung",
                           "man", "mango", "icecream", "and",
                           "go", "i", "love", "ice", "cream"};
    int n = sizeof(dictionary) / sizeof(dictionary[0]);
    for (int i = 0; i < n; i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}

// Result store the current prefix with spaces
// between words
void wordBreakUtil(string str, int n, string result)
{
    // Process all prefixes one by one
    for (int i = 1; i <= n; i++)
    {
        // Extract substring from 0 to i in prefix
        string prefix = str.substr(0, i);

        // If dictionary contains this prefix, then
        // we check for remaining string. Otherwise
        // we ignore this prefix (there is no else for
        // this if) and try next
        if (dictionaryContains(prefix))
        {
            // If no more elements are there, print it
            if (i == n)
            {
                // Add this element to previous prefix
                result += prefix;
                cout << result << endl;
                return;
            }
            wordBreakUtil(str.substr(i, n - i), n - i,
                          result + prefix + " ");
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     string prefix = str.substr(0, i);

    //     if (dictionaryContains(prefix))
    //     {
    //         // base case check
    //         if (i == n)
    //         {
    //             result += prefix;
    //             cout << result << endl;
    //             return;
    //         }

    //         wordBreakUtil(str.substr(i, n - i), n - i, result + prefix + " ");
    //     }
    // }
}

// Prints all possible word breaks of given string
void wordBreak(string str)
{
    // Last argument is prefix
    wordBreakUtil(str, str.size(), "");
}

// Driver Code
int main()
{

    // Function call
    cout << "First Test:\n";
    wordBreak("iloveicecreamandmango");

    cout << "\nSecond Test:\n";
    wordBreak("ilovesamsungmobile");
    return 0;
}
