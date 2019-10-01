include("AddSFML.lua")

project "Bomberman"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++11"
	
	-- "workspaceFolder" is defined in premake5.lua
	-- Place build files in workspaceFolder/build/projectName
	location ( path.join( workspaceFolder, "build/%{prj.name}") )
	-- Place binary files in workspaceFolder/bin/platformName/configurationName
	targetdir ( path.join( workspaceFolder, "bin/%{cfg.platform}/%{cfg.buildcfg}") )

	includedirs {
		"../include"
	}

	local sfmlOptions = {
			modules	= { 
					graphics 	= true,
					window 		= true,
					audio 		= true,
					network 	= true,
					system		= true
				},
			root 		= userConfig.deps.sfml.root,
			linkDynamic = userConfig.deps.sfml.dynamic,
			pre250Version = userConfig.deps.sfml.pre250Version or false
		}
	sfmlOptions.libDir = path.join(sfmlOptions.root, "lib/%{cfg.platform}/%{cfg.buildcfg}")
	

	-- Add SFML (debug version)
	filter "configurations:Debug"
		defines { "BOMBERMAN_DEBUG "}
		addSFML( sfmlOptions.root, sfmlOptions.libDir, sfmlOptions.modules, sfmlOptions.linkDynamic, true, sfmlOptions.pre250Version)
	
	-- Add SFML (release version)
	filter "configurations:Release"
		addSFML( sfmlOptions.root, sfmlOptions.libDir, sfmlOptions.modules, sfmlOptions.linkDynamic, false, sfmlOptions.pre250Version)

	filter {"system:windows"}
		defines {
			"BOMBERMAN_WINDOWS"
		}

	-- Clear filter
	filter {}


	files {
		"../include/Bomberman/**.hpp",
		"../src/**.cpp"
	}
