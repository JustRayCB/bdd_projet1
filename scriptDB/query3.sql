SELECT m.`SpecialisationNom`, COUNT(*) AS total_prescriptions
FROM Medecin m
JOIN Prescription p ON m.`INAMI` = p.`MedecinINAMI`
GROUP BY m.`SpecialisationNom`
ORDER BY total_prescriptions DESC
LIMIT 1;