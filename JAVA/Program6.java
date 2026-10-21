class Student{
	String name;
	int rollno;
	double marks;
	
	void displaydetails(){
		
		System.out.println("Student name is :: " + name);
		System.out.println("Student roll number is :: " + rollno);
		System.out.println("Student marks is :: " + marks);
	}
}

public class Program6{
	public static void main(String[] args){
	
		Student stu = new Student();
	
		stu.name = "Mithilesh";
		stu.rollno = 101;
		stu.marks = 85.5;
	
		stu.displaydetails();
	}
}