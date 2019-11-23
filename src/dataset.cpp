#include "dataset.h"

Dataset::Dataset(dataset nome_arquivo){

    std::vector<string> palavras;
    std::vector<vector<pair<int, int>>> relacao;

    map<string, int> consultas;

    long int contagem_de_documentos = 0;

    string endereco_ = nome_arquivo;
}

long int Dataset::Contar_palavras(){
    return palavras.size();
}

long int Dataset::Numero_de_documentos(){
    return contagem_de_documentos;
}

long int Dataset::Quantos_documentos_possuem_essa_palavra(int idPx){
    cout << "Documentos do Dataset: " << relacao[idPx].size() << endl;
    if(idPx >= Numero_de_documentos()) return 0;
    return relacao[idPx].size();
}

long int Dataset::Quantas_vezes_dj_possui_Px(int dj, int idPx){
    if(idPx != -1){
        for(int i = 0; i < contagem_de_documentos; ++i){
            if(relacao[idPx][i].first == dj){
                return relacao[idPx][i].second;
            }
        }
    }
    return 0;
}

string Dataset::Formata_palavra(string palavra){
    for (int i = 0; i < palavra.size(); i++){
        if (((palavra[i] < 'A') || (palavra[i] > 'Z')) && ((palavra[i] < 'a') || (palavra[i] > 'z')) && ((palavra[i] < '0') || (palavra[i] > '9'))){
            palavra.erase(i, 1);
            i--;
        } else{
            tolower(palavra[i]);
        }
    }
    return palavra;
}

void Dataset::Le_documento(Documento doc){
    string key;
    ifstream arquivo;
    arquivo.open(endereco_+doc.nome);
    vector<pair<int,int> > v;
    if(arquivo.is_open()){
        while(arquivo >> key){
            key = Formata_palavra(key);
            int idKey = Palavra_indice(key);
            if(idKey =! -1){
                palavras[idKey][doc.id].second += 1;
            } else{
                v.clear();
                v.push_back(make_pair((int) doc.id, (int) 1));
                palavras.push_back(v);
            }
        }
        contagem_de_documentos++;
    }
    cout << "Palavras dentro do Le Documento:" << palavras.size() << endl;
}

void Dataset::Le_consulta(vector<string> consulta){
    string key;

    for(vector<string>::iterator it = consulta.begin(); it!=consulta.end(); it++){
        key = *it;
        key = Formata_palavra(key);
        int idKey = Palavra_indice(key);
        if(idKey != -1){
            if(search(palavras.begin(), palavras.end(), key, key) != consultas.end()){
                consultas[key]++;
            } else{
                consultas.insert(make_pair(key, 1));
            }
        }
    }
}

void Dataset::Le_lista(){
    contagem_de_documentos = 0;
    ifstream lista;
    lista.open(endereco_+"lista_de_documentos.txt");

    if(lista.is_open()){
        cout << "Palavras dentro do Dataset:" << palavras.size() << endl;
    
    }

    string nome_documento;

    while(getline (lista,nome_documento)){
        struct Documento doc(Numero_de_documentos(),nome_documento);

        Le_documento(doc);
    }

    lista.close();
}

int Dataset::Palavra_indice(string Word){
    std::vector<string>::iterator it;
    it = search(palavras.begin(), palavras.end(), Word, Word);

    if (it!=palavras.end())
        return(it-palavras.begin());
    else
        return -1;
}

Dataset::~Dataset(){
    palavras.clear();
    relacao.clear();
    consultas.clear();
    contagem_de_documentos = 0;
}
