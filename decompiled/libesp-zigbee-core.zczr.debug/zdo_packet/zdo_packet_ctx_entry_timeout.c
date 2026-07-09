/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_ctx_entry_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_packet_ctx_entry_timeout(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = core_globals_get();
  puVar1 = *(undefined4 **)(iVar3 + 0xcac);
  if (puVar1 != (undefined4 *)0x0) {
    for (; (puVar2 = puVar1 + -9, puVar2 != (undefined4 *)0xffffffdc &&
           ((puVar2 == (undefined4 *)0x0 || (puVar2 != param_1)))); puVar1 = (undefined4 *)*puVar1)
    {
    }
    if ((puVar2 != (undefined4 *)0xffffffdc) && (puVar2 != (undefined4 *)0x0)) {
      if ((puVar1[-4] & 1) == 0) {
        zdo_packet_notify_result(puVar1 + -3,7,0);
        *(byte *)(puVar1 + -4) = *(byte *)(puVar1 + -4) | 1;
      }
      else if (*(char *)(puVar1 + -3) == '\x02') {
        zdo_packet_notify_result(puVar1 + -3,0,0);
      }
      zdo_packet_ctx_list_remove_entry(puVar2);
      zdo_packet_ctx_free_entry(puVar2);
    }
  }
  return;
}

