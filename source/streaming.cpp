#include "dat2ROOT.h"

void streamer(rawData &dObj,std::string inFile,TTree &tree)
{
    int wCounter = 0;
    int rCounter = 0;
    std::vector <std::string> tmpData;
    tmpData.resize(nWord);
    std::ifstream input_file(inFile.c_str(),std::ios::in);
    if(!input_file.is_open()) {
        std::cerr << "\nERROR 100! File not open. The path is:\n" << inFile << "\n\n";
        exit(100);
    }
    std::string input_string((std::istreambuf_iterator< char >(input_file)), (std::istreambuf_iterator< char >()));
    std::string tmp_str;
    input_file.close();
    std::istringstream input_stream(input_string);
    while(input_stream>>tmp_str)
    {
        //std::cout << "char: " << tmp_str << std::endl;
        tmpData[wCounter] = tmp_str;
        if(wCounter==16)
        {
            dObj.set_data_entry(tmpData);
            dObj.export_to_tree(tree);
            wCounter = 0;
            ++rCounter;
            /*
            if(rCounter==inspectEvent)
                dObj.getDataEvent();
            */
        }
        else
            ++wCounter;
    }

    std::cout << "\n" << rCounter << " lines have been read from data file \n\n";
}