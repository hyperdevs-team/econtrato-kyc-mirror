// swift-tools-version:5.9
import PackageDescription

// The eContrato-KyC iOS SDK (5.0.6) and the frameworks it links, as binary targets. SSZipArchive stays even though the
// vendor manual says it is no longer used: econtratokyc_2_sdk still links @rpath/SSZipArchive.framework.
let package = Package(
    name: "EContratoKYC",
    products: [
        .library(
            name: "EContratoKYC",
            targets: [
                "econtratokyc_2_sdk", "ImageProcessing", "VDDocumentCapture", "VDLibrary", "VDPhotoSelfieCapture", "SSZipArchive"
            ]
        )
    ],
    targets: [
        .binaryTarget(name: "econtratokyc_2_sdk", path: "Sources/econtratokyc_2_sdk.xcframework"),
        .binaryTarget(name: "ImageProcessing", path: "Sources/ImageProcessing.xcframework"),
        .binaryTarget(name: "VDDocumentCapture", path: "Sources/VDDocumentCapture.xcframework"),
        .binaryTarget(name: "VDLibrary", path: "Sources/VDLibrary.xcframework"),
        .binaryTarget(name: "VDPhotoSelfieCapture", path: "Sources/VDPhotoSelfieCapture.xcframework"),
        .binaryTarget(name: "SSZipArchive", path: "Sources/SSZipArchive.xcframework")
    ]
)
