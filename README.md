# SZE-MOSZE-2020-Memory-leak

## RPG Game szoftver

### Csapattagok
* Joós Tibor (joostibor)
* Károlyi Péter (Peti96)
* Török Kristóf (Krisiiii98)

### A program működése (röviden)
A Modern Szoftverfejlesztési Eszközök tárgyra készült a projektünk, melyben két hős harcol egymással amíg az egyik meg nem hal. A program úgy működik, hogy parancssori argumentumban egy json fájlt, amely tartalmaz egy forgatókönyvet a harchoz. Pl.: <code> ./a.out scenario1.json </code> Ezt követően a program beolvassa a fájlban található hőst és az ellenséges szörnyeket. Ezen folyamat megtörténte után a hős harcol a szönyek ellen mindaddig, amíg meg nem hal. Mindeközben a program folyamatosan kiírja a képernyőre, hogy éppen mely szörny ellen harcol a hős. Majd a cselekménysorozat végeztével a program kiírja a képernyőre a záróállapotot a hősről (neve, maradék életereje, sebzése, támadási sebessége).

### Dokumentáció
A szoftverhez tartozik egy doxygen dokumentáció, mely [ide kattintva](https://teaching-projects.github.io/SZE-MOSZE-2020-Memory-leak/) érhető el.
