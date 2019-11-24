#include "dataset.h"

Dataset::Dataset(string nome_arquivo){

    std::vector<string> palavras_;
    std::vector<vector<pair<int, int>>> relacao_;

    map<int, int> consultas_;

    long int contagem_de_documentos_;
    contagem_de_documentos_ = 0;

    string endereco_ = nome_arquivo;
}

long int Dataset::Contar_palavras(){
    return this->palavras_.size();
}

long int Dataset::Numero_de_documentos(){
    return contagem_de_documentos_;
}

long int Dataset::Quantos_documentos_possuem_essa_palavra(int idPx){
    cout << "Documentos do Dataset: " << relacao_[idPx].size() << endl;
    if(idPx >= Numero_de_documentos()) return 0;
    return relacao_[idPx].size();
}

long int Dataset::Quantas_vezes_dj_possui_Px(int dj, int idPx){
    if((idPx) != (-1)){
        for(int i = 0; i < contagem_de_documentos_; ++i){
            if(relacao_[idPx][i].first == dj){
                return relacao_[idPx][i].second;
            }
        }
    }
    return 0;
}

string Dataset::Formata_palavra(string word){
    for (unsigned int i = 0; i < word.size(); i++){
        if (((word[i] < 'A') || (word[i] > 'Z')) && ((word[i] < 'a') || (word[i] > 'z')) && ((word[i] < '0') || (word[i] > '9'))){
            word.erase(i, 1);
            i--;
        } else{
            tolower(word[i]);
        }
    }
    return word;
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
            if((idKey) != (-1)){
                relacao_[idKey][doc.id-1].second += 1;
            } else{
                v.clear();
                v.push_back(make_pair((int) doc.id, (int) 1));
                relacao_.push_back(v);
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
        if((idKey) != (-1)){
            auto itr = consultas_.find(idKey);
            if (itr != consultas_.end()){
                consultas_[idKey]++;
            } else{
                consultas_.insert(make_pair(idKey, 1));
            }
        }
    }
}

void Dataset::Le_lista(){
    contagem_de_documentos_ = 0;
    ifstream lista;
    lista.open(endereco_+"lista_de_documentos.txt");

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
    vector<string> v;
    v.push_back(Word);
    it = search(palavras_.begin(), palavras_.end(), v.begin(), v.end());

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
