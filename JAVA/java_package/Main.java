
import java.util.Scanner;
import org.gvp.dcs.ds.Stack;
import org.gvp.dcs.ds.Queue;
import org.gvp.dcs.shapes.Sphere;
import org.gvp.dcs.shapes.Cube;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        Stack stack = new Stack(5);
        Queue queue = new Queue(5);
        Sphere sphere = new Sphere(5);
        Cube cube = new Cube(4);

        int ch, value;

        do {
            System.out.println("\n------ MAIN MENU ------");
            System.out.println("1. Stack");
            System.out.println("2. Queue");
            System.out.println("3. Sphere");
            System.out.println("4. Cube");
            System.out.println("5. Exit");

            System.out.print("Enter your choice: ");
            ch = sc.nextInt();

            switch (ch) {

                case 1:
                    System.out.println("\n--- STACK ---");
                    System.out.println("1. Push");
                    System.out.println("2. Pop");
                    System.out.println("3. Peek");
                    System.out.println("4. Display");
                    System.out.println("5. Back to Main Menu");

                    System.out.print("Enter choice: ");
                    int s = sc.nextInt();

                    switch (s) {
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

                        case 5:
                            System.out.println("Returning to main menu...");
                            break;

                        default:
                            System.out.println("Invalid choice!");
                    }
                    break;

                case 2:
                    System.out.println("\n--- QUEUE ---");
                    System.out.println("1. Enqueue");
                    System.out.println("2. Dequeue");
                    System.out.println("3. Peek");
                    System.out.println("4. Display");
                    System.out.println("5. Back to Main Menu");

                    System.out.print("Enter choice: ");
                    int q = sc.nextInt();

                    switch (q) {
                        case 1:
                            System.out.print("Enter value: ");
                            value = sc.nextInt();
                            queue.enqueue(value);
                            break;

                        case 2:
                            System.out.println(
                                "Dequeued: " + queue.dequeue()
                            );
                            break;

                        case 3:
                            System.out.println(
                                "Front: " + queue.peek()
                            );
                            break;

                        case 4:
                            queue.display();
                            break;

                        case 5:
                            System.out.println("Returning to main menu...");
                            break;

                        default:
                            System.out.println("Invalid choice!");
                    }
                    break;

                case 3:
                    System.out.println("\n--- SPHERE ---");
                    System.out.printf(
                        "Volume: %.2f%n", sphere.volume()
                    );
                    System.out.printf(
                        "Surface Area: %.2f%n",
                        sphere.surfaceArea()
                    );
                    break;

                case 4:
                    System.out.println("\n--- CUBE ---");
                    System.out.printf(
                        "Volume: %.2f%n", cube.volume()
                    );
                    System.out.printf(
                        "Surface Area: %.2f%n",
                        cube.surfaceArea()
                    );
                    break;

                case 5:
                    System.out.println("Exiting program...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (ch != 5);

    }
}
