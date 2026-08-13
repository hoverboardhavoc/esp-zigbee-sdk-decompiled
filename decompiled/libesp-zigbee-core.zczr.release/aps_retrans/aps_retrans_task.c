/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_retrans_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_retrans_task(int param_1)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  void *__s;
  uint uVar9;
  
  iVar8 = param_1 + 0x10;
  iVar3 = zmsg_queue_get_head(iVar8);
  if (iVar3 != 0) {
    uVar4 = bitmap_find_first_zero_bit(param_1 + 0x41c,0x20);
    uVar1 = uVar4 & 0xff;
    if (uVar1 < 0x20) {
      uVar9 = 1;
      uVar4 = 1 << (uVar4 & 7) & 0xff;
      uVar5 = __atomic_fetch_or_1((uVar1 >> 3) + param_1 + 0x41c,uVar4,5);
      if ((uVar4 & uVar5) == 0) goto _L0;
      do {
        __assert_func(0,0,0,0);
_L0:
        uVar1 = uVar1 * 0x20;
        __s = (void *)(uVar1 + 0x1c + param_1);
        memset(__s,0,0x20);
        aps_retrans_start_fast_poll();
        zmsg_queue_dequeue(iVar8,iVar3);
        iVar8 = core_globals_get();
        uVar2 = *(undefined1 *)(iVar8 + 2);
        iVar8 = param_1 + uVar1;
        milli_timer_init(uVar1 + 0x24 + param_1,aps_retrans_send,__s);
        *(undefined1 *)(iVar8 + 0x39) = uVar2;
        *(int *)(iVar8 + 0x1c) = iVar3;
        uVar2 = aps_frame_get_aps_cntr(iVar3);
        *(undefined1 *)(iVar8 + 0x22) = uVar2;
        zmsg_get_footer(*(undefined4 *)(iVar8 + 0x1c),uVar1 + 0x20 + param_1,2);
        zmsg_remove_footer(*(undefined4 *)(iVar8 + 0x1c),2);
        zmsg_get_footer(*(undefined4 *)(iVar8 + 0x1c),uVar1 + 0x35 + param_1,uVar9);
        zmsg_remove_footer(*(undefined4 *)(iVar8 + 0x1c),uVar9);
        iVar6 = zmsg_get_length(*(undefined4 *)(iVar8 + 0x1c));
        iVar7 = zmsg_get_offset(*(undefined4 *)(iVar8 + 0x1c));
        uVar4 = iVar6 - iVar7 & 0xffff;
        if (uVar4 != 0) {
          uVar9 = (int)(uVar4 + *(byte *)(iVar8 + 0x35) + -1) / (int)(uint)*(byte *)(iVar8 + 0x35) &
                  0xff;
        }
      } while (7 < (byte)(*(char *)(iVar8 + 0x39) - 1U));
      *(char *)((int)__s + 0x1a) = (char)uVar9;
      *(undefined1 *)((int)__s + 0x1b) = 0;
      aps_tx_window_reset_slots(uVar1 + 0x36 + param_1);
      aps_retrans_send(__s);
      tasklet_post(param_1);
      return;
    }
  }
  return;
}

