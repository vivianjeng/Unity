#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class trade{
	public:
		int bidId;	
		int clientId;	
		int action;	
		int price;	
		int shareCount;
		trade& operator=(const trade&);
};

trade& trade::operator=(const trade& str){
	if(this != &str){
		bidId = str.bidId;
		clientId = str.clientId;
		action = str.action;
		price = str.price;
		shareCount = str.shareCount;
	}
	return *this;
}

bool operator < (const trade a,const trade b){
	if(a.price == b.price)
		return a.bidId < b.bidId;
	else
		return a.price < b.price;
} //for min

bool operator <= (const trade a,const trade b){
	if(a.price == b.price)
		return a.bidId < b.bidId;
	else
		return a.price <= b.price;
} //for min

bool operator > (const trade a,const trade b){
	if(a.price == b.price)
		return a.bidId < b.bidId;
	else
		return a.price > b.price;
} //for max

bool operator >= (const trade a,const trade b){
	if(a.price == b.price)
		return a.bidId < b.bidId;
	else
		return a.price >= b.price;
}

void swap(trade& x,trade& y){
	trade t;
	t = x;
	x = y;
	y = t;
}

void insert_max(vector<trade>& list){
	int pos = list.size() -1 ;
	while(list[pos] > list[pos/2] && pos >1){
		swap(list[pos],list[pos/2]);
		pos /= 2;
	}
}

void insert_min(vector<trade>& list){
	int pos = list.size() -1 ;
	while(list[pos] < list[pos/2] && pos >1){
		swap(list[pos],list[pos/2]);
		pos /= 2;
	}
}

void downHeap_max(vector<trade> &list,int node){
	int tmp,maxIndex;
	if ( 2*node+1 >= list.size()) {
            if (2*node >= list.size())
                  return;
            else
                  maxIndex = 2*node;
      } else {
            if (list[2*node] > list[2*node + 1])
                  maxIndex = 2*node;
            else 
                  maxIndex = 2*node+1;
            }
      if (list[maxIndex] >= list[node]) {
      		swap(list[maxIndex],list[node]);
            downHeap_max(list,maxIndex);
      }
      
}

void downHeap_min(vector<trade> &list,int node){
	int tmp,minIndex;
	if ( 2*node+1 >= list.size()) {
            if (2*node >= list.size())
                  return;
            else
                  minIndex = 2*node;
      }
      else {
            if (list[2*node] < list[2*node + 1])
                  minIndex = 2*node;
            else 
                  minIndex = 2*node+1;
      }
      
      if (list[minIndex] <= list[node]) {
      		swap(list[minIndex],list[node]);
            downHeap_min(list,minIndex);
      }
      
}

void remove_max(vector<trade>& list){
	int pos=1;
	swap(list[1],list[list.size() -1]);
	list.erase(list.end());
	
	if (list.size() > 0)
       downHeap_max(list,1);
}


void remove_min(vector<trade>& list){
	int pos=1;
	swap(list[1],list[list.size() -1]);
	list.erase(list.end());
	
	if (list.size() > 0)
       downHeap_min(list,1);
}


void trading(void){
	trade tmp;
    vector<trade> buy,sell;
    char line[100];
    int transId=0;
    buy.push_back(tmp);
    sell.push_back(tmp);
    vector<bool> cancel;
    
   
    while (cin.getline(line, 100) && *line)
    {
        istringstream sin(line);
        sin >> tmp.bidId >> tmp.clientId >> tmp.action >> tmp.price >> tmp.shareCount;
        cancel.push_back(true);
        if(tmp.action == 1){
        	sell.push_back(tmp);
        	insert_min(sell);
        }
        else if(tmp.action ==0){
        	buy.push_back(tmp);
        	insert_max(buy);
        }
        
        else if(tmp.action == 2){
        	for(int i=0;i<buy.size();i++){
        		if(tmp.price == buy[i].bidId)
        			buy[i].shareCount = 0;
        	}
        	for(int i=0;i<sell.size();i++){
        		if(tmp.price == sell[i].bidId)
        			sell[i].shareCount = 0;
        	}
        }
        
        
        while(buy[1].price >= sell[1].price && sell.size() > 1 && buy.size() > 1){
        	/*
        	while(cancel[buy[1].bidId] == false && buy[1].price >= sell[1].price ){
        			remove_max(buy);
        	}
        	while(cancel[sell[1].bidId] == false && buy[1].price >= sell[1].price){
        			remove_min(sell);
        	}
        	if(buy[1].price < sell[1].price)
        		break;
			   */
			   
        	
        	int b_Id = buy[1].clientId;
        	int s_Id = sell[1].clientId;
        	int s_p = sell[1].price;
        	int share = 0;
        	
        	if(buy[1].shareCount > sell[1].shareCount){
        		
        		share = sell[1].shareCount;
        		buy[1].shareCount -= sell[1].shareCount;
        		remove_min(sell);
  
        	}
        	else{
        		share = buy[1].shareCount;
        		sell[1].shareCount -= buy[1].shareCount;
        		remove_max(buy);
        	}
        	
        	if(share > 0){
        	cout<<transId<<"\t"<<b_Id<<"\t"<<s_Id<<"\t"<<s_p<<"\t"<<share<<endl;
        	transId++;
        	}
        }
    
    }
 
    //cout<<endl;
    //for(int i=1;i<sell.size();i++)
    //cout << sell[i].bidId <<"\t"<< sell[i].clientId <<"\t"<< sell[i].action <<"\t"<< sell[i].price <<"\t"<< sell[i].shareCount <<endl;
    //cout<<endl;
    //for(int i=1;i<buy.size();i++)
    //cout << buy[i].bidId <<"\t"<< buy[i].clientId <<"\t"<< buy[i].action <<"\t"<< buy[i].price <<"\t"<< buy[i].shareCount <<endl;
 
}


int main()
{
    trading();
    
    return 0;
    
    
}