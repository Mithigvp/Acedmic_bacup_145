import java.util.Scanner;

class Matrix
{
    private double[][] data;
    private int rows;
    private int cols;

    // Constructor 1: Allocate matrix
	
    public Matrix(int rows, int cols)
    {
        this.rows = rows;
        this.cols = cols;
        data = new double[rows][cols];
    }

    // Constructor 2: Initialize matrix using 2D array
    public Matrix(double[][] values)
    {
        rows = values.length;
        cols = values[0].length;

        data = new double[rows][cols];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = values[i][j];
            }
        }
    }

    // Constructor 3: Copy constructor
    public Matrix(Matrix m)
    {
        rows = m.rows;
        cols = m.cols;

        data = new double[rows][cols];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = m.data[i][j];
            }
        }
    }

    // Set element
    public void set(int row, int col, double value)
    {
        data[row][col] = value;
    }

    // Get element
    public double get(int row, int col)
    {
        return data[row][col];
    }

    // Transpose
    public Matrix transpose()
    {
        Matrix result = new Matrix(cols, rows);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[j][i] = data[i][j];
            }
        }

        return result;
    }

    // Addition of current matrix and m1
    public Matrix addition(Matrix m1)
    {
        if (rows != m1.rows || cols != m1.cols)
        {
            throw new IllegalArgumentException(
                "Matrices must have the same dimensions."
            );
        }

        Matrix result = new Matrix(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = data[i][j] + m1.data[i][j];
            }
        }

        return result;
    }

    // Addition of m1 and m2
    public Matrix addition(Matrix m1, Matrix m2)
    {
        return m1.addition(m2);
    }

    // Subtraction of m1 from current matrix
    public Matrix subtraction(Matrix m1)
    {
        if (rows != m1.rows || cols != m1.cols)
        {
            throw new IllegalArgumentException(
                "Matrices must have the same dimensions."
            );
        }

        Matrix result = new Matrix(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = data[i][j] - m1.data[i][j];
            }
        }

        return result;
    }

    // Subtraction of m1 and m2
    public Matrix subtraction(Matrix m1, Matrix m2)
    {
        return m1.subtraction(m2);
    }

    // Multiplication of current matrix and m1
    public Matrix multiplication(Matrix m1)
    {
        if (cols != m1.rows)
        {
            throw new IllegalArgumentException(
                "Number of columns of first matrix must equal " +
                "number of rows of second matrix."
            );
        }

        Matrix result = new Matrix(rows, m1.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < m1.cols; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    result.data[i][j] +=
                        data[i][k] * m1.data[k][j];
                }
            }
        }

        return result;
    }

    // Multiplication of m1 and m2
    public Matrix multiplication(Matrix m1, Matrix m2)
    {
        return m1.multiplication(m2);
    }

    // Inverse of matrix
    public Matrix inverse()
    {
        if (rows != cols)
        {
            throw new IllegalArgumentException(
                "Only square matrices can have an inverse."
            );
        }

        int n = rows;

        // Create augmented matrix [A | I]
        double[][] augmented = new double[n][2 * n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                augmented[i][j] = data[i][j];
            }

            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    augmented[i][j + n] = 1;
                else
                    augmented[i][j + n] = 0;
            }
        }

        // Gauss-Jordan elimination
        for (int i = 0; i < n; i++)
        {
            // Find pivot
            int pivotRow = i;

            for (int j = i + 1; j < n; j++)
            {
                if (Math.abs(augmented[j][i]) >
                    Math.abs(augmented[pivotRow][i]))
                {
                    pivotRow = j;
                }
            }

            // Check singular matrix
            if (Math.abs(augmented[pivotRow][i]) < 0.0000001)
            {
                throw new IllegalArgumentException(
                    "Matrix is singular and has no inverse."
                );
            }

            // Swap rows
            double[] temp = augmented[i];
            augmented[i] = augmented[pivotRow];
            augmented[pivotRow] = temp;

            // Divide pivot row by pivot
            double pivot = augmented[i][i];

            for (int j = 0; j < 2 * n; j++)
            {
                augmented[i][j] /= pivot;
            }

            // Make other elements in column zero
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    double factor = augmented[j][i];

                    for (int k = 0; k < 2 * n; k++)
                    {
                        augmented[j][k] -=
                            factor * augmented[i][k];
                    }
                }
            }
        }

        // Extract inverse matrix
        Matrix result = new Matrix(n, n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result.data[i][j] = augmented[i][j + n];
            }
        }

        return result;
    }

    // Display matrix
    @Override
    public String toString()
    {
        String result = "";

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result += String.format("%.2f ", data[i][j]);
            }

            result += "\n";
        }

        return result;
    }
}


// Main Program
public class Program9
{
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);

        int x, y;

        System.out.println("Enter number of rows:");
        x = scanner.nextInt();

        System.out.println("Enter number of columns:");
        y = scanner.nextInt();

        // Create Matrix A
        Matrix A = new Matrix(x, y);

        System.out.println("Enter the elements of Matrix A:");

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                A.set(i, j, scanner.nextDouble());
            }
        }

        // Create Matrix B
        Matrix B = new Matrix(x, y);

        System.out.println("Enter the elements of Matrix B:");

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                B.set(i, j, scanner.nextDouble());
            }
        }

        // Display Matrix A
        System.out.println("\nMatrix A:");
        System.out.println(A);

        // Display Matrix B
        System.out.println("Matrix B:");
        System.out.println(B);

        // Addition
        System.out.println("Addition of Matrix A and B:");
        System.out.println(A.addition(B));

        // Subtraction
        System.out.println("Subtraction of Matrix A and B:");
        System.out.println(A.subtraction(B));

        // Multiplication
        System.out.println("Multiplication of Matrix A and B:");

        try
        {
            System.out.println(A.multiplication(B));
        }
        catch (IllegalArgumentException e)
        {
            System.out.println(e.getMessage());
        }

        // Transpose
        System.out.println("Transpose of Matrix A:");
        System.out.println(A.transpose());

        // Inverse
        if (x == y)
        {
            System.out.println("Inverse of Matrix A:");

            try
            {
                System.out.println(A.inverse());
            }
            catch (IllegalArgumentException e)
            {
                System.out.println(e.getMessage());
            }
        }
        else
        {
            System.out.println("Inverse is possible only for a square matrix.");
        }
    }
}
