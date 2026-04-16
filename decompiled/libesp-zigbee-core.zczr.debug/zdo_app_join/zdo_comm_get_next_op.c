/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  if (*(short *)(iVar2 + 0xd26) == 0) {
    zVar1 = '\0';
  }
  else {
    iVar2 = core_globals_get();
    zVar1 = __ctzsi2(*(undefined2 *)(iVar2 + 0xd26));
  }
  return zVar1;
}

