import java.util.Arrays;

public class SProgram { 
    public static void main(String[] args) {
        
		//srting convert to integer
        int[] num = new int[args.length];
        for (int i = 0; i < args.length; i++) {
            num[i] = Integer.parseInt(args[i]);
        }

        //Sort values
        System.out.println("\nsorted values:");  
		for (int i = 0; i < num.length - 1; i++) 
		{
			for (int j = 0; j < num.length - 1 ; j++) 
			{
				if (num[j] > num[j + 1]) 
				{
					int temp = num[j];
					num[j] = num[j + 1];
					num[j + 1] = temp;
				}
			}
		}
        for (int n : num) {
            System.out.println(n);
        }
			 
        //max and min values
        
        int minValue = num[0];
        int maxValue = num[num.length - 1];
			
        System.out.println("\nmax values:");
        System.out.println(maxValue);
			
        System.out.println("\nmin value:");
        System.out.println(minValue);
    } 
}





