//
//  GameLayer.h
//  GATetris
//
//  Created by Christian Lao on 09/02/13.
//  Copyright 2013 Christian Lao. All rights reserved.
//
//

#define TILE_SIZE 20
#define TILE_COL 10
#define TILE_ROW 20
#define X_ANCHOR_POINT 0.5
#define Y_ANCHOR_POINT 0.5
#define OFFSET CGPointMake(X_ANCHOR_POINT, Y_ANCHOR_POINT)

#import <Foundation/Foundation.h>
#import "cocos2d.h"
#import "GATetris.h"
#import "GAMatrix.h"
#import "GATetrisFactory.h"

enum
{

	kNodeTagBackground,
	kNodeTagTetrisFactory,
	kNodeTagTetris
	
};


@interface GameLayer : CCLayer
{
	GAMatrix			*tileMatrix;
	GATetrisFactory		*tetrisFactory;
	GATetris			*currentTetris;
	CCTexture2D			*texture;
	CCSprite			*background;
	CCSpriteBatchNode	*batchNode;
}

@property (nonatomic, readonly) CCTexture2D *texture;
@property (nonatomic, readonly) GAMatrix *tileMatrix;
@property (nonatomic, readonly) GATetris *tetris;

#pragma mark - Init & Factory methods

+(id)scene;
+(GameLayer *)sharedGamelayer;

#pragma mark - Gameplay methods


-(void)moveTetrisAllDown;
-(BOOL)moveDownTetris;
-(void)moveTetris:(EnumMoveDirections)move;
-(void)rotateTetris:(EnumRotateDirections)rotate;

-(void)dropTetris;

-(void)shiftDownMatrixRows:(NSMutableArray **)rowSet;
-(void)collapseDownTilesInRows:(NSMutableArray *)rowSet;
-(NSMutableArray *)killCurrentTetris;
-(void)checkRowsForDeletion:(NSMutableArray **)rowSet;
-(void)deleteRows:(NSMutableArray *)rowSet;

#pragma mark - Utility methods

-(CGPoint)convertIndexToPosition:(CGPoint)index;
-(CGPoint)convertPositionToIndex:(CGPoint)matrixPosition;
-(CGPoint)tetrisPositionInWorld;

@end
