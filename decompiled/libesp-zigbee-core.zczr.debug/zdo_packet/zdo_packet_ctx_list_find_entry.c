/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_ctx_list_find_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte * zdo_packet_ctx_list_find_entry(uint param_1)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  iVar1 = core_globals_get();
  pbVar2 = *(byte **)(iVar1 + 0xcac);
  pbVar3 = pbVar2;
  if (pbVar2 != (byte *)0x0) {
    for (; (pbVar2 = pbVar3 + -0x24, pbVar2 != (byte *)0xffffffdc &&
           ((pbVar2 == (byte *)0x0 || (*pbVar2 != param_1)))); pbVar3 = *(byte **)pbVar3) {
    }
    if (pbVar2 == (byte *)0xffffffdc) {
      pbVar2 = (byte *)0x0;
    }
  }
  return pbVar2;
}

