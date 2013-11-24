/**
 * The Forgotten Server - a server application for the MMORPG Tibia
 * Copyright (C) 2013  Mark Samman <mark.samman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _CONFIG_MANAGER_H
#define _CONFIG_MANAGER_H

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

class ConfigManager
{
	public:
		ConfigManager();
		~ConfigManager();

		enum boolean_config_t {
			ALLOW_CHANGEOUTFIT = 0,
			CANNOT_ATTACK_SAME_LOOKFEET = 1,
			ONE_PLAYER_ON_ACCOUNT = 2,
			AIMBOT_HOTKEY_ENABLED = 3,
			REMOVE_AMMO = 4,
			REMOVE_RUNE_CHARGES = 5,
			EXPERIENCE_FROM_PLAYERS = 6,
			FREE_PREMIUM = 7,
			ADMIN_LOGS_ENABLED = 8,
			REPLACE_KICK_ON_LOGIN = 9,
			ALLOW_CLONES = 10,
			BIND_ONLY_GLOBAL_ADDRESS = 11,
			OPTIMIZE_DATABASE = 12,
			MARKET_PREMIUM = 13,
			STAMINA_SYSTEM = 14,
			LAST_BOOLEAN_CONFIG /* this must be the last one */
		};

		enum string_config_t {
			DUMMY_STR = 0,
			MAP_NAME = 1,
			HOUSE_RENT_PERIOD = 2,
			SERVER_NAME = 3,
			OWNER_NAME = 4,
			OWNER_EMAIL = 5,
			URL = 6,
			LOCATION = 7,
			IP = 8,
			MOTD = 9,
			WORLD_TYPE = 10,
			MYSQL_HOST = 11,
			MYSQL_USER = 12,
			MYSQL_PASS = 13,
			MYSQL_DB = 14,
			DEFAULT_PRIORITY = 15,
			MAP_AUTHOR = 16,
			LAST_STRING_CONFIG /* this must be the last one */
		};

		enum integer_config_t {
			SQL_PORT = 0,
			MAX_PLAYERS = 1,
			PZ_LOCKED = 2,
			DEFAULT_DESPAWNRANGE = 3,
			DEFAULT_DESPAWNRADIUS = 4,
			RATE_EXPERIENCE = 5,
			RATE_SKILL = 6,
			RATE_LOOT = 7,
			RATE_MAGIC = 8,
			RATE_SPAWN = 9,
			HOUSE_PRICE = 10,
			KILLS_TO_RED = 11,
			KILLS_TO_BLACK = 12,
			MAX_MESSAGEBUFFER = 13,
			ACTIONS_DELAY_INTERVAL = 14,
			EX_ACTIONS_DELAY_INTERVAL = 15,
			KICK_AFTER_MINUTES = 16,
			PROTECTION_LEVEL = 17,
			DEATH_LOSE_PERCENT = 18,
			STATUSQUERY_TIMEOUT = 19,
			FRAG_TIME = 20,
			WHITE_SKULL_TIME = 21,
			ADMIN_PORT = 22,
			GAME_PORT = 23,
			LOGIN_PORT = 24,
			STATUS_PORT = 25,
			STAIRHOP_DELAY = 26,
			MARKET_OFFER_DURATION = 27,
			CHECK_EXPIRED_MARKET_OFFERS_EACH_MINUTES = 28,
			MAX_MARKET_OFFERS_AT_A_TIME_PER_PLAYER = 29,
			EXP_FROM_PLAYERS_LEVEL_RANGE = 30,
			MAX_PACKETS_PER_SECOND = 31,
			LAST_INTEGER_CONFIG /* this must be the last one */
		};

		bool load();
		bool reload();

		const std::string& getString(string_config_t _what) const;
		int32_t getNumber(integer_config_t _what) const;
		bool getBoolean(boolean_config_t _what) const;

	private:
		static std::string getGlobalString(lua_State* _L, const std::string& _identifier, const std::string& _default = "");
		static int32_t getGlobalNumber(lua_State* _L, const std::string& _identifier, const int32_t _default = 0);
		static std::string getGlobalStringField(lua_State* _L, const std::string& _identifier, const int32_t _key, const std::string& _default = "");

		bool m_isLoaded;
		std::string m_confString[LAST_STRING_CONFIG];
		int32_t m_confInteger[LAST_INTEGER_CONFIG];
		bool m_confBoolean[LAST_BOOLEAN_CONFIG];
};

#endif
