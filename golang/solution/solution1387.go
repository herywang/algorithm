package solution

import (
	"fmt"
	"sort"
)

type Pair struct {
	Val    int
	Weight int
}

type ByWeight []Pair

func (a ByWeight) Len() int      { return len(a) }
func (a ByWeight) Swap(i, j int) { a[i], a[j] = a[j], a[i] }
func (a ByWeight) Less(i, j int) bool {
	if a[i].Weight == a[j].Weight {
		return a[i].Val < a[j].Val
	}
	return a[i].Weight < a[j].Weight
}

func solution(lo int, hi int, k int) {
	m := make(map[int]int)

	calculateTo1Path := func(number int, m *map[int]int) (int, map[int]int) {
		tmp_m := make(map[int]int)
		if number == 1 {
			tmp_m[number] = 0
			return 0, tmp_m
		}
		if v, exists := (*m)[number]; exists {
			return v, tmp_m
		}
		var steps int = 0
		tmp_m[number] = steps
		for {
			if number%2 == 0 {
				number = number / 2
				steps += 1
				tmp_m[number] = steps
			} else {
				number = number*3 + 1
				steps += 1
				tmp_m[number] = steps
			}
			if number == 1 {
				for k, v := range tmp_m {
					tmp_m[k] = steps - v
				}
				return steps, tmp_m
			}

			if _, exists := (*m)[number]; exists {
				steps = steps + (*m)[number]
				for k, v := range tmp_m {
					tmp_m[k] = steps - v
				}
				return steps, tmp_m
			}
		}
	}

	var result []Pair = make([]Pair, 0, hi-lo+1)
	for i := lo; i <= hi; i++ {
		p, tmp_m := calculateTo1Path(i, &m)
		for k, v := range tmp_m {
			m[k] = v
		}
		pair := &Pair{Val: int(i), Weight: int(p)}

		result = append(result, *pair)
	}

	sort.Sort(ByWeight(result))

	fmt.Println(result[k-1])
	fmt.Println(result)
}

func Solution1387() {
	fmt.Println("Please input Low(lo), High(hi) and k:")
	var lo, hi, k int = 1, 10000, 777
	// fmt.Scanf("%d %d %d", &lo, &hi, &k)
	solution(lo, hi, k)
}
