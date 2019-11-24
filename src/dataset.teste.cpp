#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "dataset.h"
#include <vector>
#include <string>
#include <map>

class Teste{
	public:
		static vector<string> palavras(const Dataset &d){
			return d.palavras_;
		}
		static vector<vector<pair<int, int>>> relacao(const Dataset &d){
			return d.relacao_;
		}
		static map<int, int> consultas(const Dataset &d){
			return d.consultas_;
		}
		static long int contagem_de_documentos(const Dataset &d){
			return d.contagem_de_documentos_;
		}
		static string endereco(const Dataset &d){
			return d.endereco_;
		}
};

TEST_SUITE("Dataset"){
	TEST_CASE("Dataset()"){
		Dataset d("../documentos/testes/");
		CHECK(Teste::palavras(d).size() == 0);
		CHECK(Teste::relacao(d).size() == 0);
		CHECK(Teste::consultas(d).size() == 0);
		CHECK(Teste::contagem_de_documentos(d) == 0);
		CHECK(Teste::endereco(d) == "../documentos/testes/");
	}

	TEST_CASE("Le_lista()"){
		Dataset d("../documentos/testes/");
		d.Le_lista();

	}

	TEST_CASE("Le_documento()"){
		Dataset d("../documentos/testes/");
		d.Le_lista();

	}

	TEST_CASE("Le_consulta()"){
		Dataset d("../documentos/testes/");
		d.Le_lista();

	}

	TEST_CASE("Palavra_indice()"){
		Dataset d("../documentos/testes/");
		CHECK(d.Palavra_indice("teste") == 0);
		CHECK(d.Palavra_indice("documento") == 1);
		CHECK(d.Palavra_indice("absurdo") == -1);
	}

	TEST_CASE("Contar_palavras()"){
		Dataset d("../documentos/testes/");
		d.Le_lista();
		CHECK(d.Contar_palavras() == 2);
	}

	TEST_CASE("Numero_de_documentos()"){
		Dataset d("../documentos/testes/");
		d.Le_lista();
		CHECK(d.Numero_de_documentos() == 2);
		
	}
	
	TEST_CASE("Quantos_documentos_possuem_essa_palavra()"){
		Dataset d("../documentos/testes/");
		d.Le_lista();
		int idTeste = d.Palavra_indice("teste");
		int idAbsurdo = d.Palavra_indice("absurdo") == -1;
		CHECK(d.Quantos_documentos_possuem_essa_palavra(idTeste) == 2);
		CHECK(d.Quantos_documentos_possuem_essa_palavra(idAbsurdo) == 0);
	}

	TEST_CASE("Quantas_vezes_dj_possui_Px()"){
		Dataset d("../documentos/testes/");
		d.Le_lista();
		CHECK(d.Quantas_vezes_dj_possui_Px(1,0) == 1);
		CHECK(d.Quantas_vezes_dj_possui_Px(1,1) == 1);
		CHECK(d.Quantas_vezes_dj_possui_Px(2,0) == 1);
		CHECK(d.Quantas_vezes_dj_possui_Px(2,1) == 2);

		CHECK(d.Quantas_vezes_dj_possui_Px(5,0) == 0);
		CHECK(d.Quantas_vezes_dj_possui_Px(0,5) == 0);
		CHECK(d.Quantas_vezes_dj_possui_Px(5,5) == 0);
		
	}

	TEST_CASE("Formata_palavra()"){
		Dataset d("../documentos/testes/");
		CHECK(d.Formata_palavra("Teste") == "teste");
		CHECK(d.Formata_palavra("05") == "05");
		CHECK(d.Formata_palavra("Mais-Teste") == "maisteste");
		CHECK(d.Formata_palavra("A") == "a");
		CHECK(d.Formata_palavra("TeStE") == "teste");	
	}
}