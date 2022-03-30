#include <iostream>

#include "GenomeReader.h"

int main(){

    //FastaReader* f = new FastaReader("petunia_m", fst::FastaType::multiple);

    //if( f->Is_Open() ) std::cout << "l'ho letto\n";

    //f->Read();

    FastaReader* g = new GenomeReader("petunia_m",fst::FastaType::multiple);

    g->Read();

    //std::map<const std::string, std::string> m = g->getMap();

    fst::FastaMap m = g->getMap();

    fst::FastaMap m1;

    fst::genInfo info;

    info.seqID = "seqID";
    info.seq = "AACT";
    info.i = 425224;

    m1["Key1"] = "Data1";
    m1["Key2"] = info;

    for(auto i : m) std::cout << i.first << "\n";

    return 0;
}