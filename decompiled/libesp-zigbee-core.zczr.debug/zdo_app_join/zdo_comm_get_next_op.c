/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_get_next_op
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 zdo_comm_get_next_op(void)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = core_globals_get();
  if (*(short *)(iVar2 + 0xcc2) == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = core_globals_get();
    uVar1 = __ctzsi2(*(undefined2 *)(iVar2 + 0xcc2));
  }
  return uVar1;
}

