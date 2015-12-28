//
//  UIFont+Pixel.m
//  OCRock
//
//  Created by rock on 15/12/28.
//  Copyright © 2015年 rock. All rights reserved.
//

#import "UIFont+Pixel.h"

@implementation UIFont (Pixel)

+(UIFont *)fontWithName:(NSString *)fontName Pixel:(CGFloat)pixel
{
    CGFloat pointsPerInch = 72.0; // see: http://en.wikipedia.org/wiki/Point%5Fsize#Current%5FDTP%5Fpoint%5Fsystem
    CGFloat scale = 1; // We dont't use [[UIScreen mainScreen] scale] as we don't want the native pixel, we want pixels for UIFont - it does the retina scaling for us
    float pixelPerInch; // aka dpi
    if (IS_IPAD) {
        pixelPerInch = 132 * scale;
    }else if (IS_IPHONE_6P){
        pixelPerInch = 200 * scale;
    }else{
        pixelPerInch = 163 * scale;
    }
    CGFloat result = pixel * pointsPerInch / pixelPerInch;
    return [UIFont fontWithName:fontName size:result];
}

+(UIFont *) fontWithName:(NSString *) fontName sizeInPixels:(CGFloat) pixels {
    static NSMutableDictionary *fontDict; // to hold the font dictionary
    if ( fontName == nil ) {
        // we default to @"HelveticaNeue-Medium" for our default font
        fontName = @"HelveticaNeue-Medium";
    }
    if ( fontDict == nil ) {
        fontDict = [ @{} mutableCopy ];
    }
    // create a key string to see if font has already been created
    //
    NSString *strFontHash = [NSString stringWithFormat:@"%@-%f", fontName , pixels];
    UIFont *fnt = fontDict[strFontHash];
    if ( fnt != nil ) {
        return fnt; // we have already created this font
    }
    // lets play around and create a font that falls near the point size needed
    CGFloat pointStart = pixels/4;
    CGFloat lastHeight = -1;
    UIFont * lastFont = [UIFont fontWithName:fontName size:.5];\
    
    NSMutableDictionary * dictAttrs = [ @{ } mutableCopy ];
    NSString *fontCompareString = @"Mgj^";
    for ( CGFloat pnt = pointStart ; pnt < 1000 ; pnt += .5 ) {
        UIFont *font = [UIFont fontWithName:fontName size:pnt];
        if ( font == nil ) {
            NSLog(@"Unable to create font %@" , fontName );
            NSAssert(font == nil, @"font name not found in fontWithName:sizeInPixels" ); // correct the font being past in
        }
        dictAttrs[NSFontAttributeName] = font;
        CGSize cs = [fontCompareString sizeWithAttributes:dictAttrs];
        CGFloat fheight =  cs.height;
        if ( fheight == pixels  ) {
            // that will be rare but we found it
            fontDict[strFontHash] = font;
            return font;
        }
        if ( fheight > pixels ) {
            if ( lastFont == nil ) {
                fontDict[strFontHash] = font;
                return font;
            }
            // check which one is closer last height or this one
            // and return the user
            CGFloat fc1 = fabs( fheight - pixels );
            CGFloat fc2 = fabs( lastHeight  - pixels );
            // return the smallest differential
            if ( fc1 < fc2 ) {
                fontDict[strFontHash] = font;
                return font;
            } else {
                fontDict[strFontHash] = lastFont;
                return lastFont;
            }
        }
        lastFont = font;
        lastHeight = fheight;
    }
    NSAssert( false, @"Hopefully should never get here");
    return nil;
}

@end
