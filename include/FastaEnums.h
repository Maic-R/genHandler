#ifndef FastaEnums_h
#define FastaEnums_h


namespace fst{

    enum FastaType{
        single=1,
        multiple
    };

    enum DataType{
        genomic=0,
        genes,
        mRNA,
        CDS,
        GFF
    };

    struct genInfo{
        std::string seqID;
        std::string seq;
        unsigned int i;

    };

    typedef std::map<const std::string, std::variant<std::string, fst::genInfo> > FastaMap;
}

#endif