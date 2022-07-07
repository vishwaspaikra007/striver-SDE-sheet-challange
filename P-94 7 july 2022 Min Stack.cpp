// striver SDE sheet challange Min Stack
// author Vishwas Paikra
// Implement class for minStack.
class minStack
{
	// Write your code here.
	int *list;
    int *minList;
    int idx;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
            list = new int[100000];
            minList = new int[100000];
            idx = 0;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            list[idx] = num;
            if(idx == 0) minList[idx] = num;
            else minList[idx] = min(minList[idx-1], num);
            ++idx;
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
            if(idx == 0) return -1;
            return list[--idx];
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            if(idx == 0) return -1;
            return list[idx-1];
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(idx == 0) return -1;
            return minList[idx-1];
		}
};
