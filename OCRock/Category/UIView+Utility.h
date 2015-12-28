//
//  UIView+Utility.h
//  OCRock
//
//  Created by rock on 15/12/28.
//  Copyright © 2015年 rock. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^UIViewClickHandle)(UIView *view);

@interface UIView (Utility)

@property(nonatomic) CGFloat left;
@property(nonatomic) CGFloat top;
@property(nonatomic) CGFloat right;
@property(nonatomic) CGFloat bottom;

@property(nonatomic) CGFloat width;
@property(nonatomic) CGFloat height;

@property(nonatomic) CGFloat centerX;
@property(nonatomic) CGFloat centerY;

-(void)makeRoundCorner;
-(void)makeRoundCornerWithRadius:(CGFloat)radius;
-(void)becomeRound;
- (UIViewController *)parentViewController;

- (void)handleClick:(UIViewClickHandle)handle;

@end
