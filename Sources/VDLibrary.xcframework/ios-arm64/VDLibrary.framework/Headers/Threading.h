//
// Created by Veridas on 29/8/24.
// Copyright (c) 2024 Veridas. All rights reserved.
//

#import <Foundation/Foundation.h>

void runOnMainThread(void (^function)(void));
void runOnMainThreadAndWait(void (^function)(void));
