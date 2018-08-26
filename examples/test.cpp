#include <iostream>
#include <rws_interface.h>

using namespace std;
using namespace abb::rws;
int main(int argc, char* argv[]) {

    auto rws_interface = new RWSInterface("192.168.132.6", 80);

    auto static_info = rws_interface->collectStaticInfo();
    cout << "Robotware Version # " << static_info.system_info.robot_ware_version << endl;
    cout << "System Name # " << static_info.system_info.system_name << endl;

    auto runtime_info = rws_interface->collectRuntimeInfo();
    cout << "Mode # " << (runtime_info.auto_mode ? "Auto" : "Manual") << endl;
    cout << "Motor # " << (runtime_info.motor_on ? "ON" : "OFF") << endl;
    cout << "Rapid # " << (runtime_info.rapid_running ? "Running" : "Stopped") << endl;
    cout << "Status # " << (runtime_info.rws_connected ? "Connected" : "Disconnected") << endl;

    delete rws_interface;

    return 0;
}
