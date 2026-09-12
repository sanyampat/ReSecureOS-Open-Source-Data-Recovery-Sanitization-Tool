# ReSecureOS

### Open-Source Linux Platform for Digital Forensics, Data Recovery & Secure Storage Sanitization

<p align="center">
  <strong>Recover. Acquire. Verify. Resecure.</strong>
</p>

<p align="center">
  A modular Linux-based platform for forensic acquisition, deleted-file recovery, storage analysis, and secure device sanitization.
</p>

<p align="center">
</p>

---

## What is ReSecureOS?

**ReSecureOS** is an open-source Linux-based platform designed to bring digital forensics, data recovery, forensic acquisition, and secure storage sanitization into a single environment.

Instead of requiring multiple independent tools and workflows, ReSecureOS aims to provide investigators, researchers, security professionals, and storage engineers with a unified platform for working with storage devices.

The project combines a modular **C++17 core**, a lightweight **Python GUI**, Linux device interfaces, and hardware-aware storage sanitization.

### Core capabilities

* 🔍 Storage device discovery
* 💽 Device metadata inspection
* 🛡️ Write-protected forensic acquisition
* 📀 Disk imaging
* 🔐 SHA-256 evidence hashing
* 🧩 Deleted-file carving
* ✅ File validation
* 📊 Recovery confidence scoring
* 🗂️ Recovered-file classification
* 🧹 Capability-driven storage sanitization
* ⚡ NVMe sanitization
* 💾 ATA sanitization
* 🔧 SCSI sanitization
* 🔄 Generic block-level clearing
* 🔎 Post-operation verification
* 📋 Evidence manifests
* 📝 Audit information
* 🖥️ Linux graphical interface

---

# Screenshots

> UI screenshots are stored in `assets/screenshots/`.

## Device Management

ReSecureOS identifies available storage devices and presents information such as:

* Device path
* Model
* Vendor
* Serial number
* Capacity
* Bus type
* Media type
* Mount status
* Safety status

---

## Forensic Acquisition

The acquisition workflow is designed around preserving the original storage device while creating a verifiable forensic image.

```text
Storage Device
      │
      ▼
Device Inspection
      │
      ▼
Write Protection
      │
      ▼
Disk Imaging
      │
      ▼
SHA-256 Hash
      │
      ▼
Evidence Manifest
      │
      ▼
Forensic Image
```

---

## Data Recovery

The recovery subsystem analyzes disk images and attempts to identify recoverable files.

```text
Disk Image
    │
    ▼
File Carving
    │
    ▼
File Validation
    │
    ▼
Confidence Scoring
    │
    ▼
Classification
    │
    ▼
Recovered Files
```

Recovered candidates can contain:

* File type
* Start offset
* End offset
* Recovered size
* Validation status
* Confidence level
* Category
* Output path
* SHA-256 hash

---

## Secure Sanitization

ReSecureOS uses a **capability-driven sanitization model**.

The system does not blindly apply the same sanitization technique to every storage device.

Instead, it first identifies the device and determines which supported sanitization mechanisms are available.

```text
                    Target Device
                         │
                         ▼
                  Safety Checks
                         │
                         ▼
                Capability Detection
                         │
             ┌───────────┼───────────┐
             │           │           │
             ▼           ▼           ▼
           NVMe         ATA         SCSI
             │           │           │
             ▼           ▼           ▼
        NVMe Method  ATA Method  SCSI Method
             │           │           │
             └───────────┼───────────┘
                         │
                         ▼
                    Verification
                         │
                         ▼
                    Audit Result
```

Supported architecture includes:

* NVMe sanitization
* ATA sanitization / secure erase mechanisms
* SCSI sanitization
* Generic block-level clearing where appropriate

---

# Architecture

```text
                         ┌──────────────────────────┐
                         │        ReSecureOS         │
                         │                          │
                         │  Portable Linux Platform │
                         └────────────┬─────────────┘
                                      │
              ┌───────────────────────┼───────────────────────┐
              │                       │                       │
              ▼                       ▼                       ▼
       ┌─────────────┐        ┌──────────────┐        ┌─────────────┐
       │   Device    │        │ Acquisition  │        │  Recovery   │
       │   Layer     │        │    Layer     │        │    Layer    │
       │             │        │              │        │             │
       │ Discovery   │        │ Write Protect│        │ File Carving│
       │ Metadata    │        │ Disk Imaging │        │ Validation  │
       │ Bus Detect  │        │ SHA-256      │        │ Confidence  │
       └──────┬──────┘        └──────┬───────┘        └──────┬──────┘
              │                      │                       │
              └──────────────────────┼───────────────────────┘
                                     │
                                     ▼
                           ┌─────────────────────┐
                           │    Sanitization     │
                           │       Engine        │
                           │                     │
                           │ Capability Detection│
                           │ Method Selection    │
                           │ NVMe / ATA / SCSI   │
                           │ Generic Fallback    │
                           └──────────┬──────────┘
                                      │
                                      ▼
                           ┌─────────────────────┐
                           │    Verification     │
                           │                     │
                           │ Read-back Checks    │
                           │ Result Generation   │
                           └──────────┬──────────┘
                                      │
                                      ▼
                           ┌─────────────────────┐
                           │    UI / CLI /       │
                           │    Audit Reports    │
                           └─────────────────────┘
```

---

# Project Structure

```text
ReSecureOS/
│
├── UI/
│   ├── ui.py
│   └── sanitizer_ui.cpp
│
├── acquisition/
│   ├── AcquisitionManager.cpp
│   ├── AcquisitionManager.h
│   ├── DiskImager.cpp
│   ├── DiskImager.h
│   ├── HashEngine.cpp
│   ├── HashEngine.h
│   ├── WriteProtection.cpp
│   └── WriteProtection.h
│
├── device/
│   ├── DriveInfo.h
│   ├── DriveManager.cpp
│   └── DriveManager.h
│
├── recovery/
│   ├── FileCarver.cpp
│   ├── FileCarver.h
│   ├── FileValidator.cpp
│   ├── FileValidator.h
│   ├── ConfidenceScorer.cpp
│   ├── ConfidenceScorer.h
│   ├── FileClassifier.cpp
│   ├── FileClassifier.h
│   └── RecoveredFile.h
│
├── sanitization/
│   ├── SanitizationEngine.cpp
│   ├── SanitizationEngine.h
│   ├── DeviceCapabilityProbe.cpp
│   ├── DeviceCapabilityProbe.h
│   ├── DeviceCapabilities.h
│   ├── SanitizationResult.h
│   ├── GenericBlockSanitizer.cpp
│   ├── GenericBlockSanitizer.h
│   ├── AtaSanitizer.cpp
│   ├── AtaSanitizer.h
│   ├── NvmeSanitizer.cpp
│   ├── NvmeSanitizer.h
│   ├── ScsiSanitizer.cpp
│   ├── ScsiSanitizer.h
│   ├── Verification.cpp
│   └── Verification.h
│
├── apps/
│   ├── acquisition-test/
│   ├── device-test/
│   ├── recovery-test/
│   └── sanitizer/
│
├── os/
│   └── launcher/
│
├── assets/
│   ├── screenshots/
│   ├── logo/
│   └── banner/
│
├── CMakeLists.txt
├── README.md
├── LICENSE
└── CONTRIBUTING.md
```

---

# Technology Stack

| Technology         | Purpose                           |
| ------------------ | --------------------------------- |
| **Linux**          | Operating system platform         |
| **C++17**          | Core forensic and storage engine  |
| **CMake**          | Build system                      |
| **Python 3**       | Application/UI layer              |
| **Tkinter**        | Lightweight GUI                   |
| **pybind11**       | Python ↔ C++ integration          |
| **OpenSSL**        | SHA-256 hashing                   |
| **libblkid**       | Block-device information          |
| **libudev**        | Device discovery                  |
| **NVMe ioctl**     | NVMe device operations            |
| **SCSI SG_IO**     | Storage command passthrough       |
| **The Sleuth Kit** | Filesystem forensic functionality |

---

# Installation

## Requirements

ReSecureOS is currently developed for Linux.

Recommended environment:

```text
Linux
 ├── C++17 compiler
 ├── CMake
 ├── Python 3
 ├── Tkinter
 ├── pybind11
 ├── OpenSSL
 ├── libblkid
 ├── libudev
 └── The Sleuth Kit
```

### Debian / Ubuntu

```bash
sudo apt update

sudo apt install \
    build-essential \
    cmake \
    git \
    python3 \
    python3-dev \
    python3-tk \
    pybind11-dev \
    libssl-dev \
    libblkid-dev \
    libudev-dev \
    pkg-config \
    libtsk-dev
```

---

# Build

Clone the repository:

```bash
git clone https://github.com/sanyampat/ReSecureOS.git
cd ReSecureOS
```

Create a build directory:

```bash
mkdir -p build
cd build
```

Configure:

```bash
cmake ..
```

Build:

```bash
cmake --build . -j$(nproc)
```

---

# Running the GUI

From the repository root:

```bash
PYTHONPATH="$PWD/UI" python3 UI/ui.py
```

---

# Sanitization Safety

**ReSecureOS performs destructive storage operations.**

Before sanitizing a device, always verify:

1. Device path
2. Model
3. Serial number
4. Capacity
5. Mount state
6. System-disk status
7. Sanitization capability
8. Intended target device

Example:

```bash
lsblk -o NAME,SIZE,MODEL,SERIAL,TYPE,MOUNTPOINTS
```

Never assume that:

```text
/dev/sda
/dev/sdb
/dev/nvme0n1
```

refers to a particular physical device.

Linux device names can change depending on hardware configuration and boot order.

---

# Sanitization Philosophy

ReSecureOS follows a **capability-driven sanitization model**.

Different storage technologies behave differently, so the platform attempts to select an appropriate mechanism based on the capabilities of the target device.

```text
HDD
 └── Block-level overwrite where appropriate

SATA SSD
 └── Prefer device-supported sanitization mechanisms

NVMe SSD
 └── Prefer supported NVMe device-level mechanisms

SCSI
 └── Use supported SCSI sanitization mechanisms

USB / Virtual / Unknown
 └── Use an appropriate fallback
     and clearly report the achievable assurance
```

ReSecureOS distinguishes between different assurance levels rather than assuming that every device can be sanitized identically.

The software should not claim a stronger sanitization assurance than the available device capabilities and verification evidence support.

---

# Verification

Verification is treated as a separate subsystem.

For logical clearing operations, the current architecture supports randomized read-back sampling.

```text
Sanitization
     │
     ▼
Verification
     │
 ┌───┴───┐
 ▼       ▼
PASS    FAIL
 │       │
 ▼       ▼
Done    Report
```

Verification results can be included in the sanitization result and audit information.

---

# Forensic Acquisition

ReSecureOS provides a controlled acquisition workflow designed to preserve evidence integrity.

```text
Source Device
      │
      ▼
Device Inspection
      │
      ▼
Write Protection
      │
      ▼
Disk Imaging
      │
      ▼
SHA-256 Hash
      │
      ▼
Evidence Manifest
      │
      ▼
Forensic Image
```

Acquisition metadata can include:

* Source device
* Device model
* Serial number
* Image destination
* Image size
* SHA-256 hash
* Acquisition status
* Timestamp
* Write-protection state

---

# Data Recovery

The recovery subsystem works primarily from disk images rather than modifying original evidence.

```text
Disk Image
     │
     ▼
File Carving
     │
     ▼
Validation
     │
     ▼
Confidence Scoring
     │
     ▼
Classification
     │
     ▼
Recovered Files
```

Recovered files can be independently validated using standard Linux tools.

Example:

```bash
file recovered-file
```

and:

```bash
sha256sum recovered-file
```

---

# Development Status

## Implemented

* [x] Storage device discovery
* [x] Drive metadata abstraction
* [x] Linux block-device interaction
* [x] C++17 modular architecture
* [x] CMake build system
* [x] Disk imaging
* [x] SHA-256 hashing
* [x] Write-protection abstraction
* [x] File carving
* [x] File validation
* [x] Confidence scoring
* [x] File classification
* [x] Python/Tkinter GUI
* [x] Python/C++ pybind11 bridge
* [x] Capability probing architecture
* [x] Sanitization result model
* [x] Generic block sanitization architecture
* [x] NVMe sanitization architecture
* [x] ATA sanitization architecture
* [x] SCSI sanitization architecture
* [x] Post-operation verification architecture
* [x] System/mounted-device safety guards

## In Development

* [ ] Hardware-wide sanitization validation
* [ ] Improved ATA passthrough compatibility
* [ ] Improved SCSI capability detection
* [ ] Device-specific verification strategies
* [ ] Stronger system-disk/LVM detection
* [ ] Automated regression testing
* [ ] Sanitization certificates
* [ ] Full forensic audit logging
* [ ] Bootable Live ISO
* [ ] Hardware compatibility database
* [ ] Production deployment image

---

# Roadmap

### Phase 1 — Core Platform

* [x] Device discovery
* [x] Device metadata
* [x] Modular architecture
* [x] CMake build
* [x] Linux integration

### Phase 2 — Forensic Acquisition

* [x] Disk imaging
* [x] SHA-256 hashing
* [x] Write-protection abstraction
* [x] Evidence manifest
* [ ] Extended acquisition logging

### Phase 3 — Recovery

* [x] File carving
* [x] File validation
* [x] Confidence scoring
* [x] File classification
* [ ] More file signatures
* [ ] Fragmented-file recovery
* [ ] Advanced filesystem recovery
* [ ] Recovery reporting

### Phase 4 — Sanitization

* [x] Sanitization engine
* [x] Capability detection
* [x] Device-specific sanitizer architecture
* [x] Generic fallback
* [x] Result/audit structure
* [ ] ATA hardening
* [ ] NVMe hardware validation
* [ ] SCSI validation
* [ ] Media-aware verification
* [ ] Sanitization certificates

### Phase 5 — ReSecureOS

* [x] Linux development environment
* [x] GUI
* [ ] Bootable ISO
* [ ] Automatic GUI startup
* [ ] Offline forensic toolkit
* [ ] Evidence/audit storage
* [ ] Automated device classification
* [ ] Hardware compatibility database
* [ ] Production-ready deployment image

---

# Open Source

ReSecureOS is intended to be developed as an open-source project.

Contributions are welcome from developers, cybersecurity researchers, digital forensics practitioners, Linux developers, storage engineers, and students.

Areas where contributions are especially useful include:

* Storage hardware compatibility
* Filesystem support
* Forensic acquisition
* Recovery algorithms
* NVMe/ATA/SCSI support
* Verification mechanisms
* GUI development
* Testing
* Documentation
* Live ISO development

See [`CONTRIBUTING.md`](CONTRIBUTING.md) for contribution guidelines.

---

# Contributing

Create a feature branch:

```bash
git checkout -b feature/your-feature
```

Make your changes and test them using disposable devices or virtual disks where applicable.

Commit:

```bash
git add .
git commit -m "Add: your feature"
```

Push:

```bash
git push origin feature/your-feature
```

Then open a Pull Request.

### Contribution principles

* Keep modules separated by responsibility.
* Prefer modern C++ practices.
* Avoid destructive operations in automated tests.
* Test storage operations using disposable devices.
* Document hardware-specific behavior.
* Clearly identify experimental functionality.
* Never claim sanitization assurance without appropriate evidence.
* Add regression tests for new functionality.

---

# Testing

Storage operations should be tested against:

* Disposable drives
* Virtual disks
* Test images
* Authorized evidence media

A safe development environment can use:

```text
QEMU / VMware
      │
      ▼
Disposable Virtual Disk
      │
      ▼
ReSecureOS
      │
      ▼
Testing
```

**Never use your operating-system disk for destructive testing.**

---

# Security

If you discover a security vulnerability in ReSecureOS, please avoid publicly posting sensitive exploit details before the issue can be investigated.

A dedicated security policy and responsible disclosure process will be added as the project matures.

---

# License

ReSecureOS is open source.

See [`LICENSE`](LICENSE) for the applicable license.

---

# Project Status

🚧 **ReSecureOS is currently under active development.**

Some features, particularly hardware-specific sanitization and the bootable operating-system environment, are experimental and require additional hardware validation.

Do not treat experimental functionality as a production-grade sanitization guarantee.

---

# Vision

The long-term goal of ReSecureOS is to become a **portable, offline forensic and storage-security operating system** that can boot directly from removable media and provide investigators and security professionals with a complete storage workflow.

```text
                ReSecureOS
                    │
        ┌───────────┼───────────┐
        │           │           │
        ▼           ▼           ▼
     Acquire     Recover     Resecure
        │           │           │
        └───────────┼───────────┘
                    │
                    ▼
                Verify
                    │
                    ▼
                 Report
```

---

## ⭐ Support the Project

If ReSecureOS is useful to you:

* ⭐ Star the repository
* 🐛 Report bugs
* 💡 Suggest features
* 🔧 Submit pull requests
* 📖 Improve documentation
* 🧪 Test on additional storage hardware

Every contribution helps make ReSecureOS better.

---

## ReSecureOS

**Recover. Acquire. Verify. Resecure.**

Built for:

**Digital Forensics · Data Recovery · Evidence Acquisition · Storage Security · Linux**
