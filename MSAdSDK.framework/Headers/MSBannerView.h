//
//  MSBannerView.h
//  MSAdSDK
//
//  Created by yang on 2019/8/16.
//  Copyright © 2019 yang. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  广点通推荐尺寸,开发者在嵌入Banner条时，可以手动设置Banner条的宽度用来满足场景需求，
 *  而高度的话广点通侧不建议更改，否则显示效果会有影响
 */
#define GDTMOB_AD_SUGGEST_SIZE_320x50    CGSizeMake(320, 50) //For iPhone
#define GDTMOB_AD_SUGGEST_SIZE_468x60    CGSizeMake(468, 60) //For iPad
#define GDTMOB_AD_SUGGEST_SIZE_728x90    CGSizeMake(728, 90) //For iPad

@class MSBannerView;

@protocol MSBannerViewDelegate <NSObject>

@optional

/**
 *  请求广告条数据成功后调用
 *  详解:当接收服务器返回的广告数据成功后调用该函数
 */
- (void)bannerViewDidReceived DEPRECATED_MSG_ATTRIBUTE("use msBannerLoaded instead");
- (void)msBannerLoaded:(MSBannerView *)msBannerAd;

/**
 *  请求广告条数据失败后调用
 *  详解:当接收服务器返回的广告数据失败后调用该函数
 */
- (void)bannerViewFailToReceived:(NSError *)error DEPRECATED_MSG_ATTRIBUTE("use msBannerError: instead");
- (void)msBannerError:(MSBannerView *)msBannerAd error:(NSError *)error;

/**
 *  banner广告曝光
 */
- (void)bannerViewShow DEPRECATED_MSG_ATTRIBUTE("use msBannerShow instead");
- (void)msBannerShow:(MSBannerView *)msBannerAd;

/**
 *  banner条点击回调
 */
- (void)bannerViewClicked DEPRECATED_MSG_ATTRIBUTE("use msBannerClicked instead");
- (void)msBannerClicked:(MSBannerView *)msBannerAd;

/**
 *  banner条被用户关闭时调用
 *  详解:用户有可能点击关闭按钮从而把广告条关闭
 */
- (void)bannerViewWillClose DEPRECATED_MSG_ATTRIBUTE("use msBannerClosed instead");
- (void)msBannerClosed:(MSBannerView *)msBannerAd;

/**
 *  banner广告点击以后弹出全屏广告页完毕
 */
- (void)bannerViewDidPresentFullScreenModal DEPRECATED_MSG_ATTRIBUTE("use msBannerDetailShow instead");
- (void)msBannerDetailShow:(MSBannerView *)msBannerAd;

/**
 *  全屏广告页已经被关闭
 */
- (void)bannerViewDidDismissFullScreenModal DEPRECATED_MSG_ATTRIBUTE("use msBannerDetailClosed instead");
- (void)msBannerDetailClosed:(MSBannerView *)msBannerAd;
@end

@interface MSBannerView : UIView

/**
 *  委托 [可选]
 */
@property(nonatomic, weak) id<MSBannerViewDelegate> delegate;

/**
 *  广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。 [可选]
 */
@property(nonatomic, assign) int interval;

/**
 *  GPS精准广告定位模式开关,默认Gps关闭
 *  详解：[可选]GPS精准定位模式开关，YES为开启GPS，NO为关闭GPS，建议设为开启，可以获取地理位置信息，提高广告的填充率，增加收益。
 */
@property(nonatomic, assign) BOOL isGpsOn;

/**
 *  Banner展现和轮播时的动画效果开关，默认打开
 */
@property(nonatomic, assign) BOOL isAnimationOn;

/**
 *  Banner条展示关闭按钮，默认打开
 */
@property(nonatomic, assign) BOOL showCloseBtn;

//@property (nonatomic, strong)UIViewController *currentViewController;

/**
 *  构造方法
 *  详解：frame - banner 展示的位置和大小
 */
- (instancetype)initWithFrame:(CGRect)frame curController:(UIViewController*)controller;

/**
 *  拉取并展示广告
 */
- (void)loadAdAndShow:(UIViewController*)currentViewController pid:(NSString *)pid;

@end

NS_ASSUME_NONNULL_END
