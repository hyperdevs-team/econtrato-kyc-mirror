//
//  DefaultCameraConfiguration.h
//  VDLibrary
//
//  Copyright © 2023 Veridas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#import <VDLibrary/InitialOffsets.h>

NS_ASSUME_NONNULL_BEGIN

@interface CameraConfiguration : NSObject

@property (nonatomic, nonnull, strong, readonly) NSString* platform;
@property (nonatomic, nonnull, strong, readonly) NSString* commercialName;
@property (nonatomic, nonnull, strong, readonly) AVCaptureDeviceType deviceType;
@property (nonatomic, nonnull, strong, readonly) InitialOffsets* initialOffsets;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initDefaultIphone;
- (instancetype _Nonnull)initDefaultIpad;
- (instancetype _Nonnull)initDefaultOther;
- (instancetype _Nonnull)initWithPlatform:(NSString * _Nonnull)platform
                               deviceType:(AVCaptureDeviceType)deviceType
                        andInitialOffsets:(InitialOffsets * _Nonnull)initialOffsets;

@end


NS_ASSUME_NONNULL_END
