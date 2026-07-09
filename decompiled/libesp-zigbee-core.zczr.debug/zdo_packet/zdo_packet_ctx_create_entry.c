/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_ctx_create_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_packet_ctx_create_entry(undefined1 param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)calloc(1,0x28);
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = param_1;
    *(undefined4 *)(puVar2 + 0x18) = *param_2;
    *(undefined4 *)(puVar2 + 0x1c) = param_2[1];
    *(undefined4 *)(puVar2 + 0x20) = param_2[2];
    bVar1 = puVar2[0x14];
    puVar2[0x14] = bVar1 & 0xfe;
    puVar2[0x14] = bVar1 & 0xfc;
    *(undefined1 **)(puVar2 + 0x24) = puVar2 + 0x24;
  }
  return;
}

