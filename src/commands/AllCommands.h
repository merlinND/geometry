//-- Interface <AllCommands> (fichier AllCommands.h)
#if ! defined ( __AllCommands___H_ )
#define __AllCommands___H_

//--------------------------------------------------- Interfaces utilisées
// Simple header file that includes all different command classes

// ----- Historizable commands
#include "MoveCommand.h"
#include "DeleteCommand.h"
#include "ClearCommand.h"

// ----- Non-historizable commands
#include "NoneCommand.h"
#include "ListCommand.h"
#include "UndoCommand.h"
#include "RedoCommand.h"
#include "SaveCommand.h"
#include "ExitCommand.h"

#endif // __AllCommands___H_ 
