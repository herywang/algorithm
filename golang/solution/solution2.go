package solution

import "fmt"

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {

	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	// 进位变量
	var m int = 0
	p1, p2 := l1, l2
	for p1 != nil && p2 != nil {
		res := p1.Val + p2.Val + m
		if res >= 10 {
			m = 1
			res = res - 10
		} else {
			m = 0
		}
		p1.Val = res
		p2.Val = res

		p1 = p1.Next
		p2 = p2.Next
	}

	if p1 == nil && p2 == nil {
		if m == 0 {
			return l1
		} else {
			q := l1
			for q.Next != nil {
				q = q.Next
			}
			q.Next = &ListNode{Val: m, Next: nil}
			return l1
		}
	}

	if p1 == nil {
		var pre *ListNode = nil
		for p2 != nil {
			res := p2.Val + m
			if res >= 10 {
				m = 1
				res = res - 10
			} else {
				m = 0
			}
			p2.Val = res
			pre = p2
			p2 = p2.Next
		}

		if m == 1 {
			pre.Next = &ListNode{Val: 1, Next: nil}
		}
		return l2
	} else {
		var pre *ListNode = nil
		for p1 != nil {
			res := p1.Val + m
			if res >= 10 {
				m = 1
				res = res - 10
			} else {
				m = 0
			}
			p1.Val = res
			pre = p1
			p1 = p1.Next
		}

		if m == 1 {
			pre.Next = &ListNode{Val: 1, Next: nil}
		}
		return l1
	}
}

func printVal(head *ListNode) {
	if head == nil {
		return
	}
	printVal(head.Next)
	fmt.Print(head.Val)
}

func Solution2() {
	var l1 *ListNode = &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3, Next: nil}}}
	var l2 *ListNode = &ListNode{Val: 9, Next: &ListNode{Val: 8, Next: &ListNode{Val: 1, Next: &ListNode{Val: 4}}}}

	var l3 *ListNode = addTwoNumbers(l1, l2)

	p := l3
	printVal(p)

}
