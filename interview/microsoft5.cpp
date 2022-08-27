//
// Created by wangheng on 2022/8/26.
//

// C++ program for the above approach
#include <iostream>
#include <string>
#include <map>

using namespace std;

// Function to count substrings having
// even frequency of each character
int subString(string s, int n)
{

    // Stores the count of a character
    map<int, int> hash;
    hash[0] = 1;

    // Stores bitmask
    int pre = 0;

    // Stores the count of substrings
    // with even count of each character
    int count = 0;

    // Traverse the string S
    for (int i = 0; i < n; i++) {

        // Flip the ord(i)-97 bits in pre
        pre ^= (1 << int(s[i]) - 97);

        // Increment the count by hash[pre]
        count += hash[pre];

        // Increment count of pre in hash
        hash[pre] = hash[pre] + 1;
    }

    // Return the total count obtained
    return count;
}

// Driver Code
int main()
{
    string S = "zthtzh";
    int N = S.length();
    cout << (subString(S, N));
}

