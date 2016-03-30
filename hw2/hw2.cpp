#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;
//#define NUM 100
#define NUM  73209277


struct data { int  UserId;
              int ItemId;
              int Result;
              int Unix_timestamp;
            } M[NUM] ,N[NUM];

//declare data struct



int  compare_UserId(const void *, const void *); //for qsort
int  compare_ItemId(const void *, const void *);

int accept(int accept_u,int accept_i,int accept_t){
  int low = 0, high =  NUM- 1;

while (low <= high)      //binary search to find Result
{
    int mid = (low + high) / 2;

    if (M[mid].UserId == accept_u)
    {
      if(M[mid].ItemId == accept_i)
      {
          if(M[mid].Unix_timestamp == accept_t){
            cout<<M[mid].Result<<endl;

             break;
          }
          else if(M[mid].Unix_timestamp > accept_t){
            high = mid -1;
          }
          else if(M[mid].Unix_timestamp < accept_t){
            low = mid + 1;
      }
    }
      else if(M[mid].ItemId > accept_i){
        high = mid - 1;
      }
      else if(M[mid].ItemId < accept_i){
        low = mid + 1;
      }
    }
    else if (M[mid].UserId > accept_u)
    {
        high = mid - 1;
    }
    else if (M[mid].UserId < accept_u)
    {
        low = mid + 1;
    }
    else
     cout<<"EMPTY"<<endl;
  }


}

int items(int items_u1,int items_u2){
  int low1 = 0, high1 =  NUM- 1;
  int low2 = 0, high2 =  NUM- 1;
  std::vector<int> tmp;
  std::vector<int> tmp2;
  int up1=1,up2=1;
  int down1=1,down2=1;

  while (low1 <= high1)
  {
      int mid1 = (low1 + high1) / 2;

      if (M[mid1].UserId == items_u1 )
      {
        while (M[mid1].UserId == M[mid1+up1].UserId) {
            up1++;
        }

        while (M[mid1].UserId == M[mid1-down1].UserId){
             down1++;
        }

        for(int i=0;i<down1+up1-1;i++){
          tmp.push_back(M[mid1-down1+1+i].ItemId);
        }

        int j=0;               //remove duplication
        for(int k=1;k<tmp.size();k++){
          if(tmp[k]!=tmp[k-1])
          j++;
          tmp[j]=tmp[k];
        }
        tmp.resize(j+1);

       break;
      }
      else if (M[mid1].UserId > items_u1)
      {
          high1 = mid1 - 1;
      }
      else if (M[mid1].UserId < items_u1)
      {
          low1 = mid1 + 1;
      }
      else
       cout<<"EMPTY"<<endl;
      }


      while (low2 <= high2)
      {
          int mid2 = (low2 + high2) / 2;


          if (M[mid2].UserId == items_u2 )
          {
            while (M[mid2].UserId == M[mid2+up2].UserId) {
                up2++;
            }

            while (M[mid2].UserId == M[mid2-down2].UserId){
                 down2++;
            }

            for(int i=0;i<down2+up2-1;i++){
              tmp2.push_back(M[mid2-down2+1+i].ItemId);
            }

            int j=0;              //remove duplication
            for(int k=1;k<tmp2.size();k++){
              if(tmp2[k]!=tmp2[k-1])
              j++;
              tmp2[j]=tmp2[k];
            }
            tmp2.resize(j+1);


           break;

          }
          else if (M[mid2].UserId > items_u2)
          {
              high2 = mid2 - 1;
          }
          else if (M[mid2].UserId < items_u2)
          {
              low2 = mid2 + 1;
          }

          else
           cout<<"EMPTY"<<endl;
          }

       for(int i=0;i<tmp.size();i++)         //compare two arrays
         for (int k = 0; k < tmp2.size(); k++) {
            if(tmp[i]==tmp2[k])
               cout<<tmp[i]<<endl;

          }

}

int users(int users_i1,int users_i2,int users_t1,int users_t2){
  int low1 = 0, high1 =  NUM- 1;
  int low2 = 0, high2 =  NUM- 1;
  std::vector<int> tmp;
  std::vector<int> tmp2;
  int up1=1,up2=1;
  int down1=1,down2=1;

  while (low1 <= high1)
  {
      int mid1 = (low1 + high1) / 2;

      if (N[mid1].ItemId == users_i1 )
      {
        while (N[mid1].ItemId == N[mid1+up1].ItemId) {
            up1++;
        }

        while (N[mid1].ItemId == N[mid1-down1].ItemId){
             down1++;
        }

        for(int i=0;i<down1+up1-1;i++){
          if(N[mid1-down1+1+i].Unix_timestamp>= users_t1 &&    //check t1 t2
             N[mid1-down1+1+i].Unix_timestamp<= users_t2)
          tmp.push_back(N[mid1-down1+1+i].UserId);
        }

        int j=0;             //remove duplication
        for(int k=1;k<tmp.size();k++){
          if(tmp[k]!=tmp[k-1])
          j++;
          tmp[j]=tmp[k];
        }
        tmp.resize(j+1);

       break;
      }
      else if (N[mid1].ItemId > users_i1)
      {
          high1 = mid1 - 1;
      }
      else if (N[mid1].ItemId < users_i1)
      {
          low1 = mid1 + 1;
      }
      else
       cout<<"EMPTY"<<endl;
      }


      while (low2 <= high2)
      {
          int mid2 = (low2 + high2) / 2;


          if (N[mid2].ItemId == users_i2 )
          {
            while (N[mid2].ItemId == N[mid2+up2].ItemId) {
                up2++;
            }

            while (N[mid2].ItemId == N[mid2-down2].ItemId){
                 down2++;
            }


            for(int i=0;i<down2+up2-1;i++){
              if(N[mid2-down2+1+i].Unix_timestamp>= users_t1 &&
                 N[mid2-down2+1+i].Unix_timestamp<= users_t2)
              tmp2.push_back(N[mid2-down2+1+i].UserId);
            }

            int j=0;           //remove duplication
            for(int k=1;k<tmp2.size();k++){
              if(tmp2[k]!=tmp2[k-1])
              j++;
              tmp2[j]=tmp2[k];
            }
            tmp2.resize(j+1);

           break;

          }
          else if (N[mid2].ItemId > users_i2)
          {
              high2 = mid2 - 1;
          }
          else if (N[mid2].ItemId < users_i2)
          {
              low2 = mid2 + 1;
          }

          else
           cout<<"EMPTY"<<endl;

          }

       for(int i=0;i<tmp.size();i++)       //compare two arrays
         for (int k = 0; k < tmp2.size(); k++) {
            if(tmp[i]==tmp2[k] )
               cout<<tmp[i]<<endl;

          }
}

int main()
{
   //FILE *fr = fopen("tmp2.txt","r");
   FILE *fr = fopen("/tmp2/KDDCUP2012/track1/rec_log_train.txt","r");


   for(int i=0;i<NUM;i++)
     fscanf(fr,"%d%d%d%d",&M[i].UserId,&M[i].ItemId,
									&M[i].Result,&M[i].Unix_timestamp);
    //input data in the struct
    fclose(fr);

    for (int i = 0; i < NUM; i++) {
      N[i] = M[i];
    }

    //copy data


   qsort((void *) &M,              // using qsort to sort struct member
   NUM,
   sizeof(struct data),
   compare_UserId );

   qsort((void *) &N,              // another sort
   NUM,
   sizeof(struct data),
   compare_ItemId );


   int n;  //query Number
   cin>>n;


   for(int i=0;i<n;i++){
   string query;
   cin>>query;


   if(query == "accept"){
     int u, i, t;
     cin>>u>>i>>t;
     accept(u,i,t);
 }


    else if(query == "items"){
     int u1, u2;
     cin>>u1>>u2;
     items(u1,u2);
   }

   else if(query == "users"){
     int i1, i2, t1, t2;
     cin>>i1>>i2>>t1>>t2;
     users(i1,i2,t1,t2);

   }

   else if(query == "ratio"){
     int ratio_i,threshold;
     cin>>ratio_i>>threshold;

     int times=1;
     int us=0;
     int accepts=0;

/* failed
     while (1) {
       if(M[i].UserId==M[i-1].UserId){
         times++;
       }
       else {
         if(times>=threshold)
          us++;

          int low3 = i - times+1, high3 =  i-1;

          while (low3 <= high3)
          {
              int mid3 = (low3 + high3) / 2;

              if (M[mid3].ItemId == ratio_i)
              {
                  if(M[mid3].Result == 1)
                  accepts++;
                  break;
              }
              else if (M[mid3].ItemId > ratio_i)
              {
                  high3 = mid3 - 1;
              }
              else if (M[mid3].ItemId < ratio_i)
              {
                  low3 = mid3 + 1;
              }
            }


          times = 1;
        }
        i++;
}*/
      cout<<accepts<<"/"<<us<<endl;

}




   else if(query == "findtime_item"){
     int ft_i;
     int ft_users[100] ;
     cin>>ft_i;

     char buf[100] ;
   	 char* hello ;
     int n_users;
     int ite;
     fgets(buf,100,stdin);
     //printf("%s",buf) ;
     n_users = 0 ;
     hello = strtok(buf, " ");
     ite =atoi(hello) ;
     while (hello != NULL) {
       hello = strtok(NULL, " ");
       if(hello == NULL)break ;
       ft_users[n_users] =atoi(hello) ;
       //printf("%d\n",users[n_users]) ;
       n_users ++ ;
     }
/* failed
     int low1 = 0, high1 =  NUM- 1;
     std::vector<int> tmp;
     int up1=1;
     int down1=1;

     while (low1 <= high1)
     {
         int mid1 = (low1 + high1) / 2;

         if (N[mid1].ItemId == ft_i )
         {
           for(int i=0;i<n_users;i++){
              if(N[mid1].UserId == ft_users[i]){
                while (N[mid1].ItemId == N[mid1+up1].ItemId) {
                    up1++;
                }

                while (N[mid1].ItemId == N[mid1-down1].ItemId){
                     down1++;
                }
                for (int k = 0; k < down1+up1-1 ; k++) {
                      tmp.push_back(N[mid1-down1+1+i].Unix_timestamp);
                }

                  break;
                }

                else if(N[mid1].UserId > ft_users[i]){
                  high1 = mid1 -1;
                }
                else if(N[mid1].UserId < ft_users[i]){
                  low1 = mid1 + 1;
       }
     }
         }
         else if (N[mid1].ItemId > ft_i)
         {
             high1 = mid1 - 1;
         }
         else if (N[mid1].ItemId < ft_i)
         {
             low1 = mid1 + 1;
         }
         else
            cout<<"EMPTY"<<endl;
         }


         sort(tmp.begin(),tmp.end());

         int count=1;
         for (int i = 1; i < tmp.size(); i++) {
           if(tmp[i] == tmp[i-1]){
            count++;
              if(count==n_users)
                cout<<tmp[i];
          }
           else{
             if(count==n_users)
               cout<<tmp[i];
            count = 1;
          }
         }
*/
    cout<<"EMPTY"<<endl;

   }

}

   return 0;
}


int compare_UserId(const void *a, const void *b)
{
     struct data c= *((struct data *)a);
	   struct data d= *((struct data *)b);
   if ( c.UserId < d.UserId  )
      return -1;

   else if (c.UserId > d.UserId )
      return 1;

   else{
     if(c.ItemId < d.ItemId)
		{
			return -1 ;
		}else if(c.ItemId > d.ItemId)
		{
			return 1 ;
		}else
		{
			if(c.Unix_timestamp < d.Unix_timestamp)
			{
				return -1 ;
			}else if(c.Unix_timestamp > d.Unix_timestamp)
			{
				return 1 ;
			}else
			{
				return 0 ;
			}
		}
	}
	return 0 ;


}

int compare_ItemId(const void *a, const void *b)
{
     struct data c= *((struct data *)a);
	   struct data d= *((struct data *)b);
   if ( c.ItemId < d.ItemId  )
      return -1;

   else if (c.ItemId > d.ItemId )
      return 1;

   else{
     if(c.UserId< d.UserId)
		{
			return -1 ;
		}else if(c.UserId > d.UserId)
		{
			return 1 ;
		}else
		{
			if(c.Unix_timestamp < d.Unix_timestamp)
			{
				return -1 ;
			}else if(c.Unix_timestamp > d.Unix_timestamp)
			{
				return 1 ;
			}else
			{
				return 0 ;
			}
		}
	}
	return 0 ;


}
