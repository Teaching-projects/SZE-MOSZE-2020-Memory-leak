# SZE-MOSZE-2020-Memory-leak

A program v0.0000000000002-es verziója egy **Hero** osztályt tartalmaz, mely három privát adattaggal rendelkezik: <em>name, hp, dmg</em>. Az osztály lényege, hogy egy hős információit eltárolja, kezelje. Az osztály rendelkezik több segédfüggvénnyel: 
1. getAttack, mely csökkenti az adott hős életerejét az ellenfél támadási erejével,
2. getter függvények az adatlekérdezéshez,
3. parseUnit függvényt, mely argumentumként vár egy fájlnevet, majd beolvassa a megadott formátumnak megfelelő json fájlt.


A kiiratáshoz operátort használunk, mely bármilyen outstreamre a kiiratást megkönnyíti.

A main.cpp-ben történik a változók értékeinek beállítása, illetve a játékmenet. A játék addig tart, amíg valamelyik hős életereje nem csökken 0 alá. Továbbá itt történik a fájlok beolvasása is.

A fájlbekérés során keletkező hibák kezelésének megkönnyítése érdekében létrehoztunk egy HeroFileError nevű osztályt, mely egy privát tagot (<em>msg</em>) tartalmaz. Az osztály a string osztályból származik, mely megkönnyíti a hiba kiírását, mivel nincs szükség külön függvényre, hiszen így az osztály rendelkezik alapból a << operátorral.

A program működésének testeléséhez egy alkönytárban létrehoztunk 3 hőst, melyek egy bash szkript által megküzdenek egymással. A szkript összehasonlítja a várt/kézzel kalkulált kimentetet a program által adott kimenettel és amennyiben nem egyezik, akkor hibakóddal tér vissza.
