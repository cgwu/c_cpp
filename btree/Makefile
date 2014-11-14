########################################################################
#
#		modify: CC TARGETS CFLAGS LDFLAG
#
########################################################################
PROJECT_TOP_DIR=$(shell cd ./; pwd)

PROJECT_SRC_DIR=$(PROJECT_TOP_DIR)
PROJECT_INC_DIR=$(PROJECT_TOP_DIR)/inc
PROJECT_LIB_DIR=$(PROJECT_TOP_DIR)/lib

PROJECT_BIN_DIR=$(PROJECT_TOP_DIR)/bin
PROJECT_OBJ_DIR=$(PROJECT_BIN_DIR)/obj
MKDIR := mkdir -p
RM := rm -rf

CC := gcc
TARGETS = a.out

CFLAGS := -g -I$(PROJECT_INC_DIR)
LDFLAG := -L$(PROJECT_LIB_DIR)

src :=$(wildcard $(PROJECT_SRC_DIR)/*.c)
dir := $(notdir $(src))
PROJECT_OBJ := $(patsubst %.c,%.o,$(dir) )
	
PROJECT_ALL_OBJS := $(addprefix $(PROJECT_OBJ_DIR)/, $(PROJECT_OBJ))
	
# Default make target
all:$(PROJECT_SRC_DIR) obj_dir $(PROJECT_ALL_OBJS)
	$(CC) $(CFLAGS) $(PROJECT_ALL_OBJS) -o $(PROJECT_BIN_DIR)/$(TARGETS) $(LDFLAG)

.PHONY:obj_dir
obj_dir:
	$(MKDIR) $(PROJECT_OBJ_DIR)

$(PROJECT_OBJ_DIR)/%.o : $(PROJECT_SRC_DIR)/%.c
#	echo $< ==> $@  # $<为第一个依赖文件; $@为目标文件
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY:clean
clean:
	$(RM) $(PROJECT_BIN_DIR)
#	rm -fr $(PROJECT_OBJ_DIR)
#	rm -fr $(TARGETS)
