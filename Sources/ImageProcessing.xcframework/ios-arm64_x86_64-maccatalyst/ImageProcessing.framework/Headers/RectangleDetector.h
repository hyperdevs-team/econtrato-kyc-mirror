//
//  RectangleDetector.h
//  ImageProcessing
//
//  Copyright © 2018 Veridas. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface RectangleDetector : NSObject

+ (CGRect) findDocumentInImage:(UIImage*) image nearRect:(CGRect) rect;

@end
