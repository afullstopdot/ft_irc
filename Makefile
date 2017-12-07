# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarquez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/20 10:10:12 by amarquez          #+#    #+#              #
#    Updated: 2017/07/14 10:10:49 by amarquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

### Create src & obj

SELECT_DIR = select
SELECT_SRC := $(wildcard $(SERVER_ROOT)/$(SELECT_DIR)/*.c)
SELECT_OBJ := $(SELECT_SRC:$(SERVER_ROOT)/$(SELECT_DIR)/%.c=$(OBJDIR)/server/$(SELECT_DIR)/%.o)

### Wrappers src & obj

WRAP_DIR = wrappers
WRAP_SRC := $(wildcard $(SERVER_ROOT)/$(WRAP_DIR)/*.c)
WRAP_OBJ := $(WRAP_SRC:$(SERVER_ROOT)/$(WRAP_DIR)/%.c=$(OBJDIR)/server/$(WRAP_DIR)/%.o)

### Main src & obj

MAIN_DIR = main
MAIN_SRC := $(wildcard $(SERVER_ROOT)/$(MAIN_DIR)/*.c)
MAIN_OBJ := $(MAIN_SRC:$(SERVER_ROOT)/$(MAIN_DIR)/%.c=$(OBJDIR)/server/$(MAIN_DIR)/%.o)

### Executabe name

SERVER_EXE = server

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

all: $(OBJDIR) $(BINDIR)/$(SERVER_EXE)

$(OBJDIR):
	@echo "\033[0;31m[server]: \033[0m\033[0;36mCreating "$@" directory!\033[0m"
	@mkdir -p $@/server/$(INTERPRETER_DIR) $@/server/$(ERROR_DIR) $@/server/$(MAIN_DIR) $@/server/$(WRAP_DIR) $@/server/$(CREATE_DIR) $@/server/$(SELECT_DIR) $@/server/$(CHAT_DIR)
	@echo "\033[0;31m[server]: \033[0m\033[0;32mComplete!\033[0m"
	

# server rules

$(BINDIR)/$(SERVER_EXE): $(INTERPRETER_OBJ) $(ERROR_OBJ) $(WRAP_OBJ) $(CREATE_OBJ) $(SELECT_OBJ) $(CHAT_OBJ) $(MAIN_OBJ)
	@make -C libft
	@echo "\033[0;31m[server]: \033[0mLinking object files!"
	@$(LINKER) $(INTERPRETER_OBJ) $(ERROR_OBJ) $(WRAP_OBJ) $(CREATE_OBJ) $(SELECT_OBJ) $(CHAT_OBJ) $(MAIN_OBJ) $(FLAGS) -o $@ $(LIBFT) -I $(INCDIR) $(LIBFT_H)
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


$(WRAP_OBJ): $(OBJDIR)/server/$(WRAP_DIR)/%.o : $(SERVER_ROOT)/$(WRAP_DIR)/%.c
	@echo "\033[0;35m[signals]: \033[0mCompiling source file \033[0;36m"$<"\033[0m!"
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCDIR) $(LINK) $(LIBFT_H)
	@echo "\033[0;35m[signals]: \033[0mCompiled \033[0;36m"$<"\033[0m successfully!"


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

.PHONY: clean fclean re
clean:
	@echo "\033[0;36mRemoving object files\033[0m"
	@rm -f $(INTERPRETER_OBJ) $(ERROR_OBJ) $(MAIN_OBJ) $(WRAP_OBJ) $(CREATE_OBJ) $(SELECT_OBJ) $(CHAT_OBJ)
	@echo "\033[0;32mCleanup complete\033[0m"


fclean: clean
	@echo "\033[0;36mRemoving executable '$(BINDIR)/$(SERVER_EXE)"
	@rm -f $(BINDIR)/$(SERVER_EXE)
	@echo "\033[0;32mExecutable removed\033[0m"


re: fclean all
