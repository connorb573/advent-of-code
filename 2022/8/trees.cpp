#include <iostream>
#include <fstream>
#include <vector>

int main(){
    std::ifstream infile("input.txt");

    std::string line;
    int trees_visible;

    std::vector<std::vector<int>> grid {};
    while(std::getline(infile, line)){
        std::vector<int> row {};
        for(auto& c : line){
            row.push_back(c - '0');
        }

        grid.push_back(row);
    }

    //Account for all the edge trees

    for(int i = 0; i < grid.size(); i++){
        std::vector<int> row = grid[i];
        for(int j = 0; j < row.size(); j++){
            if(i == 0 || i == grid.size() - 1){
                //First row or last row is visible
                trees_visible++;
            }
            else if(j == 0 || j == row.size() - 1){
                trees_visible++;
            }
            else {
                //Calculate if visible or not

                //Assume it is visible until we find a tree blocking it.
                bool lvis = true;
                bool rvis = true;
                bool uvis = true;
                bool dvis = true;

                int value = row[j];
                int decr = j - 1;
                //Left of value. 
                while(decr >= 0){
                    if(row[decr] >= value){
                        lvis = false;
                        break;
                    }

                    decr--;
                }

                //Right of value
                int incr = j + 1;
                while(incr < row.size()){
                    if(row[incr] >= value){
                        rvis = false;
                        break;
                    }
                    incr++;
                }

                //Above value
                int up_incr = i - 1;
                while(up_incr >= 0){
                    if(grid[up_incr][j] >= value){
                        uvis = false;
                        break;
                    }
                    up_incr--;
                }

                int down_incr = i + 1;
                while(down_incr < grid.size()){
                    if(grid[down_incr][j] >= value){
                        dvis = false;
                        break;
                    }
                    down_incr++;
                }

                //Must be completely blocked to not be visible;
                if(lvis || rvis || uvis || dvis){
                    trees_visible++;
                }
            }
        }
    }

    std::cout << trees_visible << std::endl;
}