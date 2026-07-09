/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_comm_put_app_signal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_put_app_signal(undefined2 param_1,undefined1 param_2)

{
  undefined2 uStack_24;
  undefined1 uStack_22;
  undefined1 auStack_21 [21];
  
  memset(auStack_21,0,0xf);
  uStack_24 = param_1;
  uStack_22 = param_2;
  zdo_app_put_signal(&uStack_24);
  return;
}

