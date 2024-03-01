package solution

import "fmt"

// 旋转链表
func rotateRight(head *ListNode, k int) *ListNode {

	var (
		p          *ListNode = head
		listLength int       = 0
		realK      int       = k
		fast       *ListNode = head
		slow       *ListNode = head
	)
	for p != nil {
		listLength++
		p = p.Next
	}
	if listLength == 0 {
		return head
	}
	realK = k % listLength

	if realK == 0 {
		return head
	}

	// 快慢指针，快指针先走realK步，然后慢指针和快指针一起往后走，直到快指针到达链表末尾
	for i := 0; i < realK; i++ {
		fast = fast.Next
	}

	for fast.Next != nil {
		slow = slow.Next
		fast = fast.Next
	}
	fast.Next = head
	head = slow.Next
	slow.Next = nil
	return head
}

func Solution61() {
	// head := &ListNode{1, &ListNode{2, &ListNode{3, &ListNode{4, &ListNode{5, nil}}}}}
	var head *ListNode = nil
	head = rotateRight(head, 0)
	for head != nil {
		fmt.Println(head.Val)
		head = head.Next
	}
}
