class CfgFunctions
{
	class CBA
	{
		class Vectors
		{
			// CBA_fnc_vectAdd
			class vectAdd
			{
				description = "Returns the sum of two vectors.  Vectors can be 2D or 3D.";
				file = "\x\cba\addons\vectors\fnc_vectAdd.sqf";
			};
			// CBA_fnc_vectDir
			class vectDir
			{
				description = "Returns the angle of a vector with the given i and k coordinates in the range 0 to 360.";
				file = "\x\cba\addons\vectors\fnc_vectDir.sqf";
			};
			// CBA_fnc_vectElev
			class vectElev
			{
				description = "Returns the angle of elevation of a 3D vector with the given i, j and k coordinates in the range -90 to 90.";
				file = "\x\cba\addons\vectors\fnc_vectElev.sqf";
			};
			// CBA_fnc_polar2vect
			class polar2vect
			{
				description = "Creates a vector based on a inputted magnitude, direction and elevation  ";
				file = "\x\cba\addons\vectors\fnc_polar2vect.sqf";
			};
			// CBA_fnc_vectMagn
			class vectMagn
			{
				description = "Returns the magnitude of a 3D vector with the given i, j and k coordinates.";
				file = "\x\cba\addons\vectors\fnc_vectMagn.sqf";
			};
			// CBA_fnc_vect2polar
			class vect2polar
			{
				description = "Parameters:";
				file = "\x\cba\addons\vectors\fnc_vect2polar.sqf";
			};
			// CBA_fnc_simplifyAngle
			class simplifyAngle
			{
				description = "Returns an equivalent angle to the specified angle in the range 0 to 360. This allows adjustment from negative angles and angles equal or greater to 360. If the inputted angle is in the range 0 - 360, it will be returned unchanged.";
				file = "\x\cba\addons\vectors\fnc_simplifyAngle.sqf";
			};
			// CBA_fnc_simplifyAngle180
			class simplifyAngle180
			{
				description = "Returns an equivalent angle to the specified angle in the range -180 to 180. If the inputted angle is in the range -180 to 180, it will be returned unchanged.";
				file = "\x\cba\addons\vectors\fnc_simplifyAngle180.sqf";
			};
			// CBA_fnc_scaleVect
			class scaleVect
			{
				description = "Scales a specified vector by a specified factor.";
				file = "\x\cba\addons\vectors\fnc_scaleVect.sqf";
			};
			// CBA_fnc_vectCross
			class vectCross
			{
				description = " Returns the cross product vector of two vectors.  Vectors must both be three dimensional.";
				file = "\x\cba\addons\vectors\fnc_vectCross.sqf";
			};
			// CBA_fnc_vectCross2D
			class vectCross2D
			{
				description = "Returns the cross product vector of two 2D vectors. The result is an integer value (positive or negative), representing the magnitude of the height component.";
				file = "\x\cba\addons\vectors\fnc_vectCross2D.sqf";
			};
			// CBA_fnc_vectDot
			class vectDot
			{
				description = "Returns the dot product of two vectors.  Vectors can be either two or three dimesions, but they must be the same dimension.";
				file = "\x\cba\addons\vectors\fnc_vectDot.sqf";
			};
			// CBA_fnc_vectMagn2D
			class vectMagn2D
			{
				description = "Returns the magnitude of a vector with the given i and k coordinates or the magnitude of the i and k components of a 3D vector.";
				file = "\x\cba\addons\vectors\fnc_vectMagn2D.sqf";
			};
			// CBA_fnc_vectSubtract
			class vectSubtract
			{
				description = "Returns the difference of two vectors.  Vectors can be 2D or 3D.";
				file = "\x\cba\addons\vectors\fnc_vectSubtract.sqf";
			};
		};
	};
};
