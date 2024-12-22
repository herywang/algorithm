package solution

import "fmt"

// 二叉树层序遍历
func levelOrder(root *TreeNode) [][]int {
	var (
		ans   [][]int     = make([][]int, 0)
		queue []*TreeNode = make([]*TreeNode, 0)
	)
	if root == nil {
		return ans
	}
	queue = append(queue, root)
	for len(queue) > 0 {
		limit := len(queue)
		level := make([]int, limit)
		for i := 0; i < limit; i++ {
			level[i] = queue[0].Val
			if queue[0].Left != nil {
				queue = append(queue, queue[0].Left)
			}
			if queue[0].Right != nil {
				queue = append(queue, queue[0].Right)
			}
			queue = queue[1:]
		}
		ans = append(ans, level)
	}
	return ans
}

func Solution102() {
	var root *TreeNode = &TreeNode{
		Val: 3,
		Left: &TreeNode{
			Val:   9,
			Left:  nil,
			Right: nil,
		},
		Right: &TreeNode{
			Val:   20,
			Left:  &TreeNode{Val: 15, Left: nil, Right: nil},
			Right: &TreeNode{Val: 7, Left: nil, Right: nil},
		},
	}
	fmt.Println(levelOrder(root))
}
