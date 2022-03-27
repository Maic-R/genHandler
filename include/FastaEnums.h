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
}

#endif