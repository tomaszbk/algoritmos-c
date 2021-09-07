import numpy as np 
import math


vector = [1,2,3,4,5,6,7, 60]
arr = np.array(vector)


def sum(x):
    if x.shape[0] == 1:
        return x[0]
    elif x.shape[0] == 0:
        return 0
    return x[0] + sum(x[1:])


def count(x):
    if x.shape[0] == 0:
        return 0
    return 1 + count(x[1:]) 


def max(x):
    maxi = 0
    for i in range(x.shape[0]):
        if x[i] > maxi:
            maxi = x[i]
    return maxi


def binary_search(valor, lista):
    index = lista.shape[0]
    num_medio = math.floor(index/2)
    if index == 1:
        if lista[0] == valor:
            return index
        if lista[0] != valor:
            return -1
            
    if lista[num_medio] == valor:
        return num_medio
   
    if lista[num_medio] > valor:
        return binary_search(valor, lista[0:num_medio])
        
    if lista[num_medio] < valor:
        return num_medio + binary_search(valor, lista[num_medio:])
        

print(binary_search(60,arr))