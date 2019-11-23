#include "doctest.h"

class Teste{
	public:
	    static std::vector<string> palavras(const Dataset &d){
	    	return d.palavras_;
	    }

	    static std::vector<vector<pair<int, int>>> relacao(const Dataset &d){
	    	return d.relacao_;
	    }

	    static map<string, int> consultas(const Dataset &d){
	    	return d.consultas_;
	    }

	    static long int contagem_de_documentos(const Dataset &d){
	    	return d.contagem_de_documentos_;
	    }
}

TEST_SUITE("Dataset"){
	

        TESTE_CASE("Dataset()"){

        }

        TESTE_CASE("Contar_palavras()"){

		}

        TESTE_CASE("Numero_de_documentos()"){

        }

        TESTE_CASE("Quantos_documentos_possuem_essa_palavra()"){

		}

        TESTE_CASE("Quantas_vezes_dj_possui_Px()"){

        }

        TESTE_CASE("Formata_palavra()"){

		}

        TESTE_CASE("Le_documento()"){

        }

        TESTE_CASE("Le_consulta()"){

		}

        TESTE_CASE("Le_lista()"){

        }

        TESTE_CASE("Palavra_indice()"){

		}

        TESTE_CASE("~Dataset()"){

        }
		}