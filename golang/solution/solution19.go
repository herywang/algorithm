package solution

import "fmt"

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if head == nil {
		return head
	}
	if head.Next == nil && n == 1 {
		return nil
	}
	var newHead *ListNode = &ListNode{0, head}
	var slow, fast *ListNode = newHead, newHead
	for i := 0; i < n; i++ {
		fast = fast.Next
	}
	for fast.Next != nil {
		slow = slow.Next
		fast = fast.Next
	}
	slow.Next = slow.Next.Next
	return newHead.Next
}

func Solution19() {
	var list *ListNode = &ListNode{1, &ListNode{2, &ListNode{3, &ListNode{4, nil}}}}
	var res *ListNode = removeNthFromEnd(list, 3)

	for res != nil {
		fmt.Println(res.Val)
		res = res.Next
	}
}
