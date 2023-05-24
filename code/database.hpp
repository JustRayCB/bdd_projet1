#ifndef _DATABASE_HPP_
#define _DATABASE_HPP_

#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <mysql_error.h>
#include <string>
#include <vector>

class Database {
    enum { Niss, Nom, Prenom, Genre, DateNaissance, Mail, NumTel, PharmacienINAMI, MedecinINAMI };
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    sql::ConnectOptionsMap connection_properties;
    std::vector<std::string> patient;

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

    /*
     * @brief : Check if the patient is in the db and stock his info
     *
     * @param niss: NISS of the patient
     * @return: A vector containing the info of the patient
     */
    bool connectUser(const std::string &niss);

    /*
     * @brief: Change the Medecin or the Pharamacien of the patient
     *
     * @param inami: Inami of the new doctor or pharmacistZ
     * @param which: 0 if it's a doctor, 1 if it's a pharmacist
     * @return: True if the change was successful, false otherwise
     */
    int changeMP(const std::string &inami, const int which);

    /**
     * @brief: Remove space before and after a string
     **/
    static void strip(std::string &str);

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
    int insertMedecin(const std::string &inami, const std::string &nom, const std::string &email,
                      const std::string &tel, const std::string &specilisation) const;

    /**
     * @brief : Load the medicaments.csv file
     * and insert the data into the database
     */
    void loadMedicaments() const;

    /**
     * @brief: Insert a medicament into the Medicament table
     *
     * @param dci: DCI of the medicament
     * @param nom: Name of the medicament
     * @param conditionnement: Conditionnement of the medicament
     **/
    void insertMedicament(const std::string &dci, const std::string &nom, const std::string &sysa,
                          const std::string &conditionnement) const;

    /**
     * @brief : Load the patient.xml file
     * and insert the data into the database
     */
    void loadPatients() const;

    /**
     * @brief: Insert a patient into the Patient table
     *
     * @param niss: NISS of the patient
     * @param nom: Name of the patient
     * @param prenom: First name of the patient
     * @param sexe: Gender of the patient
     * @param dateNaissance: Date of birth of the patient
     * @param mail: Mail of the patient
     * @param tel: Phone number of the patient
     * @param pharmacien: Inami of the pharmacist of the patient
     * @param medecin: Inami of the doctor of the patient
     * */
    int insertPatient(const std::string &niss, const std::string &nom, const std::string &prenom,
                      const std::string &sexe, const std::string &dateNaissance,
                      const std::string &mail, const std::string &tel,
                      const std::string &pharmacien, const std::string &medecin) const;

    /**
     * @brief : Load the diagnostiques.xml file
     * and insert the data into the database
     */
    void loadDiagnostics() const;

    /**
     * @brief: Insert a diagnostic into the DossierContientPathologie table
     *
     * @param niss: NISS of the Patient
     * @param pathologie: Name of the pathology
     * @param date: Date of the diagnostic
     **/
    void insertDiagnostic(const std::string &niss, const std::string &pathologie, std::string &date,
                          const std::string &specialite, const std::string &birth) const;

    /**
     * @brief : Load the diagnostiques.xml file
     * and insert the data into the database
     */
    void loadPrescriptions() const;

    /**
     * @brief: Insert a prescription into the Prescription table
     *
     * @param medecinINAMI: Inami of the doctor who wrote the prescription
     * @param dossier: NISS of the patient
     * @param pharmacien: Inami of the pharmacist who delivered the medicament
     * @param medecinNom: Name of the doctor who wrote the prescription
     * @param medicament: name of the medicament
     * @return: The id of the prescription inserted
     **/
    int insertPrescription(const std::string &medecinINAMI, const std::string &dossier,
                           const std::string &pharmacien, const std::string &medecinNom,
                           const std::string &medicament, std::string &datePrescription,
                           const std::string &duree) const;

    void insertPharmacienDelivreMedicament(const std::string &pharmacien,
                                           const std::string &prescription,
                                           const std::string &medicament,
                                           const std::string &dateDelivrance) const;

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

    bool checkIfExists3(const std::string &table, const std::string &column1,
                        const std::string &column2, const std::string &column3,
                        const std::string &value1, const std::string &value2,
                        const std::string &value3) const;

    bool isDate1MoreRecent(const std::string &date1, const std::string &date2) const;

    std::string transformDate(std::string date) const;

    bool checkInami(const std::string &inami) const;

    bool checkPhone(const std::string &phone) const;

    bool checkEmail(const std::string &email) const;

    bool checkNiss(const std::string &niss) const;

    bool checkDate(const std::string &date) const;
};

#endif // !DEBUG
