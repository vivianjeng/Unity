#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;


float min(float a,float b){
  if(a < b) return a;
  else return b;
}

float dist(float i,float j){
  if(i > j)
    return (i - j);
  else
    return (j - i);
}


main(){

  int m,n;

  vector<float> p;
  vector<float> q;
  vector<int> s;
  float d = 0;
  float tmp;
  cin>> m;
  for (int i = 0; i < m; i++) {
    cin>>tmp;
    p.push_back(tmp);
  }
  cin>> n;
  for (int i = 0; i < n; i++) {
    cin>>tmp;
    q.push_back(tmp);
  }
  float path[m][n];

	float mi = 0;
	mi+=dist(p[0],q[0]);
	path[0][0] = mi;

	for(int j = 1; j < m; j++){
		mi += dist(p[j],q[0]);
  		path[j][0] = mi;
	 	if(j == 1){
	 		path[j][1] = path[0][0] + dist(p[1],q[1]);
	 	}
	 	else if(j > 1 && j <= n){
	 		path[j][j] = dist(p[j],q[j])+ path[j-1][j-1];
	 		for (int i = 1; i < j; i++){
	 			path[j][i] = dist(p[j],q[i]) + min(path[j-1][i-1],path[j-1][i]);
	 		}
	 	}
	 	else{
	 		for (int i = 1; i < n; i++){
	 			path[j][i] = dist(p[j],q[i]) + min(path[j-1][i-1],path[j-1][i]);
	 		}
	 	}
	}

  	int final_q;
  	d = path[m-1][0];
  	for (int i = 0; i < n; i++){
		if(path[m-1][i] < d){
			d = path[m-1][i];
			final_q = i;
		}
  	}


  	for(int i = m-1; i >= 1; i--){
      if(final_q >0){
  		if(path[i-1][final_q-1] <= path[i-1][final_q] && path[i-1][final_q] != 0){
  			s.push_back(i);
  			final_q-=1;
  			//cout<<final_q<<" ";
  		}
  		else if(path[i-1][final_q]==0){
  			s.push_back(i);
  			final_q-=1;
  			//cout<<final_q<<" ";
  		}
    }
  	}

  	s.push_back(0);




  cout<<d<<endl;

	int siz = s.size();

	for(int i=siz-1;i>=0;i--){
		cout<<s[i]<<" ";
	}



  return 0;
}
