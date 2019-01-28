#include <iostream>
#include <rws_interface.h>
#include "Poco/DOM/DOMParser.h"
#include "Poco/DOM/DOMWriter.h"


using Poco::XML::DOMParser;
using Poco::XML::DOMWriter;
using Poco::XML::XMLReader;
using namespace std;
using namespace abb::rws;

void print_document(Poco::AutoPtr<Poco::XML::Document>* doc) {
    std::ostringstream ostr;

    DOMParser parser;
    parser.setFeature(XMLReader::FEATURE_NAMESPACE_PREFIXES, false);
    DOMWriter writer;
    writer.writeNode(ostr, *doc);

    std::string xml = ostr.str();

    std::cout << "Document: " << xml << std::endl;
}

int main(int argc, char* argv[]) {

    auto rws_interface = new RWSInterface("localhost", 80);

    std::string task = SystemConstants::RAPID::TASK_ROB_1;
    std::string module = "Module1";
    std::string name = "command"; //LOCAL PERS bool load_task:=False;

    auto resources = RWSClient::SubscriptionResources();

    RWSClient::RAPIDResource resource(task, module, name);
    resources.addRAPIDPersistantVariable(resource, RWSClient::SubscriptionResources::Priority::HIGH);
    auto result = rws_interface->startSubscription(resources);
    if (result) {
        std::cout << "SUCCESS: startSubscription" << std::endl;
    } else {
        std::cout << "FAILED: startSubscription" << std::endl;
    }

    Poco::AutoPtr<Poco::XML::Document>* p_xml_document = new Poco::AutoPtr<Poco::XML::Document>();
    result = rws_interface->waitForSubscriptionEvent(p_xml_document);
    if (result) {
        std::cout << "SUCCESS: waitForSubscriptionEvent" << std::endl;
        print_document(p_xml_document);
    } else {
        std::cout << "FAILED: waitForSubscriptionEvent" << std::endl;
    }

    rws_interface->endSubscription();
    delete rws_interface;

    return 0;
}
