/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac.o -> nwk_mm_register_interface
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_mm_register_interface(mac_interface_t *iface,uint8_t *iface_id)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = core_globals_get();
  bVar1 = (*(uint *)(iVar2 + 0xce0) >> 5 & 3) != 0;
  if (!bVar1) {
    iVar2 = core_globals_get();
    *iface_id = '\0';
    *(mac_interface_t **)(iVar2 + 0xce8) = iface;
    *(byte *)(iVar2 + 0xce0) = *(byte *)(iVar2 + 0xce0) & 0x80 | 0x20;
  }
  return (uint)bVar1;
}

