import matplotlib.pyplot as plt
import random
from functools import cmp_to_key
import numpy as np

fitnesses=[]
graph=[]
genes=[]
temp=''
n=0
generation=0
initialGene=[]

crossOverRate=90
mutationRate=5

def _input():
    global graph
    global initialGene
    global n

    n=int(input())
    tmp=0
    graph=[] * n
    initialGene=[None] * n

    for i in range(n):
        tmp=[]
        for j in range(n):
            tmp.append(int(input()))
        graph.append(tmp)

    for i in range(n):
        initialGene[i]=int(input())

    # print(graph)
    # print(n)

def fitness(gene):
    global n
    global graph

    score=0
    for i in range(1, n):
        score+=graph[gene[i-1]][gene[i]]     

    return score

def swap(list, pos1, pos2):
    tmp=list[pos1]
    list[pos1]=list[pos2]
    list[pos2]=tmp

def compare(gene1, gene2):
    return gene1[1]<gene2[1]

def crossOver(list1, list2, pos):
    tmp=list1[pos]
    list1[pos]=list2[pos]
    list2[pos]=tmp

def initPopulation(initialGene, ind):
    global genes

    genes.append((initialGene[:], fitness(initialGene), generation))
    for i in range(ind+2, 3):
        swap(initialGene, ind+1, i)
        initPopulation(initialGene[:], i)
        swap(initialGene, ind+1, i)

def sortGenes():
    sorted(genes, key=cmp_to_key(compare))

def goodGenes():
    return min(random.randrange(0, len(genes)), random.randrange(0, len(genes))), min(random.randrange(0, len(genes)), random.randrange(0, len(genes)))

def performCrossover():
    goodIndividuals=goodGenes()
    newGene1=genes[goodIndividuals[0]][0][:]
    newGene2=genes[goodIndividuals[1]][0][:]

    for i in range(1, len(newGene1)):
        if(random.randrange(0, 101)<crossOverRate):
            crossOver(newGene1, newGene2, i)

    return newGene1, newGene2

def mutate(individual):
    for i in range(1, len(individual)):
        if(random.randrange(0, 101)<mutationRate):
            swap(individual, i, random.randrange(1, len(individual)))

def solve():
    ans=[]
    currFitness=0
    prevFitness=0
    count=0
    i=0
    newIndividuals=tuple()
    fitness1=0
    fitness2=0
    childs=[]

    global generation
    global initialGene

    _input()

    # print(graph)

    # print(initialGene)

    initPopulation(initialGene, 0)

    # print(genes)

    while(i<50 and count<10):
        sortGenes()
        generation+=1
        i+=1

        newIndividuals=performCrossover()

        # print(newIndividuals[0])
        # print(newIndividuals[1])

        mutate(newIndividuals[0])
        mutate(newIndividuals[1])

        fitness1=fitness(newIndividuals[0])
        fitness2=fitness(newIndividuals[1])

        if(fitness1<fitness2):
            genes.append((newIndividuals[0], fitness1, generation))
            childs.append([fitness1, generation])
            currFitness=fitness1
            ans=newIndividuals[0]
        else:
            genes.append((newIndividuals[1], fitness2, generation))
            childs.append([fitness2, generation])
            currFitness=fitness2
            ans=newIndividuals[1]
        
        if(currFitness!=prevFitness):
            count=0
            prevFitness=currFitness
        else:
            count+=1

    print('Cung đường ngắn nhất: ')
    print(ans)

    nparray=np.array(childs)
    
    plt.plot(nparray[:, 1], nparray[:, 0])
    plt.xlabel('Generation')
    plt.ylabel('Fitness')

    plt.show()

solve()

input()
