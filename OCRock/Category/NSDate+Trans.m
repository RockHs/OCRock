//
//  NSDate+Trans.m
//  OCRock
//
//  Created by mac on 15/12/28.
//  Copyright © 2015年 rock. All rights reserved.
//

#import "NSDate+Trans.h"

@implementation NSDate (Trans)

/*****************************设置NSDate时间处理********************************begin*/
//string转nsdate
- (NSDate*)transToDate:(NSString*)dateStr formatter:(NSString*)formatterStr
{
    NSDateFormatter* formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:formatterStr];
    return [formatter dateFromString:dateStr];
}

//string转nsdate，默认格式”yyyy-MM-dd HH:mm:ss“
- (NSDate*)transToDateDefaultFormatter:(NSString*)dateStr
{
    return [self transToDate:dateStr formatter:@"yyyy-MM-dd HH:mm:ss"];
}

//nsdate转string
- (NSString*)transToString:(NSDate*)date formatter:(NSString*)formatterStr
{
    NSDateFormatter* formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:formatterStr];
    return [formatter stringFromDate:date];
}

//nsdate转string，默认格式”yyyy-MM-dd HH:mm:ss“
- (NSString*)transToStringDefaultFormatter:(NSDate*)date
{
    return [self transToString:date formatter:@"yyyy-MM-dd HH:mm:ss"];
}

//时间戳转换
- (NSString*)transTime:(NSString*)dateStr formatter:(NSString*)formatterStr
{
    NSTimeInterval timeInter = [dateStr doubleValue];
    NSDate* date = [NSDate dateWithTimeIntervalSince1970:timeInter];
    return [self transToString:date formatter:formatterStr];
}

//两个时间相隔多久
- (NSInteger)calculateDateInterval:(NSDate*)fromDate toDate:(NSDate*)toDate
{
    NSDateComponents* components = [[NSCalendar currentCalendar] components:NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay | NSCalendarUnitHour | NSCalendarUnitMinute | NSCalendarUnitSecond fromDate:fromDate toDate:toDate options:NSCalendarWrapComponents];
    NSInteger days = [components day];//获取天数
    NSInteger hours = [components hour];//获取小时
    NSInteger minutes = [components minute];//获取分钟
    NSInteger seconds = [components second];//获取秒数
    if (hours > 0 || minutes > 0 || seconds > 0) {//小时数，分钟，秒不为0，则天数加一
        days = days + 1;
    }
    return days;
}

//跟当前时间相隔多久
- (NSInteger)calculateDateIntervalFromCurDate:(NSDate*)toDate
{
    return [self calculateDateInterval:[NSDate date] toDate:toDate];
}

/*****************************设置NSDate时间处理********************************end*/

@end
