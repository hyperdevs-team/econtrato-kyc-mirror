//
//  ValiDasPayloadBidiCode.h
//  VDLibrary
//
//  Copyright © 2020 Veridas. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <VDLibrary/ValiDasPayload.h>
#import <VDLibrary/ValiDasBidiResult.h>

NS_ASSUME_NONNULL_BEGIN

@interface ValiDasPayloadBidiCode : ValiDasPayload

-(id _Nonnull)initWithElement:(ValiDasBidiResult*)element;

@end

NS_ASSUME_NONNULL_END
