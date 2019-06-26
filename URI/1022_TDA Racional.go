
package main

import (
	"fmt"
)

func gcd(temp1,temp2 int) int {
	gcdnum := 1
	if temp1 < 0 {
		temp1 = -temp1
	}
	if temp2 < 0 {
		temp2 = -temp2
	}
	for i := 1; i <=temp1 && i <=temp2 ; i++ {
		if temp1%i==0 && temp2%i==0 {
			gcdnum=i
		}
	}
	return gcdnum
}

func main() {
	var (
		T, n1,n2,d1,d2 int
		c string
		n0, d0 int
	)

	fmt.Scanf("%d\n", &T)
	for i := 0; i < T; i++ {
		_, _ = fmt.Scanf("%d / %d %s %d / %d\n",&n1,&d1,&c,&n2,&d2)
		switch c {
		case "+":
			n0 = n1 * d2 + n2 * d1
			d0 = d1 * d2
		case "-":
			n0 = n1 * d2 - n2 * d1
			d0 = d1 * d2
		case "*":
			n0 = n1 * n2
			d0 = d1 * d2
		case "/":
			n0 = n1 * d2
			d0 = n2 * d1
		}
		_gcd := gcd(n0,d0)
		fmt.Printf("%d/%d = %d/%d\n", n0,d0,n0/_gcd,d0/_gcd )
	}

}
