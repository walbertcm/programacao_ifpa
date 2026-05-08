Algoritmo "LISTA07Q3"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Walbert Monteiro
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Walbert
// Data atual  : 19/12/2021
Var
// Seção de Declarações das variáveis 
contador,nota01,nota02:inteiro
media:real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
contador<-1

enquanto (contador <5) faca

escreva("Digite a nota da AV01 para o aluno ", contador, " :")
leia(nota01)

enquanto nota01>10 faca
  escreva("Digite a nota da AV02 para o aluno ", contador, " :")
  leia(nota01)
fimenquanto

escreva("Digite a nota da Avaliação 02 (0 até 10) :")
leia(nota02)

enquanto nota02>10 faca
  escreva("Digite a nota da Avaliação 02 (0 até 10):")
  leia(nota02)
fimenquanto



  media <- (nota01 + nota02)/2
  escreval("O aluno :", contador, ". Teve a média final de:",media )

contador<-contador + 1
fimenquanto


Fimalgoritmo