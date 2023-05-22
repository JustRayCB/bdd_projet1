SELECT PathologieNom, COUNT(*) AS NombreDiagnostiques
FROM DossierContientPathologie
GROUP BY PathologieNom
ORDER BY NombreDiagnostiques DESC
-- Retourne la (seule et unique) maladie la plus diagnostiquée
LIMIT 1;
