#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    vector<int> price = {100,80,60,70};
    vector<int> ans(price.size(),0);  //ans vec with size of price v and al elements 0
    stack<int> s;
    for(int i = 0 ; i < price.size();i++)
    {
    while(!s.empty() && price[s.top()] <= price[i])  //pop if prev price higher than current
    s.pop();

    if(s.size() == 0 )
    ans[i] = i+1 ;  //stack empty then span this
    else 
    ans[i] = i - s.top(); //stack not empty then span is i - prevhigh(top has prevhigh rn)
    s.push(i);   //push price in stack from first iteraation
}
for(int val : ans)
{
    cout << val << " ";
}
cout <<endl;
return 0;
}