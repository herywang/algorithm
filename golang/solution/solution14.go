package solution

import "fmt"

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	left := 0
	var currentChar byte
	var minLen int = func() int {
		a := 1<<31 - 1
		for _, s := range strs {
			if len(s) < a {
				a = len(s)
			}
		}
		return a
	}()

	for left < minLen {
		var same bool = true
		currentChar = strs[0][left]
		for _, str := range strs {
			if str[left] != currentChar {
				same = false
				break
			}
		}
		if !same {
			break
		}
		left++
	}
	return strs[0][:left]
}

func Solution14() {
	fmt.Println(longestCommonPrefix([]string{"flower", "flow", "flight"}))
	fmt.Println(longestCommonPrefix([]string{"dog", "racecar", "car"}))
}
