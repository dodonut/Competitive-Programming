
package main

import (
	"fmt"
	"sort"
)

func main() {
	var (
		n,q = -1,-1
		tmp int
		count = 1
	)
	_, _ = fmt.Scanf("%d %d\n", &n, &q)
	for n != 0 && q != 0 {
		fmt.Printf("CASE# %d:\n", count)
		count++

		arr := make([]int, n+1)
		for i:=0; i < n; i++{
			_, _ =fmt.Scanf("%d\n", &tmp)
			arr[i] = tmp
		}
		sort.Ints(arr)
		for i := 0; i < q; i++{
			_, _ =fmt.Scanf("%d\n", &tmp)
			val := sort.SearchInts(arr, tmp)
			if val < len(arr) && arr[val] == tmp {
				fmt.Printf("%d found at %d\n", tmp, val)
			} else {
				fmt.Printf("%d not found\n", tmp)
			}

		}
		arr = nil
		_, _ = fmt.Scanf("%d %d\n", &n, &q)
	}

}
