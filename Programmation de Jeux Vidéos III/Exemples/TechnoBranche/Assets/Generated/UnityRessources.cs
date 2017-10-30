// ----- AUTO GENERATED CODE - ANY MODIFICATION WILL BE OVERRIDEN ----- //

using System;

namespace Harmony
{
    public static class R
    {
        public static class E
        {
            public enum Layer
            {
                None = -1503227594,
                Default = 1948333211,
                TransparentFx = -1882701027,
                IgnoreRaycast = 338979552,
                Water = 78692563,
                Ui = -837699605,
                Player = -2033144378,
                PresenceSensor = 256532668,
                EffectSensor = 1051472700,
	        }
            
            public enum Tag
            {
                None = -1503227594,
                ApplicationDependencies = 1730835176,
                ActivityDependencies = 2139145558,
                SceneDependencies = -631844885,
                EventChannels = 383674883,
                Navigation = 749312969,
                Untagged = -571865525,
                Respawn = -1490796770,
                Finish = -383300399,
                EditorOnly = 1795888415,
                Player = -2033144378,
                MainCamera = 1926007183,
	        }
            
            public enum Scene
            {
                None = -1503227594,
                Main = 1222789680,
                GameFragment = 1742177104,
                HeadUpDisplay = 940498937,
                LoadingScreen = 1149912305,
	        }
            
            public enum Prefab
            {
                None = -1503227594,
                Player = -2033144378,
                Shine = 48367701,
                Stars = -1587696329,
                Coin = 1222920746,
                Point = 33229055,
                HealthBar = -1111092702,
                Score = 1512031223,
	        }
            
            public enum GameObject
            {
                None = -1503227594,
                Control = 984698823,
                Input = 818278051,
                MainCamera = 1926007183,
                EventChannels = 1560737576,
                Initialization = 1765798574,
                ApplicationController = -42228605,
                Hills2 = 24339917,
                Flower12 = 213200000,
                GameFragmentController = 1441175076,
                Ground = -1166163552,
                GrassAndRocks12 = 1618427197,
                Flower22 = -1897330969,
                Cloud12 = -1044830065,
                Tree21 = 1062094544,
                Flower11 = 213396608,
                Navigation = 749312969,
                Cloud22 = -1052235633,
                Hills1 = 24143309,
                Flower21 = -1897134361,
                Flower13 = 213265536,
                Bush3 = 975340824,
                Cloud21 = -1052235632,
                Actors = 1218035757,
                Bush1 = -187458590,
                Cloud11 = -1044830064,
                Foreground = -1422261881,
                World = -1506748533,
                Flower14 = 213068928,
                Music = -330216473,
                GrassAndRocks21 = 1628192064,
                Bush2 = -590743117,
                Bush4 = 215825937,
                Tree12 = -511883585,
                Tree11 = 1062094527,
                Sky = -1694039926,
                Event = -1560445450,
                GrassAndRocks11 = 1618427200,
                Background = 481518672,
                Text = -307131410,
                Canvas = -1971892856,
                Image = 820751583,
                StepCount = -518864700,
                CoinCount = 972077639,
                Informations = -942002357,
                LoadingScreenController = 596290937,
                Logic = -1608751134,
                MainText = -1420397088,
                LeftFoot = 1524961682,
                LowerBody = -1132352890,
                RightHand = 1801937848,
                UpperBody = 1921110619,
                Arms = -790225768,
                RightEye = 2046125672,
                CollectBox = 1946799564,
                PresenceBox = -1959291255,
                Sound = 2002597352,
                Player = -2033144378,
                Torso = -1933715409,
                Eyes = -433405588,
                LoudFootsteps = -557563023,
                Foots = 1138344300,
                RightFoot = 1732887603,
                LeftHand = 318831288,
                Visual = 428166410,
                RightArm = -234843148,
                Footsteps = -274708535,
                LeftArm = -1205384070,
                LeftEye = 1534079751,
                Shine = 48367701,
                Stars = -1587696329,
                ShineEffect = -2057363840,
                Coin = 1222920746,
                Point = 33229055,
                PlayerPresenceBox = 2016852142,
                HealthBar = -1111092702,
                Score = 1512031223,
	        }
            
            public enum AnimatorParameter
            {
                None = -1503227594,
                HorizontalVelocity = -367364518,
                VerticalVelocity = -1365181115,
                Blink = 39716438,
	        }
            
        }

        public static class S
        {
            public static class Layer
            {
                public const string None = "None";
                public const string Default = "Default";
                public const string TransparentFx = "TransparentFX";
                public const string IgnoreRaycast = "Ignore Raycast";
                public const string Water = "Water";
                public const string Ui = "UI";
                public const string Player = "Player";
                public const string PresenceSensor = "PresenceSensor";
                public const string EffectSensor = "EffectSensor";

                public static string ToString(E.Layer value)
                {
                    switch (value)
                    {
                        case E.Layer.None:
                            return None;
                        case E.Layer.Default:
                            return Default;
                        case E.Layer.TransparentFx:
                            return TransparentFx;
                        case E.Layer.IgnoreRaycast:
                            return IgnoreRaycast;
                        case E.Layer.Water:
                            return Water;
                        case E.Layer.Ui:
                            return Ui;
                        case E.Layer.Player:
                            return Player;
                        case E.Layer.PresenceSensor:
                            return PresenceSensor;
                        case E.Layer.EffectSensor:
                            return EffectSensor;
                    }
                    return null;
                }

                public static E.Layer ToEnum(string value)
                {
                    switch (value)
                    {
                        case None:
                            return E.Layer.None;
                        case Default:
                            return E.Layer.Default;
                        case TransparentFx:
                            return E.Layer.TransparentFx;
                        case IgnoreRaycast:
                            return E.Layer.IgnoreRaycast;
                        case Water:
                            return E.Layer.Water;
                        case Ui:
                            return E.Layer.Ui;
                        case Player:
                            return E.Layer.Player;
                        case PresenceSensor:
                            return E.Layer.PresenceSensor;
                        case EffectSensor:
                            return E.Layer.EffectSensor;
                    }
                    throw new ArgumentException("Unable to convert " + value + " to UnityRessources.Enums.Layer.");
                }
            }
            
            public static class Tag
            {
                public const string None = "None";
                public const string ApplicationDependencies = "Application Dependencies";
                public const string ActivityDependencies = "Activity Dependencies";
                public const string SceneDependencies = "Scene Dependencies";
                public const string EventChannels = "Event Channels";
                public const string Navigation = "Navigation";
                public const string Untagged = "Untagged";
                public const string Respawn = "Respawn";
                public const string Finish = "Finish";
                public const string EditorOnly = "EditorOnly";
                public const string Player = "Player";
                public const string MainCamera = "MainCamera";

                public static string ToString(E.Tag value)
                {
                    switch (value)
                    {
                        case E.Tag.None:
                            return None;
                        case E.Tag.ApplicationDependencies:
                            return ApplicationDependencies;
                        case E.Tag.ActivityDependencies:
                            return ActivityDependencies;
                        case E.Tag.SceneDependencies:
                            return SceneDependencies;
                        case E.Tag.EventChannels:
                            return EventChannels;
                        case E.Tag.Navigation:
                            return Navigation;
                        case E.Tag.Untagged:
                            return Untagged;
                        case E.Tag.Respawn:
                            return Respawn;
                        case E.Tag.Finish:
                            return Finish;
                        case E.Tag.EditorOnly:
                            return EditorOnly;
                        case E.Tag.Player:
                            return Player;
                        case E.Tag.MainCamera:
                            return MainCamera;
                    }
                    return null;
                }

                public static E.Tag ToEnum(string value)
                {
                    switch (value)
                    {
                        case None:
                            return E.Tag.None;
                        case ApplicationDependencies:
                            return E.Tag.ApplicationDependencies;
                        case ActivityDependencies:
                            return E.Tag.ActivityDependencies;
                        case SceneDependencies:
                            return E.Tag.SceneDependencies;
                        case EventChannels:
                            return E.Tag.EventChannels;
                        case Navigation:
                            return E.Tag.Navigation;
                        case Untagged:
                            return E.Tag.Untagged;
                        case Respawn:
                            return E.Tag.Respawn;
                        case Finish:
                            return E.Tag.Finish;
                        case EditorOnly:
                            return E.Tag.EditorOnly;
                        case Player:
                            return E.Tag.Player;
                        case MainCamera:
                            return E.Tag.MainCamera;
                    }
                    throw new ArgumentException("Unable to convert " + value + " to UnityRessources.Enums.Tag.");
                }
            }
            
            public static class Scene
            {
                public const string None = "None";
                public const string Main = "Main";
                public const string GameFragment = "GameFragment";
                public const string HeadUpDisplay = "HeadUpDisplay";
                public const string LoadingScreen = "LoadingScreen";

                public static string ToString(E.Scene value)
                {
                    switch (value)
                    {
                        case E.Scene.None:
                            return None;
                        case E.Scene.Main:
                            return Main;
                        case E.Scene.GameFragment:
                            return GameFragment;
                        case E.Scene.HeadUpDisplay:
                            return HeadUpDisplay;
                        case E.Scene.LoadingScreen:
                            return LoadingScreen;
                    }
                    return null;
                }

                public static E.Scene ToEnum(string value)
                {
                    switch (value)
                    {
                        case None:
                            return E.Scene.None;
                        case Main:
                            return E.Scene.Main;
                        case GameFragment:
                            return E.Scene.GameFragment;
                        case HeadUpDisplay:
                            return E.Scene.HeadUpDisplay;
                        case LoadingScreen:
                            return E.Scene.LoadingScreen;
                    }
                    throw new ArgumentException("Unable to convert " + value + " to UnityRessources.Enums.Scene.");
                }
            }
            
            public static class Prefab
            {
                public const string None = "None";
                public const string Player = "Player";
                public const string Shine = "Shine";
                public const string Stars = "Stars";
                public const string Coin = "Coin";
                public const string Point = "Point";
                public const string HealthBar = "HealthBar";
                public const string Score = "Score";

                public static string ToString(E.Prefab value)
                {
                    switch (value)
                    {
                        case E.Prefab.None:
                            return None;
                        case E.Prefab.Player:
                            return Player;
                        case E.Prefab.Shine:
                            return Shine;
                        case E.Prefab.Stars:
                            return Stars;
                        case E.Prefab.Coin:
                            return Coin;
                        case E.Prefab.Point:
                            return Point;
                        case E.Prefab.HealthBar:
                            return HealthBar;
                        case E.Prefab.Score:
                            return Score;
                    }
                    return null;
                }

                public static E.Prefab ToEnum(string value)
                {
                    switch (value)
                    {
                        case None:
                            return E.Prefab.None;
                        case Player:
                            return E.Prefab.Player;
                        case Shine:
                            return E.Prefab.Shine;
                        case Stars:
                            return E.Prefab.Stars;
                        case Coin:
                            return E.Prefab.Coin;
                        case Point:
                            return E.Prefab.Point;
                        case HealthBar:
                            return E.Prefab.HealthBar;
                        case Score:
                            return E.Prefab.Score;
                    }
                    throw new ArgumentException("Unable to convert " + value + " to UnityRessources.Enums.Prefab.");
                }
            }
            
            public static class GameObject
            {
                public const string None = "None";
                public const string Control = "Control";
                public const string Input = "Input";
                public const string MainCamera = "MainCamera";
                public const string EventChannels = "EventChannels";
                public const string Initialization = "Initialization";
                public const string ApplicationController = "ApplicationController";
                public const string Hills2 = "Hills2";
                public const string Flower12 = "Flower1 (2)";
                public const string GameFragmentController = "GameFragmentController";
                public const string Ground = "Ground";
                public const string GrassAndRocks12 = "GrassAndRocks1 (2)";
                public const string Flower22 = "Flower2 (2)";
                public const string Cloud12 = "Cloud1 (2)";
                public const string Tree21 = "Tree2 (1)";
                public const string Flower11 = "Flower1 (1)";
                public const string Navigation = "Navigation";
                public const string Cloud22 = "Cloud2 (2)";
                public const string Hills1 = "Hills1";
                public const string Flower21 = "Flower2 (1)";
                public const string Flower13 = "Flower1 (3)";
                public const string Bush3 = "Bush (3)";
                public const string Cloud21 = "Cloud2 (1)";
                public const string Actors = "Actors";
                public const string Bush1 = "Bush (1)";
                public const string Cloud11 = "Cloud1 (1)";
                public const string Foreground = "Foreground";
                public const string World = "World";
                public const string Flower14 = "Flower1 (4)";
                public const string Music = "Music";
                public const string GrassAndRocks21 = "GrassAndRocks2 (1)";
                public const string Bush2 = "Bush (2)";
                public const string Bush4 = "Bush (4)";
                public const string Tree12 = "Tree1 (2)";
                public const string Tree11 = "Tree1 (1)";
                public const string Sky = "Sky";
                public const string Event = "Event";
                public const string GrassAndRocks11 = "GrassAndRocks1 (1)";
                public const string Background = "Background";
                public const string Text = "Text";
                public const string Canvas = "Canvas";
                public const string Image = "Image";
                public const string StepCount = "StepCount";
                public const string CoinCount = "CoinCount";
                public const string Informations = "Informations";
                public const string LoadingScreenController = "LoadingScreenController";
                public const string Logic = "Logic";
                public const string MainText = "MainText";
                public const string LeftFoot = "Left Foot";
                public const string LowerBody = "LowerBody";
                public const string RightHand = "Right Hand";
                public const string UpperBody = "UpperBody";
                public const string Arms = "Arms";
                public const string RightEye = "Right Eye";
                public const string CollectBox = "CollectBox";
                public const string PresenceBox = "PresenceBox";
                public const string Sound = "Sound";
                public const string Player = "Player";
                public const string Torso = "Torso";
                public const string Eyes = "Eyes";
                public const string LoudFootsteps = "LoudFootsteps";
                public const string Foots = "Foots";
                public const string RightFoot = "Right Foot";
                public const string LeftHand = "Left Hand";
                public const string Visual = "Visual";
                public const string RightArm = "Right Arm";
                public const string Footsteps = "Footsteps";
                public const string LeftArm = "Left Arm";
                public const string LeftEye = "Left Eye";
                public const string Shine = "Shine";
                public const string Stars = "Stars";
                public const string ShineEffect = "ShineEffect";
                public const string Coin = "Coin";
                public const string Point = "Point";
                public const string PlayerPresenceBox = "PlayerPresenceBox";
                public const string HealthBar = "HealthBar";
                public const string Score = "Score";

                public static string ToString(E.GameObject value)
                {
                    switch (value)
                    {
                        case E.GameObject.None:
                            return None;
                        case E.GameObject.Control:
                            return Control;
                        case E.GameObject.Input:
                            return Input;
                        case E.GameObject.MainCamera:
                            return MainCamera;
                        case E.GameObject.EventChannels:
                            return EventChannels;
                        case E.GameObject.Initialization:
                            return Initialization;
                        case E.GameObject.ApplicationController:
                            return ApplicationController;
                        case E.GameObject.Hills2:
                            return Hills2;
                        case E.GameObject.Flower12:
                            return Flower12;
                        case E.GameObject.GameFragmentController:
                            return GameFragmentController;
                        case E.GameObject.Ground:
                            return Ground;
                        case E.GameObject.GrassAndRocks12:
                            return GrassAndRocks12;
                        case E.GameObject.Flower22:
                            return Flower22;
                        case E.GameObject.Cloud12:
                            return Cloud12;
                        case E.GameObject.Tree21:
                            return Tree21;
                        case E.GameObject.Flower11:
                            return Flower11;
                        case E.GameObject.Navigation:
                            return Navigation;
                        case E.GameObject.Cloud22:
                            return Cloud22;
                        case E.GameObject.Hills1:
                            return Hills1;
                        case E.GameObject.Flower21:
                            return Flower21;
                        case E.GameObject.Flower13:
                            return Flower13;
                        case E.GameObject.Bush3:
                            return Bush3;
                        case E.GameObject.Cloud21:
                            return Cloud21;
                        case E.GameObject.Actors:
                            return Actors;
                        case E.GameObject.Bush1:
                            return Bush1;
                        case E.GameObject.Cloud11:
                            return Cloud11;
                        case E.GameObject.Foreground:
                            return Foreground;
                        case E.GameObject.World:
                            return World;
                        case E.GameObject.Flower14:
                            return Flower14;
                        case E.GameObject.Music:
                            return Music;
                        case E.GameObject.GrassAndRocks21:
                            return GrassAndRocks21;
                        case E.GameObject.Bush2:
                            return Bush2;
                        case E.GameObject.Bush4:
                            return Bush4;
                        case E.GameObject.Tree12:
                            return Tree12;
                        case E.GameObject.Tree11:
                            return Tree11;
                        case E.GameObject.Sky:
                            return Sky;
                        case E.GameObject.Event:
                            return Event;
                        case E.GameObject.GrassAndRocks11:
                            return GrassAndRocks11;
                        case E.GameObject.Background:
                            return Background;
                        case E.GameObject.Text:
                            return Text;
                        case E.GameObject.Canvas:
                            return Canvas;
                        case E.GameObject.Image:
                            return Image;
                        case E.GameObject.StepCount:
                            return StepCount;
                        case E.GameObject.CoinCount:
                            return CoinCount;
                        case E.GameObject.Informations:
                            return Informations;
                        case E.GameObject.LoadingScreenController:
                            return LoadingScreenController;
                        case E.GameObject.Logic:
                            return Logic;
                        case E.GameObject.MainText:
                            return MainText;
                        case E.GameObject.LeftFoot:
                            return LeftFoot;
                        case E.GameObject.LowerBody:
                            return LowerBody;
                        case E.GameObject.RightHand:
                            return RightHand;
                        case E.GameObject.UpperBody:
                            return UpperBody;
                        case E.GameObject.Arms:
                            return Arms;
                        case E.GameObject.RightEye:
                            return RightEye;
                        case E.GameObject.CollectBox:
                            return CollectBox;
                        case E.GameObject.PresenceBox:
                            return PresenceBox;
                        case E.GameObject.Sound:
                            return Sound;
                        case E.GameObject.Player:
                            return Player;
                        case E.GameObject.Torso:
                            return Torso;
                        case E.GameObject.Eyes:
                            return Eyes;
                        case E.GameObject.LoudFootsteps:
                            return LoudFootsteps;
                        case E.GameObject.Foots:
                            return Foots;
                        case E.GameObject.RightFoot:
                            return RightFoot;
                        case E.GameObject.LeftHand:
                            return LeftHand;
                        case E.GameObject.Visual:
                            return Visual;
                        case E.GameObject.RightArm:
                            return RightArm;
                        case E.GameObject.Footsteps:
                            return Footsteps;
                        case E.GameObject.LeftArm:
                            return LeftArm;
                        case E.GameObject.LeftEye:
                            return LeftEye;
                        case E.GameObject.Shine:
                            return Shine;
                        case E.GameObject.Stars:
                            return Stars;
                        case E.GameObject.ShineEffect:
                            return ShineEffect;
                        case E.GameObject.Coin:
                            return Coin;
                        case E.GameObject.Point:
                            return Point;
                        case E.GameObject.PlayerPresenceBox:
                            return PlayerPresenceBox;
                        case E.GameObject.HealthBar:
                            return HealthBar;
                        case E.GameObject.Score:
                            return Score;
                    }
                    return null;
                }

                public static E.GameObject ToEnum(string value)
                {
                    switch (value)
                    {
                        case None:
                            return E.GameObject.None;
                        case Control:
                            return E.GameObject.Control;
                        case Input:
                            return E.GameObject.Input;
                        case MainCamera:
                            return E.GameObject.MainCamera;
                        case EventChannels:
                            return E.GameObject.EventChannels;
                        case Initialization:
                            return E.GameObject.Initialization;
                        case ApplicationController:
                            return E.GameObject.ApplicationController;
                        case Hills2:
                            return E.GameObject.Hills2;
                        case Flower12:
                            return E.GameObject.Flower12;
                        case GameFragmentController:
                            return E.GameObject.GameFragmentController;
                        case Ground:
                            return E.GameObject.Ground;
                        case GrassAndRocks12:
                            return E.GameObject.GrassAndRocks12;
                        case Flower22:
                            return E.GameObject.Flower22;
                        case Cloud12:
                            return E.GameObject.Cloud12;
                        case Tree21:
                            return E.GameObject.Tree21;
                        case Flower11:
                            return E.GameObject.Flower11;
                        case Navigation:
                            return E.GameObject.Navigation;
                        case Cloud22:
                            return E.GameObject.Cloud22;
                        case Hills1:
                            return E.GameObject.Hills1;
                        case Flower21:
                            return E.GameObject.Flower21;
                        case Flower13:
                            return E.GameObject.Flower13;
                        case Bush3:
                            return E.GameObject.Bush3;
                        case Cloud21:
                            return E.GameObject.Cloud21;
                        case Actors:
                            return E.GameObject.Actors;
                        case Bush1:
                            return E.GameObject.Bush1;
                        case Cloud11:
                            return E.GameObject.Cloud11;
                        case Foreground:
                            return E.GameObject.Foreground;
                        case World:
                            return E.GameObject.World;
                        case Flower14:
                            return E.GameObject.Flower14;
                        case Music:
                            return E.GameObject.Music;
                        case GrassAndRocks21:
                            return E.GameObject.GrassAndRocks21;
                        case Bush2:
                            return E.GameObject.Bush2;
                        case Bush4:
                            return E.GameObject.Bush4;
                        case Tree12:
                            return E.GameObject.Tree12;
                        case Tree11:
                            return E.GameObject.Tree11;
                        case Sky:
                            return E.GameObject.Sky;
                        case Event:
                            return E.GameObject.Event;
                        case GrassAndRocks11:
                            return E.GameObject.GrassAndRocks11;
                        case Background:
                            return E.GameObject.Background;
                        case Text:
                            return E.GameObject.Text;
                        case Canvas:
                            return E.GameObject.Canvas;
                        case Image:
                            return E.GameObject.Image;
                        case StepCount:
                            return E.GameObject.StepCount;
                        case CoinCount:
                            return E.GameObject.CoinCount;
                        case Informations:
                            return E.GameObject.Informations;
                        case LoadingScreenController:
                            return E.GameObject.LoadingScreenController;
                        case Logic:
                            return E.GameObject.Logic;
                        case MainText:
                            return E.GameObject.MainText;
                        case LeftFoot:
                            return E.GameObject.LeftFoot;
                        case LowerBody:
                            return E.GameObject.LowerBody;
                        case RightHand:
                            return E.GameObject.RightHand;
                        case UpperBody:
                            return E.GameObject.UpperBody;
                        case Arms:
                            return E.GameObject.Arms;
                        case RightEye:
                            return E.GameObject.RightEye;
                        case CollectBox:
                            return E.GameObject.CollectBox;
                        case PresenceBox:
                            return E.GameObject.PresenceBox;
                        case Sound:
                            return E.GameObject.Sound;
                        case Player:
                            return E.GameObject.Player;
                        case Torso:
                            return E.GameObject.Torso;
                        case Eyes:
                            return E.GameObject.Eyes;
                        case LoudFootsteps:
                            return E.GameObject.LoudFootsteps;
                        case Foots:
                            return E.GameObject.Foots;
                        case RightFoot:
                            return E.GameObject.RightFoot;
                        case LeftHand:
                            return E.GameObject.LeftHand;
                        case Visual:
                            return E.GameObject.Visual;
                        case RightArm:
                            return E.GameObject.RightArm;
                        case Footsteps:
                            return E.GameObject.Footsteps;
                        case LeftArm:
                            return E.GameObject.LeftArm;
                        case LeftEye:
                            return E.GameObject.LeftEye;
                        case Shine:
                            return E.GameObject.Shine;
                        case Stars:
                            return E.GameObject.Stars;
                        case ShineEffect:
                            return E.GameObject.ShineEffect;
                        case Coin:
                            return E.GameObject.Coin;
                        case Point:
                            return E.GameObject.Point;
                        case PlayerPresenceBox:
                            return E.GameObject.PlayerPresenceBox;
                        case HealthBar:
                            return E.GameObject.HealthBar;
                        case Score:
                            return E.GameObject.Score;
                    }
                    throw new ArgumentException("Unable to convert " + value + " to UnityRessources.Enums.GameObject.");
                }
            }
            
            public static class AnimatorParameter
            {
                public const string None = "None";
                public const string HorizontalVelocity = "HorizontalVelocity";
                public const string VerticalVelocity = "VerticalVelocity";
                public const string Blink = "Blink";

                public static string ToString(E.AnimatorParameter value)
                {
                    switch (value)
                    {
                        case E.AnimatorParameter.None:
                            return None;
                        case E.AnimatorParameter.HorizontalVelocity:
                            return HorizontalVelocity;
                        case E.AnimatorParameter.VerticalVelocity:
                            return VerticalVelocity;
                        case E.AnimatorParameter.Blink:
                            return Blink;
                    }
                    return null;
                }

                public static E.AnimatorParameter ToEnum(string value)
                {
                    switch (value)
                    {
                        case None:
                            return E.AnimatorParameter.None;
                        case HorizontalVelocity:
                            return E.AnimatorParameter.HorizontalVelocity;
                        case VerticalVelocity:
                            return E.AnimatorParameter.VerticalVelocity;
                        case Blink:
                            return E.AnimatorParameter.Blink;
                    }
                    throw new ArgumentException("Unable to convert " + value + " to UnityRessources.Enums.AnimatorParameter.");
                }
            }
            
        }
    }
}