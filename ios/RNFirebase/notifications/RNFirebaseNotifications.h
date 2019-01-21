#ifndef RNFirebaseNotifications_h
#define RNFirebaseNotifications_h
#import <Foundation/Foundation.h>

#if __has_include(<FirebaseMessaging/FirebaseMessaging.h>)
#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>
#import <UserNotifications/UserNotifications.h>

@interface RNFirebaseNotifications : RCTEventEmitter<RCTBridgeModule>

+ (void)configure;
+ (_Nonnull instancetype)instance;



#if !TARGET_OS_TV

- (void)userNotificationCenter:(UNUserNotificationCenter *)center
       willPresentNotification:(UNNotification *)notification
         withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler;

- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void(^)(void))completionHandler;


- (void)didReceiveLocalNotification:(nonnull UILocalNotification *)notification;

- (void)didReceiveRemoteNotification:(NSDictionary *)userInfo
              fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;


#endif

@end

#else
@interface RNFirebaseNotifications : NSObject
@end
#endif

#endif

