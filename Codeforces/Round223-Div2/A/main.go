package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanln(&n)
	card := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &card[i])
	}
	var l, r int = 0, n - 1
	var a, b int = 0, 0
	for i := 0; i < n; i++ {
		var temp int = 0
		if card[l] > card[r] {
			temp = card[l]
			l++
		} else {
			temp = card[r]
			r--
		}
		if i&1 == 1 {
			b += temp
		} else {
			a += temp
		}
	}
	fmt.Println(a, b)
}
