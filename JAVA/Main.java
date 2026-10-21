import java.util.Scanner;
import org.gvp.dcs.ds.Stack;
import org.gvp.dcs.ds.Queue;
import org.gvp.dcs.shapes.Sphere;
import org.gvp.dcs.shapes.Cube;

public class main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		Stack stack = new Stack(5);
		Queue queue = new Queue(5);
		Sphere sphere = new Sphere(5);
        Cube cube = new Cube(4);
		
		int ch, value;
		do 
		{
			System.out.println("------ main menu ------\n");
			System.out.println("1. stack \n");
			System.out.println("2. Queue \n");
			System.out.println("3. Sphere \n");
			System.out.println("4. Cube \n");
			System.out.println("5. Exit");
				
			System.out.println("Enter you choice ::");
			ch = sc.nextInt();
				
			switch(ch)
			{
				case 1:
					System.out.println("\n--- STACK ---");
					System.out.println("1. Push");
					System.out.println("2. Pop");
					System.out.println("3. Peek");
					System.out.println("4. Display");
						
					System.out.print("Enter choice: ");
					int s = sc.nextInt();
						
					switch (s) 
					{
						case 1:
							System.out.print("Enter value: ");
							value = sc.nextInt();
							stack.push(value);
							break;

						case 2:
							System.out.println("Popped: " + stack.pop());
							break;

						case 3:
							System.out.println("Top: " + stack.peek());
							break;

						case 4:
							stack.display();
							break;

						default:
							System.out.println("Invalid choice!");
					}
					break;
					
					
				case 2:
					System.out.println("\n--- queue ---");
					System.out.println("1. enqueue");
					System.out.println("2. dequeue");
					System.out.println("3. Peek");
					System.out.println("4. Display");
						
					System.out.print("Enter choice: ");
					int q = sc.nextInt();
						
					switch (q) 
					{
						case 1:
							System.out.print("Enter value: ");
							value = sc.nextInt();
							queue.enqueue(value);
							break;

						case 2:
							System.out.println("dequeue:: " + queue.dequeue());
							break;

						case 3:
							System.out.println("Top: " + queue.peek());
							break;

						case 4:
							queue.display();
							break;

						default:
							System.out.println("Invalid choice!");
					}
					break;
				
				case 3:
                    System.out.println("\n--- SPHERE ---");
                    System.out.printf("Volume: %.2f%n", sphere.volume());
                    System.out.printf("Surface Area: %.2f%n", sphere.surfaceArea());
                    break;
					
				case 4:
                    System.out.println("\n--- CUBE ---");
                    System.out.printf("Volume: %.2f%n", cube.volume());
                    System.out.printf("Surface Area: %.2f%n", cube.surfaceArea());
                    break;

                case 5:
                    System.out.println("Exiting program...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }
			
		}	while (ch != 5);
	}
}