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

    /**
     * @brief: Insert an anatomic system into the SystemAnatomique table
     *
     * @param nom: The name of the anatomic system
     **/
    void insertSystemeAnatomique(const std::string &nom) const;

    /**
     * @brief: Insert a specialites into the Specialisation table
     * @param nom: The name of the specialisation
     **/
    void insertSpecialisation(const std::string &nom) const;

    /**
     * @brief: Insert a specialisation and an anatomic system into the
     *  SpecialisationSpecialiseSysAnatomique table
     *
     * @param nomSpecialisation: The name of the specialisation
     * @param nomSystemeAnatomique: The name of the anatomic system
     **/
    void insertSSS(const std::string &nomSpecialisation,
                   const std::string &nomSystemeAnatomique) const;

    /**
     * @brief : Load the pathologies.csv file
     * and insert the data into the database
     */
    void loadPathologies() const;

    /**
     * @brief: Insert a pathology into the Pathologie table
     *
     * @param nom: The name of the pathology
     * @param specialisation: The specialisation of the pathology
     **/
    void insertPathologie(const std::string &nom, const std::string &specialisation) const;

    /**
     * @brief : Load the pharmaciens.xml file
     * and insert the data into the database
     */
    void loadPharmaciens() const;

    /**
     * @brief: Insert a pharmacist into the Pharamacien table
     *
     * @param inami: Inami of the pharmacist
     * @param nom: Name of the pharmacist
     * @param email: Mail of the pharmacist
     * @param tel: Phone number of the pharmacist
     **/
    void insertPharmacien(const std::string &inami, const std::string &nom,
                          const std::string &email, const std::string &tel) const;

    /**
     * @brief : Load the medecins.xml file
     * and insert the data into the database
     */
    void loadMedecins() const;

    /**
     * @brief: Insert a doctor into the Medecin table
     *
     * @param inami: Inami of the doctor
     * @param nom: Name of the doctor
     * @param email: Mail of the doctor
     * @param tel: Phone number of the doctor
     * @param specialisation: Specialisation of the doctor
     **/
    void insertMedecin(const std::string &inami, const std::string &nom, const std::string &email,
                       const std::string &tel, const std::string &specilisation) const;

    /**
     * @brief: Check if a value exist in a table
     *
     * @param table: The name of the table to check
     * @param column: The name of the column that contains value
     * @param value: The value
     *
     * @return: True if the value exists, false otherwise
     **/
    bool checkIfExists(const std::string &table, const std::string &column,
                       const std::string &value) const;

    /**
     * @brief: Same as above but with 2 columns cause the table has
     * a primary key with 2 values
     **/
    bool checkIfExists2(const std::string &table, const std::string &column1,
                        const std::string &column2, const std::string &value1,
                        const std::string &value2) const;

    /**
     * @brief: Remove space before and after a string
     **/
    void strip(std::string &str) const;
};

#endif // !DEBUG
