#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;
const int NUM=26;
void sorteiNum(int n[NUM])
{


    int i=0, j=0, cont_linha=0;


    srand(time(NULL));


    for(i=0; i<NUM; i++)
    {
        n[i] = (rand()%NUM);



        for(j=0; j<i; j++)
        {
            if(n[j] == n[i])
            {
                n[i] = (rand()%NUM);
                j=0;
            }
        }
    }

}

int main()
{
    int i,a,vetor[26];

    string nomeRecebe[26],nomesAleatorios[26];

    fstream arquivoTexto;

    arquivoTexto.open("alunos.txt",ios::in);

    if(!arquivoTexto.is_open())
    {
        cout <<clog<<endl;
    }
    else
    {
        for(i = 0;i<26;i++)
        getline(arquivoTexto,nomeRecebe[i]);
    }
    arquivoTexto.close();

    sorteiNum(vetor);

    for(i=1; i<26; i++ )
        {
            a = vetor[i];
            nomesAleatorios[i] = nomeRecebe[a];
        }


    arquivoTexto.open("sorteio.txt",ios::out|ios::app);

    if(!arquivoTexto.is_open())
    {
        cout <<clog<<endl;
        system("pause");
        exit(1);
    }else{
        for(int k=1;k<=26;k++){

            if (k==1){
                arquivoTexto <<"========" <<endl;
                arquivoTexto << "Grupo 1:" <<endl;
                arquivoTexto << nomesAleatorios[k]<<endl;
            }else if((26-k)<1){
            arquivoTexto << nomesAleatorios[k]<<endl;
            break;
            }else if(k%5==0&&(26-k)>4){
                arquivoTexto << nomesAleatorios[k]<<endl;
                arquivoTexto <<"========="<<endl;
                arquivoTexto << "Grupo" << ((k/5)+1) <<":"<<endl;
            }else{
            arquivoTexto << nomesAleatorios[k]<<endl;
            }

            //arquivoTexto << nomesAleatorios[k]<<endl;
        }
    }
    arquivoTexto.close();

    return 0;
}

/*
int k=1;
for(k=1;k<=26;k++){
    if(k%5==0){
        st << "========";
        st << "Grupo " << k/5 << ":" << endl;
    }else if(k==1){
     st << "========";
     st << "Grupo 1:" << endl;
    }
    st << nomes[k] << endl;
    */
