SELECT M.INAMI, M.Nom
FROM Medecin M
INNER JOIN Prescription P ON M.INAMI = P.MedecinINAMI
INNER JOIN Medicament Med ON P.MedicamentNom = Med.Nom
LEFT JOIN Specialisation S ON M.SpecialisationNom = S.Nom
LEFT JOIN SpecialisationSpecialiseSysAnatomique SSA ON S.Nom = SSA.SpecialisationNom
LEFT JOIN SystemeAnatomique SA ON SSA.SystemeAnatomiqueNom = SA.Nom
WHERE Med.SystemeAnatomiqueNom NOT IN (
    SELECT SSA.SystemeAnatomiqueNom
    FROM SpecialisationSpecialiseSysAnatomique SSA
    WHERE SSA.SpecialisationNom = M.SpecialisationNom
)
OR (Med.SystemeAnatomiqueNom IS NULL AND M.SpecialisationNom IS NOT NULL)
GROUP BY M.INAMI, M.Nom, M.NumTel, M.Mail, M.SpecialisationNom;
