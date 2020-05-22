//######################################################
//#                                                    #
//# DESENVOLVEDORES:                                   #
//# NOME: Jan Peter Merkel RM:81896                    #
//# NOME: Igor Tomazelli Nietmann RM:82808             #
//# NOME: Rafael Fernandes Cruz Caldeira    RM:82776   #
//#                                                    #
//######################################################

//algumas condicoes tipo frebre de 100 graus e aceita no sistema,precisamos testar - Já corrigiu
//Reparei que dá pra colocar mais de uma UBS com o mesmo nome, e isso buga tudo kkkk -Já corrigi
//Limitar o novel de oxigenação para o maximo ser 100% e o minimo 0% -Já corrigi
//Fazer uma condição pra não poder colocar o paciente num numero q n existe -Corrigido
//COLOCAR O MEDICO Q CUIDA-ja fiz
//coloquei a data de nascimento dos pacientes

#include <iostream>
#include <locale>
#include <cstring>

#define NCAR 30
#define NPAC 200
 using namespace std;
    //declaracao de variaveis

        int i,nPacientes=0,totalUBS=0, nUBS=0,escolha,iPacientes=0, leitoTotal=0,iUBS=0,posicaoAnterior=0,ntotal = 0,posicaoAtual=0;
        char pesquisaCpf[17];
        bool hospitais=false;//variavel que habilita os hospitais


    //declaracao structs

    struct declDadosPaciente{
        char nome[NCAR],cpf[17],localInternacao[NCAR],medicoResponsavel[NCAR], anoNasc[11];
        string status;
    };

    struct declDadosUnidadeMedica{
        char nome[NCAR],telefone[NCAR];
        int nLeitos;
    };

    typedef struct declDadosPaciente dadosPaciente;
    typedef struct declDadosUnidadeMedica dadosUMedica;

    dadosPaciente pacientes[NPAC];
    dadosUMedica  umed[NPAC];
    //o paciente podera escolher onde ficará.



    /////end structs



    //declaracao de funcoes

    void menu(){
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\n selecione o que deseja fazer:\n\n"<<endl;
    cout<<"\t 1.para cadastrar unidade de saúde     4.para alterar o status de um paciente\n"<<endl;
    cout<<"\t 2.para cadastrar paciente             5.para sair do programa\n"<<endl;
    cout<<"\t 3.consulta de paciente por cpf\n"<<endl;
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"digite o número de uma opção:\n\n"<<endl;
    };


    //
    //status paciente
    //ela funciona com um indice de 0 ate 100 sendo 100 o mais grave possível
    //
    string statuspac(){

      float temperatura,Oxigenacao;
      int total=0;
      char resposta;

      cout<<"\n\n\n ======= Questionario ========= \n\n\n";
      cout<<"Digite a temperatura do paciente"<<endl;

      cin>>temperatura;
      while(temperatura<20 || temperatura>42){
        cout<<"\nTemperatura inválida!"<<endl;
        cout<<"\n\Digite a temperatura novamente: "<<endl;
        cin>>temperatura;
      }
      if(temperatura>=38){
            total=total+10;
            cout<<"\nAnotado...\n"<<endl;
      }

      cout<<"\nTem dificuldades para respirar? [s/n]\n"<<endl;
      cin>>resposta;

      if(resposta=='s' || resposta=='S'){
        total= total+30;
        cout<<"\nAnotado...\n"<<endl;
      }
      else{
        cout<<"\n\nOk...\n\n"<<endl;
      };
      cout<<"\nDigite a Oxigenacao do sangue (em %): "<<endl;
      cin>>Oxigenacao;
      while(Oxigenacao<=0||Oxigenacao>100){
        cout<<"\nNivel de oxigenação invalido, por favor insira novamente: "<<endl;
        cin>>Oxigenacao;
      }

      if(Oxigenacao<=90 && Oxigenacao>70){
            total = total+20;
      }
      else if(Oxigenacao<=70){
            total = total+30;
      }

      cout<<"\nApresenta sintomas de insuficiência renal[s/n]: "<<endl;
      cin>>resposta;

      if(resposta=='s'||resposta=='S'){
        total =total+30;
        cout<<"\nAnotado...\n"<<endl;
      }

      else{
      }

      if (total>=40){
            return "Internado";
      }

      else if(total>=10&&total<40){
            return "Em Observacao";

      }

       else if(total<10){
            return "Liberado";

       }


    }

//COMECO DO PROGRAMA
int main()
{
    bool loop=0;
    setlocale(LC_ALL,"");
    //intro
    cout<<"\t\t\t*********\t\t\t"<<endl;
    cout<<"\t\t\t*********\t\t\t"<<endl;
    cout<<"\t\t\t*********\t\t\t"<<endl;
    cout<<"\t\t   *******************\t\t\t"<<endl;
    cout<<"\t\t   *******************\t\t\t"<<endl;
    cout<<"\t\t   *******************\t\t\t"<<endl;
    cout<<"\t\t   *******************\t\t\t"<<endl;
    cout<<"\t\t\t*********\t\t\t"<<endl;
    cout<<"\t\t\t*********\t\t\t"<<endl;
    cout<<"\t\t\t*********\t\t\t"<<endl;
    //
    //
    //
    //
    //chamando o menu
    //
    do{
    menu();
    //
    //
    //
    //
    // aqui acontece a escolha do item do menu
    //
    cin>>escolha;
    cin.ignore();
    if(escolha==1){
        //hablitiando o cadastro de pacientes
        hospitais = true;
        cout<<"\nQuantas UBS deseja cadastrar? \n\n"<<endl;
        cin>>nUBS;
        totalUBS =totalUBS+nUBS;
        cin.ignore();
        //loop que passa pelo total de UBS
        for(iUBS;iUBS<totalUBS;iUBS++){
            //
            char cmp[NCAR];
            int i2;
            cout<<"\nDigite o nome da unidade médica: "<<endl;
            cin.getline(cmp, NCAR);
            //cout<<"cmp: "<<cmp<<endl;
            //verifica se já há uma unidade com o nome registrado
            for(i2=0;i2<totalUBS;i2++){
                    while((strcmp(umed[i2].nome, cmp)==0) && (i2!=iUBS)){
                    //cout<<"i2: "<<i2<<endl;
                    //cout<<"iUBS: "<<iUBS<<endl;
                    cout<<"\nJá há uma unidade com este nome, tente novamente: "<<endl;
                    cin.getline(cmp,NCAR);
                    }
            }
            strcpy(umed[iUBS].nome, cmp);
            //cout<<"umed[iubs].nome: "<<umed[iUBS].nome<<endl;

            cout<<"\nDigite o telefone da unidade médica: "<<endl;
            cin.getline(umed[iUBS].telefone,NCAR);
            cout<<"\nDigite o número de leitos disponíveis: "<<endl;
            cin>>umed[iUBS].nLeitos;
            leitoTotal=(leitoTotal + umed[iUBS].nLeitos);
            cin.ignore();
            cout<<"----------------------------------------------"<<endl;
        }
        cout<<"\nNumero total de leitos disponiveis: "<<leitoTotal<<endl;
    }
    //
    //end cadastro UBS

    //
    //cadastro de pacientes
    //
    else if(escolha==2){
        //habilitacao dos hospitais caso contrario nao e possivel colocar pacientes.
        //se o n de leitos for zero os hospitais sao impossibilitados de receber pacientes.


        if(leitoTotal==0){
        hospitais=false;
        }
        else{
            hospitais=true;
        };

        if(hospitais==true){
        cout<<"Quantos pacientes deseja cadastrar?\n\n "<<endl;
        cin>>nPacientes;
        cin.ignore();

        //compara o numero de pacientes aos leitos disponiveis antes de executar algo
        if(nPacientes<=leitoTotal){
        ntotal = ntotal+nPacientes;

        for(iPacientes;iPacientes<ntotal;iPacientes++){
            cout<<"\nDigite o nome do paciente:"<<endl;
            cin.getline(pacientes[iPacientes].nome,NCAR);
            cout<<"\nDigite a data de nascimento do paciente: "<<endl;
            cin.getline(pacientes[iPacientes].anoNasc, 11);
            //cin.ignore();
            cout<<"\nDigite o cpf do paciente:"<<endl;
            cin.getline(pacientes[iPacientes].cpf,17);
            cout<<"\nDigite o nome do Médico responsável: \n"<<endl;
            cin.getline(pacientes[iPacientes].medicoResponsavel,NCAR);

            //status
            cout<<"\n\n Para o status iremos a um questionário!"<<endl;
                string status;
                status = statuspac();
                cout<<"\n\n --------------  Condição do Paciente  --------------"<<endl;
                cout<<"| "<<status<<"                                          |"<<endl;
                cout<<" ----------------------------------------------------\n"<<endl;
                pacientes[iPacientes].status = status;
            //Ex1Funcoes ERA AQUI Q ACHO Q TUNHA APAGADO O COMENTARIO Q N DEVIA pelo visto n ferrou nada mas é bom dar uma olhada
            //bloco de codigo que vai procurar uma ubs com leitos disponiveis

            if(pacientes[iPacientes].status=="Internado" || pacientes[iPacientes].status=="Em Observacao"){

                cout<<"\n\n+++++++ Selecione a UBS: +++++++\n\n"<<endl;
                int pesquisaUBS=0;

                //busca das ubs disponíveis

                for(pesquisaUBS;pesquisaUBS<totalUBS;pesquisaUBS++){
                    cout<<"NOME INSTITUIÇÃO ["<<pesquisaUBS+1<<"]: "<<umed[pesquisaUBS].nome<<"\nLEITOS DISPONÍVEIS: "<<umed[pesquisaUBS].nLeitos<<endl;
                }
                int atribuicao=0;
                do{
                 if(umed[atribuicao].nLeitos==-1){
                     cout<<"\n\nERRO: Local de internação inválido!\n\n"<<endl;
                }
                cout<<"\n\n Selecione o número da UBS: "<<endl;
                cin>>pesquisaUBS;
                atribuicao = pesquisaUBS-1;
                umed[atribuicao].nLeitos--;
                leitoTotal--;

                }while(umed[atribuicao].nLeitos==-1);

                strcpy(pacientes[iPacientes].localInternacao,umed[atribuicao].nome);
                cout<<"\n\n\n----------------------------------------------\n"<<endl;
                cout<<"\n\nLeitos agora: "<<umed[atribuicao].nLeitos;


            }   //end status
                //end pesquisa UBS
            cout<<"\n----------------------------------------------"<<endl;
            cin.ignore();
        }
        }//liga no else
        else{
          cout<<"ERRO: Mais pacientes do que leitos disponíveis!"<<endl;
        }//end if da verificacao de pacientes>leitos

        }

        //end cadastro pacientes

        else{
        cout<<"\n\nERRO: Sem unidades cadastradas ou sem Leitos!\n\n"<<endl;
        }
    }
    //
    //cadastro de ubs
    //

    //
    //busca de cpf
    //
    else if(escolha==3){
        if(nPacientes>0){
            bool achou=0;
            cout<<"\nDigite o cpf que deseja buscar: "<<endl;
            cin.getline(pesquisaCpf, 17);
            //cin.ignore();
            for(i=0;i<ntotal;i++){
                if(strcmp(pesquisaCpf, pacientes[i].cpf)==0){
                    achou =1;
                    cout<<"\n\n\n"<<endl;
                    cout<<"Paciente encontrado!!!\nInformações: \n"<<endl;
                    cout<<"CPF : "<<pacientes[i].cpf<<endl;
                    cout<<"NOME: "<<pacientes[i].nome<<endl;
                    cout<<"STATUS: "<<pacientes[i].status<<endl;
                    cout<<"LOCAL DE INTERNAÇÃO: "<<pacientes[i].localInternacao<<endl;
                    cout<<"MEDICO RESPONSÁVEL: "<<pacientes[i].medicoResponsavel<<endl;
                    cout<<"ANO DE NASCIMENTO: "<<pacientes[i].anoNasc<<endl;
                    cout<<"\n----------------------------------------------\n"<<endl;
                }
            }
            if(achou==0){
                cout<<"\nNada foi encontrado"<<endl;
            }
        }
        else{
            cout<<"\nNão há nenhum paciente registrado!!"<<endl;
        }
    }
    //
    // end busca CPF

    //
    //alteracao de status
    //
    else if(escolha==4){
        cout<<"\nDigite o cpf do paciente que deve ter os seus dados alterados: "<<endl;
        cin.getline(pesquisaCpf, 11);

    if(nPacientes>0){

        for(i=0;i<ntotal;i++){

            if(strcmp(pesquisaCpf, pacientes[i].cpf)==0){
                string statPac;
                cout<<"\nPaciente encontrado!\n Nome: "<<pacientes[i].nome<<endl;
                cout<<"\nFaça o questionario novamente:"<<endl;
                pacientes[i].status = statuspac();
                cout<<"\n\nNovo status do paciente: "<<pacientes[i].status<<endl;

                if(pacientes[i].status=="Liberado"){
                    statPac = pacientes[i].localInternacao;
                    int i2=0;
                    for(i2;i2<ntotal;i2++){
                        if(umed[i2].nome==statPac){
                            umed[i2].nLeitos++;
                        }
                    }
                    leitoTotal++;
                }

                }

            }
        }
        else{
            cout<<"\nNão há nenhum paciente registrado!!"<<endl;
        }
    }
    //
    //end alteracao status

    //
    // sair do programa
    //
    else if(escolha==5){
            loop=1;
    }
    else{
        cout<<"\nOPÇÃO INVALIDA, TENTE NOVAMENTE!!"<<endl;//Programa grosso, grita com os outros
    }
    }while(loop==0);

    return 0;
}

