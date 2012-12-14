// Copyright (c) 2012 Twelve Twenty (http://twelvetwenty.nl)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "TTClassMapping.h"
#import "TTObjectMapping.h"
#import "TTSpawnMapping.h"
#import "TTInjectable.h"

@protocol TTInjectorSpawning

- (id)objectForClass:(Class)class;
- (id)injectPropertiesIntoObject:(id <TTInjectable>)object;

@end

@protocol TTInjectorMapping

- (id <TTClassMapping>)mapClass:(Class)class;
- (void)unmapClass:(Class)class;

@end

#define Injector [TTInjector sharedInjector]

@interface TTInjector : NSObject <TTInjectorSpawning, TTInjectorMapping>

+ (id <TTInjectorSpawning>)sharedInjector;

+ (id <TTInjectorMapping>)sharedMappingInjector;

+ (TTInjector *)setSharedInjector:(TTInjector *)injector;

@end