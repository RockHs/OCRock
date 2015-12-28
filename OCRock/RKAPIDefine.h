//
//  RKAPIDefine.h
//  OCRock
//
//  Created by rock on 15/12/28.
//  Copyright © 2015年 rock. All rights reserved.
//

#ifndef RKAPIDefine_h
#define RKAPIDefine_h

/*****************************设置网络请求API********************************begin*/
#define API_DEBUG 0
#if API_DEBUG
//正式
//#define API_TODAYTOPIC_DOMAIN_ZHAN              @"http://beikao.api.zhan.com/"
//预发
#define API_TODAYTOPIC_DOMAIN_ZHAN              @"http://kpky.api.zhan.com/"
#else
//测试
#define API_TODAYTOPIC_DOMAIN_ZHAN              @"http://reference.tpooo.net/"
#endif

/*****************************设置网络请求API********************************end*/

#endif /* RKAPIDefine_h */
