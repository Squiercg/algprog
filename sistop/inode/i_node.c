#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TAMANHO_BLOCO 4096

void imprime_string(char* arg) {
	printf("\n***** \n %s \n*****\n", arg);
}

void imprime_char(char arg) {
	printf("\n***** \n %c \n*****\n", arg);
}

void imprime_int(int arg) {
	printf("\n***** \n %d \n*****\n", arg);
}

void cria_nome(char *nome_final, const char *prefixo, int numero, const char *extensao) {
	char numero_i_node_char[10];
	sprintf(numero_i_node_char,"%d", numero);

	strcpy(nome_final, prefixo);
	strcat(nome_final, numero_i_node_char);
	strcat(nome_final, extensao);
}

char tipo_i_inode(char *nome_diruivo_bloco, FILE *fp_bloco, int numero_i_node, char *nome_diruivo_diretorio){
	char saida;
	saida= 'a';

	fp_bloco = fopen(nome_diruivo_bloco, "r");
	while(fscanf(fp_bloco, "%d,%s", &numero_i_node, nome_diruivo_diretorio) != EOF) {
		printf("%s\n", nome_diruivo_diretorio);
	}
	fclose(fp_bloco);

	return saida;
}

int main(int argc, char const *argv[])
{
	FILE *fp_i_node, *fp_bloco, *fp_i_node_more;
	int tamanho_em_bytes, bloco, linhas_i_node, i, i_node_atual = 0, encontrou, inode_arquivo, numero_bloco,numero_i_node;
	char diretorio_ou_arquivo, terminal[100], nome_arquivo_i_node[50],nome_diruivo_bloco[50],nome_diruivo_diretorio[50], aux, linha_bloco[50];


	do {
		cria_nome(nome_arquivo_i_node, "i_node_", i_node_atual, ".txt");

		printf("$ ");
		scanf("%s", terminal);		

		if(strcmp(terminal, "exit") != 0) {
			if(strcmp(terminal, "ls") == 0) {
				/* Abre o arquivo que representa o i_node */
				fp_i_node = fopen(nome_arquivo_i_node, "r");

				/* Lê no i-node o tamanho em bytes do arquivo */
				fscanf(fp_i_node, "%d\n", &tamanho_em_bytes);
				/* Lê a meta-informação que define se o i_node é de arquivo ou diretório */
				fscanf(fp_i_node, "%c\n", &diretorio_ou_arquivo);

				/* Calcula a quantidade de linhas do i_node com base no tamanho do arquivo e o tamanho do bloco de disco */
				linhas_i_node = ceil((float)tamanho_em_bytes/TAMANHO_BLOCO);

				/* Lê os endereços de disco de cada bloco do i_node */
				for(i = 0 ; i < linhas_i_node ; i++) {
					 
					/* Lê o número do bloco no i_node*/
					fscanf(fp_i_node, "%d", &numero_bloco);
					cria_nome(nome_diruivo_bloco, "bloco_", numero_bloco, ".txt");

					fp_bloco = fopen(nome_diruivo_bloco, "r");
					
					/* Lê as entradas de diretório contidas no bloco i */
					while(fscanf(fp_bloco, "%d,%s", &numero_i_node, nome_diruivo_diretorio) != EOF) {
						printf("%s\n", nome_diruivo_diretorio);
					}
					fclose(fp_bloco);
				}
				fclose(fp_i_node);
			}
			else if(strcmp(terminal, "cd") == 0) {
				encontrou = 0;
				char nome_dir[50];

				/* Nome do diretório que acessarei */
				scanf("%s", nome_dir);

				fp_i_node = fopen(nome_arquivo_i_node, "r");

				fscanf(fp_i_node, "%d\n", &tamanho_em_bytes);
				fscanf(fp_i_node, "%c\n", &diretorio_ou_arquivo);
			
				linhas_i_node = ceil((float)tamanho_em_bytes/TAMANHO_BLOCO);

				for(i = 0 ; i < linhas_i_node ; i++) {
					char nome_diruivo_bloco[50]; 
					char nome_diruivo_diretorio[20];
					int numero_bloco;
					int numero_i_node;
					
					fscanf(fp_i_node, "%d", &numero_bloco);

					cria_nome(nome_diruivo_bloco, "bloco_", numero_bloco, ".txt");

					fp_bloco = fopen(nome_diruivo_bloco, "r");
					
					while(fscanf(fp_bloco, "%d,%s", &numero_i_node, nome_diruivo_diretorio) != EOF && encontrou == 0) {
						if(strcmp(nome_diruivo_diretorio, nome_dir) == 0) {
							encontrou = 1;
							i_node_atual = numero_i_node;
						}
					}

					if(encontrou == 0) {
						printf("Diretorio '%s' não encontrado!\n", nome_dir);
					}
					fclose(fp_bloco);
				}
				fclose(fp_i_node);
			}
			else if(strcmp(terminal, "clear") == 0) {
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			}
			else if(strcmp(terminal, "more") == 0) {
				char nome_dir[50];
				scanf("%s", nome_dir);

				/*Abrindo arquivo inode atual, que vai ser um diretorio*/				
				fp_i_node = fopen(nome_arquivo_i_node, "r");

				/*Lendo as linhas de meta_informação*/
				fscanf(fp_i_node, "%d\n", &tamanho_em_bytes);
				fscanf(fp_i_node, "%c\n", &diretorio_ou_arquivo);

				/*Pegando o bloco apontado*/
				fscanf(fp_i_node, "%d", &numero_bloco);
				/*Eu vou para este bloco, a  meta informação ja foi lida ali em cima*/
				cria_nome(nome_diruivo_bloco, "bloco_", numero_bloco, ".txt");
				fp_bloco = fopen(nome_diruivo_bloco, "r");

				/*Assumimos que o arquivo não existe*/
				encontrou=0;
				/*Primeiro vamos procurar linha a linha do bloco o arquivo desejado*/
				while(fscanf(fp_bloco, "%d,%s", &numero_i_node, linha_bloco) != EOF) {
					/*Se a gente achar, preciamos do inode do arquivo, lembrando que num diretorio não pode repetir nome,
					logo esse if so vai entrar uma vez*/
					if(strcmp(linha_bloco, nome_dir) == 0) {
						/*Abrimos ele*/
						cria_nome(nome_arquivo_i_node, "i_node_", numero_i_node, ".txt");
						fp_i_node_more = fopen(nome_arquivo_i_node, "r");
						fscanf(fp_i_node_more, "%d", &tamanho_em_bytes);
						fscanf(fp_i_node_more, " %c", &diretorio_ou_arquivo);
						/*Verificamos se é um arquivo, pela metainformação do inode*/
						if(diretorio_ou_arquivo == 'a'){
							encontrou = 1;
							/*Anotamos o número*/
							inode_arquivo = numero_i_node;
							}
							fclose(fp_i_node_more);
						}
					}
				fclose(fp_bloco);
				


				if(encontrou == 1) {
					/*Como nos encontramos, precisamos abrir o inode do arquivo*/
					cria_nome(nome_arquivo_i_node, "i_node_", inode_arquivo, ".txt");
					fp_i_node_more = fopen(nome_arquivo_i_node, "r");
					fscanf(fp_i_node_more, "%d\n", &tamanho_em_bytes);
					fscanf(fp_i_node_more, "%c\n", &diretorio_ou_arquivo);				
					linhas_i_node = ceil((float)tamanho_em_bytes/TAMANHO_BLOCO);
					//printf("Linhas: %d\n",linhas_i_node);

					/*e para cada linha desse inode que é de arquivo, imprimir o conteudo do bloco dele*/
					for(i = 0 ; i < linhas_i_node ; i++) {												
						fscanf(fp_i_node_more, "%d", &numero_bloco);
						cria_nome(nome_diruivo_bloco, "bloco_", numero_bloco, ".txt");
						fp_bloco = fopen(nome_diruivo_bloco, "r");
						while (fscanf(fp_bloco, "%c", &aux) != EOF){
							printf("%c", aux);
						}
						fclose(fp_bloco);
					}					
					fclose (fp_i_node_more);
				} else {
					printf("Arquivo não encontrado.\n");
				}
				fclose(fp_i_node);				
		    }
		}
	} while(strcmp(terminal, "exit") != 0);
	
	return 0;
}