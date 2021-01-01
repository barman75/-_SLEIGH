
class CfgPatches {

	class jean_sleigh {
		units = {"jean_sleigh"};
		author="jean";
		name="Jean Sleight (signed)";
		weapons = {};
		requiredVersion = 0.100000;
		requiredAddons = {"A3_Air_F", "A3_Anims_F", "A3_Data_F_ParticleEffects", "A3_Sounds_F", "A3_Air_F_Heli_Light_01", "A3Data", "A3_Data_F"};
	};
};

class CfgMovesBasic {
	/*extern*/ class DefaultDie;
	/*extern*/ class Actions;

	class ManActions {
		jean_sleigh_Driver = "jean_sleigh_Driver";
	};
};

class CfgMovesMaleSdr: CfgMovesBasic {

	class States {
		/*extern*/ class Crew;

		class jean_sleigh_Driver_dead: DefaultDie {
			actions = "DeadActions";
			speed = 1;
			looped = "false";
			terminal = 1;
			file = "\jean_sleigh\kia_sleigh_driver.rtm";
			connectTo = {"DeadState", 0.100000};
		};

		class jean_sleigh_Driver: Crew {
			actions = "jean_sleigh_Driver";
			file = "\a3\anims_f\data\Anim\sdr\mov\sit\stp\non\non\AmovPsitMstpSnonWnonDnon_basicGunner";
			interpolateTo = {"jean_sleigh_Driver_dead", 1};
		};
	};

	class Actions: Actions {
		/*extern*/ class CargoActions;

		class jean_sleigh_Driver: CargoActions {
			Die = "jean_sleigh_Driver_dead";
		};
	};
};

class jean_ExhaustsEffectSleigh {

	class Sparkes {
		simulation = "particles";
		type = "jean_SleighSparkle";
	};
};

class CfgCloudlets {
	/*extern*/ class Default;

	class jean_SleighSparkle: Default {
		interval = 0.010000;
		circleRadius = 0;
		circleVelocity = {0, 0, 0};
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 13;
		particleFSFrameCount = 2;
		particleFSLoop = 0;
		angleVar = 360;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 7.500000;
		moveVelocity = {"speedX * 6", "speedY * 6", "speedZ * 6"};
		moveVelocityVar = {0.200000, 1, 0.200000};
		rotationVelocity = 1;
		weight = 1;
		volume = 1;
		rubbing = 0.000000;
		size = {0.100000, 0.100000, 0.100000, 0.100000, 0.100000, 0.080000, 0.080000, 0.080000, 0.080000, 0};
		color = {{1.000000, 1.000000, 1.000000, 1.000000}, {1.000000, 1.000000, 1.000000, 1.000000}, {1.000000, 1.000000, 1.000000, 1.000000}, {1.000000, 1.000000, 1.000000, 1.000000}};
		emissiveColor = {{300.000000, 300.000000, 300.000000, 0.000000}, {0.000000, 0.000000, 0.000000, 0.000000}};
		animationSpeed = {1000};
		randomDirectionPeriod = 0.500000;
		randomDirectionIntensity = 0.550000;
		onTimerScript = "";
		beforeDestroyScript = "";
		blockAIVisibility = 0;
		lifeTimeVar = 1.500000;
		position = {"positionX", "positionY", "positionZ"};
		positionVar = {0.200000, 0.200000, 0};
		rotationVelocityVar = 2;
		sizeVar = 0.040000;
		colorVar = {0, 0.150000, 0.150000, 0};
		randomDirectionPeriodVar = 0.300000;
		randomDirectionIntensityVar = 0.150000;
	};
};

class CfgVehicles {
	/*extern*/ class Helicopter;

	class Helicopter_Base_F: Helicopter {
		/*extern*/ class Turrets;
		/*extern*/ class HitPoints;
	};

	class Helicopter_Base_H: Helicopter_Base_F {
		/*extern*/ class EventHandlers;

		class Turrets: Turrets {
			/*extern*/ class CopilotTurret;
		};
		/*extern*/ class CargoTurret;

		class HitPoints: HitPoints {
			/*extern*/ class HitHull;
			/*extern*/ class HitFuel;
			/*extern*/ class HitEngine;
			/*extern*/ class HitAvionics;
			/*extern*/ class HitVRotor;
			/*extern*/ class HitHRotor;
			/*extern*/ class HitGlass1;
			/*extern*/ class HitGlass2;
			/*extern*/ class HitGlass3;
			/*extern*/ class HitGlass4;
			/*extern*/ class HitGlass5;
			/*extern*/ class HitGlass6;
		};
		/*extern*/ class AnimationSources;
		/*extern*/ class ViewOptics;
		/*extern*/ class RotorLibHelicopterProperties;
	};

	class jean_sleigh: Helicopter_Base_H {
		occludeSoundsWhenIn = 0.562341;
		obstructSoundsWhenIn = 0.316228;
		attenuationEffectType = "OpenHeliAttenuation";
		emptySound = {"", 0, 1};
		soundGeneralCollision1 = {"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_default_int_1", 1.000000, 1, 100};
		soundGeneralCollision2 = {"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_default_int_2", 1.000000, 1, 100};
		soundGeneralCollision3 = {"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_default_int_3", 1.000000, 1, 100};
		soundCrashes = {"soundGeneralCollision1", 0.330000, "soundGeneralCollision2", 0.330000, "soundGeneralCollision3", 0.330000};
		soundLandCrashes = {"emptySound", 0};
		soundBuildingCrash = {"soundGeneralCollision1", 1, "soundGeneralCollision2", 1, "soundGeneralCollision3", 1};
		soundArmorCrash = {"soundGeneralCollision1", 1, "soundGeneralCollision2", 1, "soundGeneralCollision3", 1};
		soundWoodCrash = {"soundGeneralCollision1", 1, "soundGeneralCollision2", 1, "soundGeneralCollision3", 1};
		soundBushCollision1 = {"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_1", 1.000000, 1, 100};
		soundBushCollision2 = {"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_2", 1.000000, 1, 100};
		soundBushCollision3 = {"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_3", 1.000000, 1, 100};
		soundBushCrash = {"soundBushCollision1", 0.330000, "soundBushCollision2", 0.330000, "soundBushCollision3", 0.330000};
		soundWaterCollision1 = {"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_water_ext_1", 1.000000, 1, 100};
		soundWaterCollision2 = {"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_water_ext_2", 1.000000, 1, 100};
		soundWaterCrashes = {"soundWaterCollision1", 0.500000, "soundWaterCollision2", 0.500000};
		soundDammage = {"A3\Sounds_F\vehicles\crashes\helis\Heli_crash_default_ext_1", 3.162278, 1};
		soundGetIn = {"A3\Sounds_F\vehicles\air\noises\heli_get_in2", 0.562341, 1};
		soundGetOut = {"A3\Sounds_F\vehicles\air\noises\heli_get_out2", 0.794328, 1, 20};
		soundEngineOnInt = {"jean\jean_sleigh\sleigh_engine_on", 0.316228, 1.000000};
		soundEngineOnExt = {"jean\jean_sleigh\sleigh_engine_on", 0.794328, 1.000000, 600};
		soundEngineOffInt = {"jean\jean_sleigh\sleigh_engine_off", 0.316228, 1.000000};
		soundEngineOffExt = {"jean\jean_sleigh\sleigh_engine_off", 0.794328, 1.000000, 600};
		soundLocked = {"\A3\Sounds_F\weapons\Rockets\opfor_lock_1", 1.000000, 1};
		soundIncommingMissile = {"\A3\Sounds_F\weapons\Rockets\opfor_lock_2", 1.000000, 1};
		rotorDamageInt = {"A3\Sounds_F\vehicles\air\noises\heli_damage_rotor_int_open_1", 1.000000, 1.000000};
		rotorDamageOut = {"A3\Sounds_F\vehicles\air\noises\heli_damage_rotor_ext_1", 2.511886, 1.000000, 150};
		rotorDamage = {"rotorDamageInt", "rotorDamageOut"};
		tailDamageInt = {"A3\Sounds_F\vehicles\air\noises\heli_damage_tail", 1.000000, 1.000000};
		tailDamageOut = {"A3\Sounds_F\vehicles\air\noises\heli_damage_tail", 1.000000, 1.000000, 300};
		tailDamage = {"tailDamageInt", "tailDamageOut"};
		landingSoundInt0 = {"A3\Sounds_F\vehicles\air\noises\landing_skids_int1_open", 1.000000, 1.000000, 100};
		landingSoundInt1 = {"A3\Sounds_F\vehicles\air\noises\landing_skids_int1_open", 1.000000, 1.000000, 100};
		landingSoundInt = {"landingSoundInt0", 0.500000, "landingSoundInt1", 0.500000};
		landingSoundOut0 = {"A3\Sounds_F\vehicles\air\noises\landing_skids_ext1", 1.778279, 1.000000, 100};
		landingSoundOut1 = {"A3\Sounds_F\vehicles\air\noises\landing_skids_ext1", 1.778279, 1.000000, 100};
		landingSoundOut = {"landingSoundOut0", 0.500000, "landingSoundOut1", 0.500000};
		slingCargoAttach0 = {"A3\Sounds_F\vehicles\air\noises\SL_engineDownEndINT", 1.000000, 1.000000};
		slingCargoAttach1 = {"A3\Sounds_F\vehicles\air\noises\SL_1hookLock", 1.000000, 1.000000, 80};
		slingCargoAttach = {"slingCargoAttach0", "slingCargoAttach1"};
		slingCargoDetach0 = {"A3\Sounds_F\vehicles\air\noises\SL_engineUpEndINT", 1.000000, 1.000000};
		slingCargoDetach1 = {"A3\Sounds_F\vehicles\air\noises\SL_1hookUnlock", 1.000000, 1.000000, 80};
		slingCargoDetach = {"slingCargoDetach0", "slingCargoDetach1"};
		slingCargoDetachAir0 = {"A3\Sounds_F\vehicles\air\noises\SL_unhook_air_int", 1.000000, 1.000000};
		slingCargoDetachAir1 = {"A3\Sounds_F\vehicles\air\noises\SL_unhook_air_ext", 1.000000, 1.000000, 80};
		slingCargoDetachAir = {"slingCargoDetach0", "slingCargoDetach1"};
		slingCargoRopeBreak0 = {"A3\Sounds_F\vehicles\air\noises\SL_rope_break_int", 1.000000, 1.000000};
		slingCargoRopeBreak1 = {"A3\Sounds_F\vehicles\air\noises\SL_rope_break_ext", 1.000000, 1.000000, 80};
		slingCargoRopeBreak = {"slingCargoDetach0", "slingCargoDetach1"};

		class Sounds {

			class EngineExt {
				sound = {"jean\jean_sleigh\sleigh_engine", 1.258925, 1.000000, 400};
				frequency = "rotorSpeed";
				volume = "4 * camPos * (0 max (rotorSpeed-0.4))";
			};

			class EngineInt {
				sound = {"jean\jean_sleigh\sleigh_engine", 0.794328, 1.000000};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*2*(0 max (rotorSpeed-0.4))";
			};

			class WindBench {
				sound = {"A3\Sounds_F\vehicles\air\noises\wind_open_out", 0.562341, 1.000000, 50};
				frequency = 1;
				volume = "4 * (playerPos factor [3.9, 4]) * (1 - camPos) * ((speed factor[0, 30]) + (speed factor[0, -30]))";
			};

			class TransmissionDamageExt_phase1 {
				sound = {"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_1", 1.000000, 1.000000, 150};
				frequency = "0.66 + rotorSpeed / 3";
				volume = "camPos * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
			};

			class TransmissionDamageExt_phase2 {
				sound = {"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_2", 1.000000, 1.000000, 150};
				frequency = "0.66 + rotorSpeed / 3";
				volume = "camPos * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
			};

			class TransmissionDamageInt_phase1 {
				sound = {"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_1", 1.000000, 1.000000, 150};
				frequency = "0.66 + rotorSpeed / 3";
				volume = "(1 - camPos) * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
			};

			class TransmissionDamageInt_phase2 {
				sound = {"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_2", 1.000000, 1.000000, 150};
				frequency = "0.66 + rotorSpeed / 3";
				volume = "(1 - camPos) * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
			};

			class damageAlarmInt {
				sound = {"A3\Sounds_F\vehicles\air\noises\heli_alarm_bluefor", 0.316228, 1.000000};
				frequency = 1;
				volume = "engineOn * (1 - camPos) * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0.0, 0.001])";
			};

			class damageAlarmExt {
				sound = {"A3\Sounds_F\vehicles\air\noises\heli_alarm_bluefor", 0.223872, 1.000000, 20};
				frequency = 1;
				volume = "engineOn * camPos * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0, 0.001])";
			};

			class rotorLowAlarmInt {
				sound = {"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low", 0.316228, 1.000000};
				frequency = 1;
				volume = "engineOn * (1 - camPos) * (rotorSpeed factor [0.9, 0.8999]) * (rotorSpeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
			};

			class rotorLowAlarmExt {
				sound = {"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low", 0.223872, 1.000000, 20};
				frequency = 1;
				volume = "engineOn * camPos * (rotorSpeed factor [0.9, 0.8999]) * (rotorSpeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
			};

			class scrubLandInt {
				sound = {"A3\Sounds_F\vehicles\air\noises\scrubLandInt_open", 1.000000, 1.000000, 100};
				frequency = 1;
				volume = "2 * (1-camPos) * (scrubLand factor[0.02, 0.05])";
			};

			class scrubLandExt {
				sound = {"A3\Sounds_F\vehicles\air\noises\scrubLandExt", 1.000000, 1.000000, 100};
				frequency = 1;
				volume = "camPos * (scrubLand factor[0.02, 0.05])";
			};

			class scrubBuildingInt {
				sound = {"A3\Sounds_F\vehicles\air\noises\scrubBuildingInt", 1.000000, 1.000000, 100};
				frequency = 1;
				volume = "2 * (1 - camPos) * (scrubBuilding factor[0.02, 0.05])";
			};

			class scrubBuildingExt {
				sound = {"A3\Sounds_F\vehicles\air\noises\scrubBuildingExt", 1.000000, 1.000000, 100};
				frequency = 1;
				volume = "camPos * (scrubBuilding factor[0.02, 0.05])";
			};

			class scrubTreeInt {
				sound = {"A3\Sounds_F\vehicles\air\noises\scrubTreeExt", 1.000000, 1.000000, 100};
				frequency = 1;
				volume = "(1 - camPos) * ((scrubTree) factor [0, 0.01])";
			};

			class scrubTreeExt {
				sound = {"A3\Sounds_F\vehicles\air\noises\scrubTreeExt", 1.000000, 1.000000, 100};
				frequency = 1;
				volume = "camPos * ((scrubTree) factor [0, 0.01])";
			};

			class RainExt {
				sound = {"A3\Sounds_F\vehicles\noises\rain1_ext", 1.000000, 1.000000, 100};
				frequency = 1;
				volume = "camPos * (rain - rotorSpeed/2) * 2";
			};

			class RainInt {
				sound = {"A3\Sounds_F\vehicles\noises\rain1_int_open", 1.000000, 1.000000, 100};
				frequency = 1;
				volume = "(1-camPos)*(rain - rotorSpeed/2)*2";
			};

			class SlingLoadDownExt {
				sound = {"A3\Sounds_F\vehicles\air\noises\SL_engineDownEXT", 1.000000, 1.000000, 500};
				frequency = 1;
				volume = "camPos*(slingLoadActive factor [0,-1])";
			};

			class SlingLoadUpExt {
				sound = {"A3\Sounds_F\vehicles\air\noises\SL_engineUpEXT", 1.000000, 1.000000, 500};
				frequency = 1;
				volume = "camPos*(slingLoadActive factor [0,1])";
			};

			class SlingLoadDownInt {
				sound = {"A3\Sounds_F\vehicles\air\noises\SL_engineDownINT", 1.000000, 1.000000, 500};
				frequency = 1;
				volume = "(1-camPos)*(slingLoadActive factor [0,-1])";
			};

			class SlingLoadUpInt {
				sound = {"A3\Sounds_F\vehicles\air\noises\SL_engineUpINT", 1.000000, 1.000000, 500};
				frequency = 1;
				volume = "(1-camPos)*(slingLoadActive factor [0,1])";
			};

			class WindInt {
				sound = {"A3\Sounds_F\vehicles\air\noises\wind_open_int", 1.122018, 1.000000, 50};
				frequency = 1;
				volume = "(1-camPos)*(speed factor[5, 50])*(speed factor[5, 50])";
			};

			class WindLateralMovementInt {
				sound = {"A3\Sounds_F\vehicles\air\noises\wind_lateral_open_int", 1.995262, 1.000000, 50};
				frequency = 1;
				volume = "(1-camPos)*lateralMovement*((speed factor [5,40]) + (speed factor [-5,-40]))";
			};

			class GStress {
				sound = {"A3\Sounds_F\vehicles\noises\vehicle_stress2b", 0.316228, 1.000000, 50};
				frequency = 1;
				volume = "engineOn * (1-camPos) * ((gmeterZ factor[1.5, 2.5]) + (gmeterZ factor[0.5, -0.5]))";
			};
		};

		class SoundsExt {

			class SoundEvents {
			};

			class Sounds {

				class EngineExt {
					sound = {"jean\jean_sleigh\sleigh_engine", 1.258925, 1.000000, 400};
					frequency = "rotorSpeed";
					volume = "4 * camPos * (0 max (rotorSpeed-0.4))";
				};

				class EngineInt {
					sound = {"jean\jean_sleigh\sleigh_engine", 0.794328, 1.000000};
					frequency = "rotorSpeed";
					volume = "(1-camPos)*2*(0 max (rotorSpeed-0.4))";
				};

				class WindBench {
					sound = {"A3\Sounds_F\vehicles\air\noises\wind_open_out", 0.562341, 1.000000, 50};
					frequency = 1;
					volume = "4 * (playerPos factor [3.9, 4]) * (1 - camPos) * ((speed factor[0, 30]) + (speed factor[0, -30]))";
				};

				class TransmissionDamageExt_phase1 {
					sound = {"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_1", 1.000000, 1.000000, 150};
					frequency = "0.66 + rotorSpeed / 3";
					volume = "camPos * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
				};

				class TransmissionDamageExt_phase2 {
					sound = {"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_2", 1.000000, 1.000000, 150};
					frequency = "0.66 + rotorSpeed / 3";
					volume = "camPos * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
				};

				class TransmissionDamageInt_phase1 {
					sound = {"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_1", 1.000000, 1.000000, 150};
					frequency = "0.66 + rotorSpeed / 3";
					volume = "(1 - camPos) * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
				};

				class TransmissionDamageInt_phase2 {
					sound = {"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_2", 1.000000, 1.000000, 150};
					frequency = "0.66 + rotorSpeed / 3";
					volume = "(1 - camPos) * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
				};

				class damageAlarmInt {
					sound = {"A3\Sounds_F\vehicles\air\noises\heli_alarm_bluefor", 0.316228, 1.000000};
					frequency = 1;
					volume = "engineOn * (1 - camPos) * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0.0, 0.001])";
				};

				class damageAlarmExt {
					sound = {"A3\Sounds_F\vehicles\air\noises\heli_alarm_bluefor", 0.223872, 1.000000, 20};
					frequency = 1;
					volume = "engineOn * camPos * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0, 0.001])";
				};

				class rotorLowAlarmInt {
					sound = {"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low", 0.316228, 1.000000};
					frequency = 1;
					volume = "engineOn * (1 - camPos) * (rotorSpeed factor [0.9, 0.8999]) * (rotorSpeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
				};

				class rotorLowAlarmExt {
					sound = {"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low", 0.223872, 1.000000, 20};
					frequency = 1;
					volume = "engineOn * camPos * (rotorSpeed factor [0.9, 0.8999]) * (rotorSpeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
				};

				class scrubLandInt {
					sound = {"A3\Sounds_F\vehicles\air\noises\scrubLandInt_open", 1.000000, 1.000000, 100};
					frequency = 1;
					volume = "2 * (1-camPos) * (scrubLand factor[0.02, 0.05])";
				};

				class scrubLandExt {
					sound = {"A3\Sounds_F\vehicles\air\noises\scrubLandExt", 1.000000, 1.000000, 100};
					frequency = 1;
					volume = "camPos * (scrubLand factor[0.02, 0.05])";
				};

				class scrubBuildingInt {
					sound = {"A3\Sounds_F\vehicles\air\noises\scrubBuildingInt", 1.000000, 1.000000, 100};
					frequency = 1;
					volume = "2 * (1 - camPos) * (scrubBuilding factor[0.02, 0.05])";
				};

				class scrubBuildingExt {
					sound = {"A3\Sounds_F\vehicles\air\noises\scrubBuildingExt", 1.000000, 1.000000, 100};
					frequency = 1;
					volume = "camPos * (scrubBuilding factor[0.02, 0.05])";
				};

				class scrubTreeInt {
					sound = {"A3\Sounds_F\vehicles\air\noises\scrubTreeExt", 1.000000, 1.000000, 100};
					frequency = 1;
					volume = "(1 - camPos) * ((scrubTree) factor [0, 0.01])";
				};

				class scrubTreeExt {
					sound = {"A3\Sounds_F\vehicles\air\noises\scrubTreeExt", 1.000000, 1.000000, 100};
					frequency = 1;
					volume = "camPos * ((scrubTree) factor [0, 0.01])";
				};

				class RainExt {
					sound = {"A3\Sounds_F\vehicles\noises\rain1_ext", 1.000000, 1.000000, 100};
					frequency = 1;
					volume = "camPos * (rain - rotorSpeed/2) * 2";
				};

				class RainInt {
					sound = {"A3\Sounds_F\vehicles\noises\rain1_int_open", 1.000000, 1.000000, 100};
					frequency = 1;
					volume = "(1-camPos)*(rain - rotorSpeed/2)*2";
				};

				class SlingLoadDownExt {
					sound = {"A3\Sounds_F\vehicles\air\noises\SL_engineDownEXT", 1.000000, 1.000000, 500};
					frequency = 1;
					volume = "camPos*(slingLoadActive factor [0,-1])";
				};

				class SlingLoadUpExt {
					sound = {"A3\Sounds_F\vehicles\air\noises\SL_engineUpEXT", 1.000000, 1.000000, 500};
					frequency = 1;
					volume = "camPos*(slingLoadActive factor [0,1])";
				};

				class SlingLoadDownInt {
					sound = {"A3\Sounds_F\vehicles\air\noises\SL_engineDownINT", 1.000000, 1.000000, 500};
					frequency = 1;
					volume = "(1-camPos)*(slingLoadActive factor [0,-1])";
				};

				class SlingLoadUpInt {
					sound = {"A3\Sounds_F\vehicles\air\noises\SL_engineUpINT", 1.000000, 1.000000, 500};
					frequency = 1;
					volume = "(1-camPos)*(slingLoadActive factor [0,1])";
				};

				class WindInt {
					sound = {"A3\Sounds_F\vehicles\air\noises\wind_open_int", 1.122018, 1.000000, 50};
					frequency = 1;
					volume = "(1-camPos)*(speed factor[5, 50])*(speed factor[5, 50])";
				};

				class WindLateralMovementInt {
					sound = {"A3\Sounds_F\vehicles\air\noises\wind_lateral_open_int", 1.995262, 1.000000, 50};
					frequency = 1;
					volume = "(1-camPos)*lateralMovement*((speed factor [5,40]) + (speed factor [-5,-40]))";
				};

				class GStress {
					sound = {"A3\Sounds_F\vehicles\noises\vehicle_stress2b", 0.316228, 1.000000, 50};
					frequency = 1;
					volume = "engineOn * (1-camPos) * ((gmeterZ factor[1.5, 2.5]) + (gmeterZ factor[0.5, -0.5]))";
				};
			};
		};
		scope = 2;
		author = "jean";
		_generalMacro = "jean_sleigh_base";
		displayName = "Sleigh";
		model = "\jean_sleigh\sleigh.p3d";
		driveOnComponent = {"Skids"};
		picture = "A3\Air_F\Heli_Light_01\Data\UI\Heli_Light_01_CA.paa";
		icon = "\A3\Air_F\Heli_Light_01\Data\UI\Map_Heli_Light_01_CA.paa";
		accuracy = 0.500000;
		nameSound = "veh_helicopter";

		class MFD {
		};
		fuelCapacity = 242;
		fuelConsumptionRate = 0.032200;
		maxFordingDepth = 0.650000;
		mainBladeCenter = "rotor_center";
		mainBladeRadius = 0.500000;
		tailBladeCenter = "rotor_tail_center";
		tailBladeRadius = 0.100000;
		tailBladeVertical = 1;
		backRotorForceCoef = 3;

		class RotorLibHelicopterProperties: RotorLibHelicopterProperties {
			RTDconfig = "A3\Air_F\Heli_Light_01\RTD_Heli_Light_01.xml";
			autoHoverCorrection = {0.280000, 2.880000, 0};
			defaultCollective = 0.635000;
			maxTorque = 900;
			stressDamagePerSec = 0.003333;
			maxHorizontalStabilizerLeftStress = 10000;
			maxHorizontalStabilizerRightStress = 10000;
			maxVerticalStabilizerStress = 10000;
			horizontalWingsAngleCollMin = 0;
			horizontalWingsAngleCollMax = 0;
			maxMainRotorStress = 31000;
			maxTailRotorStress = 5200;
			retreatBladeStallWarningSpeed = 77.222000;
		};
		maxSpeed = 245;
		slingLoadMaxCargoMass = 500;
		slingLoadMemoryPoint = "slingLoad0";
		radarType = 8;
		liftForceCoef = 1.500000;
		cyclicAsideForceCoef = 1.300000;
		cyclicForwardForceCoef = 1.000000;
		bodyFrictionCoef = 0.300000;
		preciseGetInOut = 0;
		cargoPreciseGetInOut = {0};
		driverAction = "jean_sleigh_Driver";
		getInAction = "ChopperLight_L_In_H";
		getOutAction = "GetOutLow";
		memoryPointsGetInCargo = {};
		memoryPointsGetInCargoDir = {};
		usePreciseGetInAction = 0;
		memoryPointsGetInDriverPrecise = "GetIn_Pilot";
		memoryPointsGetInCargoPrecise = {"GetIn_Cargo", "GetIn_Cargo2"};
		cargoGetInAction = {"GetInLow"};
		cargoGetOutAction = {"GetOutLow"};
		typicalCargo = {"B_HeliPilot_F"};
		cargoAction = {};
		transportSoldier = 2;
		maximumLoad = 1000;

		class TransportBackpacks {

			class _xx_B_Parachute {
				backpack = "B_Parachute";
				count = 4;
			};
		};

		class TransportMagazines {
		};

		class TransportWeapons {
		};

		class TransportItems {

			class _xx_FirstAidKit {
				name = "FirstAidKit";
				count = 2;
			};
		};
		threat = {0, 0, 0};
		driverCanSee = 31;
		extCameraPosition = {0, 2, -15};

		class ViewOptics: ViewOptics {
			initAngleX = 0;
			minAngleX = -30;
			maxAngleX = 30;
			initAngleY = 0;
			minAngleY = -86;
			maxAngleY = 86;
			minFov = 0.250000;
			maxFov = 1.250000;
			initFov = 0.750000;
		};
		gunnerUsesPilotView = 1;
		castCargoShadow = 1;
		LockDetectionSystem = 8;
		irScanRangeMax = 10000;
		cameraBegin = "rtd1_pos";
		cameraEnd = "rtd1_dir";

		class RenderTargets {
		};

		class Reflectors {

			class Right {
				color = {7000, 7500, 10000};
				ambient = {70, 75, 100};
				intensity = 50;
				size = 1;
				innerAngle = 15;
				outerAngle = 65;
				coneFadeCoef = 10;
				position = "Light_pos";
				direction = "Light_dir";
				hitpoint = "Light_hitpoint";
				selection = "Light";
				useFlare = 1;
				flareSize = 10;
				flareMaxDistance = 250;
				dayLight = 0;

				class Attenuation {
					start = 0;
					constant = 0;
					linear = 1;
					quadratic = 1;
					hardLimitStart = 100;
					hardLimitEnd = 200;
				};
			};
		};

		class Exhausts {

			class Exhaust1 {
				position = "exhaust1";
				direction = "exhaust1_dir";
				effect = "jean_ExhaustsEffectSleigh";
			};

			class Exhaust2 {
				position = "exhaust2";
				direction = "exhaust2_dir";
				effect = "jean_ExhaustsEffectSleigh";
			};
		};
		armor = 100;
		damageResistance = 0.010390;
		epeImpulseDamageCoef = 20;

		class HitPoints: HitPoints {

			class HitFuel: HitFuel {
				visual = "";
				radius = 0.100000;
				explosionShielding = 2;
			};

			class HitHull: HitHull {
				armor = 999;
				visual = "zbytek";
				depends = "Total";
				radius = 0.010000;
			};

			class HitEngine: HitEngine {
				visual = "";
				radius = 0.200000;
				explosionShielding = 2;
			};

			class HitAvionics: HitAvionics {
				armor = 1;
				visual = "";
				radius = 0.500000;
				explosionShielding = 2;
			};

			class HitHRotor: HitHRotor {
				visual = "main rotor static";
				armor = 3;
				radius = 0.300000;
				explosionShielding = 2.500000;
			};

			class HitVRotor: HitVRotor {
				visual = "tail rotor static";
				armor = 2;
				radius = 0.060000;
				explosionShielding = 6;
			};

			class HitGlass1: HitGlass1 {
				armor = 0.500000;
				radius = 0.150000;
			};

			class HitGlass2: HitGlass2 {
				armor = 0.500000;
				radius = 0.150000;
			};

			class HitGlass3: HitGlass3 {
				armor = 0.500000;
				radius = 0.150000;
			};

			class HitGlass4: HitGlass4 {
				armor = 0.500000;
				radius = 0.150000;
			};
		};

		class Damage {
			tex = {};
			mat = {"A3\Air_F\Heli_Light_01\Data\Heli_Light_01_ext.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_ext_damage.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_ext_destruct.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_ext_UNIColor.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_ext_UNIColor_damage.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_ext_UNIColor_destruct.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_glass.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_glass_damage.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_glass_damage.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_glass_in.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_glass_damage.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_glass_damage.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_int.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_int_damage.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_int_destruct.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_detail.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_detail_damage.rvmat", "A3\Air_F\Heli_Light_01\Data\Heli_Light_01_detail_destruct.rvmat"};
		};

		class AnimationSources: AnimationSources {
		};

		class Turrets: Turrets {

			class CopilotTurret: CopilotTurret {
				gunnerAction = "jean_sleigh_Driver";
				gunnerInAction = "Chopperlight_R_Static_H";
				weapons = {};
				magazines = {};
				gunnerGetInAction = "Chopperlight_R_In_H";
				gunnergetOutAction = "GetOutLow";
				usePreciseGetInAction = 0;
				memoryPointsGetInGunnerPrecise = "GetIn_Turret";
				preciseGetInOut = 0;
				canEject = 0;
				isPersonTurret = 0;
				personTurretAction = "vehicle_coshooter_1";
				maxElev = 15;
				minElev = -60;
				maxTurn = -20;
				minTurn = -105;

				class dynamicViewLimits {
					CargoTurret_01 = {-70, -20};
				};
				ejectDeadGunner = 0;
			};

			class CargoTurret_01: CargoTurret {
				gunnerAction = "passenger_inside_3";
				gunnerCompartments = "Compartment1";
				memoryPointsGetInGunner = "pos cargo L";
				memoryPointsGetInGunnerDir = "pos cargo L dir";
				gunnerName = "Passenger (Left)";
				proxyIndex = 1;
				maxElev = 0;
				minElev = 0;
				maxTurn = 0;
				minTurn = 0;
				isPersonTurret = 1;
				ejectDeadGunner = 0;

				class TurnIn {
					limitsArrayTop = {{45, -20}, {45, 90}};
					limitsArrayBottom = {{-10, -15}, {-10, 7}, {-10, 15}, {-50, 20}, {-50, 110}};
				};
			};

			class CargoTurret_02: CargoTurret {
				gunnerAction = "passenger_inside_3";
				gunnerCompartments = "Compartment1";
				memoryPointsGetInGunner = "pos cargo R";
				memoryPointsGetInGunnerDir = "pos cargo R dir";
				gunnerName = "Passenger (Right)";
				proxyIndex = 2;
				maxElev = 0;
				minElev = 0;
				maxTurn = 0;
				minTurn = 0;
				isPersonTurret = 1;
				ejectDeadGunner = 0;

				class TurnIn {
					limitsArrayTop = {{45, -90}, {45, 20}};
					limitsArrayBottom = {{-50, -110}, {-50, -20}, {-10, -15}, {-10, -7}, {-10, 15}};
				};
			};
		};
		hiddenSelections = {};
		hiddenSelectionsTextures = {};

		class Armory {
		};
		cargoCanEject = 1;
		driverCanEject = 1;
		ejectDeadCargo = 0;

		class pilotCamera {

			class OpticsIn {

				class Wide {
					opticsDisplayName = "W";
					initAngleX = 0;
					minAngleX = 0;
					maxAngleX = 0;
					initAngleY = 0;
					minAngleY = 0;
					maxAngleY = 0;
					initFov = 0.500000;
					minFov = 0.500000;
					maxFov = 0.500000;
					directionStabilized = 1;
					visionMode = {"Normal", "NVG"};
					thermalMode = {0, 1};
					gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
				};
				showMiniMapInOptics = 0;
				showUAVViewpInOptics = 0;
				showSlingLoadManagerInOptics = 1;
			};
			minTurn = 0;
			maxTurn = 0;
			initTurn = 0;
			minElev = 80;
			maxElev = 80;
			initElev = 80;
			maxXRotSpeed = 0.500000;
			maxYRotSpeed = 0.500000;
			pilotOpticsShowCursor = 1;
			controllable = 0;
		};

		class EventHandlers: EventHandlers {
		};
		memoryPointDriverOptics = "slingCamera";
	};
};
