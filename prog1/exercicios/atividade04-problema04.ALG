Algoritmo "Atividae04-Problema04"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Walbert Monteiro
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Walbert
// Data atual  : 29/11/2021
Var
// Seção de Declarações das variáveis 
valor:inteiro
valorAnt:inteiro
valorSuc:inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 

escreval("Digite um numero :")
leia(valor)

//Calculo do antecessor e sucessor
valorAnt <- valor - 1
valorSuc <- valor + 1

escreval("O valor do antecessor é :", valorAnt)
escreval("O valor do sucessor é :", valorSuc)

Fimalgoritmo