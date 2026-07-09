/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_node_power_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_node_power_desc_init(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  *(ushort *)(iVar1 + 0xc98) = *(ushort *)(iVar1 + 0xc98) & 0xfff0;
  iVar1 = core_globals_get();
  *(ushort *)(iVar1 + 0xc98) = *(ushort *)(iVar1 + 0xc98) & 0xff0f | 0x10;
  iVar1 = core_globals_get();
  *(ushort *)(iVar1 + 0xc98) = *(ushort *)(iVar1 + 0xc98) & 0xf0ff | 0x100;
  iVar1 = core_globals_get();
  *(ushort *)(iVar1 + 0xc98) = *(ushort *)(iVar1 + 0xc98) & 0xfff | 0xc000;
  return 0;
}

