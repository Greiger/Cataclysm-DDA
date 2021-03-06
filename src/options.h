#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm> //atoi

class regional_settings;
class options_data
{
        friend class regional_settings;
    public:
        void add_retry(const std::string &var, const std::string &val);
        void add_value(const std::string &myoption, const std::string &myval, std::string myvaltxt = "" );
        options_data();
    private:
        void enable_json(const std::string &var);
        std::map<std::string, std::string> post_json_verify;
};

class cOpt
{
        friend class options_data;
    public:
        //Default constructor
        cOpt();

        //string constructor
        cOpt(const std::string sPageIn, const std::string sMenuTextIn, const std::string sTooltipIn,
             const std::string sItemsIn, std::string sDefaultIn);

        //bool constructor
        cOpt(const std::string sPageIn, const std::string sMenuTextIn, const std::string sTooltipIn,
             const bool bDefaultIn);

        //int constructor
        cOpt(const std::string sPageIn, const std::string sMenuTextIn, const std::string sTooltipIn,
             const int iMinIn, int iMaxIn, int iDefaultIn);

        //float constructor
        cOpt(const std::string sPageIn, const std::string sMenuTextIn, const std::string sTooltipIn,
             const float fMinIn, float fMaxIn, float fDefaultIn, float fStepIn);

        //Default deconstructor
        ~cOpt() {};

        //helper functions
        std::string getPage();
        std::string getMenuText();
        std::string getTooltip();
        std::string getType();

        std::string getValue();
        std::string getValueName();
        std::string getDefaultText();

        int getItemPos(const std::string sSearch);

        //set to next item
        void setNext();
        //set to prev item
        void setPrev();
        //set value
        void setValue(std::string sSetIn);
        void setValue(float fSetIn);

        //Set default class behaviour to float
        operator float() const;
        // if (class == "string")
        bool operator==(const std::string sCompare) const;
        // if (class != "string")
        bool operator!=(const std::string sCompare) const;

    private:
        std::string sPage;
        std::string sMenuText;
        std::string sTooltip;
        std::string sType;

        //sType == "string"
        std::string sSet;
        std::vector<std::string> vItems;
        std::string sDefault;

        //sType == "bool"
        bool bSet;
        bool bDefault;

        //sType == "int"
        int iSet;
        int iMin;
        int iMax;
        int iDefault;

        //sType == "float"
        float fSet;
        float fMin;
        float fMax;
        float fDefault;
        float fStep;
};

extern std::unordered_map<std::string, cOpt> OPTIONS;
extern std::unordered_map<std::string, cOpt> ACTIVE_WORLD_OPTIONS;

extern options_data optionsdata;
void initOptions();
void load_options();
void save_options(bool ingame = false);
void show_options(bool ingame = false);

bool use_narrow_sidebar(); // short-circuits to on if terminal is too small

std::string get_tileset_names(std::string dir_path);


#endif
