package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scanln(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	sort.Ints(a)
	var max int = a[n-1]
	var fi, se []int
	var pf, ps int = max, max
	for i := n - 1; i >= 0; i-- {
		if a[i] < pf {
			fi = append(fi, a[i])
			pf = a[i]
		} else if a[i] < ps {
			se = append(se, a[i])
			ps = a[i]
		}
	}
	var len_fi, len_se int = len(fi), len(se)
	fmt.Println(len_fi + len_se + 1)
	for i := len_fi - 1; i >= 0; i-- {
		fmt.Printf("%d ", fi[i])
	}
	fmt.Printf("%d", max)
	for i := 0; i < len_se; i++ {
		fmt.Printf(" %d", se[i])
	}
	fmt.Println()
}
