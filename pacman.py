#Pegando o tamanho da matriz
n = int(input())

#Criando a matriz
matriz = []

#Variáveis utilizadas depois
contador = 0
maior = 0
flag = True

#Inserindo as linhas na matriz
for i in range(n):
    linhas = list(input())
    matriz.append(linhas)

#Variáveis
flag = True #Muda o sentido do pacman
maior = 0 #Salva o máximo de comidas possível
contador = 0 #Contador de comidas

for l in matriz: #Perorre a matriz, indo em cada linha

    if flag == True: #Sentido normal do pacman

        for objeto in l: #Percorre os elementos das linhas

            if objeto == "A": #Se encontrar um fantasma

                if maior < contador: #Salva o número atual de comida no maior
                    maior = contador

                contador = 0 #Zera o contador

            if objeto == "o": #Se encontra uma comida
                contador += 1 #Adiciona no contador

        flag = False #Muda o sentido de percorrimento
    else: #Se o sentido for reverso, vai fazer o mesmo mas começando pelo último elemento

        for j in range(n - 1, -1, -1):
            objeto = l[j]

            if objeto == "A":

                if maior < contador:
                    maior = contador

                contador = 0

            if objeto == "o":
                contador += 1

        flag = True #Inverte o sentido no final

if contador > maior:
    print(contador)
else:
    print(maior)