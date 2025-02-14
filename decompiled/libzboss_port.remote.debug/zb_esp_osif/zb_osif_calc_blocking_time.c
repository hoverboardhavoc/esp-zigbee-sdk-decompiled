/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_osif.o -> zb_osif_calc_blocking_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void zb_osif_calc_blocking_time(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int extraout_a1;
  int iVar4;
  int iVar5;
  
  if (*(int *)(_g_zb + 8) == 0) {
    if (DAT_00011084 == 0xff) {
      uVar2 = 0x78;
    }
    else {
      uVar3 = zb_timer_get();
      iVar5 = _DAT_00011080 + (uint)DAT_00011084 * 0xf;
      uVar1 = *(uint *)(iVar5 + 4);
      iVar5 = *(int *)(iVar5 + 8);
      uVar2 = uVar1 - uVar3;
      iVar4 = (iVar5 - extraout_a1) - (uint)(uVar1 < uVar2);
      if ((iVar4 < 0) || ((iVar4 == 0x7fffffff && (uVar2 == 0xffffffff)))) {
        uVar2 = uVar3 - uVar1;
        iVar4 = (extraout_a1 - iVar5) - (uint)(uVar3 < uVar2);
      }
      if ((iVar4 != 0) || (0x78 < uVar2)) {
        uVar2 = 0x78;
      }
    }
  }
  else {
    uVar2 = 0x78;
  }
  __udivdi3(uVar2,0,1000,0);
  return;
}

