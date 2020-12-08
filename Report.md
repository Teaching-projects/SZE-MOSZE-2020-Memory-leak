# Tagok

| Név | Github azonosito  | Javasolt relatív érdemjegy | Becsült óra | Indoklás  | 
| --- | ---- | --- | ------------------ | --------- |
| Joós Tibor | @joostibor | 0 | >100 | A rábízott a feladatot megoldotta, ahol tudott segített. Nehezebb feladatokat is rá lehetett bízni. Projekt összefogási feladatok. |
| Károlyi Péter | @Peti96 | 0 | 80-100 | A rá kitűzött feladatokat megoldotta határidőre, a közös munkák során mindig jelen volt, jó tanácsokat adott. |
| Török Kristóf | @Krisiiii98 | 0 | 80-100 | Amit kért a csapat megoldotta. Számos jó ötlete volt a fejlesztésekkel kapcsolatban. Közös kódolásoknál mindig jelen volt. |


# Videók

 - [Gameplay](/videos/Memory_leak_code.mp4)
 - [CodeBaseDefense](/videos/Memory_leak_code.mp4)

# Befejezett feladatok

| Feladat | Merge ideje a határidóhöz (nap) | Change request körök | Reviewer | 
| ------- | ------------------------------- | -------------------- | -------- |
| Feladat 1 | +2 | 6 | @hegyhati | 
| Feladat 2 | +4 | 0 | @wajzy |
| jsonparser | +11 | 2 | @wajzy |
| levelup | +5 | 1 | @oliverosz |
| attackspeed | -1 | 1 | @vizvezetek |
| documentation | -8 | 0 | @haliscsharp, @nemethvalentin / @Krisiiii98 |
| unittest | -7 | 1 | @AnonymDavid, @haliscsharp / @joostibor |
| makefile | -1 | 3 | @hegyhati |
| refactor | 0 | 1 | @hegyhati |
| docker | -3 | 0 | @hegyhati |
| jsonpimp | Merge: 11.16 | 0 | @halischarp, @nemethvalentin / @Krisiiii98 |
| map | Merge: 11.28 | 0 | @AnonymDavid, @nemethvalentin / @joostibor |
| game | Merge: 11.28 | 1 | @AnonymDavid, @nemethvalentin / @joostibor |
| defense | Merge: 11.28 | 0 | @AnonymDavid, @nemethvalentin / @joostibor |
| damage | Merge: 11.28 | 0 | @AnonymDavid, @nemethvalentin / @joostibor  |
| markedmap | Merge: 12.01 | 0 | @haliscsharp, @AnonymDavid / @Peti96 |
| preparedgame | Merge: 12.01 | 0 | @haliscsharp, @AnonymDavid / @Peti96
| light radius | Merge: 12.01 | 0 | @haliscsharp, @AnonymDavid / @Peti96 |
| rendering | Merge: 12.05 | 1 | @haliscsharp, @AnonymDavid / @Peti96 |

# Unit tesztek

| Osztály | Publikus metódusok száma | Unit tesztelt metódusok száma | Unit tesztek száma |
| --- | --- | --- | --- |
| `Game` | 12 | 4 | 1 |
| `Hero` | 9 | 5 | 4 | 
| `HeroSVGRenderer` | 2 | 0 | 0 |
| `HeroTextRenderer` | 3 | 0 | 0 |
| `JSON` | 5 | 4 | 10 |
| `Map` | 5 | 3 | 1 |
| `MarkedMap` | 5 | 2 | 1 |
| `Monster` | 14 | 10 | 3 |
| `ObserverSVGRenderer` | 2 | 0 | 0 |
| `ObserverTextRenderer` | 3 | 0 | 0 |
| `PreparedGame` | 3 | 0 | 0 |
| `Renderer` | 2 | 0 | 0 |
| `SVGRenderer` | 2 | 0 | 0 |
| `TextRenderer` | 4 | 0 | 0 |

# Kód dokumentáció

| Teljesen dokumentált osztályok | Részben dokumentált osztályok | Nem dokumentált osztályok |
| --- | --- | --- | 
| `Monster` | `Game` |  | 
| `MarkedMap` | `HeroSVGRenderer` | |  
| `Map` | `ObserverSVGRenderer` | |  
| `JSON` | `TextRenderer` | |  
| `HeroTextRenderer` | `SVGRenderer` | |  
| `Hero` | `PreparedGame` | |  
| `ObserverTextRenderer` | | | 
| `Renderer` | | |   


# Mindenféle számok

 - Összes cpp kódsor : 848
 - Egyéb kódsor (make,doxyfile,shellscript, ...) : 94 (+ 2580 doxconf kommentekkel)
 - cppcheck
   - warning : 0
   - style : 30
   - performance : 42
   - unusedFunction : 0
   - missingInclude : 0

# Implicit megtanult dolgok
Olyanok, amik nem a tárgy anyaga, de muszáj/hasznos volt elsajátítani:
 - JSON fájlok felépítése, hasznossága stb.
 - `std::variant`
 - SVG fájlok készítése
 - Linux subsystem használata
 - parancssori programfuttatás
 - paranccsori argumentum használat
 - platformfüggetlen programozás
 - VS Code használata, előnyei

# Feedback 

Először is úgy gondoljuk fontos megemlíteni, hogy a képzés egyik, a gyakorlatban legjobban használható tárgya volt. Jó volt találkozni a gyakorlatban is valóban használt megoldásokkal, ez sokszor hiányzik más tárgyak esetében.

A félév talán leghasznosabb része a GitHub mélyebb megismerése volt, mivel ezt a tudás fel tudjuk használni más tárgyak esetében történő kódfejlesztéshez, hasznos jövőbeli tudás. A másik dolog, amit nagyon hasznosnak találtunk, az a Makefile volt, mivel előtte elképzelni sem tudtunk volna ilyen könnyű megoldást. Emellett hasznos tudás volt a Docker tárolók megismerése is.

Az online videós megoldás szerintünk jó megoldás volt, mivel többször visszanézhető, jobban emészthető volt és akkor nézhettük meg a videókat, amikor akartuk, így nem volt az hogy fáradtság vagy bármi miatt nem tudtunk volna gondolkodni rendesen.

# Üzenet a jövőbe

Jobban kiemelni (az első órainál is jobban), hogy ez a tárgy valóban a gyakorlatban is hasznos tudásokkal ruház fel. Érdemes lehet megemlíteni, hogy szükség van mély programozási tudásra és jó csapatmunka képességre (azok miatt érdemes, akik még nem csinálták meg a Projektmunka 1-t, például mi is sajnos így voltunk). Emellett érdemes lehet megemlíteni, hogy tényleg érdemes időben elkészülni a feladattal és csak alaposan átnézve beadni mert a reviewek csúszhatnak/lehetnek időbeli különbségek mivel az oktatók is csak emberek, nem robotok.
