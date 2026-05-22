/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_rx_window_set_blk_nr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_rx_window_set_blk_nr(aps_trx_window_t *w,uint8_t blk_nr)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined3 in_register_0000202d;
  uint extraout_a1;
  char *pcVar4;
  uint uVar5;
  
  if (w->blk_start != '\0') {
    pcVar4 = "aps_rx_window_set_blk_nr";
    iVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x19f,
                          "w->blk_start == 0");
    uVar5 = 0;
    while( true ) {
      uVar5 = bitmap_find_next_bit(iVar3 + 0x41c,0x20,uVar5);
      uVar5 = uVar5 & 0xff;
      if ((0x1f < uVar5) ||
         (((char *)(uint)*(byte *)(uVar5 * 0x20 + iVar3 + 0x22) == pcVar4 &&
          (*(ushort *)(uVar5 * 0x20 + iVar3 + 0x20) == extraout_a1)))) break;
      uVar5 = uVar5 + 1 & 0xff;
    }
    return;
  }
  bVar1 = w->slot_done;
  w->blk_nr = blk_nr;
  w->slot_i = '\0';
  uVar5 = (uint)w->slot_nr;
  if ((int)CONCAT31(in_register_0000202d,blk_nr) < (int)(uint)w->slot_nr) {
    uVar5 = CONCAT31(in_register_0000202d,blk_nr);
  }
  w->slot_nr = (uint8_t)uVar5;
  bVar2 = -(char)(1 << (uVar5 & 0x1f));
  w->slot_done = bVar2;
  w->slot_done = bVar2 | bVar1;
  return;
}

