/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_cnf_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_packet_cnf_handler(byte *param_1,int param_2)

{
  uint uVar1;
  
  if ((param_1 != (byte *)0x0) && (param_2 != 0)) {
    *(byte *)(param_2 + 0x14) = *(byte *)(param_2 + 0x14) | 2;
    if ((*(char *)(param_2 + 0x18) == '\0') ||
       ((param_2 + 0x24 != *(int *)(param_2 + 0x24) && (*param_1 != 0)))) {
      if (*param_1 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = *param_1 | 0x400;
      }
      zdo_packet_notify_result(param_2 + 0x18,uVar1,0);
      *(byte *)(param_2 + 0x14) = *(byte *)(param_2 + 0x14) | 1;
      zdo_packet_ctx_list_remove_entry(param_2);
      zdo_packet_ctx_free_entry(param_2);
    }
  }
  return;
}

