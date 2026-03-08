# 🚗 UnlockAllCars — BakkesMod Plugin

Plugin BakkesMod per **Rocket League** che aggiunge un bottone nelle impostazioni per **attivare tutte le auto** nel garage con un solo click.

---

## ✅ Funzionalità

- Bottone **"Attiva tutte le Cars"** nell'interfaccia ImGui di BakkesMod
- Aggiunge automaticamente all'inventario tutti i Product ID delle auto del gioco
- Feedback visivo colorato: verde = successo, rosso = errore
- Funziona in **Freeplay**, **Custom Training** e **Garage**

---

## 📦 Installazione

### Metodo 1 — DLL precompilata (consigliato)

1. Copia `UnlockAllCars.dll` in:
   ```
   %APPDATA%\bakkesmod\bakkesmod\plugins\
   ```
2. Apri Rocket League con BakkesMod attivo
3. Apri il menu BakkesMod (`F2`) → **Plugins** → cerca **"Unlock All Cars"**
4. Clicca **"Attiva tutte le Cars"** ✅

---

### Metodo 2 — Compilazione da sorgente

#### Requisiti
- Visual Studio 2022 (o 2019)
- [BakkesMod SDK](https://github.com/bakkesmodorg/BakkesModSDK)
- CMake ≥ 3.15

#### Passi

```bash
git clone https://github.com/ilfenomeno-gif/rocket-league.git
cd rocket-league/UnlockAllCars

# Crea la build directory
mkdir build && cd build

# Configura con il percorso corretto dell'SDK
cmake .. -DBAKKESMOD_SDK_PATH="C:/BakkesModSDK"

# Compila
cmake --build . --config Release
```

La DLL viene copiata automaticamente in:
```
%APPDATA%\bakkesmod\bakkesmod\plugins\UnlockAllCars.dll
```

---

## 📂 Struttura del progetto

```
UnlockAllCars/
├── UnlockAllCars.h       ← Header del plugin
├── UnlockAllCars.cpp     ← Logica + UI ImGui
├── pch.h                 ← Precompiled header
├── CMakeLists.txt        ← Build system
└── README.md             ← Questo file
```

---

## ⚙️ Note tecniche

- Le auto vengono aggiunte tramite `ItemsWrapper::AddProduct()` — funziona **lato client** (solo cosmetico, non modifica il server)
- I Product ID sono hardcodati in `GetAllCarProductIDs()` — puoi aggiungerne altri facilmente
- Compatibile con BakkesMod SDK **0.9.x** e superiori

---

## ⚠️ Disclaimer

Questo plugin è solo per uso personale/divertimento in freeplay.
Non garantisce compatibilità con server online o dopo aggiornamenti del gioco.

---

Made with ❤️ by [ilfenomeno-gif](https://github.com/ilfenomeno-gif)
