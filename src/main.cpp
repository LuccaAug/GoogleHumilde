#include <cstdlib>

#include "dataset.h"
#include "indice_invertido.h"
#include "ranking.h"

int main(int argc, char const *argv[])
{
	#ifdef _WIN32
	//código específico para windows
		system("cria_arquivo.py");
	#else
		system("./cria_arquivo.py");
	#endif
	
	Dataset ds;
	ds.Dataset::Le_lista();

	Indice_invertido id_iv(&ds, "indice_invertido.txt");
	id_iv.Indice_invertido::Arquivo_Indice_Invertido();

	cout<<"chegou aqui"<<endl;
	Ranking rk(id_iv, &ds);
	rk.Ranking::Mostrar_ranking();

	return 0;
}