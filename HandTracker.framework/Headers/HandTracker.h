#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>
// version = 1.0.0
@class Landmark;
@class HandTracker;

@protocol TrackerDelegate <NSObject>
- (void)handTracker: (HandTracker*)handTracker didOutputLandmarks: (NSDictionary *)landmarks;
- (void)handTracker: (HandTracker*)handTracker didOutputPixelBuffer: (CVPixelBufferRef)pixelBuffer;
@end

@interface HandTracker : NSObject
@property (weak, nonatomic) id <TrackerDelegate> delegate;
- (instancetype)init;
- (void)startGraph;
- (void)processVideoFrame:(CVPixelBufferRef)imageBuffer;
- (void)setW:(int)w H:(int)h;
- (void)setDebug:(BOOL)isDebug;
- (NSString*)version;
- (NSString*)updateTime;
@end

@interface Landmark: NSObject
@property(nonatomic, readonly) float x;
@property(nonatomic, readonly) float y;
@property(nonatomic, readonly) float z;
@end
