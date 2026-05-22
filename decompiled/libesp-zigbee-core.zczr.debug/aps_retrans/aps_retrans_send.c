/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

void aps_retrans_send(aps_retrans_ent_t *retrans)

{
  byte bVar1;
  int iVar2;
  _Bool _Var3;
  undefined3 extraout_var;
  int iVar4;
  undefined3 extraout_var_00;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iStack_3c;
  aps_apsde_data_req_t req;
  
  if (retrans == (aps_retrans_ent_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0xbf,
                  "aps_retrans_send","retrans != ((void *)0)");
  }
  else if (3 < retrans->retry_cntr) {
    iVar2 = 0;
    iVar5 = 0x3a7;
    goto _L0;
  }
  iVar2 = zmsg_alloc(0x2f);
  if (iVar2 == 0) {
    iVar5 = 1;
    goto _L0;
  }
  _Var3 = aps_tx_window_find_next_slot(&retrans->w);
  if (CONCAT31(extraout_var,_Var3) == 0) goto _L0;
  uVar7 = (uint)(retrans->w).blk_start + (uint)(retrans->w).slot_i & 0xff;
  iVar5 = aps_frame_find_payload_offset(retrans->tx_msg);
  bVar1 = retrans->blk_sz;
  uVar6 = uVar7 * bVar1 + iVar5 & 0xffff;
  iVar4 = zmsg_get_length(retrans->tx_msg);
  if ((int)(uint)bVar1 < (int)(iVar4 - uVar6)) {
    uVar8 = (uint)retrans->blk_sz;
  }
  else {
    iVar4 = zmsg_get_length(retrans->tx_msg);
    uVar8 = iVar4 - uVar6 & 0xffff;
  }
  iVar5 = zmsg_append_bytes_from_msg(iVar2,retrans->tx_msg,0,iVar5);
  if (iVar5 == 0) {
    iVar5 = zmsg_append_bytes_from_msg(iVar2,retrans->tx_msg,uVar6,uVar8);
    if (iVar5 != 0) goto _L0;
    if (1 < (retrans->w).blk_nr) goto _L0;
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0xcf,
                  "aps_retrans_send",
                  "(zmsg_append_bytes_from_msg(msg, retrans->tx_msg, 0, hdr_sz)) == 0");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0xd0,
                  "aps_retrans_send",
                  "(zmsg_append_bytes_from_msg(msg, retrans->tx_msg, tx_offset, tx_len)) == 0");
_L0:
    aps_frame_write_ext_hdr(iVar2,uVar7);
  }
  zmsg_get_footer(retrans->tx_msg,&iStack_3c,0x1c);
  iStack_3c = iVar2;
  iVar5 = aps_send_frame(retrans->dst_addr,&iStack_3c);
  if (iVar5 == 0) {
    (retrans->w).slot_i = (retrans->w).slot_i + '\x01';
_L0:
    _Var3 = aps_tx_window_find_next_slot(&retrans->w);
    if (CONCAT31(extraout_var_00,_Var3) != 0) {
      milli_timer_start(&retrans->tm,0);
      return;
    }
    retrans->retry_cntr = retrans->retry_cntr + '\x01';
    (retrans->w).slot_i = '\0';
    milli_timer_start(&retrans->tm,0x640);
    return;
  }
_L0:
  if (iVar2 != 0) {
    zmsg_free(iVar2);
  }
  aps_retrans_send_confirm(retrans,iVar5);
  return;
}

