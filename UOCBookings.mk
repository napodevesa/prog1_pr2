##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Test
ProjectName            :=UOCBookings
ConfigurationName      :=Test
WorkspacePath          :=/home/uoc/Desktop/UOCBookings_PR2_sol
ProjectPath            :=/home/uoc/Desktop/UOCBookings_PR2_sol
IntermediateDirectory  :=./Test
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=uoc
Date                   :=07/10/19
CodeLitePath           :=/home/uoc/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="UOCBookings.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch)./include $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_api.c$(ObjectSuffix) $(IntermediateDirectory)/src_customer.c$(ObjectSuffix) $(IntermediateDirectory)/src_test.c$(ObjectSuffix) $(IntermediateDirectory)/src_hotel.c$(ObjectSuffix) $(IntermediateDirectory)/src_list.c$(ObjectSuffix) $(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IntermediateDirectory)/src_movement.c$(ObjectSuffix) $(IntermediateDirectory)/src_queue.c$(ObjectSuffix) $(IntermediateDirectory)/src_menu.c$(ObjectSuffix) 



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
	@test -d ./Test || $(MakeDirCommand) ./Test


$(IntermediateDirectory)/.d:
	@test -d ./Test || $(MakeDirCommand) ./Test

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_api.c$(ObjectSuffix): src/api.c $(IntermediateDirectory)/src_api.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOCBookings_PR2_sol/src/api.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_api.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_api.c$(DependSuffix): src/api.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_api.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_api.c$(DependSuffix) -MM src/api.c

$(IntermediateDirectory)/src_api.c$(PreprocessSuffix): src/api.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_api.c$(PreprocessSuffix) src/api.c

$(IntermediateDirectory)/src_customer.c$(ObjectSuffix): src/customer.c $(IntermediateDirectory)/src_customer.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOCBookings_PR2_sol/src/customer.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_customer.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_customer.c$(DependSuffix): src/customer.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_customer.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_customer.c$(DependSuffix) -MM src/customer.c

$(IntermediateDirectory)/src_customer.c$(PreprocessSuffix): src/customer.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_customer.c$(PreprocessSuffix) src/customer.c

$(IntermediateDirectory)/src_test.c$(ObjectSuffix): src/test.c $(IntermediateDirectory)/src_test.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOCBookings_PR2_sol/src/test.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_test.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_test.c$(DependSuffix): src/test.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_test.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_test.c$(DependSuffix) -MM src/test.c

$(IntermediateDirectory)/src_test.c$(PreprocessSuffix): src/test.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_test.c$(PreprocessSuffix) src/test.c

$(IntermediateDirectory)/src_hotel.c$(ObjectSuffix): src/hotel.c $(IntermediateDirectory)/src_hotel.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOCBookings_PR2_sol/src/hotel.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_hotel.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_hotel.c$(DependSuffix): src/hotel.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_hotel.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_hotel.c$(DependSuffix) -MM src/hotel.c

$(IntermediateDirectory)/src_hotel.c$(PreprocessSuffix): src/hotel.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_hotel.c$(PreprocessSuffix) src/hotel.c

$(IntermediateDirectory)/src_list.c$(ObjectSuffix): src/list.c $(IntermediateDirectory)/src_list.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOCBookings_PR2_sol/src/list.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_list.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_list.c$(DependSuffix): src/list.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_list.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_list.c$(DependSuffix) -MM src/list.c

$(IntermediateDirectory)/src_list.c$(PreprocessSuffix): src/list.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_list.c$(PreprocessSuffix) src/list.c

$(IntermediateDirectory)/src_main.c$(ObjectSuffix): src/main.c $(IntermediateDirectory)/src_main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOCBookings_PR2_sol/src/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.c$(DependSuffix): src/main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.c$(DependSuffix) -MM src/main.c

$(IntermediateDirectory)/src_main.c$(PreprocessSuffix): src/main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.c$(PreprocessSuffix) src/main.c

$(IntermediateDirectory)/src_movement.c$(ObjectSuffix): src/movement.c $(IntermediateDirectory)/src_movement.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOCBookings_PR2_sol/src/movement.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_movement.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_movement.c$(DependSuffix): src/movement.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_movement.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_movement.c$(DependSuffix) -MM src/movement.c

$(IntermediateDirectory)/src_movement.c$(PreprocessSuffix): src/movement.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_movement.c$(PreprocessSuffix) src/movement.c

$(IntermediateDirectory)/src_queue.c$(ObjectSuffix): src/queue.c $(IntermediateDirectory)/src_queue.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOCBookings_PR2_sol/src/queue.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_queue.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_queue.c$(DependSuffix): src/queue.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_queue.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_queue.c$(DependSuffix) -MM src/queue.c

$(IntermediateDirectory)/src_queue.c$(PreprocessSuffix): src/queue.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_queue.c$(PreprocessSuffix) src/queue.c

$(IntermediateDirectory)/src_menu.c$(ObjectSuffix): src/menu.c $(IntermediateDirectory)/src_menu.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Desktop/UOCBookings_PR2_sol/src/menu.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_menu.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_menu.c$(DependSuffix): src/menu.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_menu.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_menu.c$(DependSuffix) -MM src/menu.c

$(IntermediateDirectory)/src_menu.c$(PreprocessSuffix): src/menu.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_menu.c$(PreprocessSuffix) src/menu.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Test/


