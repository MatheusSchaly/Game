algoritmo "LM2ex1"
var
i, cont, j, x : inteiro
seno : real
vetorx,vetorf : vetor[1..15] de real
vetorfinal : vetor[1..15] de real   //Com vetor inteiro ta dando integer overflow
inicio
cont <- 0
escreva("Forne�a o valor de x em graus: ")
leia(x)
para i de 1 ate 30 passo 2 faca //valor do seno de x
   cont <- cont + 1
   vetorx[cont] <- x ^ i
fimpara
cont <- 0
para i de 1 ate 30 passo 2 faca //valor do fatorial
   cont <- cont + 1
   vetorf[cont] <- 1
   para j de 1 ate i faca
      vetorf[cont] <- vetorf[cont] * j
   fimpara
fimpara
para i de 1 ate 15 passo 2 faca               //definindo valores positivos
   vetorfinal[i] <- vetorx[i] / vetorf[i]
fimpara
para i de 2 ate 14 passo 2 faca
   vetorfinal[i] <- (vetorx[i]) / (-vetorf[i])  //definindo valores negativos
fimpara
seno <- 0
para i de 1 ate 15 faca
   seno <- seno + vetorfinal[i]
fimpara
escreval("______________________")            //Identa��o
escreval("Valor do seno: ",seno)
fimalgoritmo
