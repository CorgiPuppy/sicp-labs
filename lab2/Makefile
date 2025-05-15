SRC_DIR := src
TARGET_DIR := target

GROUP_ID := com.pumps
ARTIFACT_ID := lab2
JAR_FILE := $(ARTIFACT_ID)-1.0-SNAPSHOT.jar
CLASS_NAME := $(GROUP_ID).Main

EXE := $(TARGET_DIR)/$(JAR_FILE)

JV := java
JVFLAGS := -cp 
PARAMETERS := -XX:+DisableExplicitGC
MEMORY_SIZE := -Xmx1G
MVN := mvn

.PHONY: all

all: run-src clean-target

run-src: $(EXE)
	@echo "Running.."
	@$(JV) $(PARAMETERS) $(MEMORY_SIZE) $(JVFLAGS) $< $(CLASS_NAME)

$(EXE):
	@echo "Building binaries.."
	@$(MVN) install

clean-target:
	@echo "Cleaning the target dir.."
	@$(MVN) clean
