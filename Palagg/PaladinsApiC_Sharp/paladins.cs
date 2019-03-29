using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.IO;
using System.Runtime.CompilerServices;
using System.Security.Cryptography.X509Certificates;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace PaladinsApiC_Sharp
{
    public partial class PaladinsApi
    {
        public enum LanguageCode
        {
            English = 1,
            German = 2,
            French = 3,
            Chinese = 5,
            Spanish = 7,
            Portuguese = 10,
            Russian = 11,
            Polish = 12,
            Turkish = 13
        }
        public class Champion
        {
            public enum ID
            {
                Androxus = 2205,
                Ash = 2404,
                Barik = 2073,
                Bomb_King = 2281,
                Buck = 2147,
                Cassie = 2092,
                Drogoz = 2277,
                Evie = 2094,
                Fernando = 2071,
                Furia = 2491,
                Grohk = 2093,
                Grover = 2254,
                Inara = 2348,
                Jenos = 2431,
                Khan = 2479,
                Kinessa = 2249,
                Lex = 2362,
                Lian = 2417,
                Maeve = 2338,
                Makoa = 2288,
                Mal_Damba = 2303,
                Moji = 2481,
                Pip = 2056,
                Ruckus = 2149,
                Seris = 2372,
                Sha_Lin = 2307,
                Skye = 2057,
                Strix = 2438,
                Talus = 2472,
                Terminus = 2477,
                Torvald = 2322,
                Tyra = 2314,
                Viktor = 2285,
                Vivian = 2480,
                Willo = 2393,
                Ying = 2267,
                Zhin = 2420
            }
            public static string IDParse(Champion.ID champ)
            {
                var str = champ.ToString();
                if (str == ID.Mal_Damba.ToString())
                    str = str.Replace("_", "'");
                else if (str.Contains("_"))
                    str = str.Replace("_", " ");

                return str;
            }
            public static string IDParse(int ID)
            {
                var str = ((Champion.ID)ID).ToString();
                if (str == Champion.ID.Mal_Damba.ToString())
                    str = str.Replace("_", "'");
                else if (str.Contains("_"))
                    str = str.Replace("_", " ");
                return str;
            }
        }
        public class RankTiers
        {
            public enum Tier
            {
                Qualify = 0,
                Bronze_5 = 1,
                Bronze_4 = 2,
                Bronze_3 = 3,
                Bronze_2 = 4,
                Bronze_1 = 5,
                Silver_5 = 6,
                Silver_4 = 7,
                Silver_3 = 8,
                Silver_2 = 9,
                Silver_1 = 10,
                Gold_5 = 11,
                Gold_4 = 12,
                Gold_3 = 13,
                Gold_2 = 14,
                Gold_1 = 15,
                Platinum_5 = 16,
                Platinum_4 = 17,
                Platinum_3 = 18,
                Platinum_2 = 19,
                Platinum_1 = 20,
                Diamond_5 = 21,
                Diamond_4 = 22,
                Diamond_3 = 23,
                Diamond_2 = 24,
                Diamond_1 = 25,
                Master = 26,
                Grand_Master = 27
            }
            public static string TierParse(RankTiers.Tier tier)
            {
                var str = tier.ToString();
                if (str.Contains("_"))
                    str = str.Replace("_", " ");

                return str;
            }
            public static string TierParse(int tier)
            {
                var str = ((RankTiers.Tier)tier).ToString();
                if (str.Contains("_"))
                    str = str.Replace("_", " ");
                return str;
            }
        }
        public class Queue
        {
            public enum ID
            {
                Siege = 424,
                Siege_Training = 425,
                Ranked = 428,
                Tutorial = 444,
                Onslaught_Training = 453,
                Deathmatch = 469,
                Team_Deathmatch_Training = 470
            }
            public static string IDParse(Queue.ID queue)
            {
                var str = queue.ToString();
                if (str.Contains("_"))
                    str = str.Replace("_", " ");

                return str;
            }
            public static string IDParse(int queue)
            {
                var str = ((Queue.ID)queue).ToString();
                if (str.Contains("_"))
                    str = str.Replace("_", " ");
                return str;
            }
        }


        public static T Deserialization<T>(string input)
        {
            var jsonString = CallServer(input);
            return JsonConvert.DeserializeObject<T>(jsonString);
        }
        public void CleanJson(ref string json, ref string[] removal)
        {
            var jo = JObject.Parse(json);
            foreach (var prop in removal)
            {
                jo.Property(prop).Remove();
            }

            json = jo.ToString();
        }

        public class ServerStatus
        {
            public string entry_datetime { get; set; }
            public string ret_msg { get; set; }
            public string status { get; set; }
            public string version { get; set; }
        }
        public class DevDataUsed
        {
            public int Active_Sessions { get; set; }
            public int Concurrent_Sessions { get; set; }
            public int Request_Limit_Daily { get; set; }
            public int Session_Cap { get; set; }
            public int Session_Time_Limit { get; set; }
            public int Total_Requests_Today { get; set; }
            public int Total_Sessions_Today { get; set; }
            public string ret_msg { get; set; }
        }
        public class SessionInfo
        {
            public string ret_msg { get; set; }
            public string session_id { get; set; }
            public string timestamp { get; set; }

        }
        public class Friends
        {
            public string account_id { get; set; }
            public string name { get; set; }
            public string player_id { get; set; }
            public string ret_msg { get; set; }
        }
        public class ChampionRanks
        {
            public string assists { get; set; }
            public string deaths { get; set; }
            public string kills { get; set; }
            public string losses { get; set; }
            public string minionKills { get; set; }
            public string rank { get; set; }
            public string wins { get; set; }
            public string worshippers { get; set; }
            public string champion { get; set; }
            public string champion_id { get; set; }
            public string player_id { get; set; }
            public string ret_msg { get; set; }
        }
        public class AbilityDescription
        {
            public string description { get; set; }
            public int id { get; set; }
            public string summary { get; set; }
            public string url { get; set; }
        }
        public class Champions
        {
            public string Ability1 { get; set; }
            public string Ability2 { get; set; }
            public string Ability3 { get; set; }
            public string Ability4 { get; set; }
            public string Ability5 { get; set; }
            public int AbilityId1 { get; set; }
            public int AbilityId2 { get; set; }
            public int AbilityId3 { get; set; }
            public int AbilityId4 { get; set; }
            public int AbilityId5 { get; set; }
            public AbilityDescription Ability_1 { get; set; }
            public AbilityDescription Ability_2 { get; set; }
            public AbilityDescription Ability_3 { get; set; }
            public AbilityDescription Ability_4 { get; set; }
            public AbilityDescription Ability_5 { get; set; }
            public string ChampionAbility1_URL { get; set; }
            public string ChampionAbility2_URL { get; set; }
            public string ChampionAbility3_URL { get; set; }
            public string ChampionAbility4_URL { get; set; }
            public string ChampionAbility5_URL { get; set; }
            public string ChampionCard_URL { get; set; }
            public string ChampionIcon_URL { get; set; }
            public string Cons { get; set; }
            public int Health { get; set; }
            public string Lore { get; set; }
            public string Name { get; set; }
            public string OnFreeRotation { get; set; }
            public string Pantheon { get; set; }
            public string Pros { get; set; }
            public string Roles { get; set; }
            public int Speed { get; set; }
            public string Title { get; set; }
            public string Type { get; set; }
            public string abilityDescription1 { get; set; }
            public string abilityDescription2 { get; set; }
            public string abilityDescription3 { get; set; }
            public string abilityDescription4 { get; set; }
            public string abilityDescription5 { get; set; }
            public int id { get; set; }
            public string latestChampion { get; set; }
            public string ret_msg { get; set; }
        }
        public class SkinDetails
        {
            public string champion_id { get; set; }
            public string champion_name { get; set; }
            public string rarity { get; set; }
            public string ret_msg { get; set; }
            public string skin_id1 { get; set; }
            public string skin_id2 { get; set; }
            public string skin_name { get; set; }
            public string skin_name_english { get; set; }
        }
        public class Items
        {
            public string Description { get; set; }
            public string DeviceName { get; set; }
            public int IconId { get; set; }
            public int ItemId { get; set; }
            public int Price { get; set; }
            public string ShortDesc { get; set; }
            public int champion_id { get; set; }
            public string itemIcon_URL { get; set; }
            public string item_type { get; set; }
            public string ret_msg { get; set; }
            public string talent_reward_level { get; set; }
        }
        public class MatchDetails
        {
            public int Account_Level { get; set; }
            public int ActiveId1 { get; set; }
            public int ActiveId2 { get; set; }
            public int ActiveId3 { get; set; }
            public int ActiveId4 { get; set; }
            public int ActiveLevel1 { get; set; }
            public int ActiveLevel2 { get; set; }
            public int ActiveLevel3 { get; set; }
            public int ActiveLevel4 { get; set; }
            public int Assists { get; set; }
            public int BanId1 { get; set; }
            public int BanId2 { get; set; }
            public int BanId3 { get; set; }
            public int BanId4 { get; set; }
            public string Ban_1 { get; set; }
            public string Ban_2 { get; set; }
            public string Ban_3 { get; set; }
            public string Ban_4 { get; set; }
            public int Camps_Cleared { get; set; }
            public int ChampionId { get; set; }
            public int Damage_Bot { get; set; }
            public int Damage_Done_In_Hand { get; set; }
            public int Damage_Done_Magical { get; set; }
            public int Damage_Done_Physical { get; set; }
            public int Damage_Mitigated { get; set; }
            public int Damage_Player { get; set; }
            public int Damage_Taken { get; set; }
            public int Damage_Taken_Magical { get; set; }
            public int Damage_Taken_Physical { get; set; }
            public int Deaths { get; set; }
            public int Distance_Traveled { get; set; }
            public string Entry_Datetime { get; set; }
            public int Final_Match_Level { get; set; }
            public int Gold_Earned { get; set; }
            public int Gold_Per_Minute { get; set; }
            public int Healing { get; set; }
            public int Healing_Bot { get; set; }
            public int Healing_Player_Self { get; set; }
            public int ItemId1 { get; set; }
            public int ItemId2 { get; set; }
            public int ItemId3 { get; set; }
            public int ItemId4 { get; set; }
            public int ItemId5 { get; set; }
            public int ItemId6 { get; set; }
            public int ItemLevel1 { get; set; }
            public int ItemLevel2 { get; set; }
            public int ItemLevel3 { get; set; }
            public int ItemLevel4 { get; set; }
            public int ItemLevel5 { get; set; }
            public int ItemLevel6 { get; set; }
            public string Item_Active_1 { get; set; }
            public string Item_Active_2 { get; set; }
            public string Item_Active_3 { get; set; }
            public string Item_Active_4 { get; set; }
            public string Item_Purch_1 { get; set; }
            public string Item_Purch_2 { get; set; }
            public string Item_Purch_3 { get; set; }
            public string Item_Purch_4 { get; set; }
            public string Item_Purch_5 { get; set; }
            public string Item_Purch_6 { get; set; }
            public int Killing_Spree { get; set; }
            public int Kills_Bot { get; set; }
            public int Kills_Double { get; set; }
            public int Kills_Fire_Giant { get; set; }
            public int Kills_First_Blood { get; set; }
            public int Kills_Gold_Fury { get; set; }
            public int Kills_Penta { get; set; }
            public int Kills_Phoenix { get; set; }
            public int Kills_Player { get; set; }
            public int Kills_Quadra { get; set; }
            public int Kills_Siege_Juggernaut { get; set; }
            public int Kills_Single { get; set; }
            public int Kills_Triple { get; set; }
            public int Kills_Wild_Juggernaut { get; set; }
            public int League_Losses { get; set; }
            public int League_Points { get; set; }
            public int League_Tier { get; set; }
            public int League_Wins { get; set; }
            public string Map_Game { get; set; }
            public int Mastery_Level { get; set; }
            public int Match { get; set; }
            public int Minutes { get; set; }
            public int Multi_kill_Max { get; set; }
            public int Objective_Assists { get; set; }
            public int PartyId { get; set; }
            public int Rank_Stat_League { get; set; }
            public string Reference_Name { get; set; }
            public string Region { get; set; }
            public string Skin { get; set; }
            public int SkinId { get; set; }
            public int Structure_Damage { get; set; }
            public int Surrendered { get; set; }
            public int TaskForce { get; set; }
            public int Team1Score { get; set; }
            public int Team2Score { get; set; }
            public int TeamId { get; set; }
            public string Team_Name { get; set; }
            public int Time_In_Match_Seconds { get; set; }
            public int Towers_Destroyed { get; set; }
            public int Wards_Placed { get; set; }
            public string Win_Status { get; set; }
            public int Winning_TaskForce { get; set; }
            public string hasReplay { get; set; }
            public int match_queue_id { get; set; }
            public string name { get; set; }
            public string playerId { get; set; }
            public string playerName { get; set; }
            public string ret_msg { get; set; }
        }
        public class MatchHistoryDetails
        {
            public int ActiveId1 { get; set; }
            public int ActiveId2 { get; set; }
            public int ActiveId3 { get; set; }
            public int ActiveId4 { get; set; }
            public int ActiveLevel1 { get; set; }
            public int ActiveLevel2 { get; set; }
            public int ActiveLevel3 { get; set; }
            public int ActiveLevel4 { get; set; }
            public string Active_1 { get; set; }
            public string Active_2 { get; set; }
            public string Active_3 { get; set; }
            public string Active_4 { get; set; }
            public int Assists { get; set; }
            public string Champion { get; set; }
            public int ChampionId { get; set; }
            public int Creeps { get; set; }
            public int Damage { get; set; }
            public int Damage_Bot { get; set; }
            public int Damage_Done_In_Hand { get; set; }
            public int Damage_Mitigated { get; set; }
            public int Damage_Structure { get; set; }
            public int Damage_Taken { get; set; }
            public int Damage_Taken_Magical { get; set; }
            public int Damage_Taken_Physical { get; set; }
            public int Deaths { get; set; }
            public int Distance_Traveled { get; set; }
            public int Gold { get; set; }
            public int Healing { get; set; }
            public int Healing_Bot { get; set; }
            public int Healing_Player_Self { get; set; }
            public int ItemId1 { get; set; }
            public int ItemId2 { get; set; }
            public int ItemId3 { get; set; }
            public int ItemId4 { get; set; }
            public int ItemId5 { get; set; }
            public int ItemId6 { get; set; }
            public int ItemLevel1 { get; set; }
            public int ItemLevel2 { get; set; }
            public int ItemLevel3 { get; set; }
            public int ItemLevel4 { get; set; }
            public int ItemLevel5 { get; set; }
            public int ItemLevel6 { get; set; }
            public string Item_1 { get; set; }
            public string Item_2 { get; set; }
            public string Item_3 { get; set; }
            public string Item_4 { get; set; }
            public string Item_5 { get; set; }
            public string Item_6 { get; set; }
            public int Killing_Spree { get; set; }
            public int Kills { get; set; }
            public int Level { get; set; }
            public string Map_Game { get; set; }
            public int Match { get; set; }
            public int Match_Queue_Id { get; set; }
            public string Match_Time { get; set; }
            public int Minutes { get; set; }
            public int Multi_kill_Max { get; set; }
            public int Objective_Assists { get; set; }
            public string Queue { get; set; }
            public string Region { get; set; }
            public string Skin { get; set; }
            public int SkinId { get; set; }
            public int Surrendered { get; set; }
            public int TaskForce { get; set; }
            public int Team1Score { get; set; }
            public int Team2Score { get; set; }
            public int Time_In_Match_Seconds { get; set; }
            public int Wards_Placed { get; set; }
            public string Win_Status { get; set; }
            public int Winning_TaskForce { get; set; }
            public string playerName { get; set; }
            public string ret_msg { get; set; }
        }
        public class PlayerStatus
        {
            public int Match { get; set; }
            public string personal_status_message { get; set; }
            public string ret_msg { get; set; }
            public int status { get; set; }
            public string status_string { get; set; }
        }
        public class MatchPlayerDetails
        {
            public int Account_Level { get; set; }
            public int ChampionId { get; set; }
            public string ChampionName { get; set; }
            public int Mastery_Level { get; set; }
            public int Match { get; set; }
            public string Queue { get; set; }
            public string SkinId { get; set; }
            public string Tier { get; set; }
            public string playerCreated { get; set; }
            public string playerId { get; set; }
            public string playerName { get; set; }
            public string ret_msg { get; set; }
            public int taskForce { get; set; }
            public int tierLosses { get; set; }
            public int tierWins { get; set; }
        }
        public class RankedSeasonInfo
        {
            public string complete { get; set; }
            public int id { get; set; }
            public string name { get; set; }
            public string ret_msg { get; set; }
        }
        public class RankedStats
        {
            public int Leaves { get; set; }
            public int Losses { get; set; }
            public string Name { get; set; }
            public int Points { get; set; }
            public int PrevRank { get; set; }
            public int Rank { get; set; }
            public string Rank_Stat_Conquest { get; set; }
            public string Rank_Stat_Duel { get; set; }
            public string Rank_Stat_Joust { get; set; }
            public int Season { get; set; }
            public int Tier { get; set; }
            public int Trend { get; set; }
            public int Wins { get; set; }
            public string player_id { get; set; }
            public string ret_msg { get; set; }
        }
        public class PlayerInfo
        {
            public string Created_Datetime { get; set; }
            public int Id { get; set; }
            public string Last_Login_Datetime { get; set; }
            public int Leaves { get; set; }
            public int Level { get; set; }
            public int Losses { get; set; }
            public int MasteryLevel { get; set; }
            public string Name { get; set; }
            public string Personal_Status_Message { get; set; }
            public RankedStats RankedConquest { get; set; }
            public string Region { get; set; }
            public int TeamId { get; set; }
            public string Team_Name { get; set; }
            public int Tier_Conquest { get; set; }
            public int Total_Achievements { get; set; }
            public int Total_Worshippers { get; set; }
            public int Wins { get; set; }
            public string ret_msg { get; set; }
        }
        public class Achievements
        {
            public int AssistedKills { get; set; }
            public int CampsCleared { get; set; }
            public int DivineSpree { get; set; }
            public int DoubleKills { get; set; }
            public int FireGiantKills { get; set; }
            public int FirstBloods { get; set; }
            public int GodLikeSpree { get; set; }
            public int GoldFuryKills { get; set; }
            public int Id { get; set; }
            public int ImmortalSpree { get; set; }
            public int KillingSpree { get; set; }
            public int MinionKills { get; set; }
            public string Name { get; set; }
            public int PentaKills { get; set; }
            public int PhoenixKills { get; set; }
            public int PlayerKills { get; set; }
            public int QuadraKills { get; set; }
            public int RampageSpree { get; set; }
            public int ShutdownSpree { get; set; }
            public int SiegeJuggernautKills { get; set; }
            public int TowerKills { get; set; }
            public int TripleKills { get; set; }
            public int UnstoppableSpree { get; set; }
            public int WildJuggernautKills { get; set; }
            public string ret_msg { get; set; }
        }
        public class QueueStats
        {
            public int Assists { get; set; }
            public string Champion { get; set; }
            public int ChampionId { get; set; }
            public int Death { get; set; }
            public int Gold { get; set; }
            public int Kills { get; set; }
            public string LastPlayed { get; set; }
            public int Losses { get; set; }
            public int Matches { get; set; }
            public int Minutes { get; set; }
            public string Queue { get; set; }
            public int Wins { get; set; }
            public string player_id { get; set; }
            public string ret_msg { get; set; }
        }
        public class LoadOutItems
        {
            public int ItemId { get; set; }
            public string ItemName { get; set; }
            public int Points { get; set; }
        }
        public class GetPlayerLoadout
        {
            public int ChampionId { get; set; }
            public string ChampionName { get; set; }
            public int DeckId { get; set; }
            public string DeckName { get; set; }
            public List<LoadOutItems> LoadoutItems { get; set; }
            public int playerId { get; set; }
            public string playerName { get; set; }
            public string ret_msg { get; set; }
        }
        public class EsportsProLeagueData
        {
            public int away_team_clan_id { get; set; }
            public string away_team_name { get; set; }
            public string away_team_tagname { get; set; }
            public int home_team_clan_id { get; set; }
            public string home_team_name { get; set; }
            public string home_team_tagname { get; set; }
            public string map_instance_id { get; set; }
            public string match_date { get; set; }
            public string match_number { get; set; }
            public string match_status { get; set; }
            public string matchup_id { get; set; }
            public string region { get; set; }
            public object ret_msg { get; set; }
            public string tournament_name { get; set; }
            public int winning_team_clan_id { get; set; }
        }
        public class MatchesByQueue
        {
            public string Active_Flag { get; set; }
            public string Match { get; set; }
            public object ret_msg { get; set; }
        }
    }
}