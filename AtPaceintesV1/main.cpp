//oq falta fazer? o sistema de colocar leitos de volta quando um paciente for curado, nao sei como fazer /to cansado
//algumas condicoes tipo frebre de 100 graus e aceita no sistema,precisamos testar
#include <iostream>
#include <locale>
#include <cstring>

#define NCAR 30
#define NPAC 200
 using namespace std;
    //declaracao de variaveis

        int i,nPacientes=0,totalUBS=0, nUBS=0,escolha,iPacientes=0, leitoTotal=0,iUBS=0,posicaoAnterior=0,ntotal = 0,posicaoAtual=0;
        char pesquisaCpf[17];


    //declaracao structs

    struct declDadosPaciente{
        char nome[NCAR],cpf[17],localInternacao[NCAR],medicoResponsavel[NCAR];
        string status;
        int anoNasc;
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
    cout<<"\t 1.para cadastrar paciente             4.para alterar o status de um paciente\n"<<endl;
    cout<<"\t 2.para cadastrar unidade de saúde     5.para sair do programa\n"<<endl;
    cout<<"\t 3.consulta de paciente por cpf\n"<<endl;
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"digite o número uma opção:\n\n"<<endl;
    };


    //
    //status paciente
    //ela funciona com um indice de 0 ate 100
    //
    string statuspac(){

      float temperatura,Oxigenacao;
      int total;
      char resposta;

      cout<<"\n\n\n ======= Questionario ========= \n\n\n";
      cout<<"digite a temperatura do paciente"<<endl;

      cin>>temperatura;
      if(temperatura>=38){
            total=total+10;
            cout<<"total até agora: "<<total<<endl;
            cout<<"\nanotado...\n"<<endl;
      }

      cout<<"\ntem dificuldades para respirar? [s/n]\n"<<endl;
      cin>>resposta;

      if(resposta=='s' || resposta=='S'){
        total= total+30;
        cout<<"\nanotado...\n"<<endl;
      }
      else{
        cout<<"\n\nok...\n\n"<<endl;
      };


      cout<<"Digite a Oxigenacao do sangue (em %): "<<endl;
      cin>>Oxigenacao;
      if(Oxigenacao<=90 && Oxigenacao>70){
        total = total+20;
      }
      else if(Oxigenacao<=70)
        total = total+30;

      cout<<"\napresenta sintomas de insuficiência renal[s/n]: "<<endl;
      cin>>resposta;

      if(resposta=='s'||resposta=='S'){
        total =total+30;
        cout<<"\nanotado...\n"<<endl;
      }

      else{
        cout<<"\n\ntudo bem, anotado!\n"<<endl;
      }
     cout<<"o resultado foi: \n"<<total<<endl;

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

    //end declaracao funcoes

int main()
{
    bool loop=0;
    setlocale(LC_ALL,"");

    //fazer menu
    //registro de paciente precisa ter questionario
    //consulta por cpf
    //alteração de status
    //sair do programa
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
    //cout<<"\n\n\n ========================================SISTEMA MEDICO=========================================================== \n\n\n"<<endl;
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

    //
    //cadastro de pacientes
    //
    if(escolha==1){
        cout<<"Quantos pacientes deseja cadastrar?\n\n "<<endl;
        cin>>nPacientes;
        cin.ignore();

        ntotal = ntotal+nPacientes;

        for(iPacientes;iPacientes<ntotal;iPacientes++){
            cout<<"\ndigite o nome do paciente:"<<endl;
            cin.getline(pacientes[iPacientes].nome,NCAR);
            cout<<"\ndigite o cpf do paciente:"<<endl;
            cin.getline(pacientes[iPacientes].cpf,17);

            //status
            cout<<"\n\n para o status iremos a um questionário!"<<endl;
                string status;
                status = statuspac();
                cout<<"\n\n"<<status<<endl;
                pacientes[iPacientes].status = status;

        //bloco de codigo que vai procurar uma ubs com leitos disponiveis

            if(pacientes[iPacientes].status=="Internado" || pacientes[iPacientes].status=="Em Observacao"){

                cout<<"\n\n+++++++ Selecione a UBS: +++++++\n\n"<<endl;
                int pesquisaUBS=0;
                for(pesquisaUBS;pesquisaUBS<totalUBS;pesquisaUBS++){
                    cout<<"NOME INSTITUIÇÃO ["<<pesquisaUBS+1<<"]: "<<umed[pesquisaUBS].nome<<"\nLEITOS DISPONÍVEIS: "<<umed[pesquisaUBS].nLeitos<<endl;
                }
                cout<<"\n\n Selecione o número da UBS: "<<endl;
                int atribuicao=0;
                cin>>pesquisaUBS;
                atribuicao = pesquisaUBS-1;
                umed[atribuicao].nLeitos-1;
                leitoTotal-1;
                strcpy(pacientes[iPacientes].localInternacao,umed[atribuicao].nome);


            }
                //end pesquisa UBS
            cout<<"\n----------------------------------------------"<<endl;
            cin.ignore();
            //questionario status
            //indice do paciente: cout<<"\n\nipacientes "<<iPacientes<<endl;
        }
        //end cadastro pacientes

    }
    //
    //cadastro de ubs
    //
    else if(escolha==2){

        cout<<"\nQuantas UBS deseja cadastrar? \n\n"<<endl;
        cin>>nUBS;
        totalUBS =totalUBS+nUBS;
        cin.ignore();

        for(iUBS;iUBS<totalUBS;iUBS++){
            cout<<"\nDigite o nome da unidade médica: "<<endl;
            cin.getline(umed[iUBS].nome,NCAR);
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
    //busca de cpf
    //
    else if(escolha==3){
        if(nPacientes>0){
            cout<<"\nDigite o cpf que deseja buscar: "<<endl;
            cin.getline(pesquisaCpf, 17);
            //cin.ignore();
            for(i=0;i<ntotal;i++){
                if(strcmp(pesquisaCpf, pacientes[i].cpf)==0){
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
        }
        else{
            cout<<"\nNão há nenhum paciente registrado!!"<<endl;
        }
    }
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
                }

            }
        }
        else{
            cout<<"\nNão há nenhum paciente registrado!!"<<endl;
        }
    }

    //
    // sair do programa
    //
    else if(escolha==5){
            loop=1;
    }
    else{
        cout<<"\nOPÇÃO INVALIDA, TENTE NOVAMENTE!!"<<endl;
    }
    }while(loop==0);

    return 0;
}
//FEIJAO DOCE
