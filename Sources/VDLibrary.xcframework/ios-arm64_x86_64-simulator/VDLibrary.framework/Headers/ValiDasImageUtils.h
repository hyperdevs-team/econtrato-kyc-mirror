//
//  ValiDasImageUtils.h
//  VDLibrary
//
//  Copyright © 2019 Veridas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ValiDasImageUtils : NSObject

#pragma mark - Image Helpers

/**
 @brief Returns an image with a new size.
 @param image (UIImage*) image to resize
 @param newSize (CGSize) the new image size
 @returns (UIImage*) The resized image
 */
+(UIImage*)imageWithImage:(UIImage*)image scaledToSize:(CGSize)newSize;

/**
 Gets an image from the Assets folder of the selected bundle if possible. If the image is not found in the selected bundle, the main bundle is used.
 
 @param bundle to look for the image.
 @param name of the image.
 
 @returns the image if found, nil otherwise.
 */
+ (UIImage * _Nullable) getImageFromAssetsWithBundle: (NSBundle * _Nonnull) bundle andName: (NSString * _Nonnull) name;
/**
 Gets an image from the Resources folder in the selected bundle if possible. If the image is not found in the selected bundle, the main bundle is used.
 
 @param bundle to look for the image.
 @param name of the image.
 
 @returns the image if found, nil otherwise.
 */
+ (UIImage * _Nullable) getImageFromResourcesWithBundle: (NSBundle * _Nonnull) bundle andName: (NSString * _Nonnull) name;
/**
 Load an image with the supplied name, from:
 
     1. Assets folder (selected bundle first, main bundle sencond).
     2. Resources folder if not found in the assets folder (selected bundle first, main bundle sencond).
 
 @param bundle to look for the image.
 @param name of the image.
 
 @returns the image if found, nil otherwise.
 */
+ (UIImage * _Nullable) loadImageFromBundle: (NSBundle * _Nonnull) bundle andName: (NSString * _Nonnull) name;
    
/**
 @brief Returns and resize a image for a height.
 @param image (UIImage*) image to resize
 @param heightTarget (int) height to resize
@returns (UIImage*) The resized image
 */
+(UIImage*)getImageTarget:(UIImage*)image forHeight:(int)heightTarget;
+(UIImage*)getImageTarget:(UIImage*)image forWidth:(int)widthTarget;

/**
 @brief Returns the region resized for and image and ratios.
 @param region (CGRect) region to resize
 @param ratioX (float) the X ratio to resize
 @param ratioY (float) the Y ratio to resize
 @param image (UIImage*) the image
@returns (CGRect) The resized rect
 */
+(CGRect)resizeRegionToImage:(CGRect)region withRatioX:(float)ratioX andRatioY:(float)ratioY inImage:(UIImage*)image;

/**
 @brief Returns a rotated image.
 @param image (UIImage*) image to rotate
 @returns (UIImage*) The rotated image
 */
+(UIImage*)rotateImage:(UIImage*)image;


@end

NS_ASSUME_NONNULL_END
