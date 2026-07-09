/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_pim_start_fast_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_pim_start_fast_poll(uint param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = core_globals_get();
  if ((*(uint *)(iVar2 + 0xb14) >> 0x15 & 1) != 0) {
    iVar2 = core_globals_get();
    sVar1 = *(short *)(iVar2 + 0xb14);
    iVar2 = core_globals_get();
    if ((*(byte *)(iVar2 + 0xb16) & 0xf) != 0xf) {
      iVar2 = core_globals_get();
      *(byte *)(iVar2 + 0xb16) =
           ((byte)*(undefined2 *)(iVar2 + 0xb16) & 0xf) + 1 & 0xf | *(byte *)(iVar2 + 0xb16) & 0xf0;
    }
    if (param_1 == 0) {
      param_1 = 8;
    }
    iVar2 = core_globals_get();
    if (param_1 < *(ushort *)(iVar2 + 0xb14)) {
      iVar2 = core_globals_get();
      param_1 = (uint)*(ushort *)(iVar2 + 0xb14);
    }
    iVar2 = core_globals_get();
    *(short *)(iVar2 + 0xb14) = (short)param_1;
    if (sVar1 == 0) {
      nwk_pim_schedule_next_poll(1);
    }
  }
  return;
}

