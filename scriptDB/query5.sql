SELECT DISTINCT d.`Niss`, d.`Nom`, d.`Prenom`, d.`Mail`, d.`NumTel`
FROM Dossier d
JOIN Prescription p ON d.`Niss` = p.`DossierID`
JOIN PharmacienDelivreMedicament pdm ON p.`ID` = pdm.`PrescriptionID`
Join Medicament m ON pdm.`MedicamentID` = m.`ID`
WHERE p.`DatePrescription` < '2009-03-10' 
AND DATE_ADD( pdm.`DateDelivrance`,INTERVAL p.`DureeTraitement` DAY) < '2009-03-10' 
AND m.`DCI` = 'EPLERENONE'
