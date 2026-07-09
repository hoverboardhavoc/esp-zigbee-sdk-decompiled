/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_rx_window_set_blk_nr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * aps_rx_window_set_blk_nr(undefined1 *param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint extraout_a1;
  char *pcVar4;
  uint uVar5;
  
  if (param_1[1] == '\0') {
    bVar1 = param_1[4];
    *param_1 = (char)param_2;
    param_1[2] = 0;
    uVar5 = (uint)(byte)param_1[3];
    if ((int)param_2 < (int)(uint)(byte)param_1[3]) {
      uVar5 = param_2;
    }
    param_1[3] = (char)uVar5;
    bVar2 = -(char)(1 << (uVar5 & 0x1f));
    param_1[4] = bVar2;
    param_1[4] = bVar2 | bVar1;
    return param_1;
  }
  pcVar4 = "aps_rx_window_set_blk_nr";
  iVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x19f,
                        "w->blk_start == 0");
  uVar5 = 0;
  while( true ) {
    uVar5 = bitmap_find_next_bit(iVar3 + 0x41c,0x20,uVar5);
    uVar5 = uVar5 & 0xff;
    if (0x1f < uVar5) {
      return (undefined1 *)0x0;
    }
    if (((char *)(uint)*(byte *)(uVar5 * 0x20 + iVar3 + 0x22) == pcVar4) &&
       (*(ushort *)(uVar5 * 0x20 + iVar3 + 0x20) == extraout_a1)) break;
    uVar5 = uVar5 + 1 & 0xff;
  }
  return (undefined1 *)(uVar5 * 0x20 + iVar3 + 0x1c);
}

