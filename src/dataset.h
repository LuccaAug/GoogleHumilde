#ifndef DATASET_H
#define DATASET_H

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

struct Documento{
    int id;
    string nome;
    
    Documento() {
        id = 0;
        nome = "";
    }
    Documento(int id_documento, string nome_documento) {
        id = id_documento;
        nome = nome_documento;
    }
};

class Dataset{
    public:
        //Inicializa o map e comeca a contagem de documentos
        Dataset(string nome_arquivo);

        //Conta a quantidade de palavras diferentes nos documentos
        long int Contar_palavras();

        //Retorna o numero de documentos abertos
        long int Numero_de_documentos();

        //Retorna quantos documentos possuem a palavra Px
        long int Quantos_documentos_possuem_essa_palavra(int idPx);

        //Retorna quantas vezes a palavra Px aparece no documento dj
        long int Quantas_vezes_dj_possui_Px(int dj, int idPx);

        //Remove caracteres especiais da string
        string Formata_palavra(string word);

        //Le o arquivo e armazena as informacoes no map
        void Le_documento(Documento doc);

        //Le a consulta e armazena as informacoes no map, retira palavras fora dos documentos
        void Le_consulta(vector<string> consulta);

        //Le a lista dos documentos
        void Le_lista();

        //retorna a palavra de indice 'indice' no map
        int Palavra_indice(string word);

        //Remove todos os elementos do map
        ~Dataset();
    private:
        // Palavra, ID do documento, quantidade de vezes que a palavra aparece no documento
        std::vector<string> palavras_;

        // Vetor cujo o índice é o id de cada palavra e nesta posição possui um vetor 
        // em que cada par é uma relacao (idDoc, #palavra)
        std::vector<vector<pair<int, int>>> relacao_;

        // Palavra, quantidade de vezes que a palavra aparece na consulta
        map<int, int> consultas_;

        long int contagem_de_documentos_;

        string endereco_;

    friend class Teste;
};

#endif  // DATASET_H