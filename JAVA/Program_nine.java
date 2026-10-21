import java.util.Scanner;

public class Program_nine
{
	public static void main(String args[])
	{
		Scanner scanner = new Scanner(System.in);
		int x, y;
		
		System.out.println("Enter your element in x matrix");
		x = scanner.nextInt();
		
		System.out.println("Enter your element in y matrix");
		y = scanner.nextInt();
		
		int[][] a = new int[x][y];
		
		System.out.println("Enter the elements of Matrix A:");
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				a[i][j] = scanner.nextInt();
			}
		}
		
		
		int[][] b = new int[x][y];
		System.out.println("Enter the elements of Matrix B:");
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				b[i][j] = scanner.nextInt();
				}
		}
		
		int[][] c = new int[x][y];
		
		
		//Addition
		
		System.out.println("Addition Of Matrix A & B:");
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				
				c[i][j] += a[i][j] + b[i][j];
				System.out.print(c[i][j] + " ");
			}
			System.out.println();
		}
		
		//Subtraction
		
		System.out.println("Subtraction Of Matrix A & B:");
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				c[i][j] = a[i][j] - b[i][j];
				System.out.print(c[i][j] + " ");
			}
			System.out.println();
		}
		
		//Multiplication
		System.out.println("Multiplication Of Matrix A & B:");
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				c[i][j] = 0;
				for (int k = 0; k < y; k++)
				{
					c[i][j] += a[i][k] * b[k][j];
				}
				System.out.print(c[i][j] + " ");
			}
			System.out.println();
		}
		
		//transpose
		System.out.println("Transpose Of Matrix:");
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				c[j][i] = b[i][j];
				System.out.print(c[j][i] + " ");
			}
			System.out.println();
		}
		
		
		//inverse
		System.out.println("inverse Of Matrix");
		double[][] m = 
		{
			{1.0, 2.0},
			{3.0, 4.0}
		};
		double[][] n = new double[2][2];

		double det = (m[0][0] * m[1][1]) - (m[0][1] * m[1][2-1]);// 2-1 is index 1

			// Step 3: Print the result
			System.out.println("Inverse Of Matrix ");
			for (int i = 0; i < 2; i++) 
			{
				for (int j = 0; j < 2; j++) 
				{
					System.out.print(n[i][j] + " ");
				}
				System.out.println();
			}
	}
}
