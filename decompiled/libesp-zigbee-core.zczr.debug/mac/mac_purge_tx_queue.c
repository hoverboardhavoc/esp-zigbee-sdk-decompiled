/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_purge_tx_queue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_purge_tx_queue(int param_1,char *param_2)

{
  int iVar1;
  
  if (*param_2 == '\0') {
    while (iVar1 = zmsg_queue_get_head(param_1 + 0x48), iVar1 != 0) {
      mac_handle_tx_done(param_1,param_1 + 0x48,0xda,0);
    }
    while (iVar1 = zmsg_queue_get_head(param_1 + 0x54), iVar1 != 0) {
      mac_handle_tx_done(param_1,param_1 + 0x54,0xda,1);
    }
    while (iVar1 = zmsg_queue_get_head(param_1 + 0x60), iVar1 != 0) {
      mac_handle_tx_done(param_1,param_1 + 0x60,0xda,1);
    }
    micro_timer_stop(param_1 + 0x6c);
  }
  return;
}

