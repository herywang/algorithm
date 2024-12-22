package solution

import (
	"fmt"
	"math"
)

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	head, q := &ListNode{math.MinInt32, list1}, list2
	p := head

	for {
		if p.Next == nil && q != nil {
			p.Next = q
			break
		} else if q == nil {
			break
		}

		if q.Val < p.Next.Val && q.Val >= p.Val {
			tmp := q.Next
			q.Next = p.Next
			p.Next = q
			q = tmp
			p = p.Next
		} else if q.Val >= p.Next.Val {
			p = p.Next
		}
	}

	return head.Next
}

// newHead -> q -> r -> s
//    p

func Solution21() {
	// l1 := &ListNode{1, &ListNode{2, &ListNode{2, &ListNode{5, nil}}}}
	var l1 *ListNode = nil
	l2 := &ListNode{2, &ListNode{3, &ListNode{3, &ListNode{4, &ListNode{7, nil}}}}}

	res := mergeTwoLists(l1, l2)
	for res != nil {
		fmt.Println(res.Val)
		res = res.Next
	}
}
