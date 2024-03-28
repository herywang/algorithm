package solution

import "fmt"

// 反转二叉树
func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}
	var inverse func(*TreeNode)
	inverse = func(node *TreeNode) {
		if node == nil {
			return
		}
		node.Left, node.Right = node.Right, node.Left
		inverse(node.Left)
		inverse(node.Right)
	}
	inverse(root)
	return root
}

func Solution226() {
	root := &TreeNode{
		Val: 1,
		Left: &TreeNode{
			Val:   2,
			Left:  &TreeNode{Val: 3},
			Right: &TreeNode{Val: 4},
		},
		Right: &TreeNode{Val: 5},
	}

	invertTree(root)

	preorder(root)
}

func preorder(root *TreeNode) {

	if root == nil {
		return
	}
	fmt.Println(root.Val)
	preorder(root.Left)
	preorder(root.Right)
}
