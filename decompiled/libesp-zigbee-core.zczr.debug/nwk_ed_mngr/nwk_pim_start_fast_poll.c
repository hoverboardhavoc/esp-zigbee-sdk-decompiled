/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_pim_start_fast_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_pim_start_fast_poll(uint16_t fast_poll_nr)

{
  short sVar1;
  uint uVar2;
  undefined2 in_register_0000202a;
  int iVar3;
  
  uVar2 = CONCAT22(in_register_0000202a,fast_poll_nr);
  iVar3 = core_globals_get();
  if ((*(uint *)(iVar3 + 0xb14) >> 0x15 & 1) != 0) {
    iVar3 = core_globals_get();
    sVar1 = *(short *)(iVar3 + 0xb14);
    iVar3 = core_globals_get();
    if ((*(byte *)(iVar3 + 0xb16) & 0xf) != 0xf) {
      iVar3 = core_globals_get();
      *(byte *)(iVar3 + 0xb16) =
           ((byte)*(undefined2 *)(iVar3 + 0xb16) & 0xf) + 1 & 0xf | *(byte *)(iVar3 + 0xb16) & 0xf0;
    }
    if (uVar2 == 0) {
      uVar2 = 8;
    }
    iVar3 = core_globals_get();
    if (uVar2 < *(ushort *)(iVar3 + 0xb14)) {
      iVar3 = core_globals_get();
      uVar2 = (uint)*(ushort *)(iVar3 + 0xb14);
    }
    iVar3 = core_globals_get();
    *(short *)(iVar3 + 0xb14) = (short)uVar2;
    if (sVar1 == 0) {
      nwk_pim_schedule_next_poll(true);
    }
  }
  return;
}

