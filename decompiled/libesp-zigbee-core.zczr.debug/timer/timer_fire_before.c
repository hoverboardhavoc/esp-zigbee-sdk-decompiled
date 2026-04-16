/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> timer.o -> timer_fire_before
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool timer_fire_before(timer_base *tm0,timer_base *tm1,time32_t now)

{
  byte bVar1;
  uint uVar2;
  uint32_t uVar3;
  
  uVar2 = (tm0->fire_time).val - now.val;
  bVar1 = (byte)(uVar2 >> 0x18);
  uVar3 = (tm1->fire_time).val;
  if (-1 < (int)(uVar3 - now.val ^ uVar2)) {
    bVar1 = (byte)((tm0->fire_time).val - uVar3 >> 0x18);
  }
  return (_Bool)(bVar1 >> 7);
}

