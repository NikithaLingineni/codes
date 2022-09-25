#include<iostream>
using namespace std;
int main()
{
	int i,n,capacity,cur_weight,item;
	float total_profit;
	cin>>capacity;
	cin>>n;
	int used[10];
	int weight[50];
	int benefit[50];
	for(i=0;i<n;i++)
	{
		cin>>weight[i];
		cin>>benefit[i];
	}
	for(i=0;i<n;i++)
	{
		used[i]=0;
	}
	cur_weight=capacity;
	cout<<"Enter the capacity of knapsack:"<<"\n";
	cout<<"Enter the number of items:"<<"\n";
	cout<<"Enter the weight and value of "<<n<<" item:"<<"\n";
	while (cur_weight > 0)
    {
	    item = -1;
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) &&
                ((item == -1) || ((float) benefit[i] / weight[i] > (float) benefit[item] / weight[item])))
                item = i;
        used[item] = 1;
        cur_weight -= weight[item];
        total_profit += benefit[item];
        if (cur_weight >= 0)
        {
        	cout<<item+1<<" "<<benefit[item]<<" "<<weight[item]<<" "<<cur_weight<<"\n";
		}
        else
        {
            int item_percent = (int) ((1 + (float) cur_weight / weight[item]) * 100);
            cout<<item_percent<<"%"<<" "<<benefit[item]<<" "<<weight[item]<<" "<<item + 1<<"\n";
            total_profit -= benefit[item];
            total_profit += (1 + (float)cur_weight / weight[item]) * benefit[item];
        }
    }
    cout<<"Filled the bag with objects worth Rs."<<total_profit;
}
