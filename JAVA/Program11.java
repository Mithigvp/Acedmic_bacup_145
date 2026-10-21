import java.util.Scanner;

interface Shape1
{
	public double area();
	public double perimeter();
}

class Rectangle1 implements Shape1
{
	 double l, w ;

    public Rectangle1() 
    {
        l = 10 ;
        w = 20 ;
    }
	 public Rectangle1(double l ,double w) 
    {
        this.l = l ;
        this.w = w ;
    }
	public double area()
    {
        return l * w ;
    }

    public double perimeter()
    {
        return 2 * (l + w) ;
    }
}
class Triangle1 implements Shape1
{
	double base, h, l, b ;

    public Triangle1() 
    {
        base = 5 ;
        h = 10 ;
        l = 15 ;
        b = 20 ;
    }

    public Triangle1(double base, double h, double l, double b) 
    {
        this.base = base ;
        this.h = h ;
        this.l = l ;
        this.b = b ;
    }

    public double area()
    {
        return 0.5 * (base * h) ;
    }

    public double perimeter()
    {
        return base + l + b ;
    }
}
class Circle1 implements Shape1
{
	double r;
	
	public Circle1()
	{
		r = 10;
	}
	
	public Circle1(double r)
	{
		this.r = r;
	}
	
	public double area()
	{
		return Math.PI*r*r;
		
	}
	public double perimeter()
	{
		
		return 2*Math.PI*r;
	}
}


class Program11
{
    public static void main(String[] args)
    {

        Scanner sc = new Scanner(System.in) ;

        System.out.println("\n ---------- Rectangle Class -------------");
        System.out.println("\n Select Perameters For Rectangle");
        System.out.println(" 1. Default Perameters");
        System.out.println(" 2. User Entered Perameters");
        System.out.println(" ---------------------------------------- ");

        System.out.print("\n\n Enter Your Choice = ");
        int ch = sc.nextInt() ;

        Rectangle1 rec = new Rectangle1(); 

        switch (ch) 
        {
            case 1:
            {
                System.out.println("\n Selecting Default Values.....");
                break;
            }

            case 2:
            {
                System.out.print("\n\n Enter Rectangle Length = ");
                double l = sc.nextDouble() ;
                System.out.print("\n\n Enter Rectangle Width = ");
                double b = sc.nextDouble() ;
                rec = new Rectangle1(l, b);
                break;
            }

            default:
            {
                System.out.println("\n Invalid Choice!! \n Selecting Default Values.....");
            }
        }

        System.out.println("\n ---------- Rectangle Class Output -------------");
        System.out.println("\n Length Of Rectangle = " + rec.l);
        System.out.println("\n Width Of Rectangle = " + rec.w);
        System.out.println("\n Area Of Rectangle = " + rec.area());
        System.out.println("\n Perimeter Of Rectangle = " + rec.perimeter());
        System.out.println("\n ----------------------------------------");

        Triangle1 tri = new Triangle1();
        System.out.println("\n ---------- Triangle Class -------------");
        System.out.println("\n Select Perameters For Triangle");
        System.out.println(" 1. Default Perameters");
        System.out.println(" 2. User Entered Perameters");
        System.out.println(" ---------------------------------------- ");

        System.out.print("\n\n Enter Your Choice = ");
        ch = sc.nextInt() ;

        switch (ch) 
        {
            case 1:
            {
                System.out.println("\n Selecting Default Values.....");
                break;
            }

            case 2:
            {
                System.out.print("\n\n Enter Triangle Base = ");
                double base = sc.nextDouble() ;
                System.out.print("\n\n Enter Triangle Hight = ");
                double h = sc.nextDouble() ;
                System.out.print("\n\n Enter Triangle's another Line's Length = ");
                double l = sc.nextDouble() ;
                System.out.print("\n\n Enter Triangle's another Line's Length = ");
                double b = sc.nextDouble() ;
                tri = new Triangle1(base, h, l, b);
                break;
            }

            default:
            {
                System.out.println("\n Invalid Choice!! \n Selecting Default Values.....");
            }
        }

        System.out.println("\n ---------- Triangle Class Output -------------");
        System.out.println("\n Base Of Triangle = " + tri.base);
        System.out.println("\n Hight Of Triangle = " + tri.h);
        System.out.println("\n Lenght Of Another 2 Lines Of Triangle Are = " + tri.l + ", " + tri.b);
        System.out.println("\n Area Of Triangle = " + tri.area());
        System.out.println("\n Perimeter Of Triangle = " + tri.perimeter());
        System.out.println("\n ----------------------------------------");

        Circle1 cir = new Circle1() ;
        System.out.println("\n ---------- Circle Class -------------");
        System.out.println("\n Select Perameters For Triangle");
        System.out.println(" 1. Default Perameters");
        System.out.println(" 2. User Entered Perameters");
        System.out.println(" ---------------------------------------- ");

        System.out.print("\n\n Enter Your Choice = ");
        ch = sc.nextInt() ;

        switch (ch) 
        {
            case 1:
            {
                System.out.println("\n Selecting Default Values.....");
                break;
            }

            case 2:
            {
                System.out.print("\n\n Enter Circle Radius = ");
                double r = sc.nextDouble() ;
                cir = new Circle1(r);
                break;
            }

            default:
            {
                System.out.println("\n Invalid Choice!! \n Selecting Default Values.....");
            }
        }

        System.out.println("\n ---------- Circle Class Output -------------");
        System.out.println("\n Radius Of Circle = " + cir.r);
        System.out.println("\n Area Of Circle = " + cir.area());
        System.out.println("\n Perimeter Of Circle = " + cir.perimeter());
        System.out.println("\n ----------------------------------------");
    }
}