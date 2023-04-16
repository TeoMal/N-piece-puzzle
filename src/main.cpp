#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include<string>
#include"../include/Puzzle.hpp"
#include "../include/Heuristic.hpp"
#include<queue>
#include<list>
using namespace std;
void Solve(vector<vector<int>> grid);
vector<int> splitAndConvertToInts(string input, char delimiter) {
    vector<int> output;
    stringstream ss(input);
    string item;
    while (getline(ss, item, delimiter)) {
        output.push_back(stoi(item));
    }
    return output;
}
vector<vector<int>> read_from_file(vector<string> input,int n){
    vector<int> integer_line;
    vector<vector<int>> grid(n,vector<int>(n,0));
    for (int i = 0; i < n; i++) {
        integer_line=splitAndConvertToInts(input[i],'.');
        for (int j = 0; j < n; j++) {
            grid[i][j]=integer_line[j];
        }
        integer_line.clear();
    }
    return grid;
}
int main(int argc,char ** argv)
{
    if (argc!= 2){
        perror("Wrong amount of arguments\nExecute program: ./executable input_file");
        exit(1);
    }
    ifstream file;
    file.open(argv[1]);
    if(!file){
        perror("Couldn't find the input file...\nExiting\n");
        exit(2);
    }
    int n=0;
    string line;
    getline(file,line);
    n=stoi(line);
    if(n==0){
        perror("Couldn't get the size of the board please provide the size of the board in the first line of the .txt file and in the following the input\n");
        exit(3);
    }
    cout <<"Size is " << n << endl;
    
    vector <string> input_lines;
    while(getline(file,line)){
        input_lines.push_back(line);
    }
    vector<vector<int>> grid=read_from_file(input_lines,n);
    file.close();
    Solve(grid);
    grid.clear();
    return 0;
}


void Solve(vector<vector<int>> grid){
    //Find blank
    struct point blank;
    int n=(int)grid.size();
    blank.x=-1;
    blank.y=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==-1){
                blank={i,j};
            }
        }
    }
    if(blank.x==-1){
        perror("You didn't provide a blank spot to do so put -1");
        exit(4);
    }
    Puzzle *Node= new Puzzle(grid,blank,0,heuristic(grid),NULL);
    Puzzle *temp;
    priority_queue<Puzzle *> Queue;
    list<Puzzle *> Trash;
    Queue.push(Node);
    while(!Queue.empty()){
        Node=Queue.top();
        Trash.push_back(Node);
        //Check that we have reached end state
        if(Node->is_goal()){
            Node->print_path();
            break;
        }
        
        //Expand here and have parent current node
        
        
        Queue.pop();

    }

    //Destroy Funct
    while(!Trash.empty()){
        temp=Trash.back();
        Trash.pop_back();
        delete temp;
    }
}