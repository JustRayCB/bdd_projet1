
SHOW TABLES;
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
    ID INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    Niss INT NOT NULL,
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

-- NOTE: Prescription à besoin de Médecin, Medicament et Dossier
CREATE TABLE Prescription (
    ID INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    MedecinINAMI VARCHAR(20) DEFAULT NULL,
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
    MedecinINAMI VARCHAR(20) NOT NULL,
    PrescriptionID INT NOT NULL,
    DateDebutTraitement DATE NOT NULL,
    DuréeTraitement INT NOT NULL,
    FOREIGN KEY (MedecinINAMI) REFERENCES Medecin(INAMI) ON DELETE CASCADE,
    FOREIGN KEY (PrescriptionID) REFERENCES Prescription(ID) ON DELETE CASCADE,
    PRIMARY KEY (MedecinINAMI, PrescriptionID)
);


-- NOTE: PharmacienDélivreMédicament à besoin de Pharmacien et Médicament
CREATE TABLE PharmacienDelivreMedicament(
    PharmacienINAMI VARCHAR(20) NOT NULL,
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
