//
//  NSDate+Trans.h
//  OCRock
//
//  Created by mac on 15/12/28.
//  Copyright © 2015年 rock. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (Trans)

//string转nsdate
- (NSDate*)transToDate:(NSString*)dateStr formatter:(NSString*)formatterStr;
//string转nsdate，默认格式”yyyy-MM-dd HH:mm:ss“
- (NSDate*)transToDateDefaultFormatter:(NSString*)dateStr;
//nsdate转string
- (NSString*)transToString:(NSDate*)date formatter:(NSString*)formatterStr;
//nsdate转string，默认格式”yyyy-MM-dd HH:mm:ss“
- (NSString*)transToStringDefaultFormatter:(NSDate*)date;
//时间戳转换
- (NSString*)transTime:(NSString*)dateStr formatter:(NSString*)formatterStr;
//两个时间相隔多久
- (NSInteger)calculateDateInterval:(NSDate*)fromDate toDate:(NSDate*)toDate;
//跟当前时间相隔多久
- (NSInteger)calculateDateIntervalFromCurDate:(NSDate*)toDate;

@end
