package org.gvp.dcs.ds;

public class Queue 
{
    private int[] arr;
    private int front, rear, capacity, size;

    public Queue(int capacity) 
	{
        this.capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    public void enqueue(int value) 
	{
        if (size == capacity) 
		{
            System.out.println("Queue Overflow!");
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        System.out.println(value + " inserted into queue");
    }

    public int dequeue() 
	{
        if (size == 0) 
		{
            System.out.println("Queue Underflow!");
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    public int peek()
	{
        if (size == 0) 
		{
            System.out.println("Queue is empty!");
            return -1;
        }
        return arr[front];
    }

    public boolean isEmpty() 
	{
        return size == 0;
    }

    public void display() 
	{
        System.out.print("Queue: ");
        for (int i = 0; i < size; i++) 
		{
            System.out.print(arr[(front + i) % capacity] + " ");
        }
        System.out.println();
    }
}