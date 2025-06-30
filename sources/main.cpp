#include <iostream>
#include <limits>
#include "Local.h"
#include "Veiculo.h"
#include "Pedido.h"
#include "LocalUtils.h"

using namespace std;

int main()
{
    int secao;

    do
    {
        cout << "\n=== Selecione a se��o ==="
             << "\n1. Local"
             << "\n2. Ve�culo"
             << "\n3. Pedido"
             << "\n0. Sair"
             << "\nEscolha: ";
        cin >> secao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (secao)
        {
        case 1:
        {
            int opc;
            do
            {
                cout << "\n--- Menu Local ---"
                     << "\n1. Adicionar Local"
                     << "\n2. Excluir Local"
                     << "\n3. Listar Locais"
                     << "\n0. Voltar"
                     << "\nEscolha: ";
                cin >> opc;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (opc)
                {
                case 1:
                {
                    char nomeRua[50];
                    float x, y;
                    cout << "Informe nome da rua: ";
                    cin.getline(nomeRua, sizeof(nomeRua));
                    cout << "Coord X: ";
                    cin >> x;
                    cout << "Coord Y: ";
                    cin >> y;
                    Local::adicionarLocal(nomeRua, x, y);
                    cout << "Local adicionado.\n";
                    break;
                }
                case 2:
                {
                    float x, y;
                    cout << "Coord X do local a excluir: ";
                    cin >> x;
                    cout << "Coord Y do local a excluir: ";
                    cin >> y;
                    Local::excluirLocal(x, y);
                    cout << "Local exclu�do se encontrado.\n";
                    break;
                }
                case 3:
                {
                    int total;
                    infoLocal* locais = Local::listarTodosLocais(total);
                    if (locais && total > 0)
                    {
                        for (int i = 0; i < total; ++i)
                        {
                            cout << "Local: " << locais[i].nomerua
                                 << ", X: " << locais[i].coordx
                                 << ", Y: " << locais[i].coordy << endl;
                        }
                    }
                    else
                    {
                        cout << "Nenhum local encontrado.\n";
                    }
                    delete[] locais;
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "Op��o inv�lida!\n";
                }
            }
            while (opc != 0);
            break;
        }
        case 2:
        {
            int opc;
            do
            {
                cout << "\n--- Menu Ve�culo ---"
                     << "\n1. Adicionar Ve�culo"
                     << "\n2. Excluir Ve�culo"
                     << "\n3. Listar Ve�culos"
                     << "\n0. Voltar"
                     << "\nEscolha: ";
                cin >> opc;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (opc)
                {
                case 1:
                {
                    char placa[10], modelo[50];
                    bool disponivel;
                    cout << "Informe placa: ";
                    cin.getline(placa, sizeof(placa));
                    cout << "Informe modelo: ";
                    cin.getline(modelo, sizeof(modelo));

                    // Sele��o de local usando fun��o utilit�ria
                    infoLocal infoOrigem;
                    if (!escolherLocal(infoOrigem))
                    {
                        cout << "N�o h� locais cadastrados para escolha.\n";
                        break;
                    }
                    Local locOrigem(infoOrigem.nomerua, infoOrigem.coordx, infoOrigem.coordy);

                    cout << "Dispon�vel? (1=sim/0=n�o): ";
                    cin >> disponivel;
                    Veiculo::adicionarVeiculo(placa, modelo, locOrigem, disponivel);
                    cout << "Ve�culo adicionado.\n";
                    break;
                }
                case 2:
                {
                    char placa[10];
                    cout << "Informe placa do ve�culo a excluir: ";
                    cin.getline(placa, sizeof(placa));
                    Veiculo::excluirVeiculo(placa);
                    cout << "Ve�culo exclu�do se encontrado.\n";
                    break;
                }
                case 3:
                {
                    int totalVeiculos;
                    InfoVeiculo* veiculos = Veiculo::listarTodosVeiculos(totalVeiculos);
                    if (veiculos && totalVeiculos > 0)
                    {
                        cout << "\n== Lista de Ve�culos ==\n";
                        for (int i = 0; i < totalVeiculos; ++i)
                        {
                            cout << "Placa: " << veiculos[i].placa << endl;
                            cout << "Modelo: " << veiculos[i].modelo << endl;
                            cout << "Dispon�vel: " << (veiculos[i].disponivel ? "Sim" : "N�o") << endl;
                            cout << "Local: " << veiculos[i].local << endl;
                            cout << "--------------------------\n";
                        }
                    }
                    else
                    {
                        cout << "Nenhum ve�culo encontrado.\n";
                    }
                    delete[] veiculos;
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "Op��o inv�lida!\n";
                }
            }
            while (opc != 0);
            break;
        }
        case 3:
        {
            int opc;
            do
            {
                cout << "\n--- Menu Pedido ---"
                     << "\n1. Adicionar Pedido"
                     << "\n2. Excluir Pedido"
                     << "\n3. Listar Pedidos"
                     << "\n4. Calcular Rotas"
                     << "\n0. Voltar"
                     << "\nEscolha: ";
                cin >> opc;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (opc)
                {
                case 1:
                {
                    float peso;

                    // Sele��o de origem
                    infoLocal infoOrig;
                    if (!escolherLocal(infoOrig))
                    {
                        cout << "N�o h� locais cadastrados para origem.\n";
                        break;
                    }
                    Local orig(infoOrig.nomerua, infoOrig.coordx, infoOrig.coordy);

                    // Sele��o de destino
                    infoLocal infoDest;
                    if (!escolherLocal(infoDest))
                    {
                        cout << "N�o h� locais cadastrados para destino.\n";
                        break;
                    }
                    Local dest(infoDest.nomerua, infoDest.coordx, infoDest.coordy);

                    cout << "Peso do pedido: ";
                    cin >> peso;
                    Pedido::adicionarPedido(orig, dest, peso);
                    cout << "Pedido adicionado.\n";
                    break;
                }
                case 2:
                {
                    int id;
                    cout << "Informe ID do pedido a excluir: ";
                    cin >> id;
                    Pedido::excluirPedido(id);
                    cout << "Pedido exclu�do se encontrado.\n";
                    break;
                }
                case 3:
                {
                    int totalPedidos;
                    infoPedido* pedidos = Pedido::listarTodosPedidos(totalPedidos);
                    if (pedidos && totalPedidos > 0)
                    {
                        for (int i = 0; i < totalPedidos; ++i)
                        {
                            cout << "ID: " << pedidos[i].id << endl;
                            cout << "Peso: " << pedidos[i].peso << " kg" << endl;
                            cout << "Origem: " << pedidos[i].localOrigem << endl;
                            cout << "Destino: " << pedidos[i].localDestino << endl;
                            cout << "-------------------------\n";
                        }
                    }
                    else
                    {
                        cout << "Nenhum pedido encontrado.\n";
                    }
                    delete[] pedidos;
                    break;
                }
                case 4:
                    cout << "Calcular Rotas n�o implementado.\n";
                    break;
                case 0:
                    break;
                default:
                    cout << "Op��o inv�lida!\n";
                }
            }
            while (opc != 0);
            break;
        }
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Se��o inv�lida!\n";
        }
    }
    while (secao != 0);

    return 0;
}
