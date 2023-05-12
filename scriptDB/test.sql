SHOW TABLES;
SELECT * FROM SystemeAnatomique; -- 14
SELECT * FROM Specialisation; -- 16
SELECT * FROM SpecialisationSpecialiseSysAnatomique; -- 29
SELECT * FROM Pathologie; -- 120
SELECT * FROM Pharmacien; -- 270
SELECT * FROM Medecin; -- 274
SELECT * FROM Medicament; -- 1540
SELECT * FROM Dossier; -- 274
SELECT * FROM DossierContientPathologie; -- 970
describe Pathologie;
describe Specialisation;
describe Dossier
describe Medicament
select * from PharmacienDelivreMedicament;
SELECT * FROM Prescription;

SELECT ID
FROM Medicament
WHERE Nom = "Acinax" AND DCI = "BEVACIZUMAB" AND Conditionnement >= 6
ORDER BY Conditionnement ASC
LIMIT 1;
-- TODO: Il manque MedecinPrescritPrescription, PharmacienDelivreMedicament, Prescription
-- Tous ceci avec le dernier fichier dossier_patient.csv

-- describe Pathologie;
