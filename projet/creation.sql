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

-- Drop all tables if exists 
-- DROP TABLE IF EXISTS DossierContientPathologie;
-- DROP TABLE IF EXISTS PharmacienDelivreMedicament;
-- DROP TABLE IF EXISTS MedecinPrescritPrescription;
-- DROP TABLE IF EXISTS Prescription;
-- DROP TABLE IF EXISTS Dossier;
-- DROP TABLE IF EXISTS Medecin;
-- DROP TABLE IF EXISTS Pharmacien;
-- DROP TABLE IF EXISTS Pathologie;
-- DROP TABLE IF EXISTS Specialisation;
-- DROP TABLE IF EXISTS Medicament;
-- DROP TABLE IF EXISTS SystemeAnatomique;


-- WARNING: Un patient peut avoir plusieurs DOSSIERS, 
--          mais un seul DOSSIER peut être lié à un patient
/*
 WARNING: Je vais supprimer la table Patient et mettre tous dans la table dossier
*/

-- CREATE DATABASE [IF NOT EXISTS] database_name
-- CREATE DATABASE projetINFOH303_2223 if not exists;
create database if not exists projetINFOH303_2223;
USE projetINFOH303_2223;


CREATE TABLE SystemeAnatomique (
    Nom VARCHAR(50) NOT NULL PRIMARY KEY
);

CREATE TABLE Medicament(
    ID INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    -- DCI VARCHAR(50) NOT NULL,
    Nom VARCHAR(50) NOT NULL,
    Conditionnement INT NOT NULL
);

-- NOTE: Spécialisation à besoin de SystemeAnatomique
CREATE TABLE Specialisation (
    Nom VARCHAR(50) NOT NULL PRIMARY KEY,
    Systeme VARCHAR(50) DEFAULT NULL,
    FOREIGN KEY(Systeme) REFERENCES SystemeAnatomique(Nom) ON DELETE SET NULL
);

-- SHOW TABLES;

-- NOTE: Pathologie à besoin de Spécialisation
CREATE TABLE Pathologie (
    Nom VARCHAR(50) NOT NULL PRIMARY KEY,
    SpecialisationNom VARCHAR(50),
    Systeme VARCHAR(50),
    FOREIGN KEY (SpecialisationNom) REFERENCES Specialisation(Nom) ON DELETE SET NULL,
    FOREIGN KEY (Systeme) REFERENCES SystemeAnatomique(Nom) ON DELETE SET NULL
);

CREATE TABLE Pharmacien (
    INAMI INT NOT NULL PRIMARY KEY,
    Nom VARCHAR(50) NOT NULL,
    NumTel INT NOT NULL,
    Mail VARCHAR(50) DEFAULT NULL
);

-- NOTE: Médecin à besoin de Spécialisation 
CREATE TABLE Medecin (
    INAMI INT NOT NULL PRIMARY KEY,
    Nom VARCHAR(50) NOT NULL,
    NumTel INT NOT NULL,
    Mail VARCHAR(50) DEFAULT NULL,
    SpecialisationNom VARCHAR(50) NOT NULL,
    FOREIGN KEY (SpecialisationNom) REFERENCES Specialisation(Nom)
);


-- NOTE: Dossier à besoin de Medecin et pharmacien
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
    FOREIGN KEY (PharmacienINAMI) REFERENCES Pharmacien(INAMI),
    FOREIGN KEY (MedecinINAMI) REFERENCES Medecin(INAMI)
);

-- NOTE: Prescription à besoin de Médecin, Medicament et Dossier
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
    FOREIGN KEY(MedicamentID) REFERENCES Medicament(ID) ON DELETE SET NULL
    -- FOREIGN KEY (MedicamentNom) REFERENCES Medicament(Nom) ON DELETE SET NULL
    -- FOREIGN KEY (MedecinNom) REFERENCES Medecin(Nom) ON DELETE SET NULL,
    -- FOREIGN KEY (PharmacienINAMI) REFERENCES Pharmacien(INAMI) ON DELETE SET NULL,
);


-- NOTE: MédecinPrescritPrescription à besoin de Médecin et Prescription
CREATE TABLE MedecinPrescritPrescription (
    MedecinINAMI INT NOT NULL,
    PrescriptionID INT NOT NULL,
    DateDebutTraitement DATE NOT NULL,
    DuréeTraitement INT NOT NULL,
    FOREIGN KEY (MedecinINAMI) REFERENCES Medecin(INAMI) ON DELETE CASCADE,
    FOREIGN KEY (PrescriptionID) REFERENCES Prescription(ID) ON DELETE CASCADE,
    PRIMARY KEY (MedecinINAMI, PrescriptionID)
);


-- NOTE: PharmacienDélivreMédicament à besoin de Pharmacien et Médicament
CREATE TABLE PharmacienDelivreMedicament(
    PharmacienINAMI INT NOT NULL,
    MedicamentID INT NOT NULL,
    FOREIGN KEY (PharmacienINAMI) REFERENCES Pharmacien(INAMI) ON DELETE CASCADE,
    FOREIGN KEY (MedicamentID) REFERENCES Medicament(ID) ON DELETE CASCADE,
    PRIMARY KEY (PharmacienINAMI, MedicamentID)
);


-- NOTE: Dossier à besoin Dossier et de Pathologie
CREATE TABLE DossierContientPathologie (
    DID INT NOT NULL,
    PathologieNom VARCHAR(50) NOT NULL,
    DateDiagnostique DATE NOT NULL,
    FOREIGN KEY (DID) REFERENCES Dossier(ID) ON DELETE CASCADE,
    FOREIGN KEY (PathologieNom) REFERENCES Pathologie(Nom) ON DELETE CASCADE,
    PRIMARY KEY (DID, PathologieNom)
);


