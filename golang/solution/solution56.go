package solution

import (
	"fmt"
	"sort"
)

// 合并重叠区间
func merge(intervals [][]int) [][]int {
	if len(intervals) == 1 {
		return intervals
	}
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	var (
		ans   [][]int = make([][]int, 0)
		start int     = intervals[0][0]
		end   int     = intervals[0][1]
	)
	for i := 1; i < len(intervals); i++ {
		if intervals[i][0] <= end {
			end = max(intervals[i][1], end)
		} else {
			ans = append(ans, []int{start, end})
			start = intervals[i][0]
			end = intervals[i][1]
		}
	}
	ans = append(ans, []int{start, end})
	return ans
}

func Solution56() {

	intervals := [][]int{{1, 3}, {2, 6}, {8, 10}, {15, 18}}
	fmt.Println(merge(intervals))
}
