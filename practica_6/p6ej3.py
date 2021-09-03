# // Escribir una función recursiva para contar la cantidad de vocales que posee una cadena de 
# // caracteres S.
# //  Ejemplo si S = 'Práctica de Algoritmos’ la función retorna 8

s = "hola como andasaa"
cant = 0
r = 0

def contarvoc(x, i = 0):
    global r
    if x[i] == "a":
        r+=1
    if i != cant -1:
        contarvoc(x, i +1)
    return

cant = len(s)
contarvoc(s)
print(r)