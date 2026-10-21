import java.util.*;

public class ThrProgram{
	public static void main(String[] args){
		Scanner sc =new Scanner(System.in);
		
		
		System.out.print("Enter the String : ");
		String str = sc.nextLine();
		str = str.toLowerCase(); 
		
		System.out.print("Enter the char : ");
		String c = sc.nextLine();
		c = c.toLowerCase();
		char ch = c.charAt(0);


		int index = 0;
		
		for(int i = 0; i < str.length(); i++ ){
			if(str.charAt(i) == ch){
				System.out.print(i + " ");
				index++;
			}
		}
		System.out.print("Total index: " + index);
	}
}