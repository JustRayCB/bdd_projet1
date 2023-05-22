SELECT DISTINCT M.Nom
FROM Medecin AS M
INNER JOIN Prescription AS P ON M.INAMI = P.MedecinINAMI
INNER JOIN Medicament AS Med ON P.MedicamentNom = Med.Nom
-- Condition : le DCI du médicament ne doit pas être présent dans la liste suivante
WHERE Med.DCI NOT IN ( 
    -- Sous-requête pour obtenir les DCIs des médicaments ne relevant pas de la spécialité des médecins
    SELECT Med2.DCI
    FROM Medecin AS M2
    INNER JOIN Specialisation AS S ON M2.SpecialisationNom = S.Nom
    INNER JOIN SpecialisationSpecialiseSysAnatomique AS SSA ON S.Nom = SSA.SpecialisationNom
    INNER JOIN Medicament AS Med2 ON SSA.SystemeAnatomiqueNom = Med2.Conditionnement
)
