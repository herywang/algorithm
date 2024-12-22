package solution

import "fmt"

// 分割链表

func partition(head *ListNode, x int) *ListNode {
	if head == nil {
		return head
	}
	var smal_list *ListNode = &ListNode{0, nil}
	var big_list *ListNode = &ListNode{0, nil}

	var p *ListNode = head
	var q *ListNode = smal_list
	var r *ListNode = big_list
	for p != nil {
		if p.Val < x {
			q.Next = p
			q = q.Next
		} else {
			r.Next = p
			r = r.Next
		}
		p = p.Next
	}
	q.Next = big_list.Next
	r.Next = nil
	return smal_list.Next
}

func Solution86() {
	head := &ListNode{1, &ListNode{4, &ListNode{3, &ListNode{2, &ListNode{5, &ListNode{2, nil}}}}}}
	head = partition(head, 3)
	for head != nil {
		fmt.Println(head.Val)
		head = head.Next
	}
}
