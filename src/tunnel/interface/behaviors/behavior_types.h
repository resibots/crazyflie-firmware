#ifndef __BEHAVIORS_H
#define __BEHAVIORS_H

#include "behavior_idle.h"

const BehaviorType behavior_idle = {
.id = TUNNEL_BEHAVIOR_IDLE,
.init = behaviorIdleInit,
.update = behaviorIdleUpdate,
};

#include "behavior_vertical.h"

const BehaviorType behavior_takeoff = {
.id = TUNNEL_BEHAVIOR_TAKE_OFF,
.init = behaviorTakeOffInit,
.update = behaviorTakeOffUpdate,
};

const BehaviorType behavior_land = {
.id = TUNNEL_BEHAVIOR_LAND,
.init = behaviorLandInit,
.update = behaviorLandUpdate,
};

#include "behavior_hover.h"

const BehaviorType behavior_hover = {
.id = TUNNEL_BEHAVIOR_HOVER,
.init = behaviorHoverInit,
.update = behaviorHoverUpdate,
};

#include "behavior_goto.h"

const BehaviorType behavior_goto = {
.id = TUNNEL_BEHAVIOR_GOTO,
.init = behaviorGotoInit,
.update = behaviorGotoUpdate,
};

#include "behavior_positioning.h"

const BehaviorType behavior_positioning = {
.id = TUNNEL_BEHAVIOR_POSITIONING,
.init = behaviorPositioningInit,
.update = behaviorPositioningUpdate,
};

#include "behavior_reconnect.h"

const BehaviorType behavior_reconnect = {
.id = TUNNEL_BEHAVIOR_RECONNECT,
.init = behaviorReconnectInit,
.update = behaviorReconnectUpdate,
};

#include "behavior_rollback.h"

const BehaviorType behavior_rollback = {
.id = TUNNEL_BEHAVIOR_ROLLBACK,
.init = behaviorRollbackInit,
.update = behaviorRollbackUpdate,
};

#include "behavior_scan.h"

const BehaviorType behavior_scan = {
.id = TUNNEL_BEHAVIOR_SCAN,
.init = behaviorScanInit,
.update = behaviorScanUpdate,
};

#endif