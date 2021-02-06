import java.util.*;
import java.io.*;

public class anirban {
	// For Globally storing the sum of power of prime factors
	public static int powerSum[] = new int[1000001];

	// For Identifying the factor is prime or not
	public static boolean prime[] = new boolean[1000001];  
	public static int sum[]=new int[1000001];
	public static void sieve()
	{
	    powerSum[0] = 0;
	    powerSum[1] = 1;

	    Arrays.fill(prime , true);

	    prime[0] = false;
	    prime[1] = false;

	    for(int i = 2 ; i <= 1000000 ; i++)     // sieve algorithm
	    {
	        if(prime[i])   // Consider the factor for calculation only if it is prime
	        {
	            for(int j = i ; j <= 1000000 ; j += i)
	            {
	                int tempJ = j;

	                while(tempJ != 0 && tempJ%i == 0)// Counting number of occurance of the factor
	                {
	                    powerSum[j]++;

	                    tempJ /= i;
	                }

	                prime[j] = false;
	            }
	        }
	    }
	    powerSum[1]=0;
	}
	public static void sum()
	{
		sum[0]=powerSum[0];
		for(int i=1;i<=1000000;i++)
		{
			sum[i]=sum[i-1]+powerSum[i];
		}
	}
	public static void main(String args[]) throws IOException
	{   
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		OutputStream o=new BufferedOutputStream(System.out);
	    sieve();
	    sum();
	    int t=Integer.parseInt(br.readLine());
	    for(int j=0;j<t;j++)
	    {
	    	int n=Integer.parseInt(br.readLine());
			for(int i = 0; i < 10; i++) {
				System.out.println(i + ": " + powerSum[i] + " " + sum[i]);
			}
	    	o.write((sum[n]+"\n").getBytes());
	    	o.flush();
	    }


	}
	
}
