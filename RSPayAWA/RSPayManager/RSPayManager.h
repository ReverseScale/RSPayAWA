//
//  RSPayManager.h
//  RSPayAWA
//
//  Created by WhatsXie on 2017/6/30.
//  Copyright © 2017年 StevenXie. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "WXApi.h"
#import <AlipaySDK/AlipaySDK.h>

/**
 *  @author DevelopmentEngineer
 *
 *  此处必须保证在Info.plist 中的 URL Types 的 Identifier 对应一致
 */
#define RSWECHATURLNAME @"weixin"
#define RSALIPAYURLNAME @"zhifubao"

/**
 *  [RSPayManager shareManager]
 *
 *  单例方法
 */
#define RSPAYMANAGER [RSPayManager shareManager]

/**
 *  @author DevelopmentEngineer
 *
 *  回调状态码
 */
typedef NS_ENUM(NSInteger,RSErrCode){
    RSErrCodeSuccess,// 成功
    RSErrCodeFailure,// 失败
    RSErrCodeCancel  // 取消
};

typedef void(^RSCompleteCallBack)(RSErrCode errCode,NSString *errStr);


@interface RSPayManager : NSObject


/**
 *  @author DevelopmentEngineer
 *
 *  单例管理
 */
+ (instancetype)shareManager;



/**
 *  @author DevelopmentEngineer
 *
 *  处理跳转url，回到应用，需要在delegate中实现
 */
- (BOOL)rs_handleUrl:(NSURL *)url;



/**
 *  @author DevelopmentEngineer
 *
 *  注册App，需要在 didFinishLaunchingWithOptions 中调用
 */
- (void)rs_registerApp;



/**
 *  @author DevelopmentEngineer
 *
 *  发起支付
 *
 * @param orderMessage 传入订单信息,如果是字符串，则对应是跳转支付宝支付；如果传入PayReq 对象，这跳转微信支付,注意，不能传入空字符串或者nil
 * @param callBack     回调，有返回状态信息
 */
- (void)rs_payWithOrderMessage:(id)orderMessage callBack:(RSCompleteCallBack)callBack;



@end
