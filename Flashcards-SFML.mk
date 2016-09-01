##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Flashcards-SFML
ConfigurationName      :=Debug
WorkspacePath          := "/home/chris/CodeLiteProjects"
ProjectPath            := "/home/chris/CodeLiteProjects/Flashcards-SFML"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Chris
Date                   :=01/09/16
CodeLitePath           :="/home/chris/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)SFML_STATIC 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Flashcards-SFML.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/home/chris/dev/sfml/SFML/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-audio $(LibrarySwitch)sfml-network $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-graphics" "sfml-window" "sfml-audio" "sfml-network" "sfml-system" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/home/chris/dev/sfml/SFML/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Window.cpp$(ObjectSuffix) $(IntermediateDirectory)/Flashcards.cpp$(ObjectSuffix) $(IntermediateDirectory)/StateStart.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/chris/CodeLiteProjects/Flashcards-SFML/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Window.cpp$(ObjectSuffix): Window.cpp $(IntermediateDirectory)/Window.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/chris/CodeLiteProjects/Flashcards-SFML/Window.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Window.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Window.cpp$(DependSuffix): Window.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Window.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Window.cpp$(DependSuffix) -MM "Window.cpp"

$(IntermediateDirectory)/Window.cpp$(PreprocessSuffix): Window.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Window.cpp$(PreprocessSuffix) "Window.cpp"

$(IntermediateDirectory)/Flashcards.cpp$(ObjectSuffix): Flashcards.cpp $(IntermediateDirectory)/Flashcards.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/chris/CodeLiteProjects/Flashcards-SFML/Flashcards.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Flashcards.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Flashcards.cpp$(DependSuffix): Flashcards.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Flashcards.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Flashcards.cpp$(DependSuffix) -MM "Flashcards.cpp"

$(IntermediateDirectory)/Flashcards.cpp$(PreprocessSuffix): Flashcards.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Flashcards.cpp$(PreprocessSuffix) "Flashcards.cpp"

$(IntermediateDirectory)/StateStart.cpp$(ObjectSuffix): StateStart.cpp $(IntermediateDirectory)/StateStart.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/chris/CodeLiteProjects/Flashcards-SFML/StateStart.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/StateStart.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/StateStart.cpp$(DependSuffix): StateStart.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/StateStart.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/StateStart.cpp$(DependSuffix) -MM "StateStart.cpp"

$(IntermediateDirectory)/StateStart.cpp$(PreprocessSuffix): StateStart.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/StateStart.cpp$(PreprocessSuffix) "StateStart.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


