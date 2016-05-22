#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_LENGTH 20

bool compare_alpha(string a, string b){
  if (a < b) return true;
  else
  return false ;
  }

bool eqaul(string str1,string str2){
  return (!str1.compare(str2));
}

bool operator!= (string c1, string c2)
{
    return !(c1.compare(c2));
}




int main ()
{
  FILE * pFile;
  char buffer[100];
  unordered_set<string> hash;
  vector<string> output;
  unordered_set<string>::iterator i;

  //pFile = fopen ("small.txt","r");
  //pFile = fopen ("cmudict-0.7b","r");
  pFile = fopen ("/tmp2/dsa2016_hw5/cmudict-0.7b","r");
  while(fgets(buffer,100,pFile)!=NULL){ //讀一行
    //fscanf(pFile,"%s",buffer);
    for (int i = 0; i < 100; i++) {
      buffer[i] = tolower(buffer[i]);//轉小寫
    }

    char *word;
    word = strtok(buffer," ");
    string key(word);
    hash.insert(key);

    word = strtok(NULL, " ");

    }


    //for(unordered_map<string,string>::iterator i=hash.begin(); i!=hash.end(); ++i)
		//cout << (*i).first << ": " << (*i).second << endl;

    char line[100];
    string find;

    while (cin.getline(line, 100) && *line)
    {
        istringstream sin(line);
        sin >> find;
        cout<<find<<" ==> ";

          if(hash.find(find) != hash.end()){
            cout<<"OK"<<endl;
          continue;
        }
        else{
          int l = find.length();

            //cout<<"deletion twice  ";
          for (int i = 0; i < l; i++) {
              string tmp;
              tmp.assign(find);

              for (int j = i; j < l-1; j++) {
                tmp[j] = tmp[j+1];
              }
              tmp.resize(l-1);

                  if(hash.find(tmp) != hash.end()){

                    string t;
                    t.assign(tmp);
                  output.push_back(t);
                }
                for (int m = 0; m < l -1; m++) {
                    string tmp2;
                    tmp2.assign(tmp);
                    for (int j = m; j < l -2; j++) {
                      tmp2[j] = tmp2[j+1];
                    }
                    tmp2.resize(l -2);

                        if(hash.find(tmp2) != hash.end()){
                          //cout<<tmp2<<" ";
                          string t2;
                          t2.assign(tmp2);
                        output.push_back(t2);
                      }
                  }

            }
            //cout<<"insert twice";
            for (int i = 0; i < l+1; i++) {
              string tmp;
              tmp.assign(find);
              tmp.resize(l+1);
                for (int j = l; j >= i; j--) {
                  tmp[j+1] = tmp[j];
                }
                for (int k = 97; k <= 122; k++) {
                  tmp[i] = (char)k;
                      if(hash.find(tmp) != hash.end()){

                        string t;
                        t.assign(tmp);
                        //cout<<t<<" ";
                      output.push_back(t);
                }

                for (int m = 0; m < l+2; m++) {
                  string tmp2;
                  tmp2.assign(tmp);
                  tmp2.resize(l+2);
                  for (int j = l+1; j >= m; j--) {
                    tmp2[j+1] = tmp[j];
                  }
                  for (int k = 97; k <= 122; k++) {
                    tmp2[m] = (char) k ;
                    //cout<<tmp2<<" ";
                    if(hash.find(tmp2) != hash.end()){

                      string t2;
                      t2.assign(tmp2);
                      //cout<<t2<<" ";
                    output.push_back(t2);
              }

                  }

                }


            }
          }

          //cout<<"substitute twice";
        for (int i = 0; i < l; i++) {
          string tmp;
          tmp.assign(find);
          for (int j = 97; j <= 122; j++) {
            tmp[i] = (char)j;
            if(hash.find(tmp) != hash.end()){
              //cout<<tmp<<":/"<<hash[hashcode(tmp)]<<"/end"<<endl;
              string t;
              t.assign(tmp);
            output.push_back(t);
          }
          for (int m = 0; m < l; m++) {

          string tmp2;
          tmp2.assign(tmp);
          for (int j = 97; j <= 122; j++) {
            tmp2[m] = (char)j;

        if(hash.find(tmp2) != hash.end()){
          //cout<<tmp2<<" " ;
          string t2;
          t2.assign(tmp2);
        output.push_back(t2);
        }
      }
    }
      }
    }

    //cout<<"transpose  twice ";
    //transpose
      for (int i = 0; i < l-1; i++) {
        string tmp;
        tmp.assign(find);
        char tmpc;
        tmpc = tmp[i];
        tmp[i] = tmp[i+1];
        tmp[i+1] = tmpc;
            if(hash.find(tmp) != hash.end()){
              //cout<<tmp<<" ";
              string t;
              t.assign(tmp);
            output.push_back(t);

      }
      for (int j = 0; j < l-1; j++) {
      string tmp2;
      tmp2.assign(tmp);
      char tmpc2;
      tmpc2 = tmp2[j];
      tmp2[j] = tmp2[j+1];
      tmp2[j+1] = tmpc2;
          if(hash.find(tmp2) != hash.end()){
            //cout<<tmp2<<" ";
            string t2;
            t2.assign(tmp2);
          output.push_back(t2);
        }
      }
    }

    //cout<<"transpose -> deletion  ";
    for (int i = 0; i < l-1; i++) {
      string tmp;
      tmp.assign(find);
      char tmpc;
      tmpc = tmp[i];
      tmp[i] = tmp[i+1];
      tmp[i+1] = tmpc;
      for (int m = 0; m < l -1; m++) {
    string tmp2;
    tmp2.assign(tmp);

    for (int j = m; j < l -1; j++) {
      tmp2[j] = tmp2[j+1];
    }
    tmp2.resize(l-1);

        if(hash.find(tmp2) != hash.end()){
          //cout<<tmp2<<" ";
          string tmp3;
          tmp3.assign(tmp2);
        output.push_back(tmp3);
      }
    }

  }

  //cout<<"deletion -> transpose  ";
  for (int i = 0; i < l; i++) {
      string tmp;
      tmp.assign(find);

      for (int j = i; j < l-1; j++) {
        tmp[j] = tmp[j+1];
      }
      tmp.resize(l-1);

        for (int j = 0; j < l-2; j++) {
        string tmp2;
        tmp2.assign(tmp);
        char tmpc2;
        tmpc2 = tmp2[j];
        tmp2[j] = tmp2[j+1];
        tmp2[j+1] = tmpc2;
            if(hash.find(tmp2) != hash.end()){
              //cout<<tmp2<<" ";
              string t2;
              t2.assign(tmp2);
            output.push_back(t2);
          }
        }
      }

      //cout<<"insert -> deletion ";
      for (int i = 0; i < l+1; i++) {
        string tmp;
        tmp.assign(find);
        tmp.resize(l+1);
          for (int j = l; j >= i; j--) {
            tmp[j+1] = tmp[j];
          }
          for (int k = 97; k <= 122; k++) {
            tmp[i] = (char)k;

            for (int m = 0; m < l+1 ; m++) {
            string tmp2;
            tmp2.assign(tmp);

            for (int j = m; j < l; j++) {
              tmp2[j] = tmp2[j+1];
            }
            tmp2.resize(l);
            //cout<<tmp2<<" ";
                if(hash.find(tmp2) != hash.end()){
                  //cout<<tmp2<<" ";
                  string tmp3;
                  tmp3.assign(tmp2);
                output.push_back(tmp3);
              }
            }
          }
      }

    //cout<<"substitute -> delete ";
    for (int i = 0; i < l; i++) {
      string tmp;
      tmp.assign(find);
      for (int j = 97; j <= 122; j++) {
        tmp[i] = (char)j;

        for (int m = 0; m < l+1 ; m++) {
        string tmp2;
        tmp2.assign(tmp);

        for (int k = m; k < l-1; k++) {
          tmp2[k] = tmp2[k+1];
        }
        tmp2.resize(l-1);
            //cout<<tmp2<<" ";
            if(hash.find(tmp2) != hash.end()){
              //cout<<tmp2<<" ";
              string tmp3;
              tmp3.assign(tmp2);
            output.push_back(tmp3);
          }
    }
  }
  }

  //cout<<"delete -> substitute ";
  for (int i = 0; i < l; i++) {
      string tmp;
      tmp.assign(find);

      for (int j = i; j < l-1; j++) {
        tmp[j] = tmp[j+1];
      }
      tmp.resize(l-1);
      for (int m = 0; m < l; m++) {
      string tmp2;
      tmp2.assign(tmp);
      for (int j = 97; j <= 122; j++) {
        tmp2[m] = (char)j;

    if(hash.find(tmp2) != hash.end()){
      //cout<<tmp2<<" ";
      string t2;
      t2.assign(tmp2);
    output.push_back(t2);
    }
      }
    }
    }

    //cout<<"transpose ->insert ";
    for (int i = 0; i < l-1; i++) {
      string tmp;
      tmp.assign(find);
      char tmpc;
      tmpc = tmp[i];
      tmp[i] = tmp[i+1];
      tmp[i+1] = tmpc;

      for (int m = 0; m < l+1; m++) {
        string tmp2;
        tmp2.assign(tmp);
        tmp2.resize(l+1);
        for (int j = l+1; j >= m; j--) {
          tmp2[j+1] = tmp[j];
        }
        for (int k = 97; k <= 122; k++) {
          tmp2[m] = (char) k ;
          //cout<<tmp2<<" ";
          if(hash.find(tmp2) != hash.end()){
            //cout<<tmp2<<" ";
            string t2;
            t2.assign(tmp2);
          output.push_back(t2);
        }

        }

      }
}

    //cout<<"insert -> transpose";
    for (int i = 0; i < l+1; i++) {
      string tmp;
      tmp.assign(find);
      tmp.resize(l+1);
        for (int j = l; j >= i; j--) {
          tmp[j+1] = tmp[j];
        }
        for (int k = 97; k <= 122; k++) {
          tmp[i] = (char)k;

          for (int j = 0; j < l; j++) {
          string tmp2;
          tmp2.assign(tmp);
          char tmpc2;
          tmpc2 = tmp2[j];
          tmp2[j] = tmp2[j+1];
          tmp2[j+1] = tmpc2;
              if(hash.find(tmp2) != hash.end()){
                //cout<<tmp2<<" ";
                string t2;
                t2.assign(tmp2);
              output.push_back(t2);
            }
          }

      }

    }
    //cout<<endl<<endl;

    //cout<<"transpose -> insert ";
    for (int i = 0; i < l-1; i++) {
      string tmp;
      tmp.assign(find);
      char tmpc;
      tmpc = tmp[i];
      tmp[i] = tmp[i+1];
      tmp[i+1] = tmpc;

      for (int m = 0; m < l+1; m++) {
        string tmp2;
        tmp2.assign(tmp);
        tmp2.resize(l+1);
        for (int j = l+1; j >= m; j--) {
          tmp2[j+1] = tmp[j];
        }
        for (int k = 97; k <= 122; k++) {
          tmp2[m] = (char) k ;
          //cout<<tmp2<<" ";
          if(hash.find(tmp2) != hash.end()){

            string t2;
            t2.assign(tmp2);
            //cout<<tmp2<<" ";
          output.push_back(t2);
        }

        }

      }
  }

  //cout<<"substitute -> insert";
  for (int i = 0; i < l; i++) {
    string tmp;
    tmp.assign(find);
    for (int j = 97; j <= 122; j++) {
      tmp[i] = (char)j;
      for (int m = 0; m < l+1; m++) {
        string tmp2;
        tmp2.assign(tmp);
        tmp2.resize(l+1);
        for (int j = l+1; j >= m; j--) {
          tmp2[j+1] = tmp[j];
        }
        for (int k = 97; k <= 122; k++) {
          tmp2[m] = (char) k ;
          //cout<<tmp2<<" ";
          if(hash.find(tmp2) != hash.end()){

            string t2;
            t2.assign(tmp2);
            //cout<<tmp2<<" ";
          output.push_back(t2);
        }

        }

      }
  }
}

    //cout<<"transpose -> substitute ";
    for (int i = 0; i < l-1; i++) {
      string tmp;
      tmp.assign(find);
      char tmpc;
      tmpc = tmp[i];
      tmp[i] = tmp[i+1];
      tmp[i+1] = tmpc;

      for (int m = 0; m < l; m++) {
      string tmp2;
      tmp2.assign(tmp);
      for (int j = 97; j <= 122; j++) {
        tmp2[m] = (char)j;

    if(hash.find(tmp2) != hash.end()){
      //cout<<tmp2<<" ";
      string t2;
      t2.assign(tmp2);
    output.push_back(t2);
    }
  }
}

    }




        std::vector<string>::iterator it;
        sort(output.begin(),output.end(),compare_alpha);
        it = unique( output.begin(), output.end(), eqaul );
        output.resize( distance(output.begin(),it) );


        if(output.size() == 0)
          cout<<"NONE";
        else{
        for (it=output.begin(); it!=output.end(); ++it)
          std::cout  << *it <<" ";
        }
        output.clear();
        cout<<endl;

} //end for else



}//end for while


  return 0;
}
