#include<bits/stdc++.h>

using namespace std;

int brute(vector<vector<int>> mat){
    int n = mat.size();
    vector<int> iKnow(n, 0);   // each index represents how many people i know
    vector<int> knowMe(n, 0);  // each index represents how many people know me

    for(int i = 0 ; i < mat.size() ; i++){
        for(int j = 0 ; j < mat[1].size() ; j++){
            if (mat[i][j] == 1){
                knowMe[j] +=1;
                iKnow[i] +=1;
            }
        }
    }

    for(int i =0  ; i < knowMe.size() ; i++){
        if(knowMe[i] == mat.size() - 1 and iKnow[i] == 0){
            return i;
            
        }
    }
    return -1;
}

int optimal(vector<vector<int>> mat){
    int top = 0;
    int down = mat.size() - 1;

    while(top < down){
        if(mat[top][down] == 1){
            top++; // top value knows the down value so it cannot be a celibraty
        }
        else if(mat[down][top] == 1){
            down--;
        }
        else{
            // top and bottom they doesnot know each other
            top++;
            down--;
        }
    }
    if(top > down){
        return -1;
    }

    for(int i = 0 ; i < mat.size() ; i++){
        if(i== top) continue;
        if(//checking for every row element
            mat[top][i] == 0 and
            //checking every column element
            mat[i][top] == 1
        ){
            return top;
        }
        else{
            return -1;
        }
    }

    /*
    int candidate = top;

    // Step 2: Verify the candidate
    for(int i = 0; i < mat.size(); i++){
        if(i == candidate) continue;
        if(mat[candidate][i] == 1 || mat[i][candidate] == 0){
            return -1; // candidate knows someone or is not known by someone
        }
    }

    return candidate;
    */

}

int main(){
    vector<vector<int>> mat = {
        {0,1,1,0},
        {0,0,0,0},
        {0,1,0,0},
        {1,1,0,0}
    };

    cout << optimal(mat);
}