import java.io.*;		//STRING TOKENIZER
import java.util.*;


class Token
{
	public static void main(String arg[])
	{
		Scanner sc = new Scanner(System.in);
		String s1;
		int n,sum=0,count=1;
		System.out.println("ENTER INTEGERS : ");
		String s = sc.nextLine();
		StringTokenizer st = new StringTokenizer(s," ");
		while (st.hasMoreTokens()) 
		{
            		s1 = st.nextToken();
            		n = Integer.parseInt(s1);
            		System.out.println(count+ " INTEGER : "+n);
            		sum+=n;
            		count++;
        	}
        System.out.println("SUM OF ENTERED INTEGERS ARE : " + sum);
        sc.close();
	}
}
