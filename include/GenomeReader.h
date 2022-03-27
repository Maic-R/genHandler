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

    bool contains(const std::string& seqID) const override;

    const std::map<const std::string, const std::string>& getMap() const;

private:

    //seqID stored without '>'
    std::map<const std::string, const std::string> m_mGI;

};

#endif