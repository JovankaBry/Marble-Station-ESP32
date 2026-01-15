# Marble-Station-ESP32
This project focuses on the design and implementation of a remote-controlled marble track station with multiple marble containers, based on the ESP32 microcontroller. It includes both the hardware design and software development for wireless control, motor and sensor integration, and communication between modules.

The firmware is developed using PlatformIO with the ESP-IDF framework, ensuring efficient development, debugging, and project management directly in Visual Studio Code.
This setup allows for modular coding, easy dependency handling, and smooth integration with ESP32’s Bluetooth and GPIO features.

Bluetooth-based remote control

# Features
-Automatic marble release (e.g., one marble per second)

-Modular station architecture with multiple containers

-3D-printed mechanical parts for the station setup

## Notes
Konzeption und Implementierung einer fernsteuerbaren Kugelbahn-Stationen mit mehreren Kugelbehältern auf Basis von ESP32 Mikrocontrollern (mit Python oder C). Um Aufgaben aus dem Bereich der Automatisierungstechnik zu bearbeiten, soll für die Lehre eine Kugelbahn realisiert werden (vergleichbar mit z.B. https://www.ravensburger.de/de-DE/produkte/gravitrax). Konkret soll eine Kugelbahnstation aufgebaut werden, die mehrere Kugelbehälter verwaltet. Die Kugelbahnstation soll eine einzelne Kugel aus einem der angeschlossenen Behälter in die Kugelbahn entlassen können. Welche Kugel ausgeworfen wird, soll über Bluetooth gesteuert werden können (der ESP32 bietet hier einfache Funktionen an). Dabei soll auch eine automatische Ausgabe von Kugeln vorgesehen werden (z.B. eine Kugel pro Sekunde). Für den mechanischen Aufbau steht ein 3D-Drucker zur Verfügung. Die Basis ist bereits fertig konstruiert und muss nur um die für diese Aufgabe spezifischen Komponenten erweitert werden.

Die Kugeln sollen auf Schienen entlassen werden. Sie müssen also eine Kugelbahnstation so modifizieren, dass daran Behälter befestigt sind. Ich habe Ihnen in der HTW-Cloud mal die Kugelstation-Basis als shapr3d Datei gespeichert:

Um die Datei zu öffnen, müssen Sie shapr3d auf dem PC oder auf einem iPad installieren und dann die Datei importieren. Das Programm shapr3d ist von Siemens und für Studierende ein Jahr Kostenfrei zu nutzen. Sie müssen sich allerdings registrieren. Beachten Sie, dass die Kugelbahnstation ein Muster ist und von Ihnen angepasst werden muss. Vor allem macht es aktuell keinen Sinn, dass Sie drei Wege haben. Sie müssen den "Schienenkopf" also modifizieren, und zwar so, dass nur noch ein Weg aus der Station heraus führt. Außerdem müssen Sie natürlich die Kugelbehälter ergänzen.
