#include "script_component.hpp"
/* ----------------------------------------------------------------------------
Function: CBA_fnc_switchPlayer

Description:
    Switch player to another unit.

Parameters:
    [type] The type of the new unit the player should switch to [String]

    Optional:
    [type, "LEAVEWEAPS"] - switch to new unit of the given type, but keep
                              the weapons the player had before.


    NOTE: the function must be spawned. It cannot be called.

Returns:
    nil

Examples:
    (begin example)
    // Change into a M136 AT rifleman
    _h = ["USMC_Soldier_LAT"] spawn CBA_fnc_switchPlayer;

    // Switch into a corpsman, but keep the weapons
    _h = ["USMC_Soldier_Medic", "LEAVEWEAPS"] spawn CBA_fnc_switchPlayer;
    (end)

Author:

---------------------------------------------------------------------------- */
SCRIPT(switchPlayer);

params ["_type"];
private _oldUnit = player;

private _ar = [weapons _oldUnit, magazines _oldUnit, rank _oldUnit, score _oldUnit, group _oldUnit, getPos _oldUnit, (leader _oldUnit) == _oldUnit, vehicleVarName _oldUnit];

private _dummyGroup = createGroup (side _oldUnit);
if (isNull _dummyGroup) exitWith { hint "Sorry, something went wrong, dummyGroup is null" };
_dummyUnit = (_ar select 4) createUnit [_type, [0, 0, 0], [], 0, "NONE"]; // Join in the old group incase there was only 1 member
if (isNull _dummyUnit) exitWith { hint "Sorry, something went wrong, dummyUnit is null" };
[_oldUnit] join _dummyGroup;

LOG_1("1.Dummy created, State saved and put oldUnit in new group: %1", _dummyGroup);

private _newUnit = _dummyGroup createUnit [_type, _ar select 5, [], 0, "NONE"];

if (isNull _newUnit) exitWith { hint "Sorry, something went wrong, newUnit is null" };

LOG_1("2.New unit created, local: %1", local _newUnit);
sleep 1;

addSwitchableUnit _newUnit;
selectPlayer _newUnit;

_newUnit setRank (_ar select 2);
_newUnit addScore (_ar select 3);

LOG_1("3.State transfered, switched player control to new unit, local: %1", local _newUnit);
sleep 1;
if (_ar select 7 != "") then
{
    ["CBA_setVehicleVarName", [_oldUnit, _newUnit, (_ar select 7)]] call  CBA_fnc_globalEvent;
};

if ("LEAVEWEAPS" in _this) then
{
    sleep 1;
} else {
    removeAllWeapons _newUnit;
    { _newUnit addMagazine _x } forEach (_ar select 1);
    { _newUnit addWeapon _x } forEach (_ar select 0);
};
if ((primaryWeapon _newUnit) != "") then { [_newUnit, primaryWeapon _newUnit] call CBA_fnc_selectWeapon };

LOG("4.Weapons switched on new unit");
sleep 1;

[_newUnit] join (_ar select 4);
//removeSwitchableUnit _newUnit;

LOG("5.New Unit joined in original group");
sleep 1;

{ deleteVehicle _x } forEach [_oldUnit, _dummyUnit]; // Might have to remote execute this to be successfull in MP

LOG("6.Deleted and moved away dummy units etc");
sleep 1;

if (_ar select 6) then { (group _newUnit) selectLeader _newUnit };
