package solution

import (
	"fmt"
	"regexp"
	"strings"
)

func simplifyPath(path string) string {
	reg, _ := regexp.Compile("/+")
	path = reg.ReplaceAllString(path, "/")
	splitString := strings.Split(path, "/")
	var res []string = make([]string, 0)
	for _, s := range splitString {
		if s == "." || s == "" {
			continue
		} else if s == ".." {
			if len(res) > 0 {
				res = res[:len(res)-1]
			}
		} else {
			res = append(res, s)
		}
	}
	return "/" + strings.Join(res, "/")
}

// 简化路径
func Solution71() {
	fmt.Println(simplifyPath("/a/./b/../../c/"))
}
