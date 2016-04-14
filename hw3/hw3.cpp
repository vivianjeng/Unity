#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


int row_size, col_size;
vector< vector<int> > row;
vector< vector<int> > col;
vector< vector<int> > answer;

void input(istream &input) {
    input>>row_size>>col_size;
    input.ignore(1);

    row.resize(row_size, vector<int>());
    for (int ri = 0; ri < row_size; ri++) {
        string line;
        getline(input, line);

        stringstream ss(line); int temp;
        while (ss>>temp)
        row[ri].push_back(temp);
    }

    col.resize(col_size, vector<int>());
    for (int ci = 0; ci < col_size; ci++) {
        string line;
        getline(input, line);

        stringstream ss(line);
        int temp;
        while (ss >> temp)
        col[ci].push_back(temp);
    }

    answer.resize(row_size, vector<int>(col_size));
}


bool check(int ci){
	int run=0,j=0;
	for(int i=0;i<row_size;i++){
		if (answer[i][ci] == 1){
			run++;
			if(j >= col[ci].size() || run > col[ci][j])
				return false;
		}
		else if (answer[i][ci] == 0)
			return true;
		else if (answer[i][ci] == -1 && run>0){
			if(run != col[ci][j])
				return false;
			run = 0;
			j ++;
		}
	}

	if (run > 0){
		if(run != col[ci][j])
			return false;
		j++;
	}
	if(j != col[ci].size())
		return false;

	return true;
}

int sum(vector<int> &vi) {
    int s = 0;
    for (int i = 0; i < vi.size(); i++)
        s += vi[i];
    return s;
}


bool solve(int ri) {

    for (int i = 0; i < col_size; i++)
        if (check(i) == false)
        return false;
	//每次做column確認

    if (ri == row_size)
        return true;


    if (row[ri].size() == 1) {
       if (row[ri][0] == col_size) {
            for (int i = 0; i < col_size; i++)
                answer[ri][i] = 1;
            return solve(ri + 1);
        }
    } //一行只輸入一個數字且等於col_size，此行填滿1

    int hints = sum(row[ri]);
    if (hints + row[ri].size() - 1 == col_size) {

        int pos = 0;
        for (int k = 0; k < row[ri].size(); k++) {
            for (int ci = 0; ci < row[ri][k]; ci++) {
                answer[ri][pos + ci] = 1;
            }
            pos += row[ri][k];

            if (k == row[ri].size() - 1)
            	continue;


            answer[ri][pos] = -1;
            pos += 1;
        }
        return solve(ri + 1);
    } //輸入數字提示加空格剛好填滿一排


    vector<int> gap(row[ri].size(), 1);
    gap[0] = 0;
    do {
        int pos = gap[0];

        for (int i = 0; i < gap[0]; i++)
            answer[ri][i] = -1;

        for (int k = 0; k < row[ri].size(); k++) {
            for (int i = 0; i < row[ri][k]; i++) {
                answer[ri][pos + i] = 1;
            }
            pos += row[ri][k];


            if (k == row[ri].size() - 1)
            	continue;

            for (int i = 0; i < gap[k + 1]; i++) {
                answer[ri][pos + i] = -1;
            }
            pos += gap[k + 1];
        }

        for (int i = pos; i < col_size; i++)
        	answer[ri][i] = -1;


        if (solve(ri + 1) == true)
            return true;


        for (int i = 0; i < col_size; i++)
            answer[ri][i] = 0;


        int s = gap.size() - 1;
        gap[s]++;

        while (hints + sum(gap) > col_size && s > 0) {
            gap[s-1]++;
            gap[s]=1;
            s--;
        }


    } while (hints + sum(gap) <= col_size);
    //row的每個位置嘗試
    return false;
}



int main() {

	 input(cin);

   solve(0);


	for(int l=0;l<row_size;l++){
	for(int w=0;w<col_size;w++){
		if(answer[l][w]==1)
		 cout<<"#" ;
		else
		 cout<<".";
	}
		cout<<endl;
	}


	return 0;
}
