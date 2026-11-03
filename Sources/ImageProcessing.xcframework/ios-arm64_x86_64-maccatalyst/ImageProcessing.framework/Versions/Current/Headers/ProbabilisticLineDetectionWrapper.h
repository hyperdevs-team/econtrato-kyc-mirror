//
//  ProbabilisticLineDetectionWrapper.h
//  ImageProcessing
//
//  Created by Veridas on 5/10/22.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ProbabilisticLineDetectionWrapper : NSObject

- (void) detect: (UIImage *) image;
- (int) getNumSegments;
- (int*) getSegmentsData;

@end

NS_ASSUME_NONNULL_END
