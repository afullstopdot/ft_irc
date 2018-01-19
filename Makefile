# Compiler

CC	= gcc
LINKER = gcc

# Flags

FLAGS = -Wall -Wextra -Werror

# Project Directory

CWD = .

# Generic File Structure

INCDIR = $(CWD)/inc
SRCDIR = $(CWD)/src
OBJDIR = $(CWD)/obj

# Include Files

INC := $(wildcard $(INCDIR)/*.h)

# Server SRC

SERVER_ROOT = $(SRCDIR)/server
CLIENT_ROOT = $(SRCDIR)/client
GENERIC_ROOT = $(SRCDIR)/generic

### CLIENT Main src & obj

CMAIN_DIR = main
CMAIN_SRC := $(wildcard $(CLIENT_ROOT)/$(CMAIN_DIR)/*.c)
CMAIN_OBJ := $(CMAIN_SRC:$(CLIENT_ROOT)/$(CMAIN_DIR)/%.c=$(OBJDIR)/client/$(CMAIN_DIR)/%.o)

### CLIENT Main src & obj

CONNECT_DIR = connect
CONNECT_SRC := $(wildcard $(CLIENT_ROOT)/$(CONNECT_DIR)/*.c)
CONNECT_OBJ := $(CONNECT_SRC:$(CLIENT_ROOT)/$(CONNECT_DIR)/%.c=$(OBJDIR)/client/$(CONNECT_DIR)/%.o)

### CLIENT Main src & obj

HANDLE_DIR = handle
HANDLE_SRC := $(wildcard $(CLIENT_ROOT)/$(HANDLE_DIR)/*.c)
HANDLE_OBJ := $(HANDLE_SRC:$(CLIENT_ROOT)/$(HANDLE_DIR)/%.c=$(OBJDIR)/client/$(HANDLE_DIR)/%.o)

### Wrappers src & obj

WRAP_DIR = wrappers
WRAP_SRC := $(wildcard $(GENERIC_ROOT)/$(WRAP_DIR)/*.c)
WRAP_OBJ := $(WRAP_SRC:$(GENERIC_ROOT)/$(WRAP_DIR)/%.c=$(OBJDIR)/generic/$(WRAP_DIR)/%.o)

### CB src & obj

CB_DIR = circular-buffers
CB_SRC := $(wildcard $(GENERIC_ROOT)/$(CB_DIR)/*.c)
CB_OBJ := $(CB_SRC:$(GENERIC_ROOT)/$(CB_DIR)/%.c=$(OBJDIR)/generic/$(CB_DIR)/%.o)

### Interpreter src & obj

INTERPRETER_DIR = users
INTERPRETER_SRC := $(wildcard $(SERVER_ROOT)/$(INTERPRETER_DIR)/*.c)
INTERPRETER_OBJ := $(INTERPRETER_SRC:$(SERVER_ROOT)/$(INTERPRETER_DIR)/%.c=$(OBJDIR)/server/$(INTERPRETER_DIR)/%.o)

### Chat src & obj

CHAT_DIR = chat
CHAT_SRC := $(wildcard $(SERVER_ROOT)/$(CHAT_DIR)/*.c)
CHAT_OBJ := $(CHAT_SRC:$(SERVER_ROOT)/$(CHAT_DIR)/%.c=$(OBJDIR)/server/$(CHAT_DIR)/%.o)

### Error src & obj

ERROR_DIR = error
ERROR_SRC := $(wildcard $(SERVER_ROOT)/$(ERROR_DIR)/*.c)
ERROR_OBJ := $(ERROR_SRC:$(SERVER_ROOT)/$(ERROR_DIR)/%.c=$(OBJDIR)/server/$(ERROR_DIR)/%.o)

### Create src & obj

CREATE_DIR = create
CREATE_SRC := $(wildcard $(SERVER_ROOT)/$(CREATE_DIR)/*.c)
CREATE_OBJ := $(CREATE_SRC:$(SERVER_ROOT)/$(CREATE_DIR)/%.c=$(OBJDIR)/server/$(CREATE_DIR)/%.o)

### Select src & obj

SELECT_DIR = select
SELECT_SRC := $(wildcard $(SERVER_ROOT)/$(SELECT_DIR)/*.c)
SELECT_OBJ := $(SELECT_SRC:$(SERVER_ROOT)/$(SELECT_DIR)/%.c=$(OBJDIR)/server/$(SELECT_DIR)/%.o)

### Client select src & obj

CSELECT_DIR = select
CSELECT_SRC := $(wildcard $(CLIENT_ROOT)/$(CSELECT_DIR)/*.c)
CSELECT_OBJ := $(CSELECT_SRC:$(CLIENT_ROOT)/$(CSELECT_DIR)/%.c=$(OBJDIR)/client/$(CSELECT_DIR)/%.o)

### Main src & obj

MAIN_DIR = main
MAIN_SRC := $(wildcard $(SERVER_ROOT)/$(MAIN_DIR)/*.c)
MAIN_OBJ := $(MAIN_SRC:$(SERVER_ROOT)/$(MAIN_DIR)/%.c=$(OBJDIR)/server/$(MAIN_DIR)/%.o)

### Executabe name

SERVER_EXE = server
CLIENT_EXE = client

# OS for linking libraries (linux and os x different)

OS := $(shell uname)

LIBFT = -L ./libft -lft
LIBFT_H = -I libft

ifneq ($(OS),Darwin)

  LINK = $(LIBFT)

endif

# Bin directory

BINDIR = .

##### NB: Check if directories exists before you try to use them

# rules begin:

all: $(OBJDIR) $(WRAP_OBJ) $(CB_OBJ) $(BINDIR)/$(SERVER_EXE) $(BINDIR)/$(CLIENT_EXE)

$(OBJDIR):
	@echo "\033[0;31m[server]: \033[0m\033[0;36mCreating "$@" directory!\033[0m"
	@mkdir -p $@/server/$(INTERPRETER_DIR) $@/server/$(ERROR_DIR) $@/server/$(MAIN_DIR) $@/server/$(CREATE_DIR) $@/server/$(SELECT_DIR) $@/server/$(CHAT_DIR)
	@mkdir -p $@/generic/$(WRAP_DIR) $@/generic/$(CB_DIR)
	@mkdir -p $@/client/$(CMAIN_DIR) $@/client/$(CONNECT_DIR) $@/client/$(HANDLE_DIR) $@/client/$(CSELECT_DIR)
	@echo "\033[0;31m[server]: \033[0m\033[0;32mComplete!\033[0m"
	
# generic rukes

$(WRAP_OBJ): $(OBJDIR)/generic/$(WRAP_DIR)/%.o : $(GENERIC_ROOT)/$(WRAP_DIR)/%.c
	@echo "\033[0;42m[wrap]: \033[0mCompiling source file \033[0;36m"$<"\033[0m!"
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCDIR) $(LINK) $(LIBFT_H)
	@echo "\033[0;42m[wrap]: \033[0mCompiled \033[0;36m"$<"\033[0m successfully!"

$(CB_OBJ): $(OBJDIR)/generic/$(CB_DIR)/%.o : $(GENERIC_ROOT)/$(CB_DIR)/%.c
	@echo "\033[0;40m[circular-buffers]: \033[0mCompiling source file \033[0;36m"$<"\033[0m!"
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCDIR) $(LINK) $(LIBFT_H)
	@echo "\033[0;40m[circular-buffers]: \033[0mCompiled \033[0;36m"$<"\033[0m successfully!"


# server rules

$(BINDIR)/$(SERVER_EXE): $(INTERPRETER_OBJ) $(ERROR_OBJ) $(CREATE_OBJ) $(SELECT_OBJ) $(CHAT_OBJ) $(MAIN_OBJ)
	@make -C libft
	@echo "\033[0;31m[server]: \033[0mLinking object files!"
	@$(LINKER) $(INTERPRETER_OBJ) $(ERROR_OBJ) $(WRAP_OBJ) $(CREATE_OBJ) $(SELECT_OBJ) $(CHAT_OBJ) $(CB_OBJ) $(MAIN_OBJ) $(FLAGS) -o $@ $(LIBFT) -I $(INCDIR) $(LIBFT_H) -fPIC
	@chmod +x $@
	@echo "\033[0;31m[server]: \033[0mLinking complete!"


$(INTERPRETER_OBJ): $(OBJDIR)/server/$(INTERPRETER_DIR)/%.o : $(SERVER_ROOT)/$(INTERPRETER_DIR)/%.c
	@echo "\033[0;32m[interpreter]: \033[0mCompiling source file \033[0;36m"$<"\033[0m!"
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCDIR) $(LINK) $(LIBFT_H)
	@echo "\033[0;32m[interpreter]: \033[0mCompiled \033[0;32m"$<"\033[0m successfully!"
	

$(ERROR_OBJ): $(OBJDIR)/server/$(ERROR_DIR)/%.o : $(SERVER_ROOT)/$(ERROR_DIR)/%.c
	@echo "\033[0;33m[error]: \033[0mCompiling source file \033[0;36m"$<"\033[0m!"
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCDIR) $(LINK) $(LIBFT_H)
	@echo "\033[0;33m[error]: \033[0mCompiled \033[0;36m"$<"\033[0m successfully!"


$(MAIN_OBJ): $(OBJDIR)/server/$(MAIN_DIR)/%.o : $(SERVER_ROOT)/$(MAIN_DIR)/%.c
	@echo "\033[0;34m[main]: \033[0mCompiling source file \033[0;36m"$<"\033[0m!"
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCDIR) $(LINK) $(LIBFT_H)
	@echo "\033[0;34m[main]: \033[0mCompiled \033[0;36m"$<"\033[0m successfully!"


$(CREATE_OBJ): $(OBJDIR)/server/$(CREATE_DIR)/%.o : $(SERVER_ROOT)/$(CREATE_DIR)/%.c
	@echo "\033[0;36m[create]: \033[0mCompiling source file \033[0;36m"$<"\033[0m!"
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCDIR) $(LINK) $(LIBFT_H)
	@echo "\033[0;36m[create]: \033[0mCompiled \033[0;36m"$<"\033[0m successfully!"


$(SELECT_OBJ): $(OBJDIR)/server/$(SELECT_DIR)/%.o : $(SERVER_ROOT)/$(SELECT_DIR)/%.c
	@echo "\033[0;37m[select]: \033[0mCompiling source file \033[0;36m"$<"\033[0m!"
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCDIR) $(LINK) $(LIBFT_H)
	@echo "\033[0;37m[select]: \033[0mCompiled \033[0;36m"$<"\033[0m successfully!"


$(CHAT_OBJ): $(OBJDIR)/server/$(CHAT_DIR)/%.o : $(SERVER_ROOT)/$(CHAT_DIR)/%.c
	@echo "\033[0;38m[chat]: \033[0mCompiling source file \033[0;36m"$<"\033[0m!"
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCDIR) $(LINK) $(LIBFT_H)
	@echo "\033[0;38m[chat]: \033[0mCompiled \033[0;36m"$<"\033[0m successfully!"


# client rules

$(BINDIR)/$(CLIENT_EXE): $(CMAIN_OBJ) $(CONNECT_OBJ) $(CSELECT_OBJ) $(ERROR_OBJ) $(WRAP_OBJ) $(CB_OBJ) $(HANDLE_OBJ)
	@make -C libft
	@echo "\033[0;31m[client]: \033[0mLinking object files!"
	@$(LINKER) $(CMAIN_OBJ) $(CONNECT_OBJ) $(ERROR_OBJ) $(WRAP_OBJ) $(CSELECT_OBJ) $(CB_OBJ) $(HANDLE_OBJ) $(FLAGS) -o $@ $(LIBFT) -I $(INCDIR) $(LIBFT_H) -fPIC
	@chmod +x $@
	@echo "\033[0;31m[client]: \033[0mLinking complete!"


$(CMAIN_OBJ): $(OBJDIR)/client/$(CMAIN_DIR)/%.o : $(CLIENT_ROOT)/$(CMAIN_DIR)/%.c
	@echo "\033[0;34m[cmain]: \033[0mCompiling source file \033[0;36m"$<"\033[0m!"
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCDIR) $(LINK) $(LIBFT_H)
	@echo "\033[0;34m[cmain]: \033[0mCompiled \033[0;36m"$<"\033[0m successfully!"


$(CONNECT_OBJ): $(OBJDIR)/client/$(CONNECT_DIR)/%.o : $(CLIENT_ROOT)/$(CONNECT_DIR)/%.c
	@echo "\033[0;35m[CONNECT]: \033[0mCompiling source file \033[0;36m"$<"\033[0m!"
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCDIR) $(LINK) $(LIBFT_H)
	@echo "\033[0;35m[CONNECT]: \033[0mCompiled \033[0;36m"$<"\033[0m successfully!"


$(HANDLE_OBJ): $(OBJDIR)/client/$(HANDLE_DIR)/%.o : $(CLIENT_ROOT)/$(HANDLE_DIR)/%.c
	@echo "\033[0;35m[HANDLE]: \033[0mCompiling source file \033[0;36m"$<"\033[0m!"
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCDIR) $(LINK) $(LIBFT_H)
	@echo "\033[0;35m[HANDLE]: \033[0mCompiled \033[0;36m"$<"\033[0m successfully!"


$(CSELECT_OBJ): $(OBJDIR)/client/$(CSELECT_DIR)/%.o : $(CLIENT_ROOT)/$(CSELECT_DIR)/%.c
	@echo "\033[0;45m[CLIENT SELECT]: \033[0mCompiling source file \033[0;36m"$<"\033[0m!"
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCDIR) $(LINK) $(LIBFT_H)
	@echo "\033[0;45m[CLIENT SELECT]: \033[0mCompiled \033[0;36m"$<"\033[0m successfully!"


# General rules

.PHONY: clean fclean oclean re
clean:
	@echo "\033[0;36mRemoving object files\033[0m"
	@rm -f $(INTERPRETER_OBJ) $(ERROR_OBJ) $(MAIN_OBJ) $(WRAP_OBJ) $(CREATE_OBJ) $(SELECT_OBJ) $(CHAT_OBJ) $(CB_OBJ)
	@rm -f $(CMAIN_OBJ) $(CONNECT_OBJ) $(HANDLE_OBJ) $(CSELECT_OBJ)
	@echo "\033[0;32mCleanup complete\033[0m"


fclean: clean
	@echo "\033[0;36mRemoving executable '$(BINDIR)/$(SERVER_EXE)"
	@echo "\033[0;36mRemoving executable '$(BINDIR)/$(CLIENT_EXE)"
	@rm -f $(BINDIR)/$(SERVER_EXE)
	@rm -f $(BINDIR)/$(CLIENT_EXE)
	@echo "\033[0;32mExecutable removed\033[0m"


oclean:
	@echo "\033[0;36mRemoving obj directory"
	@rm -rf $(OBJDIR)
	@echo "\033[0;32mDirectory removed\033[0m"


re: fclean all
