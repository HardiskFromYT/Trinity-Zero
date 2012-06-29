ALTER TABLE `quest_template` DROP COLUMN `RewardArenaPoints`;
ALTER TABLE `access_requirement` DROP COLUMN `completed_achievement`;
DROP TABLE IF EXISTS `player_factionchange_achievement`;
DROP TABLE IF EXISTS `player_factionchange_items`;
DROP TABLE IF EXISTS `player_factionchange_reputations`;
DROP TABLE IF EXISTS `player_factionchange_spells`;
