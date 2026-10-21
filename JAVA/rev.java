import java.util.*;
public class rev{

	public static void main(String [] arge){
		Scanner sc = new Scanner(System.in); 

		int size;
		int i , j;
		char[] revname = "";
		
		System.out.println("enter your String size ::");
		size = sc.nextInt();
		char[] name = new char[size];
		
		for(j = 0; j < size; j++)
		{
			System.out.println("enter your String " + j + " :: ");
			name[j]= sc.next().charAt(0);
		}
		
		for (i = name.length - 1; i >= 0; i--) 
		{
			revname = revname + name[i];
		}
		System.out.println("reverse name is :: " + revname[i]);
	}
}