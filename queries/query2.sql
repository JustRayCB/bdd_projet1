SELECT p.`Nom`
FROM Pathologie p
GROUP BY p.`Nom`
HAVING COUNT(DISTINCT p.`SpecialisationNom`) = 1;
