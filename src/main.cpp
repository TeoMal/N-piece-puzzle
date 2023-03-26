#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include<string>
#include"../include/Puzzle.hpp"
#include "../include/Heuristic.hpp"
#include<queue>
void Solve(std::vector<std::vector<int>> grid);
std::vector<int> splitAndConvertToInts(std::string input, char delimiter) {
    std::vector<int> output;
    std::stringstream ss(input);
    std::string item;
    while (getline(ss, item, delimiter)) {
        output.push_back(stoi(item));
    }
    return output;
}
std::vector<std::vector<int>> read_from_file(std::vector<std::string> input,int n){
    std::vector<int> integer_line;
    std::vector<std::vector<int>> grid(n,std::vector<int>(n,0));
    for (int i = 0; i < n; i++) {
        integer_line=splitAndConvertToInts(input[i],'.');
        for (int j = 0; j < integer_line.size(); j++) {
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
    std::ifstream file;
    file.open(argv[1]);
    if(!file){
        perror("Couldn't find the input file...\nExiting\n");
        exit(2);
    }
    int n=0;
    std::string line;
    getline(file,line);
    n=stoi(line);
    if(n==0){
        perror("Couldn't get the size of the board please provide the size of the board in the first line of the .txt file and in the following the input\n");
        exit(3);
    }
    std::cout <<"Size is " << n << std::endl;
    
    std::vector <std::string> input_lines;
    while(getline(file,line)){
        input_lines.push_back(line);
    }
    std:: cout << input_lines.size() << std::endl;
    std::vector<std::vector<int>> grid=read_from_file(input_lines,n);
    file.close();
    Solve(grid);
    grid.clear();
    return 0;
}


void Solve(std::vector<std::vector<int>> grid){
    //Find blank
    struct point blank;
    blank.x=-1;
    blank.y=-1;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==-1){
                blank={i,j};
            }
        }
    }
    if(blank.x==-1){
        perror("You didn't provide a blank spot to do so put -1");
        exit(4);
    }
    Puzzle Node(grid,blank,0,heuristic(grid),NULL);
    std::priority_queue<Puzzle> Queue;
    Queue.push(Node);
    while(!Queue.empty()){
        Node=Queue.top();
        //Check that we have reached end state
        
        
        //Expand here and have parent current node
        Queue.pop();
    }
    //Destroy Funct
}