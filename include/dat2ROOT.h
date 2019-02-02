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

#define nWord 17
#include "rawData.h"

extern void streamer(rawData &dObj,std::string inFile,TTree &tree);

#endif

