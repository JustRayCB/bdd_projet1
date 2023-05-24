#include "database.hpp"
#include <bit>
#include <ctime>
#include <fstream>
#include <iostream>
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
    loadPatients();
    loadDiagnostics();
    loadPrescriptions();
}

bool Database::connectUser(const std::string &niss) {
    std::cout << "Je suis dans connect" << std::endl;
    sql::PreparedStatement *stmt = con->prepareStatement("SELECT * FROM Dossier WHERE Niss = ?");
    stmt->setString(1, niss);
    sql::ResultSet *res = stmt->executeQuery();
    if (res->next()) {
        std::vector<std::string> fields = {"Niss",          "Nom",  "Prenom", "Genre",
                                           "DateNaissance", "Mail", "NumTel", "PharmacienINAMI",
                                           "MedecinINAMI"};
        for (auto field : fields) { patient.push_back(res->getString(field)); }
        for (size_t i = 0; i < patient.size(); i++) {
            std::cout << fields[i] << ": " << patient[i] << std::endl;
        }
    }
    delete res;
    delete stmt;
    return (patient.empty()) ? false : true;
}

int Database::changeMP(const std::string &inami, const int which) {
    std::cout << "Change mp" << std::endl;
    bool exists = false;
    std::string columnName;

    if (inami.size() < 10) { return -2; }

    for (auto c : inami) {
        if (!isdigit(c)) { return -2; }
    }

    if (which) {
        // pharmacien
        if (checkIfExists("Medecin", "INAMI", inami)) { return -3; }
        exists = checkIfExists("Pharmacien", "INAMI", inami);
        columnName = "PharmacienINAMI";
    } else {
        // médecin
        if (checkIfExists("Pharmacien", "INAMI", inami)) { return -3; }
        exists = checkIfExists("Medecin", "INAMI", inami);
        columnName = "MedecinINAMI";
    }

    if (not exists) { return -1; }

    sql::PreparedStatement *stmt =
        con->prepareStatement("UPDATE Dossier SET " + columnName + " = ? WHERE Niss = ?");
    stmt->setString(1, inami);
    stmt->setString(2, patient.at(Niss));
    std::cout << "Going to execute" << std::endl;
    stmt->executeUpdate();
    delete stmt;
    std::cout << "Previous Medecin : " << patient.at(MedecinINAMI) << std::endl;
    std::cout << "Previous Pharmacient" << patient.at(PharmacienINAMI) << std::endl;
    if (which) {
        patient.at(PharmacienINAMI) = inami;
    } else {
        patient.at(MedecinINAMI) = inami;
    }
    std::cout << "New Medecin : " << patient.at(MedecinINAMI) << std::endl;
    std::cout << "New Pharmacient" << patient.at(PharmacienINAMI) << std::endl;

    std::cout << "OK" << std::endl;
    return 1;
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
    if (checkIfExists("Pathologie", "Nom", nom)) {
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

    for (pugi::xml_node pharmacienNode : doc.children("pharmacien")) {
        // Extraire le nom de la spécialité
        pugi::xml_node inamiNode = pharmacienNode.child("inami");
        pugi::xml_node nameNode = pharmacienNode.child("nom");
        pugi::xml_node mailNode = pharmacienNode.child("mail");
        pugi::xml_node telNode = pharmacienNode.child("tel");
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

int Database::insertPharmacien(const std::string &inami, const std::string &nom,
                               const std::string &email, const std::string &tel) const {
    std::vector<std::string> args = {inami, nom, tel, email};
    if (checkIfExists("Pharmacien", "INAMI", inami)) {
        std::cout << inami << " exist "
                  << " Inside Pharmacien" << std::endl;
        return -1;
    }
    if (checkIfExists("Medecin", "INAMI", inami)) {
        std::cout << "The inami is already taken by a Medecin" << std::endl;
        return -2;
    }
    if (inami == "None" or inami == "") { return -3; }
    for (size_t i = 0; i < args.size(); i++) {
        if (i == 2 or i == 3) {
        } else if (args[i] == "None" or args[i].empty()) {
            std::cout << "Missing argument " << i << std::endl;
            return -3;
        }
    }
    if (not checkInami(inami)) {
        std::cout << "The inami is not valid" << std::endl;
        return -4;
    }
    if (not(args.at(3).empty() or args.at(3) == "None") and not checkEmail(email)) {
        std::cout << "Mail is not valid" << std::endl;
        return -5;
    }
    if (not(args.at(2).empty() or args.at(2) == "None") and not checkPhone(tel)) {
        std::cout << "Tel is not valid" << std::endl;
        return -6;
    }
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
    return 0;
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

    for (pugi::xml_node medecinNode : doc.children("medecin")) {
        // Extraire le nom de la spécialité
        pugi::xml_node inamiNode = medecinNode.child("inami");
        pugi::xml_node mailNode = medecinNode.child("mail");
        pugi::xml_node nameNode = medecinNode.child("nom");
        pugi::xml_node specNode = medecinNode.child("specialite");
        pugi::xml_node telNode = medecinNode.child("telephone");
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

int Database::insertMedecin(const std::string &inami, const std::string &nom,
                            const std::string &email, const std::string &tel,
                            const std::string &specilisation) const {
    std::vector<std::string> args = {inami, nom, tel, email, specilisation};
    if (checkIfExists("Medecin", "INAMI", inami)) {
        std::cout << inami << " exist "
                  << " Inside Medecin" << std::endl;
        return -1;
    }

    if (checkIfExists("Pharmacien", "INAMI", inami)) {
        std::cout << "The inami of the medecin is already taken by a Pharmacien" << std::endl;
        return -2;
    }
    if (not checkIfExists("Specialisation", "Nom", specilisation)) { return -7; }

    for (size_t i = 0; i < args.size(); i++) {
        if (i == 2 or i == 3) {
        } else if (args[i] == "None" or args[i] == "") {
            std::cout << "The " << i << "th argument is empty" << std::endl;
            return -3;
        }
    }
    if (not checkInami(inami)) {
        std::cout << "The inami is not valid" << std::endl;
        return -4;
    }
    if (not(args.at(3).empty() or args.at(3) == "None") and not checkEmail(email)) {
        std::cout << "Mail is not valid" << std::endl;
        return -5;
    }
    if (not(args.at(2).empty() or args.at(2) == "None") and not checkPhone(tel)) {
        std::cout << "Tel is not valid" << std::endl;
        return -6;
    }

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
    return 0;
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
            insertMedicament(args[DCI], args[NOMCOMMERCIALE], args.at(SYSA), args[CONDITIONNEMENT]);
        }
        i++;
    }
    return;
}

void Database::insertMedicament(const std::string &dci, const std::string &nom,
                                const std::string &sysa, const std::string &conditionnement) const {
    std::vector<std::string> args = {dci, nom, conditionnement, sysa};
    if (std::stoi(conditionnement) <= 0) {
        std::cout << "Conditionnement is negative or null number" << std::endl;
        return;
    }
    if (checkIfExists3("Medicament", "DCI", "Conditionnement", "Nom", dci, conditionnement, nom)) {
        std::cout << dci << " exist "
                  << " Inside Medicament" << std::endl;
        return;
    }
    if (not checkIfExists("SystemeAnatomique", "Nom", sysa)) { insertSystemeAnatomique(sysa); }
    if (dci == "None" or dci == "") { return; }
    // std::cout << "Insert medicament" << std::endl;
    sql::PreparedStatement *stmt =
        con->prepareStatement("INSERT INTO Medicament (DCI, Nom, Conditionnement, "
                              "SystemeAnatomiqueNom) VALUES (?, ?, ?, ?)");
    for (size_t i = 0; i < args.size(); i++) { stmt->setString(i + 1, args[i]); }
    stmt->execute();
    delete stmt;
}

void Database::loadPatients() const {
    std::cout << "Loading patients.xml ..." << std::endl;
    std::cout << std::endl;

    std::string specialitesPath = "../data/patients_corrige.xml";
    pugi::xml_document doc;
    if (!doc.load_file(specialitesPath.c_str())) {
        std::cout << "Erreur lors du chargement du fichier XML." << std::endl;
        return;
    }

    for (pugi::xml_node patientNode : doc.children("patient")) {
        // Extraire le nom de la spécialité
        enum { NISS, BIRTH, SEX, MEDECIN, PHARMACIEN, MAIL, NOM, PRENOM, TEL };
        pugi::xml_node nissNode = patientNode.child("NISS");
        pugi::xml_node birthNode = patientNode.child("date_de_naissance");
        pugi::xml_node sexNode = patientNode.child("genre");
        pugi::xml_node medecinNode = patientNode.child("inami_medecin");
        pugi::xml_node pharmacienNode = patientNode.child("inami_pharmacien");
        pugi::xml_node mailNode = patientNode.child("mail");
        pugi::xml_node nomNode = patientNode.child("nom");
        pugi::xml_node prenomNode = patientNode.child("prenom");
        pugi::xml_node telNode = patientNode.child("telephone");
        std::vector<pugi::xml_node> nodes = {nissNode,    birthNode,      sexNode,
                                             medecinNode, pharmacienNode, mailNode,
                                             nomNode,     prenomNode,     telNode};
        std::vector<std::string> args = {"None", "None", "None", "None", "None",
                                         "None", "None", "None", "None"};
        for (size_t i = 0; i < nodes.size(); i++) {
            if (nodes[i]) {
                args[i] = nodes[i].text().as_string();
                strip(args[i]);
            }
        }
        std::cout << "NISS: " << args[NISS] << " Nom: " << args[NOM] << " Prenom: " << args[PRENOM]
                  << std::endl;
        insertPatient(args.at(NISS), args.at(NOM), args.at(PRENOM), args.at(SEX), args.at(BIRTH),
                      args.at(MAIL), args.at(TEL), args.at(PHARMACIEN), args.at(MEDECIN));
    }

    std::cout << std::endl;
    std::cout << "fini2" << std::endl;
    return;
}

int Database::insertPatient(const std::string &niss, const std::string &nom,
                            const std::string &prenom, const std::string &sexe,
                            const std::string &dateNaissance, const std::string &mail,
                            const std::string &tel, const std::string &pharmacien,
                            const std::string &medecin) const {
    std::vector<std::string> args = {niss, nom, prenom,     sexe,   dateNaissance,
                                     mail, tel, pharmacien, medecin};
    if (checkIfExists("Dossier", "Niss", niss)) {
        std::cout << niss << " exist "
                  << " Inside Dossier" << std::endl;
        return -1;
    }
    // if (niss == "None" or niss == "") { return; }
    for (size_t i = 0; i < args.size(); i++) {
        if (i == 5 or i == 6) {

        } else if (args[i] == "None" or args[i] == "") {
            std::cout << "Argument " << i << " is empty" << std::endl;
            return -2;
        }
    }
    if (not checkNiss(niss)) {
        std::cout << "Niss is not valid" << std::endl;
        return -3;
    }
    if (not(args.at(5).empty() or args.at(5) == "None") and not checkEmail(mail)) {
        std::cout << "Mail is not valid" << std::endl;
        return -4;
    }
    if (not(args.at(6).empty() or args.at(6) == "None") and not checkPhone(tel)) {
        std::cout << "Tel is not valid" << std::endl;
        return -5;
    }
    if (not checkDate(dateNaissance)) {
        std::cout << "=======Date is not valid========" << std::endl;
        return -6;
    }
    // std::cout << "Insert patient" << std::endl;
    sql::PreparedStatement *stmt = con->prepareStatement(
        "INSERT INTO Dossier (Niss, Nom, Prenom, Genre, DateNaissance, Mail, NumTel, "
        "PharmacienINAMI, MedecinINAMI) VALUES (?, ?, ?, ?, STR_TO_DATE(?, '%m/%d/%Y'), ?, ?, ?, "
        "?)");
    for (size_t i = 0; i < args.size(); i++) {
        if (i == 7 and not checkIfExists("Pharmacien", "INAMI", pharmacien)) {
            stmt->setNull(i + 1, sql::DataType::VARCHAR);
        } else if (i == 8 and not checkIfExists("Medecin", "INAMI", medecin)) {
            stmt->setNull(i + 1, sql::DataType::VARCHAR);
        } else if ((i == 5 and args[i] == "None") or (i == 6 and args[i] == "None")) {
            stmt->setNull(i + 1, sql::DataType::VARCHAR);
        } else if (i == 3) {
            if (args[i] == "1") {
                stmt->setString(i + 1, "M");
            } else if (args[i] == "2") {
                stmt->setString(i + 1, "F");
            } else {
                stmt->setString(i + 1, "X");
            }
        } else {
            stmt->setString(i + 1, args[i]);
        }
    }
    stmt->execute();
    delete stmt;
    return 0;
}

void Database::loadDiagnostics() const {

    std::cout << "Loading diagnostiques.xml ..." << std::endl;
    std::cout << std::endl;

    std::string specialitesPath = "../data/diagnostiques.xml";
    pugi::xml_document doc;
    if (!doc.load_file(specialitesPath.c_str())) {
        std::cout << "Erreur lors du chargement du fichier XML." << std::endl;
        return;
    }

    for (pugi::xml_node diagnosticNode : doc.children("diagnostique")) {
        enum { NISS, DATE, BIRTH, PATHO, SPECIALITE };
        pugi::xml_node nissNode = diagnosticNode.child("NISS");
        pugi::xml_node dateNode = diagnosticNode.child("date_diagnostic");
        pugi::xml_node birthNode = diagnosticNode.child("naissance");
        pugi::xml_node pathoNode = diagnosticNode.child("pathology");
        pugi::xml_node specialiteNode = diagnosticNode.child("specialite");
        std::vector<pugi::xml_node> nodes = {nissNode, dateNode, birthNode, pathoNode,
                                             specialiteNode};
        std::vector<std::string> args = {"None", "None", "None", "None", "None"};
        for (size_t i = 0; i < nodes.size(); i++) {
            if (nodes[i]) {
                args[i] = nodes[i].text().as_string();
                strip(args[i]);
            }
        }
        std::cout << "NISS: " << args[NISS] << " Date: " << args[DATE] << " Patho: " << args[PATHO]
                  << " Specialite: " << args[SPECIALITE] << std::endl;
        insertDiagnostic(args.at(NISS), args.at(PATHO), args.at(DATE), args.at(SPECIALITE),
                         args.at(BIRTH));
    }

    std::cout << std::endl;
    std::cout << "fini Diagnositques" << std::endl;
    return;
}

void Database::insertDiagnostic(const std::string &niss, const std::string &pathologie,
                                std::string &date, const std::string &specialite,
                                const std::string &birth) const {
    std::vector<std::string> args = {niss, pathologie, date};
    if (checkIfExists3("DossierContientPathologie", "DossierID", "PathologieNom",
                       "DateDiagnostique", niss, pathologie, transformDate(date))) {
        std::cout << niss << " exist " << pathologie << " exist "
                  << " Inside DossierContientPathologie" << std::endl;
        return;
    }
    if (niss == "None" or niss == "") { return; }
    if (pathologie == "None" or pathologie == "") { return; }
    if (not isDate1MoreRecent(date, birth)) {
        std::cout << "Diagnostic birth is more recent than date" << std::endl;
        return;
    }
    if (not checkIfExists("Dossier", "Niss", niss)) {
        std::cout << "Dossier does not exist " << std::endl;
        return;
    }
    insertSpecialisation(specialite);
    insertPathologie(pathologie, specialite);

    sql::PreparedStatement *stmt = con->prepareStatement(
        "INSERT INTO DossierContientPathologie (DossierID, PathologieNom, DateDiagnostique) "
        "VALUES (?, ?, STR_TO_DATE(?, '%m/%d/%Y'))");
    for (size_t i = 0; i < args.size(); i++) { stmt->setString(i + 1, args[i]); }
    stmt->execute();
    delete stmt;
}

std::string Database::transformDate(std::string date) const {
    std::string month = date.substr(0, 2);
    std::string day = date.substr(3, 2);
    std::string year = date.substr(6, 4);
    date = year + "-" + month + "-" + day;
    return date;
}

void Database::loadPrescriptions() const {
    std::string prescriptionPath = "../data/dossiers_patients.csv";
    std::cout << "Loading dossier_patients.csv ..." << std::endl;
    std::cout << std::endl;
    std::ifstream file(prescriptionPath);
    // NISS_patient,medecin,inami_medecin,pharmacien,inami_pharmacien,medicament_nom_commercial,
    // DCI,date_prescription,date_vente,duree_traitement
    enum {
        NISS,
        MEDECIN,
        INAMI_MEDECIN,
        PHARMACIEN,
        INAMI_PHARMACIEN,
        MEDICAMENT,
        DCI,
        DATE,
        VENTE,
        DUREE
    };
    std::string line;
    std::vector<std::string> args = {"None", "None", "None", "None", "None",
                                     "None", "None", "None", "None", "None"};
    int i = 0;
    while (std::getline(file, line)) {
        if (i == 0) {
        } else {
            std::istringstream iss(line);
            for (size_t i = 0; i < args.size(); i++) {
                std::getline(iss, args[i], ',');
                strip(args[i]);
            }
            // std::cout << "NISS: " << args[NISS] << " Medecin: " << args[MEDECIN]
            //           << " Inami Medecin: " << args[INAMI_MEDECIN]
            //           << " Pharmacien: " << args[PHARMACIEN]
            //           << " Inami Pharmacien: " << args[INAMI_PHARMACIEN]
            //           << " Medicament: " << args[MEDICAMENT] << " DCI: " << args[DCI]
            //           << " Date: " << args[DATE] << " Duree: " << args[DUREE] << std::endl;
            int prescriptionId =
                insertPrescription(args[INAMI_MEDECIN], args[NISS], args[PHARMACIEN], args[MEDECIN],
                                   args[MEDICAMENT], args[DATE], args[DUREE]);
            if (prescriptionId != -1) {
                // find the medicmanet id
                int medicamentId = -1;
                sql::PreparedStatement *stmt =
                    con->prepareStatement("SELECT ID FROM Medicament WHERE Nom = ? AND DCI = ?"
                                          " AND Conditionnement >= ? "
                                          " ORDER BY Conditionnement ASC "
                                          " LIMIT 1");
                stmt->setString(1, args[MEDICAMENT]);
                stmt->setString(2, args[DCI]);
                stmt->setString(3, args[DUREE]);
                sql::ResultSet *res = stmt->executeQuery();
                if (res->next()) { medicamentId = res->getInt("ID"); }
                delete res;
                delete stmt;
                if (medicamentId == -1) {
                    std::cout << "Medicament not found, taking the one with max conditionnement"
                              << std::endl;
                    sql::PreparedStatement *stmt =
                        con->prepareStatement("SELECT ID FROM Medicament WHERE Nom = ? AND DCI = ?"
                                              " ORDER BY Conditionnement DESC"
                                              " LIMIT 1");
                    stmt->setString(1, args[MEDICAMENT]);
                    stmt->setString(2, args[DCI]);
                    sql::ResultSet *res = stmt->executeQuery();
                    if (res->next()) { medicamentId = res->getInt("ID"); }
                }
                std::cout << "I foutnd the medicament id" << medicamentId << std::endl;
                insertPharmacienDelivreMedicament(args[INAMI_PHARMACIEN],
                                                  std::to_string(prescriptionId),
                                                  std::to_string(medicamentId), args[VENTE]);
            }
        }
        i++;
    }
    std::cout << "Nombre de prescriptions : " << i << std::endl;
    return;
}

int Database::insertPrescription(const std::string &medecinINAMI, const std::string &dossier,
                                 const std::string &pharmacien, const std::string &medecinNom,
                                 const std::string &medicament, std::string &datePrescription,
                                 const std::string &duree) const {
    std::vector<std::string> args = {medecinINAMI, dossier,          pharmacien, medecinNom,
                                     medicament,   datePrescription, duree};
    // no need to check if a prescription exists, because it is possible to have the same
    // prescription twice
    if (std::stoi(duree) <= 0) { // check if the duree is negative or null
        std::cout << "Duree is negative" << std::endl;
        return -1;
    }
    if (checkIfExists3("Prescription", "DossierID", "MedicamentNom", "DatePrescription", dossier,
                       medicament, transformDate(datePrescription))) {
        std::cout << medecinINAMI << " exist " << dossier << " exist " << pharmacien
                  << " exist Inside Prescription" << std::endl;
        return -1;
    }
    if (not checkIfExists("Dossier", "Niss", dossier)) {
        std::cout << "Dossier does not exist " << std::endl;
        return -1;
    }
    if (not checkIfExists("Medecin", "INAMI", medecinINAMI)) {
        std::cout << "Medecin does not exist " << std::endl;
        return -1;
    }
    if (not checkIfExists("Pharmacien", "Nom", pharmacien)) {
        std::cout << "Pharmacien does not exist " << std::endl;
        return -1;
    }
    if (not checkIfExists("Medicament", "Nom", medicament)) {
        std::cout << "Medicament does not exist " << std::endl;
        return -1;
    }
    sql::PreparedStatement *stmt = con->prepareStatement(
        "INSERT INTO Prescription (MedecinINAMI, DossierID, PharmacienNom, MedecinNom, "
        "MedicamentNom, DatePrescription, DureeTraitement) VALUES (?, ?, ?, ?, ?, STR_TO_DATE(?, "
        "'%m/%d/%Y'), ?)");
    for (size_t i = 0; i < args.size(); i++) { stmt->setString(i + 1, args[i]); }
    stmt->execute();
    delete stmt;
    sql::Statement *stmt2 = con->createStatement();
    stmt2 = con->createStatement();
    sql::ResultSet *res = stmt2->executeQuery("SELECT LAST_INSERT_ID()");
    int prescriptionId = -1;
    if (res->next()) {
        prescriptionId = res->getInt(1);
        std::cout << "ID de la prescription insérée : " << prescriptionId << std::endl;
    }
    delete stmt2;
    delete res;
    return prescriptionId;
}

void Database::insertPharmacienDelivreMedicament(const std::string &pharmacien,
                                                 const std::string &prescription,
                                                 const std::string &medicament,
                                                 const std::string &dateDelivrance) const {

    std::vector<std::string> args = {pharmacien, prescription, medicament, dateDelivrance};
    if (checkIfExists2("PharmacienDelivreMedicament", "PharmacienINAMI", "PrescriptionID",
                       pharmacien, prescription)) {
        std::cout << pharmacien << " exist " << prescription << " exist "
                  << " Inside PharmacienDelivreMedicament" << std::endl;
        return;
    }
    // TODO: Find the correct medicament that can covered a max of duration of prescrption
    sql::PreparedStatement *stmt = con->prepareStatement(
        "INSERT INTO PharmacienDelivreMedicament (PharmacienINAMI, PrescriptionID, "
        "MedicamentID, DateDelivrance) VALUES (?, ?, ?, STR_TO_DATE(?, '%m/%d/%Y'))");
    for (size_t i = 0; i < args.size(); i++) { stmt->setString(i + 1, args[i]); }
    stmt->execute();
    delete stmt;
}

bool Database::isDate1MoreRecent(const std::string &date1, const std::string &date2) const {

    struct tm tm1 = {};
    struct tm tm2 = {};
    time_t t1, t2;
    strptime(date1.c_str(), "%m/%d/%Y", &tm1);
    strptime(date2.c_str(), "%m/%d/%Y", &tm2);
    t1 = mktime(&tm1);
    t2 = mktime(&tm2);
    return t1 >= t2;
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

void Database::strip(std::string &str) {
    str.erase(0, str.find_first_not_of(" \r\n")); // supprime les espaces au début
    str.erase(str.find_last_not_of(" \r\n") + 1); // supprime les espaces à la fin
}

bool Database::checkInami(const std::string &inami) const {
    if (inami.size() < 10) { return false; }
    for (size_t i = 0; i < inami.size(); i++) {
        if (not std::isdigit(inami[i])) { return false; }
    }
    return true;
}

bool Database::checkPhone(const std::string &phone) const {
    if (phone.size() < 12) {
        std::cout << "Not a good size for a phone number" << std::endl;
        return false;
    }
    if (phone[0] != '+') {
        std::cout << "Not a good format for a phone number" << std::endl;
        return false;
    }
    if (phone.substr(0, 3) != "+32") {
        std::cout << "Not a good format +32 for a phone number" << std::endl;
        return false;
    }
    for (size_t i = 1; i < phone.size(); i++) {
        if (not std::isdigit(phone[i])) {
            std::cout << "The is a signe wich is not a digit: " << phone[i] << std::endl;
            return false;
        }
    }
    return true;
}

bool Database::checkEmail(const std::string &email) const {
    if (email.size() < 5) { return false; }
    if (email.find('@') == std::string::npos) { return false; }
    if (email.find('.') == std::string::npos) { return false; }
    return true;
}

bool Database::checkNiss(const std::string &niss) const {
    if (niss.size() < 10) { return false; }
    for (size_t i = 0; i < niss.size(); i++) {
        if (not std::isdigit(niss[i])) { return false; }
    }
    return true;
}

bool Database::checkDate(const std::string &date) const {
    if (date.size() != 10) {
        std::cout << "Not a good size for a date" << std::endl;
        return false;
    }
    if (date[2] != '/' or date[5] != '/') {
        std::cout << "Not a good format for a date" << std::endl;
        return false;
    }
    for (size_t i = 0; i < date.size(); i++) {
        if (i != 2 and i != 5) {
            if (not std::isdigit(date[i])) {
                std::cout << "This is not a digit" << std::endl;
                return false;
            }
        }
    }
    // check if the date is after today
    std::time_t now = std::time(0);
    std::tm *today = std::localtime(&now);
    std::tm otherDate = {};

    otherDate.tm_mday = std::stoi(date.substr(3, 2));
    otherDate.tm_mon = std::stoi(date.substr(0, 2)) - 1;
    otherDate.tm_year = std::stoi(date.substr(6, 4)) - 1900;

    std::time_t t1 = std::mktime(&otherDate);
    // std::time_t td = std::mktime(today);
    if (today->tm_mday == otherDate.tm_mday && today->tm_mon == otherDate.tm_mon &&
        today->tm_year == otherDate.tm_year) {
        std::cout << "date is today" << std::endl;
        return true;
    } else if (t1 < now) {
        std::cout << "date is before today" << std::endl;
        return true;
    }
    std::cout << "date is after today" << std::endl;
    return false;
}
