import java.util.*;
import java.io.*;

class StudentDetails
{
    String name;
    int rollNumber;
    float m1, m2, m3;

    void setdata(String name, int rollNumber, float m1, float m2, float m3)
    {
        this.name = name;
        this.rollNumber = rollNumber;
        this.m1 = m1;
        this.m2 = m2;
        this.m3 = m3;
    }

    void create_file()
    {
        try
        {
            File st = new File("Student.txt");

            if (st.createNewFile())
            {
                System.out.println("File created: " + st.getName());
            }
            else
            {
                System.out.println("File already exists.");
            }
        }
        catch (IOException e)
        {
            System.out.println("An error create file: ");
			e.printStackTrace();
        }
    }

    void filewrite()
    {
        try
        {
            FileWriter fw = new FileWriter("Student.txt", true);
			fw.append("\tName \tRollno \tSub1 \tSub2 \tSub3" + "\n");
            fw.append(" " + this.name + "\t" + this.rollNumber + "\t" 
			+ this.m1 + "\t" + this.m2 + "\t" + this.m3 + "\n");
            fw.close();
            System.out.println("\nFile written successfully");
        }
        catch (IOException e)
        {
             System.out.println("An error write the file: ");
			 e.printStackTrace();
        }
    }
}

public class Program14
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter your roll number :: ");
        int rollNumber = sc.nextInt();

        sc.nextLine();

        System.out.print("Enter your Name :: ");
        String name = sc.nextLine();

        System.out.print("Enter your sub1 marks :: ");
        float sub1 = sc.nextFloat();

        System.out.print("Enter your sub2 marks :: ");
        float sub2 = sc.nextFloat();

        System.out.print("Enter your sub3 marks :: ");
        float sub3 = sc.nextFloat();

        System.out.println("\nStudent roll number :: " + rollNumber);
        System.out.println("Student name :: " + name);
        System.out.println("Student sub1 marks :: " + sub1);
        System.out.println("Student sub2 marks :: " + sub2);
        System.out.println("Student sub3 marks :: " + sub3);

        StudentDetails st = new StudentDetails();

        st.setdata(name, rollNumber, sub1, sub2, sub3);
        st.create_file();
        st.filewrite();
    }
}