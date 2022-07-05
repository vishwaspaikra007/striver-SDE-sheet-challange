// striver SDE sheet challange sort-a-stack
// author Vishwas Paikra
void _sort(stack<int> &stack, int n) {
    if(stack.empty() || stack.top() <= n) {
        stack.push(n);
        return;
    }
    int temp = stack.top();
    stack.pop();
    _sort(stack, n);
    stack.push(temp);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty()) return;
    int n = stack.top();
    stack.pop();
    sortStack(stack);
    _sort(stack, n);
}
