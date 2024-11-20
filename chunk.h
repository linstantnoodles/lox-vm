#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
  OP_CONSTANT,
  OP_NIL,
  OP_TRUE,
  OP_FALSE,
  OP_POP,
  OP_GET_GLOBAL,
  OP_RETURN,
  OP_NEGATE,
  OP_PRINT,
  OP_JUMP_IF_FALSE,
  OP_ADD,
  OP_JUMP,
  OP_EQUAL,
  OP_DEFINE_GLOBAL,
  OP_SET_GLOBAL,
  OP_GET_LOCAL,
  OP_SET_LOCAL,
  OP_GREATER,
  OP_LESS,
  OP_SUBTRACT,
  OP_MULTIPLY,
  OP_DIVIDE,
  OP_NOT
} OpCode; // by default uint8_t?

typedef struct {
  int count;
  int capacity;
  uint8_t* code;
  int* lines;
  ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

#endif
