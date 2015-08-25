import java.util.*;

class Main{
    public static void main(String args[]){
	Scanner s = new Scanner(System.in);
	String a = "";
	while(s.hasNextLine()){
	    int arr[] = new int[26];
	    for(int i=0;i<26;i++)
		arr[i] = 0;
	    a = s.nextLine();
	    if(a.isEmpty())
		continue;
	    if(a.charAt(0) == '*')
		break;
	    a = a.trim();
	    String []sa = a.split(" ");
	    for(int i=0;i<sa.length;i++){
		arr[sa[i].toLowerCase().charAt(0) - 'a']++;
	    }
	    int count = 0;
	    for(int i=0;i<26;i++){
		if(arr[i]>0)
		    count++;
	    }
	    if(count==1)
		System.out.println("Y\n");
	    else
		System.out.println("N\n");
	    
		
	}
    }
}
	    
