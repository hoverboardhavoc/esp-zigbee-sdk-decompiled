/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_pim_start_fast_poll
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
  int iVar3;
  undefined2 in_register_0000202a;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = CONCAT22(in_register_0000202a,fast_poll_nr);
  iVar4 = core_globals_get();
  if (*(int *)(iVar4 + 0xb14) << 10 < 0) {
    iVar4 = core_globals_get();
    sVar1 = *(short *)(iVar4 + 0xb14);
    iVar4 = core_globals_get();
    if ((*(byte *)(iVar4 + 0xb16) & 0xf) != 0xf) {
      iVar4 = core_globals_get();
      *(byte *)(iVar4 + 0xb16) =
           *(byte *)(iVar4 + 0xb16) & 0xf0 | (char)*(undefined2 *)(iVar4 + 0xb16) + 1U & 0xf;
    }
    if (uVar2 == 0) {
      uVar2 = 8;
    }
    iVar4 = core_globals_get();
    if (uVar2 < *(ushort *)(iVar4 + 0xb14)) {
      iVar4 = core_globals_get();
      uVar2 = (uint)*(ushort *)(iVar4 + 0xb14);
    }
    iVar4 = core_globals_get();
    *(short *)(iVar4 + 0xb14) = (short)uVar2;
    if (sVar1 == 0) {
      iVar4 = core_globals_get();
      iVar6 = *(int *)(iVar4 + 0xb0c);
      iVar4 = core_globals_get();
      uVar2 = nwk_ed_get_keepalive_interval();
      iVar3 = core_globals_get();
      if (((*(byte *)(iVar3 + 0xb16) & 0x10) != 0) && (1000 < uVar2)) {
        uVar2 = 1000;
      }
      iVar3 = core_globals_get();
      if ((*(short *)(iVar3 + 0xb14) != 0) &&
         (iVar3 = core_globals_get(), *(uint *)(iVar3 + 0xb10) <= uVar2)) {
        iVar3 = core_globals_get();
        uVar2 = *(uint *)(iVar3 + 0xb10);
      }
      if (uVar2 == 0) {
        uVar2 = 10;
      }
      *(uint *)(iVar4 + 0xb0c) = uVar2;
      iVar4 = core_globals_get();
      iVar4 = milli_timer_is_running(iVar4 + 0xafc);
      if (iVar4 != 0) {
        iVar4 = core_globals_get();
        if (*(int *)(iVar4 + 0xb0c) != iVar6) {
          iVar4 = core_globals_get();
          iVar4 = milli_timer_get_fire_time(iVar4 + 0xafc);
          iVar3 = core_globals_get();
          iVar5 = *(int *)(iVar3 + 0xb0c);
          iVar3 = core_globals_get();
          milli_timer_fire_at(iVar3 + 0xafc,(iVar4 - iVar6) + iVar5);
          return;
        }
        return;
      }
      iVar4 = core_globals_get();
      iVar3 = core_globals_get();
      milli_timer_start(iVar4 + 0xafc,*(undefined4 *)(iVar3 + 0xb0c));
      return;
    }
  }
  return;
}

