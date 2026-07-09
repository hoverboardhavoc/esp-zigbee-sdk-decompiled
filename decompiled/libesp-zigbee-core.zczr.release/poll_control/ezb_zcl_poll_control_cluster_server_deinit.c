/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> ezb_zcl_poll_control_cluster_server_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_poll_control_cluster_server_deinit(void)

{
  int iVar1;
  
  iVar1 = poll_control_srv_get_attr_desc_part_0();
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 8), iVar1 != 0)) {
    milli_timer_stop(iVar1 + 4);
    mm_free(iVar1);
    return;
  }
  return;
}

