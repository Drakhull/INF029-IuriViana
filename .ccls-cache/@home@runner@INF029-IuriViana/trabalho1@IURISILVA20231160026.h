// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do
//  trabalho

//  ----- Dados do Aluno -----
//  Nome: Iuri Viana Portela Cruz e Silva
//  email: iurii.vianna@gmail.com
//  Matrícula: 20231160026
//  Semestre: 2º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021

// #################################################
#ifndef TRABALHO1_IURISILVA20231160026_H
#define TRABALHO1_IURISILVA20231160026_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DQ {
  int iDia;
  int iMes;
  int iAno;
  int valido; // 0 se inválido, e 1 se válido

} DataQuebrada;

typedef struct Qtd {
  int qtdDias;
  int qtdMeses;
  int qtdAnos;
  int retorno;

} DiasMesesAnos;

int somar(int x, int y) { // função utilizada para testes
  int soma;
  soma = x + y;
  return soma;
}
int fatorial(int x) { // função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}
// Questão 1
int q1(char data[]) {
  int datavalida = 1, i;
  char sDia[3];
  int dia;

  char sMes[3];
  int mes;

  char sAno[5];
  int ano;

  char *dataBckp = data;

  for (i = 0; dataBckp[i] != '/'; i++) {
    sDia[i] = dataBckp[i];
    if (i > 2 || dataBckp[i] == '\0')
      return 0;
  }
  sDia[i] = '\0';
  dataBckp += i + 1;
  dia = atoi(sDia);
  if (dia < 1)
    return 0;

  for (i = 0; dataBckp[i] != '/'; i++) {
    sMes[i] = dataBckp[i];
    if (i > 2 || dataBckp[i] == '\0')
      return 0;
  }
  sMes[i] = '\0';
  dataBckp += i + 1;
  mes = atoi(sMes);
  if (mes < 1 || mes > 12)
    return 0;

  for (i = 0; dataBckp[i] != '/' && dataBckp[i] != '\0'; i++) {
    sAno[i] = dataBckp[i];
    if (i > 4)
      return 0;
  }
  if (i == 2)
    return 0;

  sAno[i] = '\0';
  dataBckp += i + 1;
  ano = atoi(sAno);
  if (i == 1) 
  {
    if (ano >= 0 && ano <= 23) ano += 2000;
    else ano += 1900;
  }
  switch (mes) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:

  case 10:

  case 12:
    if (dia > 31)
      return 0;
    break;

  case 4:
  case 6:
  case 9:
  case 11:
    if (dia > 30)
      return 0;
    break;

  case 2: {
    if ((dia == 29) && (ano % 4 == 0))
      datavalida = 1;
    else if (dia > 28)
      return 0;
  } break;

  default:
    return 0;
    break;
  }
  printf("\n");

  if (datavalida)
    return 1;
  else
    return 0;
}
DiasMesesAnos q2(char datainicial[], char datafinal[]);
int q3(char *texto, char c, int isCaseSensitive);

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros
 (posicoes) que irá guardar as posições de início e fim de cada ocorrência da
 palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída
 correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do
 vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve
 ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a
 segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente.
 Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como
 há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da
 seguinte forma: posicoes[0] = 13; posicoes[1] = 16; Observe que o índice da
 posição no texto deve começar ser contado a partir de 1. O retorno da função,
 n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]) {
  int qtdOcorrencias = 0;
  int p = 0;
  int tamBusca = strlen(strBusca);
  int acentuacao = 0;

  for (int i = 0; strTexto[i] != '\0'; i++) {
    for (int j = 0; strBusca[j] == strTexto[i] && strBusca[j] != '\0' &&
                    strTexto[i] != '\0';
         j++) {
      if ((strTexto[i + 1] > 'z' ||
           (strTexto[i + 1] < 'a' && strTexto[i + 1] > 'Z') ||
           (strTexto[i + 1] < 'A' && strTexto[i + 1] > '9') ||
           strTexto[i + 1] < '0')) {
        acentuacao++;
      }
      if (j == 0) {
        if (acentuacao > 0) {
          posicoes[p] = (i - acentuacao);
        } else
          posicoes[p] = (i + 1);
      } else if (j == tamBusca - 1) {
        p++;

        if (acentuacao > 0) {
          posicoes[p] = (i - acentuacao);
        } else
          posicoes[p] = (i + 1);

        p++;
        qtdOcorrencias++;
      }
      i++;
    }
  }

  for (int i = 0; i < p; i++) {
    printf("posicoes[%d] = %d\n", i, posicoes[i]);
  }

  return qtdOcorrencias;
}
int q5(int num) {
  int numCopy = num, i = 0;
  // verify how many times you can divide by 10
  while (numCopy != 0) {
    numCopy /= 10;
    i++;
  }

  numCopy = 0;
  while (i > 0) {
    numCopy = numCopy + (num % 10);
    num /= 10;
    if (i > 1)
      numCopy *= 10;
    i--;
  }

  num = numCopy;
  printf("RESULTADO %d\n\n", num);
  return num;
}
int q6(int numerobase, int numerobusca);
DataQuebrada quebraData(char data[]);

#endif // TRABALHO1_IURISILVA20231160026_H