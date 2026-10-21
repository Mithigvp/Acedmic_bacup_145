import java.util.Scanner;

public class FourthProgram
{
	public static void main(String args[])
	{
		Scanner scanner = new Scanner(System.in);
		int[][] a = new int[3][3];
		System.out.println("---Two Dimensional Array---");
		System.out.println("Enter the elements of Matrix A:");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				a[i][j] = scanner.nextInt();
			}
		}
		
		
		int[][] b = new int[3][3];
		System.out.println("Enter the elements of Matrix B:");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				b[i][j] = scanner.nextInt();
				}
		}
		
		int[][] c = new int[3][3];
		
		
		//Addition
		
		System.out.println("Addition Of Matrix A & B:");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				
				c[i][j] += a[i][j] + b[i][j];
				System.out.print(c[i][j] + " ");
			}
			System.out.println();
		}
		
		//Subtraction
		
		System.out.println("Subtraction Of Matrix A & B:");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				c[i][j] = a[i][j] - b[i][j];
				System.out.print(c[i][j] + " ");
			}
			System.out.println();
		}
		
		//Multiplication
		System.out.println("Multiplication Of Matrix A & B:");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				c[i][j] = 0;
				for (int k = 0; k < 3; k++)
				{
					c[i][j] += a[i][k] * b[k][j];
				}
				System.out.print(c[i][j] + " ");
			}
			System.out.println();
		}
	}
}