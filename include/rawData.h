#ifndef RAWDATA_H
#define RAWDATA_H

#include "dat2ROOT.h"

class rawData
{
    public:
        rawData();
        rawData(
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
                );
        void set_data_entry(
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
                            );
        void set_data_entry(std::vector<std::string> &mergeData);
        void branch_tree(TTree &tree);
        void export_to_tree(TTree &tree) { tree.Fill(); }
        void getDataEvent();
        void set_max_min_values();
        void highlightMaxMin();
        ~rawData() {};
    private:

        /////// Event variables ...

        ULong64_t evID;
        ULong64_t DAMPE_timestamp;
        Double_t energy;        
        Double_t STK_theta;
        Double_t STK_phi;
        
        Double_t SatGeo_P_X;
        Double_t SatGeo_P_Y;
        Double_t SatGeo_P_Z;

        Double_t SatGeo_V_X;
        Double_t SatGeo_V_Y;    
        Double_t SatGeo_V_Z;

        /////// Max and min values ...

        ULong64_t DAMPE_tstmp_min;
        ULong64_t DAMPE_tstmp_max;

        Double_t engy_min;
        Double_t engy_max;

        Double_t STK_tht_min;
        Double_t STK_tht_max;

        Double_t STK_phi_min;
        Double_t STK_phi_max;

        Double_t SatGeo_P_X_min;
        Double_t SatGeo_P_X_max;
        
        Double_t SatGeo_P_Y_min;
        Double_t SatGeo_P_Y_max;

        Double_t SatGeo_P_Z_min;
        Double_t SatGeo_P_Z_max;

        Double_t SatGeo_V_X_min;
        Double_t SatGeo_V_X_max;

        Double_t SatGeo_V_Y_min;
        Double_t SatGeo_V_Y_max;

        Double_t SatGeo_V_Z_min;
        Double_t SatGeo_V_Z_max;

};

#endif

