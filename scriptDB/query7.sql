SELECT
    CONCAT(Decade, '0') As Decade,
    Medicament,
    Nombre_Patients
FROM (
    -- Sous-requête pour calculer le nombre de patients par décennie et par médicament
    SELECT
        -- Déduction de la décennie par rapport à la date de naissance du patient
        SUBSTRING(d.DateNaissance, 1, 3) AS Decade,
        m.DCI AS Medicament,
        COUNT(*) AS Nombre_Patients,
        -- Un numéro de ligne par décennie en fonction du nombre de patients (tri descendant)
        ROW_NUMBER() OVER (PARTITION BY SUBSTRING(d.DateNaissance, 1, 3) ORDER BY COUNT(*) DESC) AS RowNum
    FROM
        Dossier AS d
        JOIN Prescription AS p ON d.Niss = p.DossierID
        JOIN Medicament AS m ON p.MedicamentNom = m.Nom
    WHERE
        -- Filtre pour inclure uniquement les patients nés entre 1950 et 2000
        SUBSTRING(d.DateNaissance, 1, 3) BETWEEN '195' AND '200'
    GROUP BY
        Decade,
        Medicament
) AS T
WHERE
    RowNum = 1
ORDER BY
    Decade;
