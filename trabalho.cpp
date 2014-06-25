        #include "stdio.h"
        #include "stdlib.h"
        #include "conio.h"
        #include "string.h"
        #include "time.h"
        
        #define max 11
        
        struct jogador
        {
               char nome[20], posicao [20], equipe[10];
               int numero, cansaco, habilidade;
        };
         
        int main(int argc, char *argv[]){
            
            int gol, bat, aux, i, j, sg1 = 0, sg2 = 0;
            jogador novo[max][2];
            
            printf("\t\t Simulacao de penalts\n\n\n");
        
            for(j=0; j<2; j++){
                     printf ("Entre com o nome da %d%c equipe:",j+1,167);
                     gets(novo[0][j].equipe);
                     printf ("\nEntre com os dados dos jogadores do ");
                     puts(novo[0][j].equipe);
                     printf ("\nDigite o nome do goleiro: ");
                     gets(novo[0][j].nome);
                     strcpy(novo[0][j].posicao, "goleiro");
                     printf("\nDigite o numero da camisa do goleiro: ");
                     scanf("%d",&novo[0][j].numero);
                     printf("\nDigite o nivel de cansaco do goleiro em uma escala de 0 a 10: ");
                     scanf("%d",&novo[0][j].cansaco);
                     printf("\nDigite a habilidade do goleiro em uma escala de 0 a 10: ");
                     scanf("%d",&novo[0][j].habilidade);
                     system ("cls");
                     getchar();
                    
                     for(i=1; i<max; i++){
                     aux = max;
                      do{
                         printf("\nDigite o nome do %d%c batedor: ", i, 167);
                         gets(novo[i][j].nome);
                         printf("\nDigite a posicao do jogador: ");
                         gets(novo[i][j].posicao);
                         //compara a posição do jogador com a do goleiro, se forem igual ele retorna
                         // 0, então retorna uma mensagem dizendo que o goleiro ja esta cadastrado.
                         aux = strcmp(novo[0][j].posicao, novo[i][j].posicao);
                         
                         if(aux == 0)
                         printf("\nO goleiro ja esta cadastrado!\n");
                       } while (aux == 0);
                      
                       // cadastra os demais jogadores
                       printf("\nDigite o numero da camisa do %d%c batedor: ", i, 167);
                       scanf("%d",&novo[i][j].numero) ;
                       printf("\nDigite o nivel de cansaco do jogador em uma escala de 0 a 10: ");
                       scanf("%d",&novo[i][j].cansaco);
                       printf("\nDigite o nivel de  habilidade do jogador em uma escala de 0 a 10: ");
                       scanf("%d",&novo[i][j].habilidade); 
                       getchar();  
                       strcpy(novo[i][j].equipe, novo[0][j].equipe);
                       system ("cls");
                     }  
                     
                }
                
                
                // simula os penalts das equipes
                printf("\t\t\tBatidas de penaltis\n ");
                srand( (unsigned)time(NULL) );
              for(i=1;i<=5;i++){
                     printf("\n\n%d%c penalidade da equipe do ",i, 167);
                     puts(novo[0][0].equipe);
                     printf("\n");
                     printf("Batedor: ");
                     puts(novo[i][0].nome);
                     printf(" x \n");
                     printf("Goleiro: ");
                     puts(novo[0][1].nome);
                     aux = rand()%10;                     
                     bat = novo[i][0].habilidade + aux - novo[i][0].cansaco;
                     aux = rand()%10;
                     gol = novo[0][1].habilidade + aux - novo[0][1].cansaco;
                     getchar();
                                 
                     if(bat>gol){
                                printf("\nGOOOOLLLLLLLLL\n");
                                sg1 ++;
                                }
                                
                     else if(bat<gol){
                                printf("\nDEFENDEUUUU O GOLEIROOOO, QUE BELA DEFESA...\n");
                                }
                     else{
                                printf("\nPRAAA FORAAAAAAA\n");
                                }
                     printf("\nPlacar do jogo: %d X %d\n\n",sg1, sg2);
                                
        getchar();
        system("cls");
                     
                     printf("\n\n%d%c penalidade da equipe do ",i, 167);
                     puts(novo[0][1].equipe);
                     printf("\n");
                     printf("Batedor: ");
                     puts(novo[i][1].nome);
                     printf(" x \n");
                     printf("Goleiro: ");
                     puts(novo[0][0].nome);
                     aux = rand()%10;                       
                     bat = novo[i][1].habilidade + aux - novo[i][1].cansaco;
                     aux = rand()%10;
                     gol = novo[0][0].habilidade + aux - novo[0][0].cansaco;
                     getchar();
                     
                     if(bat>gol){
                                printf("\nGOOOOLLLLLLLLL\n");
                                sg2 ++;
                                }
                                
                     else if(bat<gol){
                                printf("\nDEFENDEUUUU O GOLEIROOOO, QUE BELA DEFESA...\n");
                                }
                    else{
                                printf("\nPRAAA FORAAAAAAA\n");
                                }       
                 printf("\nPlacar do jogo: %d X %d\n\n",sg1, sg2);
                 
        getchar();
        system("cls");                                                        
        
                }
               
                if(sg1>sg2){
                           printf("\nE o time do ");
                           puts(novo[0][0].equipe);
                           printf(" vence a disputa de penalidades!!\n");
                          
                           }
                           
                else if(sg1<sg2){ 
                           printf("\nE o time do ");
                           puts(novo[0][1].equipe);
                           printf(" vence a disputa de penalidades!!\n");             
                           
                     }
                     
              //quando o empate persistir as cobranças seguem uma a uma
                else{
                    
                     i=6;
                     j=10;
                     printf("\nO jogo continua empatado, a torcida esta aflita com o resultado\nA disputa agora segue nas cobranças uma a uma!\n");
                     do{
                     printf("\n\n%d%c panalidade da equipe do ",i, 167);
                     puts(novo[0][0].equipe);
                     printf("\n");
                     printf("Batedor: ");
                     puts(novo[j][0].nome);
                     printf(" x \n");
                     printf("Goleiro: ");
                     puts(novo[0][1].nome);
                     aux = rand()%10;
                     bat = novo[j][0].habilidade + aux - novo[j][0].cansaco;
                     aux = rand()%10;
                     gol = novo[0][1].habilidade + aux - novo[0][1].cansaco;
                     getchar();
                     
                     if(bat>gol){
                                sg1 ++;
                                printf("\nGOOOOLLLLLLLLL\n");
                                }
                     else if(bat<gol){
                                printf("\nDEFENDEUUUU O GOLEIROOOO, QUE BELA DEFESA...\n");
                                }
                     else{
                                printf("\nPRAAA FORAAAAAAA\n");
                                }
                                
                     printf("\nPlacar do jogo: %d X %d\n\n",sg1, sg2);
                     
        getchar();
        system("cls");
                     
                     printf("\n\n%d%c penalidade da equipe do ",i, 167);
                     puts(novo[0][1].equipe);
                     printf("\n");
                     printf("Batedor: ");
                     puts(novo[j][1].nome);
                     printf(" x \n");
                     printf("Goleiro: ");
                     puts(novo[0][0].nome);
                     aux = rand()%10;
                     bat = novo[j][1].habilidade+aux-novo[j][1].cansaco;
                     aux = rand()%10;
                     gol = novo[0][0].habilidade+aux-novo[0][0].cansaco;
                     getchar();
                     
                     if(bat>gol){
                                printf("\nGOOOOLLLLLLLLL\n");
                                sg2 ++;
                                }
                     else if(bat<gol)
                                printf("\nDEFENDEUUUU O GOLEIROOOO, QUE BELA DEFESA...\n");
                    else
                                printf("\nPRAAA FORAAAAAAA\n");
                                
                    printf("\nPlacar do jogo: %d X %d\n\n",sg1, sg2);
                    
        getchar();
        system("cls");
        
                     i ++;
                     j ++;
                     
                     if(j==12){
                             j=1;
                             }
                     
                     
                     }while(sg1==sg2);
                       
                if(sg1>sg2){
                           printf("\nE o time do ");
                           puts(novo[0][0].equipe);
                           printf(" vence a disputa de penalidades!!\n");
                           }
                else { 
                           printf("\nE o time do ");
                           puts(novo[0][1].equipe);
                           printf(" vence a disputa de penalidades!!\n");             
                     }
                }
                     
          system("PAUSE");	
          return 0;
        }
