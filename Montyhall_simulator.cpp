#include<iostream>
#include<random>
#include<cstdlib>
#include<time.h>
#include<vector>


std::vector<int> get_non_revealed_doors(std::vector<int>&doors,int opened_doors,int num_doors,int cardoor){
    std::vector<int> non_revealed;
    int k = opened_doors;
            for(int i=1;i<num_doors;i++){
                if(k>0){
                    if(i!=cardoor){
                        k--;
                    }
                else{
                    non_revealed.push_back(i);
                }
            }
            else{
                non_revealed.push_back(i);
            }
        }
        return non_revealed;
}  

void run_simulations(int num_doors, int opened_doors, int iterations){
    
    std::vector<int> doors(num_doors,0);
    int notswitched = 0;
    int switched = 0;
    srand(time(0));
    for(int iter = 0; iter<iterations;iter++){   
        int cardoor = rand()%num_doors;
        doors[cardoor] = 1;
        if(cardoor==0){
           
            notswitched++; 
        }
        else{
            std::vector<int>non_revealed = get_non_revealed_doors(doors,opened_doors,num_doors,cardoor);    
            int switched_door = non_revealed[rand()%non_revealed.size()];

            if(switched_door==cardoor){
                switched++;
            }
        }

        doors[cardoor]=0;
    }
    
    std::cout<<"Probability  of winning when switched : "<<float(switched)/float(iterations)*100<<"%\n";
    std::cout<<"Probabilty of winning when sticking to inital choice: "<<float(notswitched)/float(iterations)*100<<"%\n";
}

int main(int argc, char *argv[]){

    int num_doors = std::atoi(argv[1]);
    int opened_doors = std::atoi(argv[2]);
    int num_iterations = std::atoi(argv[3]);

    run_simulations(num_doors,opened_doors,num_iterations);

    return 0;

}