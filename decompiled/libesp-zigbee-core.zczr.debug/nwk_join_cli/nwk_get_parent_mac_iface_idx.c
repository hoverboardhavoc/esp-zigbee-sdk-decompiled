/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_get_parent_mac_iface_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t nwk_get_parent_mac_iface_idx(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = core_globals_get();
  if (*(int *)(iVar2 + 0xac4) == 0) {
    bVar1 = 0xff;
  }
  else {
    iVar2 = nwk_is_joined();
    if (iVar2 == 0) {
      iVar2 = core_globals_get();
      bVar1 = *(byte *)(*(int *)(iVar2 + 0xac4) + 0x13) & 0x1f;
    }
    else {
      iVar2 = core_globals_get();
      bVar1 = (byte)(*(uint *)(*(int *)(iVar2 + 0xac4) + 0xc) >> 0xd) & 0x1f;
    }
  }
  return bVar1;
}

