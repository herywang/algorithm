package stl

import "errors"

type Stacker interface {
	Pop() (any, error)
	Push(val any)
	IsEmpty() bool
	Top() (any, error)
}

type Stack struct {
	ElementData []any
}

func (s *Stack) IsEmpty() bool {
	return len(s.ElementData) == 0
}

func (s *Stack) Pop() (any, error) {
	if s.IsEmpty() {
		return -1, errors.New("empty stack error")
	}
	res := s.ElementData[len(s.ElementData)-1]
	s.ElementData = s.ElementData[:len(s.ElementData)-1]
	return res, nil
}

func (s *Stack) Push(val any) {
	s.ElementData = append(s.ElementData, val)
}

func (s *Stack) Top() (any, error) {
	if s.IsEmpty() {
		return 0, errors.New("empty stack error")
	}
	return s.ElementData[len(s.ElementData)-1], nil
}
