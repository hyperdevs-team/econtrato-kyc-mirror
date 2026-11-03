//
//  DNObjectDetectionConfig.h
//  ImageProcessing
//
//  Copyright © 2016 Veridas. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DNObjectDetectionConfig : NSObject

@property NSString *cascadePath;
@property double scale;
@property NSUInteger neighbours;
@property NSUInteger minSizeWidth;
@property NSUInteger minSizeHeight;
@property NSUInteger maxSizeWidth;
@property NSUInteger maxSizeHeight;
@property float xTransformationFactorXml;
@property float yTransformationFactorXml;
@property float widthTransformationFactorXml;
@property float heightTransformationFactorXml;

@end
