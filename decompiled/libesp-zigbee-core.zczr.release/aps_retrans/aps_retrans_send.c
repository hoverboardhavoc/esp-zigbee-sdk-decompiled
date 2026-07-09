/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_retrans_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_retrans_send(int *param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int aiStack_3c [7];
  
  if (param_1 != (int *)0x0) goto _L0;
  while( true ) {
    param_1 = (int *)__assert_func(0,0,0,0);
_L0:
    iVar6 = 0x3a7;
    if (3 < *(byte *)(param_1 + 6)) goto _L0;
    iVar4 = zmsg_alloc(0x2f);
    if (iVar4 == 0) break;
    bVar2 = bitmap_find_next_zero_bit
                      ((int)param_1 + 0x1e,*(undefined1 *)((int)param_1 + 0x1d),(char)param_1[7]);
    *(byte *)(param_1 + 7) = bVar2;
    if (*(byte *)((int)param_1 + 0x1d) <= bVar2) goto _L0;
    uVar1 = (uint)(byte)(bVar2 + *(char *)((int)param_1 + 0x1b));
    iVar6 = aps_frame_find_payload_offset(*param_1);
    bVar2 = *(byte *)((int)param_1 + 0x19);
    uVar8 = bVar2 * uVar1 + iVar6 & 0xffff;
    iVar5 = zmsg_get_length(*param_1);
    if ((int)(uint)bVar2 < (int)(iVar5 - uVar8)) {
      uVar9 = (uint)*(byte *)((int)param_1 + 0x19);
    }
    else {
      iVar5 = zmsg_get_length(*param_1);
      uVar9 = iVar5 - uVar8 & 0xffff;
    }
    iVar6 = zmsg_append_bytes_from_msg(iVar4,*param_1,0,iVar6);
    if ((iVar6 == 0) && (iVar6 = zmsg_append_bytes_from_msg(iVar4,*param_1,uVar8,uVar9), iVar6 == 0)
       ) {
      if (1 < *(byte *)((int)param_1 + 0x1a)) {
        aps_frame_write_ext_hdr(iVar4,uVar1);
      }
      zmsg_get_footer(*param_1,aiStack_3c,0x1c);
      aiStack_3c[0] = iVar4;
      iVar6 = aps_send_frame((short)param_1[1],aiStack_3c);
      if (iVar6 == 0) {
        *(char *)(param_1 + 7) = (char)param_1[7] + '\x01';
_L0:
        bVar2 = bitmap_find_next_zero_bit((int)param_1 + 0x1e,*(undefined1 *)((int)param_1 + 0x1d));
        *(byte *)(param_1 + 7) = bVar2;
        uVar7 = 0;
        if (*(byte *)((int)param_1 + 0x1d) <= bVar2) {
          *(undefined1 *)(param_1 + 7) = 0;
          uVar7 = 0x640;
          *(char *)(param_1 + 6) = (char)param_1[6] + '\x01';
        }
        milli_timer_start(param_1 + 2,uVar7);
        return;
      }
      zmsg_free(iVar4);
_L0:
      iVar5 = *param_1;
      *param_1 = 0;
      iVar4 = core_globals_get();
      milli_timer_stop(param_1 + 2);
      uVar1 = (int)param_1 - (iVar4 + 0x54);
      if (*param_1 == 0) goto _L6;
      do {
        __assert_func(0,0,0,0);
_L6:
        uVar1 = (int)uVar1 >> 5;
      } while ((0x1f < (uVar1 & 0xff)) ||
              (iVar3 = test_and_clr_bitmap(uVar1 & 0xff,iVar4 + 0x454), iVar3 == 0));
      nwk_pim_stop_fast_poll();
      aps_send_frame_confirm(iVar5,iVar6);
      iVar6 = core_globals_get();
      tasklet_post(iVar6 + 0x38);
      return;
    }
  }
  iVar6 = 1;
  goto _L0;
}

