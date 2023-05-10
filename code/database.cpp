#include "database.hpp"
#include <fstream>
#include <ostream>
#include <pugixml.hpp>
#include <sstream>
#include <string>

Database::Database() {
    connection_properties["hostName"] = "tcp://localhost:3306/projetINFOH303_2223";
    connection_properties["userName"] = "root";
    connection_properties["password"] = "root";
    connection_properties["OPT_RECONNECT"] = true; // Optionnel : Permet la reconnexion automatique
                                                   // en cas de déconnexion
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect(connection_properties); // Connexion à la base de données
    // con->setSchema("projetINFOH303_2223"); // Sélection de la base de données
}

Database::~Database() { delete con; }

sql::Connection *Database::getConnection() const { return con; }

void Database::showTables() const {
    std::cout << "========================" << std::endl;
    std::cout << "Showing the tables" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << std::endl;
    sql::Statement *stmt = con->createStatement();
    sql::ResultSet *res = stmt->executeQuery("SHOW TABLES");

    while (res->next()) { std::cout << res->getString(1) << std::endl; }
    std::cout << "========================" << std::endl;
    std::cout << std::endl;

    delete res;
    delete stmt;
}

void Database::init() const {
    /* Dossier
    DossierContientPathologie
    Medecin
    MedecinPrescritPrescription
    Medicament
    Pathologie
    Pharmacien
    PharmacienDelivreMedicament
    Prescription
    Specialisation
    SpecialisationSpecialiseSysAnatomique
    SystemeAnatomique */
    std::cout << "Loading the database ..." << std::endl;
    std::cout << std::endl;
    /*
     * NOTE: Les fichier:
     * - specialites.xml et pathologies.csv doivent êtres initiallisés ensemble
     *   ces 2 fichiers devront remplire les tables:
     *      - Specialisation
     *      - SpecialisationSpecialiseSysAnatomique
     *      - SystemeAnatomique
     *      - Pathologie
     *      Ou specialites.xml remplis les 3 premières et pathologie la dernière
     **/
    loadSpecialites();
    loadPathologies();
}

void Database::loadSpecialites() const {
    // NOTE: Il faut remplire d'abord système anatomique avant la donnée de specialites
    std::cout << "Loading specialites.xml ..." << std::endl;

    std::cout << std::endl;
    std::string specialitesPath = "../data/specialites.xml";
    pugi::xml_document doc;
    if (!doc.load_file(specialitesPath.c_str())) {
        std::cout << "Erreur lors du chargement du fichier XML." << std::endl;
        return;
    }

    for (pugi::xml_node specialiteNode : doc.children("specialite")) {
        // Extraire le nom de la spécialité
        pugi::xml_node nameNode = specialiteNode.child("name");
        std::string nomSpecialite = "None";
        std::string nomSystemeAnatomique = "None";
        if (nameNode) {
            nomSpecialite = nameNode.text().get();
            strip(nomSpecialite);
            insertSpecialisation(nomSpecialite);
        }
        // Parcourir les nœuds "medicament" which actually is not a medicament but a systeme
        for (pugi::xml_node medicamentNode : specialiteNode.children("medicament")) {
            nomSystemeAnatomique = medicamentNode.text().get();
            strip(nomSystemeAnatomique);
            insertSystemeAnatomique(nomSystemeAnatomique);
            insertSSS(nomSpecialite, nomSystemeAnatomique);
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return;
}

void Database::insertSystemeAnatomique(const std::string &nom) const {
    bool exists = checkIfExists("SystemeAnatomique", "Nom", nom);
    if (exists) {
        std::cout << nom << " exist "
                  << " inside SystemeAnatomique " << std::endl;
        return;
    }
    if (nom == "None") { return; }
    std::cout << "Insert Systeme anatomique" << std::endl;
    sql::PreparedStatement *stmt =
        con->prepareStatement("INSERT INTO SystemeAnatomique (Nom) VALUES (?)");
    stmt->setString(1, nom);
    stmt->execute();
    delete stmt;
}

void Database::insertSpecialisation(const std::string &nom) const {
    bool exists = checkIfExists("Specialisation", "Nom", nom);
    if (exists) {
        std::cout << nom << " exist "
                  << " inside Specialisation " << std::endl;
        return;
    }
    if (nom == "None") { return; }
    std::cout << "Insert specialisation" << std::endl;
    sql::PreparedStatement *stmt =
        con->prepareStatement("INSERT INTO Specialisation (Nom) VALUES (?)");
    stmt->setString(1, nom);
    stmt->execute();
    delete stmt;
}

void Database::insertSSS(const std::string &nomSpecialisation,
                         const std::string &nomSystemeAnatomique) const {
    bool exists = checkIfExists2("SpecialisationSpecialiseSysAnatomique", "SpecialisationNom",
                                 "SystemeAnatomiqueNom", nomSpecialisation, nomSystemeAnatomique);
    if (exists) {
        std::cout << nomSpecialisation << " " << nomSystemeAnatomique << " exist "
                  << " inside SpecialisationSpecialiseSysAnatomique " << std::endl;
        return;
    }
    if (nomSpecialisation == "None" or nomSystemeAnatomique == "None") { return; }
    std::cout << "Insert SSS" << std::endl;
    sql::PreparedStatement *stmt = con->prepareStatement(
        "INSERT INTO SpecialisationSpecialiseSysAnatomique (SpecialisationNom , "
        "SystemeAnatomiqueNom) VALUES (?, ?)");
    stmt->setString(1, nomSpecialisation);
    stmt->setString(2, nomSystemeAnatomique);
    stmt->execute();
    delete stmt;
}

void Database::loadPathologies() const {
    std::string pathologiesPath = "../data/pathologies.csv";
    std::cout << "Loading pathologies.csv ..." << std::endl;
    std::cout << std::endl;
    std::ifstream file(pathologiesPath);
    std::string line;
    std::string nomPathologie = "None";
    std::string nomSpecialisation = "None";
    int i = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::getline(iss, nomPathologie, ',');
        std::getline(iss, nomSpecialisation, ',');
        // std::cout << "Pathologie: " << nomPathologie << " Specialisation: " << nomSpecialisation
        //           << std::endl;
        strip(nomPathologie);
        strip(nomSpecialisation);
        insertSpecialisation(nomSpecialisation);
        insertPathologie(nomPathologie, nomSpecialisation);
        i++;
    }
    std::cout << "Number of pathologies: " << i << std::endl;

    return;
}

void Database::insertPathologie(const std::string &nom, const std::string &specialisation) const {
    bool exists = checkIfExists("Pathologie", "Nom", nom);
    if (exists) {
        std::cout << nom << " exist "
                  << " Inside Pathologie" << std::endl;
        return;
    }
    if (nom == "None") { return; }
    // std::cout << "Insert pathologie" << std::endl;
    sql::PreparedStatement *stmt =
        con->prepareStatement("INSERT INTO Pathologie (Nom, SpecialisationNom) VALUES (?, ?)");
    stmt->setString(1, nom);
    stmt->setString(2, specialisation);
    stmt->execute();
    delete stmt;
}

bool Database::checkIfExists(const std::string &table, const std::string &column,
                             const std::string &value) const {
    // std::cout << "Check if exists with 1 column" << std::endl;
    // std::cout << "Checking if data exists in table: " << table << std::endl;
    sql::PreparedStatement *stmt =
        con->prepareStatement("SELECT COUNT(*) FROM " + table + " WHERE " + column + " = ?");
    stmt->setString(1, value);
    sql::ResultSet *res = stmt->executeQuery();
    res->next();
    int count = res->getInt(1);
    delete stmt;
    delete res;

    return count > 0;
}

bool Database::checkIfExists2(const std::string &table, const std::string &column1,
                              const std::string &column2, const std::string &value1,
                              const std::string &value2) const {
    // std::cout << "Check if exists with 2 columns" << std::endl;
    // std::cout << "Checking if data exists in table: " << table << std::endl;
    sql::PreparedStatement *stmt = con->prepareStatement(
        "SELECT COUNT(*) FROM " + table + " WHERE " + column1 + " = ? AND " + column2 + " = ?");
    stmt->setString(1, value1);
    stmt->setString(2, value2);
    sql::ResultSet *res = stmt->executeQuery();
    res->next();
    int count = res->getInt(1);
    delete stmt;
    delete res;

    return count > 0;
}

void Database::strip(std::string &str) const {
    str.erase(0, str.find_first_not_of(" \r\n")); // supprime les espaces au début
    str.erase(str.find_last_not_of(" \r\n") + 1); // supprime les espaces à la fin
}
