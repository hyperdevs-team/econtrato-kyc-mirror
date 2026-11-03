//
//  CustomConfiguration.h
//  VDLibrary
//
//  Copyright © 2020 Veridas. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CustomConfiguration : NSObject

+ (float) getSecondsForObverseDetectionCapture: (NSArray<NSString *> *) documents;
+ (float) getSecondsForReverseDetectionCapture: (NSArray<NSString *> *) documents;
+ (float) getSecondsForObverseCountdown: (NSArray<NSString *> *) documents;
+ (float) getSecondsForReverseCountdown: (NSArray<NSString *> *) documents;

@end

NS_ASSUME_NONNULL_END
