#include "FastaReader.h"

std::string FastaReader::m_defaultString = "invalid sequence";
char FastaReader::m_seqStart = '>';

FastaReader::FastaReader():
m_name(""),
m_type(fst::FastaType::multiple),
m_delimiter('>'),
m_isOpen(false){
}

FastaReader::FastaReader(const std::string& name, const fst::FastaType type = fst::FastaType::multiple):
m_name(name),
m_type(type),
m_isOpen(false){
    FastaReader::Open(name,type);
}

FastaReader::~FastaReader(){
    FastaReader::Close();
}

void FastaReader::Open(const std::string& name, const fst::FastaType type = fst::FastaType::multiple){

    if(m_isOpen) return;

    m_is.open(name);
    m_type = type;

    switch (m_type){
    case fst::FastaType::single:
        m_delimiter = EOF;
        break;
    case fst::FastaType::multiple:
        m_delimiter = '>';
        break;
    }

    m_isOpen = true;

    return;
}

bool FastaReader::Is_Open() const {return m_isOpen;}

void FastaReader::Close(){
    m_is.close();
    m_isOpen = false;
    return;
}

const std::string& FastaReader::GetFileName() const {return m_name;}

