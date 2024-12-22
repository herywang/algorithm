package solution

import (
	"fmt"
	"sort"
)

var romanMap map[int]string = map[int]string{
	1000: "M",
	900:  "CM",
	500:  "D",
	400:  "CD",
	100:  "C",
	90:   "XC",
	50:   "L",
	40:   "XL",
	10:   "X",
	9:    "IX",
	5:    "V",
	4:    "IV",
	1:    "I",
}

func intToRoman(num int) string {
	keys := make([]int, 0, len(romanMap))
	for key := range romanMap {
		keys = append(keys, key)
	}
	sort.Ints(keys)
	var res string = ""
	for i := len(keys) - 1; i >= 0; i-- {
		if num < keys[i] {
			continue
		}
		n := num / keys[i]
		for j := 0; j < n; j++ {
			res = res + romanMap[keys[i]]
		}
		num = num % keys[i]
	}
	return res
}

func Solution12() {
	fmt.Println(intToRoman(12345))
}
