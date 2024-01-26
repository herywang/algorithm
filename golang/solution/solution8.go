// String to integer
package solution

import (
	"fmt"
	"math"
	"strings"
)

func myAtoi(s string) int {
	if len(s) == 0 {
		return 0
	}

	newStr := strings.Trim(s, " ")
	var res []uint8 = make([]uint8, 0)

	var isNegative bool = false

	for i, v := range newStr {
		if i == 0 && byte(v) == byte('+') {
			isNegative = false
			continue
		} else if i == 0 && byte(v) == byte('-') {
			isNegative = true
			continue
		} else if i == 0 && !(byte(v) >= byte('0') && byte(v) <= ('9')) {
			return 0
		}

		if byte(v) < byte('0') || byte(v) > byte('9') {
			break
		}
		if len(res) == 0 && byte(v)-byte('0') == 0 {
			continue
		}
		res = append(res, byte(v)-byte('0'))
		if len(res) > 11 {
			break
		}
	}

	var resInt int64 = 0

	for i, v := range res {
		resInt = int64(v)*int64(math.Pow10(len(res)-i-1)) + resInt
	}
	if isNegative {
		resInt = -resInt
		if resInt < math.MinInt32 {
			return math.MinInt32
		}
		return int(resInt)
	}

	if resInt > math.MaxInt32 {
		return math.MaxInt32
	}
	return int(resInt)
}

func Solution8() {
	// fmt.Println(myAtoi(" -456"))
	// fmt.Println(myAtoi(" -456dass"))
	// fmt.Println(myAtoi("98733"))
	// fmt.Println(myAtoi("dss2343"))
	// fmt.Println(myAtoi("-91283472332"))
	// fmt.Println(myAtoi("20000000000000000000"))
	fmt.Println(myAtoi("0000000000012345678"))
}
