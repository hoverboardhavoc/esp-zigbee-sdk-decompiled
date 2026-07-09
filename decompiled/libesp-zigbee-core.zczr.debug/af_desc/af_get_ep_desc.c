/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_get_ep_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void af_get_ep_desc(uint param_1)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = core_globals_get();
  pbVar2 = *(byte **)(iVar1 + 0xca0);
  if (pbVar2 != (byte *)0x0) {
    iVar1 = core_globals_get();
    pbVar2 = (byte *)**(undefined4 **)(iVar1 + 0xca0);
  }
  for (; (pbVar2 != (byte *)0x0 && (*pbVar2 != param_1)); pbVar2 = *(byte **)(pbVar2 + 0x1c)) {
  }
  return;
}

