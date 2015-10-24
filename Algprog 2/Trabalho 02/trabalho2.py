from igraph import *

n=8
arestas=[
[1, 2, 2.2],
[2, 3, 8.79],
[2, 8, 2.34],
[2, 7, 10.2],
[5, 7, 9.6],
[5, 4, 4.33],
[3, 4, 6.66],
[5, 6, 6.66],
[8, 5, 7.0],
[3, 8, 3.14],
[1, 6, 1.0],
[6, 7, 8.1],
[8, 7, 1.25]]

entrada = Graph(n)

for i in arestas:
    entrada.add_edges((i[0]-1,i[1]-1))
    
plot(entrada)


menor=1000
for i in range(len(arestas)):
    if arestas[i][2]<menor:
        menor=arestas[i][2]


print menor
