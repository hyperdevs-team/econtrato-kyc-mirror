//
//  FirebaseTagProtocol.h
//  VDLibrary
//
//  Copyright © 2019 Veridas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VDLibrary/ValiDasConstantes.h>

@protocol FirebaseTagProtocol <NSObject>

@optional

-(void)iterationDetectionMode:(detectorMode)mode;
-(void)typeDocumentDetected:(NSString*)type;
-(void)rectangleDetected:(BOOL)detected;
-(void)documentDetectionProgress:(float)progress;

@end
