#ifndef DAT2ROOT_H
#define DAT2ROOT_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "TTree.h"
#include "TFile.h"

#include "rawData.h"

#define nWord 17
#define inspectEvent 100


extern void streamer(rawData &dObj,std::string inFile,TTree &tree);

#endif

