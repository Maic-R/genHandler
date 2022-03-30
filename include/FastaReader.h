#ifndef FastaReader_h
#define FastaReader_h

#include <string>
#include <map>
#include <fstream>
#include <variant>

#include "FastaEnums.h"

class FastaReader{

public: 

    FastaReader();
    //constructors with parameeters: name of the file to open and file type (single or multiple)
    FastaReader(const std::string& name, const fst::FastaType type);
    FastaReader(const FastaReader& fr) = delete;

    virtual ~FastaReader();
    //open the file "name" of type "type"
    void Open(const std::string& name, const fst::FastaType type);
    bool Is_Open() const;

    virtual void Read() = 0;
    void Close();

    //returns the name of the opened fasta file
    const std::string& GetFileName() const;

    bool contains(const std::string& seqID) const;

    const fst::FastaMap& getMap() const;

    //given the sequence name returns the corresponding sequence
    //const string& GetSequence(const string& seqName) const;

    //given the sequence name returns the sequence ID
    //const string GetSequenceID(const string& seqName, const string& sep, unsigned int nBlock) const;

protected:

    std::string m_name;
    fst::FastaType m_type;
    char m_delimiter; 

    bool m_isOpen;
    std::ifstream m_is;
    fst::FastaMap m_mFI;  

    static std::string m_defaultString;
    static char m_seqStart;


private:

};

#endif