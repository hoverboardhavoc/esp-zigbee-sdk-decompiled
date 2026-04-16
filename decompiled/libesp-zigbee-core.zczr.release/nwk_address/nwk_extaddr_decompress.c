/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_extaddr_decompress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_extaddr_decompress(ezb_extaddr_t *extaddr,nwk_extaddr_c_t *extaddr_c)

{
  byte bVar1;
  int iVar2;
  void *__src;
  
  bVar1 = extaddr_c->oui_ref;
  iVar2 = core_globals_get();
  __src = (void *)0x0;
  if (bVar1 < 0x20) {
    __src = (void *)(iVar2 + (uint)bVar1 * 3 + 0xc4a);
  }
  memcpy(extaddr,extaddr_c,5);
  memcpy((void *)((int)&extaddr->field_0 + 5),__src,3);
  return;
}

