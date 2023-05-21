SELECT D.Niss, D.Nom, D.Prenom, COUNT(DISTINCT P.MedecinINAMI) AS NombreMedecinsPrescripteurs
FROM Dossier D
--LEFT JOIN garantit que tous les éléments de la table `Dossier` sont inclus dans le résultat, même s'il n'y a
--pas d'éléments correspondants dans la table `Prescription`
LEFT JOIN Prescription P ON D.Niss = P.DossierID
GROUP BY D.Niss, D.Nom, D.Prenom;
