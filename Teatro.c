/* Participantes:
   -Guilherme Gonçalves Dutra de Mendonça
   -Hugo Moreno I Veiga Jardim
   -Vitor Martins Castanheira
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{       //Struct que agrupa as variaveis de cada ingresso
		char nome[50];
		char fone[20];
		char email[50];
		float valor;
		int status;
		
	}ingresso;
typedef struct{     //Struct que agrupa as variaveis do teatro inicializado 
		ingresso ingressos[22][15];
		char peca[60];
		char data[11];
		char horario[10];	
		int pessoas;
	}teatro;
	
//Neste ponto, abrimos o arquivo referente a uma sessão de teatro:	
void criar_arq (teatro t) {   // sem a struct...
   FILE *fp;  
 
   fp = fopen ("Teatro.dat", "wb"); //arquivo para escrita binária
   if (fp == NULL) {  
      printf ("Erro ao abrir o arquivo.\n");  
      return;  
   }  
   else {  
           printf ("Arquivo Binario criado com sucesso.\n");  
          fwrite(&t, sizeof(teatro), 1, fp); 
          }         
     fclose (fp);  
       
}/*Função reponsavel por exibir o conteudo do arquivo Binario.dat*/
	
	
/* Neste ponto o usuário seleciona a cadeira desejada para compra, e são inseridas
as informações pessoais de tal, se disponível, a compra é efetuada: */	
void comprar(teatro *t){  
	
	ingresso x;
	int op;
	int tipo;
	int f, c;
	float valor;
	do{
	    system("cls");
	    printf("\nNome: ");
	    fgets(x.nome, 50, stdin);
	    printf("\nTelefone: ");
	    fgets(x.fone, 32, stdin);
        printf("\nEmail:");
	    fgets(x.email, 50, stdin);
	    printf("Escolha uma cadeira:       (22 fileiras e 15 cadeiras)\n");
	    printf("Fileira:");
	    scanf("%d", &f);
	    printf("Cadeira:");
	    scanf("%d", &c);
	    getchar();
	    if(t->ingressos[f][c].status==1 || t->ingressos[f][c].status==2){
		    printf("\nEssa Cadeira esta ocupada!\n");
	    }
	    else{
	        printf("\nDigite 1 se deseja pagar meia (R$ 15)\n");
	        printf("Digite 2 se deseja pagar inteira (R$ 30)\n");
	        scanf("%d", &tipo); 
	        if(tipo==1){
		        printf("Voce optou pela meia\n");
		        valor = 15;
	        }
	        else{
		        printf("Voce optou pela inteira\n");
		        valor = 30;
	        }
	        x.valor = valor;
	        x.status = 1;
	        t->ingressos[f][c] = x;
	    }
	    printf("\n1- Continuar comprando\n");
	    printf("0- Sair\n");
	    scanf("%d", &op);
	    getchar();
	
	}while(op!=0);
	
}
//Aqui, quando selelecionado pelo usuário a opção de reservar assento, serão inseridas as informações necessárias:
void reservar(teatro *t){ 
	
	ingresso x;
	int op;
	int f, c;
	
	do{
	    system("cls");
    	printf("\nNome: ");
    	fgets(x.nome, 50, stdin);
    	printf("\nTelefone: ");
    	fgets(x.fone, 20, stdin);
        printf("\nEmail:");
    	fgets(x.email, 50, stdin);
        printf("Escolha a cadeira que deseja reservar:       (22 fileiras e 15 cadeiras)\n");
	    printf("Fileira:");
	    scanf("%d", &f);
	    printf("Cadeira:");
	    scanf("%d", &c);
	    getchar();
	    if(t->ingressos[f][c].status==1 || t->ingressos[f][c].status==2){
		    printf("\nEssa Cadeira esta ocupada!\n");
	    }
	    else{
		    printf("Reserva feita com sucesso!\n");
	        x.status = 2;
	        t->ingressos[f][c] = x;
	    }
	    printf("\n1- Continuar reservando\n");
	    printf("0- Sair\n");
	    scanf("%d", &op);
	    getchar();
	
	}while(op!=0);
	
}
//Aqui são impressas as informções gerais de disponibilidade dos assentos do teatro:
void listar(teatro *t){  
	int i, j, op;
	
	system("cls");
	printf("====================PALCO======================\n\n");
		
    for(i=0;i<22;i++){
    	printf("%2d| ", i+1);
	    for(j=0;j<15;j++){
	     		
		    if(t->ingressos[i+1][j+1].status==1){
				printf("O  ");
			}
			else if(t->ingressos[i+1][j+1].status==2){
				printf("R  ");
			}
			else{
			    printf("L  ");	
			}
	    }
	printf("\n");
    }
    printf("------------------------------------------------\n");
    printf("    1  2  3  4  5  6  7  8  9  10 11 12 13 14 15\n");
	printf("\nEnter para continuar\n");
	getchar();
		
}
//Aqui o usuário consulta as informações do assento específico desejado:
void consultar(teatro *t){  
	
	int f, c, op;
	do{
	    system("cls");
    	printf("Escolha a cadeira que deseja consultar:\n\n");
    	printf("Fileira:");
    	scanf("%d", &f);
    	printf("Cadeira:");
    	scanf("%d", &c);
	
	    if(t->ingressos[f][c].status==1){
		    printf("=========================================");
	    	printf("\nNome: %s\n", t->ingressos[f][c].nome);
	    	printf("Telefone: %s\n", t->ingressos[f][c].fone);
	    	printf("Email: %s\n\n", t->ingressos[f][c].email);
	    	printf("VALOR: %.2f reais", t->ingressos[f][c].valor);
	    	if(t->ingressos[f][c].valor == 15){
			    printf("    (MEIA)");
		    }
		    else{
			    printf("    (INTEIRA)");
		    }
		    printf("    Fileira: %d  Cadeira: %d\n\n", f, c);
		    printf("Peca: %s%s%s\n", t->peca, t->data, t->horario);
		    printf("=========================================\n");
	    }
	    else if(t->ingressos[f][c].status==2){
		    printf("=========================================");
	    	printf("\nNome: %s\n", t->ingressos[f][c].nome);
	    	printf("Telefone: %s\n", t->ingressos[f][c].fone);
	    	printf("Email: %s\n\n", t->ingressos[f][c].email);
	    	printf("RESERVADO");
	    	printf("    Fileira: %d  Cadeira: %d\n\n", f, c);
	    	printf("Peca: %s%s%s\n", t->peca, t->data, t->horario);
	        printf("=========================================\n");
        }
	    else{
		    printf("\n=========================================");
	    	printf("\nEssa Cadeira esta livre!\n");
	    	printf("=========================================\n\n");
	    }
	    printf("1- Continuar consultando\n");
	    printf("0- Sair\n");
	    scanf("%d", &op);
	    getchar();
	}while(op!=0);
}
//Aqui, o usuário pode cancelar uma reserva de assento feita anteriormente:
void cancelar(teatro *t){ 
	int op, f, c;
	do{
    	system("cls");
    	printf("Selecione a cadeira de sua reserva:\n\n");
    	printf("Fileira:");
        scanf("%d", &f);
    	printf("Cadeira:");
    	scanf("%d", &c);
	
    	t->ingressos[f][c].status = 0;
    	printf("\n\nReserva cancelada com sucesso!\n\n");
	
        printf("1- Continuar consultando\n");
    	printf("0- Sair\n");
    	scanf("%d", &op);
    	getchar();
	}while(op!=0);
}
//Neste ponto temos a função que calcula a arrecadação parcial da peça:
void arrecadado(teatro *t){  
	int i, j, meias=0, inteiras=0, op;
	float total;
	
	do{
	    system("cls");
    	for(i=0;i<22;i++){
	    	for(j=0;j<15;j++){
		        if(t->ingressos[i+1][j+1].valor==15){
			        meias++;
		        }
		        else if(t->ingressos[i+1][j+1].valor==30){
				    inteiras++;
			    }  	
		    }
	    }
    	printf("Foram vendidas %d inteiras\n", inteiras);
    	printf("Foram vendidas %d meias\n\n", meias);
    	total = (float)15*meias + 30*inteiras;
	
    	printf("Total arrecadado ate o momento: %.2f reais\n\n", total);
	
    	printf("0- Sair\n");
    	scanf("%d", &op);
	}while(op!=0);
}
//Aqui temos as opções concedidas pelo menu:
void menu(){  
	
		system("cls");
		printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
	    printf("1- Comprar ingresso\n");
	    printf("2- Reservar ingresso\n");
	    printf("3- Lista de cadeiras ocupadas\n");
        printf("4- Consultar cadeira\n");
        printf("5- Cancelar reserva\n");
        printf("6- Total arrecadado\n");
    	printf("0- Sair\n");
        printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
}
//Função que inicia e guarda as informações sobre o teatro
void iniciar_teatro(teatro *t){  
	int i, j;
	
	for(i=0;i<22;i++){
		for(j=0;j<15;j++){
			t->ingressos[i][j].status = 0;
		}
	}
	printf("Nome da peca: ");
	fgets(t->peca, 60, stdin);
	printf("\nEntre com a data: ");
	fgets(t->data, 11, stdin);
	printf("\nEntre com o horario: ");
	fgets(t->horario, 6, stdin);
	t->pessoas = 0;
}
void Carregar_Teatro(teatro *t){  //Função que carrega um teatro previamente inicializado
     FILE *fp;
    
     fp = fopen ("Teatro.dat", "rb"); 
      if (fp == NULL) {  
		  iniciar_teatro(&(*t));
		return;
}  else {
          fread(&(*t),sizeof(teatro),1,fp);
          fclose(fp);
         }  
}
int main () {
	int op;
	teatro t;
	Carregar_Teatro(&t);
	
	//Aqui vemos o menu inicial:
	do{
    	menu();
        scanf("%d", &op);           //Escaneia a opção 
    	getchar();
    	switch(op){                //Chama determinada função de acordo com a opção escolhida
    	    	case 1:
    	     	    comprar(&t);
		    	break;
			
		    	case 2:
			    	reservar(&t);
		    	break;	
			
		    	case 3:
		    		listar(&t);
		    	break;
			
		    	case 4:
		     	    consultar(&t);
		    	break;	
			
		    	case 5:
		    	    cancelar(&t);
		    	break;
			
		    	case 6:
		    	    arrecadado(&t);
		    	break;						
		}
	}while(op!=0);
	
	system("cls");
	printf("OBRIGADO POR USAR NOSSO PROGRAMA\n\n");
	criar_arq(t);     //Finaliza o programa e cria o arquivo binário
	    

	return 0;
}
