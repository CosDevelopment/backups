using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Reflection.Emit;
using System.Security.Cryptography;
using System.Text;
using System.Web;
using Newtonsoft.Json;

namespace PaladinsApiC_Sharp
{
    public partial class PaladinsApi
    {
        /*
         * You should have access to this on your paladins.gg email
         * Function Call Checklist can be found here: https://docs.google.com/spreadsheets/d/157B9JWLLFPbHM5ZO_PZ--35uf-4504GxHn32k740Ghs/edit?usp=sharing
         *
         * Output to test.json is "../../test.json"
         *
         */

        private const string BaseURL = "http://api.paladins.com/paladinsapi.svc";
        private static string devID;
        private static string authKey;
        private const string responseFormat = "Json"; // Allows for an easy way to change, just in case
        private static string timeStamp;
        private static SessionInfo _session;
        private static DateTime _lastSession;

        public PaladinsApi(string devID, string authKey)
        {
            PaladinsApi.devID = devID;
            PaladinsApi.authKey = authKey;
            CreateSession();
        }
        public void CheckSessionLife()
        {
            if (DateTime.UtcNow.Subtract(_lastSession).TotalMinutes >= 15)
                CreateSession();
        }

        ///<summary> Sends a request to HiRez's Server using an apicall </summary>
        ///<param name="apicall"> The rest of the URL associated with an apicall </param>
        ///<returns> The response from the server, if any </returns>
        private static string CallServer(string apicall)
        {
            var request = WebRequest.Create($"{BaseURL}/{apicall}"); // Makes the Request to the server
            var response = request.GetResponse(); // Gets the server's response
            var stream = response.GetResponseStream();
            var reader = new StreamReader(stream ?? throw new InvalidOperationException());
            var responseFromServer = reader.ReadToEnd();
            reader.Close();
            response.Close();

            return responseFromServer;
        }

        private static string GetMD5Hash(string input)
        {
            var md5 = new System.Security.Cryptography.MD5CryptoServiceProvider();
            var bytes = System.Text.Encoding.UTF8.GetBytes(input);
            bytes = md5.ComputeHash(bytes);
            var sb = new System.Text.StringBuilder();
            foreach (var b in bytes)
            {
                sb.Append(b.ToString("x2").ToLower());
            }
            return sb.ToString();
        }

        ///<summary> Pings the server, used for testing the connection </summary>
        public void Ping()
        {
            CheckSessionLife();
            const string action = "ping";
            Console.WriteLine(CallServer($"{action}{responseFormat}"));
        }

        ///<summary> Creates a session to use the HiRes API for Paladins </summary>
        public SessionInfo CreateSession()
        {
            const string action = "createsession";
            timeStamp = DateTime.UtcNow.ToString("yyyyMMddHHmmss");
            _lastSession = DateTime.UtcNow;
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            _session = Deserialization<SessionInfo>($"{action}{responseFormat}/{devID}/{_signature}/{timeStamp}");
            return _session;
        }

        ///<summary> Tests to see if the session was created properly </summary>
        public void TestSession()
        {
            CheckSessionLife();
            const string action = "testsession";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            Console.WriteLine(CallServer($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}"));
        }

        ///<summary> Gets the status of the HiRez server </summary>
        public List<ServerStatus> GetHiRezServerStatus()
        {
            CheckSessionLife();
            const string action = "gethirezserverstatus";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<ServerStatus>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}");
        }

        ///<summary> Used to check the data usage associated with the used dev account</summary>
        public List<DevDataUsed> GetDataUsed()
        {
            CheckSessionLife();
            const string action = "getdataused";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<DevDataUsed>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}");
        }

        ///<summary> </summary>
        public List<EsportsProLeagueData> GetESportsProLeagueDetails()
        {
            CheckSessionLife();
            const string action = "getesportsproleaguedetails";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            var data = Deserialization<List<EsportsProLeagueData>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}");
            File.WriteAllText("../../test.json", CallServer($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}"));
            return data;
        }

        ///<summary></summary>
        public List<Friends> GetFriends(string playerName)
        {
            CheckSessionLife();
            const string action = "getfriends";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<Friends>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}/{playerName}");
        }

        ///<summary> Returns all the information associated with playerName's champions, e.g. Level, kills, deaths, assists, etc. </summary>
        ///<param name="playerName"> The player that is having their information looked up </param>
        public List<ChampionRanks> GetChampionRanks(string playerName)
        {
            CheckSessionLife();
            const string action = "getchampionranks";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<ChampionRanks>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}/{playerName}");

        }

        ///<summary> Returns all the information associated with all the champions in the current version in the game </summary>
        ///<param name="lang"> The language the response will be returned in </param>
        public List<Champions> GetChampions(LanguageCode lang)
        {
            CheckSessionLife();
            const string action = "getchampions";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<Champions>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}/{(int)lang}");
        }

        ///<summary> </summary>
        ///<param name="champID"></param>
        ///<param name="lang"> The language the response will be returned in  </param>
        public List<SkinDetails> GetChampionSkins(Champion.ID champID, LanguageCode lang)
        {
            CheckSessionLife();
            const string action = "getchampionskins";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<SkinDetails>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}/{(int)champID}/{(int)lang}");

        }

        ///<summary> </summary>
        ///<param name="lang"> The language the response will be returned in </param>
        public List<Items> GetItems(LanguageCode lang)
        {
            CheckSessionLife();
            const string action = "getitems";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<Items>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}/{(int)lang}");
        }

        ///<summary> </summary>
        ///<param name="matchID"></param>
        public List<MatchDetails> GetMatchDetails(string matchID)
        {
            CheckSessionLife();
            const string action = "getmatchdetails";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<MatchDetails>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}/{matchID}");
        }

        ///<summary> </summary>
        ///<param name="matchID"></param>
        public List<MatchPlayerDetails> GetMatchPlayerDetails(string matchID)
        {
            CheckSessionLife();
            const string action = "getmatchplayerdetails";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            File.WriteAllText("../../MatchPlayerDetails.json", CallServer($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}/{matchID}"));
            return Deserialization<List<MatchPlayerDetails>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}/{matchID}");
        }

        ///<summary> </summary>
        ///<param name="queueID"> The id of the game mode </param>
        ///<param name="date"> In the format "yyyyMMdd" </param>
        ///<param name="time"> A string in the format "HH,mm" relative to UTC, where ",mm" is "00", "10", “20”, “30”, “40”, “50” </param>
        public List<MatchesByQueue> GetMatchIDsByQueue(Queue.ID queueID, DateTime date, string time)
        {
            CheckSessionLife();
            const string action = "getmatchidsbyqueue";
            var dateStr = date.ToString("yyyyMMdd");
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<MatchesByQueue>>($"{ action}{ responseFormat}/{ devID}/{ _signature}/{ _session.session_id}/{ timeStamp}/{(int)queueID}/{ dateStr}/{ time}");
        }

        ///<summary> </summary>
        ///<param name="queueID"> The id of the game mode </param>
        ///<param name="tier"> The tier division, ex. Bronze_1 </param>
        ///<param name="season"> The season of the league </param>
        public List<RankedStats> GetLeagueLeaderBoard(Queue.ID queueID, RankTiers.Tier tier, int season)
        {
            CheckSessionLife();
            const string action = "getleagueleaderboard";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<RankedStats>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}/{(int)queueID}/{(int)tier}/{season}");
        }

        ///<summary> </summary>
        ///<param name="queueID"> The id of the game mode </param>
        public List<RankedSeasonInfo> GetLeagueSeasons(Queue.ID queueID)
        {
            CheckSessionLife();
            const string action = "getleagueseasons";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<RankedSeasonInfo>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}/{(int)queueID}");
        }

        ///<summary> </summary>
        ///<param name="playerName"> The player that is having their information looked up </param>
        public List<MatchHistoryDetails> GetMatchHistory(string playerName)
        {
            CheckSessionLife();
            const string action = "getmatchhistory";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<MatchHistoryDetails>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}/{playerName}");
        }

        ///<summary> </summary>
        ///<param name="playerName"> The player that is having their information looked up </param>
        public List<PlayerInfo> GetPlayer(string playerName)
        {
            CheckSessionLife();
            const string action = "getplayer";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<PlayerInfo>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}/{playerName}");
        }

        ///<summary> </summary>
        ///<param name="playerID"> The ID of the player that is having their information looked up </param>
        ///<param name="lang"> The language the response will be returned in </param> 
        public List<GetPlayerLoadout> GetPlayerLoadouts(int playerID, LanguageCode lang)
        {
            CheckSessionLife();
            const string action = "getplayerloadouts";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<GetPlayerLoadout>>($"{ action}{ responseFormat}/{ devID}/{ _signature}/{ _session.session_id}/{ timeStamp}/{ playerID}/{ (int)lang}");
        }

        ///<summary> </summary>
        ///<param name="playerName"> The player that is having their information looked up </param>
        public List<PlayerStatus> GetPlayerStatus(string playerName)
        {
            CheckSessionLife();
            const string action = "getplayerstatus";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<PlayerStatus>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}/{playerName}");
        }

        ///<summary> </summary>
        ///<param name="playerName"> The player that is having their information looked up </param>
        ///<param name="queueID"></param>
        public List<QueueStats> GetQueueStats(string playerName, Queue.ID queueID)
        {
            CheckSessionLife();
            const string action = "getqueuestats";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<List<QueueStats>>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}/{playerName}/{(int)queueID}");

        }
        public Achievements GetPlayerAchievements(int playerID)
        {
            CheckSessionLife();
            const string action = "getplayerachievements";
            var _signature = GetMD5Hash($"{devID}{action}{authKey}{timeStamp}");
            return Deserialization<Achievements>($"{action}{responseFormat}/{devID}/{_signature}/{_session.session_id}/{timeStamp}/{playerID}");
        }
    }
}