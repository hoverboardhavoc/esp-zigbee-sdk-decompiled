/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_indirect_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_indirect_transmit(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = micro_timer_get_now();
  *(uint *)(param_3 + 0x18) = (uint)*(ushort *)(param_1 + 0x28) * 0x3c00 + iVar1;
  zmsg_add_footer(param_3,param_2,10);
  zmsg_queue_enqueue(param_1 + 0x60,param_3);
  iVar1 = micro_timer_is_running(param_1 + 0x6c);
  if (iVar1 == 0) {
    micro_timer_fire_at(param_1 + 0x6c,*(undefined4 *)(param_3 + 0x18));
  }
  return;
}

