# econtrato-kyc-mirror

Private mirror of the eContrato-KyC identity verification SDK (Inetum, with Veridas libraries) for the eTravel apps.
The files are the vendor's and are kept here only so both apps build without access to the plugin repository they came
from. **Do not make this repository public and do not redistribute the files.** Delete it when the SDK is replaced.

One repository serves both platforms:

| | Android | iOS |
|---|---|---|
| SDK version | 5.0.7 | 5.0.6 |
| Layout | Maven: `es/orange/econtratokyc/<artifact>/5.0.7/` with a minimal POM each | Swift package: `Package.swift` and `Sources/*.xcframework` |
| Consumed with | `maven { url }` in `settings.gradle.kts`, sending a GitHub token | Swift Package Manager, by URL and tag |

The files are byte for byte the ones in `masorange/acme-monorepo` at commit `d852ebdecf20a4e391c762392e900abbb1eb9dd9`
(`capacitorecontrato-library-typescript`). The POMs only name the artifact: the SDK ships no dependency metadata, so the
consuming app declares the libraries it needs.

## Android

The repository is private, so Gradle must send a token. The app reads it from `gh auth token`, the `GITHUB_TOKEN`
environment variable or the `kycMirrorToken` Gradle property, in that order of preference. See
`pkg/etravel/docs/kyc.md` in `apps-monorepo`.

## iOS

Add `https://github.com/hyperdevs-team/econtrato-kyc-mirror` as a package dependency, exact version `5.0.6`, product
`EContratoKYC`. SwiftPM clones with your own git credentials, so you need to be signed in to GitHub.

Tags: `5.0.6` is the iOS SDK. Android has no tag: its version is in the folder names.
