/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_forget_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_forget_device(undefined4 param_1)

{
  int iVar1;
  
  aps_retrans_purge();
  aps_bind_table_remove_dst_all(param_1);
  iVar1 = aps_secur_get_key_pair_by_addr(param_1);
  if (iVar1 != 0) {
    aps_secur_delete_key_pair();
  }
  return;
}

