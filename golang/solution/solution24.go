package solution

import (
	"fmt"
)

// swap nodes in pairs
func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	newHead := &ListNode{0, head}
	p := newHead
	for p.Next != nil && p.Next.Next != nil {
		q := p.Next
		p.Next = q.Next

		nextP := p.Next.Next
		p.Next.Next = q

		q.Next = nextP

		p = p.Next.Next
	}

	return newHead.Next
}

func Solution24() {
	list1 := &ListNode{1, &ListNode{2, &ListNode{3, &ListNode{4, &ListNode{5, nil}}}}}
	res := swapPairs(list1)

	for res != nil {
		fmt.Println(res.Val)
		res = res.Next
	}
}
