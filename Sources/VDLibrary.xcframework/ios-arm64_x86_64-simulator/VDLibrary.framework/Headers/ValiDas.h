//
//  ValiDasLibrary.h
//  ValiDasLibrary
//
//  Copyright © 2015 Veridas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ImageIO/ImageIO.h>
#import <VDLibrary/ValiDasDocumento.h>
#import <VDLibrary/ValiDasConstantes.h>
#import <VDLibrary/FirebaseTagProtocol.h>
#import <VDLibrary/ValiDasBidiCode.h>
#import <VDLibrary/ValiDasBidiResult.h>
#import <VDLibrary/ValiDasPayload.h>
#import <VDLibrary/UserAgent.h>
#import <VDLibrary/Artifact.h>
#import <VDLibrary/AdvancedDetectionConfiguration.h>
#import <VDLibrary/InitialOffsets.h>
#import <VDLibrary/CameraConfiguration.h>


#define DOCUMENT_SDK @"DocumentSdk"
#define PHOTO_SELFIE_SDK @"PhotoSelfieSdk"
#define VIDEO_SELFIE_SDK @"VideoSelfieSdk"

#define VALIDAS_TESTS @"ValidasTests"

@protocol ProtocoloValiDas <NSObject>

@optional
/**
 @brief Método delegado invocado cuando se detecta el frontal del DNI.
 */
- (void)documentObverseDetected;

/**
 @brief Método delegado invocado cuando se detecta el reverso del DNI.
 */
- (void)documentReverseDetected;

/**
 @brief Método delegado invocado cuando se detecta el reverso del DNI.
 */
- (void)passportDetected;

/**
 @brief Método delegado invocado cuando se detecta el selfie del usuario.
 */
- (void)frontFaceDetected;

/**
 @brief Método delegado invocado cuando se desea alertar debido al brillo.
 */
- (void)brightDetected;

/**
 @brief Método delegado invocado cuando se desea quitar la alerta del brillo.
 */
- (void)deleteBright;

/**
 @brief Método delegado invocado cuando se desea notificar la distaincia a la que se encuentra el DNI.
 @param proximity Distancia a la que se encuentra el DNI.
 */
- (void)patternDistance:(PatternProximity)proximity;

/**
 @brief Método delegado invocado cuando se desea notificar la finalización de la detección de un documento
 @param result Tipo de resultado
 */
- (void)analysisFinished:(ResultType)result;

/**
 @brief Método que devuelve un diccionario con la información de los países y documentos disponibles para su procesado en la aplicación.
 @param dictionary (NSDictionary <NSString *, ValiDasDocumento *> *) Diccionario con la información de los paíse en las claves y de los documentos en los valores.
 */
- (void)getDocumentDictionary:(NSDictionary <NSString *, ValiDasDocumento *> * _Nonnull)dictionary;

/**
 @brief Método delegado que envía la información del documento encontrado.
 @param docType (NSArray<NSNumber *> *), tipo de documento encontrado.
 */
- (void)documentTypeFound: (NSArray<NSString *> * _Nullable) docType;

- (void)fpsCalculated:(int)fps;

@end

@interface ValiDas : NSObject

/**
 Static method for "Singleton" initialization (similar somehow, but not a Singleton, actually).
 */
+ (void)init;

/**
 @brief Método invocado cuando se desea finalizar el sistema vali-Das
 */
+ (void)finalizeInstance;

/**
 @brief Método que permite programar un delegado al que devolver los eventos del protocolo
 @param delegate (id) Instancia de la clase.
 @param _sdkId String con el "SDK setter" de dicho delegate.
 */
+ (void)setDelegate:(id)delegate from:(NSString *)sdkId;

/**
 @brief Método que busca un documento en una imagen
 @param documentArray (NSArray<ValiDasDocumento*>*) Array de documentos a buscar
 @param type (AnalysisType) Tipo de análisis a realizar
 @param image (UIImage *) Imagen original
 @returns GRect Región que contiene las regiones del documento
 */
+ (CGRect)searchDocumentsWithDocs:(NSArray<ValiDasDocumento*>* _Nonnull)documentArray analysisType:(AnalysisType)type image:(UIImage* _Nonnull)image searchType: (SearchType) searchType andAdvancedDetectionConfiguration: (AdvancedDetectionConfiguration * _Nonnull) advancedDetectionConfiguration;

/**
 @brief Método que busca una cara frontal en una imagen
 @param image (UIImage *) Imagen original
 @param tightness (NSString *)
 @returns GRect Región que contiene la región de la cara
 */
+ (CGRect)searchFrontalFace:(UIImage* _Nonnull)image withTightness:(NSString * _Nonnull)tightness;

/**
 @brief Método que busca una cara frontal en una imagen
 @param image (UIImage *) Imagen original
 @returns GRect Región que contiene la región de la cara
 */
+ (CGRect)searchFrontalFaceVideo:(UIImage* _Nonnull)image;

/**
 @brief Método que busca un código Bidi en una imagen. La librería rotará la imagen manualmente según las rotaciones recibidas.
 @param image (UIImage *) Imagen original.
 @param hints (NSArray) Array con los formatos a buscar. ENUM BidiType.
 @param rotations (NSArray) Array con las rotaciones de los códigos a buscar. ENUM Rotation.
 @returns NSArray<ValiDasBidiResult*>* Array deo bjetos con la info del código bidi leído o nil si no se lee nada
 */
+ (NSArray<ValiDasBidiResult*>* _Nullable)searchBidiCodes:(UIImage* _Nonnull)image hints:(NSArray* _Nullable)hints rotations:(NSArray* _Nullable)rotations;

/**
 @brief Analyzes an image containing one face and delivers the cut section of the face if found.
 @param data (NSData *) Imagen original
 @returns Cut section of the face if found, full image if not.
 */
+ (UIImage * _Nullable)analyzeFrontalFace:(NSData * _Nonnull)data;

/**
 @brief Método que analiza un vídeo en busca de pruebas de vida.
 */
+ (void)analizeProofOfLife;

/**
 @brief Método que devuelve la versión de la librería
 @returns NSString Versión de la librería
 */
+ (NSString * _Nonnull) getVersion;

+ (UIImage * _Nullable)getStoredImage:(int)analysisType;

/**
 Sets the screen size for tests (device not available)
 @param size size of the screen.
 */
+ (void) setScreenSizeForTest: (CGSize) size;

/**
 @brief Get the reference region where to locate the document.
 @returns (CGRect) Rect with the region.
 */
+ (CGRect)getReferenceRegion:(NSString* _Nullable)standardType;

/**
 @brief Get the reference region where to locate the passport.
 @returns (CGRect) Rect with the region.
 */
+ (CGRect)getReferenceRegionPassport;

/**
 @brief Gets the device model string.
 @returns (NSString *) String with the device model.
 */
+ (NSString * _Nonnull)getDeviceModel;
+ (void)restartSearch;
+ (CGRect)getReferenceRegionOpenCV:(CGSize)sizeImage;

/**
 @brief Returns all the available default configuration.
 @returns (NSDictionary*) Default configuration.
 */
+(NSDictionary* _Nonnull)getDefaultConfig;

/**
 @brief Returns all the available documents info ordered by group.
 @returns (NSDictionary *) Available Documents by Group.
 */
+ (NSDictionary* _Nonnull)getAvailableDocumentsByGroup;

/**
 @brief Returns all the available documents.
 @returns (NSArray *) Available Documents.
 */
+ (NSArray* _Nonnull)getAvailableDocuments;

/**
 @brief Returns the standard type for document.
 @param doc (NSString*) Document Id
 @returns (NSString *) standard type
 */
+ (NSString* _Nonnull)getStandardTypeForDocument:(NSString* _Nullable)doc;

/**
 @brief Returns the image template name for document.
 @param doc (NSString*) Document Id
 @param forReverse (BOOL) If search for reverse or not
 @returns (NSString *) standard type
 */
+ (NSString* _Nullable)getTemplateNameForDocument:(NSString* _Nullable)doc forReverse:(BOOL)forReverse;

/**
@brief Returns the bidi documents for document.
@param doc (NSString*) Document Id
@returns (NSArray<ValiDasBidiCode>*) array with ValiDasBidiCode objects for the document or nil if there are no codes for that document
*/
+(NSArray<ValiDasBidiCode*>* _Nullable)getBidiCodesForDocument:(NSString* _Nullable)doc;

/**
@brief Returns the bidi documents for document in a given side.
@param doc (NSString*) Document Id
@param side (SideType) the document side for getting bidi codes.
@returns (NSArray<ValiDasBidiCode>*) array with ValiDasBidiCode objects for the document or nil if there are no codes for that document in that side
*/
+(NSArray<ValiDasBidiCode*>* _Nullable)getBidiCodesForDocument:(NSString* _Nullable)doc side:(SideType)side;

/**
 @brief Returns the document id for a document legacy id.
 @param legacyId (NSString*) legacy id
 @returns (NSString *) Document id
 */
+ (NSString* _Nonnull)getDocumentForLegacyId:(NSString* _Nullable)legacyId;
+ (NSString* _Nullable)getLegacyIdForDocument:(NSString* _Nullable)document;

/**
 @brief Returns the ValiDasDocument for a document legacy id.
 @param legacyId (NSString*) id
 @returns (NSString *) ValiDasDocumento or nil
 */
+ (ValiDasDocumento * _Nullable)getValiDasDocumentForLegacyId:(NSString * _Nonnull)legacyId;
/**
 @brief Returns the ValiDasDocument for a document id.
 @param identifier (NSString*) id (not named id because name collission with objective-c's id)
 @returns (NSString *) ValiDasDocumento or nil
 */
+ (ValiDasDocumento * _Nullable)getValiDasDocumentForId:(NSString * _Nonnull) identifier;

/**
 @brief Returns if document is type Passport.
 @param docType (NSString*) Document Id
 @returns (BOOL) true if it's type Passport
 */
+ (BOOL)isDocumentTypePassport:(NSString* _Nullable)docType;

/**
 @brief Returns if document is a special EU paper driving license.
 @param doc (NSString*) Document Id
 @returns (BOOL) true if document is a special EU paper driving license.
 */
+ (BOOL)isDocumentTypeEuPaperDrivingLicense:(NSString* _Nullable)doc;

+ (BOOL) isDocumentSmart:(ValiDasDocumento* _Nonnull) document;

+(BOOL) isThereSomeNonIntelligentDocument:(NSArray<ValiDasDocumento*>* _Nonnull) documentArray analysisType:(AnalysisType) analysisType;

+ (BOOL) areAllSmartDocumentsIn:(NSArray<ValiDasDocumento*>* _Nonnull) documentArray withTypeAnalysis:(AnalysisType) analysisType;
/**
@brief Returns the imageData with added bidi codes metadata in EXIF.UserComment field.
@param artifact (struct Artifact*) artifact struct information.
@param payloads (NSArray<ValiDasPayload*>*) array of ValiDasPayload.
@param agent (UserAgent*) user agent information.
@returns (NSData*) image data with the bidi code metadata inserted.
*/
+(NSData* _Nonnull)addVeridasMetadataWithArtifact:(Artifact* _Nonnull)artifact payloads:(NSArray<ValiDasPayload*>* _Nullable)payloads userAgent:(UserAgent* _Nonnull)agent;

+ (void) setRectangleDetectorHardMode;

+ (CameraConfiguration * _Nonnull) getConfiguationForCurrentDevice;

@end
