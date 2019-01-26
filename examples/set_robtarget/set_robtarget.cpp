#include <iostream>
#include <rws_interface.h>

using namespace std;
using namespace abb::rws;
int main(int argc, char* argv[]) {

    auto rws_interface = new RWSInterface("localhost", 80);

    std::string task = "T_ROB1";
    std::string module = "Module1";
    std::string name = "rws_target";

    RobTarget target;

    target.pos.x = 500;
    target.pos.y = -150;
    target.pos.z = 200;

    target.orient.q1 = 0.707F;
    target.orient.q2 = 0;
    target.orient.q3 = 0.707F;
    target.orient.q3 = 0;

    target.robconf.cf1 = -1;
    target.robconf.cf4 = -1;
    target.robconf.cf6 = 0;
    target.robconf.cfx = -1;

    target.extax.eax_a = 9E+09F;
    target.extax.eax_b = 9E+09F;
    target.extax.eax_c = 9E+09F;
    target.extax.eax_d = 9E+09F;
    target.extax.eax_e = 9E+09F;
    target.extax.eax_f = 9E+09F;

    // RAPIDSymbolDataAbstract data = 
    auto result = rws_interface->setRAPIDSymbolData(task, module, name, target);
    if (result) {
        std::cout << "SUCCESS: setRAPIDSymbolData" << std::endl;
    } else {
        std::cout << "FAILED: setRAPIDSymbolData" << std::endl;
    }

    delete rws_interface;

    return 0;
}
