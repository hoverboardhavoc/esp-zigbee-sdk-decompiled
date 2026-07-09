/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_ctx_entry_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_packet_ctx_entry_timeout(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = core_globals_get();
  piVar2 = *(int **)(iVar1 + 0xcac);
  if (piVar2 != (int *)0x0) {
    for (; piVar2 + -9 != (int *)0xffffffdc; piVar2 = (int *)*piVar2) {
      if (piVar2 + -9 == (int *)param_1) {
        if ((*(uint *)(param_1 + 0x14) & 1) == 0) {
          zdo_packet_notify_result(param_1 + 0x18,7,0);
          *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 1;
        }
        else if (*(char *)(param_1 + 0x18) == '\x02') {
          zdo_packet_notify_result(param_1 + 0x18,0,0);
        }
        zdo_packet_ctx_list_remove_entry(param_1);
        if (param_1 == 0) {
          return;
        }
        if ((*(uint *)(param_1 + 0x14) & 3) != 3) {
          return;
        }
        milli_timer_stop(param_1 + 4);
        mm_free(param_1);
        return;
      }
    }
  }
  return;
}

