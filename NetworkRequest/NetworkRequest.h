//
//  NetworkRequest.h
//  SDK
//
//  Created by ConnorJ on 15/4/1.
//  Copyright (c) 2015年 PutiBaby. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void (^DownloadProgress)(int64_t bytesRead,
                                 int64_t totalBytesRead);

typedef DownloadProgress GetProgress;
typedef DownloadProgress PostProgress;


typedef void (^UploadProgress)(int64_t bytesWritten,
                                  int64_t totalBytesWritten);

typedef NS_ENUM(NSUInteger, ResponseType) {
  kResponseTypeJSON = 1,
  kResponseTypeXML  = 2,
  kResponseTypeData = 3
};

typedef NS_ENUM(NSUInteger, RequestType) {
  kRequestTypeJSON = 1,
  kRequestTypePlainText  = 2
};

@class NSURLSessionTask;


typedef NSURLSessionTask TheURLSessionTask;

typedef void(^ResponseSuccess)(id response);

typedef void(^ResponseFail)(NSError *error);

@interface NetworkRequest : NSObject

+ (void)updateBaseUrl:(NSString *)baseUrl;

+ (NSString *)baseUrl;

+ (void)enableInterfaceDebug:(BOOL)isDebug;

+ (void)configResponseType:(ResponseType)responseType;

+ (void)configRequestType:(RequestType)requestType;

+ (void)shouldAutoEncodeUrl:(BOOL)shouldAutoEncode;

+ (void)configCommonHttpHeaders:(NSDictionary *)httpHeaders;

+ (TheURLSessionTask *)getWithUrl:(NSString *)url
                          success:(ResponseSuccess)success
                             fail:(ResponseFail)fail;

+ (TheURLSessionTask *)getWithUrl:(NSString *)url
                           params:(NSDictionary *)params
                          success:(ResponseSuccess)success
                             fail:(ResponseFail)fail;

+ (TheURLSessionTask *)getWithUrl:(NSString *)url
                           params:(NSDictionary *)params
                         progress:(GetProgress)progress
                          success:(ResponseSuccess)success
                             fail:(ResponseFail)fail;

+ (TheURLSessionTask *)postWithUrl:(NSString *)url
                            params:(NSDictionary *)params
                           success:(ResponseSuccess)success
                              fail:(ResponseFail)fail;

+ (TheURLSessionTask *)postWithUrl:(NSString *)url
                            params:(NSDictionary *)params
                          progress:(PostProgress)progress
                           success:(ResponseSuccess)success
                              fail:(ResponseFail)fail;

+ (TheURLSessionTask *)uploadWithImage:(UIImage *)image
                                   url:(NSString *)url
                              filename:(NSString *)filename
                                  name:(NSString *)name
                              mimeType:(NSString *)mimeType
                            parameters:(NSDictionary *)parameters
                              progress:(UploadProgress)progress
                               success:(ResponseSuccess)success
                                  fail:(ResponseFail)fail;

+ (TheURLSessionTask *)uploadFileWithUrl:(NSString *)url
                           uploadingFile:(NSString *)uploadingFile
                                progress:(UploadProgress)progress
                                 success:(ResponseSuccess)success
                                    fail:(ResponseFail)fail;

+ (TheURLSessionTask *)downloadWithUrl:(NSString *)url
                            saveToPath:(NSString *)saveToPath
                              progress:(DownloadProgress)progressBlock
                               success:(ResponseSuccess)success
                               failure:(ResponseFail)failure;

@end
