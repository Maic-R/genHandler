#include "GenomeReader.h"

GenomeReader::GenomeReader(){
}

GenomeReader::GenomeReader(const std::string& name, fst::FastaType type):
FastaReader::FastaReader(name,type){
}

GenomeReader::~GenomeReader(){
}

void GenomeReader::Read() {

    if(!m_isOpen) return;

    //reading char
    char c;
    
    std::string seqID;
    std::string seq;
    
    while(m_is.get(c)){
        if(c == m_seqStart){
            if(getline(m_is,seqID)){
                getline(m_is,seq,m_delimiter);
                m_is.unget();
            }
            m_mFI.insert( std::make_pair(seqID,seq) );
        }
        else continue;
    }
    
    return;
}