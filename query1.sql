-- Active: 1683463812091@@127.0.0.1@3306@projetINFOH303_2223
SELECT
    distinct m.`Nom`,
    m.`Conditionnement`
FROM
    Medicament AS m
WHERE
    m.`DCI` = 'BEVACIZUMAB'
    AND m.`Nom` IS NOT NULL
ORDER BY
    m.`Nom`,
    m.`Conditionnement`;