package solution

import "fmt"

// Letter Combinations of a Phone Number
var letter = map[int]string{
	2: "abc",
	3: "def",
	4: "ghi",
	5: "jkl",
	6: "mno",
	7: "pqrs",
	8: "tuv",
	9: "wxyz",
}

func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return make([]string, 0)
	}
	var res []string = make([]string, 0)
	var combination string = ""
	backtrack(&res, digits, 0, &combination)
	return res
}

func backtrack(res *[]string, digits string, index int, combination *string) {
	if index == len(digits) {
		*res = append(*res, *combination)
		return
	}
	letterNumber := digits[index]
	letterStr := letter[int(letterNumber-'0')]
	for _, c := range letterStr {
		*combination = *combination + string(c)
		backtrack(res, digits, index+1, combination)
		*combination = (*combination)[:len(*combination)-1]
	}
}

func Solution17() {
	res := letterCombinations("234")
	for _, v := range res {
		fmt.Println(v)
	}
}
