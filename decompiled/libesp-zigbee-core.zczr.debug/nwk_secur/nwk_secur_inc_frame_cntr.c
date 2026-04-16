/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_secur.o -> nwk_secur_inc_frame_cntr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint32_t nwk_secur_inc_frame_cntr(void)

{
  int iVar1;
  uint32_t uVar2;
  
  iVar1 = core_globals_get();
  if ((*(uint *)(iVar1 + 0x9fc) & 0x3ff) == 0) {
    nwk_secur_store_frame_cntr();
  }
  uVar2 = *(uint32_t *)(iVar1 + 0x9fc);
  *(uint32_t *)(iVar1 + 0x9fc) = uVar2 + 1;
  return uVar2;
}

