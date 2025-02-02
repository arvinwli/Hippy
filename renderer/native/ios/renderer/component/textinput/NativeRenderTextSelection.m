/*!
 * iOS SDK
 *
 * Tencent is pleased to support the open source community by making
 * Hippy available.
 *
 * Copyright (C) 2019 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "NativeRenderTextSelection.h"

@implementation NativeRenderTextSelection

- (instancetype)initWithStart:(NSInteger)start end:(NSInteger)end {
    if (self = [super init]) {
        _start = start;
        _end = end;
    }
    return self;
}

@end

@implementation HippyConvert (NativeRenderTextSelection)

+ (NativeRenderTextSelection *)NativeRenderTextSelection:(id)json {
    if ([json isKindOfClass:[NSDictionary class]]) {
        NSInteger start = [self NSInteger:json[@"start"]];
        NSInteger end = [self NSInteger:json[@"end"]];
        return [[NativeRenderTextSelection alloc] initWithStart:start end:end];
    }

    return nil;
}

@end
