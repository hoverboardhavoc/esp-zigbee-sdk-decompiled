/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_reasm_ent_input
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_reasm_ent_input(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  byte bVar8;
  int iVar9;
  byte bStack_22;
  byte bStack_21;
  
  if ((*(byte *)(param_2 + 0x11) & 3) == 1) {
    uVar6 = 0;
  }
  else {
    uVar6 = (uint)*(byte *)(param_2 + 0x12);
  }
  bStack_21 = (byte)uVar6;
  if (uVar6 < *(byte *)((int)param_1 + 0x22)) goto _L0;
  if ((uint)*(byte *)((int)param_1 + 0x22) + (uint)*(byte *)(param_1 + 9) <= uVar6) {
    if ((*(char *)((int)param_1 + 0x25) != -1) ||
       (iVar4 = aps_tx_window_move_next((int)param_1 + 0x21), iVar4 == 0)) goto _L0;
    *(undefined1 *)(param_1 + 8) = 0;
    milli_timer_start(param_1 + 4,0x640);
    if ((uint)bStack_21 < (uint)*(byte *)((int)param_1 + 0x22) + (uint)*(byte *)(param_1 + 9))
    goto _L0;
  }
  bVar8 = *(byte *)((int)param_1 + 0x22);
  uVar6 = (uint)bStack_21 - (uint)bVar8;
  iVar9 = (int)param_1 + 0x21;
  iVar4 = aps_rx_window_should_ack(iVar9);
  if (iVar4 != 0) {
    aps_send_ack(param_2,param_3,(uint)bVar8,
                 (uint)*(byte *)((int)param_1 + 0x25) | 1 << (uVar6 & 0x1f) & 0xffU);
  }
  uVar6 = uVar6 & 0x1f;
  if (((int)(uint)*(byte *)((int)param_1 + 0x25) >> uVar6 & 1U) == 0) {
    *(byte *)((int)param_1 + 0x25) = *(byte *)((int)param_1 + 0x25) | (byte)(1 << uVar6);
    if (bStack_21 == 0) {
      aps_rx_window_set_blk_nr(iVar9,*(undefined1 *)(param_2 + 0x12));
      *(undefined1 *)((int)param_1 + 0x23) = 1;
    }
    for (puVar1 = (undefined4 *)*param_1; puVar1 != param_1; puVar1 = (undefined4 *)*puVar1) {
      bStack_22 = 0;
      zmsg_get_footer(puVar1,&bStack_22,1);
      if (bStack_21 < bStack_22) break;
    }
    zmsg_add_footer(param_3,&bStack_21,1);
    puVar7 = (undefined4 *)puVar1[1];
    puVar1[1] = param_3;
    *param_3 = puVar1;
    param_3[1] = puVar7;
    *puVar7 = param_3;
    *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
    puVar1 = (undefined4 *)zmsg_queue_get_head(param_1);
    while (puVar7 = (undefined4 *)*puVar1, param_1 != puVar7) {
      bStack_22 = 0;
      bVar8 = *(char *)((int)param_1 + 0x22) + *(char *)((int)param_1 + 0x23);
      zmsg_get_footer(puVar7,&bStack_22,1);
      if (bStack_22 == bVar8) {
        *(char *)((int)param_1 + 0x23) = *(char *)((int)param_1 + 0x23) + '\x01';
        zmsg_queue_dequeue(param_1,puVar7);
        uVar5 = zmsg_get_offset(puVar7);
        sVar2 = zmsg_get_length(puVar7);
        sVar3 = zmsg_get_offset(puVar7);
        iVar4 = zmsg_append_bytes_from_msg(puVar1,puVar7,uVar5,sVar2 - sVar3);
        if (iVar4 != 0) {
          log_write(1,"aps_retrans.c","Failed to merge frag queue: %d",iVar4);
        }
      }
      else {
        if (bVar8 < bStack_22) break;
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x231,
                      "aps_reasm_ent_input","frag_blk > next_blk");
      }
      zmsg_free(puVar7);
    }
    if (*(char *)((int)param_1 + 0x25) != -1) {
      return;
    }
    iVar4 = aps_tx_window_move_next(iVar9);
    if (iVar4 != 0) {
      return;
    }
    if (*(short *)(param_1 + 2) == 1) {
      uVar5 = zmsg_queue_get_head(param_1);
      zmsg_queue_dequeue(param_1,uVar5);
      *(undefined1 *)(param_1 + 8) = 3;
      milli_timer_start(param_1 + 4,0x640);
      aps_handle_data(param_2,uVar5);
      return;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x249,
                  "aps_reasm_ent_input","ent->frag_q.length == 1");
    uVar6 = nwk_pim_get_fast_poll_interval();
    nwk_pim_start_fast_poll(0x1900 / uVar6);
    return;
  }
_L0:
  if (param_3 != (undefined4 *)0x0) {
    zmsg_free(param_3);
  }
  return;
}

