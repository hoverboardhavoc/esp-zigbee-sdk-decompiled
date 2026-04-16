/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_handle_transaction_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_handle_transaction_timeout(void *param)

{
  int iVar1;
  int iVar2;
  
  iVar1 = micro_timer_get_now();
  while( true ) {
    iVar2 = zmsg_queue_get_head((zmsg_queue_t *)((int)param + 0x60));
    if (iVar2 == 0) {
      return;
    }
    if (iVar1 - *(int *)(iVar2 + 0x18) < 0) break;
    mac_handle_tx_done((mac_device *)param,(zmsg_queue_t *)((int)param + 0x60),0x1f0,true);
  }
  micro_timer_fire_at((int)param + 0x6c);
  return;
}

