//
//  IDMPhoto.h
//  IDMPhotoBrowser
//
//  Created by Michael Waterfall on 17/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDMPhotoProtocol.h"
#import <SDWebImage/SDWebImageManager.h>

// This class models a photo/image and it's caption
// If you want to handle photos, caching, decompression
// yourself then you can simply ensure your custom data model
// conforms to IDMPhotoProtocol
@interface IDMPhoto : NSObject <IDMPhoto>

// Progress download block, used to update the circularView
typedef void (^IDMProgressUpdateBlock)(CGFloat progress);

// Properties
@property (nonatomic, readonly) MediaType type;
@property (nonatomic, strong) NSString *caption;
@property (nonatomic, strong) NSURL *photoURL;
@property (nonatomic, strong) NSURL *videoURL;
@property (nonatomic, strong) UIImage *videoThumbnail;
@property (nonatomic, strong) NSURL *videoThumbnailURL;
@property (nonatomic, strong) IDMProgressUpdateBlock progressUpdateBlock;
@property (nonatomic, strong) UIImage *placeholderImage;
@property (nonatomic, strong) UIImage *failureIcon;

// Class
+ (IDMPhoto *)photoWithImage:(UIImage *)image;
+ (IDMPhoto *)photoWithFilePath:(NSString *)path;
+ (IDMPhoto *)photoWithURL:(NSURL *)url;

+ (NSArray *)photosWithImages:(NSArray *)imagesArray;
+ (NSArray *)photosWithFilePaths:(NSArray *)pathsArray;
+ (NSArray *)photosWithURLs:(NSArray *)urlsArray;

+ (IDMPhoto *)videoWithURL:(NSURL *)url;

+ (NSArray *)videosWithURLs:(NSArray *)urlsArray;

// Init
- (id)initWithImage:(UIImage *)image;
- (id)initWithFilePath:(NSString *)path;
- (id)initWithURL:(NSURL *)url;

- (id)initWithVideoURL:(NSURL *)videoURL;

@end

