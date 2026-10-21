 class UserDefineException{
	public void Negative(int num)throws NegativeValueException
	{
		if(num < 0)
		{
			throw new NegativeValueException("negative value :: " + num + ")");
		}	
		System.out.println("\n value is positive :: " + num);
	}
}

class NegativeValueException extends Exception {
    public NegativeValueException(String message) {
        super(message); 
    }
}
 
public class Program12{
	public static void main(String[] args){
		UserDefineException ud = new UserDefineException() ;
        int num = Integer.parseInt(args[0]);
		try
		{
				 ud.Negative(num);
		}
		catch(NegativeValueException e)
		{
			System.out.println(e.getMessage());		
		}
		finally
        {
            System.out.println("\n program is Run");
        }
	}
}