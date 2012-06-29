/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DEF_ONYXIAS_LAIR_H
#define DEF_ONYXIAS_LAIR_H

enum Data64
{
    DATA_ONYXIA_GUID,
    DATA_FLOOR_ERUPTION_GUID
};

enum InstanceData
{
    DATA_ONYXIA,
    MAX_ENCOUNTER,

    DATA_ONYXIA_PHASE,
    DATA_SHE_DEEP_BREATH_MORE,
    DATA_MANY_WHELPS_COUNT
};

enum Creatures
{
    NPC_WHELP                   = 11262,
    NPC_LAIRGUARD               = 36561,

    NPC_ONYXIA                  = 10184
};

enum OnyxiaPhases
{
    PHASE_START                 = 1,
    PHASE_BREATH                = 2,
    PHASE_END                   = 3
};

enum GameObjects
{
    GO_WHELP_SPAWNER            = 176510,
    GO_WHELP_EGG                = 176511
};

#endif
