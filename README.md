# econtrato-kyc-mirror

Public mirror of the eContrato-KyC identity verification SDK (Inetum, with Veridas libraries) for the eTravel apps. The
files are the vendor's and are kept here only so both apps build without access to the plugin repository they came from.
**Do not redistribute them, and delete this repository when the SDK is replaced.**

> **The SDK carries a client certificate** (`signa_pro.p12`, with its password in the SDK's code) inside the Android AAR
> and inside the iOS framework. This repository is public, so anyone can download it. Whether the vendor's licence
> allows redistribution has not been confirmed. If the vendor or Security asks, make the repository private or delete it.

One repository serves both platforms:

| | Android | iOS |
|---|---|---|
| SDK version | 5.0.7 | 5.0.6 |
| Layout | Maven: `es/orange/econtratokyc/<artifact>/5.0.7/` with a minimal POM each | Swift package: `Package.swift` and `Sources/*.xcframework` |
| Consumed with | `maven { url }` in `settings.gradle.kts` | Swift Package Manager, by URL and tag |

The files are byte for byte the ones in `masorange/acme-monorepo` at commit `d852ebdecf20a4e391c762392e900abbb1eb9dd9`
(`capacitorecontrato-library-typescript`). The POMs only name the artifact: the SDK ships no dependency metadata, so the
consuming app declares the libraries it needs.

## Android

Add the repository to `settings.gradle.kts` and depend on `es.orange.econtratokyc:<artifact>:5.0.7`:

```kotlin
maven { url = uri("https://raw.githubusercontent.com/hyperdevs-team/econtrato-kyc-mirror/main") }
```

No token is needed.

## iOS

Add `https://github.com/hyperdevs-team/econtrato-kyc-mirror` as a package dependency, exact version `5.0.6`, product
`EContratoKYC`. No credentials are needed.

Tags: `5.0.6` is the iOS SDK. Android has no tag: its version is in the folder names.
