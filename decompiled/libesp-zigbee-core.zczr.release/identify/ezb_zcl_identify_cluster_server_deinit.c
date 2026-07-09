/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> identify.o -> ezb_zcl_identify_cluster_server_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_identify_cluster_server_deinit(void)

{
  int iVar1;
  
  iVar1 = identify_srv_get_attr_desc_part_0();
  if (iVar1 == 0) {
    iVar1 = __assert_func(0,0,0);
  }
  milli_timer_stop(*(int *)(iVar1 + 8) + 4);
  mm_free(*(undefined4 *)(iVar1 + 8));
  *(undefined4 *)(iVar1 + 8) = 0;
  return;
}

