#include <stdio.h> //biblioteca de comunica��o como usu�rio
#include <stdlib.h> //bilibioteca respons�vel por aloca��o de espa�o em mem�rias
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registrar() //fun��o respons�vel pelo cadastro dos usu�rios
{
	//in�cio da cria��o de vari�veis/string (conjunto de vari�veis)
	char arquivo[40];
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF do usu�rio a ser cadastrado: "); //coletando informa��os do usu�rio
	scanf("%s", cpf); //armazenamento da string *s* cpf
	
		strcpy(arquivo, cpf); //respons�vel por copiar os valores das string (arquivo=cpf)
	
		FILE *file; //acessa o FILE e cria o arquivo file
		file = fopen(arquivo, "w"); //cria arquivo novo para armazenar novo dado inserido por digita��o *write*
		fprintf(file, cpf); //salvar valor da variavel cpf
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //abrir arquivo para atualizar dados *a*
		fprintf(file,"_ "); //salvar arquivo "," para dar espa�o entre os dados inseridos
		fclose(file); //fechar arquivo
	
	printf("Digite o nome do usu�rio a ser cadastrado: ");
	scanf("%s", nome); //armazenamento da string nome
	
		file = fopen(arquivo, "a");
		fprintf(file, nome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file, " "); //"" criando espa�o entre os dados digitados (est�tica)
		fclose(file);
		
	printf("Digite o sobrenome do usu�rio a ser cadastrado: ");
	scanf("%s", sobrenome); //armazenento da string sobrenome
	
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, "_ "); // _ criando divis�o entre dados (est�tica)
		fclose(file);
		
	printf("Digite o cargo do usu�rio a ser cadastrado: ");
	scanf("%s", cargo); //armazenando a string cargo

		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);   //n�o precisa da segunda parte pois � o ultimo dado a ser coletado
		
		system("pause");
	
}

int consultar()
{

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usu�rio a ser consultado: "); 
	scanf("%s", cpf); //armazenamento da string cpf
	
	FILE *file;
	file = fopen(cpf, "r"); //consultar e ler arquivo cpf *read*
	
	if(file == NULL) //se o arquivo for nulo
	{
		printf("\nN�o foi poss�vel encontrar o arquivo solicitado! Usu�rio inexistente.\n");	
	}
	
	//inicio do la�o de repeti��o
	while(fgets(conteudo, 200, file) != NULL)  //enquanto houver 200 caracteres, salvar na variavel - parar quando for nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio solicitado: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	//fim do la�o de repeti��o
	
	system("pause");
	fclose(file);
	
}

int deletar()
{
			
	char cpf[40]; //criando string
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf); //salvando string cpf
	
	remove(cpf); //remo��o do arquivo
	
	FILE *file; //buscar arquivo cpf
	file = fopen(cpf, "r"); //abrir e ler arquivo cpf
	
	if (file == NULL) //se arquivo for nulo
	{
		printf("\nO usu�rio foi deletado com sucesso e n�o se encontra mais no sistema!\n\n");
	}
	
	system("pause");
	fclose(file);
	
}
	
	
int main () //fun��o principal
{
	int opcao=0; //definindo vari�vel 
	int laco=1; //definindo vari�vel
	
	for(laco=1;laco=1;) //fun��o de repeti��o
	{
		system("cls"); //limpeza de tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("----  Cart�rio da EBAC  ----\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n\n");
		printf("\t2 - Consultar nomes\n\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Escolha a op��o desejada: ");
	
		scanf("%d", &opcao); //armazenando escolha do usu�rio

		system("cls"); //comunica��o com sistema (deletar informa��es em tela ap�s escolha do usu�rio)
		
		//in�cio da sele��o do menu
		switch(opcao)
		{
			case 1:
			registrar(); //chamada de fun��o
			break;
			
			case 2:
			consultar(); //chamada de fun��o
			break;
			
			case 3:
			deletar(); //chamada de fun��o 
			break;
			
			case 4:
			printf("\nAgradecemos por utilizar o Sistema de Cadastro de Colaboradores da EBAC!\n");
			return 0;
			break;	
			
			default: //qualquer outra op��o n�o definida ou mencionada
			printf("Essa op��o n�o existe! Tente novamente\n");
			system("pause");
			break;	
		} 
		//fim da sele��o do menu
		
	}
	
}

