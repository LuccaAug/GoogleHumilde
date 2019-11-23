#include "dataset.h"

Dataset::Dataset(){

    std::vector<string> palavras_;
    std::vector<vector<pair<int, int>>> relacao_;

    map<string, int> consultas_;

    long int contagem_de_documentos_ = 0;
}

long int Dataset::Contar_palavras(){
    return palavras_.size();
}

long int Dataset::Numero_de_documentos(){
    return contagem_de_documentos_;
}

long int Dataset::Quantos_documentos_possuem_essa_palavra(int idPx){
    cout << "Documentos do Dataset: " << relacao_[idPx].size() << endl;
    return relacao_[idPx].size();
}

long int Dataset::Quantas_vezes_dj_possui_Px(int dj, int idPx){
    if(idPx != -1){
        for(int i = 0; i < contagem_de_documentos_; ++i){
            if(relacao_[idPx][i].first == dj){
                return relacao_[idPx][i].second;
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
    arquivo.open("../documentos/"+doc.nome);
    vector<pair<int,int> > v;
    if(arquivo.is_open()){
        while(arquivo >> key){
            key = Formata_palavra(key);
            int idKey = Palavra_indice(key);
            if(idKey =! -1){
                palavras_[idKey][doc.id].second += 1;
            } else{
                v.clear();
                v.push_back(make_pair((int) doc.id, (int) 1));
                palavras_.push_back(v);
            }
        }
        contagem_de_documentos_++;
    }
    cout << "Palavras dentro do Le Documento:" << palavras_.size() << endl;
}

void Dataset::Le_consulta(vector<string> consulta){
    string key;

    for(vector<string>::iterator it = consulta.begin(); it!=consulta.end(); it++){
        key = *it;
        key = Formata_palavra(key);
        int idKey = Palavra_indice(key);
        if(idKey != -1){
            if(search(palavras_.begin(), palavras_.end(), key, key) != consultas_.end()){
                consultas_[key]++;
            } else{
                consultas_.insert(make_pair(key, 1));
            }
        }
    }
}

void Dataset::Le_lista(){
    contagem_de_documentos_ = 0;
    ifstream lista;
    lista.open("../documentos/lista_de_documentos.txt");

    if(lista.is_open()){
        cout << "Palavras dentro do Dataset:" << palavras_.size() << endl;
    
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
    it = search(palavras_.begin(), palavras_.end(), Word, Word);

    if (it!=palavras_.end())
        return(it-palavras_.begin());
    else
        return -1;
}

Dataset::~Dataset(){
    palavras_.clear();
    relacao_.clear();
    consultas_.clear();
    contagem_de_documentos_ = 0;
}
