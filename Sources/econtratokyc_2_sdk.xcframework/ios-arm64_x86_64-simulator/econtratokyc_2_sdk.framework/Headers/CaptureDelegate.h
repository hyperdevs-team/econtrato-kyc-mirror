//
//  Capture_Delegate.h
//  econtratokyc_2_sdk
//
//  Created by 79415840 on 21/2/23.
//  Copyright © 2023 INETUM. All rights reserved.
//

#ifndef Capture_Delegate_h
#define Capture_Delegate_h


#endif /* Capture_Delegate_h */

@protocol CaptureDelegate <NSObject>
@required
- (void) captureDidComplete:(NSDictionary*) result;
- (void) captureDidError:(NSError*) error;
- (void) captureDidCancel:(NSDictionary*) result;
@end

