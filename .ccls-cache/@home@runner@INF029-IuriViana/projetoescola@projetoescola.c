//  Problemas notados e funcionalidades a implementar

  // 1 - Modularizar mais
  // 2 - Fazer um vetor dentro de uma função e passar para a matriz original somente se tudo der certo (Usar doppelganger no cadastro pessoa)
  // 3 - Opção de voltar é atualizar, voltar tudo é excluir
  // 4 - Implementar opção de voltar após entrar nas opções de inserir
  // 5 - Criar funções para cada operação de verificação?
  // 6 - Excluir espaçamentos após digitar algum nome completo etc
  // 7 - O programa aceita entrada de nome "aBCDEF V"
  // 8 - Confirmação no final perguntando se quer salvar ou não

//  Problemas notados e funcionalidades a implementar;


  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>
  
  #define max 100
  #define n_alunos 6
  #define n_profs 3
  #define n_disci 3
  
  #define cad_a_sucesso -1
  #define cad_invalido -2

// Structs

  typedef struct pessoa
  {
    long int matricula;
    char cpf[12];
    int nascimento_dia;
    char cpf_formatado[15];
    int nascimento_mes;
    char nome[max];
    int nascimento_ano;
    char sexo;
  }  pessoa;

  
  typedef struct disciplina
  {
    char nome[max];
    int semestre;
    char codigo[9];
    pessoa * professor;
    int vagas_a_cad[60];
    int total_de_cad;
  }  disciplina;

// Structs;


// Protótipos;

  int menuPrincipal(int windows);

  int menuAtualizarPessoas(int windows);

  int menuAttDisciplinas(int windows);

  int menuExibicao(int windows);

  void listarPorSexo(int aluno, pessoa pessoasOrdenar[], int cad, int dia_at, int mes_at, int ano_at);

  void listarOrdemABC(int aluno, pessoa pessoasOrdenar[], int cad, int dia_at, int mes_at, int ano_at);

  void listarNascimento(int aluno, pessoa pessoasOrdenar[], int cad, int dia_at, int mes_at, int ano_at);

  void buscarPessoa(pessoa pessoaBuscadaP[], pessoa pessoaBuscadaA[], int a_cad, int p_cad, int dia_at, int mes_at, int ano_at);

  int cadastrar(pessoa pessoa_main[], int a_cad, pessoa pessoa_comp[], int p_cad, int windows, int ano_at, int aluno, int* continuar, int i, int escolha_att);

  int procurarPessoa(int aluno, long int matricula, pessoa pessoaBuscada[], int dia_at, int mes_at, int ano_at, int a_cad);

  void mostrarUmaPessoa(pessoa pessoaBuscada[], int dia_at, int mes_at, int ano_at, int i);

  void exibirPessoa(int aluno, int a_cad);

  int excluirPessoa(pessoa alvoExclusao[], int posicaoVetor, int a_cad);

  int excluirDisciplina(disciplina alvoExclusao[], int posicaoVetor, int d_cad);

  int calcularIdade(int ano_pessoa, int mes_pessoa, int dia_pessoa, int dia_at, int mes_at, int ano_at);

  void aniversarianteDia(int windows, pessoa aniversarianteA[], pessoa aniversarianteP[], int a_cad, int p_cad, int dia_at, int mes_at, int ano_at);

  void aniversariantesMes(int windows, pessoa aniversarianteA[], pessoa aniversarianteP[], int a_cad, int p_cad, int dia_at, int mes_at, int ano_at);

  int compararDatas(pessoa pessoa1, pessoa pessoa2); 
  
  int menuAlunos(int windows);

  void exibirAlunos(pessoa alunos[], int a_cad, int ano_at, int mes_at, int dia_at);
  
  int menuProfessores(int windows);
  
  void exibirProfessores(pessoa professores[], int p_cad, int ano_at, int mes_at, int dia_at);
  
  int menuDisciplinas(int windows);
  
  int cadastrarDisciplina(disciplina disciplinas[], int d_cad, pessoa professores[], int p_cad, int windows, int *continuar, int i, int escolha_att);
  
  void exibirDisciplinas(disciplina disciplinas[], int d_cad, int windows);

  int procurarDisciplina(disciplina disciplinaBuscada[], char codigo[], int d_cad);
  
  void limparTela(int windows);
  
  void limparBuffer();
  
  void delay(long int secs);
  
  void pressEnter();

  void fixQuebraLinhaFgets(char alvo[]);

// Protótipos;
  
  // DEFINIR SISTEMA

    int windows = 0;

  // DEFINIR SISTEMA;


  // Variavéis tipo pessoa e disciplina

    pessoa alunos[n_alunos];
    pessoa professores[n_profs];
    disciplina disciplinas[n_disci];

  // Variavéis tipo pessoa e disciplina;

  int main (void)
  {
    // Data/hora

      struct tm *data_hora_atual;
  
      time_t segundos;
  
      time(&segundos);
  
      data_hora_atual = localtime(&segundos);
  
      int ano_at = data_hora_atual -> tm_year + 1900;
      int mes_at = data_hora_atual -> tm_mon + 1;
      int dia_at = data_hora_atual -> tm_mday;
  
    // Data/hora;

    int a_cad = 5, p_cad = 2, d_cad = 2;
    int escolha = -1;
    int aluno = -1;
    int opcao = 0;
    int continuar;
  
    // TESTES
    
        // Alunos 
            // Aluno 1
            strcpy(alunos[0].cpf, "12345678912");
            strcpy(alunos[0].cpf_formatado, "xxx.xxx.xxx-xx");
            alunos[0].matricula = 213546788; 
            strcpy(alunos[0].nome, "Pedro Albuquerque");
            alunos[0].nascimento_dia = 22;
            alunos[0].nascimento_mes = 8;
            alunos[0].nascimento_ano = 1999;
            alunos[0].sexo = 'M';
  
            // Aluno 2
            strcpy(alunos[1].cpf_formatado, "xxx.xxx.xxx-xx");
            alunos[1].matricula = 363546789;
            strcpy(alunos[1].nome, "Pedro Pascal");
            alunos[1].nascimento_dia = 22;
            alunos[1].nascimento_mes = 8;
            alunos[1].nascimento_ano = 2002;
            alunos[1].sexo = 'M';

            // Aluno 3
            strcpy(alunos[2].cpf, "12345678912");
            strcpy(alunos[2].cpf_formatado, "xxx.xxx.xxx-xx");
            alunos[2].matricula = 213546781; 
            strcpy(alunos[2].nome, "Iuri VIana");
            alunos[2].nascimento_dia = 22;
            alunos[2].nascimento_mes = 8;
            alunos[2].nascimento_ano = 1950;
            alunos[2].sexo = 'F';

            // Aluno 4
            strcpy(alunos[3].cpf, "12345678912");
            strcpy(alunos[3].cpf_formatado, "xxx.xxx.xxx-xx");
            alunos[3].matricula = 213546782; 
            strcpy(alunos[3].nome, "Jusde Edfs Quarta");
            alunos[3].nascimento_dia = 22;
            alunos[3].nascimento_mes = 8;
            alunos[3].nascimento_ano = 2015;
            alunos[3].sexo = 'F';

            // Aluno 5
            strcpy(alunos[4].cpf, "12345678912");
            strcpy(alunos[4].cpf_formatado, "xxx.xxx.xxx-xx");
            alunos[4].matricula = 213546789; 
            strcpy(alunos[4].nome, "Jusde Edfs Primeira");
            alunos[4].nascimento_dia = 22;
            alunos[4].nascimento_mes = 8;
            alunos[4].nascimento_ano = 2003;
            alunos[4].sexo = 'F';

  
        // Professores
            // Professor 1
            strcpy(professores[0].cpf, "92345678911");
            strcpy(professores[0].cpf_formatado, "xxx.xxx.xxx-xx");
            professores[0].matricula = 373546789;
            strcpy(professores[0].nome, "Professor Prof");
            professores[0].nascimento_dia = 22;
            professores[0].nascimento_mes = 8;
            professores[0].nascimento_ano = 1985;
            professores[0].sexo = 'M';
  
            // Professor 2
            strcpy(professores[1].cpf_formatado, "xxx.xxx.xxx-xx");
            professores[1].matricula = 835467893;
            strcpy(professores[1].nome, "Prof Proof");
            professores[1].nascimento_dia = 29;
            professores[1].nascimento_mes = 12;
            professores[1].nascimento_ano = 1961;
            professores[1].sexo = 'F';
  
        // Disciplinas
            // Disciplina 1
            strcpy(disciplinas[0].nome, "Matematica");
            disciplinas[0].professor = &professores[0];
            strncpy(disciplinas[0].codigo, "matpoenb", sizeof(disciplinas[0].codigo) - 1);
            disciplinas[0].semestre = 1;
            
            // Disciplina 2
            strcpy(disciplinas[1].nome, "Programacao");
            disciplinas[1].professor = &professores[1];
            strncpy(disciplinas[1].codigo, "logpoenb", sizeof(disciplinas[1].codigo) - 1);
            disciplinas[1].semestre = 1;
    
    // TESTES;
    
      limparTela(windows);
      int sair = 0;

    // Programa Principal (Switch Case)
      while (!sair)
      {
          printf("Menu Principal\n");
          escolha = menuPrincipal(windows);
  
          limparTela(windows);
  
          switch (escolha) 
          {
              case 0:
              {
                  printf("Programa finalizado.\n");
                  sair = 1;
              }
              break;
    
              case 1:
              {
                  int sairAluno = 0;
                  int escolha_aluno;
  
                  limparTela(windows);
                  
                  while(!sairAluno)
                  {
                      printf("Modulo de Alunos\n");
                      escolha_aluno = menuAlunos(windows);
                      aluno = 1;
  
                      switch(escolha_aluno)
                      {
                          case 0:
                          {
                              sairAluno = 1;
                              limparTela(windows);
                          }
                          break;
                          
                          case 1:
                          {
                            limparTela(windows);
                            continuar = 1;
                            int i = a_cad;

                            while (i < n_alunos && continuar && a_cad < n_alunos)
                            {
                                limparTela(windows);
                                a_cad = cadastrar(alunos, a_cad, professores, p_cad, windows, ano_at, aluno, &continuar, i, opcao);
                                i = a_cad;
                            }
                            
                            if (a_cad >= n_alunos && continuar)
                            {
                                int contagem_reg = 3;
                                while (contagem_reg > 0) 
                                {
                                    limparTela(windows);
                                    printf("Limite de cadastros atingido! Voltando em %d...", contagem_reg);
                                    delay(1);
                                    limparTela(windows);
                                    contagem_reg--;
                                }
                            }
                          }
                          break;
  
                          case 2:
                          {
                            limparTela(windows);
                            long int matricula = 0;

                            while (1)
                            {   
                                char exibir;
                                printf("Deseja exibir os alunos? S/N: ");
                                while (scanf("%c", &exibir) != 1)
                                {
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                                }
                                if (exibir == 's' || exibir == 'S')
                                {
                                    aluno = 1;
                                    exibirAlunos(alunos, a_cad, ano_at, mes_at, dia_at);
                                    break;
                                }
                                else if (exibir == 'n' || exibir == 'N')
                                {
                                    break;
                                }
                                else 
                                {
                                    printf("Opcao Invalida! Tente novamente:");
                                    limparTela(windows);
                                }
                            }

                            printf("Digite a Matricula do Aluno que Deseja Atualizar: ");
                            while (scanf("%ld", &matricula) != 1)
                            {
                              printf("Erro.");
                              limparBuffer();
                              printf("\nTente Novamente: ");
                            }
                            // scanf("%ld", &matricula);
                            limparBuffer();

                            int retorno;
                            int tentarNovamente = 1;
                            
                            retorno = procurarPessoa(aluno, matricula, alunos, dia_at, mes_at, ano_at, a_cad);

                            while (retorno == -2)
                            {
                                limparTela(windows);
                                printf("Aluno nao existe\n\n");
                                printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                while (scanf("%d", &tentarNovamente) != 1)
                                {
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                                }
                              
                                while (tentarNovamente != 1 && tentarNovamente != 0)
                                {
                                    printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                    while (scanf("%d", &tentarNovamente) != 1)
                                    {
                                      printf("Erro.");
                                      limparBuffer();
                                      printf("\nTente Novamente: ");
                                    }
                                }
                                
                                if (tentarNovamente)
                                {
                                    limparTela(windows);
                                    printf("Digite a Matricula do Aluno que Deseja Atualizar: ");
                                    while (scanf("%ld", &matricula) != 1)
                                    {
                                      printf("Erro.");
                                      limparBuffer();
                                      printf("\nTente Novamente: ");
                                    }
                                    retorno = procurarPessoa(aluno, matricula, alunos, dia_at, mes_at, ano_at, a_cad);
                                }
                                else if (!tentarNovamente)
                                {
                                    break;
                                }
                            }
                            if (retorno == -1)
                            {
                                limparTela(windows);
                                break;
                            }

                                int sairAtualizar = 0;
                                int escolha_att;
                                while (!sairAtualizar && retorno != -2 && retorno != -1)
                                {
                                    limparTela(windows);
                                    printf("Menu de Atualizar\n");
                                    escolha_att = menuAtualizarPessoas(windows);
                                    switch (escolha_att)
                                        {
                                        case 0:
                                            sairAtualizar = 1;
                                            limparTela(windows);
                                            break;

                                        case 1:
                                            limparTela(windows);
                                            continuar = 1;

                                            cadastrar(alunos, a_cad, professores, p_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;
                                        
                                        case 2:
                                            limparTela(windows);
                                            continuar = 1;

                                            cadastrar(alunos, a_cad, professores, p_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;

                                        case 3:
                                            limparTela(windows);
                                            continuar = 1;
                                            
                                            cadastrar(alunos, a_cad, professores, p_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;

                                        case 4:
                                            limparTela(windows);
                                            continuar = 1;
                                            
                                            cadastrar(alunos, a_cad, professores, p_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;

                                        case 5:
                                            limparTela(windows);
                                            continuar = 1;
                                            
                                            cadastrar(alunos, a_cad, professores, p_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;
                                        
                                        default:
                                            break;
                                        }
                                }
                            
                              
                            limparTela(windows);
                          }
                          break;
  
                          case 3:
                          {
                            int sair_e_aluno = 0;
                            int escolha_e_aluno;
                            while (!sair_e_aluno)
                            {
                                limparTela(windows);
                                printf("Exibicao Alunos\n");
                                escolha_e_aluno = menuExibicao(windows);
                                switch (escolha_e_aluno)
                                {
                                    case 0:
                                    {
                                        sair_e_aluno = 1;
                                        limparTela(windows);
                                    }
                                        break;

                                    case 1:
                                    {
                                        limparTela(windows);

                                        exibirAlunos(alunos, a_cad, ano_at, mes_at, dia_at);

                                        limparTela(windows);
                                    }
                                        break;
                                        
                                    case 2:
                                    {
                                        
                                    }
                                        break;
                                        
                                    case 3:
                                    {
                                        limparTela(windows);

                                        listarPorSexo(aluno, alunos, a_cad, dia_at, mes_at, ano_at);

                                        limparTela(windows);
                                    }  
                                        break;
                                    
                                    case 4:
                                    {
                                        limparTela(windows);

                                        listarOrdemABC(aluno, alunos, a_cad, dia_at, mes_at, ano_at);

                                        limparTela(windows);
                                    }
                                        break;

                                    case 5:
                                    {
                                        limparTela(windows);

                                        listarNascimento(aluno, alunos, a_cad, dia_at, mes_at, ano_at);

                                        limparTela(windows);
                                    }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            
                            
                            limparTela(windows);

                          }
                          break;
                          
                          case 4:
                          {
                            limparTela(windows);
                            long int matricula = 0;

                            while (1)
                            {
                                char exibir;
                                printf("Deseja exibir os alunos? S/N: ");
                                while (scanf("%c", &exibir) != 1)
                                {
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                                }
                                if (exibir == 's' || exibir == 'S')
                                {
                                    exibirAlunos(alunos, a_cad, ano_at, mes_at, dia_at);
                                    break;
                                }
                                else if (exibir == 'n' || exibir == 'N')
                                {
                                    break;
                                }
                                else 
                                {
                                    printf("Opcao Invalida! Tente novamente:");
                                    limparTela(windows);
                                }
                            }

                            printf("\n\nDigite a Matricula do Aluno que Deseja Excluir: ");
                            while (scanf("%ld", &matricula) != 1)
                            {
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                            }
                            limparBuffer();

                            int retorno;
                            int tentarNovamente = 1;
                            
                            retorno = procurarPessoa(aluno, matricula, alunos, dia_at, mes_at, ano_at, a_cad);

                            while (retorno == -2)
                            {
                                limparTela(windows);
                                printf("Aluno nao existe\n\n");
                                printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                while (scanf("%d", &tentarNovamente) != 1)
                                {
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                                }
                                while (tentarNovamente != 1 && tentarNovamente != 0)
                                {
                                    printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                    while (scanf("%d", &tentarNovamente) != 1)
                                    {
                                        printf("Erro.");
                                        limparBuffer();
                                        printf("\nTente Novamente: ");
                                    }
                                }
                                
                                if (tentarNovamente)
                                {
                                    limparTela(windows);
                                    printf("Digite a Matricula do Aluno que Deseja Excluir: ");
                                    while (scanf("%d", &tentarNovamente) != 1)
                                    {
                                      printf("Erro.");
                                      limparBuffer();
                                      printf("\nTente Novamente: ");
                                    }
                                    retorno = procurarPessoa(aluno, matricula, alunos, dia_at, mes_at, ano_at, a_cad);
                                }
                                else if (!tentarNovamente)
                                {
                                    break;
                                }
                            }
                            if (retorno == -1)
                            {
                                limparTela(windows);
                                break;
                            }
                              limparTela(windows);
                            
                              a_cad = excluirPessoa(alunos, retorno, a_cad);

                              limparTela(windows);
                          }
                          break;
  
                          default:
                          {
                              limparTela(windows);
                          }
                          break;
                      }
                  }
              limparTela(windows);
              }
              break;


            
    
              case 2:
              {
                  int sairProf = 0;
                  int escolha_prof;
                  int aluno = 0;
  
                  limparTela(windows);
                  
                  while (!sairProf)
                  {
                      printf("Modulo de Professores\n");
                      escolha_prof = menuProfessores(windows);
  
                      switch(escolha_prof)
                      {
                          case 0:
                          {
                              sairProf = 1;
                              limparTela(windows);
                          }
                          break;
                          
                          case 1:
                          {
                            limparTela(windows);

                            int continuar = 1;
                            int i = p_cad;

                            while (i < n_profs && continuar && p_cad < n_profs)
                            {
                                limparTela(windows);
                                p_cad = cadastrar(professores, p_cad, alunos, a_cad, windows, ano_at, aluno, &continuar, i, opcao);
                                i = p_cad;
                            }
                            
                            if (p_cad >= n_profs && continuar)
                            {
                                int contagem_reg = 3;
                                while (contagem_reg > 0) 
                                {
                                    limparTela(windows);
                                    printf("Limite de cadastros atingido! Voltando em %d...", contagem_reg);
                                    delay(1);
                                    limparTela(windows);
                                    contagem_reg--;
                                }
                            }
                          }
                          break;
  
                          case 2:
                          {
                            limparTela(windows);
                            long int matricula = 0;

                            while (1)
                            {   
                                char exibir;
                                printf("Deseja exibir os professores? S/N: ");
                                while (scanf("%c", &exibir) != 1)
                                {
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                                }
                                if (exibir == 's' || exibir == 'S')
                                {
                                    aluno = 0;
                                    exibirProfessores(professores, p_cad, ano_at, mes_at, dia_at);
                                    break;
                                }
                                else if (exibir == 'n' || exibir == 'N')
                                {
                                    break;
                                }
                                else 
                                {
                                    printf("Opcao Invalida! Tente novamente:");
                                    limparTela(windows);
                                }
                            }

                            printf("\n\nDigite a Matricula do Professor que Deseja Atualizar: ");
                            while (scanf("%ld", &matricula) != 1)
                            {
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                            }
                            limparBuffer();

                            int retorno;
                            int tentarNovamente = 1;
                            
                            retorno = procurarPessoa(aluno, matricula, professores, dia_at, mes_at, ano_at, p_cad);

                            while (retorno == -2)
                            {
                                limparTela(windows);
                                printf("Professor nao existe\n\n");
                                printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                while (scanf("%d", &tentarNovamente) != 1)
                                {
                                  
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                                }
                                while (tentarNovamente != 1 && tentarNovamente != 0)
                                {
                                    printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                    while (scanf("%d", &tentarNovamente) != 1)
                                    {
                                        printf("Erro.");
                                        limparBuffer();
                                        printf("\nTente Novamente: ");
                                    }
                                }
                                
                                if (tentarNovamente)
                                {
                                    limparTela(windows);
                                    printf("Digite a Matricula do Professor que Deseja Atualizar: ");
                                    while (scanf("%ld", &matricula) != 1)
                                    {
                                      
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                                    }
                                    retorno = procurarPessoa(aluno, matricula, professores, dia_at, mes_at, ano_at, p_cad);
                                }
                                else if (!tentarNovamente)
                                {
                                    break;
                                }
                            }
                            if (retorno == -1)
                            {
                                limparTela(windows);
                                break;
                            }

                                int sairAtualizar = 0;
                                int escolha_att;
                                while (!sairAtualizar && retorno != -2 && retorno != -1)
                                {
                                    limparTela(windows);
                                    printf("Menu de Atualizar\n");
                                    escolha_att = menuAtualizarPessoas(windows);
                                    switch (escolha_att)
                                        {
                                        case 0:
                                            sairAtualizar = 1;
                                            limparTela(windows);
                                            break;

                                        case 1:
                                            limparTela(windows);
                                            continuar = 1;

                                            cadastrar(professores, p_cad, alunos, a_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;
                                        
                                        case 2:
                                            limparTela(windows);
                                            continuar = 1;

                                            cadastrar(professores, p_cad, alunos, a_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;

                                        case 3:
                                            limparTela(windows);
                                            continuar = 1;

                                            cadastrar(professores, p_cad, alunos, a_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;

                                        case 4:
                                            limparTela(windows);
                                            continuar = 1;

                                            cadastrar(professores, p_cad, alunos, a_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;

                                        case 5:
                                            limparTela(windows);
                                            continuar = 1;

                                            cadastrar(professores, p_cad, alunos, a_cad, windows, ano_at, aluno, &continuar, retorno, escolha_att);
                                            break;
                                        
                                        default:
                                            break;
                                        }
                                }
                            
                              
                            limparTela(windows);
                          }
                          break;
  
                          case 3:
                          {
                            int sair_e_prof = 0;
                            int escolha_e_prof;
                            while (!sair_e_prof)
                            {
                                limparTela(windows);
                                printf("Exibicao Professores\n");
                                escolha_e_prof = menuExibicao(windows);
                                switch (escolha_e_prof)
                                {
                                    case 0:
                                    {
                                        sair_e_prof = 1;
                                        limparTela(windows);
                                    }
                                        break;

                                    case 1:
                                    {
                                        limparTela(windows);

                                        exibirProfessores(professores, p_cad, ano_at, mes_at, dia_at);

                                        limparTela(windows);
                                    }
                                        break;
                                        
                                    case 2:
                                    {
                                        limparTela(windows);

                                        buscarPessoa(professores, alunos, a_cad, p_cad, dia_at, mes_at, ano_at);

                                        limparTela(windows);
                                    }
                                        break;
                                        
                                    case 3:
                                    {
                                        limparTela(windows);

                                        listarPorSexo(aluno, professores, p_cad, dia_at, mes_at, ano_at);

                                        limparTela(windows);
                                    }  
                                        break;
                                    
                                    case 4:
                                    {
                                        limparTela(windows);

                                        listarOrdemABC(aluno, professores, p_cad, dia_at, mes_at, ano_at);

                                        limparTela(windows);
                                    }
                                        break;

                                    case 5:
                                    {
                                        limparTela(windows);

                                        listarNascimento(aluno, professores, p_cad, dia_at, mes_at, ano_at);

                                        limparTela(windows);
                                    }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            limparTela(windows);
                          }
                          break;
                          
                          case 4:
                          {
                            limparTela(windows);
                            aluno = 0;
                            long int matricula = 0;

                            while (1)
                            {   
                                char exibir;
                                printf("Deseja exibir os professores? S/N: ");
                                while (scanf("%c", &exibir) != 1)
                                {
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                                }
                                if (exibir == 's' || exibir == 'S')
                                {
                                    aluno = 0;
                                    exibirProfessores(professores, p_cad, ano_at, mes_at, dia_at);
                                    break;
                                }
                                else if (exibir == 'n' || exibir == 'N')
                                {
                                    break;
                                }
                                else 
                                {
                                    printf("Opcao Invalida! Tente novamente:");
                                    limparTela(windows);
                                }
                            }

                            printf("Digite a Matricula do Professor que Deseja Excluir: ");
                            while (scanf("%ld", &matricula) != 1)
                            {
                              
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                            }
                            limparBuffer();

                            int retorno;
                            int tentarNovamente = 1;
                            
                            retorno = procurarPessoa(aluno, matricula, professores, dia_at, mes_at, ano_at, p_cad);

                            while (retorno == -2)
                            {
                                limparTela(windows);
                                printf("Professor nao existe\n\n");
                                printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                while (scanf("%d", &tentarNovamente) != 1)
                                {
                                  
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                                }
                                while (tentarNovamente != 1 && tentarNovamente != 0)
                                {
                                    printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                    while (scanf("%d", &tentarNovamente) != 1)
                                    {
                                      
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                                    }
                                }
                                
                                if (tentarNovamente)
                                {
                                    limparTela(windows);
                                    printf("Digite a Matricula do Professor que Deseja Excluir: ");
                                    while (scanf("%ld", &matricula) != 1)
                                    {
                                      
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                                    }
                                    retorno = procurarPessoa(aluno, matricula, professores, dia_at, mes_at, ano_at, p_cad);
                                }
                                else if (!tentarNovamente)
                                {
                                    break;
                                }
                            }
                            if (retorno == -1)
                            {
                                limparTela(windows);
                                break;
                            }
                              limparTela(windows);

                              p_cad = excluirPessoa(professores, retorno, p_cad);

                              limparTela(windows);
                          }
                          break;
  
                          default:
                          {
                              limparTela(windows);
                          }
                          break;
                      }
                  }
                  limparTela(windows);
              }
              break;
    
              case 3:
              {
                  int sairDisci = 0;
                  int escolha_disci;
  
                  limparTela(windows);
                  
                  while (!sairDisci)
                  {
                      printf("Modulo de Disciplinas\n");
                      escolha_disci = menuDisciplinas(windows);
  
                      switch(escolha_disci)
                      {
                          case 0:
                          {
                            sairDisci = 1;
                            limparTela(windows);
                          }
                          break;
                          
                          case 1:
                          {
                            limparTela(windows);

                            int continuar = 1;
                            int i = d_cad;
                            int escolha_att = 0;

                            while (i < n_disci && continuar && d_cad < n_disci)
                            {
                                limparTela(windows);
                                d_cad = cadastrarDisciplina(disciplinas, d_cad, professores, p_cad, windows, &continuar, i, escolha_att);
                                i = d_cad;
                            }
                            
                            if (d_cad >= n_disci && continuar)
                            {
                                int contagem_reg = 3;
                                while (contagem_reg > 0) 
                                {
                                    limparTela(windows);
                                    printf("Limite de cadastros atingido! Voltando em %d...", contagem_reg);
                                    delay(1);
                                    limparTela(windows);
                                    contagem_reg--;
                                }
                            }
                          }
                          break;
  
                          case 2:
                          {
                            limparTela(windows);
                            while (1)
                            {   
                                char exibir;
                                printf("Deseja exibir as disciplinas? S/N: ");
                                while (scanf("%c", &exibir) != 1)
                                {
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                                }
                                limparBuffer();
                                if (exibir == 's' || exibir == 'S')
                                {
                                    exibirDisciplinas(disciplinas, d_cad, windows);
                                    break;
                                }
                                else if (exibir == 'n' || exibir == 'N')
                                {
                                    break;
                                }
                                else 
                                {
                                    printf("Opcao Invalida! Tente novamente:");
                                    limparTela(windows);
                                }
                            }
                            
                            char disciplina_codigo[10];
                            limparBuffer();
                            printf("\nInsira o Codigo da Disciplina que Deseja Atualizar: ");
                            while (fgets(disciplina_codigo, 10, stdin) == NULL) 
                            {
                                printf("\nAlgo deu errado ao digitar.");
                                printf("\nTente novamente: ");
                                limparBuffer();
                            }
                            fixQuebraLinhaFgets(disciplina_codigo);
                            
                            

                            int retorno;
                            int tentarNovamente = 1;
                            
                            retorno = procurarDisciplina(disciplinas, disciplina_codigo, d_cad);

                            while (retorno == -1)
                            {
                                limparTela(windows);
                                limparBuffer();
                                printf("Disciplina nao existe\n\n");
                                printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                while (scanf("%d", &tentarNovamente) != 1)
                                {
                                    printf("\nErro.");
                                    limparBuffer();
                                    printf("\nTente Novamente: ");
                                }
                                while (tentarNovamente != 1 && tentarNovamente != 0)
                                {
                                    printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                    while (scanf("%d", &tentarNovamente) != 1)
                                    {
                                        printf("\nErro.");
                                        limparBuffer();
                                        printf("\nTente Novamente: ");
                                    }
                                }
                                
                                if (tentarNovamente)
                                {
                                    limparTela(windows);
                                    printf("\nInsira o Codigo da Disciplina que Deseja Atualizar: ");
                                    while (fgets(disciplina_codigo, 10, stdin) == NULL) 
                                    {
                                        printf("\nAlgo deu errado ao digitar.");
                                        printf("\nTente novamente: ");
                                    }
                                    retorno = procurarDisciplina(disciplinas, disciplina_codigo, d_cad);
                                }
                                else if (!tentarNovamente)
                                {
                                    break;
                                }
                            }


                            int sairAttDisci = 0;
                            while (!sairAttDisci && retorno != -2 && retorno != -1)
                            {   
                                limparTela(windows);
                                int escolha_att;
                                printf("Menu de Atualizar\n");
                                escolha_att = menuAttDisciplinas(windows);

                                switch (escolha_att)
                                {
                                case 0:
                                    sairAttDisci = 1;
                                    limparTela(windows);

                                    break;

                                case 1:
                                    limparTela(windows);
                                    continuar = 1;

                                    cadastrarDisciplina(disciplinas, d_cad, professores, p_cad, windows, &continuar, retorno, escolha_att);
                                    break;
                                    
                                case 2:
                                    limparTela(windows);
                                    continuar = 1;

                                    cadastrarDisciplina(disciplinas, d_cad, professores, p_cad, windows, &continuar, retorno, escolha_att);
                                    
                                    break;
                                    
                                case 3:
                                    limparTela(windows);
                                    continuar = 1;

                                    cadastrarDisciplina(disciplinas, d_cad, professores, p_cad, windows, &continuar, retorno, escolha_att);
                                    
                                    break;
                                    
                                case 4:
                                    limparTela(windows);
                                    continuar = 1;

                                    cadastrarDisciplina(disciplinas, d_cad, professores, p_cad, windows, &continuar, retorno, escolha_att);
                                    
                                    break;
                                
                                default:
                                    break;
                                }
                            }
                            
                            


                            
                            limparTela(windows);
                          }
                          break;
  
                          case 3:
                          {
                              limparTela(windows);
                              
                              exibirDisciplinas(disciplinas, d_cad, windows);

                              limparTela(windows);
                          }
                          break;
                          
                          case 4:
                          {
                            limparTela(windows);
                            while (1)
                            {   
                                char exibir;
                                printf("Deseja exibir as disciplinas? S/N: ");
                                while (scanf("%c", &exibir) != 1)
                                {
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                                }
                                limparBuffer();
                                if (exibir == 's' || exibir == 'S')
                                {
                                    exibirDisciplinas(disciplinas, d_cad, windows);
                                    break;
                                }
                                else if (exibir == 'n' || exibir == 'N')
                                {
                                    break;
                                }
                                else 
                                {
                                    printf("Opcao Invalida! Tente novamente:");
                                    limparTela(windows);
                                }
                            }
                            
                            char disciplina_codigo[10];
                            limparBuffer();
                            printf("\nInsira o Codigo da Disciplina que Deseja Excluir: ");
                            while (fgets(disciplina_codigo, 10, stdin) == NULL) 
                            {
                                printf("\nAlgo deu errado ao digitar.");
                                printf("\nTente novamente: ");
                                limparBuffer();
                            }
                            fixQuebraLinhaFgets(disciplina_codigo);
                            
                            int retorno;
                            int tentarNovamente = 1;
                            
                            retorno = procurarDisciplina(disciplinas, disciplina_codigo, d_cad);

                            while (retorno == -1)
                            {
                                limparTela(windows);
                                limparBuffer();
                                printf("Disciplina nao existe\n\n");
                                printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                while (scanf("%d", &tentarNovamente) != 1)
                                {
                                    printf("\nErro.");
                                    limparBuffer();
                                    printf("\nTente Novamente: ");
                                }
                                while (tentarNovamente != 1 && tentarNovamente != 0)
                                {
                                    printf("Tente novamente pressionando 1 ou pressione 0 para voltar: ");
                                    while (scanf("%d", &tentarNovamente) != 1)
                                    {
                                        printf("\nErro.");
                                        limparBuffer();
                                        printf("\nTente Novamente: ");
                                    }
                                }
                                
                                if (tentarNovamente)
                                {
                                    limparTela(windows);
                                    printf("\nInsira o Codigo da Disciplina que Deseja Excluir: ");
                                    while (fgets(disciplina_codigo, 10, stdin) == NULL) 
                                    {
                                        printf("\nAlgo deu errado ao digitar.");
                                        printf("\nTente novamente: ");
                                    }
                                    retorno = procurarDisciplina(disciplinas, disciplina_codigo, d_cad);
                                    
                                    limparBuffer();
                                    
                                    limparTela(windows);
                                    
                                  	
								}
								else if (!tentarNovamente)
                                {
                                	limparTela(windows);
                                	break;
								}
                                    
                                    limparTela(windows);
                            }
                                
                            if (!tentarNovamente)
                                {
                                	limparTela(windows);
                                	break;
								}
                            
                            
                                
                            
                            if (retorno != -1)
                            {          
                                      limparTela(windows);
	                                    printf("--------------Disciplina %d--------------", retorno+1);
	                          
	                                    printf("\n\nNome: %s", disciplinas[retorno].nome);
	                                    
	                                    printf("\n\nCodigo: %s", disciplinas[retorno].codigo);
	                          
	                                    printf("\n\nProfessor: %s", disciplinas[retorno].professor->nome);
	                            
	                                    printf("\n\nSemestre: %d", disciplinas[retorno].semestre);
	                          
	                                    printf("\n\n");
	                                    
	                                    limparBuffer();
	                                    printf("Deseja continuar? (S/N): ");
	                                    
	                                    char SeN;
	                                    while (scanf("%c", &SeN) != 1) 
	                                    {
	                                        printf("\nAlgo deu errado ao digitar.");
	                                        printf("\nTente novamente: ");
	                                    }
	                                     if (SeN == 'n'|| SeN == 'N')
		                                {
		                                	   limparTela(windows);
                                          limparBuffer();
                                          printf("Operacao cancelada.\n\n");
                                          pressEnter();
                                        limparTela(windows);
		                                    break;
		                                }
		                                else if (SeN == 's'|| SeN == 'S')
		                                {
			                                limparTela(windows);
			                                limparBuffer();
	                            			char nome[100];
	                            			strcpy(nome, disciplinas[retorno].nome);
	                            			printf("Disciplina %s excluida com sucesso!", nome);
	                            			pressEnter();
	                            			d_cad = excluirDisciplina(disciplinas, retorno, d_cad);
	                            			
	                            			
										}
                            }
                            
                            limparTela(windows);
                          }
                          break;
  
                          default:
                          {
                              limparTela(windows);
                          }
                          break;
                      }
                  }
                  limparTela(windows);
              }
              break;
    
              case 4:
              {
                limparTela(windows);

                aniversarianteDia(windows, alunos, professores, a_cad, p_cad, dia_at, mes_at, ano_at);

                limparTela(windows);
              }
              break;
    
              case 5:
              {
                limparTela(windows);

                aniversariantesMes(windows, alunos, professores, a_cad, p_cad, dia_at, mes_at, ano_at);

                limparTela(windows);
              }
              break;
    
              case 6:
              {
              
                limparTela(windows);

                buscarPessoa(professores, alunos, a_cad, p_cad, dia_at, mes_at, ano_at);

                limparTela(windows);
              }
              break;
      
              default:
                  break;
          }
      }
    
    // Programa Principal (Switch Case);
    
      return 0;
  }
  
// MENUS

void errorMsg(int windows)
{
    limparTela(windows);
    printf("Entrada Invalida!");
    pressEnter();
}

  int menuPrincipal(int windows)
  {
      int escolha = -1;
      printf("======================\n\n");
      printf("|0| - Sair\n\n");
      printf("|1| - Modulo de Alunos\n\n");
      printf("|2| - Modulo de Professores\n\n");
      printf("|3| - Modulo de Disciplinas\n\n");
      printf("|4| - Aniversariante do Dia\n\n");
      printf("|5| - Aniversariantes do Mes\n\n");
      printf("|6| - Buscar pessoa por nome\n\n");
      printf("======================\n\n");
  
      printf("Qual deseja acessar?: ");
      if (scanf("%d", &escolha) != 1)
      {
        errorMsg(windows);
      }
  
      limparBuffer();
  
      return escolha;
  }
  
  
  int menuAlunos(int windows)
  {
      int escolha_aluno = -1;
      printf("======================\n\n");
      printf("|0| - Voltar\n\n");
      printf("|1| - Inserir Alunos\n\n");
      printf("|2| - Atualizar Alunos\n\n");
      printf("|3| - Exibicao\n\n");
      printf("|4| - Excluir Alunos\n\n");
      printf("======================\n\n");
      printf("Qual deseja acessar?: ");
    
      if (scanf("%d", &escolha_aluno) != 1)
      {
        errorMsg(windows);
      }

      limparBuffer();

      return escolha_aluno;
  }

  int menuExibicao(int windows)
  {
      int escolha_exibicao = -1;
      printf("======================\n\n");
      printf("|0| - Voltar\n\n");
      printf("|1| - Ordem Padrao (Ordem de Cadastro)\n\n");
      printf("|2| - Buscar por Nome\n\n");
      printf("|3| - Ordenar por Sexo\n\n");
      printf("|4| - Ordenar por Nome\n\n");
      printf("|5| - Ordenar por Nascimento\n\n");
      printf("======================\n\n");
      printf("Qual deseja acessar?: ");

      if (scanf("%d", &escolha_exibicao) != 1)
      {
        errorMsg(windows);
      }
  
      return escolha_exibicao;
  }


  int menuAtualizarPessoas(int windows)
  {
      int escolha_att = -1;
      printf("======================\n\n");
      printf("|0| - Voltar\n\n");
      printf("|1| - Atualizar Nome\n\n");
      printf("|2| - Atualizar Sexo\n\n");
      printf("|3| - Atualizar Data de Nascimento\n\n");
      printf("|4| - Atualizar Matricula\n\n");
      printf("|5| - Atualizar CPF\n\n");
      printf("======================\n\n");
      printf("Qual deseja acessar?: ");
  
      if (scanf("%d", &escolha_att) != 1)
      {
        errorMsg(windows);
      }

      limparBuffer();
  
      return escolha_att;
  }
  
  
  int menuProfessores(int windows)
  {
      int escolha_prof = -1;
      printf("======================\n\n");
      printf("|0| - Voltar\n\n");
      printf("|1| - Inserir Professores\n\n");
      printf("|2| - Atualizar Professores\n\n");
      printf("|3| - Exibicao\n\n");
      printf("|4| - Excluir Professores\n\n");
      printf("======================\n\n");
      printf("Qual deseja acessar?: ");
  
      if (scanf("%d", &escolha_prof) != 1)
      {
        errorMsg(windows);
      }

      limparBuffer();
  
      return escolha_prof;
  }
  
  
  int menuDisciplinas(int windows)
  {
      int escolha_disci = -1;
      printf("======================\n\n");
      printf("|0| - Voltar\n\n");
      printf("|1| - Inserir Disciplinas\n\n");
      printf("|2| - Atualizar Disciplinas\n\n");
      printf("|3| - Exibir Disciplinas\n\n");
      printf("|4| - Excluir Disciplinas\n\n");
      printf("======================\n\n");
      printf("Qual deseja acessar?: ");
  
      if (scanf("%d", &escolha_disci) != 1)
      {
        errorMsg(windows);
      }

      limparBuffer();
  
      return escolha_disci;
  }

   
  int menuAttDisciplinas(int windows)
  {
      int escolha_att_disci = -1;
      printf("======================\n\n");
      printf("|0| - Voltar\n\n");
      printf("|1| - Atualizar Nome\n\n");
      printf("|2| - Atualizar Codigo\n\n");
      printf("|3| - Atualizar Professor\n\n");
      printf("|4| - Atualizar Semestre\n\n");
      printf("======================\n\n");
      printf("Qual deseja acessar?: ");
  
      if (scanf("%d", &escolha_att_disci) != 1)
      {
        errorMsg(windows);
      }

      limparBuffer();
  
      return escolha_att_disci;
  }
// MENUS;
  
// Funções
  
  void limparTela(int windows)
  {
      if (windows)
      {
          if (system("cls") == 1)
              printf("Comando limpar tela nao pode ser executado");
      }else if (system("clear") == 1)
                printf("Comando limpar tela nao pode ser executado");
  }
  
  
  void delay(long int secs) 
  {
      long int end = time(0) + secs;
      while (time(0) < end);
  }
  
  
  void limparBuffer()
  {
      int c;
      while ((c = getchar()) != '\n' && c != EOF);
  }
  
  
  void pressEnter()
  {
      printf("\nPressione a tecla enter para continuar.");
      limparBuffer();
  }

  
  void fixQuebraLinhaFgets(char alvo[])
  {
    size_t ln = strlen(alvo) -1;
    if (alvo[ln] == '\n')
    alvo[ln] = '\0'; 
  }

// Funções;


// Funcionalidades

  void buscarPessoa(pessoa pessoaBuscadaP[], pessoa pessoaBuscadaA[], int a_cad, int p_cad, int dia_at, int mes_at, int ano_at)
  {
    char busca[100];
    int verificado = 0;
    int tamanhoBusca = 0;

    printf("Informe o nome/letras que deseja encontrar em alunos e professores: ");
    if (fgets(busca, 100, stdin) == NULL) 
    {
        printf("Algo deu errado ao digitar.");
    }
    fixQuebraLinhaFgets(busca);

    tamanhoBusca = strlen(busca);

    while (verificado < tamanhoBusca)
    {
        // Verifica quantos caracteres o usuario digitou
        // printf("DEBUG: Nome Busca %s\n\n", busca);
        // printf("DEBUG: Tamanho Busca %d\n\n", tamanhoBusca);
        for (int i = 0; busca[i] != '\0'; i++)
        {
            if (tamanhoBusca < 3)
            {
                verificado = 0;
                printf("\nDigite pelo menos 3 letras para realizar a busca.\n\nInsira novamente:  ");
                if (fgets(busca, 100, stdin) == NULL) 
                {
                  printf("Algo deu errado ao digitar.");
                }
                fixQuebraLinhaFgets(busca);
                tamanhoBusca = strlen(busca);
            }
            else if (!((busca[i] >= 'A' && busca[i] <= 'Z') || (busca[i] >= 'a' && busca[i] <= 'z') || (busca[i] == ' ')))
            {
                verificado = 0;
                printf("\nNao pode conter caracteres especiais, acento ou numeros!\n\nInsira novamente:  ");
                if (fgets(busca, 100, stdin) == NULL) 
                {
                  printf("Algo deu errado ao digitar.");
                }
                fixQuebraLinhaFgets(busca);
                tamanhoBusca = strlen(busca);
            }
            else verificado++;
        }
        // printf("DEBUG: Nome Busca %s\n\n", busca);
        // printf("DEBUG: Tamanho Busca %d\n\n", tamanhoBusca);
    }
    
    
    int qtdImpressoes = 0;
    // Realiza a Busca
    for (int i = 0, k = 0, letrasIguais = 0; i < a_cad; i++)
    {
        for (int j = 0; pessoaBuscadaA[i].nome[j] != '\0'; j++)
        {
            if ((busca[k] == pessoaBuscadaA[i].nome[j] && busca[k] != '\0') || 
                (busca[k] == (pessoaBuscadaA[i].nome[j] - 32) && busca[k] != '\0') || 
                (busca[k] == (pessoaBuscadaA[i].nome[j] + 32) && busca[k] != '\0'))
            {
                letrasIguais++;
                k++;
                // printf("DEBUG: Letras Iguais aluno: %d\n\n", letrasIguais);
            }
        }
        
        // Imprime na tela o aluno que corresponde as letras buscadas
        if (tamanhoBusca == letrasIguais)
        {
            printf("\n<Aluno No. %d (ordem de cadastro)>", i+1);
            mostrarUmaPessoa(pessoaBuscadaA, dia_at, mes_at, ano_at, i);
            printf("================================\n");
            qtdImpressoes++;
        }
        letrasIguais = 0;
        k = 0;
    }

    for (int i = 0, k = 0, letrasIguais = 0; i < p_cad; i++)
    {
        for (int j = 0; pessoaBuscadaP[i].nome[j] != '\0'; j++)
        {
            if ((busca[k] == pessoaBuscadaP[i].nome[j] && busca[k] != '\0') || 
                (busca[k] == (pessoaBuscadaP[i].nome[j] - 32) && busca[k] != '\0') || 
                (busca[k] == (pessoaBuscadaP[i].nome[j] + 32) && busca[k] != '\0'))
            {
                letrasIguais++;
                k++;
                // printf("DEBUG: Letras Iguais prof: %d\n\n", letrasIguais);
            }
        }
       
        // Imprime na tela o professor que corresponde as letras buscadas
        if (tamanhoBusca == letrasIguais)
        {
            printf("\n<Professor No. %d (ordem de cadastro)>", i+1);
            mostrarUmaPessoa(pessoaBuscadaP, dia_at, mes_at, ano_at, i);
            printf("================================\n");
            qtdImpressoes++;
        }
        letrasIguais = 0;
        k = 0;
    }

    if (qtdImpressoes == 0)
    {
        printf("\n-------------------------------------------------------------------------------");
        printf("\nNao existe ninguem com os termos buscados. Volte para o menu e tente novamente.");
        printf("\n-------------------------------------------------------------------------------\n");
    }
    
    pressEnter();
  }


  void listarPorSexo(int aluno, pessoa pessoasOrdenar[], int cad, int dia_at, int mes_at, int ano_at)
  {
    char sexo;
    int verificado = 0;
    printf("Digite 'F' para Feminino e 'M' para Masculino: "); limparBuffer();
    while (scanf("%c", &sexo) != 1)
    {
      
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
    }
    while (!verificado)
    {
        if (sexo != 'f' && sexo != 'F' && sexo != 'm' && sexo != 'M')
        {
            printf("\nOpcao invalida. Tente Novamente (F/M): "); limparBuffer();
            while (scanf("%c", &sexo) != 1)
            {
              
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
            }
        }
        else 
        {
            verificado = 1;
        }
    }

    limparBuffer();
    
    for (int i = 0; i < cad; i++)
    {
        if (sexo == 'f' || sexo == 'F')
        {
            if (pessoasOrdenar[i].sexo == 'f' || pessoasOrdenar[i].sexo == 'F')
            {
                exibirPessoa(aluno, i);
                mostrarUmaPessoa(pessoasOrdenar, dia_at, mes_at, ano_at, i);
            }
            if (i == (cad-1))
            {
                pressEnter();
            }
        }
        else if (sexo == 'm' || sexo == 'M')
        {
            if (pessoasOrdenar[i].sexo == 'm' || pessoasOrdenar[i].sexo == 'M')
            {
                exibirPessoa(aluno, i);
                mostrarUmaPessoa(pessoasOrdenar, dia_at, mes_at, ano_at, i);
            }
            if (i == (cad-1))
            {
                pressEnter();
            }
        }
    }
  }


int compararDatas(pessoa pessoa1, pessoa pessoa2)
{
    if (pessoa1.nascimento_ano != pessoa2.nascimento_ano) {
        return pessoa1.nascimento_ano - pessoa2.nascimento_ano;
    } else if (pessoa1.nascimento_mes != pessoa2.nascimento_mes) {
        return pessoa1.nascimento_mes - pessoa2.nascimento_mes;
    } else {
        return pessoa1.nascimento_dia - pessoa2.nascimento_dia;
    }
}




void listarNascimento(int aluno, pessoa pessoasOrdenar[], int cad, int dia_at, int mes_at, int ano_at)
{
    int ordem = -1;
    int verificado = 0;
    pessoa ordenado[cad];

    printf("Ordenar por Nascimento\n");
    printf("======================\n\n");
    printf("|0| - Voltar\n\n");
    printf("|1| - Mais Novo Para o Mais Velho\n\n");
    printf("|2| - Mais Velho Para o Mais Novo\n\n");
    printf("======================\n\n");

    printf("Como deseja ordenar?: ");
    while (scanf("%d", &ordem) != 1)
    {
      
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
    }
    limparBuffer();

    while (!verificado)
    {
        if (ordem != 0 && ordem != 1 && ordem != 2)
        {
            printf("\nOpcao invalida. Tente Novamente: ");
            while (scanf("%d", &ordem) != 1)
            {
              
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
            }
        }
        else 
        {
            verificado = 1;
        }
    }

    for (int i = 0; i < cad; i++)
    {
        ordenado[i] = pessoasOrdenar[i];
        strcpy(ordenado[i].nome, pessoasOrdenar[i].nome);
        strcpy(ordenado[i].cpf_formatado, pessoasOrdenar[i].cpf_formatado);
    }
    

    if (ordem == 1)
    {
        int i, j;
        pessoa aux[1];

        for (i = 1; i < cad - 1; i++)
        {
            aux[0] = ordenado[i];
            strcpy(aux[0].nome, ordenado[i].nome);
            strcpy(aux[0].cpf_formatado, ordenado[i].cpf_formatado);

            j = i - 1;

            while (j >= 0 && (compararDatas(aux[0], ordenado[i+i])) > 0) 
            {
                ordenado[j+1] = ordenado[j];
                strcpy(ordenado[j+1].nome, ordenado[j].nome);
                strcpy(ordenado[j+1].cpf_formatado, ordenado[j].cpf_formatado);

                j--;
            }
            ordenado[j+1] = aux[0];
        }
    }

    else if (ordem == 2)
    {
        int i, j;
        pessoa aux[1];

        for (i = 1; i < cad - 1; i++)
        {
            aux[0] = ordenado[i];
            strcpy(aux[0].nome, ordenado[i].nome);
            strcpy(aux[0].cpf_formatado, ordenado[i].cpf_formatado);

            j = i - 1;

            while (j >= 0 && (compararDatas(aux[0], ordenado[i+i])) < 0) 
            {
                ordenado[j+1] = ordenado[j];
                strcpy(ordenado[j+1].nome, ordenado[j].nome);
                strcpy(ordenado[j+1].cpf_formatado, ordenado[j].cpf_formatado);

                j--;
            }
            ordenado[j+1] = aux[0];
        }
    }
       
        if (aluno)
        {
            exibirAlunos(ordenado, cad, ano_at, mes_at, dia_at);
        }
        if (!aluno)
        {
            exibirProfessores(ordenado, cad, ano_at, mes_at, dia_at);  
        }
}

void aniversarianteDia(int windows, pessoa aniversarianteA[], pessoa aniversarianteP[], int a_cad, int p_cad, int dia_at, int mes_at, int ano_at)
{
    int idade = 0;
    int aniversarios = 0;

    void adicionarLinha(int aniversarios)
    {
        if (aniversarios > 0)
        {
            printf("========================================================================\n\n");
        }
    }

    printf("========================================================================\n\n");
    for (int i = 0; i < p_cad; i++)
    {
        if (aniversarianteP[i].nascimento_mes == mes_at && aniversarianteP[i].nascimento_dia == dia_at)
        {
            adicionarLinha(aniversarios);
            aniversarios++;
            idade = calcularIdade(aniversarianteP[i].nascimento_ano, aniversarianteP[i].nascimento_mes, aniversarianteP[i].nascimento_dia, dia_at, mes_at, ano_at);

            if (aniversarianteP[i].sexo == 'm' || aniversarianteP[i].sexo == 'M' )
            {
                printf("O Professor %s", aniversarianteP[i].nome);
            }
            else if (aniversarianteP[i].sexo == 'f' || aniversarianteP[i].sexo == 'F' )
            {
                printf("A Professora %s", aniversarianteP[i].nome);
            }
            
            if (aniversarianteP[i].sexo == 'f' || aniversarianteP[i].sexo == 'F')
            {
                printf(" e a aniversariante do dia!!!\n\nParabens pelos %d anos de vida e por mais 1 ano de proximidade da morte!\n\n", idade);
            }
            else if (aniversarianteP[i].sexo == 'm' || aniversarianteP[i].sexo == 'M')
            {
                printf(" e o aniversariante do dia!!!\n\nParabens pelos %d anos de vida e por mais 1 ano de proximidade da morte!\n\n", idade);
            }
        }
    }

    for (int i = 0; i < a_cad; i++)
    {
        if (aniversarianteA[i].nascimento_mes == mes_at && aniversarianteA[i].nascimento_dia == dia_at)
        {
            adicionarLinha(aniversarios);
            aniversarios++;
            idade = calcularIdade(aniversarianteA[i].nascimento_ano, aniversarianteA[i].nascimento_mes, aniversarianteA[i].nascimento_dia, dia_at, mes_at, ano_at);

            if (aniversarianteA[i].sexo == 'm' || aniversarianteA[i].sexo == 'M')
            {
                printf("O Aluno %s", aniversarianteA[i].nome);
            }
            else if (aniversarianteA[i].sexo == 'f' || aniversarianteA[i].sexo == 'F')
            {
                printf("A Aluna %s", aniversarianteA[i].nome);
            }
             
            if (aniversarianteA[i].sexo == 'f' || aniversarianteA[i].sexo == 'F')
            {
                printf(" e a aniversariante do dia!!!\n\nParabens pelos %d anos de vida e por mais 1 ano de proximidade da morte!\n\n", idade);
            }
            else if (aniversarianteA[i].sexo == 'm' || aniversarianteA[i].sexo == 'M')
            {
                printf(" e o aniversariante do dia!!!\n\nParabens pelos %d anos de vida e por mais 1 ano de proximidade da morte!\n\n", idade);
            }
        }
    }
    printf("========================================================================\n\n");

    if (!aniversarios)
    {
        limparTela(windows);
        printf("Sem aniversariantes do dia.\n");
    }

    pressEnter();
}


void aniversariantesMes(int windows, pessoa aniversarianteA[], pessoa aniversarianteP[], int a_cad, int p_cad, int dia_at, int mes_at, int ano_at)
{
    int idade = 0;
    int aniversarios = 0;

    void fixIdade(int idade, int nascimento_dia, int dia_at)
    {
        if (nascimento_dia > dia_at)
        {
            idade++;
            printf("%d anos.\n\n", idade);
        }
        else if (nascimento_dia <= dia_at)
        {
            printf("%d anos.\n\n", idade);
        }
    }

    void adicionarLinha(int aniversarios)
    {
        if (aniversarios > 0)
        {
            printf("------------------------------------------------------------------------\n\n");
        }
    }

    printf("Os aniversariantes do mes sao: \n");
    printf("==============================\n\n");

    for (int i = 0; i < p_cad; i++)
    {
        if (aniversarianteP[i].nascimento_mes == mes_at)
        {
            adicionarLinha(aniversarios);
            aniversarios++;
            idade = calcularIdade(aniversarianteP[i].nascimento_ano, aniversarianteP[i].nascimento_mes, aniversarianteP[i].nascimento_dia, dia_at, mes_at, ano_at);

            if (aniversarianteP[i].sexo == 'm' || aniversarianteP[i].sexo == 'M' )
            {
                printf("O Professor %s completando ", aniversarianteP[i].nome);
                fixIdade(idade, aniversarianteP[i].nascimento_dia, dia_at);
            }
            else if (aniversarianteP[i].sexo == 'f' || aniversarianteP[i].sexo == 'F' )
            {
                printf("A Professora %s completando ", aniversarianteP[i].nome);
                fixIdade(idade, aniversarianteP[i].nascimento_dia, dia_at);
            }
        }
    }

    for (int i = 0; i < a_cad; i++)
    {
        if (aniversarianteA[i].nascimento_mes == mes_at)
        {
            adicionarLinha(aniversarios);
            aniversarios++;
            idade = calcularIdade(aniversarianteA[i].nascimento_ano, aniversarianteA[i].nascimento_mes, aniversarianteA[i].nascimento_dia, dia_at, mes_at, ano_at);
            
            if (aniversarianteA[i].sexo == 'm' || aniversarianteA[i].sexo == 'M')
            {
                printf("O Aluno %s completando ", aniversarianteA[i].nome);
                fixIdade(idade, aniversarianteA[i].nascimento_dia, dia_at);
            }
            else if (aniversarianteA[i].sexo == 'f' || aniversarianteA[i].sexo == 'F')
            {
                printf("A Aluna %s completando ", aniversarianteA[i].nome);
                fixIdade(idade, aniversarianteA[i].nascimento_dia, dia_at);
            }
        }
    }
    adicionarLinha(aniversarios);   
    

    if (!aniversarios)
    {
        limparTela(windows);
        printf("Sem aniversariantes do mes.\n");
    }
    
    pressEnter();
}


void listarOrdemABC(int aluno, pessoa pessoasOrdenar[], int cad, int dia_at, int mes_at, int ano_at)
{
    int resultadoCmp;
    pessoa ordenado[cad];

    for (int i = 0; i < cad; i++)
    {
        ordenado[i] = pessoasOrdenar[i];
        strcpy(ordenado[i].nome, pessoasOrdenar[i].nome);
        strcpy(ordenado[i].cpf_formatado, pessoasOrdenar[i].cpf_formatado);
    }
    
    for (int i = 0; i < cad; i++)
    {   
        for (int j = i+1; j < cad; j++)
        {
            resultadoCmp = strcmp(ordenado[i].nome, ordenado[j].nome);

            if (resultadoCmp > 0)
            {
                ordenado[i] = pessoasOrdenar[j];
                strcpy(ordenado[i].nome, pessoasOrdenar[j].nome);
                strcpy(ordenado[i].cpf_formatado, pessoasOrdenar[j].cpf_formatado);

                ordenado[j] = pessoasOrdenar[i];
                strcpy(ordenado[j].nome, pessoasOrdenar[i].nome);
                strcpy(ordenado[j].cpf_formatado, pessoasOrdenar[i].cpf_formatado);
            }
            
        }
    }

    if (aluno)
    {
        exibirAlunos(ordenado, cad, ano_at, mes_at, dia_at);   
    }
    if (!aluno)
    {
        exibirProfessores(ordenado, cad, ano_at, mes_at, dia_at);  
    }
}


  int procurarPessoa(int aluno, long int matricula, pessoa pessoaBuscada[], int dia_at, int mes_at, int ano_at, int a_cad)
  {
    // Retorno -2 Matricula Invalida
    // Retorno -1 Operacao cancelada
    for (int i = 0; i < a_cad; i++)
    {
        char SeN;

        char SimNao()
        {
            char SeN;
            printf("Deseja Continuar? S/N: ");
            while (scanf("%c", &SeN) != 1)
            {
              
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
            }
            while (SeN != 's' && SeN != 'n' && SeN != 'S' && SeN != 'N')
            {
                printf("\n\nOpcao invalida. Digite 'S' para SIM e 'N' para NAO: ");
                while (scanf("%c", &SeN) != 1)
                {
                  
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                }
            }
            return SeN;
        }

        if (matricula == pessoaBuscada[i].matricula)
        {
            if (aluno)
            {
                printf("Aluno Encontrado!\n\n");
                exibirPessoa(aluno, i);
                mostrarUmaPessoa(pessoaBuscada, dia_at, mes_at, ano_at, i);

                SeN = SimNao();
                if (SeN == 's' || SeN == 'S')
                {
                    return i;
                }
                else if (SeN == 'n' || SeN == 'N')
                {
                    return -1;
                }
            }
            else if (!aluno)
            {
                printf("Professor Encontrado!\n\n");
                exibirPessoa(aluno, i);
                mostrarUmaPessoa(pessoaBuscada, dia_at, mes_at, ano_at, i);

                SeN = SimNao();
                if (SeN == 's' || SeN == 'S')
                {
                    return i;
                }
                else if (SeN == 'n' || SeN == 'N')
                {
                    return -1;
                }
            }
        }
    }

    return -2;
  }


  int calcularIdade(int ano_pessoa, int mes_pessoa, int dia_pessoa, int dia_at, int mes_at, int ano_at)
  {
    int idade;
    idade = ano_at - ano_pessoa;
    if (mes_pessoa >= mes_at)
    {
        if (mes_pessoa > mes_at) idade -= 1;
        
        if (mes_pessoa == mes_at)
        {
            if (dia_pessoa > dia_at) idade -= 1;
        }
    }
    return idade;
  }

  
  void mostrarUmaPessoa(pessoa pessoaBuscada[], int dia_at, int mes_at, int ano_at, int i)
    {
        int idade;
        printf("\n\nNome: ");puts(pessoaBuscada[i].nome);
        
        idade = ano_at - pessoaBuscada[i].nascimento_ano;
        if (pessoaBuscada[i].nascimento_mes >= mes_at)
        {
            if (pessoaBuscada[i].nascimento_mes > mes_at) idade -= 1;

            if (pessoaBuscada[i].nascimento_mes == mes_at)
            {
                if (pessoaBuscada[i].nascimento_dia > dia_at) idade -= 1;
            }
        }
        printf("\nData de Nascimento: %02d/%02d/%d\n\nIdade: %d anos", pessoaBuscada[i].nascimento_dia, pessoaBuscada[i].nascimento_mes, pessoaBuscada[i].nascimento_ano, idade);

        if (pessoaBuscada[i].sexo == 'M' || pessoaBuscada[i].sexo == 'm')
        {
            printf("\n\nSexo: Masculino");
        }else printf("\n\nSexo: Feminino");

        printf("\n\nMatricula: %ld", pessoaBuscada[i].matricula);

        printf("\n\nCPF: %s", pessoaBuscada[i].cpf_formatado);
        printf("\n\n");
    }


  void exibirPessoa(int aluno, int a_cad)
    {
        if (aluno)
        {
            printf("--------Aluno %d--------", a_cad+1);
        }else printf("--------Professor %d--------", a_cad+1);
    }
  

  int cadastrar(pessoa pessoa_main[], int a_cad, pessoa pessoa_comp[], int p_cad, int windows, int ano_at, int aluno, int* continuar, int i, int escolha_att)
  {
    int espaco = 0;

    // pessoa doppelganger[1];
    
    if (escolha_att == 1 || escolha_att == 0)
    {
        exibirPessoa(aluno, a_cad);
        printf("\nInsira seu nome: "); 
        if (fgets(pessoa_main[i].nome, max, stdin) == NULL) 
        {
          printf("Algo deu errado ao digitar.");
        }
        fixQuebraLinhaFgets(pessoa_main[i].nome);
        
        for (int j = 0; pessoa_main[i].nome[j] != '\0'; j++)
        {
            while (!((pessoa_main[i].nome[j] >= 'A' && pessoa_main[i].nome[j] <= 'Z') || (pessoa_main[i].nome[j] >= 'a' && pessoa_main[i].nome[j] <= 'z') || (pessoa_main[i].nome[j] == ' ')))
            {
                printf("\nO nome nao pode conter caracteres especiais ou acento!\n\nInsira novamente:  ");
                if (fgets(pessoa_main[i].nome, max, stdin) == NULL) 
                {
                  printf("Algo deu errado ao digitar.");
                }
                fixQuebraLinhaFgets(pessoa_main[i].nome);
            }
            if (pessoa_main[i].nome[j] == ' ')
            {
                if ((pessoa_main[i].nome[j+1] >= 'A' && pessoa_main[i].nome[j+1] <= 'Z') || (pessoa_main[i].nome[j+1] >= 'a' && pessoa_main[i].nome[j+1] <= 'z'))
                {
                    espaco++;
                }
            }
        }
        while (espaco < 1 || pessoa_main[i].nome[0] <'A' || pessoa_main[i].nome[0] > 'Z')
            {
                if (pessoa_main[i].nome[0] <'A' || pessoa_main[i].nome[0] > 'Z')
                {
                    printf("\nSeu nome esta em minusculo!\n\nInsira novamente:  ");
                    if (fgets(pessoa_main[i].nome, max, stdin) == NULL) 
                    {
                      printf("Algo deu errado ao digitar.");
                    }
                    fixQuebraLinhaFgets(pessoa_main[i].nome);
                }
                for (int j = 0; pessoa_main[i].nome[j] != '\0'; j++)
                {
                    if (!((pessoa_main[i].nome[j] >= 'A' && pessoa_main[i].nome[j] <= 'Z') || (pessoa_main[i].nome[j] >= 'a' && pessoa_main[i].nome[j] <= 'z') || (pessoa_main[i].nome[j] == ' ')))
                    {
                        printf("\nO nome nao pode conter caracteres especiais ou acento!\n\nInsira novamente:  ");
                        if (fgets(pessoa_main[i].nome, max, stdin) == NULL) 
                        {
                          printf("Algo deu errado ao digitar.");
                        }
                        fixQuebraLinhaFgets(pessoa_main[i].nome);
                    }
                    if (pessoa_main[i].nome[j] == ' ')
                    {
                        if ((pessoa_main[i].nome[j+1] >= 'A' && pessoa_main[i].nome[j+1] <= 'Z') || (pessoa_main[i].nome[j+1] >= 'a' && pessoa_main[i].nome[j+1] <= 'z'))
                        {
                            espaco++;
                        }
                    }
                }
                if (espaco < 1)
                {
                    printf("\nVoce deve inserir seu nome completo!\n\nInsira novamente:  ");
                    
                    if (fgets(pessoa_main[i].nome, max, stdin) == NULL) 
                    {
                      printf("Algo deu errado ao digitar.");
                    }
                    fixQuebraLinhaFgets(pessoa_main[i].nome);
                }
            }
        espaco = 0;

        printf("\n> Nome: '%s' definido com sucesso.\n", pessoa_main[i].nome);

        pressEnter();

        limparTela(windows);
    }

    

    if (escolha_att == 2 || escolha_att == 0)
    {
        exibirPessoa(aluno, a_cad);
        
        printf("\nQual o seu sexo? F (Feminino), M (Masculino): ");
        while (scanf("%c", &pessoa_main[i].sexo) != 1)
        {
          
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
        }
        limparBuffer();
        while (pessoa_main[i].sexo != 'm' && pessoa_main[i].sexo != 'M' && pessoa_main[i].sexo != 'f' && pessoa_main[i].sexo != 'F')
        {
            printf("\nSomente as opcoes F (Feminino) e M (Masculino) sao aceitas!\n\nInsira novamente:  ");
            while (scanf("%c", &pessoa_main[i].sexo) != 1)
            {
              
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
            }
            limparBuffer();
        }

        if (pessoa_main[i].sexo == 'm' || pessoa_main[i].sexo == 'M')
        {
            printf("\n> Sexo definido como 'Masculino' com sucesso.\n");
        }

        else if (pessoa_main[i].sexo == 'f' || pessoa_main[i].sexo == 'F')
        {
            printf("\n> Sexo definido como 'Feminino' com sucesso.\n");
        }

        pressEnter();

        limparTela(windows);
    }

    if (escolha_att == 3 || escolha_att == 0)
    {
        exibirPessoa(aluno, a_cad);

        printf("\nInsira sua data de nascimento DD MM AAAA espacando devidamente: ");
        while (scanf(" %d%d%d", &pessoa_main[i].nascimento_dia, &pessoa_main[i].nascimento_mes, &pessoa_main[i].nascimento_ano) != 3)
        {
          printf("Erro.");
          limparBuffer();
          printf("\nTente Novamente: ");
          printf("\nInsira sua data de nascimento DD MM AAAA espacando devidamente: ");
        }
        limparBuffer();

        // FAZER UMA FUNÇÂO DE VERIFICAÇÂO DE DATA

        int validDate = 0;
        while (!validDate)
        {
            int validacao = 0;
            if (pessoa_main[i].nascimento_ano > 1900 && pessoa_main[i].nascimento_ano <= ano_at)
            {
                validacao++;
            }
            else if(validacao != 2)
            {
                validacao = 0;
                printf("\n\nData invalida!\n\nInsira Novamente no modo DD MM AAAA: ");
                while (scanf(" %d%d%d", &pessoa_main[i].nascimento_dia, &pessoa_main[i].nascimento_mes, &pessoa_main[i].nascimento_ano) != 3)
                {
                  
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                }
              limparBuffer();
            } 
            
            if ((pessoa_main[i].nascimento_mes == 1 || pessoa_main[i].nascimento_mes == 3 || pessoa_main[i].nascimento_mes == 5 || 
                pessoa_main[i].nascimento_mes == 7 || pessoa_main[i].nascimento_mes == 8 || pessoa_main[i].nascimento_mes == 10 || 
                pessoa_main[i].nascimento_mes == 12)  &&  (pessoa_main[i].nascimento_dia >= 1 && pessoa_main[i].nascimento_dia <= 31))
            {
                validacao++;
            }
            else if ((pessoa_main[i].nascimento_mes == 4 || pessoa_main[i].nascimento_mes == 6 || pessoa_main[i].nascimento_mes == 9 || 
                    pessoa_main[i].nascimento_mes == 11)  &&  (pessoa_main[i].nascimento_dia >= 1 && pessoa_main[i].nascimento_dia <= 30))
                {
                    validacao++;
                }
            else if ((pessoa_main[i].nascimento_mes == 2)  &&  (pessoa_main[i].nascimento_dia >= 1 && pessoa_main[i].nascimento_dia <= 28))
                {
                    validacao++;
                }
            else if ((pessoa_main[i].nascimento_mes == 2 && pessoa_main[i].nascimento_dia == 29) && (pessoa_main[i].nascimento_ano % 4 == 0))
                {
                    validacao++;
                }
            
            else if(validacao != 2)
            {
                validacao = 0;
                printf("\n\nData invalida!\n\nInsira Novamente no modo DD MM AAAA: ");
                while (scanf(" %d%d%d", &pessoa_main[i].nascimento_dia, &pessoa_main[i].nascimento_mes, &pessoa_main[i].nascimento_ano) != 3)
                {
                  
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                }
              limparBuffer();
            } 
            if (validacao == 2)
                {
                    validDate = 1;
                }
        }

        printf("\n> Data: %.2d/%.2d/%d definida como data de nascimento.\n", pessoa_main[i].nascimento_dia, pessoa_main[i].nascimento_mes, pessoa_main[i].nascimento_ano);

        pressEnter();
        
        limparTela(windows);
    }

    if (escolha_att == 4 || escolha_att == 0)
    {
        exibirPessoa(aluno, a_cad);
    // ALERTA QUANDO ALGUÉM DIGITAR UM VALOR COMO 123 será considerado válido
        printf("\nInsira sua matricula (9 digitos): ");
        while (scanf(" %ld", &pessoa_main[i].matricula) != 1)
        {

            printf("Erro.");
            limparBuffer();
            printf("\nTente Novamente: ");
        }
        limparBuffer();
        for (int j = 0, t1 = 0, t2 = 0, t3 = 0; t1 == 0 || t2 == 0 || t3 == 0; j++)
        {
            t1 = 0; t2 = 0; t3 = 0;
            for(int j = 0; j < a_cad; j++)
            {
                
                if (j == i)j++;
                if (pessoa_main[i].matricula == pessoa_main[j].matricula)
                {
                    printf("\n\nMatricula ja existente!\n\nInsira novamente: ");
                    while (scanf(" %ld", &pessoa_main[i].matricula) != 1)
                    {
                      
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                    }
                    limparBuffer();
                }else t1++;
                
            }
            for(int j = 0; j < p_cad; j++)
            {
                if (j == i)j++;
                if (pessoa_main[i].matricula == pessoa_comp[j].matricula)
                {
                    printf("\n\nMatricula ja existente!\n\nInsira novamente: ");
                    while (scanf(" %ld", &pessoa_main[i].matricula) != 1)
                    {
                      
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                    }
                    limparBuffer();
                }else t2++;
            }

            if (pessoa_main[i].matricula <= 0 || pessoa_main[i].matricula > 999999999)
            {
                printf("\n\nMatricula invalida!\n\nInsira novamente: ");
                while (scanf(" %ld", &pessoa_main[i].matricula) != 1)
                {
                  
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                }
                limparBuffer();
            }else t3++;
        }

        printf("\n> Matricula: %ld definida com sucesso.\n", pessoa_main[i].matricula);

        pressEnter();

        limparTela(windows);
    }

    if (escolha_att == 5 || escolha_att == 0)
    {
        exibirPessoa(aluno, a_cad);

        printf("\nInsira seu CPF sem formatacao (11 Digitos): ");
        while (scanf(" %s", pessoa_main[i].cpf) != 1)
        {
          
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
        }
        limparBuffer();
        
        int cpfValidado = 0;

        while (cpfValidado < 5)
        {
            // Validacoes basicas
            if (strlen(pessoa_main[i].cpf) != 11)
            {
                cpfValidado = 0;

                printf("\n\nCPF invalido. Verifique se digitou corretamente.\n\nInsira novamente: ");
                while (scanf(" %s", pessoa_main[i].cpf) != 1)
                {
                
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                }
            }
            else cpfValidado++;

            for (int j = 0; pessoa_main[i].cpf[j] != '\0'; j++)
            {
                if (pessoa_main[i].cpf[j] > '9' || pessoa_main[i].cpf[j] < '0')
                {
                    cpfValidado = 0;

                    printf("Apenas numeros sao permitidos.\n\nInsira novamente: ");
                    while (scanf(" %s", pessoa_main[i].cpf) != 1)
                    {
                    
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                    }
                    limparBuffer();
                }
                else cpfValidado++;
            }

            for(int j = 0; j < a_cad; j++)
            {
                if (j == i)j++;
                if (strcmp(pessoa_main[i].cpf, pessoa_main[j].cpf) == 0)
                {
                    cpfValidado = 0;
                    printf("\n\nDEBUG: CPF ja existente!(Mensagem original: 'CPF invalido.')\n\nInsira novamente: ");
                    while (scanf(" %s", pessoa_main[i].cpf) != 1)
                    {
                      
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                    }
                    limparBuffer();
                }
                else cpfValidado++;
            }
            
            for(int j = 0; j < p_cad; j++)
            {
                if (j == i)j++;
                if (strcmp(pessoa_main[i].cpf, pessoa_comp[j].cpf) == 0)
                {
                    cpfValidado = 0;
                    printf("\n\nDEBUG: CPF ja existente!(Mensagem original: 'CPF invalido.')\n\nInsira novamente: ");
                    while (scanf(" %s", pessoa_main[i].cpf) != 1)
                    {
                      
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                    }
                    limparBuffer();
                }
                else cpfValidado++;
            }
            // Fim validacoes basicas


            // Validacao do digito verificador (Colocar em funcao separada para reutilizar em projetos futuros)

                // Separando cada digito do CPF para validar
                int digitos_cpf[11];
                int k = 0;
                while (k < 11)
                {
                    // DEBUG: printf ("Atribuindo o numero %d, a posicao %d de digitos cpf\n\n", (pessoa_main[i].cpf[k] - 48), k);
                    if (pessoa_main[i].cpf[k] <= '9' || pessoa_main[i].cpf[k] >= '0')
                    {
                        digitos_cpf[k] = (pessoa_main[i].cpf[k] - 48);
                    }
                    k++;
                }
                // Fim da separacao.
                
                // Faz a validacao
                int verificador1 = 0;
                int verificador2 = 0;
                
                for (int j = 0, multiplicador1 = 10, multiplicador2 = 11; j < 9; j++)
                {
                    // DEBUG: printf ("\nDigito %d do CPF: %d\n", j, digitos_cpf[j]);

                    // DEBUG: printf("Verificador 1 antes da atribuicao: %d\nMultiplicador1 Antes: %d\n\n", verificador1, multiplicador1);

                    verificador1 = verificador1 + (digitos_cpf[j] * multiplicador1); //--;
                    multiplicador1--;

                    // DEBUG: printf ("Verificador 1 depois da atribuicao: %d\nMultiplicador1 depois: %d\n", verificador1, multiplicador1);

                    verificador2 = verificador2 + (digitos_cpf[j] * multiplicador2); //--;
                    multiplicador2--;
                }

                // DEBUG: printf("\n\nVERIFICADOR1 %d\n\nVERIFICADOR2 %d", verificador1, verificador2);
                
                verificador1 *= 10;
                verificador1 %= 11;

                verificador2 = ((verificador2 + (verificador1 * 2)) * 10);
                verificador2 %= 11;

                // DEBUG: printf("\n\nVERIFICADOR1 %d\n\nVERIFICADOR2 %d", verificador1, verificador2);

                if (verificador1 != digitos_cpf[9])
                {
                    cpfValidado = 0;
                    printf("\n\nDEBUG: Problema com digito verificador 1. (Mensagem original: 'CPF invalido.')\n\nInsira novamente: ");
                    while (scanf(" %s", pessoa_main[i].cpf) != 1)
                    {
                        
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                    }
                    limparBuffer();
                }
                else if (verificador2 != digitos_cpf[10])
                {
                    cpfValidado = 0;
                    printf("\n\nDEBUG: Problema com digito verificador 2. (Mensagem original: 'CPF invalido.')\n\nInsira novamente: ");
                    while (scanf(" %s", pessoa_main[i].cpf) != 1)
                    {
                        
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
                    }
                    limparBuffer();
                }
                else cpfValidado++;
            // Fim da validacao do digito verificador.
        }
    
        sprintf(pessoa_main[i].cpf_formatado, "%c%c%c.%c%c%c.%c%c%c-%c%c", pessoa_main[i].cpf[0], pessoa_main[i].cpf[1], 
        pessoa_main[i].cpf[2], pessoa_main[i].cpf[3], pessoa_main[i].cpf[4], 
        pessoa_main[i].cpf[5], pessoa_main[i].cpf[6], pessoa_main[i].cpf[7], 
        pessoa_main[i].cpf[8], pessoa_main[i].cpf[9], pessoa_main[i].cpf[10]);

        printf("\n> CPF: %s definido com sucesso.\n", pessoa_main[i].cpf_formatado);

        pressEnter();

        limparTela(windows);
    }

        // int contagem_reg = 3;
        // while (contagem_reg > 0) 
        // {
        //     if (aluno)
        //     {
        //         printf("Aluno %d ", a_cad+1);
        //     }
        //     else 
        //     {
        //         printf("Professor %d ", a_cad+1);
        //     }
        //     printf("cadastrado com sucesso! Voltando em %d...", contagem_reg);
        //     delay(1);
        //     limparTela(windows);
        //     contagem_reg--;
        // }
        

        
    if (escolha_att == 0)
    {
        if (aluno)
        {
            printf("Aluno %d ", a_cad+1);
        }
        else 
        {
            printf("Professor %d ", a_cad+1);
        }
        printf("cadastrado com sucesso!");
        pressEnter();

        limparTela(windows);

        a_cad++; // passa para a próxima posição do vetor dizendo que a anterior ja esta ocupada por um cadastro
        char SeN;
        printf("Deseja realizar um novo cadastro? (S/N): ");
        while (scanf("%c", &SeN) != 1)
        {
            printf("Erro.");
            limparBuffer();
            printf("\nTente Novamente: ");
        }
        // SeN = getch();
        while (SeN != 's' && SeN != 'n' && SeN != 'S' && SeN != 'N')
        {
            printf("\n\nOpcao invalida. Digite 'S' para SIM e 'N' para NAO: ");
            while (scanf("%c", &SeN) != 1)
            {
              
                                  printf("Erro.");
                                  limparBuffer();
                                  printf("\nTente Novamente: ");
            }
            // SeN = getch();
        }
        if (SeN == 'n' || SeN == 'N')
        {   
            *continuar = 0;
            limparTela(windows);
        }
    }
    else 
    {
        printf("Cadastro Atualizado com sucesso!");
        pressEnter();
        *continuar = 0;
    }

    if (escolha_att == 0)
    {
        return a_cad;
    }
    return 0;
  }


  int excluirPessoa(pessoa alvoExclusao[], int posicaoVetor, int a_cad)
  {
    if (posicaoVetor < (a_cad - 1))
    {
        while (posicaoVetor < (a_cad -1))
        {
            alvoExclusao[posicaoVetor] = alvoExclusao[posicaoVetor + 1];
            posicaoVetor++;
        }
        a_cad--;
        return a_cad;
    }
    else if (posicaoVetor == (a_cad - 1))
    {
        a_cad--;
        return a_cad;
    }
    
    return 0;
  }


  int excluirDisciplina(disciplina alvoExclusao[], int posicaoVetor, int d_cad)
  {
    if (posicaoVetor < (d_cad - 1))
    {
        while (posicaoVetor < (d_cad -1))
        {
            alvoExclusao[posicaoVetor] = alvoExclusao[posicaoVetor + 1];
            posicaoVetor++;
        }
        d_cad--;
        return d_cad;
    }
    else if (posicaoVetor == (d_cad - 1))
    {
        d_cad--;
        return d_cad;
    }
    
    return 0;
  }
  
  
  void exibirAlunos(pessoa alunos[], int a_cad, int ano_at, int mes_at, int dia_at)
  {
      for (int i = 0, idade = 0; i < a_cad; i++)
      {
          printf("--------------Aluno %d--------------", i+1);
          printf("\n\nNome: ");puts(alunos[i].nome);
          
          idade = ano_at - alunos[i].nascimento_ano;
          if (alunos[i].nascimento_mes >= mes_at){
              if (alunos[i].nascimento_mes > mes_at) idade -= 1;
              if (alunos[i].nascimento_mes == mes_at){
                  if (alunos[i].nascimento_dia > dia_at) idade -= 1;}}
          printf("\nData de Nascimento: %02d/%02d/%d\n\nIdade: %d anos", alunos[i].nascimento_dia, alunos[i].nascimento_mes, alunos[i].nascimento_ano, idade);
  
          if (alunos[i].sexo == 'M' || alunos[i].sexo == 'm')
          {
              printf("\n\nSexo: Masculino");
          }else printf("\n\nSexo: Feminino");
  
          printf("\n\nMatricula: %ld", alunos[i].matricula);
  
          printf("\n\nCPF: %s", alunos[i].cpf_formatado);
          printf("\n\n");
      }
      limparBuffer();
      pressEnter();
  }
  
  
  void exibirProfessores(pessoa professores[], int p_cad, int ano_at, int mes_at, int dia_at)
  {
      for (int i = 0, idade = 0; i < p_cad; i++)
      {
          printf("--------------Professor %d--------------", i+1);
          printf("\n\nNome: "); puts(professores[i].nome);
          
          idade = ano_at - professores[i].nascimento_ano;
          if (professores[i].nascimento_mes >= mes_at){
              if (professores[i].nascimento_mes > mes_at) idade -= 1;
              if (professores[i].nascimento_mes == mes_at){
                  if (professores[i].nascimento_dia > dia_at) idade -= 1;}}
          printf("\nData de Nascimento: %02d/%02d/%d\n\nIdade: %d anos", professores[i].nascimento_dia, professores[i].nascimento_mes, professores[i].nascimento_ano, idade);
  
          if (professores[i].sexo == 'M' || professores[i].sexo == 'm')
          {
              printf("\n\nSexo: Masculino");
          }else printf("\n\nSexo: Feminino");
  
          printf("\n\nMatricula: %ld", professores[i].matricula);
  
          printf("\n\nCPF: %s", professores[i].cpf_formatado);
          printf("\n\n");
      }
      limparBuffer();
      pressEnter();
  }


  int cadastrarDisciplina(disciplina disciplinas[], int d_cad, pessoa professores[], int p_cad, int windows, int *continuar, int i, int escolha_att)
  {
    if (escolha_att == 1 || escolha_att == 0)
    {
        printf("--------Disciplina %d--------", d_cad+1);
  
        printf("\nInsira o nome da disciplina: ");
        if (fgets(disciplinas[i].nome, max, stdin) == NULL) 
        {
        printf("Algo deu errado ao digitar.");
        }
        fixQuebraLinhaFgets(disciplinas[i].nome); 

        for (int j = 0; j < n_disci; j++)
        {
            if (i == j)j++;
            if (strcmp(disciplinas[i].nome, disciplinas[j].nome) == 0)
            {
                printf("\n\nNome ja existente!\n\nInsira novamente: ");
                
                if (fgets(disciplinas[i].nome, max, stdin) == NULL) 
                {
                    printf("Algo deu errado ao digitar.");
                }
                fixQuebraLinhaFgets(disciplinas[i].nome);
            }
            while (disciplinas[i].nome[0] < 'A' || disciplinas[i].nome[0] > 'Z')
            {
                if (disciplinas[i].nome[0] < 'A' || disciplinas[i].nome[0] > 'Z')
                {
                    printf("\nA primeira letra esta em minusculo!\n\nInsira novamente:  ");

                    if (fgets(disciplinas[i].nome, max, stdin) == NULL) 
                    {
                        printf("Algo deu errado ao digitar.");
                    }
                    fixQuebraLinhaFgets(disciplinas[i].nome);
                }
                for (int j = 0; disciplinas[i].nome[j] != '\0'; j++)
                {
                    if (!((disciplinas[i].nome[j] >= 'A' && disciplinas[i].nome[j] <= 'Z') || (disciplinas[i].nome[j] >= 'a' && disciplinas[i].nome[j] <= 'z') || (disciplinas[i].nome[j] == ' ')))
                    {
                        printf("\nO nome nao pode conter caracteres especiais ou acento!\n\nInsira novamente:  ");

                        if (fgets(disciplinas[i].nome, max, stdin) == NULL) 
                        {
                            printf("Algo deu errado ao digitar.");
                        }
                        fixQuebraLinhaFgets(disciplinas[i].nome);
                    }
                }
            }
        }
    }
    
          
  
    if (escolha_att == 2 || escolha_att == 0)
    {
        limparTela(windows);
        int valido = 0;
        printf("--------Disciplina %d--------", d_cad+1);
        int etapa = 0;
        while(!valido)
        {
            char disciplina_codigo[10];
            switch(etapa)
            {
                case 0:
                {
                    printf("\nInsira o codigo da disciplina 8 digitos: ");
                    while (fgets(disciplina_codigo, 10, stdin) == NULL) 
                    {
                        printf("\nAlgo deu errado ao digitar.");
                        printf("\nTente novamente: ");
                    }
                    limparBuffer();
                    fixQuebraLinhaFgets(disciplina_codigo);

                    etapa = 1;
                }
                break;

                case 1:
                {
                    if(strlen(disciplina_codigo) != 8)
                    {
                        printf("\nO nome precisa ter 8 digitos!\n");
                        etapa = 0;
                    }
                    else
                    {
                        etapa = 2;
                    }
                }
                break;

                case 2:
                {
                    for (int k = 0; k < d_cad; k++)
                    {
                        if (strcmp(disciplina_codigo, disciplinas[k].codigo) == 0)
                        {
                            printf("\n\nCodigo ja existentente!");
                            etapa = 0;
                            break;
                        }
                    }
                    etapa = 3;
                }
                break;

                case 3:
                {
                    strcpy(disciplinas[i].codigo, disciplina_codigo);
                    valido = 1;
                }
                break;
            }
        }
    }     
          

    if (escolha_att == 3 || escolha_att == 0)
    { 
        limparTela(windows);
        printf("--------Disciplina %d--------", d_cad+1);

        long int matriculaProfessor = 0;

        printf("\nInsira a matricula do professor da disciplina de %s: ", disciplinas[i].nome); 
        while (scanf(" %ld", &matriculaProfessor) != 1)
        {
            printf("Erro.");
            limparBuffer();
            printf("\nTente Novamente: ");
        }

        int encontrado = 0;
        while (!encontrado)
        {
            for (int k = 0; k < p_cad; k++)
            {
                if (matriculaProfessor == professores[k].matricula)
                {
                    disciplinas[i].professor = &professores[k];
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado)
            {
                printf("\n\nMatricula Invalida. Verifique se digitou corretamente.\n\nInsira novamente: ");
                while (scanf(" %ld", &matriculaProfessor) != 1)
                {
                    printf("Erro.");
                    limparBuffer();
                    printf("\nTente Novamente: ");
                }
            }
        }
        
    }
          
          
    if (escolha_att == 4 || escolha_att == 0)
    { 
        limparTela(windows);
        printf("--------Disciplina %d--------", d_cad+1);

        printf("\nInsira o semestre da disciplina. Ex: 1, 2, 3... : "); 
        limparBuffer();
        while (scanf("%d", &disciplinas[i].semestre) != 1)
        {
        printf("Erro.");
        limparBuffer();
        printf("\nTente Novamente: ");
        }

        while (disciplinas[i].semestre < 1 || disciplinas[i].semestre > 14)
        {
            printf("\n\nOpcao invalida!\nInsira novamente: "); 
            limparBuffer();
            while (scanf("%d", &disciplinas[i].semestre) != 1)
            {
            printf("Erro.");
            limparBuffer();
            printf("\nTente Novamente: ");
            } 
        }
    }
        limparTela(windows);

        // int contagem_reg = 3;
        // while (contagem_reg > 0) 
        // {
        //     printf("Disciplina %d cadastrada com sucesso! Voltando em %d...", d_cad+1, contagem_reg);
        //     delay(1);
        //     limparTela(windows);
        //     contagem_reg--;
        // }

        

    if (escolha_att == 0)
    {
        printf("Disciplina %d cadastrada com sucesso!", d_cad+1);
        pressEnter();
        d_cad++;
        limparBuffer();
        char SeN;
        printf("Deseja cadastrar mais uma disciplina? 's' para Sim, 'n' para Nao: ");
        while (scanf("%c", &SeN) != 1)
        {
            printf("Erro.");
            limparBuffer();
            printf("\nTente Novamente: ");
        }
        // SeN = getch();
        while (SeN != 's' && SeN != 'n' && SeN != 'S' && SeN != 'N')
        {
            printf("\n\nOpcao invalida. Digite 's' para SIM e 'n' para NAO: ");
            while (scanf("%c", &SeN) != 1)
            {
                printf("Erro.");
                limparBuffer();
                printf("\nTente Novamente: ");
            }
            // SeN = getch();
        }

        if (SeN == 'n' || SeN == 'N')
        {   
            *continuar = 0;
            limparTela(windows);
        }
    }
    else 
    {
        printf("Cadastro Atualizado com sucesso!");
        pressEnter();
        *continuar = 0;
    }

    if (escolha_att == 0)
    {
        return d_cad;
    }
    return 0;
    
    limparTela(windows);
  }

  
  void exibirDisciplinas(disciplina disciplinas[], int d_cad, int windows)
  {
      for (int i = 0; i < d_cad; i++)
      {
          printf("--------------Disciplina %d--------------", i+1);

          printf("\n\nNome: %s", disciplinas[i].nome);
          
          printf("\n\nCodigo: %s", disciplinas[i].codigo);

          printf("\n\nProfessor: %s", disciplinas[i].professor->nome);
  
          printf("\n\nSemestre: %d", disciplinas[i].semestre);

          printf("\n\n");
      }
      limparBuffer();
      pressEnter();
      limparTela(windows);
  }


  int procurarDisciplina(disciplina disciplinaBuscada[], char codigo[], int d_cad)
  {
    for (int i = 0; i < d_cad; i++)
    {
        int comparacao;
        comparacao = strcmp(codigo, disciplinaBuscada[i].codigo);
        if(comparacao == 0)
        {
            printf("Disciplina econtrada!");
            pressEnter();
            return i;
        }
    }
    
	  printf("Disciplina nao encontrada.");
    pressEnter();
    return -1;
  }

// void inserirAlunoDisciplina(disciplina* entrada, pessoa* lista_alunos, int total_alunos){
// 	int matricula = 0;
// 	int etapa = 0;
// 	int sair = 0;
// 	char escolha_aluno_insercao;
// 	while(!sair){
// 		switch(etapa){
// 			case 0:{
// 				titulo("CADASTRANDO ALUNO EM DISCIPLINA", '-', 0);
// 				printf("[0] - SAIR\n");
// 				printf("[1] - CADASTRAR ALUNO POR MATRICULA\n");
// 				printf("[2] - VER ALUNOS E CADASTRAR\n");
// 				titulo("CADASTRANDO ALUNO EM DISCIPLINA", '-', 1);
// 				escolha_aluno_insercao = leia_char("> Sua escolha: ");
// 				switch(escolha_aluno_insercao){
// 					case '0':{
// 						sair = 1;
// 						break;
// 					}
// 					case'1':{
// 						etapa = 1;
// 						break;
// 					}
// 					case'2': {
// 						titulo("LISTANDO PESSOAS", '-', 1);
// 						ordem_cadastro(lista_alunos, total_alunos);
// 						etapa = 1;
// 						break;
// 					}
// 					default:{
// 						titulo("OPCAO INVALIDA!", '~', 0);
// 						break;
// 					}
// 				}
// 				break;
// 			}
// 			case 1:{
// 				matricula = leia_int_longo("> Digite a matricula do aluno: ");
// 				if(!disciplina_aluno_valido(lista_alunos, total_alunos, matricula)){
// 					titulo("NAO EXISTE ALUNO COM A MATRICULA DIGITADA!", '~', 0);
// 				}
// 				else{
// 					etapa = 2;
// 				}
// 				break;
// 			}
// 			case 2:{
// 				if(!disciplina_aluno_existe(entrada, matricula)){
// 					char texto[100];
// 					char escolha;
// 					if(lista_alunos[matricula - 1].sexo == 'M'){
// 						sprintf(texto,"> Deseja cadastrar %s como aluno de %s?", lista_alunos[matricula - 1].nome, entrada->nome);
// 					}
// 					else{
// 						sprintf(texto,"> Deseja cadastrar %s como aluna de %s?", lista_alunos[matricula - 1].nome, entrada->nome);
// 					}
// 					titulo(texto, '=', 0);
// 					printf("[0] - CANCELAR\n");
// 					printf("[1] - CONFIRMAR\n");
// 					printf("[2] - DIGITAR NOVAMENTE\n");
// 					titulo(texto, '=', 1);
// 					escolha_aluno_insercao = leia_char("> Sua escolha: ");
// 					switch(escolha_aluno_insercao){
// 						case'0':{
// 							etapa = 0;
// 							break;
// 						}
// 						case'1':{
// 							entrada->alunos_cadastrados[entrada->total_alunos_cadastrados] = matricula;
// 							entrada->total_alunos_cadastrados += 1;
// 							lista_alunos[matricula - 1].qtd_disciplinas += 1;
// 							titulo("ALUNO CADASTRADO COM SUCESSO!", '=', 0);
// 							etapa = 0;
// 							break;
// 						}
// 						case '2':{
// 							etapa = 1;
// 							break;
// 						}
					
// 					}
// 				}			
// 				else{
// 					titulo("JA EXISTE UM ALUNO COM A MATRICULA DIGITADA!", '~', 0);
// 					etapa = 1;
// 				}
// 				break;
// 			}
// 		}
// 	}
// }

// Funcionalidades;