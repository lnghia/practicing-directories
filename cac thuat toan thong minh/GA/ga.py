import matplotlib.pyplot as plot

fitnesses=[]
graph=[[]]
genes=[tuple()]
temp=''
n=0
generation=0

def input():
    input(n)
    tmp=0
    graph=[[None] * n] * n
    for i in range(n):
        for j in range(n):
            input(graph[i][j])

def fitness(gene):
    score=0
    for i in range(1, n):
        score+=graph[i-1][i]        
    return score

def swap(list, pos1, pos2):
    tmp=list[pos1]
    list[pos1]=list[pos2]
    list[pos2]=tmp

def crossOver(list1, list2, pos):
    tmp=list1[pos]
    list1[pos]=list2[pos]
    list2[pos]=tmp

def initGenes(initialGene, ind):
    genes.append(tuple(initialGene, fitness(initialGene), generation))
    for i in range(ind+1, n):
        swap(initialGene, ind, i)
        initGenes(initialGene, i)
        swap(initialGene, ind, i)


