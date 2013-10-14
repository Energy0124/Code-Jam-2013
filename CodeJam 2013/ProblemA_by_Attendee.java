import java.util.*;
public class Main{
	public static void main(String[] args)
	{
	    Scanner sc = new Scanner(System.in);
		 int n = sc.nextInt();
		 int k = sc.nextInt();
		 long[][] f = new long[20][20];
		 for(int i = 1; i <= k-1; i++) f[1][i] = 1;
		 for(int i = 2; i <= n; i++)
			{
				for(int j = 1; j<= k-1; j++) 
				   for(int t = 0; t <= k-1; t++) f[i][j] += f[i-1][t];
				for(int t = 1; t <= k-1; t++) f[i][0] += f[i-1][t];
			};
		 long result = 0;
		 for(int i = 0;i<=k-1;i++) result += f[n][i];
		 System.out.println(result);
	};
};