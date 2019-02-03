#include "dat2ROOT.h"
#include "rawData.h"

rawData::rawData()
{
    evID =  0;
    DAMPE_timestamp = 0;
    energy =  -999;
    STK_theta =  -999;
    STK_phi = -999;
    SatGeo_P_X =  -999;
    SatGeo_P_Y =  -999;
    SatGeo_P_Z =  -999;
    SatGeo_V_X =  -999;
    SatGeo_V_Y =  -999;
    SatGeo_V_Z =  -999;
}

rawData::rawData(
                    ULong64_t ID,
                    ULong64_t t_stp,
                    Double_t egy,
                    Double_t theta,
                    Double_t phi,
                    Double_t sat_geo_pos_X,
                    Double_t sat_geo_pos_Y,
                    Double_t sat_geo_pos_Z,
                    Double_t sat_geo_vel_X,
                    Double_t sat_geo_vel_Y,
                    Double_t sat_geo_vel_Z
                )
{
    evID =  ID;
    DAMPE_timestamp = t_stp;
    energy =  egy;
    STK_theta =  theta;
    STK_phi = phi;
    SatGeo_P_X =  sat_geo_pos_X;
    SatGeo_P_Y =  sat_geo_pos_Y;
    SatGeo_P_Z =  sat_geo_pos_Z;
    SatGeo_V_X =  sat_geo_vel_X;
    SatGeo_V_Y =  sat_geo_vel_Y;
    SatGeo_V_Z =  sat_geo_vel_Z;
}

void rawData::set_data_entry(
                                ULong64_t ID,
                                ULong64_t t_stp,
                                Double_t egy,
                                Double_t theta,
                                Double_t phi,
                                Double_t sat_geo_pos_X,
                                Double_t sat_geo_pos_Y,
                                Double_t sat_geo_pos_Z,
                                Double_t sat_geo_vel_X,
                                Double_t sat_geo_vel_Y,
                                Double_t sat_geo_vel_Z
                            )
{
    evID =  ID;
    DAMPE_timestamp = t_stp;
    energy =  egy;
    STK_theta =  theta;
    STK_phi = phi;
    SatGeo_P_X =  sat_geo_pos_X;
    SatGeo_P_Y =  sat_geo_pos_Y;
    SatGeo_P_Z =  sat_geo_pos_Z;
    SatGeo_V_X =  sat_geo_vel_X;
    SatGeo_V_Y =  sat_geo_vel_Y;
    SatGeo_V_Z =  sat_geo_vel_Z;
}

void rawData::set_data_entry(std::vector<std::string> &mergeData)
{
    evID = strtoull(mergeData[0].c_str(),NULL,10);
    DAMPE_timestamp = strtoull(mergeData[1].c_str(),NULL,10);
    energy = stod(mergeData[3],NULL);
    STK_theta = stod(mergeData[4],NULL);
    STK_phi = stod(mergeData[5],NULL);
    
    SatGeo_P_X = stod(mergeData[11],NULL);
    SatGeo_P_Y = stod(mergeData[12],NULL);
    SatGeo_P_Z = stod(mergeData[13],NULL);
    
    SatGeo_V_X = stod(mergeData[14],NULL);
    SatGeo_V_Y = stod(mergeData[15],NULL);
    SatGeo_V_Z = stod(mergeData[16],NULL);
}

void rawData::branch_tree(TTree &tree)
{
    tree.Branch("EventID",&evID,"EventID/l");
    tree.Branch("DAMPE_timestamp",&DAMPE_timestamp,"DAMPE_timestamp/l");
    tree.Branch("energy",&energy,"DAMPE_timestamp/D");
    tree.Branch("STK_theta",&STK_theta,"STK_theta/D");
    tree.Branch("STK_phi",&STK_phi,"STK_phi/D");

    tree.Branch("SatGeo_P_X",&SatGeo_P_X,"SatGeo_P_X/D");
    tree.Branch("SatGeo_P_Y",&SatGeo_P_Y,"SatGeo_P_Y/D");
    tree.Branch("SatGeo_P_Z",&SatGeo_P_Z,"SatGeo_P_Z/D");

    tree.Branch("SatGeo_V_X",&SatGeo_V_X,"SatGeo_V_X/D");
    tree.Branch("SatGeo_V_Y",&SatGeo_V_Y,"SatGeo_V_Y/D");
    tree.Branch("SatGeo_V_Z",&SatGeo_V_Z,"SatGeo_V_Z/D");
}

void rawData::getDataEvent()
{
    std::cout << "\n****************\n";
    std::cout << "Data event sumup: \n\n";
    
    std::cout << "EventID: \t" << evID << std::endl;
    std::cout << "DAMPE_timestamp \t" << DAMPE_timestamp << std::endl;
    std::cout << "Energy (GeV) \t" << energy << std::endl;
    std::cout << "STK_theta \t" << STK_theta << std::endl;
    std::cout << "STK_phi \t" << STK_phi << std::endl;
    std::cout << "Satellite Position X (GeoCenter coord.) \t" << SatGeo_P_X << std::endl;
    std::cout << "Satellite Position Y (GeoCenter coord.) \t" << SatGeo_P_Y << std::endl;
    std::cout << "Satellite Position Z (GeoCenter coord.) \t" << SatGeo_P_Z << std::endl;
    std::cout << "Satellite Velocity X (GeoCenter coord.) \t" << SatGeo_V_X << std::endl;
    std::cout << "Satellite Velocity Y (GeoCenter coord.) \t" << SatGeo_V_Y << std::endl;
    std::cout << "Satellite Velocity Z (GeoCenter coord.) \t" << SatGeo_V_Z << std::endl;

    std::cout << "\n****************\n";
}