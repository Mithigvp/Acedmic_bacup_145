import java.util.*;

class Circle { 
   
    private int x; 
    private int y; 
    private double r; 

    public Circle(int x, int y, double r) { 
	this.x = x; 
	this.y = y; 
	this.r = r; 
	}
	
	public Circle() { 
	x = 5; 
	y = 2; 
	r = 2; 
	}

    public double area() { 
        return Math.PI * this.r * this.r; 
    } 
	public double circumference() { 
        return 2 * Math.PI* this.r; 
    } 
	
	
	public void position(){
		System.out.println("Current position of circle (" + this.x + "," + this.y +")\n");
	}
}
public class Program7{
		public static void main(String[] args) {
			
			Scanner s = new Scanner(System.in); 
			System.out.println("Enter the value of X :: "); 
			int x = s.nextInt(); 
			
			System.out.println("Enter the value of Y :: "); 
			int y = s.nextInt(); 
			
			System.out.println("Enter the value of Radius :: "); 
			double r = s.nextDouble();
			
			Circle obj = new Circle(x, y, r);
			
			System.out.println("parameterized constructors :: "); 
			System.out.println("Area = " + obj.area()); 
			System.out.println("Circumference = " + obj.circumference());
			obj.position();
		
			Circle obj2 = new Circle();
			
			System.out.println("Default constructors :: ");
			System.out.println("\nArea = " + obj2.area()); 
			System.out.println("Circumference = " + obj2.circumference());
			obj2.position();
		}
}
