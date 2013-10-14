//
//  FICImageTableChunk.h
//  FastImageCache
//
//  Copyright (c) 2013 Path, Inc.
//  See LICENSE for full license agreement.
//

#import "FICImports.h"

@class FICImageTable;

/**
 `FICImageTableChunk` represents a contiguous portion of image table file data.
 */
@interface FICImageTableChunk : NSObject

///-----------------------------------
/// @name Image Table Chunk Properties
///-----------------------------------

/**
 The bytes of file data contained in the chunk.
 
 @discussion `FICImageTableChunk` maps file data directly to `bytes`, so no memory copy occurs.
 */
@property (nonatomic, assign, readonly) void *bytes;

/**
 The index of the chunk in the image table file.
 */
@property (nonatomic, assign, readonly) NSInteger index;

/**
 The offset in the image table file where the chunk begins.
 */
@property (nonatomic, assign, readonly) off_t fileOffset;

///----------------------------------------
/// @name Initializing an Image Table Chunk
///----------------------------------------

/**
 Initializes a new image table chunk.
 
 @param imageTable The image table to create a chunk from.

 @param fileDescriptor The image table's file descriptor to map from.
 
 @param index The index of the chunk.
 
 @param length The length, in bytes, of the chunk.
 
 @return A new image table chunk.
 */
- (instancetype)initWithImageTable:(FICImageTable *)imageTable fileDescriptor:(int)fileDescriptor index:(NSInteger)index length:(size_t)length;

@end