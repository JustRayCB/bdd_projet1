#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <mysql_error.h>

using namespace std;

int main() {

  sql::mysql::MySQL_Driver *driver;
  sql::Connection *con;

  driver = sql::mysql::get_mysql_driver_instance();
  sql::ConnectOptionsMap connection_properties;
  connection_properties["hostName"] =
      "tcp://localhost:3306/projetINFOH303_2223";
  connection_properties["userName"] = "root";
  connection_properties["password"] = "root";
  connection_properties["OPT_RECONNECT"] =
      true; // Optionnel : Permet la reconnexion automatique en cas de
            // déconnexion
  con = driver->connect(connection_properties);

  if (con->isValid()) {
    cout << "Connection is valid" << endl;
  } else {
    cout << "Connection is invalid" << endl;
  }
  delete con;

  return 0;
}
