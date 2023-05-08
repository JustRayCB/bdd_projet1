/* Toutes les tables:
    - Patient
    - Pharmacien
    - Médecin
    - Spécialisations (de médecin)
    - Prescription
    - Traitement
    - MédecinDonneTraitement
    - Médicament
    - TraitementContientMédicament
    - PhramacienDélivreMédicament
    - DossierContientPathologie
    - Pathologie
 TODO: Table Dossier
*/

-- WARNING: Un patient peut avoir plusieurs DOSSIERS, 
--          mais un seul DOSSIER peut être lié à un patient
/*
 WARNING: Je vais supprimer la table Patient et mettre tous dans la table dossier
*/
CREATE DATABASE projetINFOH303_2223 if not exists;
USE projetINFOH303_2223;

/* Création de la table Patient 
 NOTE: Patient à besoin de Medecin, pharmacien et dossier
*/ 

/*
 WARNING: La table Patient et la Tale Dossier sont fusionnées (dossier n'existait pas avant)
 En Effet, il y a une relation 1, 1. Et j'ai décidé de mettre les infos du patient dans le dossier
*/
CREATE TABLE Dossier (
    ID INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    Niss INT NOT NULL,
    Nom VARCHAR(50) NOT NULL,
    Prenom VARCHAR(50) NOT NULL,
    Genre VARCHAR(1) NOT NULL,
    DateNaissance DATE NOT NULL,
    Mail VARCHAR(50) DEFAULT NULL,
    NumTel INT DEFAULT NULL,
    PharmacienINAMI INT NOT NULL,
    MedecinINAMI INT NOT NULL,
    FOREIGN KEY (PharmacienINAMI) REFERENCES Pharmacien(INAMI) ON DELETE SET NULL,
    FOREIGN KEY (MedecinINAMI) REFERENCES Medecin(INAMI) ON DELETE SET NULL,
);

/* Création de la table Pharmacien */ 
CREATE TABLE Pharmacien (
    INAMI INT NOT NULL PRIMARY KEY,
    Nom VARCHAR(50) NOT NULL,
    NumTel INT NOT NULL,
    Mail VARCHAR(50) DEFAULT NULL
);

/* 
Création de la table Médecin 
 NOTE: Médecin à besoin de Spécialisation 
 */
CREATE TABLE Medecin (
    INAMI INT NOT NULL PRIMARY KEY,
    Nom VARCHAR(50) NOT NULL,
    NumTel INT NOT NULL,
    Mail VARCHAR(50) DEFAULT NULL,
    SpecialisationNom INT NOT NULL,
    FOREIGN KEY (SpecialisationNom) REFERENCES Specialisation(Nom) ON DELETE SET NULL
);

/* Création de la table Spécialisation */ 
CREATE TABLE Specialisation (
    Nom VARCHAR(50) NOT NULL PRIMARY KEY,
    Systeme VARCHAR(50) DEFAULT NULL,
    FOREIGN KEY(Systeme) REFERENCES SystemeAnatomique(Nom) ON DELETE SET NULL
);

/* 
Création de la table Prescription 
    NOTE: Prescription à besoin de Traitement et Médecin
    On a merge Prescription et Traitement
 */
CREATE TABLE Prescription (
    ID INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    MedecinINAMI INT DEFAULT NULL,
    DossierID INT NOT NULL,
    PharmacienNom INT DEFAULT NULL,
    MedecinNom INT DEFAULT NULL,
    MedicamentNom VARCHAR(50) DEFAULT NULL, -- Celui choisi par le médecin
    MedicamentID INT DEFAULT NULL, -- Celui choisi par le pharmacien
    FOREIGN KEY (MedecinINAMI) REFERENCES Medecin(INAMI) ON DELETE SET NULL,
    FOREIGN KEY (DossierID) REFERENCES Dossier(ID) ON DELETE CASCADE,
    FOREIGN KEY(MedicamentID) REFERENCES Medicament(ID) ON DELETE SET NULL,
    -- FOREIGN KEY (MedicamentNom) REFERENCES Medicament(Nom) ON DELETE SET NULL
    -- FOREIGN KEY (MedecinNom) REFERENCES Medecin(Nom) ON DELETE SET NULL,
    -- FOREIGN KEY (PharmacienINAMI) REFERENCES Pharmacien(INAMI) ON DELETE SET NULL,
);

/*
Création de la table MédecinPrescritPrescription
    NOTE: MédecinPrescritPrescription à besoin de Médecin et Prescription
*/
CREATE TABLE MedecinPrescritPrescription (
    MedecinINAMI INT NOT NULL,
    PrescriptionID INT NOT NULL,
    DateDebutTraitement DATE NOT NULL,
    DuréeTraitement INT NOT NULL,
    FOREIGN KEY (MedecinINAMI) REFERENCES Medecin(INAMI) ON DELETE CASCADE,
    FOREIGN KEY (PrescriptionID) REFERENCES Prescription(ID) ON DELETE CASCADE,
    PRIMARY KEY (MedecinINAMI, PrescriptionID)
);

/*
Création de la table Médicament
*/
CREATE TABLE Medicament(
    ID INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    DCI VARCHAR(50) NOT NULL,
    Nom VARCHAR(50) NOT NULL,
    Conditionnement INT NOT NULL,
);

/*
Création de la table PharmacienDélivreMédicament
    NOTE: PharmacienDélivreMédicament à besoin de Pharmacien et Médicament
*/
CREATE TABLE PharmacienDelivreMedicament(
    PharmacienINAMI INT NOT NULL,
    MedicamentDCI VARCHAR(50) NOT NULL,
    FOREIGN KEY (PharmacieINAMI) REFERENCES Pharmacie(INAMI) ON DELETE CASCADE,
    FOREIGN KEY (MedicamentDCI) REFERENCES Medicament(DCI) ON DELETE CASCADE,
    PRIMARY KEY (PharmacieINAMI, MedicamentDCI)
);

/*
Création de la table Dossier
    NOTE: Dossier à besoin Dossier et de Pathologie
*/
CREATE TABLE DossierContientPathologie (
    DID INT NOT NULL PRIMARY KEY,
    PathologieNom INT NOT NULL,
    DateDiagnostique DATE NOT NULL,
    FOREIGN KEY (DID) REFERENCES Dossier(ID) ON DELETE CASCADE,
    FOREIGN KEY (PathologieNom) REFERENCES Pathologie(Nom) ON SET NULL,
    PRIMARY KEY (DID, PathologieID)
);

/*
Création de la table Pathologie 
    NOTE: Pathologie à besoin de Spécialisation
*/
CREATE TABLE Pathologie (
    Nom VARCHAR(50) NOT NULL PRIMARY KEY,
    Systeme VARCHAR(50) NOT NULL
    SpecialisationNom VARCHAR(50) NOT NULL,
    FOREIGN KEY (SpecialisationNom) REFERENCES Specialisation(Nom) ON DELETE SET NULL,
    FOREIGN KEY (Systeme) REFERENCES SystemeAnatomique(Nom) ON DELETE SET NULL
);

CREATE TABLE SystemeAnatomique (
    Nom VARCHAR(50) NOT NULL PRIMARY KEY,
);


