# grp04-algdatII
[![](https://travis-ci.org/algdat/grp04-algdatII.svg?branch=master)](https://travis-ci.org/algdat/grp04-algdatII)

## Slides

Link zur Presentation: [Google-Slides](https://docs.google.com/presentation/d/1Pdye6wak54ME0-gzCj-k0S3rz5Ayfoy9sa8NZLTxUZI/edit?usp=sharing)

## Datenstrukturen

### Labyrinth

2-Dimensionaler bool-Vektor, Koordinaten entsprechen indizes. Indizierung beginnt links oben bei 0,0.
Gültige Werte:
* 0 = Weg
* 1 = Mauer 
* Start- und Ende werden durch koordinaten spezifiziert.

### Koordinate

struct 'Coordinate'. Wird implementiert.

### Weg

Der ideale Weg ist eine Liste aus 'Coordinate's,  jede Koordinate entspricht einem Schritt richtung ausgang.

## Module

### Einlesen, generieren eines Labyrinths

Zu Beginn liefert dieses Modul ein statisches Labyrinth, im späteren Entwicklungsstand sollen Labyrinthe eingelesen und generiert werden können.

**Verantwortlich**: @arne2

### Algorithmus

Erhält ein 'Labyrinth', sowie Start- und Endpunkte als 'Coordinate'. Führt den Algorithmus zur Berechnung des besten Weges aus und liefert anschließend den Weg wie oben spezifiziert zurück.

**Verantwortlich:** @maximilian-zollbrecht @darenegade

### Visualisierung

Erhält das 'Labyrinth' und den vom Algorithmus berechneten Weg zur darstellung.

**Verantwortlich:** @FabianHoltkoetter

### Integrator und CI-Verantwortlicher

Ist verantwortlich dafür, dass alle Module ihre Schnittstellendefinition einhalten/aktuell halten und andere Modulentwickler über Änderungen informiert werden. Außerdem sorgt er für ein reibungsloses zusammenspiel der Komponenten.
Er sorgt für eine korrekte Konfiguration von Travis und das Deployment der Projektseite inklusive Doku auf GIthub Pages

**Integrator**: @peter-mueller
