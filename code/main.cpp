#include "database.hpp"
#include <iostream>
#include <mysql_error.h>

using namespace std;

int main() {
    // NOTE: execute -> pour les requêtes qui ne retournent rien
    //       executeQuery -> pour les requêtes qui retournent quelque chose
    try {
        Database db;
        db.showTables();
        db.init();
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        /* what() (derived from std::runtime_error) fetches error message */
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;

        return EXIT_FAILURE;
    }

    return 0;
}
