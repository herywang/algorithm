package solution

import "fmt"

var (
	romanMap2 = map[string]int{
		"I":  1,
		"V":  5,
		"IV": 4,
		"X":  10,
		"IX": 9,
		"L":  50,
		"C":  100,
		"D":  500,
		"M":  1000,
		"XL": 40,
		"XC": 90,
		"CD": 400,
		"CM": 900,
	}
)

func romanToInt(s string) int {
	if len(s) == 0 {
		return 0
	}
	var res int = 0
	for left := 0; left < len(s); left++ {
		if left+1 < len(s) {
			value, ok := romanMap2[s[left:left+2]]
			if ok {
				res += value
				left++
			} else {
				res += romanMap2[s[left:left+1]]
			}

		} else {
			value := romanMap2[s[left:left+1]]
			res += value
		}
	}
	return res
}

func Solution13() {
	fmt.Println(romanToInt("MCMXCIV"))
	fmt.Println(romanToInt("III"))
	fmt.Println(romanToInt("LVIII"))
}
