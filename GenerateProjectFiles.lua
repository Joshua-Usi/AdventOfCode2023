outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
include_files = {
	"%{prj.name}/**.hpp",
	"%{prj.name}/**.cpp",
	-- C backward compatibility
	"%{prj.name}/**.h",
	"%{prj.name}/**.c",
}
exclude_files = {}
library_dirs = {}
engine_dirs = {}
flags_debug = {
	"MultiProcessorCompile",
	"NoMinimalRebuild",
}
flags_optimised = {
	"LinkTimeOptimization",
	"MultiProcessorCompile",
	"NoMinimalRebuild",
}
project_name = "AdventOfCode2023"

workspace(project_name)
	architecture "x64"
	startproject(project_name)
	configurations {
		"Debug",
		"Release",
	}

project(project_name)
	location(project_name)
	language "C++"
	cppdialect "C++20"
	staticruntime "on"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-intermediate/" .. outputdir .. "/%{prj.name}")
	files(include_files)
	includedirs(engine_dirs)
	libdirs(library_dirs)
	links {}
	filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"
	filter "configurations:Debug"
		symbols "on"
		flags(flags_debug)
		kind "ConsoleApp"
	filter "configurations:Release"
		optimize "on"
		floatingpoint "Fast"
		optimize "speed"
		flags(flags_optimised)
		kind "ConsoleApp"