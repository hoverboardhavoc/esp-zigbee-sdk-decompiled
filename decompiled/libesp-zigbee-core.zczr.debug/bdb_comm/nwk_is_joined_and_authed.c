/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> nwk_is_joined_and_authed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_is_joined_and_authed(void)

{
  _Bool _Var1;
  int iVar2;
  
  iVar2 = nwk_is_joined();
  if (iVar2 == 0) {
    _Var1 = false;
  }
  else {
    iVar2 = nwk_is_authed();
    if (iVar2 == 0) {
      _Var1 = false;
    }
    else {
      _Var1 = true;
    }
  }
  return _Var1;
}

