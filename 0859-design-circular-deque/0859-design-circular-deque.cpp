class MyCircularDeque {
public:
    vector<int> v;
    int front, back, size, capacity;

    MyCircularDeque(int k) 
    {
        v = vector<int>(k, -1);
        front = 0;
        back = 0;
        size = 0; // Keeps track of the current number of elements
        capacity = k;
    }

    bool insertFront(int value) 
    {
        if (isFull())
            return false;

        if (front == 0) 
            front = capacity - 1; 
        else 
            front--; 

        v[front] = value;
        size++;

        return true;
    }

    bool insertLast(int value) 
    {
        if (isFull())
            return false;

        v[back] = value;

        if (back == capacity - 1) 
            back = 0; // Wrap around to the beginning
        else 
            back++; // Simply increment back

        size++;
        return true;
    }

    bool deleteFront() 
    {
        if (isEmpty()) 
            return false;

        v[front] = -1;

        // Way - 01
        if (front == capacity - 1) 
            front = 0; // Wrap around to the beginning
        else 
            front++; // Simply increment front
        
        size--;
        return true;
    }

    bool deleteLast() 
    {
        if (isEmpty()) 
            return false;

        if (back == 0) 
            back = capacity - 1; // Wrap around to the end
        else 
            back--; // Simply decrement back

        v[back] = -1;
        
        size--;
        return true;
    }

    int getFront() 
    {
        if (isEmpty())
            return -1;

        return v[front];
    }

    int getRear() 
    {
        if (isEmpty())
            return -1;

        if (back == 0)
            return v[capacity - 1]; // Wrap around to the last valid element
        else
            return v[back - 1]; // Get the last element
    }

    bool isEmpty() 
    { 
        return (size == 0); 
    }

    bool isFull() 
    { 
        return (size == capacity); 
    }
};