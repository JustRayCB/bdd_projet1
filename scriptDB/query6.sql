SELECT M.INAMI, M.Nom
FROM Medecin M
JOIN Prescription P ON M.INAMI = P.MedecinINAMI
JOIN Medicament Med ON P.MedicamentNom = Med.Nom
LEFT JOIN SpecialisationSpecialiseSysAnatomique SSA ON M.SpecialisationNom = SSA.SpecialisationNom
WHERE Med.SystemeAnatomiqueNom NOT IN (
    SELECT SSA.SystemeAnatomiqueNom
    FROM SpecialisationSpecialiseSysAnatomique SSA
    WHERE SSA.SpecialisationNom = M.SpecialisationNom
)
GROUP BY M.INAMI, M.Nom;
