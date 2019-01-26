#include <iostream>
#include <rws_interface.h>

using namespace std;
using namespace abb::rws;
int main(int argc, char* argv[]) {

    auto rws_interface = new RWSInterface("localhost", 80);

    std::string task = SystemConstants::RAPID::TASK_ROB_1;
    std::string module = "Module1";
    std::string name = "rws_target"; //LOCAL PERS robtarget rws_target

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

    // robtarget
    auto result = rws_interface->setRAPIDSymbolData(task, module, name, target);
    if (result) {
        std::cout << "SUCCESS: setRAPIDSymbolData (robtarget)" << std::endl;
    } else {
        std::cout << "FAILED: setRAPIDSymbolData (robtarget)" << std::endl;
    }

    // num
    name = "frames_processed"; //LOCAL VAR num frames_processed;
    
    RAPIDAtomic<RAPID_NUM> frames_processed = 10;
    result = rws_interface->setRAPIDSymbolData(task, module, name, frames_processed);
    if (result) {
        std::cout << "SUCCESS: setRAPIDSymbolData (num)" << std::endl;
    } else {
        std::cout << "FAILED: setRAPIDSymbolData (num)" << std::endl;
    }

    // bool
    name = "task_loaded"; //LOCAL VAR bool task_loaded:=False;
    
    RAPIDAtomic<RAPID_BOOL> task_loaded = true; 
    result = rws_interface->setRAPIDSymbolData(task, module, name, task_loaded);
    if (result) {
        std::cout << "SUCCESS: setRAPIDSymbolData (bool)" << std::endl;
    } else {
        std::cout << "FAILED: setRAPIDSymbolData (bool)" << std::endl;
    }
    
    // string
    name = "message"; //LOCAL VAR string message;
    std::string msg = "RWS Rocks!";
    RAPIDAtomic<RAPID_STRING> message = msg; 
    result = rws_interface->setRAPIDSymbolData(task, module, name, message);
    if (result) {
        std::cout << "SUCCESS: setRAPIDSymbolData (string)" << std::endl;
    } else {
        std::cout << "FAILED: setRAPIDSymbolData (string)" << std::endl;
    }


    delete rws_interface;

    return 0;
}
