-- Drop all tables if exists 
-- WARNING: The deletion order matter ⚠️ 
DROP TABLE IF EXISTS DossierContientPathologie;
DROP TABLE IF EXISTS PharmacienDelivreMedicament;
DROP TABLE IF EXISTS MedecinPrescritPrescription;
DROP TABLE IF EXISTS Prescription;
DROP TABLE IF EXISTS Dossier;
DROP TABLE IF EXISTS Medecin;
DROP TABLE IF EXISTS Pharmacien;
DROP TABLE IF EXISTS Pathologie;
DROP TABLE IF EXISTS SpecialisationSpecialiseSysAnatomique;
DROP TABLE IF EXISTS Specialisation;
DROP TABLE IF EXISTS SystemeAnatomique;
DROP TABLE IF EXISTS Medicament;
-- ALTER TABLE SpecialisationSpecialiseSysA DROP FOREIGN KEY SpecialisationSpecialiseSysA_ibfk_1;
-- ALTER TABLE SpecialisationSpecialiseSysA DROP FOREIGN KEY SpecialisationSpecialiseSysA_ibfk_2;
-- ALTER TABLE Specialisation DROP FOREIGN KEY Specialisation_ibfk_1;
