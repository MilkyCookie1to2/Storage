#include "../class .h"

storage::datauser::datauser(){
    name = fam = och = "Name";
    numphone = 000000000;
    position = "N/N";
}
storage::datauser::datauser(string m_name, string m_fam, string m_och, int m_num,date m_date,string m_position) {
    name = m_name;
    fam = m_fam;
    och = m_och;
    numphone = m_num;
    bith = m_date;
    position = m_position;
}

storage::datauser::datauser(const datauser &datauser) {
    fam = datauser.fam;
    name = datauser.name;
    och= datauser.och;
    numphone = datauser.numphone;
    bith = datauser.bith;
    position = datauser.position;
}