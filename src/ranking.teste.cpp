#include "doctest.h"

class Teste{
	public:
		static Dataset* ds(const Ranking &r){
			return r.ds_;
		}
		static double* arq_coord(const Ranking &r){
			return r.coordenadas_consulta_;
		}
		static double sum_com_2(const Ranking &r){
			return r.sum_com_2_;
		}
}

TEST_SUITE("Ranking"){
	TEST_CASE("Ranking()"){
		Dataset ds_test;
		Ranking r(ds_test, "test.txt");
		CHECK(Teste::ds(r) == &ds_test);
		CHECK(Teste::ds(r) == "test.txt");
	}

	TESTE_CASE("Ler_coordenadas()"){

	}

	TESTE_CASE("Similaridade()"){

	}

	TESTE_CASE("Ordenar_documentos()"){

	}

	TESTE_CASE("Mostrar_ranking()"){

	}

	TESTE_CASE("~Ranking()"){

	}
}