package solution

import "fmt"

// Zigzag conversion
func convert_low_performance(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	nCols := (len(s) / (numRows + numRows - 2)) * (numRows - 1)
	t := len(s) % (numRows + numRows - 2)
	if t != 0 {
		if t <= numRows {
			nCols += 1
		} else {
			nCols += (t - numRows + 1)
		}
	}

	resArray := make([][]string, numRows)
	for i := range resArray {
		resArray[i] = make([]string, nCols)
	}

	for i := 0; i < len(resArray); i++ {
		for j := 0; j < len(resArray[i]); j++ {
			resArray[i][j] = " "
		}
	}

	col2 := 0

	for strIndex := 0; strIndex < len(s); {
		for i := 0; i < numRows && strIndex < len(s); i++ {
			resArray[i][col2] = string(s[strIndex])
			strIndex++
		}

		col2 += 1
		for i := numRows - 2; i > 0 && strIndex < len(s); i-- {
			resArray[i][col2] = string(s[strIndex])
			strIndex++
			col2 += 1
		}
	}

	var resStr string = ""

	for index1 := range resArray {
		for index2 := range resArray[index1] {
			fmt.Print(resArray[index1][index2])
			if ss := resArray[index1][index2]; ss != " " {
				resStr += ss
			}
		}
		fmt.Println()
	}

	return resStr
}

func convert(s string, numRows int) string {
	if numRows <= 1 {
		return s
	}
	var reachedEdge bool = true
	var currentLine int = 0

	var lines []string = make([]string, numRows)
	for i := 0; i < len(lines); i++ {
		lines[i] = ""
	}

	for i := 0; i < len(s); i++ {
		if currentLine == 0 || currentLine == numRows-1 {
			reachedEdge = !reachedEdge
		}
		lines[currentLine] += string(s[i])
		if reachedEdge {
			currentLine--
		} else {
			currentLine++
		}
	}

	var res string = lines[0]
	for i := 1; i < numRows; i++ {
		res += lines[i]
	}
	return res
}

func Solution6() {
	fmt.Println(convert("PAYPALISHIRING", 3))
	fmt.Println(convert("PAYPALISHIRING", 4))
}
