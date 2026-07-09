/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_deinit(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  zmsg_queue_deinit(iVar1 + 0x2c);
  aps_reasm_deinit();
  aps_retrans_deinit();
  aps_bind_table_deinit();
  aps_group_table_deinit();
  aps_dup_table_deinit();
  aps_secur_deinit();
  random_deinit();
  return;
}

