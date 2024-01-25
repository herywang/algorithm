package solution

import (
	"fmt"
	"math"
	"strconv"
)

func reverse_string(x string) string {
	var res []rune = []rune(x)
	for i, j := 0, len(x)-1; i < j; i, j = i+1, j-1 {
		res[i], res[j] = res[j], res[i]
	}
	return string(res)
}

func reverse(x int) int {
	var isMinus bool = (x < 0)
	if isMinus {
		x = -x
	}
	s := strconv.Itoa(x)
	start := 0
	end := func() int {
		var i int = len(s) - 1
		for ; i >= 0; i-- {
			if string(s[i]) != "0" {
				break
			}
		}
		return i
	}()
	if start == end {
		v, _ := strconv.Atoi(reverse_string(s[start : start+1]))
		if isMinus {
			if -v < math.MinInt32 {
				return 0
			}
			return -v
		}
		if v > math.MaxInt32 {
			return 0
		}
		return v
	} else {
		v, _ := strconv.Atoi(reverse_string(s[start : end+1]))
		if isMinus {
			if -v < math.MinInt32 {
				return 0
			}
			return -v
		}
		if v > math.MaxInt32 {
			return 0
		}
		return v
	}

}

func Solution7() {
	fmt.Println(reverse(123))
	fmt.Println(reverse(1534236469))
	fmt.Println(reverse(-34560001))
}
