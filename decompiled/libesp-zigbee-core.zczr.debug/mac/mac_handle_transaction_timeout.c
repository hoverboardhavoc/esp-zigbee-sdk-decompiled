/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_transaction_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_handle_transaction_timeout(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = micro_timer_get_now();
  while( true ) {
    iVar2 = zmsg_queue_get_head(param_1 + 0x60);
    if (iVar2 == 0) {
      return;
    }
    if (iVar1 - *(int *)(iVar2 + 0x18) < 0) break;
    mac_handle_tx_done(param_1,param_1 + 0x60,0x1f0,1);
  }
  micro_timer_fire_at(param_1 + 0x6c,*(undefined4 *)(iVar2 + 0x18));
  return;
}

