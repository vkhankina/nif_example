#include <erl_nif.h>

extern int sum(int x, int y);
extern int twice(int x);

static ERL_NIF_TERM sum_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  int x, y, res;

  if(!enif_get_int(env, argv[0], &x) || !enif_get_int(env, argv[1], &y))
  {
    return enif_make_badarg(env);
  }
  res = sum(x, y);
  return enif_make_int(env, res);
}

static ERL_NIF_TERM twice_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  int x, res;

  if(!enif_get_int(env, argv[0], &x))
  {
    return enif_make_badarg(env);
  }
  res = twice(x);
  return enif_make_int(env, res);
}

static ErlNifFunc nif_funcs[] = {
  {"sum", 2, sum_nif},
  {"twice", 1, twice_nif}
};

ERL_NIF_INIT(example, nif_funcs, NULL, NULL, NULL, NULL)