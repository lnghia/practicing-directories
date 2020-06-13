#include <bits/stdc++.h>
#include <stdlib.h>     
#include <time.h>

using namespace std;

vector<vector<int>> graph; 
vector<pair<string, int>> genes;
string temp;

const crossoverRate=90;
const mutationRate=5;

bool compare(const pair<string, int>& a, const pair<string, int>& b){
    return a.second<b.second;
}

void input(){
    int n, tmp;

    cout << "Nhap so thanh pho: ";
    cin >> n;

    graph.resize(n);
    for(auto& row : graph){
        for(int i=0; i<n; ++i){
            cin >> tmp;
            row.push_back(tmp);
        }
    }
}

void swap(char& a, char& b){
    char temp=a;
    a=b;
    b=temp;
}

// Evaluate individual
int fitness(const string& gene){
    int score=0;

    for(int i=1; i<gene.size(); ++i){
        score+=graph[gene[i-1]-'0'][gene[i]-'0'];
    }

    return score;
}

// Population initialize
void initGenes(string& initialPath, int ind){
    genes.push_back({initialPath, fitness(initialPath)});
    for(int i=ind+1; i<initialPath.length(); ++i){
        swap(initialPath[ind], initialPath[i]);
        initGenes(initialPath, i);
        swap(initialPath[ind], initialPath[i]);
    }
}

// Sort genes in ascending order by fitness
void sortGenes(){
    sort(genes.begin(), genes.end(), compare);
}

// Select good individuals for crossover process and mutating (binary selection)
pair<int, int> goodGenes(){
    return {max(rand() % genes.size(), rand() % genes.size()), max(rand() % genes.size(), rand() % genes.size())};
}

// Crossover 2 individuals (binary crossover)
pair<string, string> crossover(){
    pair<int, int> genesIndex=goodGenes();
    string newGene1=genes[genesIndex.first];
    string newGene2=genes[genesIndex.second];

    for(int i=0; i<gene1.length(); ++i){
        if(rand()%101<crossoverRate){
            char tmp=newGene1[i];
            newGene1[i]=genes[genesIndex.first][i];
            newGene2[i]=genes[genesIndex.second][i];
        }
    }

    return {newGene1, newGene2};
}

// Mutate an individual
void mutate(string& individual){
    for(int i=1; i<individual.length(); ++i){
        if(rand()%101<mutationRate){
            swap(individual[i], individual[rand()%individual.length()+1]);
        }
    }
}

int main(){
    srand(time(NULL));

    return 0;
}
