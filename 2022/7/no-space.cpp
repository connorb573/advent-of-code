#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <regex>

class Node {
    public:
    std::shared_ptr<Node> parent;
    std::vector<std::shared_ptr<Node>> children;
    int size; 
    std::string name;
    std::string type;

    Node(std::string name){
        children = std::vector<std::shared_ptr<Node>>();
        size = 0;
        this->name =name;
    }

    Node(Node &n){
        parent = n.parent;
        children = n.children;
        size = n.size;
        name = n.name;
        type = n.type;
    }

    Node(Node &&n){
        parent = n.parent;
        children = n.children;
        size = n.size;
        name = n.name;
        type = n.type;
    }
};

int getTotalSum(std::shared_ptr<Node> node){
    int sum = 0;

    if(node->type == "dir"){
        //Process children first
        for(auto& child : node->children){
            sum += getTotalSum(child);
        }

        if(node->size <= 100000){
            sum+=node->size;
        }
    }

    return sum;
}

int getDirSize(std::shared_ptr<Node> node){
    if(node->children.size() != 0){
        //process children first
        for(auto& child : node->children){
            if(child->type == "dir"){
                node->size += getDirSize(child);
            }
            else {
                node->size += child->size;
            }
        }   
    }
    return node->size;
}

int main() {
    std::ifstream infile("input.txt");

    Node root = Node("/");
    root.type = "dir";
    root.parent = std::make_shared<Node>(root);
    std::shared_ptr<Node> curr = std::make_shared<Node>(root);

    //Skip first line
    std::string line;
    std::getline(infile, line);

    while(std::getline(infile, line)){
        if(line[0] == 'd'){ //Directory
            std::string new_dir = line.substr(4);
            Node new_dir_node = Node(new_dir);
            new_dir_node.type = "dir";
            new_dir_node.parent = curr;
            curr->children.push_back(std::make_shared<Node>(new_dir_node));
        }
        else if(line[0] == '$'){ //Command
           std::string cmd = line.substr(2, 2);
           if(cmd == "cd"){
                std::string new_dir = line.substr(5);
                if(new_dir == ".."){
                    curr = curr->parent;
                }
                else {
                    for(auto& child : curr->children){
                        if(child->name == new_dir){
                            curr = child;
                        }
                    }
                }
           } 
        }else { //File
            std::string value = line.substr(0, line.find(" "));
            std::string name = line.substr(line.find(" ") + 1);

            Node file_node = Node(name);
            file_node.size = stoi(value);
            file_node.type = "file";
            file_node.parent = curr;
            curr->children.push_back(std::make_shared<Node>(file_node));
        }

    }

    //Go back to root.
    do{
        curr = curr->parent;
    }while(curr->name != "/");

    getDirSize(curr);
    int total = getTotalSum(curr);

    std::cout << total <<std::endl;
}