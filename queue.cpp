// Reverse First K elements of Queue - https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1#

queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    stack<int> s;
    for(int i = 1; i<=k; i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    int l = q.size() - k;
    for(int i = 1; i<=l; i++){
        q.push(q.front());
        q.pop();
    }
    return q;
}
