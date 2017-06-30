//
//  RSApplePay.h
//  RSPayAWA
//
//  Created by WhatsXie on 2017/6/30.
//  Copyright © 2017年 StevenXie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import<PassKit/PassKit.h>

@protocol RSApplePayDelegate <NSObject>

/**
 *  支付成功
 */
- (void)RSApplePayDidSuccess;

/**
 *  支付失败
 */
- (void)RSApplePayDidFailure;

@end

@interface RSApplePay : NSObject<PKPaymentAuthorizationViewControllerDelegate>

@property (nonatomic,assign) id<RSApplePayDelegate>delegate;

/**
 *  初始化init  创建
 *
 *  @param payReceiver 收款方
 *  @param amount      金额
 *
 *  @return self
 */
- (instancetype)initWithPayReceiver:(NSString *)payReceiver amount:(NSString *)amount presentVC:(UIViewController *)vc;

@end
