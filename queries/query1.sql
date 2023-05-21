SELECT
    distinct m.`Nom`,
FROM
    Medicament AS m
WHERE
    m.`DCI` = 'BEVACIZUMAB'
    AND m.`Nom` IS NOT NULL
ORDER BY
    m.`Nom`,
    m.`Conditionnement`;
