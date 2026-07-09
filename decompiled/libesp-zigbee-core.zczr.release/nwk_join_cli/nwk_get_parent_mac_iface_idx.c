/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_cli.o -> nwk_get_parent_mac_iface_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_get_parent_mac_iface_idx(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = core_globals_get();
  uVar2 = 0xff;
  if (*(int *)(iVar1 + 0xac4) != 0) {
    iVar1 = nwk_is_joined(0xff);
    if (iVar1 == 0) {
      iVar1 = core_globals_get();
      uVar2 = (uint)*(byte *)(*(int *)(iVar1 + 0xac4) + 0x13);
    }
    else {
      iVar1 = core_globals_get();
      uVar2 = *(uint *)(*(int *)(iVar1 + 0xac4) + 0xc) >> 0xd;
    }
    uVar2 = uVar2 & 0x1f;
  }
  return uVar2;
}

