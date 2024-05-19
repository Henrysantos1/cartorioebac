#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
 
	int registro()
	{
		//inicioa da criação de valores/string
		char arquivo [40];
		char cpf [40];
		char nome [40];
		char sobrenome [40];
		char cargo [40];
		//final da criação de valores/string
		
		printf("coloque o cpf a ser cadastrado: - "); //coletando informações do usuario
		scanf("%s", cpf);//%s se refere-se a string
		
		strcpy(arquivo,cpf); //responsável por copiar os valores das string
		
		FILE *file; //criar arquivo
		file = fopen(arquivo, "w"); //criar  arquivo e o "w" significar escrever
		fprintf(file,cpf); //salvar o valor da variavel
		fclose(file); //fecha de arquivo
	
		file =fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
		
		printf("coloque o nome a ser cadastrado: - ");
		scanf("%s", nome);
		
		file = fopen(arquivo,"a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
		
		printf("coloque o sobrenome a ser cadastrado: - ");
		scanf("%s",sobrenome);
		
		file = fopen(arquivo,"a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
		
		printf("coloque o cargo a ser cadastrado: - ");
		scanf("%s",cargo);
		
		file = fopen(arquivo,"a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
		
	}
	
	int consulta()
	{
		char cpf [40];
		char conteudo [200];
		
		printf("digite um cpf a ser consultado:");
		scanf("%s",cpf);
		
		FILE * file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("nao foi possivel localizar o arquivo. \n");
		}
		 
		 while(fgets(conteudo, 200, file) != NULL)
		 
		 {
		 	printf("\n essas sao as informacoes do usuario:");
	        printf("%s", conteudo);
	        printf("\n\n");
	        
	        system("pause");
		 }
		
		
	}
	
	int deletar()
	{
		char cpf [40];
		
		printf("informe o cpf a ser deletado: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE * file;
		file = fopen(cpf,"r");
		
		if(file == NULL);
		{
			printf("\t deseja deletar esse usuario?!.\n");
			system("pause");
		}
		
		
	}

int main()
{
	
		int opcao = 0; //definindo variaveis
		int i = 1;
		
	for(i=1; i=1;)	
	{
		system("cls");
	
	   setlocale(LC_ALL,"PORTUGUESE"); //definindo a linguagem
		printf("escolha a opção desejada do menu:\n\n"); //inicio do menu
		printf("\t1 - registrar os nome:\n");
		printf("\t2 - consultar os nome:\n");
		printf("\t3 - deletar os nome:\n\n");
		printf("\t4 - sair do programa:\n\n");
		printf("opcao:");//fim do menu
		 scanf("%d",&opcao); //armazenando a escolha so usuario
		 
		 system("cls"); //responsavel por limpar a tela
		 
	  switch(opcao)	 //inicio da seleção do menu
	  {
	  	case 1:
	    registro(); //chamada de funções
	     break;
	     
	    case 2:
	    consulta();
	     break;
	     
	    case 3:
	    deletar();
	    break;
	    
	    case 4:
	    printf("\t obrigado por ultilizar nosso sistema!\n");
	    return 0;
	    break;
	    
	    case 5:
	    default:
		printf("\tessa opção está invalida:\n");
	    system("pause");
	    break;

      }
	} 
}
