#include "database.hpp"
#include <fstream>
#include <ostream>
#include <pugixml.hpp>
#include <sstream>
#include <string>
#include <vector>

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
    loadPharmaciens();
    loadMedecins();
    loadMedicaments();
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
    if (nom == "None" or nom == "") { return; }
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
    if (nom == "None" or nom == "") { return; }
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
    if (nom == "None" or nom == "") { return; }
    // std::cout << "Insert pathologie" << std::endl;
    sql::PreparedStatement *stmt =
        con->prepareStatement("INSERT INTO Pathologie (Nom, SpecialisationNom) VALUES (?, ?)");
    stmt->setString(1, nom);
    stmt->setString(2, specialisation);
    stmt->execute();
    delete stmt;
}

void Database::loadPharmaciens() const {
    std::cout << "Loading pharmaciens.xml ..." << std::endl;
    std::cout << std::endl;

    std::string specialitesPath = "../data/pharmaciens.xml";
    pugi::xml_document doc;
    if (!doc.load_file(specialitesPath.c_str())) {
        std::cout << "Erreur lors du chargement du fichier XML." << std::endl;
        return;
    }

    for (pugi::xml_node specialiteNode : doc.children("pharmacien")) {
        // Extraire le nom de la spécialité
        pugi::xml_node inamiNode = specialiteNode.child("inami");
        pugi::xml_node nameNode = specialiteNode.child("nom");
        pugi::xml_node mailNode = specialiteNode.child("mail");
        pugi::xml_node telNode = specialiteNode.child("tel");
        std::string inami = "None";
        std::string name = "None";
        std::string mail = "None";
        std::string tel = "None";
        if (inamiNode) {
            inami = inamiNode.text().as_string();
            strip(inami);
        }
        if (mailNode) {
            mail = mailNode.text().as_string();
            strip(mail);
        }
        if (nameNode) {
            name = nameNode.text().as_string();
            strip(name);
        }
        if (telNode) {
            tel = telNode.text().as_string();
            strip(tel);
        }
        // std::cout << "Inami: " << inami << " Name: " << name << " Mail: " << mail << " Tel: " <<
        // tel
        //           << std::endl;
        insertPharmacien(inami, name, mail, tel);
    }

    std::cout << std::endl;
    std::cout << "fini" << std::endl;
    return;
}

void Database::insertPharmacien(const std::string &inami, const std::string &nom,
                                const std::string &email, const std::string &tel) const {
    bool exists = checkIfExists("Pharmacien", "Inami", inami);
    std::vector<std::string> args = {inami, nom, tel, email};
    if (exists) {
        std::cout << inami << " exist "
                  << " Inside Pharmacien" << std::endl;
        return;
    }
    if (inami == "None" or inami == "") { return; }
    // std::cout << "Insert pharmacien" << std::endl;
    sql::PreparedStatement *stmt = con->prepareStatement(
        "INSERT INTO Pharmacien (INAMI, Nom, NumTel, Mail) VALUES (?, ?, ?, ?)");

    for (size_t i = 0; i < args.size(); i++) {
        if (i == 3 and email == "") { // email
            stmt->setNull(i + 1, sql::DataType::VARCHAR);
        } else {
            stmt->setString(i + 1, args[i]);
        }
    }
    stmt->execute();
    delete stmt;
}

void Database::loadMedecins() const {
    std::cout << "Loading medecins.xml ..." << std::endl;
    std::cout << std::endl;

    std::string specialitesPath = "../data/medecins.xml";
    pugi::xml_document doc;
    if (!doc.load_file(specialitesPath.c_str())) {
        std::cout << "Erreur lors du chargement du fichier XML." << std::endl;
        return;
    }

    for (pugi::xml_node specialiteNode : doc.children("medecin")) {
        // Extraire le nom de la spécialité
        pugi::xml_node inamiNode = specialiteNode.child("inami");
        pugi::xml_node mailNode = specialiteNode.child("mail");
        pugi::xml_node nameNode = specialiteNode.child("nom");
        pugi::xml_node specNode = specialiteNode.child("specialite");
        pugi::xml_node telNode = specialiteNode.child("telephone");
        std::string inami = "None";
        std::string name = "None";
        std::string mail = "None";
        std::string specialite = "None";
        std::string tel = "None";
        if (inamiNode) {
            inami = inamiNode.text().as_string();
            strip(inami);
        }
        if (mailNode) {
            mail = mailNode.text().as_string();
            strip(mail);
        }
        if (nameNode) {
            name = nameNode.text().as_string();
            strip(name);
        }
        if (specNode) {
            specialite = specNode.text().as_string();
            strip(specialite);
        }
        if (telNode) {
            tel = telNode.text().as_string();
            strip(tel);
        }
        std::cout << "Inami: " << inami << " Name: " << name << " Mail: " << mail << " Tel: " << tel
                  << " Specialite : " << specialite << std::endl;
        insertSpecialisation(specialite);
        insertMedecin(inami, name, mail, tel, specialite);
    }

    std::cout << std::endl;
    std::cout << "fini2" << std::endl;
    return;
}

void Database::insertMedecin(const std::string &inami, const std::string &nom,
                             const std::string &email, const std::string &tel,
                             const std::string &specilisation) const {
    bool exists = checkIfExists("Medecin", "INAMI", inami);
    std::vector<std::string> args = {inami, nom, tel, email, specilisation};
    if (exists) {
        std::cout << inami << " exist "
                  << " Inside Medecin" << std::endl;
        return;
    }
    if (inami == "None" or inami == "") { return; }
    std::cout << "Insert medecin" << std::endl;
    sql::PreparedStatement *stmt = con->prepareStatement(
        "INSERT INTO Medecin (INAMI, Nom, NumTel, Mail, SpecialisationNom) VALUES (?, ?, ?, ?, ?)");
    for (size_t i = 0; i < args.size(); i++) {
        if (i == 3 and email == "") { // email
            stmt->setNull(i + 1, sql::DataType::VARCHAR);
        } else {
            stmt->setString(i + 1, args[i]);
        }
    }
    stmt->execute();
    delete stmt;
}

void Database::loadMedicaments() const {
    std::string pathologiesPath = "../data/medicaments.csv";
    std::cout << "Loading medicaments.csv ..." << std::endl;
    std::cout << std::endl;
    std::ifstream file(pathologiesPath);
    enum { DCI, NOMCOMMERCIALE, SYSA, CONDITIONNEMENT };
    std::string line;
    std::vector<std::string> args = {"", "", "", ""};
    int i = 0;
    while (std::getline(file, line)) {
        if (i == 0) {
        } else {
            std::istringstream iss(line);
            for (size_t i = 0; i < args.size(); i++) {
                std::getline(iss, args[i], ',');
                strip(args[i]);
            }
            // std::cout << "Pathologie: " << nomPathologie << " Specialisation: " <<
            // nomSpecialisation
            //           << std::endl;
            std::cout << "DCI: " << args[DCI] << " Nom: " << args[NOMCOMMERCIALE]
                      << " Conditionnement: " << args[CONDITIONNEMENT] << std::endl;
            insertMedicament(args[DCI], args[NOMCOMMERCIALE], args[CONDITIONNEMENT]);
        }
        i++;
    }
    return;
}

void Database::insertMedicament(const std::string &dci, const std::string &nom,
                                const std::string &conditionnement) const {
    bool exists =
        checkIfExists3("Medicament", "DCI", "Conditionnement", "Nom", dci, conditionnement, nom);
    std::vector<std::string> args = {dci, nom, conditionnement};
    if (exists) {
        std::cout << dci << " exist "
                  << " Inside Medicament" << std::endl;
        return;
    }
    if (dci == "None" or dci == "") { return; }
    // std::cout << "Insert medicament" << std::endl;
    sql::PreparedStatement *stmt = con->prepareStatement(
        "INSERT INTO Medicament (DCI, Nom, Conditionnement) VALUES (?, ?, ?)");
    for (size_t i = 0; i < args.size(); i++) { stmt->setString(i + 1, args[i]); }
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

bool Database::checkIfExists3(const std::string &table, const std::string &column1,
                              const std::string &column2, const std::string &column3,
                              const std::string &value1, const std::string &value2,
                              const std::string &value3) const {
    // std::cout << "Check if exists with 3 columns" << std::endl;
    // std::cout << "Checking if data exists in table: " << table << std::endl;
    sql::PreparedStatement *stmt =
        con->prepareStatement("SELECT COUNT(*) FROM " + table + " WHERE " + column1 + " = ? AND " +
                              column2 + " = ? AND " + column3 + " = ?");
    std::vector<std::string> args = {value1, value2, value3};
    for (size_t i = 0; i < args.size(); i++) { stmt->setString(i + 1, args[i]); }
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
