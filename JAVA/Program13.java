class OddThread extends Thread 
{
  public void run() 
  {
	int i;
	
	for(i = 0; i<100 ; i++)
	{
		if(i%2 != 0)
		{
			System.out.println("num : " + i );
		}
		
		try 
		{
			Thread.sleep(500);
		} 
		catch (InterruptedException e) 
		{
            e.printStackTrace();
		}
	}
  }
}

class PrimeThread implements Runnable 
{
	public void run() 
  {
	 for (int n = 2; n < 100; n++) 
	 {
            int count = 0;
            for (int i = 1; i <= n; i++) 
			{
                if (n % i == 0) 
				{
                    count++;
                }
            }

            if (count == 2) 
			{
                System.out.println("Prime : " + n);
            }
		try 
		{
			Thread.sleep(1000);
		} 
		catch (InterruptedException e) 
		{
            e.printStackTrace();
		}
	}
  }
}
public class Program13
{
	public static void main(String[] args) 
	{
			
		OddThread ot = new OddThread();
		ot.start();		
		PrimeThread pt = new PrimeThread();
		Thread primeThreadWrapper = new Thread(pt);
		primeThreadWrapper.start();
	}	
}