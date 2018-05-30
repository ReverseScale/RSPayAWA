# RSPayAWA

![](https://img.shields.io/badge/platform-iOS-red.svg) 
![](https://img.shields.io/badge/language-Objective--C-orange.svg) 
![](https://img.shields.io/badge/download-34.9MB-brightgreen.svg) 
![](https://img.shields.io/badge/license-MIT%20License-brightgreen.svg) 
[![Build Status](https://travis-ci.org/ReverseScale/RSPayAWA.svg?branch=master)](https://travis-ci.org/ReverseScale/RSPayAWA)

![image](http://og1yl0w9z.bkt.clouddn.com/17-6-30/21408306.jpg)

[EN](#Requirements) | [中文](#中文说明)

With Mr. Ma's cashless assumption, China has entered a new era of mobile payments. Even Apple in the United States can not afford to launch Apple Pay for a share. As the domestic mainstream payment only requires Alipay and WeChat to be paid, On a separate package of Apple Pay.

#### My Tech Blog: https://reversescale.github.io Welcome to step on

## 🎨 Why test the UI?

| 1 list page | 2 Alipay payment | 3 WeChat payment |
| ------------- | ------------- | ------------- |
| ![](http://og1yl0w9z.bkt.clouddn.com/17-7-6/6294420.jpg) | ![](http://og1yl0w9z.bkt.clouddn.com/17-8-21/82506836.jpg) | ![](http://og1yl0w9z.bkt.clouddn.com/17-8-21/77699782.jpg) |
| Set up a basic framework through the storyboard | Alipay page lack of related profiles | WeChat payment page without related profiles |

## 🚀 Advantage 
* 1. Less documents, code concise
* 2. At the same time support the mainstream nowadays payment methods
* 3. Packaging, call simple
* 4. Unified macro management registration, reduce the pressure on the code AppDelegate
* 5. Have a higher custom
* 6. To ensure that no conflict with the code and code pollution
* 7. Based on the official SDK production, safety and risk-free

## 🤖 Requirements
* iOS 7+
* Xcode 8+

## 🛠 Usage method
### The first step is to drag the tools folder into the project file
Folder: RSPayManager
### The second step to configure the environment
Introduced folder RSPayManager will certainly reported a lot of mistakes, do not be afraid, these unobtrusive red will soon disappear.
![image](http://og1yl0w9z.bkt.clouddn.com/17-6-30/32301308.jpg)
Followed by adding the shelf rack, note: WeChat, Alipay two rack package in the previous step has quietly entered.
![image](http://og1yl0w9z.bkt.clouddn.com/17-6-30/39436315.jpg)
Pay attention to the WeChat shelves relatively stubborn, so special treatment, otherwise there will be a chance when registering Crash ...
![image](http://og1yl0w9z.bkt.clouddn.com/17-6-30/6112277.jpg)
Fill out according to the project directory: my "$ (SRCROOT) /RSPayAWA/RSPayManager/WeChatPayLib/libWeChatSDK.a"
~ OK, the compiler should not be an error now.
### The third step is to set the parameters
In AppDelegate, do the following (remember to import the header file: #import "RSPayManager.h"):
```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
// Override point for customization after application launch.

[RSPAYMANAGER rs_registerApp];

return YES;
}
/**
*  @author DevelopmentEngineer-DWQ
*
*  The oldest version, it is best to write
*/
- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url {

return [RSPAYMANAGER rs_handleUrl:url];
}
/**
*  @author DevelopmentEngineer-DWQ
*
*  Will be called before iOS 9.0
*/
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {

return [RSPAYMANAGER rs_handleUrl:url];
}
/**
*  @author DevelopmentEngineer-DWQ
*
*  iOS 9.0 or above (including iOS9.0)
*/

- (BOOL)application:(UIApplication *)application openURL:(nonnull NSURL *)url options:(nonnull NSDictionary<NSString *,id> *)options{

return [RSPAYMANAGER rs_handleUrl:url];
}
```
Is not very concise, compared to the official document simply to be happy to God, the latter can help AppDelegate slimming through the Method Swizzing way.

### The fourth step to use
```
// Apple Pay 头文件
#import "RSApplePay.h"
// 微信支付、支付宝头文件
#import "RSPayManager.h"
```
1.Alipay
```
NSString *orderMessage = @"app_id=2015052600090779&biz_content=%7B%22timeout_express%22%3A%2230m%22%2C%22seller_id%22%3A%22%22%2C%22product_code%22%3A%22QUICK_MSECURITY_PAY%22%2C%22total_amount%22%3A%220.02%22%2C%22subject%22%3A%221%22%2C%22body%22%3A%22%E6%88%91%E6%98%AF%E6%B5%8B%E8%AF%95%E6%95%B0%E6%8D%AE%22%2C%22out_trade_no%22%3A%22314VYGIAGG7ZOYY%22%7D&charset=utf-8&method=alipay.trade.app.pay&sign_type=RSA&timestamp=2016-08-15%2012%3A12%3A15&version=1.0&sign=MsbylYkCzlfYLy9PeRwUUIg9nZPeN9SfXPNavUCroGKR5Kqvx0nEnd3eRmKxJuthNUx4ERCXe552EV9PfwexqW%2B1wbKOdYtDIb4%2B7PL3Pc94RZL0zKaWcaY3tSL89%2FuAVUsQuFqEJdhIukuKygrXucvejOUgTCfoUdwTi7z%2BZzQ%3D";
[RSPAYMANAGER rs_payWithOrderMessage:orderMessage callBack:^(RSErrCode errCode, NSString *errStr) {
NSLog(@"errCode = %zd,errStr = %@",errCode,errStr);
}];
```
2.WeiChatPay
```
PayReq* req = [[PayReq alloc] init];
req.partnerId = @"10000100";
req.prepayId= @"1101000000140415649af9fc314aa427";
req.package = @"Sign=WXPay";
req.nonceStr= @"a462b76e7436e98e0ed6e13c64b4fd1c";
req.timeStamp= @"1397527777".intValue;
req.sign= @"582282D72DD2B03AD892830965F428CB16E7A256";

[RSPAYMANAGER rs_payWithOrderMessage:req callBack:^(RSErrCode errCode, NSString *errStr) {
NSLog(@"errCode = %zd,errStr = %@",errCode,errStr);
}];
```

3.Apple Pay (No deliberate package, access it according to demand)

3.1 proxy
```
<RSApplePayDelegate>
```
3.2 Click Action
```
RSApplePay *pay=[[RSApplePay alloc]initWithPayReceiver:@"申冠华" amount:@"5.20" presentVC:self];
[pay setDelegate:self];
```
3.3 Acting callback
```
//payment successful
- (void)RSApplePayDidSuccess{
NSLog(@"payment successful!");
}
//Payment failed
- (void)RSApplePayDidFailure{
NSLog(@"Payment failed!");
}

- (NSString *)generateTradeNO {
static int kNumber = 15;

NSString *sourceStr = @"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
NSMutableString *resultStr = [[NSMutableString alloc] init];
srand((unsigned)time(0));
for (int i = 0; i < kNumber; i++)
{
unsigned index = rand() % [sourceStr length];
NSString *oneStr = [sourceStr substringWithRange:NSMakeRange(index, 1)];
[resultStr appendString:oneStr];
}
return resultStr;
}

```

## ⚖ License

```
MIT License

Copyright (c) 2017 ReverseScale

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## 😬 Contributions

* WeChat : WhatsXie
* Email : ReverseScale@iCloud.com
* Blog : https://reversescale.github.io

---
# 中文说明
随着马云先生的一个无现金设想，中国进入了一个移动支付的新纪元，连美国的Apple也坐不住了，推出 Apple Pay 想分一杯羹，由于国内一般主流支付只需要支付宝和微信支付，所以就单独封装的 Apple Pay。

#### 我的技术博客：https://reversescale.github.io 欢迎来踩

## 🎨 测试 UI 什么样子？
|1.列表页 | 2.支付宝支付 |3.微信支付 |
| ------------- | ------------- | ------------- |
| ![](http://og1yl0w9z.bkt.clouddn.com/17-7-6/6294420.jpg) | ![](http://og1yl0w9z.bkt.clouddn.com/17-8-21/82506836.jpg) | ![](http://og1yl0w9z.bkt.clouddn.com/17-8-21/77699782.jpg) |
| 通过 storyboard 搭建基本框架 | 缺少相关配置文件的支付宝页面 | 缺少相关配置文件的微信支付页面 |

## 🚀 框架的优势
* 1.文件少，代码简洁
* 2.同时支持时下主流支付方式
* 3.封装性强，调用简单
* 4.统一宏管理注册，减少代码AppDelegate压力
* 5.具备较高自定义性
* 6.保证无库包冲突及代码污染
* 7.基于官方SDK制作，安全无风险

## 🤖 要求
* iOS 7+
* Xcode 8+

## 🛠 使用方法
### 第一步 将工具文件夹拖入工程文件
文件夹：RSPayManager 

### 第二步 配置环境
引入文件夹 RSPayManager 后一定会报很多错误，不要怕，这些碍眼的红色很快就会消失。

![image](http://og1yl0w9z.bkt.clouddn.com/17-6-30/32301308.jpg)

依次添加上图架包，注意：微信、支付宝的两个架包在上一步就已经悄悄的进去了。

![image](http://og1yl0w9z.bkt.clouddn.com/17-6-30/39436315.jpg)

注意可能微信的架包比较倔强，所以要特殊处理一下，不然有几率会在注册时Crash...

![image](http://og1yl0w9z.bkt.clouddn.com/17-6-30/6112277.jpg)

根据项目目录填写：如我的 "$(SRCROOT)/RSPayAWA/RSPayManager/WeChatPayLib/libWeChatSDK.a"
~OK，现在编译 应该不会报错了。

### 第三步 设置参数
在 AppDelegate 中进行如下操作（记得引入头文件：#import "RSPayManager.h"）：
```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
// Override point for customization after application launch.

[RSPAYMANAGER rs_registerApp];

return YES;
}
/**
*  @author DevelopmentEngineer-DWQ
*
*  最老的版本，最好也写上
*/
- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url {

return [RSPAYMANAGER rs_handleUrl:url];
}
/**
*  @author DevelopmentEngineer-DWQ
*
*  iOS 9.0 之前 会调用
*/
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {

return [RSPAYMANAGER rs_handleUrl:url];
}
/**
*  @author DevelopmentEngineer-DWQ
*
*  iOS 9.0 以上（包括iOS9.0）
*/

- (BOOL)application:(UIApplication *)application openURL:(nonnull NSURL *)url options:(nonnull NSDictionary<NSString *,id> *)options{

return [RSPAYMANAGER rs_handleUrl:url];
}
```
是不是很简洁，对比官方文档简直要幸福上天，后期可以通过 Method Swizzing 方式帮助 AppDelegate 瘦身哦。

### 第四步 开始使用
```
// Apple Pay 头文件
#import "RSApplePay.h"
// 微信支付、支付宝头文件
#import "RSPayManager.h"
```
1.支付宝
```
NSString *orderMessage = @"app_id=2015052600090779&biz_content=%7B%22timeout_express%22%3A%2230m%22%2C%22seller_id%22%3A%22%22%2C%22product_code%22%3A%22QUICK_MSECURITY_PAY%22%2C%22total_amount%22%3A%220.02%22%2C%22subject%22%3A%221%22%2C%22body%22%3A%22%E6%88%91%E6%98%AF%E6%B5%8B%E8%AF%95%E6%95%B0%E6%8D%AE%22%2C%22out_trade_no%22%3A%22314VYGIAGG7ZOYY%22%7D&charset=utf-8&method=alipay.trade.app.pay&sign_type=RSA&timestamp=2016-08-15%2012%3A12%3A15&version=1.0&sign=MsbylYkCzlfYLy9PeRwUUIg9nZPeN9SfXPNavUCroGKR5Kqvx0nEnd3eRmKxJuthNUx4ERCXe552EV9PfwexqW%2B1wbKOdYtDIb4%2B7PL3Pc94RZL0zKaWcaY3tSL89%2FuAVUsQuFqEJdhIukuKygrXucvejOUgTCfoUdwTi7z%2BZzQ%3D";
[RSPAYMANAGER rs_payWithOrderMessage:orderMessage callBack:^(RSErrCode errCode, NSString *errStr) {
NSLog(@"errCode = %zd,errStr = %@",errCode,errStr);
}];
```
2.微信支付
```
PayReq* req = [[PayReq alloc] init];
req.partnerId = @"10000100";
req.prepayId= @"1101000000140415649af9fc314aa427";
req.package = @"Sign=WXPay";
req.nonceStr= @"a462b76e7436e98e0ed6e13c64b4fd1c";
req.timeStamp= @"1397527777".intValue;
req.sign= @"582282D72DD2B03AD892830965F428CB16E7A256";

[RSPAYMANAGER rs_payWithOrderMessage:req callBack:^(RSErrCode errCode, NSString *errStr) {
NSLog(@"errCode = %zd,errStr = %@",errCode,errStr);
}];
```

3.Apple Pay (没有刻意封装，根据需求接入吧)

3.1 代理
```
<RSApplePayDelegate>
```
3.2 点击方法
```
RSApplePay *pay=[[RSApplePay alloc]initWithPayReceiver:@"申冠华" amount:@"5.20" presentVC:self];
[pay setDelegate:self];
```
3.3 实现代理回调
```
//支付成功
- (void)RSApplePayDidSuccess{
NSLog(@"支付成功!");
}
//支付失败
- (void)RSApplePayDidFailure{
NSLog(@"支付失败!");
}

- (NSString *)generateTradeNO {
static int kNumber = 15;

NSString *sourceStr = @"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
NSMutableString *resultStr = [[NSMutableString alloc] init];
srand((unsigned)time(0));
for (int i = 0; i < kNumber; i++)
{
unsigned index = rand() % [sourceStr length];
NSString *oneStr = [sourceStr substringWithRange:NSMakeRange(index, 1)];
[resultStr appendString:oneStr];
}
return resultStr;
}

```


## ⚖ 协议

```
MIT License

Copyright (c) 2017 ReverseScale

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## 😬  联系

* 微信 : WhatsXie
* 邮件 : ReverseScale@iCloud.com
* 博客 : https://reversescale.github.io

