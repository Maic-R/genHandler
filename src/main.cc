#include <iostream>

#include "GenomeReader.h"

int main(){

    //FastaReader* f = new FastaReader("petunia_m", fst::FastaType::multiple);

    //if( f->Is_Open() ) std::cout << "l'ho letto\n";

    //f->Read();

    GenomeReader* g = new GenomeReader("petunia_m",fst::FastaType::multiple);

    g->Read();

    std::map<const std::string, const std::string> m = g->getMap();

    for(auto i : m) std::cout << i.first << "\n";

    return 0;
}