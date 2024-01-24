// Longest palindrom substring
package solution

import "fmt"

// Given a string s, return the longest palindromic substring in s
func longestPalindrome(s string) string {
	if len(s) <= 1 {
		return s
	}
	if len(s) == 2 {
		if s[0] == s[1] {
			return s
		}
		return string(s[0])
	}
	maxPalindrom := func(left int, right int) (string, int) {
		resStr, resLen := "", 0
		for left >= 0 && right <= len(s)-1 {
			if s[left] == s[right] {
				resStr = s[left : right+1]
				resLen = len(resStr)
				left--
				right++
			} else {
				break
			}
		}
		return resStr, resLen
	}

	var finalRes string = ""
	var finalLen int = 0

	for i := 0; i < len(s)-1; i++ {
		oddRes, oddLen := maxPalindrom(i, i)
		evenRes, evenLen := maxPalindrom(i, i+1)

		if oddLen > finalLen {
			finalRes = oddRes
			finalLen = oddLen
		}

		if evenLen > finalLen {
			finalRes = evenRes
			finalLen = evenLen
		}
	}

	return finalRes
}

func Solution5() {
	testStr := "cbbd"
	fmt.Println(longestPalindrome(testStr))
}
