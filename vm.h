#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "object.h"
#include "table.h"
#include "value.h"

#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

// represents a ongoing function call
// that tells us the function being called
// and where to resume after function is done
typedef struct {
  ObjClosure* closure;
  uint8_t* ip;
  Value* slots;
} CallFrame;

typedef struct {
  CallFrame frames[FRAMES_MAX];
  int frameCount;

  Chunk* chunk;
  uint8_t* ip;
  Value stack[STACK_MAX];
  Value* stackTop;
  Table globals;
  Table strings;
  ObjUpvalue* openUpvalues;
  Obj* objects;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

// allows the use of the global vm variable
// since it's used in objects.c
extern VM vm;

void initVM();
void freeVM();

InterpretResult interpret(const char* source);

void push(Value value);
Value pop();

#endif
