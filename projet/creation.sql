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
*/

CREATE TABLE Phramacien  (
    INAMI INT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    phone VARCHAR(20) DEFAULT NULL,
    email VARCHAR(50) DEFAULT NULL,
);

CREATE TABLE Specialisation (
    name VARCHAR(50) PRIMARY KEY,
    anatomical_region VARCHAR(50) NOT NULL,
);

CREATE TABLE Treatment (
    ID INT PRIMARY KEY,
    PINAMI INT NOT NULL,
    DID INT NOT NULL,
    foreign key (PINAMI) references Phramacien(INAMI),
    foreign key (DID) references DossierContientPathologie(ID),
);

CREATE TABLE Prescription (
    ID INT PRIMARY KEY,
    duration INT NOT NULL,
    name VARCHAR(50) NOT NULL,
    TRID INT NOT NULL,
    foreign key (TRID) references Treatment(ID),
);
