#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(pair<string,string> a, pair<string,string> b){
  if (atoi(a.second.c_str()) > atoi(b.second.c_str())) return true;
  else if(a.second == b.second)
    return a.first < b.first;
  else
  return false ;
  }

  bool eqaul(pair<string,string> a, pair<string,string> b){
    return (!a.first.compare(b.first));
  }

int main(){

  //FILE * pFile;
  //pFile = fopen ("2gm.small.txt","r");
  char buffer[100];
  unordered_map<string,string> hash;
  vector<pair<string,string>> output;
/*
  while(!feof(pFile)){
    fgets(buffer,100,pFile);
    if(buffer[strlen(buffer) - 1] == '\n')
      buffer[strlen(buffer) - 1] = '\0';

    char *word;
    char *frequency;

    word = strtok(buffer,"\t");
    string put_in = strdup(word);
    long int i;
    frequency = strtok(NULL,"\n");
    i = strtol(frequency,&frequency,10);

    hash.insert(make_pair(put_in,i));
  }
  fclose (pFile);
  */

  FILE * pFile_2;
  FILE * pFile_3;
  FILE * pFile_4;
  FILE * pFile_5;
  pFile_2 = fopen ("/tmp2/dsa2016_project/2gm.small.txt","r");
  pFile_3 = fopen ("/tmp2/dsa2016_project/3gm.small.txt","r");
  pFile_4 = fopen ("/tmp2/dsa2016_project/4gm.small.txt","r");
  pFile_5 = fopen ("/tmp2/dsa2016_project/5gm.small.txt","r");

  while(fgets(buffer,100,pFile_2)!=NULL){
    if(buffer[strlen(buffer) - 1] == '\n')
      buffer[strlen(buffer) - 1] = '\0';

    char *word;
    char *frequency;

    word = strtok(buffer,"\t");
    if(word!=NULL){
    string put_str(word);
    frequency = strtok(NULL,"\n");
    if(frequency!=NULL){
    string put_in(frequency);
    hash.insert(make_pair(put_str,put_in));
  }
  }
}

while(fgets(buffer,100,pFile_3)!=NULL){
  if(buffer[strlen(buffer) - 1] == '\n')
    buffer[strlen(buffer) - 1] = '\0';

  char *word;
  char *frequency;

  word = strtok(buffer,"\t");
  if(word!=NULL){
  string put_str(word);
  frequency = strtok(NULL,"\n");
  if(frequency!=NULL){
  string put_in(frequency);
  hash.insert(make_pair(put_str,put_in));
}
}
}

while(fgets(buffer,100,pFile_4)!=NULL){
  if(buffer[strlen(buffer) - 1] == '\n')
    buffer[strlen(buffer) - 1] = '\0';

  char *word;
  char *frequency;

  word = strtok(buffer,"\t");
  if(word!=NULL){
  string put_str(word);
  frequency = strtok(NULL,"\n");
  if(frequency!=NULL){
  string put_in(frequency);
  hash.insert(make_pair(put_str,put_in));
}
}
}

    while(fgets(buffer,100,pFile_5)!=NULL){
      if(buffer[strlen(buffer) - 1] == '\n')
        buffer[strlen(buffer) - 1] = '\0';

      char *word;
      char *frequency;

      word = strtok(buffer,"\t");
      if(word!=NULL){
      string put_str(word);
      frequency = strtok(NULL,"\n");
      if(frequency!=NULL){
      string put_in(frequency);
      hash.insert(make_pair(put_str,put_in));
    }
    }
  }



vector<string> prep;
prep.push_back("of");
prep.push_back("to");
prep.push_back("in");
prep.push_back("for");
prep.push_back("with");
prep.push_back("on");
prep.push_back("at");
prep.push_back("by");
prep.push_back("from");
prep.push_back("up");
prep.push_back("about");
prep.push_back("than");
prep.push_back("after");
prep.push_back("before");
prep.push_back("down");
prep.push_back("between");
prep.push_back("under");
prep.push_back("since");
prep.push_back("without");
prep.push_back("near");

  char line[100];

  while (fgets(buffer,100,stdin)!=NULL)
  {
    vector<string> gram;
    vector<int> pos;
    int run=0;

    if(buffer[strlen(buffer) - 1] == '\n')
      buffer[strlen(buffer) - 1] = '\0';

      string result(buffer);
      char *word;
      word = strtok(buffer," ");
      while(word != NULL){
         string put_in(word);
         gram.push_back(put_in);
          word = strtok(NULL," ");
      }

      for (int j = 0; j < gram.size(); j++) {
        for (int i = 0; i < 20; i++) {
          if(gram[j] == prep[i]){
            pos.push_back(j);
          }
        }
      }
      for (int i = 0; i < pos.size(); i++) {
        if(pos[i+1]!=pos[i]+1){
          run++;
        }
      }

      unordered_map<std::string,string>::const_iterator got;

      got = hash.find (result);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }

      string find;
      int m=0;
      if(pos.size()==run && gram.size() > 5){
        for (int i = 0; i < gram.size(); i++) {
          if(i==pos[m]){
            m++;
            if(i==gram.size()-1){
              //find = find +gram[i];
              find.resize(find.size()-1);
              //cout<<find<<endl;
              got = hash.find (find);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              find.clear();
              //m=0;
            }
          }
          else{
            if(i<gram.size()-1)
              find = find+gram[i]+' ';
            else{
              find = find +gram[i];
              //cout<<find<<endl;
              got = hash.find (find);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              find.clear();
              //m=0;
            }
          }
          }
      }

      if(gram.size()==1){
        for (int i = 0; i < 20; i++) {
          got = hash.find (result+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (prep[i]+' '+result);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          for (int j = 0; j < 20; j++) {
        got = hash.find (result+' '+prep[i]+' '+prep[j]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (prep[j]+' '+result+' '+prep[i]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (result+' '+prep[j]+' '+prep[i]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      }
    }

      if (pos.size()==0) {
        if(gram.size()==2){
          for (int i = 0; i < 20; i++) {
              got = hash.find (prep[i]+' '+result);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (result+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }

            for (int j = 0; j < 20; j++) {
              got = hash.find (result+' '+prep[i]+' '+prep[j]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[j]+' '+gram[1]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[j]+' '+prep[i]+' '+gram[1]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[j]+' '+gram[0]+' '+prep[i]+' '+gram[1]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[j]+' '+gram[0]+' '+gram[1]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[j]+' '+prep[i]+' '+result);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
            }//end for j
            }//end for i
          }//end if gram ==2
          else if(gram.size()==3){
            for (int i = 0; i < 20; i++) {
            got = hash.find (prep[i]+' '+result);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (result+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            for (int j = 0; j < 20; j++) {
              got = hash.find (result+' '+prep[i]+' '+prep[j]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[j]+' '+gram[1]+' '+prep[i]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[j]+' '+gram[1]+' '+gram[2]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+prep[j]+' '+gram[2]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+prep[j]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[i]+' '+gram[0]+' '+prep[j]+' '+gram[1]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[j]+' '+prep[i]+' '+gram[1]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+prep[j]+' '+prep[i]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[j]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[j]+' '+prep[i]+' '+result);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
            }//end for j
          }//end for i
        }//end if 3
        else if(gram.size()==4){
          for (int i = 0; i < 20; i++) {
          got = hash.find (prep[i]+' '+result);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (result+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
      }//end if 4
      }//end pos size ==0

      else if(pos.size()==1){
        if(gram.size()==2){
          if(pos[0]==0){
            for (int i = 0; i < 20; i++) {
              got = hash.find (prep[i]+' '+gram[1]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }

            }
          }//end if pos = 0

          if(pos[0]==1){
            for (int i = 0; i < 20; i++) {
              got = hash.find (gram[0]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
                got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]);
                if(!(got == hash.end())){
                  output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
            }
            }
          }//end if pos = 1
        }//end if gram = 2

      else if(gram.size()==3){
          if(pos[0]==0){
            for (int i = 0; i < 20; i++) {
              got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
                got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]);
                if(!(got == hash.end())){
                  output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
            }
          }
          got = hash.find (gram[1]+' '+gram[2]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        else if(pos[0]==1){
          for (int i = 0; i < 20; i++) {
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
        }
        got = hash.find (gram[0]+' '+gram[2]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        }
        else if(pos[0]==2){
          for (int i = 0; i < 20; i++) {
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
              got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
        }
        got = hash.find (gram[0]+' '+gram[1]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      }//end gram ==3
    else if(gram.size()==4){
      if(pos[0]==0){
        for (int i = 0; i < 20; i++) {
          got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
            got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
      got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==1){
        for (int i = 0; i < 20; i++) {
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
      }
      got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }
      }
      else if(pos[0]==2){
        for (int i = 0; i < 20; i++) {
          got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
      }
      got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }
      }
      else if(pos[0]==3){
        for (int i = 0; i < 20; i++) {
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
      }
      got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }
      }
    }//end if gram ==4
    else if(gram.size()==5){
      if(pos[0]==0){
        for (int i = 0; i < 20; i++) {
          got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
      got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }
      }
      else if(pos[0]==1){
        for (int i = 0; i < 20; i++) {
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
      got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }
      }
      else if(pos[0]==2){
        for (int i = 0; i < 20; i++) {
          got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
      got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }
      }
      else if(pos[0]==3){
        for (int i = 0; i < 20; i++) {
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
      got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }
      }
      else if(pos[0]==4){
        for (int i = 0; i < 20; i++) {
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
      got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }
      }
    }//end if gram ==5
    else if(gram.size()==6){
      if(pos[0]==0){
        got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==1){
        got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==2){
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==3){
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==4){
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==5){
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
    }
  }//end if pos size ==1

  else if(pos.size()==2){
    if(gram.size()==2){
      for (int i = 0; i < 20; i++) {
          got = hash.find (prep[i]+' '+gram[1]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
    }
    else if(gram.size()==3){
      if(pos[0]==0 && pos[1]==1){
        for (int i = 0; i < 20; i++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
              got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
            }
            got = hash.find (gram[1]+' '+gram[2]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[2]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
      }
      else if(pos[0]==0 && pos[1]==2){
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 20; j++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+prep[j]+' '+gram[2]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+prep[j]+' '+gram[2]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+prep[j]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+prep[j]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (prep[i]+' '+gram[1]+' '+prep[j]+' '+gram[2]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (prep[i]+' '+gram[1]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[1]+' '+prep[i]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        got = hash.find (gram[0]+' '+gram[1]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[1]+' '+gram[2]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==1 && pos[1]==2){
        for (int i = 0; i < 20; i++) {
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+prep[2]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+prep[2]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+prep[2]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+prep[i]+' '+prep[2]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        got = hash.find (gram[0]+' '+gram[1]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[2]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
    }//end gram size ==3
    else if(gram.size()==4){
      if(pos[0]==0 && pos[1]==1){
        for (int i = 0; i < 20; i++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
              got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
      else if(pos[0]==0 && pos[1]==2){
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 20; j++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+prep[j]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+prep[j]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+prep[j]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[1]+' '+prep[j]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            }
            got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+prep[i]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
              got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[1]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
      }
      else if(pos[0]==0 && pos[1]==3){
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 20; j++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
              got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
        }
        got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[1]+' '+gram[2]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==1 && pos[1]==2){
        for (int i = 0; i < 20; i++) {
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
        }
        got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==1 && pos[1]==3){
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 20; j++) {
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+prep[j]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[2]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[2]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==2 && pos[1]==3){
        for (int i = 0; i < 20; i++) {
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
              got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }

    }//end if gram size ==4
    else if(gram.size()==5){
      if(pos[0]==0 && pos[1]==1){
        for (int i = 0; i < 20; i++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
      else if(pos[0]==0 && pos[1]==2){
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 20; j++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+prep[j]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
            got = hash.find (gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
      else if(pos[0]==0 && pos[1]==3){
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 20; j++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
            got = hash.find (gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }

          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
      else if(pos[0]==0 && pos[1]==4){
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 20; j++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
            got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
      else if(pos[0]==1 && pos[1]==2){
        for (int i = 0; i < 20; i++) {
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
      else if(pos[0]==1 && pos[1]==3){
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 20; j++) {
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+prep[j]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
            got = hash.find (gram[0]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[2]+' '+gram[4]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==1 && pos[1]==4){
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 20; j++) {
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==2 && pos[1]==3){
        for (int i = 0; i < 20; i++) {
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==2 && pos[1]==4){
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 20; j++) {
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==3 && pos[1]==4){
        for (int i = 0; i < 20; i++) {
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
        }
      }
    }//gram size ==5
    else if(gram.size()==6){
        if(pos[0]==0 && pos[1]==1){
            got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        else if(pos[0]==1 && pos[1]==2){
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        else if(pos[0]==2 && pos[1]==3){
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        else if(pos[0]==3 && pos[1]==4){
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        else if(pos[0]==4 && pos[1]==5){
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        else if(pos[0]==0 && pos[1]==2){
          for (int i = 0; i < 20; i++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        else if(pos[0]==0 && pos[1]==3){
          for (int i = 0; i < 20; i++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        else if(pos[0]==0 && pos[1]==4){
          for (int i = 0; i < 20; i++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        else if(pos[0]==0 && pos[1]==5){
          for (int i = 0; i < 20; i++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        else if(pos[0]==1 && pos[1]==4){
          for (int i = 0; i < 20; i++) {
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+prep[i]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        else if(pos[0]==1 && pos[1]==5){
          for (int i = 0; i < 20; i++) {
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        else if(pos[0]==2 && pos[1]==4){
          for (int i = 0; i < 20; i++) {
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+prep[i]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        else if(pos[0]==2 && pos[1]==5){
          for (int i = 0; i < 20; i++) {
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }
        else if(pos[0]==3 && pos[1]==5){
          for (int i = 0; i < 20; i++) {
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
        }

    }
  }//end if pos size==2

  else if(pos.size()==3){
    if(gram.size()==3){
      for (int i = 0; i < 20; i++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
      }
      got = hash.find (gram[0]+' '+gram[1]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }
      got = hash.find (gram[0]+' '+gram[2]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }
      got = hash.find (gram[1]+' '+gram[2]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }
    }//gram size ==3
    else if(gram.size()==4){
      if(pos[0]==0 && pos[1]==1 && pos[2]==2){
        for (int i = 0; i < 20; i++) {
              got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
            }
            got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
      else if(pos[0]==0 && pos[1]==1 && pos[2]==3){
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 20; j++) {
          got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+prep[j]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[j]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+prep[j]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+prep[j]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]+' '+prep[j]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[j]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
          got = hash.find (gram[1]+' '+gram[2]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[1]+' '+gram[2]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[2]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==0 && pos[1]==2 && pos[2]==3){
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 20; j++) {
              got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[j]+' '+gram[1]+' '+prep[i]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[j]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[j]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[j]+' '+gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[j]+' '+gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[j]+' '+gram[1]+' '+prep[i]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[j]+' '+gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[j]+' '+gram[1]+' '+gram[2]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
            }
            got = hash.find (gram[1]+' '+prep[i]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+gram[2]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
              got = hash.find (gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
        }
        got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[1]+' '+gram[2]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[1]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
      else if(pos[0]==1 && pos[1]==2 && pos[2]==3){
        for (int i = 0; i < 20; i++) {
              got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
              got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
        }
        got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }
    }//gram size ==4
      else if(gram.size()==5){
              if(pos[0]==0 && pos[1]==1 && pos[2]==2){
                for (int i = 0; i < 20; i++) {
                  got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                    output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                    output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                    output.push_back(make_pair(got->first,got->second));
                  }
                }
                got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
                if(!(got == hash.end())){
                  output.push_back(make_pair(got->first,got->second));
                }
                got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                if(!(got == hash.end())){
                  output.push_back(make_pair(got->first,got->second));
                }
                got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                if(!(got == hash.end())){
                  output.push_back(make_pair(got->first,got->second));
                }
              }
              else if(pos[0]==0 && pos[1]==1 && pos[2]==3){
                  for (int i = 0; i < 20; i++) {
                    for (int j = 0; j < 20; j++) {
                  got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]+' '+gram[4]);
                  if(!(got == hash.end())){
                    output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+prep[j]+' '+gram[4]);
                  if(!(got == hash.end())){
                    output.push_back(make_pair(got->first,got->second));
                  }
                  }
                  got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[4]);
                  if(!(got == hash.end())){
                    output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
                  if(!(got == hash.end())){
                    output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
                  if(!(got == hash.end())){
                    output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
                  if(!(got == hash.end())){
                    output.push_back(make_pair(got->first,got->second));
                  }
                }
                got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
                if(!(got == hash.end())){
                  output.push_back(make_pair(got->first,got->second));
                }
                got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                if(!(got == hash.end())){
                  output.push_back(make_pair(got->first,got->second));
                }
                got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                if(!(got == hash.end())){
                  output.push_back(make_pair(got->first,got->second));
                }
                got = hash.find (gram[1]+' '+gram[2]+' '+gram[4]);
                if(!(got == hash.end())){
                  output.push_back(make_pair(got->first,got->second));
                }
                got = hash.find (gram[0]+' '+gram[2]+' '+gram[4]);
                if(!(got == hash.end())){
                  output.push_back(make_pair(got->first,got->second));
                }
              }
              else if(pos[0]==0 && pos[1]==1 && pos[2]==4){
                for (int i = 0; i < 20; i++) {
                  for (int j = 0; j < 20; j++) {
                      got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[j]);
                      if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                      }
                      got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+prep[j]);
                      if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                      }
                    }
                    got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
                    if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                    }
                    got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
                    if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                    }
                    got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
                    if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                    }
                    got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
                    if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                    }
                    }
                    got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
                    if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                    }
                    got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                    if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                    }
                    got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                    if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                    }
                    got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]);
                    if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                    }
                    got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]);
                    if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                    }
                  }
                  else if(pos[0]==0 && pos[1]==2 && pos[2]==3){
                    for (int i = 0; i < 20; i++) {
                          got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                          if(!(got == hash.end())){
                            output.push_back(make_pair(got->first,got->second));
                          }
                          got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
                          if(!(got == hash.end())){
                            output.push_back(make_pair(got->first,got->second));
                          }
                          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
                          if(!(got == hash.end())){
                            output.push_back(make_pair(got->first,got->second));
                          }
                        }
                        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
                        if(!(got == hash.end())){
                          output.push_back(make_pair(got->first,got->second));
                        }
                        got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                        if(!(got == hash.end())){
                          output.push_back(make_pair(got->first,got->second));
                        }
                        got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
                        if(!(got == hash.end())){
                          output.push_back(make_pair(got->first,got->second));
                        }
                      }
              else if(pos[0]==0 && pos[1]==2 && pos[2]==4){
                for (int i = 0; i < 20; i++) {
                  for (int j = 0; j < 20; j++) {
                    for (int k = 0; k < 20; k++) {
                    got = hash.find (prep[i]+' '+gram[1]+' '+prep[j]+' '+gram[3]+' '+prep[k]);
                    if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                    }
                  }
                  got = hash.find (gram[1]+' '+prep[i]+' '+gram[3]+' '+prep[j]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (prep[i]+' '+gram[1]+' '+gram[3]+' '+prep[j]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (prep[i]+' '+gram[1]+' '+prep[j]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]+' '+prep[j]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+prep[i]+' '+gram[3]+' '+prep[j]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[3]+' '+prep[j]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+prep[j]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+prep[j]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+prep[j]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (prep[i]+' '+gram[1]+' '+prep[j]+' '+gram[2]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (prep[i]+' '+gram[1]+' '+gram[3]+' '+prep[j]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (prep[i]+' '+gram[1]+' '+gram[3]+' '+gram[4]+' '+prep[j]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (prep[i]+' '+gram[0]+' '+gram[1]+' '+gram[3]+' '+prep[j]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+prep[i]+' '+gram[1]+' '+gram[3]+' '+prep[j]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                }
                got = hash.find (prep[i]+' '+gram[1]+' '+gram[3]);
                if(!(got == hash.end())){
                    output.push_back(make_pair(got->first,got->second));
                }
                got = hash.find (gram[1]+' '+prep[i]+' '+gram[3]);
                if(!(got == hash.end())){
                    output.push_back(make_pair(got->first,got->second));
                }
                got = hash.find (gram[1]+' '+gram[3]+' '+prep[i]);
                if(!(got == hash.end())){
                    output.push_back(make_pair(got->first,got->second));
                }
               }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
              }
              else if(pos[0]==0 && pos[1]==2 && pos[2]==3){
                for (int i = 0; i < 20; i++) {
                  for (int j = 0; j < 20; j++) {
                    got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]+' '+gram[4]);
                    if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                    }
                    got = hash.find (prep[i]+' '+gram[1]+' '+prep[j]+' '+gram[3]+' '+gram[4]);
                    if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                    }
                  }
                  got = hash.find (gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (prep[i]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+gram[2]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
              }
              else if(pos[0]==0 && pos[1]==3 && pos[2]==4){
                for (int i = 0; i < 20; i++) {
                  for (int j = 0; j < 20; j++) {
                    got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[j]);
                    if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                    }
                    got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+prep[j]+' '+gram[4]);
                    if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                    }
                  }
                  got = hash.find (gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+gram[2]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
              }
              else if(pos[0]==1 && pos[1]==2 && pos[2]==3){
                for (int i = 0; i < 20; i++) {
                    got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                    if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                    }
                    got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
                    if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                    }
                    got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
                    if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                    }
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
              }
              else if(pos[0]==1 && pos[1]==2 && pos[2]==4){
                for (int i = 0; i < 20; i++) {
                  for (int j = 0; j < 20; j++) {
                    got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+prep[j]);
                    if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                    }
                    got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+prep[j]);
                    if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                    }
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+prep[i]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
              }
              else if(pos[0]==1 && pos[1]==3 && pos[2]==4){
                for (int i = 0; i < 20; i++) {
                  for (int j = 0; j < 20; j++) {
                    got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+prep[j]);
                    if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                    }
                    got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+prep[j]+' '+gram[4]);
                    if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                    }
                  }
                  got = hash.find (gram[0]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[2]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
              }
              else if(pos[0]==2 && pos[1]==3 && pos[2]==4){
                for (int i = 0; i < 20; i++) {
                    got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
                    if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                    }
                    got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
                    if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                    }
                    got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
                    if(!(got == hash.end())){
                        output.push_back(make_pair(got->first,got->second));
                    }
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
                  got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
                  if(!(got == hash.end())){
                      output.push_back(make_pair(got->first,got->second));
                  }
              }
      }//gram size ==5
      else if(gram.size()==6){
        if(pos[0]==0 && pos[1]==1 && pos[2]==2){
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        else if(pos[0]==1 && pos[1]==2 && pos[2]==3){
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        else if(pos[0]==2 && pos[1]==3 && pos[2]==4){
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        else if(pos[0]==3 && pos[1]==4 && pos[2]==5){
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        else if(pos[0]==0 && pos[1]==2 && pos[2]==4){
          got = hash.find (gram[1]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          for (int i = 0; i < 20; i++) {
            got = hash.find (gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
        }
        else if(pos[0]==1 && pos[1]==3 && pos[2]==4){
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        else if(pos[0]==0 && pos[1]==1 && pos[2]==4){
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        else if(pos[0]==0 && pos[1]==1 && pos[2]==3){
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        else if(pos[0]==2 && pos[1]==4 && pos[2]==5){
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        else if(pos[0]==0 && pos[1]==3 && pos[2]==5){
          for (int i = 0; i < 20; i++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
        }
        else if(pos[0]==1 && pos[1]==3 && pos[2]==5){
          for (int i = 0; i < 20; i++) {
            got = hash.find (gram[0]+' '+gram[2]+' '+gram[4]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
        }
        else if(pos[0]==0 && pos[1]==2 && pos[2]==5){
          for (int i = 0; i < 20; i++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+gram[3]+' '+gram[4]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
      }
      else if(gram.size()==7){
        if(pos[0]==1 && pos[1]==4 && pos[2]==5){
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[5]+' '+gram[6]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]+' '+gram[6]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        else if(pos[0]==3 && pos[1]==5 && pos[2]==6){
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[6]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        else if(pos[0]==2 && pos[1]==3 && pos[2]==6){
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
      }
  }//end if pos size ==3

  else if(pos.size()==4){
    if(gram.size()==4){
      for (int i = 0; i < 20; i++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
      }
      got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }
      got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }
      got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }
      got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]);
      if(!(got == hash.end())){
        output.push_back(make_pair(got->first,got->second));
      }
    }//end if gram ==4

    else if(gram.size()==5){
      if(pos[0]==0 && pos[1]==1 && pos[2]==2 && pos[3]==3){
        for (int i = 0; i < 20; i++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }

      else if(pos[0]==0 && pos[1]==1 && pos[2]==2 && pos[3]==4){
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 20; j++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+prep[j]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
      else if(pos[0]==0 && pos[1]==1 && pos[2]==3 && pos[3]==4){
        for (int i = 0; i < 20; i++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
      else if(pos[0]==0 && pos[1]==2 && pos[2]==3 && pos[3]==4){
        for (int i = 0; i < 20; i++) {
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }

      else if(pos[0]==1 && pos[1]==2 && pos[2]==3 && pos[3]==4){
        for (int i = 0; i < 20; i++) {
            got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
    }//end if gram == 5

    else if(gram.size()==6){
      if(pos[0]==0 && pos[1]==1 && pos[2]==3 && pos[3]==4){
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
      else if(pos[0]==0 && pos[1]==2 && pos[2]==3 && pos[3]==5){
          for (int i = 0; i < 20; i++) {
            got = hash.find (gram[1]+' '+gram[2]+' '+gram[4]+' '+prep[i]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
            if(!(got == hash.end())){
              output.push_back(make_pair(got->first,got->second));
            }
            for (int j = 0; j < 20; j++) {
              got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[4]+' '+prep[j]);
              if(!(got == hash.end())){
                output.push_back(make_pair(got->first,got->second));
              }
            }
          }
      }
      else if(pos[0]==0 && pos[1]==2 && pos[2]==4 && pos[3]==5){
          got = hash.find (gram[1]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
    }
    else if(gram.size()==7){
      if(pos[0]==0 && pos[1]==1 && pos[2]==3 && pos[3]==4){
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[5]+' '+gram[6]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[4]+' '+gram[5]+' '+gram[6]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]+' '+gram[6]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[4]+' '+gram[5]+' '+gram[6]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
      else if(pos[0]==0 && pos[1]==2 && pos[2]==4 && pos[3]==6){
          got = hash.find (gram[1]+' '+gram[3]+' '+gram[5]+' '+gram[6]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[3]+' '+gram[4]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[5]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
      else if(pos[0]==1 && pos[1]==2 && pos[2]==4 && pos[3]==5){
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[5]+' '+gram[6]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[2]+' '+gram[4]+' '+gram[6]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[5]+' '+gram[6]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[4]+' '+gram[6]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
      }
    }//end if gram ==7

  }//end if pos size ==4

  else if(pos.size()==5){
    if(gram.size()==5){
      for (int i = 0; i < 20; i++) {
        got = hash.find (prep[i]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
          got = hash.find (gram[0]+' '+prep[i]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+prep[i]+' '+gram[3]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+prep[i]+' '+gram[4]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
          got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]+' '+prep[i]);
          if(!(got == hash.end())){
            output.push_back(make_pair(got->first,got->second));
          }
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[3]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[2]+' '+gram[4]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[1]+' '+gram[3]+' '+gram[4]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[0]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
        got = hash.find (gram[1]+' '+gram[2]+' '+gram[3]+' '+gram[4]);
        if(!(got == hash.end())){
          output.push_back(make_pair(got->first,got->second));
        }
      }//gram size==5
  }//end if pos size==5

    std::vector<pair<string,string>>::iterator it;
    sort(output.begin(),output.end(),compare);
    it = unique( output.begin(), output.end(), eqaul );
    output.resize( distance(output.begin(),it) );
    if(output.size()>10){
      output.resize(10);
    }
   //unordered_map<string,long int>::iterator it;
   cout<<"query: "<<result<<endl;
   cout<<"output: "<<output.size()<<endl;

   for (it=output.begin(); it!=output.end(); ++it)
     cout << it->first << "\t" << it->second<<endl;

     gram.clear();
     pos.clear();
     output.clear();
     run = 0;
}
/*
  string input;
  getline (cin,input);
  std::unordered_map<std::string,long int>::const_iterator got = hash.find (input);

 if ( got == hash.end() )
   std::cout << "not found";
 else
   std::cout << got->first << "\t" << got->second;
*/





  return 0;
}
