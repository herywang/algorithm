package solution

import (
	"fmt"
	"strings"
)

func minWindow(s string, t string) string {
	if len(s) < len(t) {
		return ""
	} else if len(s) == len(t) && strings.Compare(s, t) == 0 {
		return s
	}
	var need map[rune]int = make(map[rune]int)
	for _, v := range t {
		if _, ok := need[v]; ok {
			need[v] = need[v] + 1
		} else {
			need[v] = 1
		}
	}
	var constNeed map[rune]int = make(map[rune]int)
	for key, value := range need {
		constNeed[key] = value
	}

	var (
		// 滑动窗口左边界
		l int = 0
		// 滑动窗口右边界
		r     int    = 0
		limit        = len(s)
		res   string = ""
	)
	for l < limit {
		// 右指针右移，直到包含t中的所有字符
		for len(need) > 0 && r < len(s) {
			if _, ok := need[rune(s[r])]; ok {
				need[rune(s[r])] = need[rune(s[r])] - 1
				if need[rune(s[r])] == 0 {
					delete(need, rune(s[r]))
				}
				r++
			} else {
				r++
			}
		}
		// 如果右边界超出了s长度，并且还是没有覆盖t中的所有字符，则直接返回空
		if r == len(s) && len(need) > 0 {
			return res
		}
		// 左指针右移，直到刚好包含t中的字符
		for !strings.ContainsRune(t, rune(s[l])) || canMove(s[l+1:r], constNeed, rune(s[l])) {
			l++
		}

		res = func() string {
			if len(res) == 0 || len(s[l:r]) < len(res) {
				return s[l:r]
			}
			return res
		}()

		need[rune(s[l])] = 1
		l++
	}

	return res
}

func canMove(str string, constNeed map[rune]int, char rune) bool {
	var tmpMap map[rune]int = make(map[rune]int)
	for _, v := range str {
		if _, ok := tmpMap[v]; ok {
			tmpMap[v] = tmpMap[v] + 1
		} else {
			tmpMap[v] = 1
		}
	}
	if tmpMap[char] >= constNeed[char] {
		return true
	}
	return false
}

func Solution76() {
	// fmt.Println(minWindow("ADOBECODEBANC", "ABC"))
	fmt.Println(minWindow("bbaa", "aba"))
}
