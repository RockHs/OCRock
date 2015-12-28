//
//  RKAppMacro.h
//  OCRock
//
//  Created by rock on 15/12/28.
//  Copyright © 2015年 rock. All rights reserved.
//

#ifndef RKAppMacro_h
#define RKAppMacro_h

/*****************************设置VC尺寸及系统处理********************************begin*/
//系统版本号
#define XCODEAPPVERSION             [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
#define KEY_WINDOW                  [[UIApplication sharedApplication] keyWindow]
//判断为iPhone设备
#define IS_IPHONE                   UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone
#define IS_IPAD                     UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad
#define IS_RETINA                   ([[UIScreen mainScreen] scale] >= 2.0)
//设备宽度
#define SCREEN_WIDTH                ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT               ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH           (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH           (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))
//判断为何种设备
#define IS_IPHONE_4_OR_LESS         (IS_IPHONE && SCREEN_MAX_LENGTH < 568.0)
#define IS_IPHONE_5                 (IS_IPHONE && SCREEN_MAX_LENGTH == 568.0)
#define IS_IPHONE_6                 (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define IS_IPHONE_6P                (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)
//系统
#define IS_IOS8                     ([[UIDevice currentDevice].systemVersion floatValue] >= 8.0)
/*****************************设置VC尺寸及系统处理********************************end*/

/*****************************设置数据校验处理********************************begin*/
#define NSStringSafety(obj) \
[obj isKindOfClass:[NSObject class]]?[NSString stringWithFormat:@"%@",obj]:@""

#define NSArraySafety(obj) \
[obj isKindOfClass:[NSArray class]]?obj:nil

#define NSDictionarySafety(obj) \
[obj isKindOfClass:[NSDictionary class]]?obj:nil

#define ObjectForKeySafety(obj,key) \
[obj isKindOfClass:[NSDictionary class]]?[obj objectForKey:key]:nil


#define ObjectIndexSafety(obj,index) \
[obj isKindOfClass:[NSArray class]]&&index<[obj count] ? [obj objectAtIndex:index] :nil


#define NSMutableArraySafety(obj)  \
[obj isKindOfClass:[NSArray class]] || [obj isKindOfClass:[NSMutableArray class]] ? [NSMutableArray arrayWithArray:obj] :nil

#define NSMutableDictionarySafety(obj)  \
[obj isKindOfClass:[NSDictionary class]] || [obj isKindOfClass:[NSMutableDictionary class]] ? [NSMutableDictionary dictionaryWithDictionary:obj] : nil
/*****************************设置数据校验处理********************************end*/

/*****************************设置颜色值处理********************************begin*/
#define RGB(r, g, b)        RGBA(r,g,b,1)
#define RGBA(r, g, b, a)    [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define HEX(rgbValue)       [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
/*****************************设置颜色值处理********************************end*/

/*****************************设置文字大小处理********************************begin*/
#define RKFont(x)                       [UIFont fontWithName:@"Microsoft YaHei" size:x]
#define RKFontPixel(pix)                [UIFont fontWithName:@"Microsoft YaHei" Pixel:pix]
#define RKEnglishFontPixel(pix)         [UIFont fontWithName:@"Verdana" Pixel:pix]
#define RKEnglishItalicFontPixel(pix)   [UIFont fontWithName:@"Verdana-Italic" Pixel:pix]
/*****************************设置文字大小处理********************************end*/

#endif /* RKAppMacro_h */
