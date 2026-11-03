//
//  ImageProcessing.h
//  ImageProcessing
//
//  Created by Veridas on 16/6/22.
//

#import <Foundation/Foundation.h>

// These are the public headers of the library
#import "BlurTechnics.h"
#import "DNObjectDetection.h"
#import "DNObjectDetectionConfig.h"
#import "DNTemplateMatching.h"
#import "DNTemplateMatchingConfiguration.h"
#import "ImageTransformation.h"
#import "RectangleDetector.h"


#import "ProbabilisticLineDetectionWrapper.h"

NS_ASSUME_NONNULL_BEGIN

@interface ImageProcessing : NSObject

+ (NSString * _Nonnull) getVersion;

@end

NS_ASSUME_NONNULL_END
