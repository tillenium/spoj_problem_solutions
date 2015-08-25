import java.util.*;

class Main{
    public static void main(String args[]){
	Scanner s = new Scanner(System.in);
	long base[] ={0,1,20,360,7200,144000,2880000,57600000};
	int n;
	String maya;
	long ans;
	n = s.nextInt();
	while(n!=0){
	    ans = 0;
	    maya = s.nextLine();
	    for(int i=n-1;i>=0;i--){
		maya = s.nextLine();
		int temp = 0;
		for(int j =0;j<maya.length();j++){
		    if(maya.charAt(j)=='.')
			temp += 1;
		    else if(maya.charAt(j)=='-')
			    temp += 5;

		}
		ans += temp*base[i+1];
	    }
	    System.out.println(ans);
	    n = s.nextInt();
	    
	}
    }
}
	    
