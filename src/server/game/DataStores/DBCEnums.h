/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef DBCENUMS_H
#define DBCENUMS_H

// Client expected level limitation, like as used in DBC item max levels for "until max player level"
// use as default max player level, must be fit max level for used client
// also see MAX_LEVEL and STRONG_MAX_LEVEL define
#define DEFAULT_MAX_LEVEL 80

// client supported max level for player/pets/etc. Avoid overflow or client stability affected.
// also see GT_MAX_LEVEL define
#define MAX_LEVEL    100

// Server side limitation. Base at used code requirements.
// also see MAX_LEVEL and GT_MAX_LEVEL define
#define STRONG_MAX_LEVEL 255

enum BattlegroundBracketId                                  // bracketId for level ranges
{
    BG_BRACKET_ID_FIRST          = 0,
    BG_BRACKET_ID_LAST           = 15
};

// must be max value in PvPDificulty slot+1
#define MAX_BATTLEGROUND_BRACKETS  16

enum AreaTeams
{
    AREATEAM_NONE  = 0,
    AREATEAM_ALLY  = 2,
    AREATEAM_HORDE = 4,
    AREATEAM_ANY   = 6
};

enum AreaFlags
{
    AREA_FLAG_UNK0             = 0x00000001,                // Unknown
    AREA_FLAG_UNK1             = 0x00000002,                // Razorfen Downs, Naxxramas and Acherus: The Ebon Hold (3.3.5a)
    AREA_FLAG_UNK2             = 0x00000004,                // Only used for areas on map 571 (development before)
    AREA_FLAG_SLAVE_CAPITAL    = 0x00000008,                // city and city subsones
    AREA_FLAG_UNK3             = 0x00000010,                // can't find common meaning
    AREA_FLAG_SLAVE_CAPITAL2   = 0x00000020,                // slave capital city flag?
    AREA_FLAG_ALLOW_DUELS      = 0x00000040,                // allow to duel here
    AREA_FLAG_ARENA            = 0x00000080,                // FFA arenas
    AREA_FLAG_CAPITAL          = 0x00000100,                // main capital city flag
    AREA_FLAG_CITY             = 0x00000200,                // only for one zone named "City" (where it located?)
    AREA_FLAG_OUTLAND          = 0x00000400,                // expansion zones? (only Eye of the Storm not have this flag, but have 0x00004000 flag)
    AREA_FLAG_SANCTUARY        = 0x00000800,                // sanctuary area (PvP disabled)
    AREA_FLAG_NEED_FLY         = 0x00001000,                // Respawn alive at the graveyard without corpse
    AREA_FLAG_UNUSED1          = 0x00002000,                // Unused in 3.3.5a
    AREA_FLAG_UNUSED2          = 0x00020000,                // Unused in 3.3.5a
    AREA_FLAG_CONTESTED_AREA   = 0x00040000,                // On PvP servers these areas are considered contested, even though the zone it is contained in is a Horde/Alliance territory.
    AREA_FLAG_UNK6             = 0x00080000,                // Valgarde and Acherus: The Ebon Hold
    AREA_FLAG_LOWLEVEL         = 0x00100000,                // used for some starting areas with area_level <= 15
    AREA_FLAG_TOWN             = 0x00200000,                // small towns with Inn
    AREA_FLAG_UNK7             = 0x00400000,                // Warsong Hold, Acherus: The Ebon Hold, New Agamand Inn, Vengeance Landing Inn, Sunreaver Pavilion (Something to do with team?)
    AREA_FLAG_UNK8             = 0x00800000,                // Valgarde, Acherus: The Ebon Hold, Westguard Inn, Silver Covenant Pavilion (Something to do with team?)
    AREA_FLAG_INSIDE           = 0x02000000,                // used for determinating spell related inside/outside questions in Map::IsOutdoors
    AREA_FLAG_OUTSIDE          = 0x04000000,                // used for determinating spell related inside/outside questions in Map::IsOutdoors
};

enum Difficulty
{
    REGULAR_DIFFICULTY           = 0,

    DUNGEON_DIFFICULTY_NORMAL    = 0,
    DUNGEON_DIFFICULTY_HEROIC    = 1,
    DUNGEON_DIFFICULTY_EPIC      = 2,

    RAID_DIFFICULTY_10MAN_NORMAL = 0,
    RAID_DIFFICULTY_25MAN_NORMAL = 1,
    RAID_DIFFICULTY_10MAN_HEROIC = 2,
    RAID_DIFFICULTY_25MAN_HEROIC = 3,
};

#define RAID_DIFFICULTY_MASK_25MAN 1    // since 25man difficulties are 1 and 3, we can check them like that

#define MAX_DUNGEON_DIFFICULTY     3
#define MAX_RAID_DIFFICULTY        4
#define MAX_DIFFICULTY             4

enum SpawnMask
{
    SPAWNMASK_CONTINENT         = (1 << REGULAR_DIFFICULTY), // any any maps without spawn modes

    SPAWNMASK_DUNGEON_NORMAL    = (1 << DUNGEON_DIFFICULTY_NORMAL),
    SPAWNMASK_DUNGEON_HEROIC    = (1 << DUNGEON_DIFFICULTY_HEROIC),
    SPAWNMASK_DUNGEON_ALL       = (SPAWNMASK_DUNGEON_NORMAL | SPAWNMASK_DUNGEON_HEROIC),

    SPAWNMASK_RAID_10MAN_NORMAL = (1 << RAID_DIFFICULTY_10MAN_NORMAL),
    SPAWNMASK_RAID_25MAN_NORMAL = (1 << RAID_DIFFICULTY_25MAN_NORMAL),
    SPAWNMASK_RAID_NORMAL_ALL   = (SPAWNMASK_RAID_10MAN_NORMAL | SPAWNMASK_RAID_25MAN_NORMAL),

    SPAWNMASK_RAID_10MAN_HEROIC = (1 << RAID_DIFFICULTY_10MAN_HEROIC),
    SPAWNMASK_RAID_25MAN_HEROIC = (1 << RAID_DIFFICULTY_25MAN_HEROIC),
    SPAWNMASK_RAID_HEROIC_ALL   = (SPAWNMASK_RAID_10MAN_HEROIC | SPAWNMASK_RAID_25MAN_HEROIC),

    SPAWNMASK_RAID_ALL          = (SPAWNMASK_RAID_NORMAL_ALL | SPAWNMASK_RAID_HEROIC_ALL),
};

enum FactionTemplateFlags
{
    FACTION_TEMPLATE_FLAG_PVP               = 0x00000800,   // flagged for PvP
    FACTION_TEMPLATE_FLAG_CONTESTED_GUARD   = 0x00001000,   // faction will attack players that were involved in PvP combats
    FACTION_TEMPLATE_FLAG_HOSTILE_BY_DEFAULT= 0x00002000,
};

enum FactionMasks
{
    FACTION_MASK_PLAYER   = 1,                              // any player
    FACTION_MASK_ALLIANCE = 2,                              // player or creature from alliance team
    FACTION_MASK_HORDE    = 4,                              // player or creature from horde team
    FACTION_MASK_MONSTER  = 8                               // aggressive creature from monster team
    // if none flags set then non-aggressive creature
};

enum MapTypes                                               // Lua_IsInInstance
{
    MAP_COMMON          = 0,                                // none
    MAP_INSTANCE        = 1,                                // party
    MAP_RAID            = 2,                                // raid
    MAP_BATTLEGROUND    = 3,                                // pvp
};

enum AbilytyLearnType
{
    ABILITY_LEARNED_ON_GET_PROFESSION_SKILL     = 1,
    ABILITY_LEARNED_ON_GET_RACE_OR_CLASS_SKILL  = 2
};

enum ItemEnchantmentType
{
    ITEM_ENCHANTMENT_TYPE_NONE             = 0,
    ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL     = 1,
    ITEM_ENCHANTMENT_TYPE_DAMAGE           = 2,
    ITEM_ENCHANTMENT_TYPE_EQUIP_SPELL      = 3,
    ITEM_ENCHANTMENT_TYPE_RESISTANCE       = 4,
    ITEM_ENCHANTMENT_TYPE_STAT             = 5,
    ITEM_ENCHANTMENT_TYPE_TOTEM            = 6,
    ITEM_ENCHANTMENT_TYPE_USE_SPELL        = 7,
    ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET = 8
};

enum ItemLimitCategoryMode
{
    ITEM_LIMIT_CATEGORY_MODE_HAVE  = 0,                      // limit applied to amount items in inventory/bank
    ITEM_LIMIT_CATEGORY_MODE_EQUIP = 1,                      // limit applied to amount equipped items (including used gems)
};

enum TotemCategoryType
{
    TOTEM_CATEGORY_TYPE_KNIFE   = 1,
    TOTEM_CATEGORY_TYPE_TOTEM   = 2,
    TOTEM_CATEGORY_TYPE_ROD     = 3,
    TOTEM_CATEGORY_TYPE_PICK    = 21,
    TOTEM_CATEGORY_TYPE_STONE   = 22,
    TOTEM_CATEGORY_TYPE_HAMMER  = 23,
    TOTEM_CATEGORY_TYPE_SPANNER = 24
};

//! TrinityZero note: we can nuke all these, according to comments they're all from WOTLK.

// SummonProperties.dbc, col 1
enum SummonPropGroup
{
    SUMMON_PROP_GROUP_UNKNOWN1       = 0,                   // 1160 spells in 3.0.3
    SUMMON_PROP_GROUP_UNKNOWN2       = 1,                   // 861 spells in 3.0.3
    SUMMON_PROP_GROUP_PETS           = 2,                   // 52 spells in 3.0.3, pets mostly
    SUMMON_PROP_GROUP_CONTROLLABLE   = 3,                   // 13 spells in 3.0.3, mostly controllable
    SUMMON_PROP_GROUP_UNKNOWN3       = 4                    // 86 spells in 3.0.3, taxi/mounts
};

// SummonProperties.dbc, col 3
enum SummonPropType
{
    SUMMON_PROP_TYPE_UNKNOWN         = 0,                   // different summons, 1330 spells in 3.0.3
    SUMMON_PROP_TYPE_SUMMON          = 1,                   // generic summons, 49 spells in 3.0.3
    SUMMON_PROP_TYPE_GUARDIAN        = 2,                   // summon guardian, 393 spells in 3.0.3
    SUMMON_PROP_TYPE_ARMY            = 3,                   // summon army, 5 spells in 3.0.3
    SUMMON_PROP_TYPE_TOTEM           = 4,                   // summon totem, 169 spells in 3.0.3
    SUMMON_PROP_TYPE_CRITTER         = 5,                   // critter/minipet, 195 spells in 3.0.3
    SUMMON_PROP_TYPE_DK              = 6,                   // summon DRW/Ghoul, 2 spells in 3.0.3
    SUMMON_PROP_TYPE_BOMB            = 7,                   // summon bot/bomb, 4 spells in 3.0.3
    SUMMON_PROP_TYPE_LIGHTWELL       = 11,                  // summon lightwell, 6 spells in 3.0.3
    SUMMON_PROP_TYPE_JEEVES          = 12                   // summon Jeeves, 1 spell in 3.3.5a
};

// SummonProperties.dbc, col 5
enum SummonPropFlags
{
    SUMMON_PROP_FLAG_NONE            = 0x00000000,          // 1342 spells in 3.0.3
    SUMMON_PROP_FLAG_UNK1            = 0x00000001,          // 75 spells in 3.0.3, something unfriendly
    SUMMON_PROP_FLAG_UNK2            = 0x00000002,          // 616 spells in 3.0.3, something friendly
    SUMMON_PROP_FLAG_UNK3            = 0x00000004,          // 22 spells in 3.0.3, no idea...
    SUMMON_PROP_FLAG_UNK4            = 0x00000008,          // 49 spells in 3.0.3, some mounts
    SUMMON_PROP_FLAG_UNK5            = 0x00000010,          // 25 spells in 3.0.3, quest related?
    SUMMON_PROP_FLAG_UNK6            = 0x00000020,          // 0 spells in 3.3.5, unused
    SUMMON_PROP_FLAG_UNK7            = 0x00000040,          // 12 spells in 3.0.3, no idea
    SUMMON_PROP_FLAG_UNK8            = 0x00000080,          // 4 spells in 3.0.3, no idea
    SUMMON_PROP_FLAG_UNK9            = 0x00000100,          // 51 spells in 3.0.3, no idea, many quest related
    SUMMON_PROP_FLAG_UNK10           = 0x00000200,          // 51 spells in 3.0.3, something defensive
    SUMMON_PROP_FLAG_UNK11           = 0x00000400,          // 3 spells, requires something near?
    SUMMON_PROP_FLAG_UNK12           = 0x00000800,          // 30 spells in 3.0.3, no idea
    SUMMON_PROP_FLAG_UNK13           = 0x00001000,          // Lightwell, Jeeves, Gnomish Alarm-o-bot, Build vehicles(wintergrasp)
    SUMMON_PROP_FLAG_UNK14           = 0x00002000,          // Guides, player follows
    SUMMON_PROP_FLAG_UNK15           = 0x00004000,          // Force of Nature, Shadowfiend, Feral Spirit, Summon Water Elemental
    SUMMON_PROP_FLAG_UNK16           = 0x00008000,          // Light/Dark Bullet, Soul/Fiery Consumption, Twisted Visage, Twilight Whelp. Phase related?
};

#endif
