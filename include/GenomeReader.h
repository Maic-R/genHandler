#ifndef GenomeReader_h
#define GenomeReader_h

#include "FastaReader.h"

class GenomeReader: public FastaReader{

public:

    GenomeReader();
    GenomeReader(const std::string& name, fst::FastaType type);
    GenomeReader(const GenomeReader& gr) = delete;

    virtual ~GenomeReader();

    void Read() override;

private:

};

#endif