#ifndef _DATABASE_HPP_
#define _DATABASE_HPP_

#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <mysql_error.h>
#include <string>

class Database {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    sql::ConnectOptionsMap connection_properties;

public:
    Database();
    Database(Database &&) = default;
    Database(const Database &) = default;
    Database &operator=(Database &&) = default;
    Database &operator=(const Database &) = default;
    ~Database();

    sql::Connection *getConnection() const;
    void showTables() const;

    /**
     * @brief : Initialize the database using data files
     * inside the data folder
     */
    void init() const;

private:
    /**
     * @brief : Load the specialites.xml file
     * and insert the data into the database
     */
    void loadSpecialites() const;
    void insertSystemeAnatomique(const std::string &nom) const;
    void insertSpecialisation(const std::string &nom) const;
    void insertSSS(const std::string &nomSpecialisation,
                   const std::string &nomSystemeAnatomique) const;

    bool checkIfExists(const std::string &table, const std::string &column,
                       const std::string &value) const;
    bool checkIfExists2(const std::string &table, const std::string &column1,
                        const std::string &column2, const std::string &value1,
                        const std::string &value2) const;
};

#endif // !DEBUG
