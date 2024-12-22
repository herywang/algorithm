package solution

import (
	"fmt"
)

// Longest Substring Without Repeating Characters
func lengthOfLongestSubstring(s string) int {
	var record map[string]int = make(map[string]int)
	var maxLen int = 0
	start, end := 0, 0
	for end < len(s) {
		value, exist := record[string(s[end])]
		if !exist {
			record[string(s[end])] = end
			end += 1
			maxLen = func(a int, b int) int {
				if a > b {
					return a
				}
				return b
			}(end-start, maxLen)
		} else {
			record[string(s[end])] = end
			if value+1 >= start {
				start = value + 1
			}
			end += 1
			maxLen = func(a int, b int) int {
				if a > b {
					return a
				}
				return b
			}(end-start, maxLen)
		}
	}
	return maxLen
}

func Solution3() {
	fmt.Println(lengthOfLongestSubstring("abcabcbb"))
	fmt.Println(lengthOfLongestSubstring("bbbbb"))
	fmt.Println(lengthOfLongestSubstring("pwwkew"))
	fmt.Println(lengthOfLongestSubstring("abba"))
}
