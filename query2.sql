-- Active: 1683463812091@@127.0.0.1@3306@projetINFOH303_2223
SELECT p.`Nom`
FROM Pathologie p
GROUP BY p.`Nom`
HAVING COUNT(DISTINCT p.`SpecialisationNom`) = 1;