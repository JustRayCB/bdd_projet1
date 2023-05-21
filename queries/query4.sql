SELECT DISTINCT d.`Niss`, d.`Nom`, d.`Prenom`, d.`Mail`, d.`NumTel`
FROM Dossier d
JOIN Prescription p ON d.`Niss` = p.`DossierID`
JOIN PharmacienDelivreMedicament pdm ON p.`ID` = pdm.`PrescriptionID`
WHERE p.`MedicamentNom` = 'Lisinopril' 
AND pdm.`DateDelivrance` > '1947-04-09';
