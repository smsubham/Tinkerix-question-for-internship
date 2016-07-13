#include <iostream>
using namespace std;
struct Plan
{
    int Y;
    double X,Z;
    int STD,LOCAL; //1 if plan is applicable for it , 0 otherwise
    double cost;
    struct Plan *next;
}*start=NULL;
double planCost(struct Plan *node,int M,int N,int *Std_days,int *Local_days)
{
    double cost=0;
    if(node->LOCAL==1&&node->STD==1){ //plan applicable for std and local
            cost=node->X+M*(node->Y/30.0)*node->Z+N*(node->Y/30.0)*node->Z;
            *Std_days+=node->Y;
            *Local_days+=node->Y;
            return cost;
    }
    else if(node->LOCAL==1){ //plan only applicable for local call
        cost=node->X+N*(node->Y/30.0)*node->Z;
        *Local_days+=node->Y;
        return cost;
    }
    else //plan applicable for only std
    {
        cost=node->X+M*(node->Y/30.0)*node->Z;
        *Std_days+=node->Y;
        return cost;
    }
}
int main()
{
int T,P,Std_days,Local_days,k=1;
double cost,min_cost=999999.0,M,N;
struct Plan *plan,*temp,*n,*start_temp;
cin>>T; //no of test cases
start=temp=n=new(struct Plan);
for(int i=0;i<T;i++)
{
    cout<<"Enter no of plans to compare";
    cin>>P; //no of plans to compare
    cout<<"Enter STD and Local Minute";
    cin>>M>>N;
  for(int j=0;j<P;j++)
   {
       if(j!=0){
        start_temp=temp=new(struct Plan);
        n->next=temp;
        n=temp;
       }
       cost=0;
       k=1;
       Local_days=0;//no of local days covered by any plan
       Std_days=0; //no of std days covered by any plan
       while(k!=0) //to handle multiple plan
       {
           cout<<"Enter plan details Rs , days and p/Min";
           cin>>temp->X>>temp->Y>>temp->Z;
           cout<<"Enter if plan is applicable for Local and/or Std\n"<<"1 if applicable and 0 otherwise\n";
           cin>>temp->LOCAL>>temp->STD;
           cost+=planCost(temp,M,N,&Std_days,&Local_days);
           cout<<"\n1 to add or 0 to go to next plan";
           cin>>k;
           if(k!=0)
           {
               temp=new(struct Plan);
               n->next=temp;
               n=temp;
           }
       }
       n->next=NULL;
       cost=cost+(1.0*M*((30.0-Std_days)/30.0)+1.0*N*((30.0-Local_days)/30.0)); //adds cost of call for days not covered by any plan
       cout<<"\n"<<cost;
       if(min_cost>cost)
       {
           min_cost=cost;
           start=start_temp;
       }
   }
   cout<<"Minimum cost is:"<<min_cost;
}
}
