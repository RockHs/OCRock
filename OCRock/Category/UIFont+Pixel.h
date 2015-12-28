//
//  UIFont+Pixel.h
//  OCRock
//
//  Created by rock on 15/12/28.
//  Copyright © 2015年 rock. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIFont (Pixel)

+(UIFont*)fontWithName:(NSString *) fontName Pixel:(CGFloat)pixel;
+(UIFont*)fontWithName:(NSString *) fontName sizeInPixels:(CGFloat) pixels;

@end
