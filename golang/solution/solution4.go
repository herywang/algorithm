// Median of two sorted array
package solution

import "fmt"

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	m, n := len(nums1), len(nums2)

	l1, l2 := 0, 0
	if (m+n)%2 != 0 {
		// 基数，取中间
		lim := (m + n) / 2
		index := 0
		val := 0
		for l1 < m && l2 < n {
			if nums1[l1] <= nums2[l2] {
				val = nums1[l1]
				l1++
			} else {
				val = nums2[l2]
				l2++
			}
			if index == lim {
				return float64(val)
			}
			index++
		}
		for l1 < m {
			val = nums1[l1]
			l1++
			if index == lim {
				return float64(val)
			}
			index++
		}
		for l2 < n {
			val = nums2[l2]
			l2++
			if index == lim {
				return float64(val)
			}
			index++
		}
		return -1
	} else {
		// 偶数个
		lim := (m + n) / 2
		index := 0
		val1, preVal := 0, 0
		for l1 < m && l2 < n {
			if nums1[l1] <= nums2[l2] {
				preVal = val1
				val1 = nums1[l1]
				l1++
			} else {
				preVal = val1
				val1 = nums2[l2]
				l2++
			}
			if index == lim {
				return float64(val1+preVal) / 2.
			}
			index++
		}

		for l1 < m {
			preVal = val1
			val1 = nums1[l1]
			l1++
			if index == lim {
				return float64(val1+preVal) / 2.
			}
			index++
		}
		for l2 < n {
			preVal = val1
			val1 = nums2[l2]
			l2++
			if index == lim {
				return float64(val1+preVal) / 2.
			}
			index++
		}
		return -1
	}

}

func Solution4() {
	var nums1 []int = []int{1, 3, 5, 5, 7}
	var nums2 []int = []int{2, 4, 6, 8, 10, 11, 14}
	fmt.Println(findMedianSortedArrays(nums1, nums2))
}
