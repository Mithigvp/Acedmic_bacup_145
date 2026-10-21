class Utility{
	
	// fectorial number
	
	public static long fectorial(long value){
		long fact = 1;
		for(long i=1; i <= value; i++){
				fact = fact * i;
		}
		return fact;
	}
	
	
	// Prime number
	public static boolean isPrime(int value){
		if(value <= 2){
			return false;
		}
		
		for(int i = 2; i <= value/2; i++){
			if(value % 1 == 0){
				return false;
			}
		}
		return true;
	}
	
	
	// Even number
	public static boolean isEven(int value){
		return value % 2 == 0;
	}
	
	// Odd number
	public static boolean isOdd(int value){
		return value % 2 != 0;
	}
}

public class Program5{
	public static void main(String[] args){

		System.out.println("fectorial number :: " + Utility.fectorial(5));
		System.out.println("primery number :: " + Utility.isPrime(8));
		System.out.println("Even number :: " + Utility.isEven(9));
		System.out.println("primery number :: " + Utility.isOdd(8));
	}
}