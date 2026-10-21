import java.util.*;

class Stack 
{
    int top;
    int[] s;

	public void Stack() 
	{
        top = -1;
        s = new int[5];   
    }

    public void Stack(int size) 
	{
        top = -1;
        s = new int[size];   
    }

	public void push(int value)
	{
		++top;
		if(top >= s.length)
		{
			System.out.println("Stack is overflow " + value);
			--top;
		}else
		{
			s[top] = value;
			System.out.println("successfully insert values");
		}
	}
	
	public int pop()
	{
		if(top < 0)
		{
			System.out.println("Stack is underflow ");
			return -1;
		}
		else 
		{
			int ele = s[top];
			--top;
			return ele;
		}
	}
	
	public void traverse()
	{
		if(top < 0)
		{
			System.out.println("Stack is empty");
		}
		for (int i = top; i >= 0; i--) 
		{ 
            System.out.print(s[i] + " \n");
        }
        System.out.println();
	}
}  
	public class Program8
	{
		public static void main(String[] args)
		{	
			Scanner sc = new Scanner(System.in);
			
			//System.out.print("Enter your stack size :: ");
			//int size = sc.nextInt();
			
			Stack stack = new Stack();
			
			 System.out.println(" 1. default size [5]");
			 System.out.print(" 2. custom size");
			 
			 System.out.print("select your :: ");
			 int size = sc.nextInt();
			 switch(size)
			 {
				 case 1:
					stack.Stack();
					break;
					
				case 2:
					System.out.print("Enter your stack size :: ");
					size = sc.nextInt();
					stack.Stack(size);
					break;
					
				default :
					System.out.println("invalide choice");
					break;
			 }
	
			while(true)
			{
				System.out.println("Stack manu");
				System.out.println(" 1. push");
				System.out.println(" 2. pop");
				System.out.println(" 3. traverse");
				System.out.println(" 4. exit");
					
				System.out.print(" Enter your choice :: ");
				int ch = sc.nextInt();
					
				switch(ch)
				{
					case 1:
						System.out.print(" Enter your values :: ");
						int val = sc.nextInt();
						stack.push(val);
						break;
							
					case 2:
						if(stack.top < 0)
						{
							System.out.println("Stack is underflow ");
							break;
						}
						else 
						{
							System.out.println(" remove element " + stack.pop());
						}
						
					case 3:
						stack.traverse();
						break;
							
					case 4:
						System.exit(0);
							
					default :
						System.out.println("invalide choice ! pls choice valide number 1 to 4");
						break;
				}
			}
		}
	}
