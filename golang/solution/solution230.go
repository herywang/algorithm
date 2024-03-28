package solution

import "fmt"

func kthSmallest(root *TreeNode, k int) int {
	var inorder func(*TreeNode)
	var ans int
	inorder = func(node *TreeNode) {
		if node == nil {
			return
		}
		inorder(node.Left)
		k--
		if k == 0 {
			ans = node.Val
			return
		}
		inorder(node.Right)
	}
	inorder(root)
	return ans
}

// 二叉搜索树中，查找第k小的数
func Solution230() {
	root := &TreeNode{
		Val: 3,
		Left: &TreeNode{
			Val:   1,
			Left:  nil,
			Right: &TreeNode{2, nil, nil},
		},
		Right: &TreeNode{4, nil, nil},
	}
	fmt.Println(kthSmallest(root, 5))
}
