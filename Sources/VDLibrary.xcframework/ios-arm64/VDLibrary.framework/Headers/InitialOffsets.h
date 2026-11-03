//
//  InitialOffsets.h
//  VDLibrary
//
//  Created by Veridas on 28/9/23.
//  Copyright © 2023 Veridas. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface InitialOffsets : NSObject

@property (nonatomic, readonly) int x;
@property (nonatomic, readonly) int xAt;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initDefaultIphone;
- (instancetype _Nonnull)initDefaultIpad;
- (instancetype _Nonnull)initDefaultOther;
- (instancetype _Nonnull)initWithX: (int) x
                               xAt: (int) xAt;

@end

NS_ASSUME_NONNULL_END
