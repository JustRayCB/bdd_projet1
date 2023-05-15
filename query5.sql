-- Active: 1683463812091@@127.0.0.1@3306@projetINFOH303_2223
SELECT DISTINCT d.`Niss`, d.`Nom`, d.`Prenom`, d.`Mail`, d.`NumTel`
FROM Dossier d
JOIN Prescription p ON d.`Niss` = p.`DossierID`
JOIN PharmacienDelivreMedicament pdm ON p.`ID` = pdm.`PrescriptionID`
Join Medicament m ON pdm.`MedicamentID` = m.`ID`
WHERE p.`DatePrescription` < CURDATE() -- La date antérieure à laquelle le traitement a été prescrit
AND DATE_ADD( pdm.`DateDelivrance`,INTERVAL p.`DureeTraitement` DAY) < '2009-03-10' -- La date antérieure à laquelle le médicament a été délivré
AND m.`DCI` = 'EPLERENONE' -- Remplacez 'nom_du_medicament' par le nom du médicament (DCI)
