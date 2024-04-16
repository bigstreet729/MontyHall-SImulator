#include<iostream>
#include<random>
#include<cstdlib>
#include<time.h>
#include<vector>

std::vector<int> get_non_revealed_doors(std::vector<int>&doors,int num_doors_opened_by_host,int num_doors,int cardoor){

    // Function that returns the doors which are left after revealing the k doors
    // This code will reveal first non-car doors starting from door 2( door[1]) to door n(door[n-1] )

    std::vector<int> non_revealed;
    int k = num_doors_opened_by_host;
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
        // returning the remaining doors after revealed
        return non_revealed;
}  

void run_simulations(int num_doors, int num_doors_opened_by_host, int iterations){
    
    std::vector<int> doors(num_doors,0); 
    int notswitched = 0; // running count for which nonswitching strategy wins
    int switched = 0;    // running count for which switching strategy wins
    srand(time(0));

    // Simulation loop

    for(int iter = 0; iter<iterations;iter++){

        int cardoor = rand()%num_doors;  
        doors[cardoor] = 1;
        // Host picking random door and assigning car (1) to that door. 

        if(cardoor==0){
            // If the assigned car door is the initial choice of player we can increment count of nonswitching strategy
            notswitched++; 
        }
        else{
           // function to get the doors after host reveals k doors other than car and the intial pick of player 
            std::vector<int>non_revealed = get_non_revealed_doors(doors,num_doors_opened_by_host,num_doors,cardoor);    

            // Player switching random door from remaining n-k-1 non revealed doors
            int switched_door = non_revealed[rand()%non_revealed.size()];

            if(switched_door==cardoor){
                switched++;
                // If the switched door is cardoor we can increment the switched count by one
            }
        }

        doors[cardoor]=0;
        // Resetting the doors to all 0 for next simulation
    }
    
    std::cout<<"Probability  of winning when switched : "<<float(switched)/float(iterations)*100<<"%\n";
    std::cout<<"Probabilty of winning when sticking to inital choice: "<<float(notswitched)/float(iterations)*100<<"%\n";
}

int main(int argc, char *argv[]){

    int num_doors = std::atoi(argv[1]);
    int num_doors_opened_by_host = std::atoi(argv[2]);
    int num_iterations = std::atoi(argv[3]);

    run_simulations(num_doors,num_doors_opened_by_host,num_iterations);

    return 0;

}
