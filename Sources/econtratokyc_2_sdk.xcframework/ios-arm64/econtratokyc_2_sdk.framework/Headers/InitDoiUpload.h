//
//  InitDoiUpload.h
//  econtratokyc_2_sdk
//
//  Created by 79415840 on 21/2/23.
//  Copyright © 2023 INETUM. All rights reserved.
//

#ifndef InitDoiUpload_h
#define InitDoiUpload_h


#endif /* InitDoiUpload_h */

#import <UIKit/UIKit.h>
#import "CaptureDelegate.h"

@import WebKit;

NS_ASSUME_NONNULL_BEGIN

@interface InitDoiUpload : UIViewController

// External origin
@property (nonatomic, strong) id<CaptureDelegate> delegate;
@property (nonatomic, strong) NSString* brand;
@property (nonatomic, strong) NSString* idop;

@property (nonatomic, strong) NSString* petitionId;
@property (nonatomic, strong) NSString* processType;
@property (nonatomic, strong) NSString* systemID;
@property (nonatomic, strong) NSString* documentOwner;
@property (nonatomic, strong) NSString* sfid;
@property (nonatomic, strong) NSString* offer;
@property (nonatomic, strong) NSString* msisdn;
@property (nonatomic, strong) NSString* doubleCheck;
@property (nonatomic, strong) NSString* docId;
@property (nonatomic, assign) NSString* typeDocId;

@property (nonatomic, strong) NSString* customerCode;
@property (nonatomic, strong) NSString* clientName;
@property (nonatomic, strong) NSString* clientSurname;
@property (nonatomic, strong) NSString* isLifeTest;

@property NSNumber* test;

@end

NS_ASSUME_NONNULL_END
