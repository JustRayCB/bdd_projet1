#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>
#include <iostream>
#include <memory>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <mysql_error.h>

using namespace std;

int main() {

    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    sql::ConnectOptionsMap connection_properties;
    connection_properties["hostName"] = "tcp://localhost:3306/projetINFOH303_2223";
    connection_properties["userName"] = "root";
    connection_properties["password"] = "root";
    connection_properties["OPT_RECONNECT"] = true; // Optionnel : Permet la reconnexion automatique
                                                   // en cas de déconnexion
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(connection_properties);
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        // con->setSchema("projetINFOH303_2223");
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SHOW TABLES"));
        while (res->next()) {
            cout << "\t... MySQL replies: ";
            /* Access column data by alias or column name */
            cout << res->getString("Tables_in_projetINFOH303_2223") << endl;
        }

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        /* what() (derived from std::runtime_error) fetches error message */
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;

        return EXIT_FAILURE;
    }

    delete con;

    return 0;
}
