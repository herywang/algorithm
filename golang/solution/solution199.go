package solution

import "fmt"

// 二叉树的右视图

// 方法1 层序遍历
func rightSideView1(root *TreeNode) []int {
	var res []int = make([]int, 0)
	if root == nil {
		return res
	}
	var queue []*TreeNode = make([]*TreeNode, 0)
	queue = append(queue, root)
	for len(queue) > 0 {
		var size int = len(queue)
		for i := 0; i < size; i++ {
			var node *TreeNode = queue[0]
			queue = queue[1:]
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
			if i == size-1 {
				res = append(res, node.Val)
			}
		}
	}
	return res
}

func Solution199() {

	var root *TreeNode = &TreeNode{
		Val:   1,
		Left:  &TreeNode{Val: 2, Left: &TreeNode{Val: 4}, Right: &TreeNode{Val: 5}},
		Right: &TreeNode{Val: 3},
	}

	res := rightSideView1(root)
	fmt.Println(res)
}
