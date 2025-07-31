#include <fstream>
#include <string>
#include "../include/dbase.h"
#include "../include/datatypes.h"

using nlohmann::json;

using std::cout;
using std::endl;

/* orders.json

{
    "0": {
        "IDarticles": [
            3,
            0
        ],
        "comment": "ADAD",
        "price": 55.7,
        "processed": false,
        "restName": "B",
        "time": {
            "deliver": "1/14/2024 8:35:28 PM",
            "order": "1/14/2024 8:05:28 PM"
        },
        "userUName": "B"
    },
    "1": {
        "IDarticles": [
            3
        ],
        "comment": "AAA",
        "price": 30.4,
        "processed": false,
        "restName": "B",
        "time": {
            "deliver": "1/14/2024 8:36:05 PM",
            "order": "1/14/2024 8:06:05 PM"
        },
        "userUName": "B"
    }
}

*/

int main() {

	vector<order> orders = ordersJSONuOrdersVec();

	// Example: Print parsed data
	for (const auto& ord : orders) {

		cout << "Order Info:" << endl;
		cout << "Price: " << ord.price << endl;
		cout << "Comment: " << ord.comment << endl;
		cout << "Time Ordered: " << ord.timeOrd << endl;
		cout << "Time to Deliver: " << ord.timeRec << endl;
		cout << "User Username: " << ord.userUName << endl;
		cout << "Processed: " << ord.processed << endl;
		cout << "Restaurant Name: " << ord.restName << endl;

		cout << "ID Articles: ";
		for (const auto& id : ord.IDarticles) {
			cout << id << " ";
		}
		cout << endl;

		cout << "Article Names: ";
		for (const auto& artName : ord.artNames) {
			cout << artName << " ";
		}
		cout << endl;

		cout << "------------------------" << endl;

	}

}
