package solution

import (
	"fmt"
)

func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	start := head

	for {
		if start == nil {
			break
		}
		var next *ListNode = start.Next

		for {
			if next == nil {
				break
			}
			if next.Val < start.Val {
				tmp := next.Val
				next.Val = start.Val
				start.Val = tmp
			}
			next = next.Next
		}
		start = start.Next
	}

	return head
}

func sortList2(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	var slice1 []int
	start := head

	for start != nil {
		slice1 = append(slice1, start.Val)
	}

	return head
}

func mySort(array []int, left int, right int) {
	if left >= right {
		return
	}
	var baseVal int = array[right]
	var l int = left
	var r int = right
	for l < r {
		for ; l < r && array[l] < baseVal; l++ {
		}
		array[r] = array[l]
		for ; l < r && array[r] > baseVal; r-- {
		}
		array[l] = array[r]
	}
	array[l] = baseVal
	mySort(array, left, l-1)
	mySort(array, l+1, right)
}

func main148() {

	var a []int = []int{5, 7, 2, 4, 6}
	mySort(a, 0, 4)
	for ix := 0; ix < 5; ix++ {
		fmt.Println(a[ix])
	}

	head := &ListNode{Val: 4, Next: &ListNode{Val: 3, Next: &ListNode{Val: 2, Next: &ListNode{Val: 1, Next: nil}}}}

	sortList(head)

	for {
		if head == nil {
			break
		}
		fmt.Printf("值：%d\n", head.Val)
		head = head.Next
	}
}
