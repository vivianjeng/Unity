
#include <iostream>
#include <vector>

using namespace std;

void gen(vector<int> & permutation, int level, int n)	//What is the function of the 'level' variable?
{
int i;
if(level==n)
{
  for(i=0;i<n;i++)
    cout<<permutation[i];
  cout<<endl;
}
else
{
  for(i=0;i<=level;i++)
  {
    vector<int>  p(permutation);   //What does this do?
    p.insert(p.begin()+i,level);	  //And what is happening here?
    gen(p,level+1,n);
  }
}
}

int main()
{
int n;
cin>>n;

vector<int> permutation;
gen(permutation,1,n+1);
return 0;
}
