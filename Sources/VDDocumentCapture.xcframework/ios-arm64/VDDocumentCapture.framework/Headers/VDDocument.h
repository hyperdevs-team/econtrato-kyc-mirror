//
//  VDDocument.h
//  VDDocumentCapture
//
//  Copyright © 2017 Veridas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VDDocumentCapture/VDEnums.h>

/**
 @brief Class that represents an available document.
 @details It just encapsulates the enum VDCaptureTypeEnum.
 */
@interface VDDocument : NSObject <NSCopying>

/**
 @brief (Deprecated) Property with the document value.
 */
@property (nonatomic) int documentType;

/**
 @brief Property with the document value.
 */
@property (nonatomic) int documentLegacyId;

/**
 @brief Property with the classification groups.
 */
@property (nonatomic) NSArray* groupIds;

/**
 @brief Property with the geographical areas.
 */
@property (nonatomic) NSArray* geographicalArea;

/**
 @brief Property with the document name.
 */
@property (nonatomic) NSString* documentName;

/**
 @brief Property with the document colloquial name.
 */
@property (nonatomic) NSString* shortDescription;

/**
 @brief Property with the document country name.
 */
@property (nonatomic) NSString* documentCountry;

/**
 @brief Property that represents whether a document has obverse or not. True if it has obverse, false otherwise.
 */
@property (nonatomic) BOOL hasObverse;

/**
 @brief Property that represents whether a document has reverse or not. True if it has reverse, false otherwise.
 */
@property (nonatomic) BOOL hasReverse;

@end
