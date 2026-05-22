/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_get_next_op
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdo_comm_operation_t zdo_comm_get_next_op(void)

{
  zdo_comm_operation_t zVar1;
  int iVar2;
  
  iVar2 = core_globals_get();
  if (*(short *)(iVar2 + 0xcc2) == 0) {
    zVar1 = '\0';
  }
  else {
    iVar2 = core_globals_get();
    zVar1 = __ctzsi2(*(undefined2 *)(iVar2 + 0xcc2));
  }
  return zVar1;
}

