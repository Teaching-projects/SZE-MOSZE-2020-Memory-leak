# SZE-MOSZE-2020-Memory-leak

A program v0.0000000000001-es verziója egy **Hero** osztályt tartalmaz, mely három privát adattaggal rendelkezik: <em>name, hp, dmg</em>. Az osztály lényege, hogy egy hős információit eltárolja, kezelje. Az osztály rendelkezik több segédfüggvénnyel: 
1. getAttack, mely csökkenti az adott hős életerejét az ellenfél támadási erejével,
2. getter függvények az adatlekérdezéshez.

A kiiratáshoz operátort használunk, mely bármilyen outstreamre a kiiratást megkönnyíti.

A main.cpp-ben történik a változók értékeinek beállítása, illetve a játékmenet. A játék addig tart, amíg valamelyik hős életereje nem csökken 0 alá.
