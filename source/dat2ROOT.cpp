#include "dat2ROOT.h"

int main(int argc,char *argv[])
{
    if(argc<3)
    {
        std::cerr << "Usage: ./dat2ROOT path_to_input_file path_to_output_file";        
        std::cerr << "\n\nError: at least INPUT file should be present \n\n";
        exit(3);
    }

    std::string inFile(argv[1]);
    std::string outFile(argv[2]);

    rawData dCollect;
    TTree dataTree;

    dCollect.branch_tree(dataTree);

    streamer(dCollect,inFile,dataTree);

    TFile result(outFile.c_str(),"RECREATE");
    if(result.IsZombie())
    {
        std::cerr << "\n\n ERROR writing output file: " << outFile << std::endl;
        exit(100);
    }

    dataTree.Write();
    result.Close();

    ////// Cleaning

    dataTree.Delete();

    return 0;

}
