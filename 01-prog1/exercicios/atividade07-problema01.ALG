Algoritmo "LISTA07Q01"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Walbert Monteiro
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 19/12/2021
Var
// Seção de Declarações das variáveis 
val01:inteiro
contador:inteiro
Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
val01<-0
contador<-0

escreval("Digite um valor entre 0 e 50")
leia(val01)
contador<-val01

se (val01<=50) entao

   enquanto (contador<=1000) faca
     val01 <- val01 mod 2
      se (val01=1) entao
        escreva(contador)
      fimse
   contador <-contador+1
   val01 <- contador
   fimenquanto
senao
   escreva("valor inválido")
fimse






Fimalgoritmo