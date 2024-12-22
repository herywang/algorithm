package solution

import (
	"fmt"

	"herywang.com/v2/stl"
)

var charMap = map[rune]rune{
	'(': ')',
	'[': ']',
	'{': '}',
}

func isValid(s string) bool {

	stack := &stl.Stack{}

	if len(s) == 0 {
		return true
	}
	if len(s)%2 != 0 {
		return false
	}

	for _, c := range s {
		if stack.IsEmpty() {
			stack.Push(c)
		} else if val, error := stack.Top(); error == nil {
			r, _ := val.(rune)
			if charMap[r] == c {
				stack.Pop()
			} else {
				stack.Push(c)
			}
		}
	}

	return stack.IsEmpty()
}

func Solution20() {
	fmt.Println(isValid("([{)}])"))
}
