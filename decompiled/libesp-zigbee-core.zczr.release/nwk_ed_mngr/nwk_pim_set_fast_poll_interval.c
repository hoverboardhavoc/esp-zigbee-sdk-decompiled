/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_pim_set_fast_poll_interval
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_pim_set_fast_poll_interval(uint32_t interval)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = nwk_is_device_zed();
  if ((iVar3 != 0) && (iVar3 = core_globals_get(), *(uint32_t *)(iVar3 + 0xb10) != interval)) {
    iVar3 = core_globals_get();
    *(uint32_t *)(iVar3 + 0xb10) = interval;
    iVar3 = core_globals_get();
    if (*(int *)(iVar3 + 0xb14) << 10 < 0) {
      iVar3 = core_globals_get();
      iVar5 = *(int *)(iVar3 + 0xb0c);
      iVar3 = core_globals_get();
      uVar1 = nwk_ed_get_keepalive_interval();
      iVar2 = core_globals_get();
      if (((*(byte *)(iVar2 + 0xb16) & 0x10) != 0) && (1000 < uVar1)) {
        uVar1 = 1000;
      }
      iVar2 = core_globals_get();
      if ((*(short *)(iVar2 + 0xb14) != 0) &&
         (iVar2 = core_globals_get(), *(uint *)(iVar2 + 0xb10) <= uVar1)) {
        iVar2 = core_globals_get();
        uVar1 = *(uint *)(iVar2 + 0xb10);
      }
      if (uVar1 == 0) {
        uVar1 = 10;
      }
      *(uint *)(iVar3 + 0xb0c) = uVar1;
      iVar3 = core_globals_get();
      iVar3 = milli_timer_is_running(iVar3 + 0xafc);
      if (iVar3 != 0) {
        iVar3 = core_globals_get();
        if (*(int *)(iVar3 + 0xb0c) != iVar5) {
          iVar3 = core_globals_get();
          iVar3 = milli_timer_get_fire_time(iVar3 + 0xafc);
          iVar2 = core_globals_get();
          iVar4 = *(int *)(iVar2 + 0xb0c);
          iVar2 = core_globals_get();
          milli_timer_fire_at(iVar2 + 0xafc,(iVar3 - iVar5) + iVar4);
          return;
        }
        return;
      }
      iVar3 = core_globals_get();
      iVar2 = core_globals_get();
      milli_timer_start(iVar3 + 0xafc,*(undefined4 *)(iVar2 + 0xb0c));
      return;
    }
  }
  return;
}

