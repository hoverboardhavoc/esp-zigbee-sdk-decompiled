/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_retrans_send(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int aiStack_3c [7];
  
  if (param_1 == (undefined4 *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0xc1,
                  "aps_retrans_send","retrans != ((void *)0)");
  }
  else if (3 < *(byte *)(param_1 + 6)) {
    iVar2 = 0;
    iVar4 = 0x3a7;
    goto _L0;
  }
  iVar2 = zmsg_alloc(0x2f);
  if (iVar2 == 0) {
    iVar4 = 1;
    goto _L0;
  }
  iVar4 = aps_tx_window_find_next_slot((int)param_1 + 0x1a);
  if (iVar4 == 0) goto _L0;
  uVar6 = (uint)*(byte *)((int)param_1 + 0x1b) + (uint)*(byte *)(param_1 + 7) & 0xff;
  iVar4 = aps_frame_find_payload_offset(*param_1);
  bVar1 = *(byte *)((int)param_1 + 0x19);
  uVar5 = uVar6 * bVar1 + iVar4 & 0xffff;
  iVar3 = zmsg_get_length(*param_1);
  if ((int)(uint)bVar1 < (int)(iVar3 - uVar5)) {
    uVar7 = (uint)*(byte *)((int)param_1 + 0x19);
  }
  else {
    iVar3 = zmsg_get_length(*param_1);
    uVar7 = iVar3 - uVar5 & 0xffff;
  }
  iVar4 = zmsg_append_bytes_from_msg(iVar2,*param_1,0,iVar4);
  if (iVar4 == 0) {
    iVar4 = zmsg_append_bytes_from_msg(iVar2,*param_1,uVar5,uVar7);
    if (iVar4 != 0) goto _L0;
    if (1 < *(byte *)((int)param_1 + 0x1a)) goto _L0;
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0xd1,
                  "aps_retrans_send",
                  "(zmsg_append_bytes_from_msg(msg, retrans->tx_msg, 0, hdr_sz)) == 0");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0xd2,
                  "aps_retrans_send",
                  "(zmsg_append_bytes_from_msg(msg, retrans->tx_msg, tx_offset, tx_len)) == 0");
_L0:
    aps_frame_write_ext_hdr(iVar2,uVar6);
  }
  zmsg_get_footer(*param_1,aiStack_3c,0x1c);
  aiStack_3c[0] = iVar2;
  iVar4 = aps_send_frame(*(undefined2 *)(param_1 + 1),aiStack_3c);
  if (iVar4 == 0) {
    *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + '\x01';
_L0:
    iVar2 = aps_tx_window_find_next_slot((int)param_1 + 0x1a);
    if (iVar2 != 0) {
      milli_timer_start(param_1 + 2,0);
      return;
    }
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    *(undefined1 *)(param_1 + 7) = 0;
    milli_timer_start(param_1 + 2,0x640);
    return;
  }
_L0:
  if (iVar2 != 0) {
    zmsg_free(iVar2);
  }
  aps_retrans_send_confirm(param_1,iVar4);
  return;
}

