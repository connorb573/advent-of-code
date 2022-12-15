#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

    std::vector<int> scenic_scores;
    //Account for all the edge trees
    for(int i = 0; i < grid.size(); i++){
        std::vector<int> row = grid[i];
        for(int j = 0; j < row.size(); j++){
            if(i == 0 || i == grid.size() - 1){
                //First row or last row is visible
                //Do nothing as scenic score is 0.
            }
            else if(j == 0 || j == row.size() - 1){
                trees_visible++;
                //Do nothing as scenic score is 0
            }
            else {
                //Calculate if visible or not

                //Assume it is visible until we find a tree blocking it.
                bool lvis = true;
                bool rvis = true;
                bool uvis = true;
                bool dvis = true;

                int l_score = 0;
                int r_score = 0;
                int u_score = 0;
                int d_score = 0;

                int value = row[j];
                int decr = j - 1;
                //Left of value. 
                while(decr >= 0){
                    if(row[decr] >= value){
                        l_score++;
                        break;
                    }

                    l_score++;
                    decr--;
                }

                //Right of value
                int incr = j + 1;
                while(incr < row.size()){
                    if(row[incr] >= value){
                        r_score++;
                        break;
                    }

                    r_score++;
                    incr++;
                }

                //Above value
                int up_incr = i - 1;
                while(up_incr >= 0){
                    if(grid[up_incr][j] >= value){
                        u_score++;
                        break;
                    }
                    
                    u_score++;
                    up_incr--;
                }

                int down_incr = i + 1;
                while(down_incr < grid.size()){
                    if(grid[down_incr][j] >= value){
                        d_score++;
                        break;
                    }

                    d_score++;
                    down_incr++;
                }

                int scenic_score = l_score * r_score * d_score * u_score;

                scenic_scores.push_back(scenic_score);
            }
        }
    }

    double max = *max_element(scenic_scores.begin(), scenic_scores.end());

    std::cout << max << std::endl;
}