-- Active: 1683463812091@@127.0.0.1@3306@projetINFOH303_2223
SELECT m.`SpecialisationNom`, COUNT(*) AS total_prescriptions
FROM Medecin m
JOIN Prescription p ON m.`INAMI` = p.`MedecinINAMI`
GROUP BY m.`SpecialisationNom`
ORDER BY total_prescriptions DESC
LIMIT 1;