import java.util.*;
import java.io.*;

public class Program15
{
    public static void main(String[] args)
    {
        try
        {
            File st = new File("Student.txt");
            Scanner sc = new Scanner(st);

            if (!sc.hasNextLine())
            {
                System.out.println("File has no data");
            }
            else
            {
                while (sc.hasNextLine())
                {
                    String data = sc.nextLine().trim();

                    if (data.isEmpty())
                    {
                        continue;
                    }

              
                    String[] details = data.split("\\t");

                    if (details[0].trim().equalsIgnoreCase("Name"))
                    {
                        continue;
                    }

                    String name = details[0].trim();
                    int rollNumber = Integer.parseInt(details[1].trim());

                    float m1 = Float.parseFloat(details[2].trim());
                    float m2 = Float.parseFloat(details[3].trim());
                    float m3 = Float.parseFloat(details[4].trim());

                    float total = m1 + m2 + m3;
                    float percentage = (total / 300) * 100;

                    System.out.println("\nStudent Name: " + name);
                    System.out.println("Roll Number: " + rollNumber);
                    System.out.println("Subject 1 Marks: " + m1);
                    System.out.println("Subject 2 Marks: " + m2);
                    System.out.println("Subject 3 Marks: " + m3);
                    System.out.println("Total Marks: " + total);

                    System.out.printf("Percentage: %.2f%%%n", percentage);
                }
            }

        }
        catch (FileNotFoundException e)
        {
            System.out.println("File is not found");
        }
        catch (NumberFormatException e)
        {
            System.out.println("Invalid marks or roll number in the file");
        }
    }
}