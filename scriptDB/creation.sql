
SHOW TABLES;
create database if not exists projetINFOH303_2223;
USE projetINFOH303_2223;


CREATE TABLE SystemeAnatomique (
    Nom VARCHAR(50) NOT NULL PRIMARY KEY
);

CREATE TABLE Medicament(
    ID INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    DCI VARCHAR(50) NOT NULL,
    Nom VARCHAR(50) NOT NULL,
    Conditionnement INT NOT NULL,
    SystemeAnatomiqueNom VARCHAR(50) NOT NULL,
    FOREIGN KEY (SystemeAnatomiqueNom) REFERENCES SystemeAnatomique(Nom) ON DELETE CASCADE
);

-- NOTE: Spécialisation à besoin de SystemeAnatomique
CREATE TABLE Specialisation (
    Nom VARCHAR(50) NOT NULL PRIMARY KEY
);


-- NOTE: SpecialisationSpecialiseSysAnatomique à besoin de Spécialisation et SystemeAnatomique
CREATE TABLE SpecialisationSpecialiseSysAnatomique (
    SpecialisationNom VARCHAR(50),
    SystemeAnatomiqueNom VARCHAR(50),
    PRIMARY KEY (SpecialisationNom, SystemeAnatomiqueNom),
    FOREIGN KEY (SpecialisationNom) REFERENCES Specialisation(Nom) ON DELETE CASCADE,
    FOREIGN KEY (SystemeAnatomiqueNom) REFERENCES SystemeAnatomique(Nom) ON DELETE CASCADE
);


-- NOTE: Pathologie à besoin de Spécialisation
CREATE TABLE Pathologie (
    Nom VARCHAR(50) NOT NULL PRIMARY KEY,
    SpecialisationNom VARCHAR(50),
    FOREIGN KEY (SpecialisationNom) REFERENCES Specialisation(Nom) ON DELETE SET NULL
);

CREATE TABLE Pharmacien (
    INAMI VARCHAR(20) NOT NULL PRIMARY KEY,
    Nom VARCHAR(50) NOT NULL,
    NumTel VARCHAR(20) NOT NULL,
    Mail VARCHAR(50) DEFAULT NULL
);

-- NOTE: Médecin à besoin de Spécialisation 
CREATE TABLE Medecin (
    INAMI VARCHAR(20) NOT NULL PRIMARY KEY,
    Nom VARCHAR(50) NOT NULL,
    NumTel VARCHAR(20) NOT NULL,
    Mail VARCHAR(50) DEFAULT NULL,
    SpecialisationNom VARCHAR(50),
    FOREIGN KEY (SpecialisationNom) REFERENCES Specialisation(Nom) ON DELETE SET NULL
);


-- NOTE: Dossier à besoin de Medecin et pharmacien
CREATE TABLE Dossier (
    Niss VARCHAR(20) NOT NULL PRIMARY KEY,
    Nom VARCHAR(50) NOT NULL,
    Prenom VARCHAR(50) NOT NULL,
    Genre VARCHAR(1) NOT NULL,
    DateNaissance DATE NOT NULL,
    Mail VARCHAR(50) DEFAULT NULL,
    NumTel VARCHAR(20) DEFAULT NULL,
    PharmacienINAMI VARCHAR(20) DEFAULT NULL,
    MedecinINAMI VARCHAR(20) DEFAULT NULL,
    FOREIGN KEY (PharmacienINAMI) REFERENCES Pharmacien(INAMI) ON DELETE SET NULL,
    FOREIGN KEY (MedecinINAMI) REFERENCES Medecin(INAMI) ON DELETE SET NULL
);

-- TODO: Il manque MedecinPrescritPrescription, PharmacienDelivreMedicament, Prescription
-- Tous ceci avec le dernier fichier dossier_patient.csv

-- NOTE: Prescription à besoin de Médecin, Medicament et Dossier
CREATE TABLE Prescription (
    ID INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    MedecinINAMI VARCHAR(20) NOT NULL,
    DossierID VARCHAR(20) NOT NULL,
    PharmacienNom VARCHAR(50) NOT NULL,
    MedecinNom VARCHAR(50) NOT NULL,
    MedicamentNom VARCHAR(50) NOT NULL, -- Medicament  prescrit
    DatePrescription DATE NOT NULL,
    DureeTraitement INT NOT NULL,
    FOREIGN KEY (MedecinINAMI) REFERENCES Medecin(INAMI) ON DELETE CASCADE,
    FOREIGN KEY (DossierID) REFERENCES Dossier(Niss) ON DELETE CASCADE
);




-- NOTE: PharmacienDélivreMédicament à besoin de Pharmacien et Médicament
CREATE TABLE PharmacienDelivreMedicament(
    PharmacienINAMI VARCHAR(20) NOT NULL,
    PrescriptionID INT NOT NULL,
    MedicamentID INT NOT NULL,
    DateDelivrance DATE NOT NULL,
    FOREIGN KEY (PharmacienINAMI) REFERENCES Pharmacien(INAMI) ON DELETE CASCADE,
    FOREIGN KEY (MedicamentID) REFERENCES Medicament(ID) ON DELETE CASCADE,
    FOREIGN KEY (PrescriptionID) REFERENCES Prescription(ID) ON DELETE CASCADE,
    PRIMARY KEY (PharmacienINAMI, PrescriptionID)
);


-- NOTE: Dossier à besoin Dossier et de Pathologie
CREATE TABLE DossierContientPathologie (
    DossierID VARCHAR(20) NOT NULL,
    PathologieNom VARCHAR(50) NOT NULL,
    DateDiagnostique DATE NOT NULL,
    FOREIGN KEY (DossierID) REFERENCES Dossier(Niss) ON DELETE CASCADE,
    FOREIGN KEY (PathologieNom) REFERENCES Pathologie(Nom) ON DELETE CASCADE,
    PRIMARY KEY (DossierID, PathologieNom, DateDiagnostique)
);
