import java.util.*;

public class FirstProgram
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        int n;
        System.out.print("Enter Number : ");
        n = s.nextInt();
        // Prime Number
        if(n <= 1)
        {
            System.out.println(n + " is Not Prime");
        }
        else
        {
            boolean prime = true;

            for(int i = 2; i <= n / 2; i++)
            {
                if(n % i == 0)
                {
                    prime = false;
                    break;
                }
            }

            if(prime)
            {
                System.out.println(n + " is Prime");
            }
            else
            {
                System.out.println(n + " is Not Prime");
            }
		}
        //if-else
        if(n > 0)
        {
            System.out.println("n is Greterthan 0 ");
        }
        else
        {
            System.out.println("n is Lessthan 0");
        }
        //break and continue
        for(int i = 1; i<=10; i++)
        {
            if(i == 4)
            {
                continue;
            }

            if(i == 7)
            {
                break;
            }

            System.out.println("For: " + i);
        }
        //while
        int j = 1;

        while(j <= 5)
        {
            System.out.println("while : " + j);
            j++;
        }
        //do-while
        int m = 1;

        do
        {
            System.out.println("do-while : " + m);
            m++;
        }
        while(m <= 4);
    }
}