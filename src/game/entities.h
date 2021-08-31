////////////////////////////////////////////////////////////////////////////////////
// The MIT License (MIT)
// 
// Copyright (c) 2021 Tarek Sherif
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
////////////////////////////////////////////////////////////////////////////////////

#ifndef _GAME_ENTITIES_H_
#define _GAME_ENTITIES_H_
#include "renderer.h"

typedef struct {
    MIXIN_STRUCT(Renderer_RenderList, renderList);
    float velocity[RENDERER_DRAWLIST_MAX * 2];
    uint8_t currentAnimation[RENDERER_DRAWLIST_MAX];
    uint8_t animationTick[RENDERER_DRAWLIST_MAX];
    uint8_t health[RENDERER_DRAWLIST_MAX];
} EntitiesList;

typedef struct {
    float x;
    float y;
    float vx;
    float vy;
    uint8_t currentAnimation;
    uint8_t health;
    float scale;
    float transparency;
} EntitiesInitOptions;

typedef struct {
    float x;
    float y;
    float scale;
    float transparency;
    bool reset;
} EntitiesFromTextOptions;

extern void entities_updateAnimationPanel(EntitiesList* list, uint8_t i);
extern void entities_setAnimation(EntitiesList* list, uint8_t i, uint8_t animation);
extern void entities_updateAnimations(EntitiesList* list);
extern void entities_spawn(EntitiesList* list, EntitiesInitOptions* opts);
extern void entities_init(EntitiesList* list, uint8_t i, EntitiesInitOptions* opts);
extern void entities_kill(EntitiesList* list, uint8_t i);
extern void entities_fromText(EntitiesList* list, const char* text, EntitiesFromTextOptions* opts);

#endif