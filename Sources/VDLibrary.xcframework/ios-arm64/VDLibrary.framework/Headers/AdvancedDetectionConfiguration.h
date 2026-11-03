//
//  AdvancedDetectionConfiguration.h
//  VDLibrary
//
//  Created by Veridas on 17/3/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AdvancedDetectionConfiguration : NSObject

/**
 True if rectangles should be activated before smart detection.
 False otherwise.
 */
@property (nonatomic) BOOL deferredEnabled;

/**
 True if rectangles should be activated after smart detection. This will be activated after a delay.
 False otherwise.
 */
@property (nonatomic) BOOL isEnabled;

/**
 True whenever the rectangles are needed after delay.
 False otherwise.
 */
@property (nonatomic) BOOL delayReached;


@end

NS_ASSUME_NONNULL_END
