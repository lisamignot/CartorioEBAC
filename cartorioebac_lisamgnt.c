#include <stdio.h> //biblioteca de comunicação como usuário
#include <stdlib.h> //bilibioteca responsável por alocação de espaço em memórias
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registrar() //função responsável pelo cadastro dos usuários
{
	//início da criação de variáveis/string (conjunto de variáveis)
	char arquivo[40];
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis
	
	printf("Digite o CPF do usuário a ser cadastrado: "); //coletando informaçãos do usuário
	scanf("%s", cpf); //armazenamento da string *s* cpf
	
		strcpy(arquivo, cpf); //responsável por copiar os valores das string (arquivo=cpf)
	
		FILE *file; //acessa o FILE e cria o arquivo file
		file = fopen(arquivo, "w"); //cria arquivo novo para armazenar novo dado inserido por digitação *write*
		fprintf(file, cpf); //salvar valor da variavel cpf
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //abrir arquivo para atualizar dados *a*
		fprintf(file,"_ "); //salvar arquivo "," para dar espaço entre os dados inseridos
		fclose(file); //fechar arquivo
	
	printf("Digite o nome do usuário a ser cadastrado: ");
	scanf("%s", nome); //armazenamento da string nome
	
		file = fopen(arquivo, "a");
		fprintf(file, nome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file, " "); //"" criando espaço entre os dados digitados (estética)
		fclose(file);
		
	printf("Digite o sobrenome do usuário a ser cadastrado: ");
	scanf("%s", sobrenome); //armazenento da string sobrenome
	
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, "_ "); // _ criando divisão entre dados (estética)
		fclose(file);
		
	printf("Digite o cargo do usuário a ser cadastrado: ");
	scanf("%s", cargo); //armazenando a string cargo

		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);   //não precisa da segunda parte pois é o ultimo dado a ser coletado
		
		system("pause");
	
}

int consultar()
{

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usuário a ser consultado: "); 
	scanf("%s", cpf); //armazenamento da string cpf
	
	FILE *file;
	file = fopen(cpf, "r"); //consultar e ler arquivo cpf *read*
	
	if(file == NULL) //se o arquivo for nulo
	{
		printf("\nNão foi possível encontrar o arquivo solicitado! Usuário inexistente.\n");	
	}
	
	//inicio do laço de repetição
	while(fgets(conteudo, 200, file) != NULL)  //enquanto houver 200 caracteres, salvar na variavel - parar quando for nulo
	{
		printf("\nEssas são as informações do usuário solicitado: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	//fim do laço de repetição
	
	system("pause");
	fclose(file);
	
}

int deletar()
{
			
	char cpf[40]; //criando string
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf); //salvando string cpf
	
	remove(cpf); //remoção do arquivo
	
	FILE *file; //buscar arquivo cpf
	file = fopen(cpf, "r"); //abrir e ler arquivo cpf
	
	if (file == NULL) //se arquivo for nulo
	{
		printf("\nO usuário foi deletado com sucesso e não se encontra mais no sistema!\n\n");
	}
	
	system("pause");
	fclose(file);
	
}
	
	
int main () //função principal
{
	int opcao=0; //definindo variável 
	int laco=1; //definindo variável
	
	for(laco=1;laco=1;) //função de repetição
	{
		system("cls"); //limpeza de tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("----  Cartório da EBAC  ----\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n\n");
		printf("\t2 - Consultar nomes\n\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Escolha a opção desejada: ");
	
		scanf("%d", &opcao); //armazenando escolha do usuário

		system("cls"); //comunicação com sistema (deletar informações em tela após escolha do usuário)
		
		//início da seleção do menu
		switch(opcao)
		{
			case 1:
			registrar(); //chamada de função
			break;
			
			case 2:
			consultar(); //chamada de função
			break;
			
			case 3:
			deletar(); //chamada de função 
			break;
			
			case 4:
			printf("\nAgradecemos por utilizar o Sistema de Cadastro de Colaboradores da EBAC!\n");
			return 0;
			break;	
			
			default: //qualquer outra opção não definida ou mencionada
			printf("Essa opção não existe! Tente novamente\n");
			system("pause");
			break;	
		} 
		//fim da seleção do menu
		
	}
	
}

