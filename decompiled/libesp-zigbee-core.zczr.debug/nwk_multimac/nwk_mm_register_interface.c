/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_multimac.o -> nwk_mm_register_interface
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_mm_register_interface(mac_interface_t *iface,uint8_t *iface_id)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar1 = 0;
  do {
    if (uVar1 != 0) {
      puVar3 = (uint *)0x0;
_L0:
      if (puVar3 != (uint *)0x0) {
        *iface_id = (uint8_t)uVar1;
        uVar4 = *puVar3;
        *puVar3 = uVar4 & 0xffffffe0 | uVar1;
        *puVar3 = uVar4 & 0xffffff80 | uVar1 | 0x20;
        puVar3[2] = (uint)iface;
      }
      return (uint)(puVar3 == (uint *)0x0);
    }
    iVar2 = core_globals_get();
    if ((*(uint *)(iVar2 + 0xce0) >> 5 & 3) == 0) {
      iVar2 = core_globals_get();
      puVar3 = (uint *)(iVar2 + 0xce0);
      goto _L0;
    }
    uVar1 = 1;
  } while( true );
}

