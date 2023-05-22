SELECT DISTINCT Medicament.Nom
FROM Medicament
LEFT JOIN PharmacienDelivreMedicament ON Medicament.ID = PharmacienDelivreMedicament.MedicamentID
--Utilisation de left join pour récupérer les médicaments qui n'ont pas de correspondance
--dans la table Prescirption ou dont la date de prescription est antérieure à la date spécifiée
LEFT JOIN Prescription ON PharmacienDelivreMedicament.PrescriptionID = Prescription.ID
WHERE Prescription.ID IS NULL OR Prescription.DatePrescription < '2020-04-11'
