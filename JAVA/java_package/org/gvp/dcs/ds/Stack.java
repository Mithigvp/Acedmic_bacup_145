package org.gvp.dcs.ds;

public class Stack
{

    private int[] arr;
    private int top;
    private int cap;

    public Stack(int size) 
	{
        cap = size;
        arr = new int[size];
        top = -1;
    }

    public void push(int value) 
	{
        if (top >= cap - 1) 
		{
            System.out.println("Stack Overflow! Cannot insert " + value);
        }
		else 
		{
            arr[++top] = value;
            System.out.println("Successfully inserted: " + value);
        }
    }

    public int pop() 
	{
        if (top == -1) 
		{
            System.out.println("Stack Underflow! Stack is empty.");
            return -1;
        } 
		else 
		{
            int ele = arr[top];
            top--;
            return ele;
        }
    }

    public int peek() 
	{
        if (top == -1) 
		{
            System.out.println("Stack is empty!");
            return -1;
        } 
		else 
		{
            return arr[top];
        }
    }

    public boolean isEmpty() 
	{
        return top == -1;
    }

    public boolean isFull() 
	{
        return top == cap - 1;
    }

    public void display()
	{
        if (top == -1) 
		{
            System.out.println("Stack is empty!");
            return;
        }
        System.out.print("Stack: ");

        for (int i = top; i >= 0; i--) 
		{
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}