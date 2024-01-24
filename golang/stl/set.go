package stl

type Setter interface {
	Add(item string)
	Remove(item string)
	Has(item string) bool
	Contains(item string) bool
}

type Set map[string]bool

func (s Set) Add(item string) {
	s[item] = true
}

func (s Set) Remove(item string) {
	delete(s, item)
}

func (s Set) Has(item string) bool {
	_, ok := s[item]
	return ok
}
