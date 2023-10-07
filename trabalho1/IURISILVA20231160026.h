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

int somar(int x, int y);
int fatorial(int x);

int q1(char data[]);
DiasMesesAnos q2(char datainicial[], char datafinal[]);
int q3(char *texto, char c, int isCaseSensitive);
int q5(int num);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q6(int numerobase, int numerobusca);
DataQuebrada quebraData(char data[]);

#endif // TRABALHO1_IURISILVA20231160026_H