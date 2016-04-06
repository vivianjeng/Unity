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
    input >> row_size >> col_size;
    input.ignore(1);

    row.resize(row_size, vector<int>());
    for (int ri = 0; ri < row_size; ri++) {
        string line;
        getline(input, line);

        stringstream ss(line); int temp;
        while (ss >> temp) row[ri].push_back(temp);
    }

    col.resize(col_size, vector<int>());
    for (int ci = 0; ci < col_size; ci++) {
        string line;
        getline(input, line);

        stringstream ss(line); int temp;
        while (ss >> temp) col[ci].push_back(temp);
    }

    answer.resize(row_size, vector<int>(col_size));
}

bool check_col(int ci) {
    int run = 0, chi = 0;
    for (int ri = 0; ri < row_size; ri++) {
        if (answer[ri][ci] == 1) {
            run++;

            if (chi >= col[ci].size() || run > col[ci][chi])
                return false;
        }

        else if (answer[ri][ci] == 0) return true;
        else if (answer[ri][ci] == -1 && run > 0) {
            if (run != col[ci][chi])
                return false;
            run = 0;
            chi++;
        }
    }
    if (run > 0) {
        if (run != col[ci][chi])
            return false;
        chi++;
    }
    if (chi != col[ci].size())
        return false;

    return true;
}

int sum(vector<int> &vi) {
    int ret = 0;
    for (int i = 0; i < vi.size(); i++)
        ret += vi[i];
    return ret;
}


bool solve(int ri, bool debug = false) {

    for (int ci = 0; ci < col_size; ci++)
        if (check_col(ci) == false)
            return false;
	       //做column確認

    if (ri == row_size)
        return true;


    if (row[ri].size() == 1) {
       if (row[ri][0] == col_size) {
            for (int ci = 0; ci < col_size; ci++)
                answer[ri][ci] = 1;
            return solve(ri + 1, debug);
        }
    }
     //一行只輸入一個數字且等於col_size，此行填滿1

    int hints_sum = sum(row[ri]);
    if (hints_sum + row[ri].size() - 1 == col_size) {

        int pos = 0;
        for (int rhi = 0; rhi < row[ri].size(); rhi++) {
            for (int ci = 0; ci < row[ri][rhi]; ci++) {
                answer[ri][pos + ci] = 1;
            }
            pos += row[ri][rhi];

            if (rhi == row[ri].size() - 1)
            	continue;


            answer[ri][pos] = -1;
            pos += 1;
        }
        return solve(ri + 1, debug);
    }
    //輸入數字提示加空格剛好填滿一排


    vector<int> gap(row[ri].size(), 1);
    gap[0] = 0;
    do {
        int pos = gap[0];

        for (int ci = 0; ci < gap[0]; ci++)
            answer[ri][ci] = -1;

        for (int rhi = 0; rhi < row[ri].size(); rhi++) {
            for (int ci = 0; ci < row[ri][rhi]; ci++) {
                answer[ri][pos + ci] = 1;
            }
            pos += row[ri][rhi];


            if (rhi == row[ri].size() - 1)
            	continue;

            for (int ci = 0; ci < gap[rhi + 1]; ci++) {
                answer[ri][pos + ci] = -1;
            }
            pos += gap[rhi + 1];
        }

        for (int ci = pos; ci < col_size; ci++)
        	answer[ri][ci] = -1;


        if (solve(ri + 1, debug) == true)
            return true;


        for (int ci = 0; ci < col_size; ci++)
            answer[ri][ci] = 0;


        int gi = gap.size() - 1;
        gap[gi]++;
        while (hints_sum + sum(gap) > col_size && gi > 0) {
            gap[gi - 1]++;
            gap[gi] = 1;
            gi--;
        }


    }
    //row的每個位置嘗試
    while (hints_sum + sum(gap) <= col_size);

    return false;
}


int main() {

	  input(cin);
    solve(0, true);


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
