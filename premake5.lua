----------------------------------------
-- Build system starts from this file.
----------------------------------------

-- Store workspace root folder:
workspaceFolder = os.getcwd()

include("build_system/BuildConfig.user.lua")

-- Used to retarget VS solution and projects.
-- Returns version of Windows SDK.
getWindowsSDKVersion = function()
    local reg_arch = iif( os.is64bit(), "\\Wow6432Node\\", "\\" )
    local sdk_version = os.getWindowsRegistry( "HKLM:SOFTWARE" .. reg_arch .."Microsoft\\Microsoft SDKs\\Windows\\v10.0\\ProductVersion" )
	if sdk_version ~= nil then return sdk_version end
	return ""
end

-- Workspace configuration:
workspace "BombermanWS"
	-- Place where build files will be generated:
	location "build"
	-- Available configurations and platforms:
	configurations { "Debug", "Release" }
	platforms { "x86", "x64" }
	
	-- Note: this is a workaround. Premake does not automatically retarget MSBuild solutions. 
	filter {"system:windows", "action:vs*"}
    	systemversion(getWindowsSDKVersion() .. ".0")

	-- Setup platforms:
	filter "platforms:*32"
		architecture "x86"

	filter "platforms:*64"
		architecture "x86_64"

	-- Setup configurations:
	filter "configurations:Debug"
		defines { "DEBUG", "_DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"

	
	-- Add project:
	include("build_system/Bomberman.lua")