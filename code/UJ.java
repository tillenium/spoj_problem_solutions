import java.util.*;
import java.math.*;

class Main{
    public static void main(String args[]){
	Scanner s = new Scanner(System.in);
	int n,d;
	n = s.nextInt();
	d = s.nextInt();
	while(n>0){
	    BigInteger N = BigInteger.valueOf(n);
    	    BigInteger ans = BigInteger.ONE;
	    ans = N.pow(d);
	    System.out.println(ans);
	    n = s.nextInt();
	    d = s.nextInt();
	}
    }
}
