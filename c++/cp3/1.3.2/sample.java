import java.util.*;

public class sample{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        //THE NUMBER OF CASES GIVEN AT FIRST LINE OF INPUT
        /*int TC, a, b;
        TC = scan.nextInt();
        while(TC > 0){
            a = scan.nextInt();
            b = scan.nextInt();
            System.out.println(a+b);
            TC--;
        }
        */

        //THE INPUT ENDS WHEN BOTH NUMBERS ARE 0
        /*
        int a, b;
        a = scan.nextInt();
        b = scan.nextInt();
        while(a != 0 && b != 0){
            System.out.println(a + b);
            a = scan.nextInt();
            b = scan.nextInt();
        }*/

        //THE INPUT ENDS WHEN THE FILE ENDS
        /*
        int a, b;
        while(scan.hasNextInt()){
            a = scan.nextInt();
            b = scan.nextInt();
            System.out.println(a + b);
        }
        */

        //PRINTING CASE [NUMBER]: [ANSWER]
        /*
        int a, b, c = 1;
        while(scan.hasNextInt()){
            a = scan.nextInt();
            b = scan.nextInt();
            if(c>1) System.out.printf("\n");
            System.out.printf("Case %d: %d\n", c++, a+b);
        }
        */

        //SUM WITHOUT THE N TO TELL HOW MANY INTEGERS HAVE TO SUM
        /*String a[];
        int b = 0;
        while(scan.hasNextLine()){
            a = scan.nextLine().split(" ");
            for(String s: a){
                b += Integer.valueOf(s);
            }   
            System.out.println(b);
            b = 0;
        }*/
    }    
}