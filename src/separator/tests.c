// .h
typedef enum type {
  T_FIRST,
  T_SECOND,
  T_THIRD
} type_t;

typedef struct pair {
    type_t key;
    const char *value;
} pair_t;

extern const pair_t map[];

// .c
const pair_t map[] = {
  { T_FIRST, "first" },
  { T_SECOND, "second" },
  { T_THIRD, "third" }
};

const char *find(type_t key)
{
  // nombre de lignes dans la map
  size_t map_size = sizeof(map / sizeof(pair_t));

  for (size_t index = 0; index < map_size; ++index) {
    if (map[index].key == key)
      return (map[index].value);
  }
  return (NULL);
}


// Si la map n'a pas besoin d'être accessible depuis un autre fichier que le fichier dans lequel elle est définie:
// .h
// pas de "extern ..."

// .c
static 